#include <iostream>

using namespace std;

struct bst
{
    int id;
    bst *left = NULL;
    bst *right = NULL;
};

bst *root = NULL;

void insert(int x);
bool search(int x);
void in_order(bst *p);

int main()
{
    int exit = 1;
    do
    {
        cout << "Enter number to perform operation\n"
             << "1. Insert\n"
             << "2. Search\n"
             << "3. in_order\n"
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
            cout << "Enter element too add: ";
            cin >> element;
            insert(element);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            element;
            cout << "Enter element too search: ";
            cin >> element;
            if (search(element))
            {
                cout << element << " found";
            }
            else
            {
                cout << element << " NOT found";
            }
            cout << "\n";
            break;
        case 3:
            in_order(root);
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
    bst *p = new bst;
    p->id = x;
    if (root == NULL)
    {
        root = p;
    }
    else
    {
        bst *q = root;
        bst *k = NULL;
        while (q != NULL)
        {
            k = q;
            if (q->id > x)
            {
                q = q->left;
            }
            else
            {
                q = q->right;
            }
        }
        if (k->id > x)
        {
            k->left = p;
        }
        else
        {
            k->right = p;
        }
    }
}

void in_order(bst *p)
{
    if (p != NULL)
    {
        in_order(p->left);
        cout << "ID: " << p->id << endl;
        in_order(p->right);
    }
}

bool search(int x)
{
    bst *p = root;
    while (p != NULL)
    {
        if (p->id == x)
        {
            return true;
        }
        else if (p->id > x)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return false;
}