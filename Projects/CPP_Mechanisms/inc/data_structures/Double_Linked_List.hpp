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

    // Function if sorted
    void InsertIfSorted(const People &a_data);
public:
    DLinkedList();
    ~DLinkedList();

    // Adding elements to the list
    void PushFront(const People& a_data);
    void PushBack(const People& a_data, bool a_sorted = false);
    void Insert(const People& a_data, std::shared_ptr<Node>, bool a_sorted = false);

    // Removing elements from the list
    People PopFront();
    People PopBack();
    void Print() const;
    void BubbleSort(char);
    void SwapTwo(std::shared_ptr<Node> a_first, std::shared_ptr<Node> a_second);

    // Function if sorted
    void PushIfSorted(const People& a_data);

    // Accessors
    std::shared_ptr<Node> Front() const {return m_head;};
    std::weak_ptr<Node> Back() const {return m_tail;};

    // Operator overloads
    friend std::ostream& operator<<(std::ostream&, const DLinkedList&);

    // Bad functions :<
    std::shared_ptr<Node> operator[](int) const;
    void Insert(const People& a_data, int a_iterator, bool a_sorted = false);
    void SwapTwo(int, int);
};