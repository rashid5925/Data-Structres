#include <iostream>

using namespace std;

class graphs
{
public:
    int** matrix;
    int vertices;
    graphs(int node);
    void add_edge(int n1, int n2, int weight);
    void display();

};

graphs::graphs(int vertices)
{
    this->vertices = vertices;

    matrix = new int*[vertices];

    for (int i = 0; i < vertices; i++)
    {
        matrix[i] = new int[vertices];
        for (int j = 0; j < vertices; j++)
        {
            matrix[i][j] = 0;
        }
        
    }
}

void graphs::add_edge(int n1, int n2, int weight)
{
    matrix[n1][n2] = weight;
}

void graphs::display()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    
}

int main() 
{
    graphs g(5);
    g.add_edge(0, 1, 2);
    g.add_edge(1, 4, 3);
    g.add_edge(2, 3, 1);
    g.add_edge(3, 4, 3);
    g.add_edge(0, 2, 5);

    g.display();
    return 0;
}