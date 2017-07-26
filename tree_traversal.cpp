#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ǰ�������������
vector<int> preorderTraversal(TreeNode* root) 
{
	vector<int> rst;
	stack<TreeNode *> st;
	if (root) st.push(root);
	while (!st.empty())
	{
		TreeNode * cur = st.top();
		st.pop();
		rst.push_back(cur->val);
		// ע�⣺��ѹ��������
		if (cur->right) st.push(cur->right);
		if (cur->left) st.push(cur->left);
	}
	return rst;
}

// ��������������
vector<int> inorderTraversal(TreeNode* root) 
{
	vector<int> rst;
	stack<TreeNode *> st;
	TreeNode * cur = root;

	while (!st.empty() || cur != NULL)
	{
		// �ߵ���ǰ�ڵ�������·�
		if (cur)
		{
			st.push(cur);
			cur = cur->left;
		}
		else
		{
			// ������ڵ�͸��ڵ㣬ֱ��pop���ɡ�
			// ����ѹջ˳���൱���ȷ�������ڵ㣬Ȼ���ַ����˸��ڵ㡣
			cur = st.top();
			st.pop();
			rst.push_back(cur->val);

			// ����������
			// ��������������������������cur==NULL������������һ�����ڵ�
			cur = cur->right;
		}
	}
	return rst;
}

// ������������Ҹ�
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> rst;
	stack<TreeNode *> st;
	TreeNode * cur = root;
	do
	{
		// �ߵ���ǰ�ڵ�������·�
		while (cur)
		{
			st.push(cur);
			cur = cur->left;
		}

		TreeNode * last = NULL;
		while (!st.empty())
		{
			cur = st.top();
			// ���������Ϊ�ջ��߸ոշ��ʹ�������Է��ʵ�ǰ�ڵ㣬��������������
			if (cur->right == NULL || cur->right == last)
			{
				rst.push_back(cur->val);
				st.pop();
				last = cur;
			}
			else
			{
				// ����������
				cur = cur->right;
				break;
			}

		}
	} while (!st.empty());

	return rst;
}

// ��ӡ�������
void print_traversal(vector<int> & order, const char * name)
{
	cout << name << ": ";
	for (size_t i = 0; i < order.size(); ++i)
	{
		cout << order[i] << " ";
	}
	cout << endl;
}

int main()
{
	TreeNode * root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);

	vector<int> preorder = preorderTraversal(root);
	vector<int> inoder = inorderTraversal(root);
	vector<int> postorder = postorderTraversal(root);

	print_traversal(preorder, "preorder");
	print_traversal(inoder, "inoder");
	print_traversal(postorder, "postorder");
	
	getchar();
	return 0;
}
