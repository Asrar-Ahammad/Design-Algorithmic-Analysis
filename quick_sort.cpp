#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high); // finding pivot element

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void print_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {96, 52357, 438, 2327, 1345, 2683, 67, 8763};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array :";
    print_array(arr, size);

    cout << "\nSorted array :";
    quick_sort(arr, 0, size - 1);
    print_array(arr, size);
    return 0;
}