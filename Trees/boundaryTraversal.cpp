#include<bits/stdc++.h>
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


    bool isLeaf(Node* root) {
        return (root->left == NULL && root->right == NULL);
    }

    void leftBoundary(Node* root, vector<int>& ans) {

        Node* curr = root->left;

        while (curr != NULL) {

            if (!isLeaf(curr))
                ans.push_back(curr->data);

            if (curr->left != NULL)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(Node* root, vector<int>& ans) {

        if (root == NULL)
            return;

        if (isLeaf(root)) {
            ans.push_back(root->data);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void rightBoundary(Node* root, vector<int>& ans) {

        Node* curr = root->right;
        vector<int> temp;

        while (curr != NULL) {

            if (!isLeaf(curr))
                temp.push_back(curr->data);

            if (curr->right != NULL)
                curr = curr->right;
            else
                curr = curr->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(Node* root) {

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
     vector<vector<int>> verticalTraversal(Node* root) {

        map<int, map<int, multiset<int>>> nodes;
        queue<pair<Node*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int x = it.second.first;
            int y = it.second.second;

            nodes[x][y].insert(node->data);

            if (node->left)
                q.push({node->left, {x - 1, y + 1}});

            if (node->right)
                q.push({node->right, {x + 1, y + 1}});
        }

        vector<vector<int>> ans;

        for (auto p : nodes) {

            vector<int> col;

            for (auto q : p.second) {

                col.insert(col.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(col);
        }

        return ans;
    }
    vector<int> topView(Node *root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> mpp;
        queue<pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            Node* node = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end()){
                mpp[line] = node->data;
            }
            if (node->left)
                q.push({node->left, line - 1});

            if (node->right)
                q.push({node->right, line + 1});
        }

        for (auto it : mpp) {
            ans.push_back(it.second);
        }

        return ans;
    }