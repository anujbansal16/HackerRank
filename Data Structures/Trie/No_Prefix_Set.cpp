#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Node Node;
struct Node{
    Node *childs[26];
    bool isPresent;
};

Node *root;

//initalize and return a new node
Node *createNode(){
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->isPresent=false;
    for(int i=0;i<26;i++)
        temp->childs[i]=NULL;
    return temp;
}

//add a node in trie and simultaneiously check the prefix
//return false if already a prefix exist
//else return true
bool add(string s){
    Node * temp=root;
    bool flag=true;
    for(int i=0;i<s.size();i++){
        int index=s[i]-'a';
        if(temp->childs[index]!=NULL && temp->childs[index]->isPresent)
            return false;
        else if(temp->childs[index]==NULL){
         temp->childs[index]=createNode();
            flag=false;
        }
        temp=temp->childs[index];
    }
    if(flag)
        return false;
    temp->isPresent=true;
    return true;
}


int main() {
    root=(Node *)malloc(sizeof(Node));
    root->isPresent=false;
    for(int i=0;i<26;i++)
        root->childs[i]=NULL;
    int n;
    string s;
    cin>>n;
    bool flag;
    while(n--){
        flag=false;
        cin>>s;
        if(!add(s))flag=true;
        if(flag){
            cout<<"BAD SET\n";
            cout<<s<<"\n";
            break;
        }
    }
    if(!flag)
        cout<<"GOOD SET\n";
    return 0;
}
