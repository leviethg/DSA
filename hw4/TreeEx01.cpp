#include <iostream>
#include <vector>
using namespace std;

// Structure to represent a node in the tree
struct Node {
    int data;
    vector<Node*> children;

    Node(int val) : data(val) {}
};

class Tree {
public:
    Node* root;
    bool isBinary;

    Tree(int N) {
        root = new Node(1);
        isBinary = true;
        for (int i = 0; i < N - 1; i++) {
            int u, v;
            cin >> u >> v;
            addEdge(u, v);
        }
    }

    // Add an edge to the tree
    void addEdge(int parent, int child) {
        Node* parentNode = findNode(root, parent);
        if (parentNode) {
            Node* childNode = new Node(child);
            parentNode->children.push_back(childNode);
        }
    }

    // Helper function to find a node with given data
    Node* findNode(Node* node, int data) {
        if (!node) return nullptr;
        if (node->data == data) return node;

        for (Node* child : node->children) {
            Node* found = findNode(child, data);
            if (found) return found;
        }

        return nullptr;
    }

    // Calculate the height of the tree
    int height(Node* node) {
        if (!node) return 0;

        int maxDepth = 0;
        for (Node* child : node->children) {
            maxDepth = max(maxDepth, height(child));
        }

        return maxDepth;
    }

    // Preorder traversal
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        for (Node* child : node->children) {
            preorder(child);
        }
    }

    // Postorder traversal
    void postorder(Node* node) {
        if (!node) return;
        for (Node* child : node->children) {
            postorder(child);
        }
        cout << node->data << " ";
    }

    // Inorder traversal (only if it's a binary tree)
    void inorder(Node* node) {
        if (!node) return;
        if (node->children.size() > 2) {
            isBinary = false;
            return;
        }
        if (node->children.size() >= 1) {
            inorder(node->children[0]);
        }
        cout << node->data << " ";
        if (node->children.size() == 2) {
            inorder(node->children[1]);
        }
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    Tree tree(N);

    int treeHeight = tree.height(tree.root);
    cout << treeHeight << endl;

    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    if (tree.isBinary) {
        cout << "Inorder Traversal: ";
        tree.inorder(tree.root);
        cout << endl;
    } else {
        cout << "NOT BINARY TREE" << endl;
    }

    return 0;
}

