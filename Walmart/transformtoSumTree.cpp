class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int getSum(Node *root)
    {
        if (!root)
            return 0;
        int left = getSum(root->left);
        int right = getSum(root->right);

        int curr = root->data;
        if (left == 0 && right == 0)
            root->data = 0;
        else
            root->data = left + right;
        return curr + left + right;
    }
    void toSumTree(Node *node)
    {
        // Your code here
        getSum(node);
    }
};