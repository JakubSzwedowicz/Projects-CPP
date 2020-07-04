#pragma once
#include "People.hpp"
#include "Node.hpp"
#include <memory>
#include <array>

class DLinkedList
{
private:
    std::shared_ptr<Node> m_head;
    std::weak_ptr<Node> m_tail;
    int m_size;
public:
    DLinkedList();
    ~DLinkedList();
    void PushFront(const People& a_data);
    void PushBack(const People& a_data);
    void PushAtIndex(const People& a_data, int a_iterator);
    People PopFront();
    People PopBack();
    void Print() const;
    friend std::ostream& operator<<(std::ostream&, const DLinkedList&);
    std::shared_ptr<Node> operator[](int) const;
};