#include <iostream>

struct Node {
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};

int dfs(Node* root, Node* needle, int depth) {
    if (root == needle) {
        return depth;
    }

    if (root->left) {
        int result = dfs(root->left, needle, depth + 1);
        if (result >= 0) {
            return result;
        }
    }
    if (root->right) {
        int result = dfs(root->right, needle, depth + 1);
        if (result >= 0) {
            return result;
        }
    }
    return -1;
}

Node* lca(Node* root, Node* v, Node* w) {
    // Check whether the nodes we seach for are in the same
    // or separate subtrees.

    if (root->left && dfs(root->left, v, 0) >= 0 && dfs(root->left, w, 0) >= 0)
        return lca(root->left, v, w);
    else if (root->right && dfs(root->right, v, 0) >= 0 && dfs(root->right, w, 0) >= 0)
        return lca(root->right, v, w);
    else
        return root; 
}

int dist(Node* root, Node* v, Node* w) {
    Node* common = lca(root, v, w);

    return dfs(common, v, 0) + dfs(common, w, 0);
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    Node* root = new Node;
    root->value = 0;

    Node* n1 = new Node;
    n1->value = 1;

    Node* n2 = new Node;
    n2->value = 2;

    Node* n3 = new Node;
    n3->value = 3;

    Node* n4 = new Node;
    n4->value = 4;

    Node* n5 = new Node;
    n5->value = 5;
    
    Node* n6 = new Node;
    n6->value = 6;

    Node* n7 = new Node;
    n7->value = 7;

    Node* n8 = new Node;
    n8->value = 8;

    /*
            root
          /      \
         n1      n2
        /  \    /  \
       n3  n4  n5  n6
      /  \
     n7  n8

     */

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    n2->right = n6;

    n3->left = n7;
    n3->right = n8;

    std::cout << dist(root, n7, n6) << std::endl; // 5
    std::cout << dist(root, n7, n4) << std::endl; // 3
    std::cout << dist(root, n7, n8) << std::endl; // 2

    return 0;
}
