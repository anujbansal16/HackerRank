
/*
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

    void levelOrder(Node * root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node * fr=q.front();
            cout<<fr->data<<" ";
            if(fr->left!=NULL)
                q.push(fr->left);
            if(fr->right!=NULL)
                q.push(fr->right);
            q.pop();
        }

    }