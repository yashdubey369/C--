#include<bits/stdc++.h>
using namespace std;
//#define int long long int
//without using DynamicProgramming:
int lcs(string s1,string s2,int m,int n){
    if(m==0||n==0){
        return 0;
    }
    else{
    if(s1[m-1]==s2[n-1]){
        return 1+lcs(s1,s2,m-1,n-1);
    }
    else{
        return max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
    }
    }
}
//Using DynamicProgramming(memoisation):
int lcsdp(string s1,string s2,int m,int n){
    vector<vector<int>> memo(m+1,vector<int>(n+1,-1));
    if(memo[m][n]==-1){
        if(m==0||n==0){
            memo[m][n]=0;
        }
        else{
            if(s1[m-1]==s2[n-1]){
                memo[m][n]=1+lcs(s1,s2,m-1,n-1);
        }
        else{
            memo[m][n]=max(lcs(s1,s2,m,n-1),lcs(s1,s2,m-1,n));
        }
        }
        return memo[m][n];
    }
    return memo[m][n];
}
signed main(){
    string s1="muskan";
    string s2="muskan";
    int a=lcsdp(s1,s2,7,7);
    cout<<a;
    return 0;
}