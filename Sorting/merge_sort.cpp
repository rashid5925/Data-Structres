#include <iostream>
using namespace std;


void merge (int arr[], int first, int mid, int last)
{
    int temp[100];
    int index_a = first, index_b = mid + 1, index = first;
    while (index_a <= mid && index_b <= last)
    {
        if (arr[index_a] < arr[index_b])
        {
            temp[index] = arr[index_a];
            index_a++;
        }
        else
        {
            temp[index] = arr[index_b];
            index_b++;
        }
        index++;
    }
    
    while (index_a <= mid)
    {
        temp[index] = arr[index_a];
        index_a++;
        index++;
    }
    while (index_b <= last)
    {
        temp[index] = arr[index_b];
        index_b++;
        index++;
    }

    for (int i = first; i <= last; i++)
    {
        arr[i] = temp[i];
    }
}

void merge_sort (int arr[], int first, int last) 
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

int main () 
{
    int arr[] = {3, 12, 4, 1, 5, 11, 2, -2, 6};
    merge_sort(arr, 0, 8);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}