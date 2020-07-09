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
    bool m_sorted;
    char m_how_sorted;
public:
    DLinkedList();
    ~DLinkedList();
    void PushFront(const People& a_data);
    void PushBack(const People& a_data);
    void PushIfSorted(const People& a_data);
    void Insert(const People& a_data, int a_iterator);
    void Insert(const People& a_data, std::shared_ptr<Node>);
    void SwapTwo(int, int);
    People PopFront();
    People PopBack();
    void Print() const;
    void BubbleSort(char);
    friend std::ostream& operator<<(std::ostream&, const DLinkedList&);
    std::shared_ptr<Node> operator[](int) const;

    void SwapTwo(std::shared_ptr<Node> a_first, std::shared_ptr<Node> a_second);
};