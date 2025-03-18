#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdexcept>


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
class Node {
public:

    /*
    * @brief initialises a node
    *   object
    * 
    * @param data initial value
    *   stored in the node
    */
    Node(Type data);

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
    void setNext(Node<Type>* next);

    /*
    * @brief returns data stored
    *   by the node
    * 
    * @return stored value
    */
    Type getData(void);

    /*
    * @brief returns a pointer
    *   to the next node
    * 
    * @return pointer to the 
    *   next node
    */
    Node<Type>* getNext(void);

private:

	Type mData;
	Node<Type>* mNext;

};

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
	Node<Type>* find(Type key);

    /*
    * @brief checks if the 
    *   list is empty
    * 
    * @return true if empty
    */
	bool isEmpty(void);

private:

	Node<Type>* mHead;

};


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

	Node<Type>* mHead;

};


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

private:

	Node<Type>* mHead;
	Node<Type>* mTail;

};


/* NODE */

template<typename Type>
Node<Type>::Node(Type data) : mData(data), mNext(nullptr) {}

template<typename Type>
void Node<Type>::setNext(Node<Type>* next) { mNext = next; }

template<typename Type>
Node<Type>* Node<Type>::getNext(void) { return mNext; }

template<typename Type>
void Node<Type>::setData(Type data) { mData = data; }

template<typename Type>
Type Node<Type>::getData(void) { return mData; }


/* LIST */

template<typename Type>
List<Type>::List(void) : mHead(nullptr) {}

template<typename Type>
void List<Type>::insert(Type data) {
    if (!mHead) {
        mHead = new Node<Type>(data);
    } else {
        Node<Type>* ptr = mHead;
        while (ptr->getNext())
            ptr = ptr->getNext();
        ptr->setNext(new Node<Type>(data));
    }
}

template<typename Type>
Node<Type>* List<Type>::find(Type key) {
    Node<Type>* ptr = mHead;
    while (ptr && ptr->getData() != key)
        ptr = ptr->getNext();
    return ptr;
}

template<typename Type>
void List<Type>::remove(Type key) {
    if (!mHead) return;

    if (mHead->getData() == key) {
        Node<Type>* tmp = mHead;
        mHead = mHead->getNext();
        delete tmp;
        return;
    }

    Node<Type>* ptr = mHead;
    while (ptr->getNext()
        && ptr->getNext()->getData() != key)
        ptr = ptr->getNext();

    if (!ptr->getNext()) return;

    Node<Type>* tmp = ptr->getNext();
    ptr->setNext(ptr->getNext()->getNext());
    delete tmp;
}

template<typename Type>
bool List<Type>::isEmpty(void) {
    return !mHead;
}


/* STACK */

template<typename Type>
Stack<Type>::Stack(void) : mHead(nullptr) {}

template<typename Type>
void Stack<Type>::push(Type data) {
    Node<Type>* newElem = new Node<Type>(data);
    newElem->setNext(mHead);
    mHead = newElem;
}

template<typename Type>
Type Stack<Type>::pop(void) {
    if (!mHead)
        throw std::runtime_error("Tried to pop from an empty stack");
    Node<Type>* tmp = mHead;
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


/* QUEUE */

template<typename Type>
Queue<Type>::Queue(void) : mHead(nullptr), mTail(nullptr) {}

template<typename Type>
void Queue<Type>::enqueue(Type data) {
    if (!mHead) {
        mHead = mTail = new Node<Type>(data);
    } else {
        mTail->setNext(new Node<Type>(data));
        mTail = mTail->getNext();
    }
}

template<typename Type>
Type Queue<Type>::dequeue(void) {
    if (!mHead)
        throw std::runtime_error("Tried to dequeue an empty queue");
    Type data = mHead->getData();
    Node<Type>* tmp = mHead;
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


#endif // !DATA_STRUCTURES_H
