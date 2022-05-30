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

bst* insert(bst *node, bst *new_node);
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
            cout << "Enter element too insert: ";
            cin >> element;
            bst* p;
            p = new bst;
            p->id = element;
            root = insert(root, p);
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

bst* rotate_right (bst *y)
{
    bst *x = y->left;
    bst *t = x->right;

    x->right = y;
    y->left = t;

    return x;
}

bst* rotate_left (bst *y)
{
    bst *x = y->right;
    bst *t = x->left;

    x->left = y;
    y->right = t;

    return x;
}

bst* insert (bst *node, bst *new_node)
{
    if (node == NULL)
    {
        return new_node;
    }
    else if (node->id > new_node->id)
    {
        node->left = insert(node->left, new_node);
    }
    else if (node->id < new_node->id)
    {
        node->right = insert(node->right, new_node);
    }
    
    int balance_factor = height(node->left) - height(node->right);

    //LL
    if (balance_factor > 1 && new_node->id < node->left->id)
    {
        return rotate_right(node);
    }

    //RR
    if (balance_factor < -1 && new_node->id > node->right->id)
    {
        return rotate_left(node);
    }

    //LR
    if (balance_factor > 1 && new_node->id > node->left->id)
    {
        node->left = rotate_left(node);
        return rotate_right(node);
    }

    //RL
    if (balance_factor < -1 && new_node->id < node->right->id)
    {
        node->right = rotate_right(node);
        return rotate_left(node);
    }
    return node;
}

int remove (int x)
{
    return 0;
}
