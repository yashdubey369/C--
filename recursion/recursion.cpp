#include <bits/stdc++.h>
using namespace std;
//recursive codes of.....
int fun(int n){
    if (n==0){
        return 0;
    }
    else{
        cout<<n<<" ";
        fun(n-1);
        cout<<n<<" ";
    }
}
int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int fib(int n){
    if(n==0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
bool ispalindrome(string str,int s,int l){
    if(s>=l){
        return true;
    }
    return (str[s]==str[l])&& ispalindrome(str,s+1,l-1);
    }
int sumofn(int n){
    if (n==0 ){
        return 0;
    }
    return n+sumofn(n-1);
}
int sum_digits(int n){
	if(n==0){
		return 0;}
	 
	return (n%10 + fun(n/10));
}
vector<int> printsubsequence(int ind,vector<int> d,int arr[],int n){
    if(ind==n) return d;
    d.push_back(arr[ind]);
    printsubsequence(ind+1,d,arr,n);
    d.pop_back();
    printsubsequence(ind+1,d,arr,n);
}
int main(){
   int a[3]={3,2,1};
   vector<int> j;
   vector<int> k=printsubsequence(0,j,a,3);
}