#include <iostream>

using namespace std;

struct stu
{
    char data;
    stu *next = NULL;
    stu *prev = NULL;
};

stu *top = NULL;

void push(char element);
char pop();
void display();
bool check_palindrome();

int main()
{
    int exit = 1;
    do
    {
        cout << "Enter number to perform operation\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. Display Stack\n"
             << "4. Check palindrome\n"
             << "0. Exit\n";
        cin >> exit;

        switch (exit)
        {
        case 0:
            cout << "Exit...\n";
            break;
        case 1:
            cout << "\n";
            char element;
            cout << "Enter element too add: ";
            cin >> element;
            push(element);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            char poped;
            poped = pop();
            cout << "Char poped is: " << poped << "\n";
            cout << "\n";
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "\n";
            if (check_palindrome())
            {
                cout << "String is palindrome\n";
            }
            else
            {
                cout << "Not a palindrome\n";
            }
            cout << "\n";
            break;
        default:
            cout << "Wrong input\n";
            break;
        }
    } while (exit != 0);
    
    return 0;
}

void push(char element)
{
    stu *p = new stu;
    p->data = element;
    if (top == NULL)
    {
        top = p;
    }
    else
    {
        top->prev = p;
        p->next = top;
        top = p;
    }
}

char pop()
{
    char element;
    if (top == NULL)
    {
        cout << "Empty";
        return element;
    }
    else if (top->next == NULL)
    {
        element = top->data;
        delete top;
        top = NULL;
        return element;
    }
    else
    {
        element = top->data;
        top = top->next;
        top->prev = NULL;
        return element;
    }
    
}

void display()
{
    if (top == NULL)
    {
        cout << "Empty\n";
    }
    else
    {
        stu *p = top;
        while (p != NULL)
        {
            cout << "Data: " << p->data << "\n";
            p = p->next;
        }
    }
}

bool check_palindrome()
{
    string str;
    cout << "Enter string to check palindrome: ";
    cin >> str;
    top = NULL;
    cout << "\n";
    for (int i = 0; i < str.length(); i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (!(pop() == str[i]))
        {
            return false;
        }
    }
    return true;
}