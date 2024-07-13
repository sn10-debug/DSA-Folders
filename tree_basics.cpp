#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *right_child;
    Node *left_child;

    Node(int data)
    {
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    }
};

Node *buildTree()
{

    int data;
    cout << "Enter the data : ";
    cin >> data;
    if (data == -1)
        return NULL;
    Node *node = new Node(data);

    cout << "Enter the left child for " << data << endl;
    node->left_child = buildTree();
    cout << "Enter the right child for " << data << endl;
    node->right_child = buildTree();

    return node;
}

void levelOrder(Node *root)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        cout << q.front()->data << " ";
        if (q.front()->left_child)
            q.push(q.front()->left_child);
        if (q.front()->right_child)
            q.push(q.front()->right_child);
        q.pop();
    }
}

void inorder(Node *root)
{

    if (root == NULL)
        return;

    inorder(root->left_child);

    cout << root->data << " ";

    inorder(root->right_child);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";

    preorder(root->left_child);
    preorder(root->right_child);
}

void postorder(Node *root)
{

    if (root == NULL)
        return;

    postorder(root->left_child);
    postorder(root->right_child);

    cout << root->data << " ";
}

int heightTree(Node *root)
{

    if (root == NULL)
        return 0;

    int left_height = heightTree(root->left_child);
    int right_height = heightTree(root->right_child);

    return 1 + max(left_height, right_height);
}

int diameterTree(Node *root)
{
    if (root == NULL)
        return 0;

    int left_tree_height = heightTree(root->left_child);
    int right_tree_height = heightTree(root->right_child);

    return max(left_tree_height + 1 + right_tree_height, max(diameterTree(root->left_child), diameterTree(root->right_child)));
}
int main()
{

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Node *root;
    root = buildTree();
    cout << endl;
    cout << "Level Order : " << endl;
    levelOrder(root);
    cout << endl;

    cout << "InOrder : " << endl;
    inorder(root);
    cout << endl;
    cout << "Preorder : " << endl;
    preorder(root);
    cout << endl;

    cout << "Postorder : " << endl;
    postorder(root);
    cout << endl;

    cout << "Height : " << endl;
    cout << heightTree(root) << endl;
    cout << "Diameter of Tree : " << endl;
    cout << diameterTree(root) << endl;

    return 0;
}