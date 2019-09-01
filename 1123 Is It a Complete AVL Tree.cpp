#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
};

Node *leftRotate(Node *r)
{
	Node *tmp = r->right;
	r->right = tmp->left;
	tmp->left = r;
	return tmp;
}

Node *rightRotate(Node *r)
{
	Node *tmp = r->left;
	r->left = tmp->right;
	tmp->right = r;
	return tmp;
}

Node *leftRightRotate(Node *r)
{
	r->left = leftRotate(r->left);
	return rightRotate(r);
}

Node *rightLeftRotate(Node *r)
{
	r->right = rightRotate(r->right);
	return leftRotate(r);
}

int getH(Node *r)
{
	if (r == nullptr)
	{
		return 0;
	}
	return max(getH(r->left) + 1, getH(r->right) + 1);
}
Node *insert(Node *r, int v)
{
	if (r == nullptr)
	{
		r = new Node();
		r->val = v;
		return r;
	}
	if (v < r->val)
	{
		r->left = insert(r->left, v);
		int lh = getH(r->left), rh = getH(r->right);
		if (lh - rh >= 2)
		{
			if (v < r->left->val)
			{
				r = rightRotate(r);
			}
			else
			{
				r = leftRightRotate(r);
			}
		}
	}
	else
	{
		r->right = insert(r->right, v);
		int lh = getH(r->left), rh = getH(r->right);
		if (rh - lh >= 2)
		{
			if (v < r->right->val)
			{
				r = rightLeftRotate(r);
			}
			else
			{
				r = leftRotate(r);
			}
		}
	}
	return r;
}

int levelOrder(Node *tree)
{
	vector<Node *> list[2];
	int flag = 0, level = 0;
	bool isCom = true, pre;
	list[0].push_back(tree);
	while (list[flag].size() != 0)
	{
		list[1 - flag].clear();
		pre = true;
		for (int i = 0; i < list[flag].size(); i++)
		{
			Node *u = list[flag][i];
			printf("%s%d", u == tree ? "" : " ", u->val);
			if (u->left != nullptr)
			{
				if (!pre)
					isCom = false;
				list[1 - flag].push_back(u->left);
			}
			else
			{
				pre = false;
			}
			if (u->right != nullptr)
			{
				if (!pre)
					isCom = false;
				list[1 - flag].push_back(u->right);
			}
			else
			{
				pre = false;
			}
		}
		if (!list[1 - flag].empty() && list[flag].size() != pow(2, level))
		{
			isCom = false;
		}
		flag = 1 - flag;
		level++;
	}
	printf("\n%s", isCom ? "YES" : "NO");
	return 0;
}

int main()
{
	int N;
	Node *tree = nullptr;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		tree = insert(tree, n);
	}
	levelOrder(tree);
	return 0;
}
