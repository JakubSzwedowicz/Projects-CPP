#include <iostream>
#include <memory>
#include "Binary_Tree.hpp"
#include "Tree_Node.hpp"

template class BinaryTree<int>;
template <typename T>
void BinaryTree<T>::Insert(T a_key)
{
    std::cout << "next insert \n" << std::endl;
    if(m_root == nullptr)
        m_root = std::make_unique<TreeNode<T>>(a_key);
    else {
        TreeNode<T>* ptr = m_root.get();
        ptr = TravelTree(m_root.get(), a_key);
        if (ptr->GetData() == a_key) // Adding the duplicate
        {
            ptr->GetDuplicates()++;
        } else {
            if (a_key < ptr->GetData()) {
                ptr->GetLeft() = std::make_unique<TreeNode<T>>(ptr, a_key);
                ptr = ptr->GetLeft().get();
            } else {
                ptr->GetRight() = std::make_unique<TreeNode<T>>(ptr, a_key);
                ptr = ptr->GetRight().get();
            }
            std::cout<<"Key: "<<a_key<<" - Before balancing: "<<std::endl;
            PrintTree();
            BalanceTree(ptr);
            std::cout<<"Key: "<<a_key<<" - After balancing: "<<std::endl;
        }
    }
    PrintTree();
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
    else if(a_key > a_ptr->GetData())
    {
        if(a_ptr->GetRight() == nullptr)
            return a_ptr;
        else
            return TravelTree(a_ptr->GetRight().get(), a_key);
    }
    else
        return a_ptr;
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
    std::cout << *a_node << "\n";
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
        bool not_colored = true;
        if(a_node->GetRight() != nullptr && a_node->GetRight()->GetColor() == false)
            if(a_node->GetLeft() != nullptr && a_node->GetLeft()->GetColor() == false)
            {
                not_colored = false;
                RecolorCaseOne(a_node);
                BalanceTree(a_node);
            }
        if(not_colored)
        {
            RecolorCaseTwo(new_node, new_nodes_parent, a_node);
            not_colored = false;
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
//        a_parent = a_child;
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

template <typename T>
void BinaryTree<T>::Remove(int a_node_key)    // https://www.programiz.com/dsa/red-black-tree
{
    std::cout << "Key: " << a_node_key << " - Before removing:" << std::endl;
    PrintTree();
    if(m_root == nullptr)
        return;

    TreeNode<T>* node_to_remove = TravelTree(a_node_key);
    if(node_to_remove->GetData() == a_node_key) // In case user tries to remove sth that doesnt exist
    {
        bool removed_node_color = node_to_remove->GetColor();   // Saving the color of removed node
        TreeNode<T>* node_replacement = node_to_remove;
        TreeNode<T>* node_repl_child;

        if(node_to_remove->GetLeft() == nullptr)
            node_replacement = node_to_remove->GetRight().get();
       else if (node_to_remove->GetRight() == nullptr)
           node_replacement = node_to_remove->GetLeft().get();
       else
       {
            node_replacement = node_to_remove->GetRight().get();
            while(node_replacement->GetLeft() != nullptr)
                node_replacement = node_replacement->GetLeft().get(); // finds the smallest node in right subtree of node_to_remove
            removed_node_color = node_replacement->GetColor();
            node_repl_child = node_replacement->GetRight().get();
       }
       if(node_replacement != nullptr)  // In case of removed node being a leaf meaning it has no child
           node_replacement->GetParent() = node_to_remove->GetParent();
       TransplantNodes(node_to_remove, node_replacement);
       if(removed_node_color == true)
       {
           std::cout << "repairing black-red tree not implemented yet" << std::endl;
           // Repair the black-red tree
       }
    }
    std::cout << "Key: " << a_node_key << " - After removing:" << std::endl;
    PrintTree();
}

template <typename T>
void BinaryTree<T>::TransplantNodes(TreeNode<T>* a_first, TreeNode<T>* a_second)    // a_first is a parent of a_second
{
    TreeNode<T>* parent = a_first->GetParent();
    auto& (TreeNode<T>::*parent_side)() = &TreeNode<T>::GetLeft;    // there would be many "ifs" otherwise
    auto& (TreeNode<T>::*child_side)() = &TreeNode<T>::GetLeft;
    auto& (TreeNode<T>::*not_child_side)() = &TreeNode<T>::GetLeft;

    if(a_first->GetLeft().get() == a_second)
        not_child_side = &TreeNode<T>::GetRight;
    else
        child_side = &TreeNode<T>::GetRight;

    if(parent->GetRight().get() == a_first)
        parent_side = &TreeNode<T>::GetRight;

    if(a_second != nullptr)
    {
        a_second->GetParent() = parent;
        if((a_second->*not_child_side)() == nullptr)
            (a_second->*not_child_side)().reset((a_first->*not_child_side)().release());
        else
            std::cout << "ERROR: DATA LOSS WHEN TRANSPLANTING NODES!" << std::endl;   // not using exceptions yet!
    }
    (parent->*parent_side)().reset((a_first->*child_side)().release());

}

//template <typename T>
//void BinaryTree<T>::Remove(int a_node_key)
//{
//    if(m_root == nullptr)
//        return;
//
//     TreeNode<T>* node = m_root.get();
//     node = TravelTree(node, a_node_key);
//    if(node == m_root.get())
//    {
//        m_root.reset();
//        std::cout << "After the removal of the node: " << a_node_key << " \n";
//        PrintTree();
//        return;
//    }
//
//    if(node->GetData() == a_node_key)    // In case user tries to remove sth that doesnt exist
//    {
//        TreeNode<T>* nt`ode_parent = node->GetParent();
//        if(node_parent->GetLeft().get() == node)    // If node is on the left part of the tree
//        {
//            if(node->GetLeft() == nullptr || node->GetRight() == nullptr) {
//                RemoveCaseOne(node, false);
////                if(node->GetLeft() == nullptr)
////                    TransplantNodes(node, node->GetRight().get());
////                else if (node->GetRight() == nullptr)
////                    TransplantNodes(node, node->GetLeft().get());
//            }
//            else
//            {
//                TreeNode<T>* node_child = node->GetRight().get();
//                while(node_child->GetLeft() != nullptr)
//                    node_child = node_child->GetLeft().get();
//                if(node_child->GetParent() == node)   // if node_child is just on the right of the removed node
//                {
//                    RemoveCaseTwo(node, false);
//                }
//                else    // if node_child is further on the right of the removed node
//                {
//                    RemoveCaseThree(node, node_child, false);
//                }
//            }
//        }
//        else
//        {
//            if(node->GetLeft() == nullptr || node->GetRight() == nullptr){
//                RemoveCaseOne(node, true);
//            }
//            else
//            {
//                TreeNode<T>* node_child = node->GetRight().get();
//                while(node_child->GetLeft() != nullptr)
//                    node_child = node_child->GetLeft().get();
//                if(node_child->GetParent() == node)   // if node_child is just on the right of the removed node
//                {
//                    RemoveCaseTwo(node, true);
//                }
//                else    // if node_child is further on the right of the removed node
//                {
//                    RemoveCaseThree(node, node_child, true);
//                }
//            }
//        }
//    }
//    std::cout << "After the removal of the node: " << a_node_key << " \n";
//    PrintTree();
//}
//
//template <typename T>
//void BinaryTree<T>::RemoveCaseOne(TreeNode<T>* a_node, bool a_side)
//{
//    bool do_recoloring, parent_color;
//    TreeNode<T>* node_parent = a_node->GetParent();
//    do_recoloring = a_node->GetColor(); // If removed node is black(true) then we should recolor the tree
//    if(a_side) // The Truth is on the right side of the force
//    {
//        if(a_node->GetLeft() == nullptr)
//            node_parent->GetRight().reset(a_node->GetRight().release());
//        else
//            node_parent->GetRight().reset(a_node->GetLeft().release());
//        if(do_recoloring && node_parent->GetColor() == false && node_parent->GetRight()->GetColor() == false)
//            node_parent->GetRight()->GetColor() = true;
//
//    }
//    else
//    {
//        if(a_node->GetLeft() == nullptr)
//            node_parent->GetLeft().reset(a_node->GetRight().release());
//        else
//            node_parent->GetLeft().reset(a_node->GetLeft().release());
//        if(do_recoloring && node_parent->GetColor() == false && node_parent->GetLeft()->GetColor() == false)
//            node_parent->GetLeft()->GetColor() = true;
//    }
//}
//
//template <typename T>
//void BinaryTree<T>::RemoveCaseTwo(TreeNode<T>* a_node, bool a_side)
//{
//    TreeNode<T>* node_parent = a_node->GetParent();
//    bool do_recoloring = a_node->GetRight()->GetColor();
//    if(a_side)  // if removed node is on the right side of the tree
//    {
//        a_node->GetRight()->GetLeft().reset(a_node->GetLeft().release());
//        a_node->GetRight()->GetColor() = a_node->GetColor();
//        node_parent->GetRight().reset(a_node->GetRight().release());
//    }
//    else    // if removed node is on the left side of the tree then we swap it with is right grandchild
//    {
//        a_node->GetRight()->GetLeft().reset(a_node->GetLeft().release());
//        a_node->GetRight()->GetColor() = a_node->GetColor();
//        node_parent->GetLeft().reset(a_node->GetRight().release());
//    }
//    if(do_recoloring)
//    {
//        // The balance of the tree needs to be restored here!
//    }
//}
//
//template <typename T>
//void BinaryTree<T>::RemoveCaseThree(TreeNode<T>* a_node, TreeNode<T>* a_node_replacement, bool a_side)
//{
//    bool do_recoloring = a_node_replacement->GetColor();
//    a_node->GetData() = a_node_replacement->GetData();
//
//    TreeNode<T>* node_child = a_node_replacement->GetRight().get();   // node to replace a_node_replacement
//    node_child->GetParent() = a_node_replacement->GetParent();
//    node_child->GetColor() = a_node_replacement->GetColor();
//    a_node_replacement->GetParent()->GetLeft().reset(a_node_replacement->GetRight().release());
//    bool node_child_color = node_child->GetColor();
//    if(do_recoloring)
//    {
//        // The balance of the tree has to be restored here!
//    }
//}