#pragma once
#include "People.hpp"
#include <memory>
#include <iostream>
#include <functional>

class Node
{
private:
    std::shared_ptr<Node> m_previous_node;
    People m_data;
    std::weak_ptr<Node> m_next_node;
public:
    Node(const People& a_data);
    ~Node();
    inline std::shared_ptr<Node>& GetPreviousNode() {return m_previous_node;};
    inline People& GetData() {return m_data;};
    inline void SetData(const People& a_data) {m_data = a_data;};
    inline std::weak_ptr<Node>& GetNextNode() {return m_next_node;};
};