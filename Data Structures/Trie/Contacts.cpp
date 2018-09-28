#include <bits/stdc++.h>

using namespace std;
typedef struct Node Node;
struct Node{
    Node *childs[26];
    int count;//count of contacts
};

//root node
Node * root;

//initialize and return a new node
Node *createNode(){
    Node * temp=(Node *)malloc(sizeof(Node));
    temp->count=1;
    for(int i=0;i<26;i++)
        temp->childs[i]=NULL;
    return temp;
}

//add a word in the trie
void add(string s){
    Node * temp=root;
    for(int i=0;i<s.size();i++){
        int index=s[i]-'a';
        if(!temp->childs[index]){
            temp->childs[index]=createNode();
        }
        else
            temp->childs[index]->count++;       
        temp=temp->childs[index];
    }
}

//find a contact
int find(string s){
    Node *temp=root;
    for(int i=0;i<s.size();i++){
        int index=s[i]-'a';
        if(temp->childs[index]==NULL)
            return 0;
        temp=temp->childs[index];
    }
    return temp->count;
    
}

int main()
{
    root=(Node *)malloc(sizeof(Node));
    root->count=0;
    for(int i=0;i<26;i++)
        root->childs[i]=NULL;
    int n;
    string s1,s2;
    cin>>n;
    while(n--){
        cin>>s1>>s2;
        if(s1=="add")
            add(s2);
        else if(s1=="find")
            cout<<find(s2)<<"\n";
    }
    return 0;
}
