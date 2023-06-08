#include<iostream>
using namespace std;
int main(){
    int a[5]={1,3,55,7,9};
    cout<<"enter elements you want to search:";
    int c,k=-1;
    cin>> c;
    for(int i=0;i<5;i++){
        if(a[i]==c){
            k=i;
        }
    }
    if (k>=0){
        cout<<"element is at index:"<<k;

    }
    else{
        cout<<"element not in array.";
    }
        
    }
