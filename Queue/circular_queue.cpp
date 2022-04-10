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
            cout << "Enter element too Enqueue: ";
            cin >> element;
            que.enqueue(element);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            cout << "Dequeued element is: " << que.dequeue() << "\n";
            cout << "\n";
            break;
        case 3:
            que.display();
            break;
        default:
            cout << "Wrong input\n";
            break;
        }
    } while (exit != 0);
    return 0;
}
