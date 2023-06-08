#include<bits/stdc++.h>
using namespace std;

#define int long long int
//Structure of a BINARY TREE:
struct node{
    int data;
    node *left;
    node *right;
    node(int val)
    {
    data=val;
    left=NULL;
    right=NULL;
    }
    
}
//TRAVERSAL OF BINARY TREE::
//DFS(Depth First Search):It searches an element from TOP to BOTTOM. 
//Recursive
 void preorder(node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
 }
 //Iterative 
 vector<int> preorder(node *root){
   vector<int> preorder;
   if(root==NULL) return preorder;
   stack<node> st;
   st.push(root);
   while(!st.empty()) {
      root=st.top();
      st.pop();
      preorder.push_back(root->data);
      if(root->right!=NULL)st.push(root->right);
      if(root->left!=NULL)st.push(root->left);

   }
   return preorder;
 }
 void inorder(node *root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
 }
  void postorder(node *root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
 }
 //BFS(Breadth First Search):It searches an element  level-wise :
void LOT(node* root){
   if(root=NULL) return;
   queue<node*> q;
   q.push(root);
   while(!q.empty()){
      node* curr =q.front();
      q.pop();
      cout<<curr->data<<" ";
      if(curr->left!=NULL) q.push(curr->left);
      if(curr->right!=NULL) q.push(curr->right);

   }
}
 //HEIGHT of BINARY TREE:
 void height(node *root){
    if(root==NULL){
        return 0;
    }
    return max(height(root->left),height(root->right))+1;

 }
 //print nodes at K distance:
 void printKthnode(node* root,k){
   if(root==NULL) return;
   if(k==0) cout<<root->data<<" ";
   else{
      printKthnode(root->left,k-1);
      printKthnode(root->right,k-1);
   } 
 }
signed main(){

}