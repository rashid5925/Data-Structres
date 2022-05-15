#include <iostream>

using namespace std;

struct Stu
{
    int id;
    float marks;
    Stu *next = NULL;
};

Stu *first = NULL, *last = NULL;

void display();
void insertEnd();
void swap_address(int key1, int key2);

int main()
{
    int exit = 1;

    do
    {
        cout << "Enter the command number you want to execute\n";
        cout << "1. Display all records\n";
        cout << "2. Insert a record at end\n";
        cout << "3.Swap by Address\n";
        cout << "0.Exit\n";
        cin >> exit;
        cout << "\n";

        switch (exit)
        {
        case 0:
            cout << "Exiting.....\n";
            break;
        case 1:
            display();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            cout << "\n";
            int a, b;
            cout << "Enter IDs of both nodes to be swapped: ";
            cin >> a;
            cin >> b;
            swap_address(a, b);
            break;
        default:
            cout << "Wrong Number Entered. Please try again.....\n";
            break;
        }
    } while (exit != 0);

    return 0;
}

Stu *search(int key)
{
    Stu *p = first;
    while (p != NULL)
    {
        if (p->id == key)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void display()
{
    Stu *p = first;
    cout << "\n";
    if (p == NULL)
    {
        cout << "No record to show\n";
    }
    else
    {
        while (p != NULL)
        {
            cout << "ID: " << p->id << " Marks: " << p->marks << "\n";
            p = p->next;
        }
    }
    cout << "\n";
}

void insertEnd()
{
    cout << "\n";
    Stu *curr = new Stu;
    cout << "Enter Student ID: ";
    cin >> curr->id;
    cout << "Enter Student marks: ";
    cin >> curr->marks;
    if (first == NULL)
    {
        first = last = curr;
    }
    else
    {
        last->next = curr;
        last = curr;
    }
    cout << "\n";
}

void insertAfter(Stu *after, Stu *added)
{
    if (after == NULL)
    {
        added->next = first;
        first = added;
        return;
    }
    if (after == last)
    {
        last->next = added;
        last = added;
        return;
    }
    Stu *p = search(after->id);
    if (p == NULL)
    {
        cout << "ID not found\n";
    }
    else
    {
        added->next = p->next;
        p->next = added;
    }
    cout << "\n";
}

void swap_address(int key1, int key2)
{
    Stu *node1 = first, *prev1 = NULL, *node2 = first, *prev2 = NULL;
    while (node1 != NULL && node1->id != key1)
    {
        prev1 = node1;
        node1 = node1->next;
    }
    while (node2 != NULL && node2->id != key2)
    {
        prev2 = node2;
        node2 = node2->next;
    }
    if (node1 != NULL && node2 != NULL)
    {
        if (prev1 != NULL && node1 != last)
        {
            prev1->next = node2;
        }
        else if (node1 == last)
        {
            prev1->next = node2;
            last = node2;
        }
        else
        {
            first = node2;
        }
        
        if (prev2 != NULL && node2 != last)
        {
            prev2->next = node1;
        }
        else if (node2 == last)
        {
            prev2->next = node1;
            last = node1;
        }
        else
        {
            first = node1;
        }

        Stu *temp = node2->next;
        node2->next = node1->next;
        node1->next = temp;
    }
    else
    {
        cout << "ID not Found\n";
    }
}
