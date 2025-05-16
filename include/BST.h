#ifndef BST_H
#define BST_H

#include <functional>

#include "TreeNode.h"
#include "Queue.h"

/*
 * @brief naive binary search 
 *      tree data structure 
 *
 * @tparam Type data type to 
 *      be stored within the 
 *      tree
 */
template<typename Type>
class BST {
public:

    /*
     * @brief creates an empty 
     *  binary search tree
     */
    BST(void);

    /*
     * @brief destroys the binary 
     *  tree by deleting all of 
     *  the existing nodes 
     */
    ~BST(void);

    /*
     * @brief inserts a value into 
     *  the tree in a naive way. Does 
     *  nothing if the value already 
     *  exists
     *
     * @param value the value to be 
     *  inserted into the tree 
     */
    void insert(const Type& value);

    /*
     * @brief removes a value from 
     *  the tree. Does nothing if 
     *  the value doesn't exist
     *
     * @param value the value to be 
     *  removed
     */
    void remove(const Type& value);

    /*
     * @brief searches for a value 
     *  in the tree and returns a 
     *  pointer to said value if it 
     *  exists
     *
     * @param value the value to 
     *  search for
     *
     * @return pointer to the found 
     *  value. Returns nullptr if 
     *  the value doesn't exist
     */
    Type* search(const Type& value);

    /*
     * @brief searches for the minimum
     *  value within the tree
     *
     * @return pointer to the minimum 
     *  value within the tree. Returns 
     *  nullptr if the tree is empty 
     */
    Type* minimum(void);

    /*
     * @brief searches for the maximum 
     *  value within the tree 
     *
     * @return pointer to the maximum 
     *  value within the tree. Returns 
     *  nullptr if the tree is empty
     */
    Type* maximum(void);

    /*
     * @brief traverses the whole 
     *  tree recursively in the 
     *  order of: 
     *  1. parent node
     *  2. left child 
     *  3. right child
     *
     * @param action lambda with a 
     *  set of instructions to be 
     *  performed on each of the nodes
     */
    void preorder(const std::function<void(const Type& value)>& action);

    /*
     * @brief traverses the whole 
     *  tree recursively in the 
     *  order of: 
     *  1. left child 
     *  2. parent node
     *  3. right child
     *
     * @param action lambda with a 
     *  set of instructions to be 
     *  performed on each of the nodes
     */
    void inorder(const std::function<void(const Type& value)>& action);

    /*
     * @brief traverses the whole 
     *  tree recursively in the 
     *  order of: 
     *  1. left child 
     *  2. right child
     *  3. parent node
     *
     * @param action lambda with a 
     *  set of instructions to be 
     *  performed on each of the nodes
     */
    void postorder(const std::function<void(const Type& value)>& action);

    /*
     * @brief traverses the whole 
     *  tree recursively row by row
     *
     * @param action lambda with a 
     *  set of instructions to be 
     *  performed on each of the nodes
     */
    void roworder(const std::function<void(const Type& value)>& action);

private:

    /*
     * @brief recursive part of the 
     *  preorder DFS traversal
     *
     * @param node currently visited
     *  node
     * @param action action to be 
     *  performed on every visited 
     *  node
     */
    void __recurse_preorder__(TreeNode<Type>* node,
            const std::function<void(const Type& value)>& action);

    /*
     * @brief recursive part of the 
     *  inorder DFS traversal
     *
     * @param node currently visited
     *  node
     * @param action action to be 
     *  performed on every visited 
     *  node
     */
    void __recurse_inorder__(TreeNode<Type>* node,
            const std::function<void(const Type& value)>& action);

    /*
     * @brief recursive part of the 
     *  postorder DFS traversal
     *
     * @param node currently visited
     *  node
     * @param action action to be 
     *  performed on every visited 
     *  node
     */
    void __recurse_postorder(TreeNode<Type>* node,
            const std::function<void(const Type& value)>& action);

    /*
     * @brief root node of the 
     *  binary search tree
     */
    TreeNode<Type>* mRoot;

};

template<typename Type>
BST<Type>::BST(void) : mRoot(nullptr) {}

template<typename Type>
BST<Type>::~BST(void) {

    /*
     * Create a queue for the 
     * tree nodes. If the root 
     * is not nullptr, then add it 
     * to the queue.
     */
    Queue<TreeNode<Type>*> queue;
    if (mRoot) { queue.enqueue(mRoot); }

    /*
     * Traverse the whole tree by 
     * using BFS.
     */
    while (!queue.isEmpty()) {

        /*
         * Pop the current node 
         * from the front of the 
         * queue
         */
        auto node = queue.dequeue();

        /*
         * If the left child is not 
         * nullptr then add it to the 
         * queue
         */
        if (node->getLeft())
            queue.enqueue(node->getLeft());

        /*
         * If the right child is not 
         * nullptr then add it to the 
         * queue
         */
        if (node->getRight())
            queue.enqueue(node->getRight());

        /* Delete the current node */
        delete node;
    }
}

template<typename Type>
void BST<Type>::insert(const Type& value) {

    /*
     * If the root doesn't exist
     * then create a new node and 
     * assign it to the root
     */
    if (!mRoot) {
        mRoot = new TreeNode<Type>(value);
        return;
    }

    /*
     * Search for the appropriate 
     * place otherwise 
     */
    auto ptr = mRoot;
    for (;;) {

        /*
         * If the value is smaller 
         * than the one in the current
         * node go left
         */
        if (value < ptr->getData()) {
            
            /*
             * If left node is nullptr then 
             * create a new tree node and 
             * assign it to the left pointer 
             */
            if (!ptr->getLeft()) {
                ptr->setLeft(new TreeNode(value));
                break;
            }

            /* Else go left */
            ptr = ptr->getLeft();

        /*
         * If the value is greater 
         * than the one in the current 
         * node go right
         */
        } else if (value > ptr->getData()){

            /*
             * If right node is nullptr then 
             * create a new tree node and 
             * assign it to the right pointer
             */
            if (!ptr->getRight()) {
                ptr->setRight(new TreeNode(value));
                break;
            }

            /* Else go right */
            ptr = ptr->getRight();

        /*
         * Ignore if a value is a duplicate 
         * of another value that's already 
         * present in the tree
         */
        } else { break; }
    }
}

template<typename Type>
void BST<Type>::remove(const Type& value) {

    /*
     * If the tree is empty 
     * then do nothing and return
     */
    if (!mRoot) { return; }

    /*
     * Create a parent node, that will follow 
     * the path of the 'toDelete' node. It'll
     * come in handy later
     */
    TreeNode<Type>* parent = nullptr, *toDelete = mRoot;

    /*
     * Create a dir flag, that will indicate 
     * if 'toDelete' node is the left or 
     * the right child of the parent node
     */
    uint8_t dir = 0;

    /*
     * Search for the node to be deleted.
     * Before updating 'toDelete' pointer,
     * assign its value to the 'parent' pointer.
     */
    while (toDelete) {

        /*
         * If the right node was found
         * then break from the loop
         */
        if (toDelete->getData() == value)
            break;

        /* Else update the parent node */
        parent = toDelete;

        /*
         * If the searched value is smaller 
         * than the value in the current node 
         * then go left
         */
        if (value < toDelete->getData()) {
            toDelete = toDelete->getLeft();
            dir = 0;

        /*
         * Else go right, as there's no 
         * duplicates in the tree
         */
        } else {
            toDelete = toDelete->getRight();
            dir = 1;
        }

    }

    /*
     * Return if the searched 
     * element doesn't exist
     */
    if (!toDelete) { return; }

    /*
     * If the 'toDelete' node has 
     * two children, then switch its
     * values with the smallest node 
     * in the right subtree and delete 
     * the smalles node in that subtree
     */
    if (toDelete->getLeft() && 
        toDelete->getRight()) {
    
        /*
         * Create two additional pointers,
         * as another deletion will have to 
         * take place. Similarly to the original 
         * set of pointers, they will help 
         * safely delete the minimum node
         */
        TreeNode<Type>* minParent = nullptr, *min = toDelete->getRight();

        /*
         * Find the minimum node 
         * in the right subtree of 
         * the original 'toDelete'
         * node
         */
        while(min->getLeft()) {
            minParent = min;
            min = min->getLeft(); 
        }

        /*
         * Assign the minimum value
         * from the right subtree to 
         * the original 'toDelete' node
         */
        toDelete->setData(min->getData());

        /*
         * If 'minParent' node is nullptr 
         * then the minimum node from the 
         * rigth subtree is a child of the 
         * original 'toDelete' node. In 
         * that case assign the right child 
         * of the minimum node to the rigth 
         * pointer of the 'toDelete' node. 
         * 
         * 1. We assign the right child of 
         *      the minimum node, because 
         *      the minimum node can't have 
         *      the left child. If it had one 
         *      then it wouldn't be the minimum
         *      node.
         *
         * 2. It doesn't matter if the right 
         *      child of the minimum node is 
         *      a valid pointer or not. At worst
         *      it'll be a nullptr, which is 
         *      the default value for an empty node
         */
        if (!minParent) { toDelete->setRight(min->getRight()); }

        /*
         * Else if the 'minParent' is not nullptr
         * then set the left child of the 'minParent'
         * node to be the right child of the minimum 
         * node.
         *
         * 1. We overwrite the left child of the parent 
         *      node because the minimum node is always 
         *      on the left side of the parent.
         *
         * 2. Similarly to the other case, we don't 
         *      care if the right child of the minimum 
         *      node is a valid pointer.
         */
        else { minParent->setLeft(min->getRight()); }

        /* Delete the minimum node */
        delete min;

    /*
     * Else if the 'toDelete' node 
     * has the left child, assign 
     * the child to the parent node 
     * and delete the 'toDelte' node
     */
    } else if (toDelete->getLeft()) {

        /*
         * If parent is nullptr then 
         * 'toDelete' node is the root 
         * of the tree. In that case 
         * overwrite the root with 
         * its left child.
         */
        if (!parent) {
            auto tmp = mRoot;
            mRoot = mRoot->getLeft();
            delete tmp;

        /*
         * Else if 'toDelete' is the 
         * right child of its parent 
         * node overwrite the right 
         * child of the parent node 
         * with the left child of 
         * 'toDelete' node.
         */
        } else if (dir) {
            parent->setRight(toDelete->getLeft());
            delete toDelete;

        /*
         * Else if 'toDelete' is the 
         * left child of its parent 
         * node overwrite the left 
         * child of the parent node 
         * with the left child of 
         * 'toDelete' node.
         */
        } else {
            parent->setLeft(toDelete->getLeft());
            delete toDelete;
        }

    /*
     * Else if the 'toDelete' node 
     * has the right child, assign 
     * the child to the parent node 
     * and delete the 'toDelte' node
     */
    } else if (toDelete->getRight()) {


        /*
         * If parent is nullptr then 
         * 'toDelete' node is the root 
         * of the tree. In that case 
         * overwrite the root with 
         * its right child.
         */
        if (!parent) {
            auto tmp = mRoot;
            mRoot = mRoot->getRight();
            delete tmp;

        /*
         * Else if 'toDelete' is the 
         * right child of its parent 
         * node overwrite the right
         * child of the parent node 
         * with the right child of 
         * 'toDelete' node.
         */
        } else if (dir) {
            parent->setRight(toDelete->getRight());
            delete toDelete;

        /*
         * Else if 'toDelete' is the 
         * left child of its parent 
         * node overwrite the left 
         * child of the parent node 
         * with the right child of 
         * 'toDelete' node.
         */
        } else {
            parent->setLeft(toDelete->getRight());
            delete toDelete;
        }

    /*
     * Else if the 'toDelete' node 
     * doesn't have any children, 
     * delete it
     */
    } else {
        
        /*
         * If there's no parent node 
         * then 'toDelete' node is 
         * actually the root of the tree
         */
        if (!parent) { 
            delete mRoot; 

        /*
         * The node is the rigth child 
         * of its parent
         */
        } else if (dir) {
            delete toDelete;
            parent->setRight(nullptr);

        /*
         * The node is the left child
         * of its parent
         */
        } else {
            delete toDelete;
            parent->setLeft(nullptr);
        }

    }


}

template<typename Type>
Type* BST<Type>::search(const Type& value) {

    /*
     * If the tree is empty then 
     * return nullptr
     */
    if (!mRoot) { return nullptr; }
    auto ptr = mRoot;

    /*
     * Else traverse the tree 
     * to find the searched value.
     * If the pointer is nullptr 
     * then we've the searched 
     * value is not present in the 
     * tree.
     */
    while (ptr) {

        /*
         * If the value stored by 
         * the current node is equal 
         * to the searched value then 
         * break from the loop.
         */
        if (ptr->getData() == value)
            break;
        /*
         * If the searched value is 
         * smaller than the value 
         * stored in the node, then 
         * go left
         */
        if (value < ptr->getData()) {
            ptr = ptr->getLeft(); 

        /*
         * If the searched value is 
         * greater than the value 
         * stored in the node, then 
         * go right
         */
        } else {
            ptr = ptr->getRight();
        }
    }

    /*
     * Check if the pointer is nullptr.
     * If not then return the pointer to the 
     * stored data, else return nullptr.
     */
    return ptr ? &ptr->getData() : nullptr;
}

template<typename Type>
Type* BST<Type>::minimum(void) {

    /*
     * If the tree is empty 
     * return nullptr
     */
    if (!mRoot) { return nullptr; }
    auto ptr = mRoot;

    /*
     * Else go to the leftmost 
     * node. Because of the BSTs 
     * characteristics, we can
     * be certain that the minimum 
     * node is the leftmost node of 
     * the tree.
     */
    while (ptr->getLeft())
        ptr = ptr->getLeft();

    /*
     * Check if the pointer is nullptr.
     * If not then return the pointer to the 
     * stored data, else return nullptr.
     */
    return ptr ? &ptr->getData() : nullptr;
}

template<typename Type>
Type* BST<Type>::maximum(void) {

    /*
     * If the tree is empty 
     * return nullptr
     */
    if (!mRoot) { return nullptr; }
    auto ptr = mRoot;

    /*
     * Else go to the rightmost
     * node. Because of the BSTs 
     * characteristics, we can
     * be certain that the maximum
     * node is the rightmost node of 
     * the tree.
     */
    while (ptr->getRight())
        ptr = ptr->getRight();

    /*
     * Check if the pointer is nullptr.
     * If not then return the pointer to the 
     * stored data, else return nullptr.
     */
    return ptr ? &ptr->getData() : nullptr;
}

template <typename Type>
void BST<Type>::preorder(const std::function<void(const Type& value)>& action) {

    /*
     * If the tree is empty 
     * return from the method
     */
    if (!mRoot) { return; }

    /*
     * Recursively call preorder 
     * on every visited node
     */
    this->__recurse_preorder__(mRoot, action);
}

template <typename Type>
void BST<Type>::inorder(const std::function<void(const Type& value)>& action) {

    /*
     * If the tree is empty
     * return from the method
     */
    if (!mRoot) { return; }

    /*
     * Recursively call inorder 
     * on every visited node
     */
    this->__recurse_inorder__(mRoot, action);
}

template <typename Type>
void BST<Type>::postorder(const std::function<void(const Type& value)>& action) {

    /*
     * If the tree is empty 
     * return from the method
     */
    if (!mRoot) { return; }

    /*
     * Recursively call preorder 
     * on every visited node
     */
    this->__recurse_postorder(mRoot, action);
}

template <typename Type>
void BST<Type>::roworder(const std::function<void(const Type& value)>& action) {

    /*
     * If the tree is empty
     * return from the method
     */
    if (!mRoot) { return; }

    /*
     * Initialise an empty queue 
     * that will hold the nodes 
     * to be visited
     */
    Queue<TreeNode<Type>*> queue;

    /*
     * Enqueue the root of the 
     * binary search tree
     */
    queue.enqueue(mRoot);

    /*
     * Traverse the tree until 
     * the queue is emptied
     */
    while (!queue.isEmpty()) {

        /*
         * Pop the current node 
         * from the front of the 
         * queue
         */
        auto node = queue.dequeue();

        /*
         * Perform the action on 
         * the data stored by the 
         * current node
         */
        action(node->getData());

        /*
         * If the node has a left 
         * child, then add it to 
         * the queue
         */
        if (node->getLeft())
            queue.enqueue(node->getLeft());

        /*
         * If the node has a right 
         * child, then add it to 
         * the queue
         */
        if (node->getRight())
            queue.enqueue(node->getRight());

    }
}

template <typename Type>
void BST<Type>::__recurse_preorder__(
        TreeNode<Type>* node,
        const std::function<void(const Type& value)>& action
) {
    /*
     * If the node is nullptr
     * then return from the 
     * method. In my implementation 
     * of the tree this should 
     * never happen, but better 
     * safe than sorry
     */
    if (!node) { return; }

    /*
     * Perform the action on 
     * the data stored by the 
     * current node
     */
    action(node->getData());


    /*
     * If the node has a left 
     * child, then recursively 
     * call preorder for the left 
     * subtree
     */
    if (node->getLeft())
        this->__recurse_preorder__(node->getLeft(), action);

    /*
     * If the node has a right
     * child, then recursively 
     * call preorder for the right 
     * subtree
     */
    if (node->getRight())
        this->__recurse_preorder__(node->getRight(), action);   
}
 
template <typename Type>
void BST<Type>::__recurse_inorder__(
        TreeNode<Type>* node,
        const std::function<void(const Type& value)>& action
) {

    /*
     * If the node is nullptr
     * then return from the 
     * method. In my implementation 
     * of the tree this should 
     * never happen, but better 
     * safe than sorry
     */
    if (!node) { return; }

    /*
     * If the node has a left 
     * child, then recursively 
     * call preorder for the left 
     * subtree
     */
    if (node->getLeft())
        this->__recurse_inorder__(node->getLeft(), action);

    /*
     * Perform the action on 
     * the data stored by the 
     * current node
     */
    action(node->getData());

    /*
     * If the node has a right
     * child, then recursively 
     * call preorder for the right 
     * subtree
     */
    if (node->getRight())
        this->__recurse_inorder__(node->getRight(), action);
}

template <typename Type>
void BST<Type>::__recurse_postorder(
        TreeNode<Type>* node,
        const std::function<void(const Type& value)>& action
) {

    /*
     * If the node is nullptr
     * then return from the 
     * method. In my implementation 
     * of the tree this should 
     * never happen, but better 
     * safe than sorry
     */
    if (!node) { return; }

    /*
     * If the node has a left 
     * child, then recursively 
     * call preorder for the left 
     * subtree
     */
    if (node->getLeft())
        this->__recurse_postorder(node->getLeft(), action);

    /*
     * If the node has a right
     * child, then recursively 
     * call preorder for the right 
     * subtree
     */
    if (node->getRight())
        this->__recurse_postorder(node->getRight(), action);

    /*
     * Perform the action on 
     * the data stored by the 
     * current node
     */
    action(node->getData());
}

#endif
