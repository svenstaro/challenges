#include <iostream>

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
};

int dfs(Node* root, Node* needle, int depth) {
    if (root == needle)
        return depth;

    int result = -1;
    if (root->left) {
        result = dfs(root->left, needle, depth + 1);
    } 
    if (root->right)
        result = dfs(root->right, needle, depth + 1);

    if (result <
        return -1

    return -1;
}

Node* lca(Node* root, Node* v, Node* w) {
    // Check whether the nodes we seach for are in the same
    // or separate subtrees.
    if (dfs(root->left, v, 0) && dfs(root->left, w, 0))
        return lca(root->left, v, w);
    else if (dfs(root->right, v, 0) && dfs(root->right, w, 0))
        return lca(root->right, v, w);
    else
        return root; 
}

int dist(Node* root, Node* v, Node* w) {
    Node* common = lca(root, v, w);

    return dfs(common->left, v, 0) + dfs(common->right, w, 0);
}

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    Node* root = new Node;
    Node* n1 = new Node;
    Node* n2 = new Node;
    Node* n3 = new Node;
    Node* n4 = new Node;
    Node* n5 = new Node;
    Node* n6 = new Node;
    Node* n7 = new Node;
    Node* n8 = new Node;

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

    std::cout << dfs(root, n4, 0) << std::endl;

    std::cout << dist(root, n7, n6) << std::endl;
    std::cout << dist(root, n7, n4) << std::endl;
    std::cout << dist(root, n7, n8) << std::endl;

    return 0;
}
