#include <iostream>
using namespace std;

int max_num(int a, int b) {
    if (a > b) return a;
    else return b;
}

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

struct BST {
    Node* root;

    BST() {
        root = nullptr;
    }

    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    Node* insert(Node* root, int data) {
        if (root == nullptr) {
            return new Node(data);
        }

        if (data < root->data) {
            root->left = insert(root->left, data);
        } else if (data > root->data) {
            root->right = insert(root->right, data);
        }

        root->height = 1 + max_num(height(root->left), height(root->right));
        return root;
    }

    int maxPath(Node* root) {
        if (root == nullptr) return 0;

        int maxP = height(root->left) + height(root->right) + 1;
        int l = maxPath(root->left);
        int r = maxPath(root->right);

        return max(maxP, max(l, r));
    }
};

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    BST bst;
    Node* root = nullptr;

    for (int x : a) {
        root = bst.insert(root, x);
    }

    cout << bst.maxPath(root) << endl;
    return 0;
}