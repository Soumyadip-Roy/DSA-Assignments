#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *l;
    Node *r;
};

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

class ExpressionTree
{
public:
    Node *newNode(char val)
    {
        Node *temp = new Node;
        temp->l = temp->r = NULL;
        temp->data = val;
        return temp;
    };

    Node *root;
    stack<Node *> st;
    Node *t, *t1, *t2;

    void constructTree(string exp)
    {
        for (int i = 0; i < exp.length(); i++)
        {
            if (!isOperator(exp[i]))
            {
                t = newNode(exp[i]);
                st.push(t);
            }
            else
            {
                t = newNode(exp[i]);
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();

                t->l = t2;
                t->r = t1;

                st.push(t);
            }
        }
        root = st.top();
    }

    void constructTreePre(string exp)
    {
        reverse(exp.begin(), exp.end());

        for (int i = 0; i < exp.length(); i++)
        {
            if (!isOperator(exp[i]))
            {
                t = newNode(exp[i]);
                st.push(t);
            }
            else
            {
                t = newNode(exp[i]);
                t1 = st.top();
                st.pop();
                t2 = st.top();
                st.pop();

                t->l = t1;
                t->r = t2;

                st.push(t);
            }
        }
        root = st.top();
    }

    // inorder Left -> Right -> Root
    void inOrder(Node *p)
    {
        if (p == NULL)
            return;
        inOrder(p->l);
        cout << p->data << " ";
        inOrder(p->r);
    }

    // preorder Root -> Left -> Right
    void preOrder(Node *p)
    {
        if (p == NULL)
            return;
        cout << p->data << " ";
        preOrder(p->l);
        preOrder(p->r);
    }

    // postorder Left -> Right -> Root
    void postOrder(Node *p)
    {
        if (p == NULL)
            return;
        postOrder(p->l);
        postOrder(p->r);
        cout << p->data << " ";
    }

    void inOrder_nr(Node *p)
    {

        stack<Node *> s;
        while (p != NULL)
        {
            s.push(p);
            p = p->l;
        }
        while (!s.empty())
        {
            p = s.top();
            s.pop();

            cout << p->data << " ";
            p = p->r;
            while (p != NULL)
            {
                s.push(p);
                p = p->l;
            }
        }
    }

    void preOrder_nr(Node *p)
    {
        stack<Node *> s;
        while (p != NULL)
        {
            cout << p->data << " ";
            s.push(p);
            p = p->l;
        }
        while (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->r;
            while (p != NULL)
            {
                cout << p->data << " ";
                s.push(p);
                p = p->l;
            }
        }
    }

    void postOrder_nr(Node *p)
    {
        stack<Node *> s1, s2;

        s1.push(p);
        Node *t;

        while (!s1.empty())
        {
            // Pop from s1 , push to s2
            t = s1.top();
            s1.pop();

            s2.push(t);

            if (t->l)
                s1.push(t->l);
            if (t->r)
                s1.push(t->r);
        }

        while (!s2.empty())
        {
            t = s2.top();
            s2.pop();
            cout << t->data << " ";
        }
    }
};

int main()
{
    while (true)
    {
        cout << "Choose Your Operation:\n";
        cout << "1.Enter a prefix expression\n";
        cout << "2.Enter a postfix expression\n";
        cout << "3.Exit Program\n";
        cout << "Enter you choice: ";
        ExpressionTree tree;
        int choice;
        cin >> choice;
        if (choice == 1) // Prefix to Postfix || Infix
        {
            cout << "Enter Your Prefix Expression: ";
            string exp;
            cin >> exp;

            tree.constructTreePre(exp);
            cout << "Choose Your Operation:\n";
            cout << "1.Get the postfix expression with recursion\n";
            cout << "2.Get the infix expression with recursion\n";
            cout << "3.Get the postfix expression without recursion\n";
            cout << "4.Get the infix expression without recursion\n";

            int choice2;
            cin >> choice2;

            if (choice2 == 1)
            {
                cout << "The postfix expression is:\n";
                tree.postOrder(tree.root);
                cout << "\n";
            }
            else if (choice2 == 2)
            {
                cout << "The infix expression is:\n";
                tree.inOrder(tree.root);
                cout << "\n";
            }
            else if (choice2 == 3)
            {
                cout << "The postfix expression without recursion is:\n";
                tree.postOrder_nr(tree.root);
                cout << "\n";
            }
            else if (choice2 == 4)
            {
                cout << "The infix expression without recursion is:\n";
                tree.inOrder_nr(tree.root);
                cout << "\n";
            }
        }
        else if (choice == 2)
        {
            cout << "Enter Your Postfix Expression: ";
            string exp;
            cin >> exp;
            tree.constructTree(exp);
            cout << "Choose Your Operation:\n";
            cout << "1.Get the prefix expression with recursion\n";
            cout << "2.Get the infix expression with recursion\n";
            cout << "3.Get the prefix expression without recursion\n";
            cout << "4.Get the infix expression without recursion\n";

            int choice2;
            cin >> choice2;
            if (choice2 == 1)
            {
                cout << "The prefix expression is:\n";
                tree.preOrder(tree.root);
                cout << "\n";
            }
            else if (choice2 == 2)
            {
                cout << "The infix expression is:\n";
                tree.inOrder(tree.root);
                cout << "\n";
            }
            else if (choice2 == 3)
            {
                cout << "The prefix expression without recursion is:\n";
                tree.preOrder_nr(tree.root);
                cout << "\n";
            }
            else if (choice2 == 4)
            {
                cout << "The infix expression without recursion is:\n";
                tree.inOrder_nr(tree.root);
                cout << "\n";
            }
        }
        else if (choice == 3)
        {
            cout << "Thank you!";
            break;
        }
        else
        {
            cout << "Invalid choice";
        }
    }
    return 0;
}
