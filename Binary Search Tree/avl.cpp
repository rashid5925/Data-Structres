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
bst *remove(int key);
bool search(int x);
void in_order(bst *p);
int height(bst *p);
bst* insert_iter(int node);


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
             << "6. Insert Iterative\n"
             << "7. Delete\n"
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
        case 6:
            cout << "\n";
            cout << "Enter element too insert: ";
            cin >> element;
            root = insert_iter(element);
            cout << "\n";
            break;
        case 7:
            cout << "\n";
            cout << "Enter element too delete: ";
            cin >> element;
            root = remove(element);
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


void trav (bst *p)
{
    if (p != NULL)
    {
        trav(p->left);
        trav(p->right);
    }
}



bst* balance (bst *node, bst *new_node)
{
    if (node != NULL)
    {
        trav(node->left);
        trav(node->right);
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
    }
    return node;
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


bst* insert_iter(int x)
{
    bst *p = new bst;
    p->id = x;
    if (root == NULL)
    {
        return p;
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
    return balance(root, p);
}


bst *remove (int key)
{
    bst *p = root, *p1;
    while (p != NULL && p->id != key)
    {
        p1 = p;
        if (p->id < key)
        {
            p = p->right;
        } else 
        {
            p = p->left;
        }
    }
    
    //not found
    if (p == NULL)
    {
        cout << "ID not found\n";
        return root;
    }
    bst *curr = p1;
    //no branch
    if (p->left == NULL && p->right == NULL)
    {
        if (p == p1->left)
        {
            p1->left = NULL;
            delete p;
        } else
        {
            p1->right = NULL;
            delete p;
        }
    }
    //one branch
    else if (p->right == NULL || p->left == NULL)
    {
        if (p->left == p)
        {
            if (p->right == NULL)
            {
                p1->left = p->left;
                delete p;
            }
            else
            {
                p1->left = p->right;
                delete p;
            }
            
        }
        else 
        {
            if (p1->left == NULL)
            {
                p1->right = p->right;
                delete p;
            }
            else
            {
                p1->right = p->left;
                delete p;
            }
            
        }
    }
    //two branches
    else
    {
        p1 = p->right;
        bst *p2 = NULL, *p3 = NULL;
        while (p1 != NULL)
        {
            p3 = p2;
            p2 = p1;
            p1 = p1->left;
        }
        if (p3 == NULL)
        {
            p->id = p2->id;
            p->right = NULL;
            delete p2;
        }
        else
        {
            p->id = p2->id;
            p3->left = p2->right;
            delete p2;
        }
    }
    return balance(root, curr);
}
