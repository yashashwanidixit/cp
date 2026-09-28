
#ifndef  find path from root to that node


bool findPath(Node* root, int target, vector<int>& path) {

    if (root == NULL)
        return false;

    path.push_back(root->data);

    if (root->data == target)
        return true;

    if (findPath(root->left, target, path) ||
        findPath(root->right, target, path))
        return true;

    // This node didn't lead to target
    path.pop_back();

    return false;
}



#endif



