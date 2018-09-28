/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/



    Node * insert(Node * root, int data) {
        if(root==NULL){
            root=(Node *)malloc(sizeof(Node));
            root->left=NULL;
            root->right=NULL;
            root->data=data;
            return root;
        }
        if(root->data>data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
        return root;
    }