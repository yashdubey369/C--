#include<bits/stdc++.h>
using namespace std;

#define int long long int
//binary search upperbound6
signed main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    int x;
    cout<<"Enter target element:";
    cin>>x;
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]>x){
            high=mid-1;
        }
        else if(a[mid]<x){
            low=mid+1;
        }
        else
        {
            if(mid==0||a[mid-1]!=a[mid]){
                cout<<mid;
                break;
                }
            else{
                high=mid-1;
            }
        }
        cout<<-1;
    }
}