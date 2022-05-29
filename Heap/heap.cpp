#include <iostream>

using namespace std;

int heap[50];
int last = -1;

void insert(int x);
int remove();
void display();

int main()
{
    int exit = 1;
    do
    {
        cout << "Enter number to perform operation\n"
             << "1. Insert\n"
             << "2. Remove\n"
             << "3. Display Heap\n"
             << "0. Exit\n";
        cin >> exit;

        switch (exit)
        {
        case 0:
            cout << "Exit...\n";
            break;
        case 1:
            cout << "\n";
            int element;
            cout << "Enter element too insert: ";
            cin >> element;
            insert(element);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            cout << "Removed element is: " << remove() << "\n";
            cout << "\n";
            break;
        case 3:
            display();
            break;
        default:
            cout << "Wrong input\n";
            break;
        }
    } while (exit != 0);
    return 0;
}

void insert(int x)
{
    if (last == -1)
    {
        heap[++last] = x;
    }
    else
    {
        heap[++last] = x;
        int i = last;
        while (i > 0 && heap[i] < heap[(i - 1) / 2])
        {
            int temp = heap[i];
            heap[i] = heap[(i - 1) / 2];
            heap[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }
}

int remove()
{
    if (last == -1)
    {
        cout << "Empty\n";
        return -1;
    }
    int value = heap[0];
    heap[0] = heap[last--];
    int i = 0;
    int smaller = 0;
    int temp;
    while (last > (2 * i + 1) || last > (2 * i + 2))
    {
        if (last > (2 * i + 1) && last > (2 * i + 2))
        {
            smaller = heap[2 * i + 1] < heap[2 * i + 2] ? (2 * i + 1) : (2 * i + 2);
        }
        else if (last > (2 * i + 1))
        {
            smaller = 2 * i + 1;
        }
        else
        {
            smaller = 2 * i + 2;
        }
        if (heap[smaller] < heap[i])
        {
            temp = heap[smaller];
            heap[smaller] = heap[i];
            heap[i] = temp;
            i = smaller;
        }
        else
        {
            return value;
        }
    }
    return value;
}

void display()
{
    cout << "\n";
    for (int i = 0; i <= last; i++)
    {
        cout << heap[i] << " ";
    }
    cout << "\n";
}
