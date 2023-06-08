#include<bits/stdc++.h>
using namespace std;
//unordered_set;
int unset(){
    int a,n;
    cout<<"Enter number of elements:";
    cin>>n;
    unordered_set<int> s;
    cout<<" Enter elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a;
        s.insert(a);
        }
    cout<<"Elements are:";
    for(auto x:s){
        cout<<x<<" ";
    } 
    
}

int count(int arr[],int n){
    unordered_set<int> s(arr,arr+n);
    for(auto x:s){
        cout<<x<<" ";
    } 
    cout<<s.size()<<" ";
}
int main(){
    // int arr[4]={10,10,20,20};
    // count(arr,4);
    unset();
 
    
}