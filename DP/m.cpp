#include<bits/stdc++.h>
using namespace std;

#define int long long int

signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
cout<<-15%7;
     //KADANE ALGORITHM
    long long maxSubarraySum(int arr[], int n){
            
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
}