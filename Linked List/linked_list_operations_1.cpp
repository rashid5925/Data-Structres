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
void insertStart();
void insertBefore();
void insertAfter();
void deleteStart();
void deleteEnd();
void deleteAfter();
void deleteBefore();
void deleteSpecific();

int main()
{
    int exit = 1;

    do
    {
        cout << "Enter the command number you want to execute\n";
        cout << "1. Display all records\n";
        cout << "2. Insert a record at end\n";
        cout << "3. Insert a record at start\n";
        cout << "4. Insert a record before specific value\n";
        cout << "5. Insert a record after specific value\n";
        cout << "6. Delete a record from start\n";
        cout << "7. Delete a record from end\n";
        cout << "8. Delete a record after specific value\n";
        cout << "9. Delete a record before specific value\n";
        cout << "10.Delete a specific record\n";
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
            insertStart();
            break;
        case 4:
            insertBefore();
            break;
        case 5:
            insertAfter();
            break;
        case 6:
            deleteStart();
            break;
        case 7:
            deleteEnd();
            break;
        case 8:
            deleteAfter();
            break;
        case 9:
            deleteBefore();
            break;
        case 10:
            deleteSpecific();
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

void insertStart()
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
        curr->next = first;
        first = curr;
    }
    cout << "\n";
}

void insertBefore()
{
    cout << "\n";
    int key;
    cout << "Enter ID before which record to be inserted: ";
    cin >> key;
    Stu *p = search(key);
    if (p == NULL)
    {
        cout << "ID not found\n";
    }
    else if (p->next == first)
    {
        Stu *curr = new Stu;
        cout << "Enter Student ID: ";
        cin >> curr->id;
        cout << "Enter Student marks: ";
        cin >> curr->marks;
        curr->next = first;
        first = curr;
    }
    else
    {
        Stu *curr = new Stu;
        cout << "Enter Student ID: ";
        cin >> curr->id;
        cout << "Enter Student marks: ";
        cin >> curr->marks;
        Stu *p2 = first;
        while (p2->id != key && p2 != NULL)
        {
            p = p2;
            p2 = p2->next;
        }
        curr->next = p->next;
        p->next = curr;
    }
    cout << "\n";
}

void insertAfter()
{
    cout << "\n";
    int key;
    cout << "Enter ID after which record to be inserted: ";
    cin >> key;
    Stu *p = search(key);
    if (p == NULL)
    {
        cout << "ID not found\n";
    }
    else if (p->next == NULL)
    {
        Stu *curr = new Stu;
        cout << "Enter Student ID: ";
        cin >> curr->id;
        cout << "Enter Student marks: ";
        cin >> curr->marks;
        last->next = curr;
        last = curr;
        delete p;
    }
    else
    {
        Stu *curr = new Stu;
        cout << "Enter Student ID: ";
        cin >> curr->id;
        cout << "Enter Student marks: ";
        cin >> curr->marks;
        curr->next = p->next;
        p->next = curr;
    }
    cout << "\n";
}

void deleteStart()
{
    cout << "\n";
    if (first == NULL)
    {
        cout << "Empty\n";
    }
    else
    {
        first = first->next;
    }
    cout << "\n";
}

void deleteEnd()
{
    cout << "\n";
    if (first == NULL)
    {
        cout << "Empty\n";
    }
    else
    {
        Stu *p = first, *pre_p;
        while (p->next != NULL)
        {
            pre_p = p;
            p = p->next;
        }
        last = pre_p;
        pre_p->next = NULL;
        delete p;
    }
    cout << "\n";
}

void deleteAfter()
{
    cout << "\n";
    int key;
    cout << "Enter ID after which record to be deleted: ";
    cin >> key;
    Stu *p = search(key);
    if (p == NULL)
    {
        cout << "ID not found\n";
    }
    else if (p->next == NULL)
    {
        cout << "No record found after entered one\n";
    }
    else
    {
        p->next = p->next->next;
    }
    cout << "\n";
}

void deleteBefore()
{
    cout << "\n";
    int key;
    cout << "Enter ID before which record to be deleted: ";
    cin >> key;
    Stu *p = search(key);
    if (p == NULL)
    {
        cout << "ID not found\n";
    }
    else if (p == first)
    {
        cout << "No record found before entered one\n";
    }
    else
    {
        Stu *p2 = first, *pre_p, *pre_pre_p;
        while (p2->next != NULL && p2->id != key)
        {
            pre_pre_p = pre_p;
            pre_p = p2;
            p2 = p2->next;
        }
        pre_pre_p->next = pre_p->next;
        delete pre_p;
    }
    cout << "\n";
}

void deleteSpecific()
{
    cout << "\n";
    int key;
    cout << "Enter ID which record to be deleted: ";
    cin >> key;
    Stu *p = search(key);
    if (p == NULL)
    {
        cout << "ID not found\n";
    }
    else if (p == first)
    {
        first = first->next;
    }
    else if (p == last)
    {
        Stu *p = first, *pre_p;
        while (p->next != NULL)
        {
            pre_p = p;
            p = p->next;
        }
        last = pre_p;
        pre_p->next = NULL;
        delete p;
    }
    else
    {
        Stu *p2 = first, *pre_p;
        while (p2->next != NULL && p2->id != key)
        {
            pre_p = p2;
            p2 = p2->next;
        }
        pre_p->next = p2->next;
        delete p2;
    }
    cout << "\n";
}
