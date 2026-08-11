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
    if (root == NULL)
    {
        return result;
    }
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
    bool left_to_Right = 1;
    if (root == NULL)
    {
        return result;
    }
    while (!q.empty())
    {

        int size = q.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++)
        {
            Node *current = q.front();
            q.pop();
            int index = left_to_Right ? i : (size - i - 1);

            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);

            row[index] = current->data;
        }

        left_to_Right = !left_to_Right;
        result.push_back(row);
    }
    return result;
}

bool isLeaf(Node *root)
{
    return (root->left == NULL && root->right == NULL);
}

void leftBoundary(Node *root, vector<int> &ans)
{

    Node *curr = root->left;

    while (curr != NULL)
    {

        if (!isLeaf(curr))
            ans.push_back(curr->data);

        if (curr->left != NULL)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addLeaves(Node *root, vector<int> &ans)
{

    if (root == NULL)
        return;

    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }

    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void rightBoundary(Node *root, vector<int> &ans)
{

    Node *curr = root->right;
    vector<int> temp;

    while (curr != NULL)
    {

        if (!isLeaf(curr))
            temp.push_back(curr->data);

        if (curr->right != NULL)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

vector<int> boundaryTraversal(Node *root)
{

    vector<int> ans;

    if (root == NULL)
        return ans;

    if (!isLeaf(root))
        ans.push_back(root->data);

    leftBoundary(root, ans);
    addLeaves(root, ans);
    rightBoundary(root, ans);

    return ans;
}
vector<vector<int>> verticalTraversal(Node *root)
{

    map<int, map<int, multiset<int>>> nodes;
    queue<pair<Node *, pair<int, int>>> q;

    q.push({root, {0, 0}});

    while (!q.empty())
    {

        auto it = q.front();
        q.pop();

        Node *node = it.first;
        int x = it.second.first;
        int y = it.second.second;

        nodes[x][y].insert(node->data);

        if (node->left)
            q.push({node->left, {x - 1, y + 1}});

        if (node->right)
            q.push({node->right, {x + 1, y + 1}});
    }

    vector<vector<int>> ans;

    for (auto p : nodes)
    {

        vector<int> col;

        for (auto q : p.second)
        {

            col.insert(col.end(), q.second.begin(), q.second.end());
        }

        ans.push_back(col);
    }

    return ans;
}
vector<int> topView(Node *root)
{

    vector<int> ans;

    if (root == NULL)
        return ans;

    map<int, int> mpp;
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {

        auto it = q.front();
        q.pop();

        Node *node = it.first;
        int line = it.second;

        if (mpp.find(line) == mpp.end())
        {
            mpp[line] = node->data;
        }
        if (node->left)
            q.push({node->left, line - 1});

        if (node->right)
            q.push({node->right, line + 1});
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;
}
void makeParent(Node *root, unordered_map<Node *, Node *> &mpp)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->left)
        {
            mpp[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            mpp[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

int minTimetoBurn(Node *root, Node *target)
{
    if (!root)
        return 0;
    unordered_map<Node *, Node *> mpp;
    makeParent(root, mpp);

    queue<Node *> q;
    unordered_map<Node *, bool> visited;

    q.push(target);
    visited[target] = true;

    int time = 0;

    while (!q.empty())
    {
        int size = q.size();
        bool burnedNodes = false;

        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left && !visited[curr->left])
            {
                visited[curr->left] = true;
                q.push(curr->left);
                burnedNodes = true;
            }
            if (curr->right && !visited[curr->right])
            {
                visited[curr->right] = true;
                q.push(curr->right);
                burnedNodes = true;
            }
            if (mpp[curr] && !visited[mpp[curr]])
            {
                visited[mpp[curr]] = true;
                q.push(mpp[curr]);
                burnedNodes = true;
            }
        }
        if (burnedNodes)
            time++;
    }
    return time;
}

int calculateLeft(Node *root)
{
    int leftHeight = 0;
    while (root)
    {
        leftHeight++;
        root = root->left;
    }
    return leftHeight;
}
int calculateRight(Node *root)
{
    int rightHeight = 0;
    while (root)
    {
        rightHeight++;
        root = root->right;
    }
    return rightHeight;
}
int totalNodes(Node *root)
{
    if (!root)
        return 0;

    int leftHeight = calculateLeft(root);
    int rightHeight = calculateRight(root);

    if (leftHeight == rightHeight)
    {
        return (1 << leftHeight) - 1;
    }

    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

Node *buildTreeHelper(vector<int> preOrder, int preStart, int preEnd, vector<int> inOrder, int inStart, int inEnd, map<int, int> &mpp)
{
    if (inStart > inEnd || preStart > preEnd)
        return NULL;

    Node *root = new Node(preOrder[preStart]);

    int idx = mpp[root->data];
    int nodesLeft = idx - inStart;

    root->left = buildTreeHelper(preOrder, preStart + 1, preStart + nodesLeft, inOrder, inStart, idx - 1, mpp);
    root->right = buildTreeHelper(preOrder, preStart + nodesLeft + 1, preEnd, inOrder, idx + 1, inEnd, mpp);
    return root;
}
Node *buildTreefromPreIn(vector<int> preOrder, vector<int> inOrder)
{
    map<int, int> mpp;
    int n = inOrder.size();

    for (int i = 0; i < n; i++)
    {
        mpp[inOrder[i]] = i;
    }

    Node *root = buildTreeHelper(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1, mpp);
    return root;
}

Node *buildTreeHelperPost(vector<int> postOrder, int postStart, int postEnd, vector<int> inOrder, int inStart, int inEnd, map<int, int> &mpp)
{
    if (inStart > inEnd || postStart > postEnd)
        return NULL;

    Node *root = new Node(postOrder[postEnd]);

    int idx = mpp[root->data];
    int nodesLeft = idx - inStart;

    root->left = buildTreeHelperPost(postOrder, postStart, postStart + nodesLeft - 1, inOrder, inStart, idx - 1, mpp);
    root->right = buildTreeHelperPost(postOrder, postStart + nodesLeft, postEnd - 1, inOrder, idx + 1, inEnd, mpp);

    return root;
}

Node *buildTreefromPostIn(vector<int> postOrder, vector<int> inOrder)
{
    map<int, int> mpp;
    int n = inOrder.size();

    for (int i = 0; i < n; i++)
    {
        mpp[inOrder[i]] = i;
    }

    Node *root = buildTreeHelperPost(postOrder, 0, postOrder.size() - 1, inOrder, 0, inOrder.size() - 1, mpp);
    return root;
}