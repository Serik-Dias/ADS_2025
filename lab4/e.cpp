#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Node*> nodes(n + 1, nullptr);
    for (int i = 1; i <= n; i++) {
        nodes[i] = new Node(i);
    }

    for (int i = 0; i < n - 1; i++) {
        int parent, child, side;
        cin >> parent >> child >> side;
        if (side == 0) nodes[parent]->left = nodes[child];
        else nodes[parent]->right = nodes[child];
    }

    // BFS to calculate width
    queue<Node*> q;
    q.push(nodes[1]); // root is always 1
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        maxWidth = max(maxWidth, levelSize);

        for (int i = 0; i < levelSize; i++) {
            Node* cur = q.front();
            q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }

    cout << maxWidth << "\n";
    return 0;
}
