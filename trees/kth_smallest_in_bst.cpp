///Kth smallest = kth node visited during inorder traversal..,

void kthSmallest(
    Node* root,
    int& k,
    int& ans
)
    {

    if (root == NULL)
        return;

    kthSmallest(root->left, k, ans);

    k--;

    if (k == 0) {
        ans = root->data;
        return;
    }

    kthSmallest(root->right, k, ans);
}

//for kth largest reversedo root->right call before