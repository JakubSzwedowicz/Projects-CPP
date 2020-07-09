#include <array>
#include <iostream>
#include "Double_Linked_List.hpp"
#include "People.hpp"

DLinkedList::DLinkedList() : m_size(0), m_sorted(false), m_how_sorted('0')
{
    std::cout << "List constructor" << std::endl;
}

DLinkedList::~DLinkedList() // AVOID RECURSIVE DESTRUCTOR !!!
{
    while(m_head != nullptr)
        m_head = std::move(m_head->GetPreviousNode());
    std::cout << "List destructor" << std::endl;
}

void DLinkedList::PushFront(const People &a_data)
{
    std::shared_ptr<Node> node = std::make_shared<Node>(a_data);
    if(m_size != 0)
    {
        node->GetPreviousNode() = m_head;
        m_head->GetNextNode() = node;
        m_head = node;
    }
    else
    {
        m_head = node;
        m_tail = node;
    }
    m_size++;
}
void DLinkedList::PushBack(const People &a_data)
{
    std::shared_ptr<Node> node = std::make_shared<Node>(a_data);
    if(m_size != 0)
    {
        node->GetNextNode() = m_tail;
        m_tail.lock()->GetPreviousNode() = node;
        m_tail = node;
    }
    else
    {
        m_head = node;
        m_tail = node;
    }
    m_size++;
}

void DLinkedList::PushIfSorted(const People& a_data)
{
    if(m_sorted == true)
    {
        int index = 0;
        std::shared_ptr<Node> node = m_head;
        switch(m_how_sorted)
        {
            case 'a':
                for(index = 0; index < m_size && node->GetData().GetAge() < a_data.GetAge(); index++)
                    node = node->GetPreviousNode();
                break;
            case 'g':
                for(index = 0; index < m_size && node->GetData().GetAge() < a_data.GetAge(); index++)
                    node = node->GetPreviousNode();
                break;
            case 'n':
                for(index = 0; index < m_size && node->GetData().GetName().compare(a_data.GetName()) < 0; index++)
                    node = node->GetPreviousNode();
                break;
        }
        m_size++;
    }
}

People DLinkedList::PopFront()
{
    if(m_size == 0)
    {
        std::cout << "List is empty" << std::endl;
        return NULL;
    }
    People data;
    data = m_head->GetData();
    m_head = m_head->GetPreviousNode();
    m_size--;
    return data;
}

People DLinkedList::PopBack()
{
    if(m_size == 0)
    {
        std::cout << "List is empty" << std::endl;
        return NULL;
    }
    People data;
    data = m_tail.lock()->GetData();
    m_tail = m_tail.lock()->GetNextNode();
    m_size--;
    return data;
}

void DLinkedList::Print() const
{
    std::weak_ptr<Node> iterator = m_head;
    for(int i = 1; i <= m_size; i++)
    {
        std::cout << "Node " << i << ":\n" << iterator.lock()->GetData() << std::endl;
        std::cout << std::endl;
        iterator = iterator.lock()->GetPreviousNode();
    }
}

std::ostream &operator<<(std::ostream &a_out, const DLinkedList &a_list)
{
    std::weak_ptr<Node> iterator = a_list.m_head;
    for(int i = 1; i <= a_list.m_size; i++)
    {
        a_out << "Node " << i << ": \n" << iterator.lock()->GetData() << std::endl;
        iterator = iterator.lock()->GetPreviousNode();
    }
    return a_out;
}

void DLinkedList::Insert(const People &a_data, int a_iterator)
{
    if(a_iterator < 0 || a_iterator > m_size)
        std::cout << "Out of bound iterator!" << std::endl;
    else if(a_iterator == m_size -1)
        PushBack(a_data);
    else
    {
        std::shared_ptr<Node> s_ptr;
        s_ptr = (*this)[a_iterator];
        std::shared_ptr<Node> data_pointer = std::make_shared<Node>(a_data);
        data_pointer->GetPreviousNode() = s_ptr;
        if(a_iterator > 0)
            s_ptr->GetNextNode().lock()->GetPreviousNode() = data_pointer;
        data_pointer->GetNextNode() = s_ptr->GetNextNode().lock();
        s_ptr->GetNextNode() = data_pointer;
    }
    m_size++;
}
void DLinkedList::Insert(const People &a_data, std::shared_ptr<Node> a_node)
{
    if(a_node == nullptr)
        PushBack(a_data);
    else
    {
        std::shared_ptr<Node> data_pointer = std::make_shared<Node>(a_data);
        data_pointer->GetPreviousNode() = a_node;
        if(a_node->GetNextNode().lock() != nullptr)
            a_node->GetNextNode().lock()->GetPreviousNode() = data_pointer;
        data_pointer->GetNextNode() = a_node->GetNextNode().lock();
        a_node->GetNextNode() = data_pointer;
    }
    m_size++;
}

std::shared_ptr<Node> DLinkedList::operator[] (const int a_index) const {
    std::shared_ptr<Node> s_ptr;
    if(a_index == m_size)
        return s_ptr = m_tail.lock()->GetPreviousNode();
    if(a_index < m_size/2)
    {
        s_ptr = m_head;
        for(int i = 0; i != a_index; i++)
            s_ptr = s_ptr->GetPreviousNode();
    } else {
        s_ptr = m_tail.lock();
        for(int i = m_size - 1; i != a_index; i--)
            s_ptr = s_ptr->GetNextNode().lock();
    }
    return s_ptr;
}

void DLinkedList::SwapTwo(int a_first, int a_second)
{
    std::shared_ptr<Node> first_node = (*this)[a_first];
    std::shared_ptr<Node> second_node = first_node;
    if(a_first < a_second)  // Optimization tweak
        for(int i = a_first; i != a_second && i < m_size; i++)
            second_node = second_node->GetPreviousNode();
    else
        for(int i = a_second; i != a_first && i < m_size; i--)
            second_node = second_node->GetNextNode().lock();
    first_node->GetDataPointer().swap(second_node->GetDataPointer());
}

void DLinkedList::SwapTwo(std::shared_ptr<Node> a_first, std::shared_ptr<Node> a_second)
{
    a_first->GetDataPointer().swap(a_second->GetDataPointer());
}

void DLinkedList::BubbleSort(char a_sorting)
{
    bool m_sorted = true;
    for(int i = 0; i < m_size-1 && m_sorted == true; i++)
    {
        m_sorted = false;
        for(std::shared_ptr<Node> node = m_head, next_node = m_head->GetPreviousNode();
            next_node != nullptr;
            node = node->GetPreviousNode(), next_node = next_node->GetPreviousNode())
        {
            switch(a_sorting)
            {
                case 'a':
                        if(node->GetData().GetAge() > node->GetPreviousNode()->GetData().GetAge())
                        {
                            SwapTwo(node, next_node);
                            m_sorted = true;
                        }
                    break;
                case 'g':
                    if(node->GetData().GetGrade() > next_node->GetData().GetGrade())
                    {
                        SwapTwo(node, next_node);
                        m_sorted = true;
                    }
                    break;
                case 'n':
                    if(node->GetData().GetName().compare(next_node->GetData().GetName()) > 0)
                    {
                        SwapTwo(node, next_node);
                        m_sorted = true;
                    }
                    break;
            }
        }
    }
    m_how_sorted = a_sorting;
}
