#include <iostream>
#include <cstdlib>

#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "Sorting.h"
#include "BST.h"

static constexpr unsigned short ARR_LENGTH = 10;
static constexpr unsigned int MAX_VAL = 20; 

void print_array(int* arr, const int& arrSize) {
    for(int i = 0; i < arrSize; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void dataStructuresDemo(void) {
    std::cout << "\n\nData Structures Demo:\n\n";

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

void sortingDemo(void) {

    std::cout << "\n\nSorting Demo:\n\n";

    /*
     * I know this method produces 
     * the same outcome every time, 
     * but it makes it easier to debug.
     */
    int mainArray[ARR_LENGTH];
    for (int i = 0; i < ARR_LENGTH; ++i)
        mainArray[i] = rand() % (MAX_VAL + 1);

    std::cout << "Original array:\t";
    print_array(mainArray, ARR_LENGTH);
    std::cout << "\n";

    for (int i = 0; i < 5; ++i) {

        /*
         * Copy values from the original 
         * array to the secondary array.
         */
        int secondaryArray[ARR_LENGTH];
        for (int i = 0; i < ARR_LENGTH; ++i)
            secondaryArray[i] = mainArray[i];

        /*
         * Use a different algorithm on 
         * each iteration.
         */
        switch(i) {
            case 0:
                std::cout << "Merge sort:\t";
                merge_sort(secondaryArray, 0, ARR_LENGTH - 1);
                break;
            case 1:
                std::cout << "Quick sort:\t";
                quick_sort(secondaryArray, 0, ARR_LENGTH - 1);
                break;
            case 2:
                std::cout << "Heap sort:\t";
                heap_sort(secondaryArray, ARR_LENGTH);
                break;
            case 3:
                std::cout << "Counting sort:\t";
                counting_sort(secondaryArray, ARR_LENGTH);
                break;
            case 4:
                std::cout << "Radix sort:\t";
                radix_sort(secondaryArray, ARR_LENGTH);
                break;
        }
        print_array(secondaryArray, ARR_LENGTH);
    }
}

void BSTDemo(void) {
    BST<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(4);
    bst.insert(7);
    bst.insert(6);

    std::cout << "Initial binary search tree:";
    std::cout << "\nPre-Order:\t";
    bst.preorder([](const int& value){ std::cout << value << " "; });
    std::cout << "\nIn-Order:\t";
    bst.inorder([](const int& value){ std::cout << value << " "; });
    std::cout << "\nPost-Order:\t";
    bst.postorder([](const int& value){ std::cout << value << " "; });
    std::cout << "\nRow-Order:\t";
    bst.roworder([](const int& value){ std::cout << value << " "; });

    std::cout << "\n";

    auto result = bst.search(5);
    std::cout << "Searching for 5...\n";
    if (result) { std::cout << "Search result: " << *result << "\n"; }
    else { std::cout << "Search unsuccessful\n"; }

    result = bst.search(10);
    std::cout << "Searching for 10...\n";
    if (result) { std::cout << "Search result: " << *result << "\n"; } 
    else { std::cout << "Search unsuccessful\n"; }

    bst.remove(5);
    std::cout << "After removing 5:\n";
    bst.inorder([](const int& value){ std::cout << value << " "; });
    std::cout << "\n";

    bst.remove(3);
    std::cout << "After removing 3:\n";
    bst.inorder([](const int& value){ std::cout << value << " "; });
    std::cout << "\n";

    result = bst.minimum();
    std::cout << "Searching for min element...\n";
    if(result) { std::cout << "Min element: " << *result << "\n"; }
    else { std::cout << "The tree is empty\n"; }

    result = bst.maximum();
    std::cout << "Searching for max element...\n";
    if(result) { std::cout << "Max element: " << *result << "\n"; }
    else { std::cout << "The tree is empty\n"; }
}

int main(void) {
    //dataStructuresDemo();
    //sortingDemo();
    BSTDemo();
}
