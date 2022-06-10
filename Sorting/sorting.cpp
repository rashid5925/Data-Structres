#include <iostream>

using namespace std;

void bubble_sort (int *arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < (size - 1) - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection_sort (int *arr, int size)
{
    int min, temp;
    for (int i = 0; i < size; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }   
    }
}

void insertion_sort (int *arr, int size)
{
    int j;
    for (int i = 0; i < size; i++)
    {
        j = i;
        while (j != 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}


int main ()
{
    int arr[] = {3, 12, 4, 1, 5, 11, 2, -2, 6};
    bubble_sort(arr, 9);
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";

    int arr1[] = {3, 12, 4, 1, 5, 2, -2, 6};
    selection_sort(arr1, 8);
    for (int i = 0; i < sizeof(arr1) / sizeof(int); i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\n";

    int arr2[] = {8, 5, 3, 12, 6, 7, 4, 1};
    insertion_sort(arr2, 8);
    for (int i = 0; i < sizeof(arr2) / sizeof(int); i++)
    {
        cout << arr2[i] << " ";
    }
    cout << "\n";

    return 0;
}