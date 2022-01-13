int helper(Node *root, int X, int &count)
{
    if (!root)
        return 0;
    int leftSum = helper(root->left, X, count);
    int rightSum = helper(root->right, X, count);
    int sum = leftSum + rightSum + root->data;
    if (leftSum + rightSum + root->data == X)
        count++;

    return sum;
}
int countSubtreesWithSumX(Node *root, int X)
{
    // Code here
    int count = 0;
    if (!root)
        return 0;
    /*int leftSum =  helper(root->left, X, count);
    int rightSum = helper(root->right, X, count);
    if(leftSum + rightSum + root->data == X)
        count++;*/
    helper(root, X, count);

    return count;
}