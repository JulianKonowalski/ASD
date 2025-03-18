#include <iostream>

#include "dataStructures.h"

int main(void) {

    std::cout << "List demo:\n";
    List<int> list;
    for (int i = 0; i < 10; ++i) {
        list.insert(i);
        std::cout << "Inserted " << i << " into a list\n";
    }
    std::cout << "\n";
    for (int i = 0; i < 10; ++i) {
        list.remove(i);
        std::cout << "Removed " << i << " from a list\n";
    }


    std::cout << "\n\nStack demo:\n";
    Stack<int> stack;
    for (int i = 0; i < 10; ++i) {
        stack.push(i);
        std::cout << "Pushed " << i << " onto the stack\n";
    }
    std::cout << "\n";
    for (int i = 0; i < 10; ++i) {
        int data = stack.pop();
        std::cout << "Poped " << data << " from the stack\n";
    }

    std::cout << "\n\nQueue demo:\n";
    Queue<int> queue;
    for (int i = 0; i < 10; ++i) {
        queue.enqueue(i);
        std::cout << "Added " << i << " to the queue\n";
    }
    std::cout << "\n";
    for (int i = 0; i < 10; ++i) {
        int data = queue.dequeue();
        std::cout << "Dequeued " << data << " from the queue\n";
    }

}
