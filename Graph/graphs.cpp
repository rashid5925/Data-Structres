#include <iostream>
using namespace std;

class Que
{
public:
    int size, front, rear;
    int *que;

    Que()
    {
        size = 10;
        front = rear = -1;
        que = new int[size];
    }

    Que(int s)
    {
        size = s;
        front = rear = -1;
        que = new int[size];
    }

    bool is_full()
    {
        if ((rear + 1) % size == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool is_empty()
    {
        if (rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void display()
    {
        if (is_empty())
        {
            cout << "Empty\n";
        }
        else
        {
            int i = front;
            do
            {
                cout << "Value is: " << que[i] << endl;
                i = (i + 1) % size;
            } while (i != (rear + 1) % size);
        }
    }

    void enqueue(int x)
    {
        if (is_empty())
        {
            front = rear = 0;
            que[rear] = x;
        }
        else if (is_full())
        {
            cout << "No space\n";
        }
        else
        {
            rear = (rear + 1) % size;
            que[rear] = x;
        }
    }

    int dequeue()
    {
        int x;
        if (is_empty())
        {
            cout << "Empty";
            x = -1;
        }
        else if (front == rear)
        {
            x = que[front];
            front = rear = -1;
        }
        else
        {
            x = que[front];
            front = (front + 1) % size;
        }
        return x;
    }
};


class graphs
{
public:
    int **matrix;
    int vertices;
    int *visited;
    graphs(int node);
    void add_edge(int n1, int n2, int weight);
    void display();
    void BFS(int ver);
    void DFS(int ver);
    void dijkstra(int ver, int to);
    void prims(int ver);
};

graphs::graphs(int vertices)
{
    this->vertices = vertices;

    matrix = new int *[vertices];
    visited = new int[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
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

void graphs::BFS(int ver)
{
    Que q(100);
    int visited[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = -1;
    }
    int vis;
    q.enqueue(ver);
    while (!q.is_empty())
    {
        vis = q.dequeue();
        for (int i = 0; i < vertices; i++)
        {
            if (visited[i] == vis)
            {
                break;
            }
            if (visited[i] == -1)
            {
                visited[i] = vis;
                break;
            }
        }

        for (int i = 0; i < vertices; i++)
        {
            if (matrix[vis][i] != 0)
            {
                for (int j = 0; j < vertices; j++)
                {
                    if (i == visited[j])
                    {
                        break;
                    }
                    if (visited[j] == -1)
                    {
                        q.enqueue(i);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        cout << visited[i] << " ";
    }
}

void graphs::DFS(int ver)
{
    int j;

    cout << ver << " ";

    visited[ver] = 1;
    for (j = 0; j < vertices; j++)
    {
        if (matrix[ver][j] != 0 && !visited[j])
        {
            DFS(j);
        }
    }
}

void graphs::dijkstra(int ver, int to)
{
    int min;
    int prev = 0;
    int dist[vertices][vertices];
    int ind = ver;
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        if (matrix[ver][i] != 0)
	    {
	    	dist[i][0] = i;
	        dist[i][1] = matrix[ver][i];
	    }
	    else
	    {
	        dist[i][0] = -1;
	        dist[i][1] = -1;
	    }
    }
    dist[ver][ver] = 0;
    dist[ver][ver + 1] = 0;
    visited[ver] = 1;
    for (int i = 0; i < vertices; i++)
    {
        visited[ind] = 1;
        min = 9999;
        for (int j = 0; j < vertices; j++)
        {
            if (!visited[j] && matrix[ind][j] != 0 && matrix[ind][j] < min)
            {
                min = matrix[ind][j];
                prev += min;
                ind = j;
            }
        }
        if (dist[ind][0] == -1 || dist[ind][1] > prev)
        {
            dist[ind][0] = ind;
			dist[ind][1] = prev;
        }
    }
    for (int i = 0; i < to; i++)
    {
    	cout << "Edge: " << dist[i][0] << " Distance: " << dist[i][1] << "\n";
	}  
}

void graphs::prims(int ver)
{
    int min;
    int prev = 0;
    int dist[vertices][vertices];
    int ind = ver;
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
        if (matrix[ver][i] != 0)
	    {
	    	dist[i][0] = i;
	        dist[i][1] = matrix[ver][i];
	    }
	    else
	    {
	        dist[i][0] = -1;
	        dist[i][1] = -1;
	    }
    }
    dist[ver][ver] = 0;
    dist[ver][ver + 1] = 0;
    visited[ver] = 1;
    for (int i = 0; i < vertices; i++)
    {
        visited[ind] = 1;
        min = 9999;
        for (int j = 0; j < vertices; j++)
        {
            if (!visited[j] && matrix[ind][j] != 0 && matrix[ind][j] < min)
            {
                min = matrix[ind][j];
                prev += min;
                ind = j;
            }
        }
        if (dist[ind][0] == -1 || dist[ind][1] > prev)
        {
        	dist[ind][0] = ind;
			dist[ind][1] = min;
        } 
    }
    for (int i = 0; i < vertices; i++)
    {
        cout << "Edge: " << dist[i][0] << " Distance: " << dist[i][1] << "\n";
    }  
}

int main()
{
    graphs g(3);
    g.add_edge(0, 1, 2);
    g.add_edge(1, 2, 1);
    g.add_edge(0, 2, 4);
    g.add_edge(1, 0, 2);
    g.add_edge(2, 1, 1);
    g.add_edge(2, 0, 4);

    g.display();

    cout << "\n";
    cout << "BFS\n";
    g.BFS(1);
    cout << "\n\n";

    cout << "DFS\n";
    g.DFS(0);
    cout << "\n\n";

    cout << "Dijkstra\n";
    g.dijkstra(0, 3);
    cout << "\n\n";
    cout << "Prim's\n";
    g.prims(0);
    cout << "\n";

    return 0;
}
