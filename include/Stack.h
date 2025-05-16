#ifndef STACK_H
#define STACK_H

#include <stdexcept>
#include "ListNode.h"

/*
* @brief Generic stack container
*   that can store any data
*   type by allocating memory
*   on the heap
* 
* @tparam Type The type parameter
*   determining the type of data
*   stored in the container
*/
template<typename Type>
class Stack {
public:

    /*
    * @brief initializes an
    *   empty stack object
    */
    Stack(void);
	
    /*
    * @brief pushes a value
    *   on top of the stack
    * 
    * @param data value to
    *   be pushed onto the 
    *   stack
    */
	void push(Type data);

    /*
    * @brief returns the value
    *   from top of the stack
    *   and deletes it from the
    *   stack
    * 
    * @throw std::runtime_error
    *   if the stack is empty
    * 
    * @return value popped
    *   from the top of the
    *   stack
    */
	Type pop(void);

    /*
    * @brief returns a value
    *   from top of the stack
    *   without deleting it
    * 
    * @throw std::runtime_error
    *   if the stack is empty
    * 
    * @return value stored at
    *   the top of the stack
    */
	Type top(void);

    /*
    * @brief checks if the
    *   stack is empty
    * 
    * @return true if empty
    */
	bool isEmpty(void);

private:

	ListNode<Type>* mHead;

};

template<typename Type>
Stack<Type>::Stack(void) : mHead(nullptr) {}

template<typename Type>
void Stack<Type>::push(Type data) {
    ListNode<Type>* newElem = new ListNode<Type>(data);
    newElem->setNext(mHead);
    mHead = newElem;
}

template<typename Type>
Type Stack<Type>::pop(void) {
    if (!mHead)
        throw std::runtime_error("Tried to pop from an empty stack");
    ListNode<Type>* tmp = mHead;
    mHead = mHead->getNext();
    Type data = tmp->getData();
    delete tmp;
    return data;
}

template<typename Type>
Type Stack<Type>::top(void) {
    return mHead->getData();
}

template<typename Type>
bool Stack<Type>::isEmpty(void) {
    return !mHead;
}

#endif
