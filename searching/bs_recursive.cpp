#include<bits/stdc++.h>
using namespace std;

//#define int long long int
int binarysearch(int a[],low,high,x){
    int mid=(high+low)/2;
    int cnt=0;
    if(x<a[mid]){
         binarysearch(int a[],low,mid-1,x);

    }
    else if(x>a[mid]){
         binarysearch(int a[],mid+1,high,x);

    }
    else{
        cnt++;
    }
    return cnt;
}
int main(){
    int arr[6]={10,15,20,20,50,50};
    binarysearch(arr,0,6,20); 

    
}