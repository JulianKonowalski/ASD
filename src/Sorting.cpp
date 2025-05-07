#include "Sorting.h"

#include <iostream>

#define _DBG std::cout <<
#define _ARRDBG(arr, start, end) for(int i = start; i < end + 1; ++i) { std::cout << arr[i] << " "; }

void merge_sort(int* arr, const int& lptr, const int& rptr) {

    /*
     * Check if the length of the 
     * array is greater than 1. 
     * If not, return from the 
     * function.
     */
    if (lptr == rptr) { return; }

    /*
     * Find the midpoint of the 
     * array in order to divide 
     * it into 2 halves.
     */
    int mid = (lptr + rptr) / 2;

    /*
     * Perform a merge sort for 
     * each of the halves.
     */
    merge_sort(arr, lptr, mid);
    merge_sort(arr, mid + 1, rptr);

    /*
     * Initialize temporary buffer 
     * for sorting. Left and right 
     * variables are used to traverse
     * both halvles of the buffer. 
     * I will use the midpoint as a 
     * limit for the left pointer and 
     * the rptr as a limit for the right
     * pointer. Both limits are shifted 
     * one place to the right, as I still 
     * want to visit rightmost elements of 
     * both halves.
     */
    int left = lptr, right = mid + 1, sptr = 0;
    int* sorted = new int[rptr - lptr + 1];

    /*
     * Start merging both halves 
     * "in place". If both pointers 
     * get out of range then stop 
     * merging and exit the loop.
     */
    while (left < mid + 1 || right < rptr + 1) {

        /*
         * If the left pointer is 
         * out of range, get the 
         * next value from the 
         * right half of the buffer.
         *
         * Otherwise check if the 
         * right pointer is out of 
         * range and get the value 
         * from the left half.
         *
         * If none of the above are 
         * true, compare values under 
         * both indexes and get the 
         * smaller one. After that 
         * increment the pointer that 
         * was used.
         */
        if (left >= mid + 1) {
            sorted[sptr++] = arr[right++];
        } else if (right >= rptr + 1) {
            sorted[sptr++] = arr[left++];
        } else {
            if(arr[left] < arr[right]) {
                sorted[sptr++] = arr[left++];
            } else {
                sorted[sptr++] = arr[right++];
            }
        }
    }

    /* 
     * Copy the values from the 
     * sorted buffer into the 
     * original array.
     */
    for (int i = lptr; i < rptr + 1; ++i)
        arr[i] = sorted[i - lptr];

    /*
     * Cleanup!
     */
    delete[] sorted;
}

void quick_sort(int* arr, const int& lptr, const int& rptr) {

    /*
     * Check if the range of the 
     * indexes makes sense. If the 
     * length of the array is equal 
     * to 1 or the left index is 
     * greater than the right index 
     * then return from the function.
     */
    if (lptr >= rptr) { return; }

    /*
     * Initialize additional indexes 
     * to traverse the array. Pivot will 
     * be the pivot value. Ideally its 
     * value should be the median value 
     * of the array, but for simplicity 
     * I will choose the rightmost value 
     * in the array.
     */
    int left = lptr, right = rptr - 1, pivot = arr[rptr];

    /*
     * Traverse the array and swap 
     * elements if the left element 
     * is greater than the pivot and 
     * the right element is smaller 
     * than the pivot.
     */
    while (left <= right) {
       
        /*
         * Increment the left pointer
         * while its smaller or equal 
         * to the rigth pointer and the 
         * value under its index is smaller 
         * than the pivot.
         */
        while (left <= right && arr[left] < pivot) 
            ++left;

        /*
         * Increment the right pointer
         * while its greater or equal 
         * to the left pointer and the 
         * value under its index is greater 
         * than the pivot.
         */
        while (right >= left && arr[right] > pivot)
            --right;
        
        /*
         * If pointers met or surpassed
         * each other break from the loop.
         */
        if (left >= right) { break; }

        /*
         * Otherwise swap their values. 
         */
        int tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }

    /*
     * After the sorting is done
     * swap the pivot and the value 
     * pointed to by the left pointer.
     *
     * After we break from the loop the 
     * left pointer points to the smallest
     * of all values greater than the 
     * pivot. By swapping the pivot with 
     * that value we can be certain that 
     * all values to the left of the pivot 
     * will be smaller and all values to the 
     * right will be greater.
     */
    arr[rptr] = arr[left];
    arr[left] = pivot;

    /*
     * Recursively call quick_sort
     * for left and the right half 
     * of the array. Don't include 
     * the pivot value, as it's 
     * already in the correct spot 
     * and doesn't need further sorting.
     */
    quick_sort(arr, lptr, left - 1);
    quick_sort(arr, left + 1, rptr);

}

void heap_sort(int* arr, const int& arrSize) {

    /*
     * Initialize the heap.
     */
    int* heap = new int[arrSize];
    int heapPtr = 0;

    /*
     * Here I will build the 
     * heap following the rule
     * that every parent has two 
     * children and every child 
     * has to be smaller than
     * its parent.
     */
    for (int i = 0; i < arrSize; ++i) {

        /*
         * First, insert data
         * at the very back
         * of the heap.
         */
        int idx = heapPtr++;
        heap[idx] = arr[i];

        /*
         * Then bring the node
         * up the data tree until 
         * it is smaller than its 
         * parent and greater than 
         * its children.
         */
        while (idx > 0) {
            int parentIdx = (idx - 1) / 2;
            if (heap[idx] < heap[parentIdx]) { break; } //all good
            int tmp = heap[parentIdx];
            heap[parentIdx] = heap[idx];
            heap[idx] = tmp;
            idx = parentIdx;
        }
    }

    /*
     * Here's the sorting logic. In 
     * order to sort the array I will 
     * pop each node from the front and
     * place it at the back (last free 
     * spot). After deleting the node 
     * from the heap I will adjust the 
     * remaining nodes to keep the 
     * integrity of the data structure.
     */
    for (int i = 0; i < arrSize; ++i) {
        
        /* 
         * Swap the first and the last 
         * nodes. I will use the heapPtr 
         * from before to point to the 
         * last free space in the array 
         * that is not a part of the heap.
         */
        int tmp = heap[0];
        heap[0] = heap[--heapPtr];
        heap[heapPtr] = tmp;
        
        /* 
         * Pull the first node down the
         * list by continuously swapping 
         * it with its greatest child. The 
         * loop stops when the node doesn't 
         * have any children or both of its 
         * children are smaller.
         */
        int idx = 0;
        while(2 * idx + 1 < heapPtr) {
            int lIdx = 2 * idx + 1;
            int rIdx = lIdx + 1;
            int maxIdx = 0;
            if (rIdx < heapPtr &&
                heap[rIdx] > heap[lIdx]) {
                maxIdx = rIdx;
            } else {
                maxIdx = lIdx;
            }
            if (heap[idx] < heap[maxIdx]) {
                tmp = heap[idx];
                heap[idx] = heap[maxIdx];
                heap[maxIdx] = tmp;
                idx = maxIdx;
            } else { break; }
        }
    }

    /*
     * Overwrite the original array 
     * with the data taken from the 
     * sorted heap.
     */
    for(int i = 0; i < arrSize; ++i)
        arr[i] = heap[i];

    /*
     * Cleanup!
     */
    delete[] heap; 

}

void counting_sort(int* arr, const int& arrSize) {

    /*
     * Find max and min values 
     * in the original array. 
     * We will use the max value
     * to establish the size of 
     * the temporary count array.
     * The minimum value will 
     * serve as the offset, allowing
     * for sorting negative numbers 
     * and (as a bonus) saving memory.
     */
    int max = arr[0], min = arr[0];
    for (int i = 0; i < arrSize; ++i) {
        max = max > arr[i] ? max : arr[i];
        min = min < arr[i] ? min : arr[i];
    }

    /*
     *  Initialize count array.
     *  It has to be 1 unit longer
     *  than the max value, for example
     *  if the max value == 0, the count
     *  array has to have a length of 1,
     *  if max == 1, len(count) == 2 etc.
     *  We also offset by minimum value 
     *  for the reasons given above.
     */
    int* count = new int[max - min + 1];
    for (int i = min; i < max + 1; ++i) 
        count[i - min] = 0;

    /*
     * Count values in the original array
     * and increment the position under
     * the value's index in the count 
     * array. The position is offset by
     * the minimum value from the original
     * array.
     */
    for (int i = 0; i < arrSize; ++i)
        ++count[arr[i] - min];

    /* 
     * Sort the original array by
     * filling it with values from
     * the count array. We insert
     * the ith value (offset by the)
     * minimum value n times, where
     * n is the number under ith index
     * in the count array.
     */
    int cntidx = 0, arridx = 0;
    while (cntidx < max - min + 1) {
        if (count[cntidx] == 0) {
            ++cntidx;
            continue;
        }
        arr[arridx++] = cntidx + min;
        --count[cntidx];
    }

    /*
     * Don't forget to cleanup
     * after ourselves!
     */
    delete[] count;

}

void radix_sort(int* arr, const int& arrSize) {

    /*
     * I will initialize two temporary
     * buffers to use during sorting.
     * PreSort buffer will store the 
     * outcome of the previous iteration
     * of the algorhithm and PostSort 
     * will be the destination buffer
     * that I'll be writing into.
     */
    int* preSort = new int[arrSize];
    int* postSort = new int[arrSize];
    for (int i = 0; i < arrSize; ++i)
        preSort[i] = postSort[i] = arr[i];

    /*
     * I will take a bit of a different
     * approach to this algorhithm. Instead
     * of operating in base 10 number system
     * I will sort by using bitwise shifts.
     * The core logic remains the same but
     * instead of having 10 possible number
     * values, there will only be 2, which
     * will simplify the code and save memory.
     * This shift variable will be incremented
     * with each iteration of the algorhithm.
     *
     * WARNING
     * This approach has some side effects.
     * It'll work ONLY on UNSIGNED values,
     * as the MSB of the number is responsible
     * for the sign. The algorhithm could be 
     * modified to work with negative numbers 
     * but I haven't implemented that 
     * functionality.
     */
    int shift = 0;

    while (true) {
        
        /*
         * This temporary count array
         * is analogous to the count 
         * array in the counting sort 
         * algorhithm above.
         */
        int count[2] = { 0, 0 };

        /* 
         * Here I will count how many
         * numbers have ones or zeroes 
         * on their ith position (indicated
         * by the shift variable) counting
         * from the left.
         */
        for (int i = 0; i < arrSize; ++i) {
            if ((preSort[i] >> shift) & 0b1) { ++count[1]; }
            else { ++count[0]; }
        }

        /*
         * If all numbers have 0 on the
         * ith position, that means that
         * we have shifted beyond the range
         * of the whole set, so there's no
         * more sorting to be done.
         */
        if (count[0] == arrSize) { break; } //sorted

        /*
         * The position array is a concept
         * specific to radix sort. It stores
         * information about where the current 
         * number should be positioned.
         *
         * If the number has a 0 on the ith
         * position, it is placed in the 
         * PostSort buffer under the index
         * stored in the 0th position of the
         * position buffer. If position[0] == 2, 
         * the number with a 0 on the ith position 
         * will be placed in postSort[2] and the 
         * position[0] value will be incremented.
         */
        int position[2] = { 0, count[0] };
        for (int i = 0; i < arrSize; ++i) {
            if ((preSort[i] >> shift) & 0b1) {
                postSort[position[1]++] = preSort[i];
            } else {
                postSort[position[0]++] = preSort[i];
            }
        }

        /*
         * Swap PreSort buffer pointer 
         * with the PostSort buffer pointer
         * and increment the shift variable
         */
        int* tmp = preSort;
        preSort = postSort;
        postSort = tmp;
        ++shift;
    }

    /*
     * Copy the preSort buffer
     * into the original array.
     *
     * After we exit the loop
     * the most recent version
     * of the array is stored
     * in the presort buffer and
     * that's why I don't use a 
     * postSort buffer here.
     */
    for (int i = 0; i < arrSize; ++i)
        arr[i] = preSort[i];

    /*
     * Cleanup!
     */
    delete[] preSort;
    delete[] postSort;

}
