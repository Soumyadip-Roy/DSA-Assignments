#include <bits/stdc++.h>
using namespace std;
struct Node
{
    char data;
    struct Node *next;
};

map<char, int> prior = {{'*', 4}, {'/', 3}, {'+', 2}, {'-', 1}};

class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }

    Node create(int x)
    {
        Node *p = new Node;
        p->data = x;
        p->next = NULL;
        return *p;
    }

    void push(char x)
    {
        Node *newNode = new Node;
        *newNode = create(x);
        if (top == NULL)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
        return;
    }

    char pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty\n";
            return 1;
        }
        Node *temp = top;
        top = top->next;
        return temp->data;
    }

    // other operations

    // void display()
    // {
    //     Node *temp =  top;
    //     while (temp != NULL)
    //     {
    //         cout << temp->data << " ";
    //         temp = temp->next;
    //     }
    //     cout << endl;
    // }

    bool isEmpty()
    {
        return top == NULL;
    }
    char topVal()
    {
        return top->data;
    }
};

string infix_to_postfix(string infix)
{
    Stack *s = new Stack();
    char x, y;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        x = infix[i];
        // for alphanumeric
        if (isalnum(x))
        {
            postfix.push_back(x);
        }
        // for brackets
        else if (x == '(')
        {
            s->push(x);
        }
        else if (x == ')')
        {
            y = s->pop();
            while (y != '(')
            {
                postfix.push_back(y);
                y = s->pop();
            }
        }
        // for operator
        else
        {
            while (!s->isEmpty() and (prior[x] < prior[s->topVal()])) //= priority do not pop
            {
                y = s->pop();
                postfix.push_back(y);
            }
            s->push(x);
        }
    }

    while (!s->isEmpty())
    {
        y = s->pop();
        postfix.push_back(y);
    }

    return postfix;
}

string infix_to_prefix(string infix)
{
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    string prefix = infix_to_postfix(infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int evaluate(int a, int b, char x)
{
    if (x == '*')
    {
        return b * a;
    }
    else if (x == '/')
    {
        return b / a;
    }
    else if (x == '+')
    {
        return b + a;
    }
    else if (x == '-')
    {
        return b - a;
    }
}

int postfix_evalution(string postfix)
{
    Stack *s = new Stack();
    char x, y;
    int a, b;
    for (int i = 0; i < postfix.length(); i++)
    {
        x = postfix[i];
        if (isalnum(x))
        {
            cout << "Enter the value of " << x << ": ";
            cin >> y;
            s->push(y);
        }
        else
        {
            a = s->pop() - '0';
            b = s->pop() - '0';
            if (a == 0)
            {
                cout << "Error cannot divide by zero" << endl;
                return -1;
            }
            int val = evaluate(a, b, x);
            s->push(val + '0');
        }
    }
    int r = s->pop() - '0';
    return r;
}

int prefix_evalution(string prefix)
{
    reverse(prefix.begin(), prefix.end());
    Stack *s = new Stack();
    char x, y;
    int a, b;
    for (int i = 0; i < prefix.length(); i++)
    {
        x = prefix[i];
        if (isalnum(x))
        {
            cout << "Enter the value of " << x << ": ";
            cin >> y;
            s->push(y);
        }
        else
        {
            a = s->pop() - '0';
            b = s->pop() - '0';
            if (b == 0 && x == '/')
            {
                cout << "Error cannot divide by zero" << endl;
                return -1;
            }
            int val = evaluate(b, a, x);
            s->push(val + '0');
        }
    }
    int r = s->pop() - '0';
    return r;
}

int main()
{

    int cont;
    do
    {
        cout << "1 - Infix -> Postfix \n2 - Infix -> Prefix \n3 - Evaluation of Postfix \n4 - Evaluation of Prefix\n";
        cout << "Enter choice : ";

        int x, ans;
        string st;
        cin >> x;

        switch (x)
        {
        case 1:
            cout << "Enter infix expression : ";
            cin >> st;
            cout << "Postfix expression is : ";
            cout << infix_to_postfix(st) << endl;
            break;

        case 2:
            cout << "Enter infix expression : ";
            cin >> st;
            cout << "Prefix expression is : ";
            cout << infix_to_prefix(st) << endl;
            break;

        case 3:
            cout << "Enter the postfix expression: ";
            cin >> st;
            ans = postfix_evalution(st);
            if (ans != -1)
            {
                cout << "Value of expression is : ";
                cout << ans << endl;
            }
            break;
        case 4:
            cout << "Enter the prefix expression: ";
            cin >> st;
            ans = prefix_evalution(st);
            if (ans != -1)
            {
                cout << "Value of expression is: ";
                cout << ans << endl;
            }
            break;
        default:
            cout << "Invalid Choice\n";
            break;
        }
        cout << "Press 1 to continue : ";
        cin >> cont;

    } while (cont == 1);

    return 0;
}

// (a+(b*c))/(c-(d*b))
// (A+B)/(C-D)
// (a-z)*(b+c-d*e)*f

// Evaluation of postfix
// abc*+cdb*-/
// ab*cd-/ef*+

// Evaluation of prefix
///+AB-CD
//+a*bc-c*db
