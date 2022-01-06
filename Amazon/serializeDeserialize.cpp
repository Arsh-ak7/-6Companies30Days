class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> v;
    vector<int> serialize(Node *root) 
    {
        //Your code here
        if(root==NULL){
        v.push_back(-1);
        return v;
        }
        v.push_back(root->data);
        serialize(root->left);
        serialize(root->right);
        return v;
    }
    
    //Function to deserialize a list and construct the tree.
    int i = 0;
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       if(i >= A.size() || A[i]==-1){
           i++;
           return NULL;
       }
       Node *newRoot = new Node(A[i++]);
       newRoot->left = deSerialize(A);
       newRoot->right = deSerialize(A);
       
       return newRoot;
    }

};
