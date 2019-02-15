#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#define MAX 100

struct  node {
    int value;
    node *left;
    node *right;
};

void dfs(node nodes[]) {
    int now;
    stack<int> s;
    s.push(0);
    
    while (!s.empty()) {
        now = s.top();
        cout << now << endl;
        s.pop();

        if (nodes[now].right) {
            s.push(nodes[now].right->value);
        }

        if (nodes[now].left) {
            s.push(nodes[now].left->value);
        }
    }
}

void bfs(node nodes[]) {
    int now;
    queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        now = q.front();
        cout << now << endl;
        q.pop();

        if (nodes[now].left) {
            q.push(nodes[now].left->value);
        }

        if (nodes[now].right) {
            q.push(nodes[now].right->value);
        }
    }
}

int main() {
    int n;
    cin >> n;

    node nodes[MAX];
    for (int i = 0; i < n; i++) {
        int parent, left, right;
        cin >> parent >> left >> right;

        nodes[parent].value = parent;

        if (left == -1) {
            nodes[parent].left = NULL;
        }
        else {
            nodes[parent].left = &nodes[left];
        }

        if (right == -1) {
            nodes[parent].right = NULL;
        }
        else {
            nodes[parent].right = &nodes[right];
        }
    }

    dfs(nodes);
    bfs(nodes);
}