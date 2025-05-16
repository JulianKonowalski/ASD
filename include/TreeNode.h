#ifndef TREE_NODE_H
#define TREE_NODE_H

/*
* @brief A generic container
*   class that stores data
*   and acts as a building block
*   for tree data structures
* 
* @tparam Type The type parameter
*   determining the type of data
*   stored in the data node
*/
template<typename Type>
class TreeNode {
public:

    /*
    * @brief initialises a node
    *   object
    * 
    * @param data initial value
    *   stored in the node
    */
    TreeNode(Type data);

    /*
    * @brief sets the data
    *   stored by the node
    * 
    * @param data data value
    *   to be stored in the node
    */
    void setData(Type data);

    /*
    * @brief sets the node that the
    *   current node's left pointer 
    *   points to
    *
    * @param left pointer to the
    *   node that the current node's
    *   left pointer will point to
    */
    void setLeft(TreeNode<Type>* left);

    /*
    * @brief sets the node that the
    *   current node's right pointer 
    *   points to
    *
    * @param right pointer to the
    *   node that the current node's
    *   right pointer will point to
    */
    void setRight(TreeNode<Type>* right);

    /*
    * @brief returns data stored
    *   by the node
    * 
    * @return a reference to the 
    *   stored value
    */
    Type& getData(void);

    /*
    * @brief returns a pointer
    *   to the left node
    * 
    * @return pointer to the 
    *   left node
    */
    TreeNode<Type>* getLeft(void);

    /*
    * @brief returns a pointer
    *   to the right node
    * 
    * @return pointer to the 
    *   right node
    */
    TreeNode<Type>* getRight(void);

private:

	Type mData;
	TreeNode<Type>* mLeft;
    TreeNode<Type>* mRight;

};

template<typename Type>
TreeNode<Type>::TreeNode(Type data) : 
    mData(data), 
    mLeft(nullptr),
    mRight(nullptr)
{}

template<typename Type>
void TreeNode<Type>::setLeft(TreeNode<Type>* left) { mLeft = left; }

template<typename Type>
void TreeNode<Type>::setRight(TreeNode<Type>* right) { mRight = right; }

template<typename Type>
TreeNode<Type>* TreeNode<Type>::getLeft(void) { return mLeft; }

template<typename Type>
TreeNode<Type>* TreeNode<Type>::getRight(void) { return mRight; }

template<typename Type>
void TreeNode<Type>::setData(Type data) { mData = data; }

template<typename Type>
Type& TreeNode<Type>::getData(void) { return mData; }

#endif
