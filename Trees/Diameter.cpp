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
int heightDiameter(Node *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = heightDiameter(root->left, diameter);
    int right = heightDiameter(root->right, diameter);
    diameter = max(diameter, left + right);
    return 1 + max(left, right);
}
int calculateDiameter(Node *root)
{
    int diameter = 0;
    heightDiameter(root, diameter);
    return diameter;
}
int main()
{
    // Tree with a clear, traceable diameter
    vector<int> arr = {1, 2, 3, 4, 5, -1, -1, 6, -1, -1, 7};
    Node *root = createTreeFromArray(arr);

    int diameter = calculateDiameter(root);
    cout << "Diameter (edges): " << diameter << endl;

    // Simple balanced tree for comparison
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    Node *root2 = createTreeFromArray(arr2);

    int diameter2 = calculateDiameter(root2);
    cout << "Diameter (edges): " << diameter2 << endl;

    return 0;
}