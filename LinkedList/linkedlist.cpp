#include<bits/stdc++.h>
using namespace std;
//struct code
struct Node
{
    int data;
    Node *next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
};
//TRAVERSAL IN LINKED LIST//
//Iterative code::
void printlist(Node *head){
    while (head!=NULL)
    {
        cout<<(head->data)<<" ";
        head=head->next;
    }
    
}
//Recursive Code::
void rprint(Node *head){
    if(head==NULL){ 
        return;
    }
     cout<<(head->data)<<" ";
     rprint(head->next);
     
}

//INSERTION IN LL:
//Insertbegin function::
Node *insertbegin(Node *head,int x){
    Node *temp=new Node(x);
    temp->next=head;
    return temp;

}
//InsertEND function::
Node *insertend(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL)
    return temp;
    Node *curr=head;
    while (curr->next!=NULL)
    {
        curr=curr->next;
    }
    curr->next=temp;
    return head;
    
}
//Insert at a position
Node *insatpos(Node *head,int a,int x){
    Node *temp=new Node(a);
    if(x==1){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    while (x-2>0&&curr!=NULL)
    {
        curr=curr->next;
        x--;
    }
    if(curr==NULL){
        return head;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}
//Sorted insert
Node *sortinsert(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        return temp;
    }
    if(head->data>temp->data){
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    while ((curr->next->data<temp->data) && (curr->next!=NULL)){
         curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

//DELETION IN LL:
//deleting first element
Node *deltefirst(Node *head){
    if(head==NULL){
        return NULL;

    }
    Node *temp=head->next;
    delete(head);
    return temp;
}
//deleting last element
Node *deletelast(Node *head){
    Node *curr=head;
    if (head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL){
        delete(head);
        return NULL;
    }
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    delete(curr->next);
    curr->next=NULL;
    return head;
}
 Node* deleteNode(Node *head,int x)
{
    //Your code here
    Node *curr=head;
    if(head==NULL)
    return NULL;
    if(x==1){
    curr=curr->next;
    delete(head);
    return curr;
    }
    while(((x-2)>0)&&(curr->next->next!=NULL)){
        curr=curr->next;
        x--;
    }
    delete(curr->next);
    curr->next=curr->next->next;
    return head;
}

//SEARCHING IN LL:
int search(Node *head,int x){
    Node *curr=head;
    int a=1;
    while(curr!=NULL){
        if(curr->data==x){
            return a;
        }
        curr=curr->next;
        a++;
        
    }
     
    return -1;
    
}

//Middle element
Node *middle(Node *head){
    Node *curr=head;
    int cnt=0;
    while (curr!=NULL)
    {
        curr=curr->next;
        cnt++;
    }
    curr=head;
    for (int i = 0; i < cnt/2; i++)
    {
        curr=curr->next;
    }
    cout<<curr->data;
}
//Get element from last nth node:
Node *lastNThnode(Node *head,int x){
    Node *curr=head;
    int cnt=0;
    while (curr!=NULL)
    {
        curr=curr->next;
        cnt++;
    }
    curr=head;
    for(int i=0;i<cnt-x;i++){
        curr=curr->next;
    }
    cout<<curr->data;
}
//Reverse a LinkedList:
Node *reversell(Node *head){
    vector<int> v;
    Node *curr=head;
    while (curr!=NULL)
    {
        v.push_back(curr->data);
        curr=curr->next;
    }
    curr=head;
    while (curr!=NULL)
    {   
        curr->data=v.back();
        curr=curr->next;
        v.pop_back();
    }
    return head;
    
}
int main(){
    // Node *head=new Node(10);
    // head->next=new Node(20);
    // head->next->next=new Node(30);
    // head->next->next->next=new Node(7);
    Node *head=NULL;
    head=insertbegin(head,30);
    head=insertbegin(head,20);
    head=insertbegin(head,15);
    head=insertbegin(head,10);
   // rprint(head);
    //cout<<endl;
    //head=insatpos(head,1,3);
    //rprint(head);
    //cout<<endl;
    //head=sortinsert(head,);

    //int a=search(head,10);
    
    // int a;
    // cout<<"enter 4 entries";
    // for (int i = 0; i < 4; i++)
    // {
    //     cin>>a;
    //     head=insertend(head,a);
    // }
    
    //rprint(head);
    //cout<<endl;
    //head=deltefirst(head);
    //rprint(head);
    //cout<<endl;
   // head=deletelast(head);
    rprint(head);

    cout<<endl;
    reversell(head);
    rprint(head);
    //lastNThnode(head,4);

    //cout<<a;

    return 0;
}