#include <array>
#include <iostream>
#include "Double_Linked_List.hpp"
#include "People.hpp"

DLinkedList::DLinkedList() : m_size(0)
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

void DLinkedList::PushAtIndex(const People &a_data, int a_iterator)
{
    if(a_iterator < 0 || a_iterator > m_size-1)
        std::cout << "Out of bound iterator!" << std::endl;
    else
    {
        std::shared_ptr<Node> s_ptr;
        s_ptr = (*this)[a_iterator];
        std::shared_ptr<Node> data_pointer = std::make_shared<Node>(a_data);
        data_pointer->GetPreviousNode() = s_ptr;
        s_ptr->GetNextNode().lock()->GetPreviousNode() = data_pointer;
        data_pointer->GetNextNode() = s_ptr->GetNextNode().lock();
        s_ptr->GetNextNode() = data_pointer;
    }
    m_size++;
}

std::shared_ptr<Node> DLinkedList::operator[] (const int a_index) const {
    std::shared_ptr<Node> s_ptr;
    if(a_index >= m_size-1)
        return s_ptr;
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
