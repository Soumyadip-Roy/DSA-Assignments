#include <bits/stdc++.h>
using namespace std;

class Student
{
    string name;
    int roll;
    float marks;

public:
    void setData(string n, int r, float m)
    {
        name = n;
        roll = r;
        marks = m;
    }
    void display()
    {
        cout << name << " " << roll << " " << marks << endl;
    }
    int linearSearch(Student s[], float key, int n)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i].marks == key)
            {
                s[i].display();
                cout << "Element found at : " << i << endl;
                ans = 1;
            }
        }
        return ans;
    }
    int binarySearch(Student s[], string p, int n)
    {
        s[0].insertionSort(s, n);
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (s[mid].name == p)
            {
                cout << "Name : " << s[mid].name << "\nRoll :" << s[mid].roll << "\nSGPA : " << s[mid].marks << "\n";
                return mid;
            }
            else if (p > s[mid].name)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    void bubbleSort(Student s[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (s[j].roll > s[j + 1].roll)
                    swap(s[j], s[j + 1]);
            }
        }
    }
    void insertionSort(Student s[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int j = i - 1;
            string key = s[i].name;
            while (j >= 0 and key < s[j].name)
            {
                swap(s[j + 1], s[j]);
                j--;
            }
        }
    }
    int partition(Student s[], int low, int high)
    {
        int i = low, j = high;
        float pivot = s[low].marks;
        while (i < j)
        {
            while (pivot <= s[i].marks)
                i++;
            while (pivot > s[j].marks)
                j--;
            if (i < j)
                swap(s[i], s[j]);
        }
        swap(s[low], s[j]);
        return j;
    }
    void quickSort(Student s[], int low, int high)
    {
        if (low < high)
        {
            int pivot = partition(s, low, high);
            quickSort(s, low, pivot - 1);
            quickSort(s, pivot + 1, high);
        }
    }
};

int main()
{
    cout << "Enter no. of records : ";
    int n;
    cin >> n;
    Student s[n], _;
    int cont;
    cout << "1 - Enter Data \n2 - Display Data \n3 - Linear Search \n4 - Binary Search \n5 - Bubble Sort \n6 - Insertion Sort\n7 - Quick Sort\n";
    do
    {
        cout << "Enter your choice : ";
        int x;
        cin >> x;
        if (x == 1)
        {
            string name;
            int roll;
            float marks;
            for (int i = 0; i < n; i++)
            {
                cin >> name >> roll >> marks;
                s[i].setData(name, roll, marks);
            }
        }
        else if (x == 2)
        {
            for (int i = 0; i < n; i++)
                s[i].display();
        }
        else if (x == 3)
        {
            cout << "Enter marks : ";
            float key;
            cin >> key;
            int pos = _.linearSearch(s, key, n);
            if (pos == 0)
                cout << "NOT_FOUND\n";
        }
        else if (x == 4)
        {
            cout << "Enter name : ";
            string nam;
            cin >> nam;
            int posName = _.binarySearch(s, nam, n);
            if (posName == -1)
                cout << "NAME_NOT_FOUND\n";
            else
                cout << "Element found at : " << posName << "\n";
        }
        else if (x == 5)
            _.bubbleSort(s, n);
        else if (x == 6)
            _.insertionSort(s, n);
        else if (x == 7)
        {
            _.quickSort(s, 0, n - 1);
            cout << "Number of top students : ";
            int k;
            cin >> k;
            for (int i = 0; i < min(n, k); i++)
            {
                cout << "Rank " << i + 1 << " : ";
                s[i].display();
            }
        }
        cout << "Press 1 to continue : ";
        cin >> cont;
    } while (cont == 1);
    return 0;
}

// AA 8 89.3
// AAA 3 82.3
// AB 10 89.3
// BA 7 82.3
// AAAA 12 89.3
// BAA 1 87
// BAB 2 83
