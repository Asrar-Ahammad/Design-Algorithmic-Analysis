#include <iostream>
using namespace std;

int main()
{
    int arr[] = {23, 34, 45, 67, 89, 90, 123, 256};
    int n = sizeof(arr) / sizeof(arr[0]);
    int val, count = 0;
    cout << "Enter element to search in array :";
    cin >> val;
    clock_t time;
    time = clock();
    int mid, low, high;
    high = n;
    low = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (val == arr[mid])
        {
            cout << "The value is at index :" << mid;
            break;
        }
        else if (val < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    time = clock() - time;
    cout << "\nThe time required in seconds :" << (double)time / CLOCKS_PER_SEC;
    return 0;
}