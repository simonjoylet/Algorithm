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

// 前序遍历：根左右
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
		// 注意：先压入右子树
		if (cur->right) st.push(cur->right);
		if (cur->left) st.push(cur->left);
	}
	return rst;
}

// 中序遍历：左根右
vector<int> inorderTraversal(TreeNode* root) 
{
	vector<int> rst;
	stack<TreeNode *> st;
	TreeNode * cur = root;

	while (!st.empty() || cur != NULL)
	{
		// 走到当前节点的最左下方
		if (cur)
		{
			st.push(cur);
			cur = cur->left;
		}
		else
		{
			// 访问左节点和根节点，直接pop即可。
			// 由于压栈顺序，相当于先访问了左节点，然后又访问了根节点。
			cur = st.top();
			st.pop();
			rst.push_back(cur->val);

			// 处理右子树
			// 右子树存在则处理右子树，否则cur==NULL，继续处理上一级根节点
			cur = cur->right;
		}
	}
	return rst;
}

// 后序遍历：左右根
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> rst;
	stack<TreeNode *> st;
	TreeNode * cur = root;
	do
	{
		// 走到当前节点的最左下方
		while (cur)
		{
			st.push(cur);
			cur = cur->left;
		}

		TreeNode * last = NULL;
		while (!st.empty())
		{
			cur = st.top();
			// 如果右子树为空或者刚刚访问过，则可以访问当前节点，否则处理右子树。
			if (cur->right == NULL || cur->right == last)
			{
				rst.push_back(cur->val);
				st.pop();
				last = cur;
			}
			else
			{
				// 处理右子树
				cur = cur->right;
				break;
			}

		}
	} while (!st.empty());

	return rst;
}

// 打印遍历结果
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
