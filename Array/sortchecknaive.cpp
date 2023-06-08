#include<iostream>
using namespace std;
int main(){
    int arr[4]={2,3,5,9};
    bool a;
    for (int i=0;i<4;i++){
         for(int j=i+1;j<4;j++){
            if(arr[i]<arr[j]){
                a=true;
                 }
            else{
                a=false;
            }
         }
    }
    if(a==true){
        cout<<"sorted"<<endl;
    }
    else{
        cout<<"not sorted"<<endl;
    }
    return 0;
}