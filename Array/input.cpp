#include<iostream>
using namespace std;
int main(){
    int c;
    cout<<"enter number of elements:"<<endl;
    cin>>c;
    int a[c];
    cout<<"enter elements"<<endl;
    for (int i=0;i<c;i++){
         
        cin>>a[i];
    }
    for(int i=0;i<c;i++){
        cout<<a[i]<<" ";
    }
    
}