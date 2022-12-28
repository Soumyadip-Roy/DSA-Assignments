#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data = 0;
	bool lbit, rbit;
	Node *l, *r;
};
class TBST
{
public:
	Node *head = new Node();
	Node *root;

	TBST()
	{
		root = NULL;
		head->data = 999;
		head->lbit = 0;
		head->rbit = 1;
		head->r = head;
		head->l = NULL;
	}

	Node *newNode(int data)
	{
		Node *temp = new Node();
		temp->data = data;

		temp->l = temp->r = NULL;
		temp->lbit = temp->rbit = 0;

		return temp;
	}

	void insert(Node *&curr, int data)
	{ // q is to be inserted
		Node *q = newNode(data);
		if (curr == NULL)
		{
			curr = q;
			curr->l = curr->r = head;

			head->l = curr;
			head->lbit = 1;
		}
		else
		{
			if (data == curr->data)
			{
				cout << "Duplicates not allowed\n";
			}
			else if (data < curr->data)
			{ // for left node
				if (curr->lbit == 0)
				{
					q->l = curr->l; // inorder predecessor
					q->r = curr;	// inorder successor

					curr->l = q;
					curr->lbit = 1;
				}
				else
				{
					insert(curr->l, data);
				}
			}
			else if (data > curr->data)
			{ // for right node
				if (curr->rbit == 0)
				{
					q->r = curr->r; // inorder successor
					q->l = curr;	// inorder predecessor

					curr->r = q;
					curr->rbit = 1;
				}
				else
				{
					insert(curr->r, data);
				}
			}
		}
	}
	void inOrder()
	{
		Node *p = root;
		while (p != head)
		{
			while (p->lbit == 1)
			{
				p = p->l;
			}
			cout << p->data << " ";
			while (p->rbit == 0)
			{
				p = p->r;
				if (p != head)
				{
					cout << p->data << " ";
				}
			}
			p = p->r;
		}
	}
	void preOrder()
	{
		Node *p = root;
		while (p != head)
		{
			while (p->lbit == 1)
			{
				cout << p->data << " ";
				p = p->l;
			}
			cout << p->data << " ";
			while (p->rbit == 0)
			{
				p = p->r;
			}
			p = p->r;
		}
	}
};

signed main()
{

	TBST tbst;
	cout << "\n1.Insert\n2.Inorder\n3.Preorder\n0.EXIT\n";

	int cnd = 1;
	while (cnd)
	{
		cout << "Enter your choice : ";

		int p;
		cin >> p;

		switch (p)
		{
		case 0:
		{
			cnd = 0;
			break;
		}
		case 1:
		{
			cout << "Enter Data : ";
			int x;
			cin >> x;
			tbst.insert(tbst.root, x);
			break;
		}
		case 2:
		{
			cout << "\nInorder : ";
			tbst.inOrder();
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "\nPreorder : ";
			tbst.preOrder();
			cout << endl;
			break;
		}
		}
	}
}
