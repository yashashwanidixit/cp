/// all root to leaf paths 

void allPaths(
    Node* root,
    vector<int>& path
) {

    if (root == NULL)
        return;

    path.push_back(root->data);

    // Leaf
    if (root->left == NULL &&
        root->right == NULL) {

        for (int x : path)
            cout << x << " ";

        cout << "\n";

        path.pop_back();
        return;
    }

    allPaths(root->left, path);
    allPaths(root->right, path);

    path.pop_back();
}