#include <iostream>

using namespace std;

struct bst
{
    int id;
    bst *left = NULL;
    bst *right = NULL;
};

bst *root = NULL;
int n = 0;

void insert(int x);
int remove(int x);
bool search(int x);
void in_order(bst *p);
int height(bst *p);


int main()
{
    int exit = 1;
    do
    {
        cout << "Enter number to perform operation\n"
             << "1. Insert\n"
             << "2. Search\n"
             << "3. in_order\n"
             << "4. Height\n"
             << "5. Remove\n"
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
        case 4:
            cout << "\n";
            n = 0;
            cout << "Height: " << height(root);
            cout << "\n";
            break;
        case 5:
            cout << "\n";
            cout << "Enter element too delete: ";
            cin >> element;
            cout << "Deleted element is: " << remove(element);
            cout << "\n";
            break;
        default:
            cout << "Wrong input\n";
            break;
        }
    } while (exit != 0);
    return 0;
}

int max (int a, int b)
{
    return a > b ? a : b;
}

void in_order (bst *p)
{
    if (p != NULL)
    {
        in_order(p->left);
        cout << "ID: " << p->id << endl;
        in_order(p->right);
    }
}

bool search (int x)
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

int height (bst *p)
{
    if (p == NULL)
    {
        return 0;
    }
    int left = height(p->left);
    int right = height(p->right);
    return max(left, right) + 1;
}

void rotate_right (bst *p, bst *prev)
{
    if (p == NULL)
    {
        return;
    }
    bst *q = p->left;
    bst *temp = q->right;
    q->right = p;
    p->left = temp;
    if (prev != NULL)
    {
        if (prev->id > q->id)
        {
            prev->left = q;
        }
        else
        {
            prev->right = q;
        }
    }
    if (p == root)
    {
        root = q;
    }
}

void rotate_left (bst *p, bst *prev)
{
    if (p == NULL)
    {
        return;
    }
    bst *q = p->right;
    bst * temp = q->left;
    q->left = p;
    p->right = temp;
    if (prev != NULL)
    {
        if (prev->id > q->id)
        {
            prev->left = q;
        }
        else
        {
            prev->right = q;
        }
    }
    if (p == root)
    {
        root = q;
    }
}

void insert (int x)
{
    bst *p = new bst;
    p->id = x;
    if (root == NULL)
    {
        root = p;
        return;
    }
    bst *curr = root;
    bst *prev = NULL;
    bst *prev_prev = NULL;
    bst *prev_3 = NULL;
    while (curr != NULL)
    {
        prev_3 = prev_prev;
        prev_prev = prev;
        prev = curr;
        if (curr->id > x)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    if (prev->id > x)
    {
        prev->left = p;
    }
    else
    {
        prev->right = p;
    }
    int balance_factor;
    if (prev_prev != NULL)
    {
        balance_factor = height(prev_prev->left) - height(prev_prev->right);
    }
    else
    {
        balance_factor = 0;
    }
    
    //LL
    if (balance_factor > 1 && x < prev->id)
    {
        rotate_right(prev_prev, prev_3);
    }
    //LR
    else if (balance_factor > 1 && x > prev->id)
    {
        rotate_left(prev, prev_prev);
        rotate_right(prev_prev, prev_3);
    }
    //RR
    else if (balance_factor < -1 && x > prev->id)
    {
        rotate_left(prev_prev, prev_3);
    }
    //RL
    else if (balance_factor < -1 && x < prev->id)
    {
        rotate_right(prev, prev_prev);
        rotate_left(prev_prev, prev_3);
    }
    
}

int remove (int x)
{
    return 0;
}
