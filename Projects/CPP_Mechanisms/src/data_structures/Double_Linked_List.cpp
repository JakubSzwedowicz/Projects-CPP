#include <array>
#include <iostream>
#include "Double_Linked_List.hpp"
#include "People.hpp"
#include <variant>

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
    if(m_size == 0)
    {
        m_head = node;
        m_tail = node;
    }
    else
    {
        if(m_sorted == true)
        {
            PushIfSorted(a_data);
            return;
        }
        node->GetPreviousNode() = m_head;
        m_head->GetNextNode() = node;
        m_head = node;
    }
    m_size++;
}
void DLinkedList::PushBack(const People &a_data, bool a_sorted)
{
    std::shared_ptr<Node> node = std::make_shared<Node>(a_data);
    if(m_size == 0)
    {
        m_head = node;
        m_tail = node;
    }
    else
    {
        if(m_sorted == true && a_sorted == false)
        {
            PushIfSorted(a_data);
            return;
        }
        node->GetNextNode() = m_tail;
        m_tail.lock()->GetPreviousNode() = node;
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
        Insert(a_data, node, true);
    }
}

People DLinkedList::PopFront()
{
    if(m_size == 0)
    {
        std::cout << "PopFront: List is empty" << std::endl;
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
        std::cout << "PopBack: List is empty" << std::endl;
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
    for(int i = 0; i < a_list.m_size; i++)
    {
        a_out << "Node " << i << ": \n" << iterator.lock()->GetData() << std::endl;
        iterator = iterator.lock()->GetPreviousNode();
    }
    return a_out;
}

void DLinkedList::Insert(const People &a_data, int a_iterator, bool a_sorted)
{
    if(a_iterator < 0 || a_iterator > m_size || m_size == 0)
    {
        std::cout << "Insert:: Out of bound iterator or m_size == 0!" << std::endl;
        return;
    }
    if(a_iterator == m_size -1)
        PushBack(a_data);   // Checks if sorted and increases size
    else if(a_iterator == 0)
        PushFront(a_data);  // Checks if sorted and increases size
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
        m_size++;
        m_sorted = false;   // No longer sorted
    }
}
void DLinkedList::Insert(const People &a_data, std::shared_ptr<Node> a_node, bool a_sorted)
{
    if(a_node == nullptr)   // if a_data is supposed to be added at the end of the list (m_tail)
        PushBack(a_data, a_sorted);   // Checks if sorted and increases size
    else
    {
        std::shared_ptr<Node> data_pointer = std::make_shared<Node>(a_data);
        data_pointer->GetPreviousNode() = a_node;
        if(a_node->GetNextNode().lock() != nullptr)
            a_node->GetNextNode().lock()->GetPreviousNode() = data_pointer;
        data_pointer->GetNextNode() = a_node->GetNextNode().lock();
        a_node->GetNextNode() = data_pointer;
        m_size++;
        if(!a_sorted)
            m_sorted = false;
    }
}

std::shared_ptr<Node> DLinkedList::operator[] (const int a_index) const {
    std::shared_ptr<Node> s_ptr;
    if(a_index >= m_size || a_index < 0 || m_size == 0)
    {
        std::cout << "operator[]: out of bound index or m_size == 0" << std::endl;
        return nullptr;
    }
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
    const_cast<DLinkedList*>(this)->m_sorted = false; // in case user changes sth afterwards
    return s_ptr;
}

void DLinkedList::SwapTwo(int a_first, int a_second)
{
    if(m_size < 2 || a_first < 0 || a_first == a_second || a_second < 0 || a_first > m_size || a_second > m_size)
    {
        std::cout << "SwapTwo: out of bound indexes or m_size < 2" << std::endl;
        return;
    }
    if(a_first > a_second)
        std::swap(a_first, a_second);
    std::shared_ptr<Node> first_node = (*this)[a_first];
    std::shared_ptr<Node> second_node = first_node;
    for(int i = a_first; i != a_second && i < m_size; i++)
        second_node = second_node->GetPreviousNode();
    SwapTwo(first_node, second_node);
}

void DLinkedList::SwapTwo(std::shared_ptr<Node> a_first, std::shared_ptr<Node> a_second)
{
    if(m_size < 2 || a_first == nullptr || a_second == nullptr)
    {
        std::cout << "SwapTwo: empty pointers, or m_size < 2" << std::endl;
        return;
    }
    if(a_first == a_second)
        return;

    if(a_second->GetPreviousNode() == a_first) // if a_second is before a_first
        a_first.swap(a_second);

    if(a_first->GetPreviousNode() == a_second) // if they are next to each other
    {
        if( !(a_first->GetNextNode().expired()) )   // if the next node exists, i.e. it is not nullptr
            a_first->GetNextNode().lock()->GetPreviousNode() = a_second;
        else    // then it means that a_first == m_head
            m_head = a_second;
        a_second->GetNextNode() = a_first->GetNextNode();
        if( a_second->GetPreviousNode() != nullptr )    // if the previous node exists, i.e. it is not a nullptr
            a_second->GetPreviousNode()->GetNextNode() = a_first;
        else    // then it means that a_second == m_tail
            m_tail.lock() = a_first;
        a_first->GetPreviousNode() = a_second->GetPreviousNode();

        a_first->GetNextNode() = a_second;
        a_second->GetPreviousNode() = a_first;

    } else  // If they are NOT next to each other
    {
        std::shared_ptr<Node> next, previous;
        previous = a_first->GetPreviousNode();
        next = a_first->GetNextNode().lock();

        a_first->GetNextNode() = a_second->GetNextNode();
        a_first->GetNextNode().lock()->GetPreviousNode() = a_first;
        a_first->GetPreviousNode() = a_second->GetPreviousNode();
        if(a_first->GetPreviousNode() != nullptr)   // if it's not nullptr, i.e. if a_second->GetPrevious != nullptr
            a_first->GetPreviousNode()->GetNextNode() = a_first;
        else    // then it means that a_second == m_tail
            m_tail = a_first;

        a_second->GetPreviousNode() = previous;
        previous->GetNextNode() = a_second;
        a_second->GetNextNode() = next;
        if(next != nullptr) // if it's not nullptr, i.e. if a_first wasn't m_head
            next->GetPreviousNode() = a_second;
        else
            m_head = a_second;
    }
    m_sorted = false;
}

void DLinkedList::BubbleSort(char a_sorting)
{
    if(m_size < 2)
    {
        std::cout << "BubbleSort: Nothing to sort" << std::endl;
        return;
    }
    m_sorted = false;
    for(int i = 0; i < m_size-1 && m_sorted == false; i++)
    {
        m_sorted = true;
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
                            m_sorted = false;
                            node.swap(next_node);
                        }
                    break;
                case 'g':
                    if(node->GetData().GetGrade() > next_node->GetData().GetGrade())
                    {
                        SwapTwo(node, next_node);
                        m_sorted = false;
                        node.swap(next_node);
                    }
                    break;
                case 'n':
                    if(node->GetData().GetName().compare(next_node->GetData().GetName()) > 0)
                    {
                        SwapTwo(node, next_node);
                        m_sorted = false;
                        node.swap(next_node);
                    }
                    break;
            }
        }
    }
    m_sorted = true;
    m_how_sorted = a_sorting;
}

void DLinkedList::MergeSort(char a_sorting) {
    if(m_size < 2)
    {
        std::cout << "MergeSort: There is nothing to sort" << std::endl;
        return;
    }
    ActualMergeSort(m_head, m_tail.lock(), m_size, a_sorting);
    m_sorted = true;
    m_how_sorted = a_sorting;
}

void DLinkedList::ActualMergeSort(std::shared_ptr<Node> a_low, std::shared_ptr<Node> a_high, int a_range, char a_sorting)
{
    if(a_range > 1) //a_low != a_high
    {
        int left_size = (a_range+1)/2;
        int right_size = (a_range)/2;

        std::shared_ptr<Node> split_ptr = a_low;
        std::shared_ptr<Node> next = a_low->GetNextNode().lock(), previous = a_high->GetPreviousNode();
        for(int i = 1; i < left_size; i++)
            split_ptr = split_ptr->GetPreviousNode();

        std::shared_ptr<Node> anchor = split_ptr->GetPreviousNode();

        ActualMergeSort(a_low, split_ptr, left_size, a_sorting);
        ActualMergeSort(anchor, a_high,right_size, a_sorting);

        if(next == nullptr)
            a_low = m_head;
        else
            a_low = next->GetPreviousNode();

        if(previous == nullptr)
            a_high = m_tail.lock();
        else
            a_high = previous->GetNextNode().lock();

        std::shared_ptr<Node> left_array[left_size], right_array[right_size];

        std::shared_ptr<Node> temp = a_low;
        for(int i = 0; i < left_size; i++, a_low = a_low->GetPreviousNode())
            left_array[i] = a_low;

        for(int i = 0; i < right_size; i++, a_low = a_low->GetPreviousNode())
            right_array[i] = a_low;
        a_low = temp;

        int i = 0, j = 0;
        bool flag = true;
        while(i != left_size && j != right_size)
        {
            switch(a_sorting)
            {
                case 'a':
                    if(left_array[i]->GetData().GetAge() <= right_array[j]->GetData().GetAge())
                        flag = true;
                    else
                        flag = false;
                    break;
                case 'g':
                    if(left_array[i]->GetData().GetGrade() <= right_array[j]->GetData().GetGrade())
                        flag = true;
                    else
                        flag = false;
                    break;
                case 'n':
                    if(left_array[i]->GetData().GetName().compare(right_array[j]->GetData().GetName()) <= 0)
                        flag = true;
                    else
                        flag = false;
                    break;
            }
            if(flag)
            {
                SwapTwo(a_low, left_array[i]);
                a_low = left_array[i];
                a_low = a_low->GetPreviousNode();
                i++;
            } else
            {
                SwapTwo(a_low, right_array[j]);
                a_low = right_array[j];
                a_low = a_low->GetPreviousNode();
                j++;
            }
        }   // after the while(i != ... && j != ...)

        for(; i != left_size; i++)
        {
            SwapTwo(a_low, left_array[i]);
            a_low = left_array[i];
            a_low = a_low->GetPreviousNode();
        }
        for(; j != right_size; j++)
        {
            SwapTwo(a_low, right_array[j]);
            a_low = right_array[j];
            a_low = a_low->GetPreviousNode();
        }
    }
}