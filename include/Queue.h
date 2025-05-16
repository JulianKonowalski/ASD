#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include "ListNode.h"

/*
* @brief Generic queue container
*   that can store any data
*   type by allocating memory
*   on the heap
* 
* @tparam Type The type parameter
*   determining the type of data
*   stored in the container
*/
template<typename Type>
class Queue {
public:

    /*
    * @brief initializes an
    *   empty queue object
    */
    Queue(void);

    /*
    * @brief adds a value
    *   at the back of the
    *   queue
    * 
    * @param data value to
    *   be added to the queue
    */
	void enqueue(Type data);

    /*
    * @brief returns a value
    *   from the front of the
    *   queue and deletes it
    *   from the queue
    * 
    * @throw std::runtime_error
    *   if the queue is empty
    * 
    * @return value fetched from
    *   the front of the queue
    */
	Type dequeue(void);

    /*
    * @brief returns a value
    *   from the front of the 
    *   queue without deleting
    *   it from the queue
    * 
    * @throw std::runtime_error
    *   if the queue is empty
    * 
    * @return value fetched from
    *   the front of the queue
    */
	Type first(void);

    /*
    * @brief returns a value
    *   from the back of the 
    *   queue without deleting
    *   it from the queue
    * 
    * @throw std::runtime_error
    *   if the queue is empty
    * 
    * @return value fetched from
    *   the back of the queue
    */
	Type last(void);

    /*
     * @brief returns true
     *  if the queue is empty
     *
     * @return true if empty,
     *  false otherwise
     */
    bool isEmpty(void);

private:

	ListNode<Type>* mHead;
	ListNode<Type>* mTail;

};

template<typename Type>
Queue<Type>::Queue(void) : mHead(nullptr), mTail(nullptr) {}

template<typename Type>
void Queue<Type>::enqueue(Type data) {
    if (!mHead) {
        mHead = mTail = new ListNode<Type>(data);
    } else {
        mTail->setNext(new ListNode<Type>(data));
        mTail = mTail->getNext();
    }
}

template<typename Type>
Type Queue<Type>::dequeue(void) {
    if (!mHead)
        throw std::runtime_error("Tried to dequeue an empty queue");
    Type data = mHead->getData();
    ListNode<Type>* tmp = mHead;
    mHead = mHead->getNext();
    delete tmp;
    return data;
}

template<typename Type>
Type Queue<Type>::first(void) {
    if (!mHead)
        throw std::runtime_error("Tired to fetch the first element of an empty queue");
    return mHead->getData();
}

template<typename Type>
Type Queue<Type>::last(void) {
    if (!mHead)
        throw std::runtime_error("Tired to fetch the last element of an empty queue");
    return mTail->getData();
}

template<typename Type>
bool Queue<Type>::isEmpty(void) { return mHead ? false : true; } 

#endif
