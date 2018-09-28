/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
bool a[30]={false};
Node * search(Node *root, int v1, int v2){
    if(root->data>v1 && root->data>v2){
        return search(root->left,v1,v2);
    }
    else if(root->data<v1 && root->data<v2){
         return search(root->right,v1,v2);
    }
    return root;
}

Node *lca(Node *root, int v1,int v2) {
    return search(root,v1,v2);
}