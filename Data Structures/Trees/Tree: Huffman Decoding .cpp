/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

int i=0;
int count1=0;
void decode_huff(node * root, string s) {
    while(i!=s.size()+1){
        if(root->left==NULL && root->right==NULL){
            cout<<root->data<<"";
            break;
        }
        else{
            if(s[i]=='0'){
                i++;
                count1++;
                decode_huff(root->left,s);
                count1--;
                if(count1!=0)
                    break;
            } 
            else {
                i++;
                count1++;
                decode_huff(root->right,s);
                count1--;
                if(count1!=0)
                    break;
            }
        }
    }
}
