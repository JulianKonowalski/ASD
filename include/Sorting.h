#ifndef SORTING_H
#define SORTING_H

void merge_sort(int* arr, const int& lptr, const int& rptr);
void quick_sort(int* arr, const int& lptr, const int& rptr);
void heap_sort(int* arr, const int& arrSize);
void counting_sort(int* arr, const int& arrSize);
void radix_sort(int* arr, const int& arrSize);

#endif
