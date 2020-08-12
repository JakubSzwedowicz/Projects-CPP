#include <iostream>
#include <memory>
#include "Binary_Tree.hpp"
#include "Tree_Node.hpp"

template class BinaryTree<int>;
template <typename T>
void BinaryTree<T>::Insert(T a_key)
{
    if(m_root == nullptr)
        m_root = std::make_unique<TreeNode<T>>(a_key);
    else
    {
        TreeNode<T>* ptr = m_root.get();
        ptr = TravelTree(ptr, a_key);
        if(a_key < ptr->GetData())
        {
            ptr->GetLeft() = std::make_unique<TreeNode<T>>(ptr, a_key);
            ptr = ptr->GetLeft().get();
        }
        else
        {
            ptr->GetRight() = std::make_unique<TreeNode<T>>(ptr, a_key);
            ptr = ptr->GetRight().get();
        }
        std::cout << "next insert \n" << std::endl;
        std::cout << "Key: " << a_key << " - Before balancing: " << std::endl;
        PrintTree();
        BalanceTree(ptr);
        std::cout << "Key: " << a_key << " - After balancing: " << std::endl;
        PrintTree();
    }
}

template <typename T>
TreeNode<T>* BinaryTree<T>::TravelTree(TreeNode<T>* a_ptr, T a_key)
{
    if(a_key < a_ptr->GetData())
    {
        if(a_ptr->GetLeft() == nullptr)
            return a_ptr;
        else
            return TravelTree(a_ptr->GetLeft().get(), a_key);
    }
    else
    {
        if(a_ptr->GetRight() == nullptr)
            return a_ptr;
        else
            return TravelTree(a_ptr->GetRight().get(), a_key);

    }
}

template<typename T>
void BinaryTree<T>::PrintTree(TreeNode<T>* a_node, int a_space)
{
    static int count = 2;
    if(a_node == nullptr)
        return;
    a_space += count;
    PrintTree(a_node->GetRight().get(), a_space);
    for(int i = count; i < a_space; i++)
        std::cout << "\t";
    std::cout << a_node->GetData() << "_" << a_node->GetColor() << "\n";
    PrintTree(a_node->GetLeft().get(), a_space);
}

template<typename T>
void BinaryTree<T>::PrintTree() {
    PrintTree(m_root.get(), 0);
}

template<typename T>
void BinaryTree<T>::BalanceTree(TreeNode<T>* a_node) {
    if(a_node->GetParent() == nullptr || a_node->GetParent()->GetColor()) // if a_node is a root or if parent is black
        return;
    else    // if parent is red
    {
        TreeNode<T>* new_node = a_node;
        a_node = a_node->GetParent();
        TreeNode<T>* new_nodes_parent = a_node;
        a_node = a_node->GetParent();
        bool not_collored = true;
        if(a_node->GetRight() != nullptr && a_node->GetRight()->GetColor() == false)
            if(a_node->GetLeft() != nullptr && a_node->GetLeft()->GetColor() == false)
            {
                not_collored = false;
                RecolorCaseOne(a_node);
                BalanceTree(a_node);
            }
        if(not_collored)
        {
            RecolorCaseTwo(new_node, new_nodes_parent, a_node);
            not_collored = false;
        }
    }
}

template <typename T>
void BinaryTree<T>::RecolorCaseOne(TreeNode<T>* parent)
{
    parent->GetLeft()->GetColor() = true;
    parent->GetRight()->GetColor() = true;
    if(parent->GetParent() != nullptr)   // if parent is not root
        parent->GetColor() = false;
}
template <typename T>
void BinaryTree<T>::RotateRight(TreeNode<T>*& a_child, TreeNode<T>*& a_parent)
{
    if(m_root.get() == a_parent)
        m_root.release();
    a_child->RotateRight(a_parent);
    if(m_root == nullptr)
    {
        m_root.reset(a_child);
    }
}

template<typename T>
void BinaryTree<T>::RotateLeft(TreeNode<T> *&a_child, TreeNode<T> *&a_parent) {
    if(m_root.get() == a_parent)
        m_root.release();
    a_child->RotateLeft(a_parent);
    if(m_root == nullptr)
    {
        m_root.reset(a_child);
        a_parent = a_child;
    }
}

template <typename T>
void BinaryTree<T>::RecolorCaseTwo(TreeNode<T>* a_grandchild, TreeNode<T>* a_child, TreeNode<T>* a_parent)
{
    if(a_parent->GetLeft().get() == a_child)
    {
        if(a_child->GetRight().get() == a_grandchild)
        {
            RotateLeft(a_grandchild, a_child);
            a_child = a_grandchild;
            a_grandchild = a_grandchild->GetLeft().get();
        }
        RotateRight(a_child, a_parent);
        a_parent = a_child;
        a_child = a_parent->GetRight().get();

    } else
    {
        if(a_child->GetLeft().get() == a_grandchild)
        {
            RotateRight(a_grandchild, a_child);
            a_child = a_grandchild;
            a_grandchild = a_grandchild->GetLeft().get();
        }
        RotateLeft(a_child, a_parent);
        a_parent = a_child;
        a_child = a_parent->GetLeft().get();

    }
    a_parent->GetColor() = !a_parent->GetColor();
    a_child->GetColor() = !a_child->GetColor();
}
