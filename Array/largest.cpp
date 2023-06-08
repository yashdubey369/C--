#include<iostream>
using namespace std;
int main(){
    int a[5]={2,3,6,1,7};
    int c=0,i=0;
    for(i;i<5;i++){
        if(c<a[i]){
           c=a[i];
        }
         
         
    }
    cout<<c;
}