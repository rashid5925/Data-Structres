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

    bool is_full()
    {
        if (rear == size - 1)
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
            cout << "Queue is empty\n";
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << "Value at " << i << " is: " << que[i] << endl;
            }
        }
    }

    void enqueue(int x)
    {
        if (is_full())
        {
            cout << "Queue is full\n";
            return;
        }
        if (is_empty())
        {
            front = rear = 0;
            que[rear] = x;
            return;
        }
        que[++rear] = x;
        int i = rear;
        while (i > 0 && que[i - 1] > que[i])
        {
            int temp = que[i - 1];
            que[i - 1] = que[i];
            que[i] = temp;
            i--;
        }
    }

    int dequeue()
    {
        if (is_empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        else
        {
            int x = que[front];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
                int i = front + 1;
                while (i <= rear)
                {
                    que[i - 1] = que[i];
                    i++;
                }
                rear--;
            }
            return x;
        }
    }
};

int main()
{
    int size;
    cout << "Enter size of queue: ";
    cin >> size;
    Que que(size);
    int exit = 1;
    do
    {
        cout << "Enter number to perform operation\n"
             << "1. Enqueue\n"
             << "2. Dequeue\n"
             << "3. Display Queue\n"
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
            cout << "Enter element to Enqueue: ";
            cin >> element;
            que.enqueue(element);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            cout << "The Element Dequeued Is: " << que.dequeue() << "\n";
            cout << "\n";
            break;
        case 3:
            que.display();
            break;
        default:
            cout << "Wrong Input\n";
            break;
        }
    } while (exit != 0);
    return 0;
}
