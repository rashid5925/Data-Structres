#include <iostream>
#define MAX 5

using namespace std;

int stack[50];
int top = -1;

void push(int element)
{
    if (top < 20)
    {
        stack[++top] = element;
    }
    else
    {
        cout << "Stack is full\n";
    }
}

char pop()
{
    if (top > -1)
    {
        return stack[top--];
    }
    int a;
    cout << "Stack empty\n";
    return a;
}

int peek()
{
    int c;
    if (top > -1)
    {
        return stack[top];
    }
    return c;
}

struct node
{
    int id;
    bool visited = false;
};

node *graph[MAX][MAX];

void initialize () {
    node *n = new node;
    n->id = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            graph[i][j] = n;
        }
    }
}

void add_edge(int n1, int n2, int weight)
{
    node *n = new node;
    n->id = weight;
    graph[n1][n2] = n;
}

void display () {
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cout << graph[i][j]->id << " ";
        }
        cout << "\n";
    }
    
}

void DFS (int key) {
    node visited[MAX];
    
}

int main()
{
    initialize();

    add_edge(0, 1, 1);
    add_edge(0, 2, 1);
    add_edge(0, 3, 1);
    add_edge(0, 4, 1);
    add_edge(1, 0, 1);
    add_edge(2, 0, 1);
    add_edge(3, 0, 1);
    add_edge(4, 0, 1);
    
    display();
    return 0;
}

