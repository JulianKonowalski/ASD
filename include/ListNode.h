#ifndef LIST_NODE_H
#define LIST_NODE_H

/*
* @brief A generic container
*   class that stores data
*   and acts as a building block
*   for larger data structures
* 
* @tparam Type The type parameter
*   determining the type of data
*   stored in the data node
*/

template<typename Type>
class ListNode {
public:

    /*
    * @brief initialises a node
    *   object
    * 
    * @param data initial value
    *   stored in the node
    */
    ListNode(Type data);

    /*
    * @brief sets the data
    *   stored by the node
    * 
    * @param data data value
    *   to be stored in the node
    */
    void setData(Type data);

    /*
    * @brief sets the next node that
    *   the current node points to
    * 
    * @param next pointer to the
    *   node that the current node
    *   will point to
    */
    void setNext(ListNode<Type>* next);

    /*
    * @brief returns data stored
    *   by the node
    * 
    * @return stored value
    */
    Type& getData(void);

    /*
    * @brief returns a pointer
    *   to the next node
    * 
    * @return pointer to the 
    *   next node
    */
    ListNode<Type>* getNext(void);

private:

	Type mData;
	ListNode<Type>* mNext;

};

template<typename Type>
ListNode<Type>::ListNode(Type data) : mData(data), mNext(nullptr) {}

template<typename Type>
void ListNode<Type>::setNext(ListNode<Type>* next) { mNext = next; }

template<typename Type>
ListNode<Type>* ListNode<Type>::getNext(void) { return mNext; }

template<typename Type>
void ListNode<Type>::setData(Type data) { mData = data; }

template<typename Type>
Type& ListNode<Type>::getData(void) { return mData; }

#endif
