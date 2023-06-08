#include<bits/stdc++.h>
using namespace std;
//dp vector: vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
//W=max weight or max size of sack,
//wt[]=weight of elements
//val[]=value of elements
//n=number of elements
//dp :dp vector
int knapsack(int W,int wt[],int val[],int n,vector<vector<int>> &dp){
         if(n==0||W==0) dp[W][n]=0;
         if(dp[W][n]==-1){
           if(wt[n-1]>W){
            dp[W][n]=knapsack(W,wt,val,n-1,dp);
           }
            else dp[W][n]=max(knapsack(W,wt,val,n-1,dp),val[n-1]+knapsack(W-wt[n-1],wt,val,n-1,dp));
    }
       else return dp[W][n];
    }  
//Variations in KnapSack:
//1.Subset Sum::This function tells us whether an array contains a subset of given sum.It Returns True/False.
bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=sum;i++){
            dp[0][i]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                 if(arr[i-1]<=j) dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
                  else dp[i][j]=dp[i-1][j];
                 
            }
        }
        
        return dp[n][sum];
    }
//2.Equal Partitions in Subst Sum:
   
        