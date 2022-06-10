#include <iostream>

using namespace std;

int linear_search (int *arr, int key)
{
    for (int i = 0; i < sizeof(arr); i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binary_search (int *arr, int key, int beg, int end)
{
    if (end >= beg)
    {
        int mid = (beg + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            return binary_search(arr, key, beg, mid - 1);
        }
        else
        {
            return binary_search(arr, key, mid + 1, end);
        }
    }
    return -1;
}

int binary_search_iter (int *arr, int key, int beg, int end)
{
    int mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            beg = mid + 1;
        }
    }
    return -1;
}


int main () 
{
    int arr[] = {3, 4, 6, 1, 2, 8};
    cout << linear_search(arr, 8) << endl;

    int bin[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << binary_search(bin, 3, 0, 9) << endl;

    int bin_iter[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << binary_search_iter(bin_iter, 9, 0, 9) << endl;

    return 0;
}
