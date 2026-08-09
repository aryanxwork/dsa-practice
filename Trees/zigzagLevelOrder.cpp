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
vector<vector<int>> levelOrderTraversal(Node *root)
{
    vector<vector<int>> result;
    queue<Node *> q;
    q.push(root);
    if(root==NULL) { return result; }
    while (!q.empty())
    {

        int size = q.size();
        vector<int> row;
        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();
            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
            row.push_back(current->data);
        }

        result.push_back(row);
    }
    return result;
}
vector<vector<int>> zigzagLevelOrderTraversal(Node *root)
{
    vector<vector<int>> result;
    queue<Node *> q;
    q.push(root);
    bool left_to_Right=1;
    if(root==NULL) { return result; }
    while (!q.empty())
    {

        int size = q.size();
        vector<int> row(size);
        
        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();
            int index=left_to_Right? i:(size-i-1);

            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
            
            row[index]=current->data;
        }
        
        left_to_Right=!left_to_Right;
        result.push_back(row);
    }
    return result;
}
