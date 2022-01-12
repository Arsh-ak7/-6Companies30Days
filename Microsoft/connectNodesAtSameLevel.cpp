void connect(Node *root)
{
    // Your Code Here
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int k = q.size();
        while (k--)
        {
            Node *top = q.front();
            q.pop();
            if (k == 0)
                top->nextRight = NULL;
            else
                top->nextRight = q.front();

            if (top->left)
                q.push(top->left);
            if (top->right)
                q.push(top->right);
        }
    }
}