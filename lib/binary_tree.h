#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>

template<typename T>
struct TreeNode
{
    T value;
    TreeNode *leftNode;
    TreeNode *rightNode;
};

template<typename T>
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void insert_node(T key);
    TreeNode<T> * search(T key);
    void delete_tree();
    void in_order_print();
    void post_order_print();
    void pre_order_print();

private:
    void delete_tree(TreeNode<T> *leaf);
    void insert_node(T key, TreeNode<T> *leaf);
    TreeNode<T> *search(T key, TreeNode<T> *leaf);
    void in_order_print(TreeNode<T> *leaf);
    void post_order_print(TreeNode<T> *leaf);
    void pre_order_print(TreeNode<T> *leaf);

    TreeNode<T> *root;
};

template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
    delete_tree();
}

template<typename T>
void BinaryTree<T>::insert_node(T key, TreeNode<T> *leaf)
{
    if(key < leaf->value)
    {
        if(leaf->leftNode != NULL)
        {
            insert_node(key, leaf->leftNode);
        }else
        {
            leaf->leftNode = new TreeNode<T>;
            leaf->leftNode->value = key;
            leaf->leftNode->leftNode = NULL;
            leaf->leftNode->rightNode = NULL;
        }
    }else if(key >= leaf->value)
    {
        if(leaf->rightNode != NULL)
        {
            insert_node(key, leaf->rightNode);
        }else
        {
            leaf->rightNode = new TreeNode<T>;
            leaf->rightNode->value = key;
            leaf->rightNode->leftNode = NULL;
            leaf->rightNode->rightNode = NULL;
        }      
    }
}

template<typename T>
void BinaryTree<T>::insert_node(T key)
{
    if(root != NULL)
    {
        insert_node(key, root);
    }else
    {
        root = new TreeNode<T>;
        root->value = key;
        root->leftNode= NULL;
        root->rightNode = NULL;
    }
}

template<typename T>
TreeNode<T> * BinaryTree<T>::search(T key, TreeNode<T> *leaf)
{
    if(leaf != NULL)
    {
        if(key == leaf->value)
        {
            return leaf;
        }

        if(key < leaf->value)
        {
            return search(key, leaf->leftNode);
        }else
        {
            return search(key, leaf->rightNode);
        }
    }else
    {
        return NULL;
    }
}

template<typename T>
TreeNode<T> * BinaryTree<T>::search(T key)
{
    return search(key, root);
}

template<typename T>
void BinaryTree<T>::delete_tree(TreeNode<T> *leaf)
{
    if(leaf != NULL)
    {
        delete_tree(leaf->leftNode);
        delete_tree(leaf->rightNode);
        delete leaf;
    }
}

template<typename T>
void BinaryTree<T>::delete_tree()
{
    delete_tree(root);
}

template<typename T>
void BinaryTree<T>::in_order_print(TreeNode<T> *leaf)
{
    if(leaf != NULL)
    {
        in_order_print(leaf->leftNode);
        std::cout<< leaf->value << ",";
        in_order_print(leaf->rightNode);
    }
}

template<typename T>
void BinaryTree<T>::in_order_print()
{
    in_order_print(root);
    std::cout<<std::endl;
}

template<typename T>
void BinaryTree<T>::post_order_print(TreeNode<T> *leaf)
{
    if(leaf != NULL)
    {
        in_order_print(leaf->leftNode);
        in_order_print(leaf->rightNode);
        std::cout<< leaf->value << ",";
        
    }
}

template<typename T>
void BinaryTree<T>::post_order_print()
{
    post_order_print(root);
    std::cout<<std::endl;
}

template<typename T>
void BinaryTree<T>::pre_order_print(TreeNode<T> *leaf)
{
    if(leaf != NULL)
    {       
        std::cout<< leaf->value << ",";
        in_order_print(leaf->leftNode);
        in_order_print(leaf->rightNode);
        
    }
}

template<typename T>
void BinaryTree<T>::pre_order_print()
{
    pre_order_print(root);
    std::cout<<std::endl;
}

#endif