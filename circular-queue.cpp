#include <bits/stdc++.h>

using namespace std;

int front = -1, rear = -1;
int size;

void display(int q[])
{

    if (front == -1)
    {
        cout << "Queue is empty!\n";
        return;
    }

    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout << q[i] << " ";
    }
    else
    {
        for (int i = front; i < size; i++)
            cout << q[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << q[i] << " ";
    }
    cout << endl;
}
void enQueue(int q[], int x)
{
    // queqe full ?

    if ((rear + 1) % size == front)
    {
        cout << "Queue is full!\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % size;

    q[rear] = x;
}

void deQueue(int q[])
{
    if (front == -1)
    {
        cout << "Queue is empty!\n";
        return;
    }

    int x = q[front];

    if (front == rear)
        front = rear = -1;
    else
    {
        front = (front + 1) % size;
    }
    cout << x << " deleted !" << endl;
}

int main()
{
    cout << "Enter the size of the queue : ";
    cin >> size;
    int q[size];

    int cnt;
    do
    {
        int y;

        cout << "1 - Insert \n2 - Delete \n3 - Display\n";
        cout << "Enter your choice : ";
        cin >> y;

        switch (y)
        {
        case 1:
            int x;
            cout << "Enter element to be inserted : ";
            cin >> x;
            enQueue(q, x);
            break;
        case 2:
            deQueue(q);
            break;
        case 3:
            display(q);
            break;
        default:
            cout << "Enter correct choice!\n";
            break;
        }
        cout << "Press 1 to continue : ";
        cin >> cnt;
    } while (cnt == 1);
    return 0;
}
