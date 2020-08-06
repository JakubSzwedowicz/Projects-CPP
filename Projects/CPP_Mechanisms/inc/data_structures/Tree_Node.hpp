#pragma once
#include <memory>

template <typename T>
class TreeNode
{
private:
    TreeNode<T>* m_parent;
    std::unique_ptr<TreeNode<T>> m_left;
    std::unique_ptr<TreeNode<T>> m_right;
    bool m_color; // true = black, false = red
    T m_data;
public:
    TreeNode(TreeNode<T>*& a_parent, T a_data) : m_data(a_data), m_parent(a_parent), m_color(false) {};
    TreeNode(T a_data) : m_data(a_data), m_parent(nullptr), m_color(true) {};
    inline std::unique_ptr<TreeNode<T>>& GetLeft() { return m_left;};   // It's inline anyway
    inline std::unique_ptr<TreeNode<T>>& GetRight() { return m_right; };
    T& GetData() { return m_data;};
    inline bool& GetColor() { return m_color;};
    inline TreeNode<T>*& GetParent() {return m_parent;};
    void RotateLeft(TreeNode<T>*&);
    void RotateRight(TreeNode<T>*&);

};

template<typename T>
void TreeNode<T>::RotateLeft(TreeNode<T> *&a_node) {    // Function assumes that a_node->GetRight() == this
    m_parent = a_node->m_parent;
    a_node->m_parent = this;
    a_node->m_right.release();
    a_node->m_right.reset(this->m_left.release()); // So not to lose right branch of this
    if(m_parent != nullptr)
    {
        if(m_parent->m_left.get() == a_node)  // a_node might be on the left of its parent
        {
            m_parent->m_left.release();   // releasing a_node from its parent
            m_parent->m_left.reset(this);
        }
        else    // a_node might be on the right of its parent
        {
            m_parent->m_right.release();   // releasing a_node from its parent
            m_parent->m_right.reset(this);
        }
    }
    m_left.reset(a_node);
}

template<typename T>
void TreeNode<T>::RotateRight(TreeNode<T> *&a_node){   // Function assumes that a_node->GetLeft() == this
    m_parent = a_node->m_parent;
    a_node->m_parent = this;
    a_node->m_left.release();
    a_node->m_left.reset(this->m_right.release()); // So not to lose right branch of this
    if(m_parent != nullptr)
    {
        if(m_parent->m_left.get() == a_node)  // a_node might be on the left of its parent
        {
            m_parent->m_left.release();   // releasing a_node from its parent
            m_parent->m_left.reset(this);
        }
        else    // a_node might be on the right of its parent
        {
            m_parent->m_right.release();   // releasing a_node from its parent
            m_parent->m_right.reset(this);
        }
    }
    m_right.reset(a_node);
}
