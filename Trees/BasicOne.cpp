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

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
int heightHelper(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = heightHelper(root->left);
    int right = heightHelper(root->right);
    return 1 + max(left, right);
}
int heightCalculator(Node *root)
{
    int maxHeight = heightHelper(root);
    return maxHeight;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *root = createTreeFromArray(arr);

    cout << "Inorder traversal: ";
    inOrder(root);
    cout << endl;
    cout << "Preorder traversal: ";
    preOrder(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postOrder(root);
    cout << endl;
    cout << "Height of Tree: ";
    cout << heightCalculator(root);
    cout << endl;

    return 0;
}
