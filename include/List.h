#ifndef LIST_H
#define LIST_H

#include "ListNode.h"

/*
* @brief Generic list container
*   that can store any data
*   type by allocating memory
*   on the heap
* 
* @tparam Type The type parameter
*   determining the type of data
*   stored in the container
*/
template<typename Type>
class List {
public:

    /*
    * @brief initialises an
    *   empty list object
    */
    List(void);

    /*
    * @brief inserts data
    *   at the back of the list
    * 
    * @param data value to be
    *   inserted into the list
    */
	void insert(Type data);

    /*
    * @brief removes a value
    *   from the list
    * 
    * @param key value to be
    *   removed from the list
    */
	void remove(Type key);

    /*
    * @brief finds a value
    *   in the list
    * 
    * @param key value to search
    *   for in the list
    * 
    * @return pointer to a node
    *   that stores the key value.
    *   If there's no such node
    *   it returns nullptr
    */
	ListNode<Type>* find(Type key);

    /*
    * @brief checks if the 
    *   list is empty
    * 
    * @return true if empty
    */
	bool isEmpty(void);

private:

	ListNode<Type>* mHead;

};

template<typename Type>
List<Type>::List(void) : mHead(nullptr) {}

template<typename Type>
void List<Type>::insert(Type data) {
    if (!mHead) {
        mHead = new ListNode<Type>(data);
    } else {
        ListNode<Type>* ptr = mHead;
        while (ptr->getNext())
            ptr = ptr->getNext();
        ptr->setNext(new ListNode<Type>(data));
    }
}

template<typename Type>
ListNode<Type>* List<Type>::find(Type key) {
    ListNode<Type>* ptr = mHead;
    while (ptr && ptr->getData() != key)
        ptr = ptr->getNext();
    return ptr;
}

template<typename Type>
void List<Type>::remove(Type key) {
    if (!mHead) return;

    if (mHead->getData() == key) {
        ListNode<Type>* tmp = mHead;
        mHead = mHead->getNext();
        delete tmp;
        return;
    }

    ListNode<Type>* ptr = mHead;
    while (ptr->getNext()
        && ptr->getNext()->getData() != key)
        ptr = ptr->getNext();

    if (!ptr->getNext()) return;

    ListNode<Type>* tmp = ptr->getNext();
    ptr->setNext(ptr->getNext()->getNext());
    delete tmp;
}

template<typename Type>
bool List<Type>::isEmpty(void) {
    return !mHead;
}

#endif
