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

int maxPathHelper(Node *root, int &maxp)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = max(0, maxPathHelper(root->left, maxp));
    int rightsum = max(0, maxPathHelper(root->right, maxp));
    maxp = max(maxp, leftsum + rightsum + root->data);
    return root->data + max(leftsum, rightsum);
}
int maxPath(Node *root)
{
    int maxp = INT32_MIN;
    maxPathHelper(root, maxp);
    return maxp;
}