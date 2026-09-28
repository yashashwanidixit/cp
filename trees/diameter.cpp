int diameter(Node* root, int &ans) 
{

    if (root == NULL)
        return -1;

    int leftHeight = diameter(root->left, ans);
    int rightHeight = diameter(root->right, ans);

    // Diameter passing through current node
    ans = max(ans, leftHeight + rightHeight + 2);

    return 1 + max(leftHeight, rightHeight);
}

/// every level /height has one stack frame assigned to it and each stack frame onyl one
//of the nodes at that level are stored in the stack frame

