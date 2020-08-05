#pragma once
#include "Tree_Node.hpp"

template<typename T>
class BinaryTree
{
private:
    std::unique_ptr<TreeNode<T>> m_root;
    void PrintTree(TreeNode<T> *a_node, int a_space);
public:
    void Insert(T a_data);
    void PrintTree();
    TreeNode<T>* TravelTree(TreeNode<T>* a_ptr, T a_key);
    void BalanceTree(TreeNode<T>*);

    void RecolorCaseOne(TreeNode<T> *parent);

    void RecolorCaseTwo(TreeNode<T>*, TreeNode<T>*, TreeNode<T>*);

    void RotateRight(TreeNode<T> *&a_child, TreeNode<T> *&a_parent);
    void RotateLeft(TreeNode<T> *&a_child, TreeNode<T> *&a_parent);
};