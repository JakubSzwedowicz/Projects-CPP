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
    TreeNode<T>* TravelTree(T a_key) {return TravelTree(m_root.get(), a_key);};
    void BalanceTree(TreeNode<T>*);

    void RecolorCaseOne(TreeNode<T> *parent);

    void RecolorCaseTwo(TreeNode<T>*, TreeNode<T>*, TreeNode<T>*);
    void RotateRight(TreeNode<T> *&a_child, TreeNode<T> *&a_parent);
    void RotateLeft(TreeNode<T> *&a_child, TreeNode<T> *&a_parent);
    void Remove(int);
    void RemoveCaseOne(TreeNode<T>*, bool);
    void RemoveCaseTwo(TreeNode<T>*, bool);
    void RemoveCaseThree(TreeNode<T>*, TreeNode<T>*, bool);

    void TransplantNodes(TreeNode<T> *a_first, TreeNode<T> *a_second);

    void FixTreeAfterDeletion(TreeNode<T>*);
};