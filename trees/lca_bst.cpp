Node* LCA_BST(Node* root, int a, int b) {

    while (root != NULL) {

        if (a < root->data && b < root->data) {
            root = root->left;
        }

        else if (a > root->data && b > root->data) {
            root = root->right;
        }

        else {
            return root;
        }
    }

    return NULL;
}

/// normal tree
Node* LCA(Node* root, int a, int b) {

    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    Node* left = LCA(root->left, a, b);
    Node* right = LCA(root->right, a, b);

    if (left != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;

    return right;
}