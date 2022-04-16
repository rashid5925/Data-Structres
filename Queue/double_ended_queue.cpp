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
        if (front == 0 && rear == size - 1)
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

    void enqueue_end(int x)
    {
        if (is_full())
        {
            cout << "No space\n";
        }
        else
        {
            if (is_empty())
            {
                front = rear = 0;
            }
            else if (rear == size - 1)
            {
                int i = front;
                while (i <= rear)
                {
                    que[i - 1] = que[i];
                    i++;
                }
                front--;
            }
            else
            {
                rear++;
            }
            que[rear] = x;
        }
    }

    void enqueue_start(int x)
    {
        if (is_full())
        {
            cout << "No space\n";
        }
        else
        {
            if (is_empty())
            {
                front = rear = 0;
            }
            else if (front == 0)
            {
                int i = rear;
                while (i >= front)
                {
                    que[i + 1] = que[i];
                    i--;
                }
                rear++;
            }
            else
            {
                front--;
            }
            que[front] = x;
        }
    }

    int dequeue_start()
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
                front++;
            }
            return x;
        }
    }

    int dequeue_end()
    {
        if (is_empty())
        {
            cout << "Queue is empty\n";
            return -1;
        }
        else
        {
            int x = que[rear];
            if (front == rear)
            {
                front = rear = -1;
            }
            else
            {
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
             << "1. Enqueue start\n"
             << "2. Dequeue start\n"
             << "3. Display Queue\n"
             << "4. Enqueue end\n"
             << "5. Dequeue end\n"
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
            cout << "Enter element too Enqueue: ";
            cin >> element;
            que.enqueue_start(element);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            cout << "Dequeued element is: " << que.dequeue_start() << "\n";
            cout << "\n";
            break;
        case 3:
            que.display();
            break;
        case 4:
            cout << "\n";
            cout << "Enter element too Enqueue: ";
            cin >> element;
            que.enqueue_end(element);
            cout << "\n";
            break;
        case 5:
            cout << "\n";
            cout << "Dequeued element is: " << que.dequeue_end() << "\n";
            cout << "\n";
            break;
        default:
            cout << "Wrong input\n";
            break;
        }
    } while (exit != 0);
    return 0;
}
