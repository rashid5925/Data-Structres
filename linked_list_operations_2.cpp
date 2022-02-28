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
void reverse();
void alternative();
bool palindrome();
void recursive(Stu *p);
void swap();

int main()
{
    int exit = 1;

    do
    {
        cout << "Enter the command number you want to execute\n";
        cout << "1. Display all records\n";
        cout << "2. Insert a record at end\n";
        cout << "3. Display all records in reverse order (iterative)\n";
        cout << "4. Print alternative nodes\n";
        cout << "5. Check palindrome\n";
        cout << "6. Display all records in reverse order (recursion)\n";
        cout << "7. Swap 2 values\n";
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
            reverse();
            break;
        case 4:
            alternative();
            break;
        case 5:
            palindrome();
            if (palindrome())
            {
                cout << "******Palindrome******\n";
                cout << "\n";
            }
            else
            {
                cout << "******Not Palindrome******\n";
                cout << "\n";
            }
            break;
        case 6:
            recursive(first);
            break;
        case 7:
            swap();
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

int size()
{
    Stu *p = first;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void recursive(Stu *p)
{
    if (p->next != NULL)
    {
        recursive(p->next);
        cout << "ID: " << p->id << " Marks: " << p->marks << "\n";
    }
    else
    {
        cout << "ID: " << p->id << " Marks: " << p->marks << "\n";
    }
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

void reverse()
{
    cout << "\n";
    Stu *p = first, *p2, *k = last;
    while (k != first)
    {
        while (p != k)
        {
            p2 = p;
            p = p->next;
        }
        cout << "ID: " << p->id << "\n";
        k = p2;
        p = first;
    }
    cout << "ID: " << p->id << "\n";
    cout << "\n";
}

void alternative()
{
    cout << "\n";
    Stu *p = first, *p2, *k = last, *p_for = first;
    while (k != p_for && p_for->next != k)
    {
        cout << "ID: " << p_for->id << "\n";
        p_for = p_for->next;
        while (p != k)
        {
            p2 = p;
            p = p->next;
        }
        cout << "ID: " << p->id << "\n";
        k = p2;
        p = first;
    }
    cout << "ID: " << p_for->id << "\n";
    if (p_for->next == k)
    {
        cout << "ID: " << k->id << "\n";
    }
    cout << "\n";
}

bool palindrome()
{
    cout << "\n";
    int length = size(), count = 0;
    if (length % 2 != 0)
    {
        length = (length / 2) + 1;
    }
    else
    {
        length = length / 2;
    }
    int arr_for[length];
    int arr_back[length];

    Stu *p = first, *p2, *k = last, *p_for = first;
    while (k != p_for && p_for->next != k)
    {
        arr_for[count] = p_for->id;
        p_for = p_for->next;
        while (p != k)
        {
            p2 = p;
            p = p->next;
        }
        arr_back[count] = p->id;
        k = p2;
        p = first;
        count++;
    }
    arr_for[count] = p_for->id;
    arr_back[count] = k->id;
    cout << "\n";

    for (int i = 0; i < length; i++)
    {
        if (arr_for[i] != arr_back[i])
        {
            return false;
        }
    }
    return true;
}

void swap()
{
    int id1, id2, temp_id;
    float temp_marks;
    cout << "Enter 1st ID: ";
    cin >> id1;
    cout << "Enter 2nd ID: ";
    cin >> id2;
    Stu *p1 = search(id1);
    Stu *p2 = search(id2);
    if (p1 != NULL && p2 != NULL)
    {
        temp_id = p1->id;
        p1->id = p2->id;
        p2->id = temp_id;
        temp_marks = p1->marks;
        p1->marks = p2->marks;
        p2->marks = temp_marks;
    }
    else
    {
        cout << "ID not found\n";
        cout << "\n";
    }
}