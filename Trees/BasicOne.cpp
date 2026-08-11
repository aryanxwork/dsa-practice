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

void inOrder(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}
void preOrder(Node *root, vector<int> ans)
{
    if (root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    preOrder(root->left, ans);
    preOrder(root->right, ans);
}
void flattenHelper(Node *root)
{
    vector<int> ans;
    preOrder(root, ans);
    int n = ans.size();
    Node *curr = root;
    for (int i = 1; i < n; i++)
    {
        curr->left = NULL;
        curr->right = new Node(ans[i]);
        curr = curr->right;
    }
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

bool isSymmetricTree(Node *root)
{
    vector<int> ans;
    inOrder(root, ans);
    int n = ans.size();
    for (int i = 0, j = n - 1; i < n / 2; i++, j--)
    {
        if (ans[i] != ans[j])
        {
            return false;
        }
    }
    return true;
}
bool getPath(Node *root, vector<Node *> &ans, int x)
{
    if (!root)
        return false;
    ans.push_back(root);
    if (root->data == x)
        return true;
    if (getPath(root->left, ans, x) || getPath(root->right, ans, x))
        return true;
    ans.pop_back();
    return false;
}
vector<Node *> rootToNode(Node *root, int target)
{
    vector<Node *> ans;
    if (!root)
        return ans;
    getPath(root, ans, target);
    return ans;
}
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    vector<Node *> path1 = rootToNode(root, p->data);
    vector<Node *> path2 = rootToNode(root, q->data);
    int i = 0;
    Node *ans = NULL;
    while (i < path1.size() && i < path2.size())
    {
        if (path1[i]->data != path2[i]->data)
        {
            break;
        }
        ans = path1[i];
        i++;
    }
    return ans;
}
void markParents(Node *root,
                 unordered_map<Node *, Node *> &parent_track)
{

    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty())
    {

        Node *current = queue.front();
        queue.pop();

        if (current->left)
        {
            parent_track[current->left] = current;
            queue.push(current->left);
        }

        if (current->right)
        {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}
vector<int> distanceK(Node *root, Node *target, int k)
{

    unordered_map<Node *, Node *> parent_track;

    // Node -> Parent
    markParents(root, parent_track);

    // Second BFS: go from target up to K levels
    unordered_map<Node *, bool> visited;

    queue<Node *> queue;
    queue.push(target);
    visited[target] = true;

    int curr_level = 0;

    while (!queue.empty())
    {

        int size = queue.size();

        if (curr_level++ == k)
            break;

        for (int i = 0; i < size; i++)
        {

            Node *current = queue.front();
            queue.pop();

            // Left
            if (current->left &&
                !visited[current->left])
            {

                queue.push(current->left);
                visited[current->left] = true;
            }

            // Right
            if (current->right &&
                !visited[current->right])
            {

                queue.push(current->right);
                visited[current->right] = true;
            }

            // Parent
            if (parent_track[current] &&
                !visited[parent_track[current]])
            {

                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }

    vector<int> result;

    while (!queue.empty())
    {
        Node *current = queue.front();
        queue.pop();

        result.push_back(current->data);
    }

    return result;
}
void flattenBT(Node *root)
{
    flattenHelper(root);
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *root = createTreeFromArray(arr);

    cout << "Inorder traversal: ";

    cout << endl;
    cout << "Preorder traversal: ";

    cout << endl;
    cout << "Postorder traversal: ";
    postOrder(root);
    cout << endl;
    cout << "Height of Tree: ";
    cout << heightCalculator(root);
    cout << endl;

    return 0;
}
