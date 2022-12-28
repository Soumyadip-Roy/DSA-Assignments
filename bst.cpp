#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *l, *r, *par;
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    // NewNode
    Node *newNode(int data)
    {
        Node *t = new Node();
        t->data = data;
        t->l = t->r = t->par = NULL;
        return t;
    }

    // Inserting a Node

    // Iterative insertion

    void insert(int data)
    {
        Node *x = newNode(data);

        if (root == NULL) // empty tree (adding first node)
            root = x;
        else
        {
            Node *p = root;
            Node *q = NULL;

            while (p != NULL) // traverse until the node's left or right becomes null
            {
                q = p; // to store the previous state of 'p' because p will eventually become null
                if (data < p->data)
                    p = p->l;
                else if (data > p->data)
                    p = p->r;
                else if (data == p->data)
                {
                    cout << "Duplicates are not allowed\n";
                    return;
                }
            }
            if (data < q->data)
                q->l = x;
            else if (data > q->data)
                q->r = x;
            x->par = q;
        }
    }

    // Recurrsive - insertion
    //  void insert_rec(Node *&p, int data)
    //  {
    //      if (p == NULL)
    //          p = newNode(data);
    //      else if (data < p->data)
    //          insert_rec(p->l, data);
    //      else if (data > p->data)
    //          insert_rec(p->r, data);
    //  }

    // Traverse to the leftmost node
    int find_min(Node *p)
    {
        while (p->l != NULL)
            p = p->l;
        return p->data;
    }

    // traverse to the rightmost node
    int find_max(Node *p)
    {
        while (p->r != NULL)
            p = p->r;
        return p->data;
    }

    // Iterative search
    int search(int x)
    {
        Node *p = root;
        while (p != NULL)
        {
            if (x == p->data)
                return 1;
            else if (x > p->data)
                p = p->r;
            else if (x < p->data)
                p = p->l;
        }
        return 0;
    }

    // traverse in Inorder
    void leafNodes()
    {
        if (root == NULL)
        {
            cout << "Tree is Empty" << endl;
            return;
        }

        Node *p = root;
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

            if (p->l == NULL and p->r == NULL)
            {
                cout << p->data << " ";
            }

            p = p->r;
            while (p != NULL)
            {
                s.push(p);
                p = p->l;
            }
        }
    }

    // height iterative
    int height()
    {
        if (root == NULL)
        {
            return 0;
        }

        Node *p = root;
        queue<Node *> q;

        q.push(p);
        q.push(NULL);

        int h = 0;

        while (!q.empty())
        {
            p = q.front();
            if (p != NULL)
                cout << p->data << " ";

            q.pop();
            if (p == NULL)
            {
                cout << endl;
                h++;
            }
            if (p != NULL)
            {
                if (p->l != NULL)
                    q.push(p->l);
                if (p->r != NULL)
                    q.push(p->r);
            }
            else if (!q.empty())
            {
                q.push(NULL);
            }
        }
        return h;
    }

    // height recursive
    int height_rec(Node *p)
    {
        if (p == NULL)
            return 0;

        int lh = height_rec(p->l);
        int rh = height_rec(p->r);
        return 1 + max(lh, rh);
    }

    // delete node iterative
    void deleteNode(int x)
    {
        Node *p = root;
        Node *q = NULL;

        while (p != NULL)
        {
            if (x == p->data)
            {
                q = p;
                break;
            }
            if (x > p->data)
            {
                p = p->r;
            }
            if (x < p->data)
            {
                p = p->l;
            }
        }

        if (q == NULL)
        {
            cout << "NOT fOUND" << endl;
            return;
        }

        // cout << q->data << " Deleted ";

        Node *t = q->par; // t is the parent of q

        if (q->l == NULL and q->r == NULL)
        {
            if (t->l == q)
                t->l = NULL;
            if (t->r == q)
                t->r = NULL;
        }

        if (q->l == NULL and q->r != NULL)
        {
            if (t->l == q)
            {
                t->l = q->r;   // left of {parent of q} is {right of q}
                q->r->par = t; // parent of {right of q} is {parent of q}
            }
            else
            {
                t->r = q->r;
                q->r->par = t;
            }
        }

        if (q->l != NULL and q->r == NULL)
        {
            if (t->l == q)
            {
                t->l = q->l;
                q->l->par = t;
            }
            else
            {
                t->r = q->l;
                q->l->par = t;
            }
        }
        if (q->l != NULL and q->r != NULL)
        {
            int x = find_min(q->r);
            // or x = find_max(q->l);
            deleteNode(x);
            q->data = x;
        }
    }

    // inorder Left -> Root -> Right
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
        if (root == NULL)
        {
            cout << "Empty Tree\n";
            return;
        }

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
        if (root == NULL)
        {
            cout << "Empty Tree\n";
            return;
        }

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
        if (root == NULL)
        {
            cout << "Empty Tree\n";
            return;
        }

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

    void mirror_image(Node *root)
    {
        if (root != NULL)
        {
            mirror_image(root->l);
            mirror_image(root->r);
            swap(root->l, root->r);
        }
    }

    void copy(Node *one, Node *&two)
    {
        if (one == NULL)
        {
            two = NULL;
        }
        else
        {
            two = new Node;
            two->data = one->data;
            copy(one->l, two->l);
            copy(one->r, two->r);
        }
    }
};

signed main()
{
    BST bst;
    bool cnd = true;
    while (cnd)
    {

        cout << "\n1.Insert\n2.Delete\n3.Display\n4.Copy\n5.Mirror Image\n6.Leaf Nodes\n7.Height\n8.Find Minimum\n9.Find Maximum\n10.Search\n0.EXIT\nEnter your choice: ";

        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter Data : ";
            int x;
            cin >> x;
            bst.insert(x);
            break;
        }
        case 2:
        {
            cout << "Enter node to delete : ";
            int x;
            cin >> x;
            bst.deleteNode(x);
            break;
        }
        case 3:
        {
            cout << "Display : \n";
            cout << "1.Inorder \n";
            cout << "2.Preorder \n";
            cout << "3.Postorder \n";
            cout << "4.Inorder without recursion\n";
            cout << "5.Preorder without recursion\n";
            cout << "6.Postorder without recursion\n";
            cout << "Enter your choice : ";
            int ask;
            cin >> ask;
            cout << endl;
            switch (ask)
            {
            case 1:
            {
                bst.inOrder(bst.root);
                break;
            }
            case 2:
            {
                bst.preOrder(bst.root);
                break;
            }
            case 3:
            {
                bst.postOrder(bst.root);
                break;
            }
            case 4:
            {
                bst.inOrder_nr(bst.root);
                break;
            }
            case 5:
            {
                bst.preOrder_nr(bst.root);
                break;
            }
            case 6:
            {
                bst.postOrder_nr(bst.root);
                break;
            }
            }
            cout << endl;
            break;
        }
        case 4:
        {
            BST copy;
            bst.copy(bst.root, copy.root);
            bst.inOrder(copy.root);
            break;
        }
        case 5:
        {
            BST copy;
            bst.mirror_image(copy.root);
            bst.inOrder(copy.root);
            break;
        }
        case 6:
        {
            bst.leafNodes();
            cout << "\n";
            break;
        }
        case 7:
        {
            cout << "Height : " << bst.height() << "\n";
            break;
        }
        case 8:
        {
            cout << bst.find_min(bst.root) << "\n";
            break;
        }
        case 9:
        {
            cout << bst.find_max(bst.root) << "\n";
            break;
        }
        case 10:
        {
            cout << "Enter Search Data : ";
            int x;
            cin >> x;
            if (bst.search(x))
            {
                cout << "Found\n";
            }
            else
            {
                cout << "Not Found\n";
            }
            break;
        }
        case 0:
        {
            cnd = false;
            break;
        }
        }
    }
}
