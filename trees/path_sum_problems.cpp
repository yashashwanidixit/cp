//is there a root to leaf path whose sum is 7



bool hasPathSum(Node* root, int target) {

    if (root == NULL)
        return false;

    target -= root->data;

    if (root->left == NULL &&
        root->right == NULL) {

        return target == 0;
    }

    return hasPathSum(root->left, target) ||
           hasPathSum(root->right, target);
}


//max root to lead path sum
int maxPathSum(Node* root) {

    if (root == NULL)
        return INT_MIN;

    if (root->left == NULL &&
        root->right == NULL)
        return root->data;

    int left = maxPathSum(root->left);
    int right = maxPathSum(root->right);

    return root->data + max(left, right);
}