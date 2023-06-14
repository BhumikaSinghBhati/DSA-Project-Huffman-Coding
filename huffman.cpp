
#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;
struct Node{
    char ch;
    int freq;
    Node *left, *right;
};
Node* getNode(char ch,int freq,Node *left,Node *right){
    struct Node *node;
    node->ch=ch;
    node->freq=freq;
    node->left=left;
    node->right=right;

    return node;
}
struct comp{
    bool operator()(Node *l,Node *r){
        return l->freq; l->freq;
    }

};
void encode(Node *root,string str,unordered_map<char,string> &hm){
    if(root==nullptr){
        return;
    }
    if(!root->left && !root->right){
        hm[root->ch]=str;
    }
    encode(root->left,str+"0",hm);
    encode(root->right,str+"1",hm);

}
void decode(Node *root,int &top_index,string str){
    if(root==nullptr){
        return ;
    }
    if(!root->left && !root->right){
        cout<<root->ch;
    }
    top_index++;
    if(str[top_index]=='0')
        decode(root->left,top_index,str);
    else
        decode(root->right,top_index,str);
    
}
void buildtree(string text){
    
    unordered_map<char,int> m;
    for(char ch: text){
        m[ch]++;

    }
    priority_queue<Node*,vector<Node*>,comp> pq;
    
    
    for(auto it : m){
        pq.push(getNode(it.first,it.second,nullptr,nullptr));
        
        
    }
    while(pq.size()!=1){
       Node *left=pq.top();pq.pop();
    Node *right=pq.top();pq.pop();
       int sum=left->freq+right->freq;
       pq.push(getNode('\0',sum,left,right));
    }
    Node *root=pq.top();
     unordered_map<char,string> hm;
    encode(root,"",hm);
    for(auto pair : hm){
        cout<<pair.first<<" "<<pair.second<<"\n";
    }
cout<<"\n Original string was:\n"<<text<<"\n";
string str="";
for(char ch: text){
 str += hm[ch];
}
cout<<"encoded string is:\n"<<str<<"\n";
int top_index=-1;
cout<<"\n Decoded string is:\n";
while(top_index < (int)str.size() - 2){
    decode(root,top_index,str);
}

    
}
int main(){
string text= "Huffman coding is a data compression algorithm:";

    buildtree(text);

}
