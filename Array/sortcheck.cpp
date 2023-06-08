#include<iostream>
#include<string>
using namespace std;
int main(){
    int arr[4]={1,2,3,4};
    string s;
    for(int i=0;i<4;i++){
        if(arr[i+1]<arr[i]){
            s="sorted";
        }
        else{
            s="nsorted";
        }

    }
    if(s=="sorted"){
        cout<<"sorted";
    }
    else{
        cout<<"not sorted";
    }
}