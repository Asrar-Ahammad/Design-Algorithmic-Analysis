#include <iostream>
#include <time.h>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int s1, s2;
    s1 = mid - low + 1;
    s2 = high - mid;
    int a1[s1], a2[s2];

    for (int i = 0; i < s1; i++)
    {
        a1[i] = arr[low + i];
    }
    for (int j = 0; j < s2; j++)
    {
        a2[j] = arr[mid + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = low;

    while (i < s1 && j < s2)
    {
        if (a1[i] <= a2[j])
        {
            arr[k] = a1[i];
            i++;
        }
        else
        {
            arr[k] = a2[j];
            j++;
        }
        k++;
    }
    while (i < s1)
    {
        arr[k] = a1[i];
        i++;
        k++;
    }
    while (j < s2)
    {
        arr[k] = a2[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        merge_sort(arr, low, mid); // dividing the elements
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high); // merging elements after sorting
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
    int size = 150;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }
    cout << "\nThe array before sort :";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    clock_t time_req;
    time_req = clock();
    merge_sort(arr, 0, size - 1);
    time_req = clock() - time_req;
    cout << "\nThe sorted array :";
    print_array(arr, size);
    cout << "\nThe time taken in seconds :" << (double)time_req / CLOCKS_PER_SEC;
    return 0;
}