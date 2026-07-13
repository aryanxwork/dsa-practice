#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
Node *createTreeFromArray(vector<int> &arr)
{
    if (arr.empty() || arr[0] == -1)
        return NULL;

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        Node *current = q.front();
        q.pop();

        if (i < arr.size() && arr[i] != -1)
        {
            current->left = new Node(arr[i]);
            q.push(current->left);
        }
        i++;

        if (i < arr.size() && arr[i] != -1)
        {
            current->right = new Node(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}
int balancedHelper(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = balancedHelper(root->left);
    int right = balancedHelper(root->right);
    if (left == -1 || right == -1)
    {
        return -1;
    }
    if (abs(left - right) > 1)
    {
        return -1;
    }
    return 1 + max(left, right);
}
bool isBalanced(Node *root)
{
    if (balancedHelper(root) != -1)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *root = createTreeFromArray(arr);
    cout << (isBalanced(root) ? "true" : "false") << endl;
    vector<int> unbalancedArr = {1, 2, 3, 4, -1, -1, -1, 5, -1};
    Node *unbalancedRoot = createTreeFromArray(unbalancedArr);
    cout << (isBalanced(unbalancedRoot) ? "true" : "false");
}