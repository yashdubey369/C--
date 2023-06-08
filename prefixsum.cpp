#include<bits/stdc++.h>
using namespace std;

//#define int long long int
void prefixsum(int arr[],int n){
    //int n=sizeof(arr)/sizeof(int);
    int prsum[n];
    prsum[0]=arr[0];
    for(int i=1;i<n;i++){
        prsum[i]=prsum[i-1]+arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<prsum[i]<<" ";
    }
} 
//KADANE ALGORITHM
void maxSubarraySum(int arr[], int n){
        
        // Your code here
        int prefix=0;
        int max=INT_MIN,start=0,s=0,end=0;
        for(int i=0;i<n;i++){
            prefix+=arr[i];
             
            if(max<prefix) {
                max=prefix;
                start=s;
                end=i;
            }  
            if(prefix<0){
                prefix=0;
                s=i+1;
            }
             
        }
        cout<< max<<" "<<start<<" "<<end<<" ";
        
    }
signed main(){
    int arr[5]={4,-3,5,-2,-1};
    maxSubarraySum(arr,5);
     
} 