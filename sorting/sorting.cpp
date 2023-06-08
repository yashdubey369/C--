#include<bits/stdc++.h>
using namespace std;

 //use of sort function
 //increasing sort(a,a+n)
 //decreasing sort(a,a+n,greater<int>)
 //BUBBLE SORT;
 void bubblesort(int a[],int n){
    //time complexity theta(n^2); 
    for(int i=0;i<n;i++){
       bool swapped=false;
       for(int j=0;j<n-i-1;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
            swapped=true;
        }
       }
       if(swapped==false){
        break;
       }
    }
 }
 //SELECTION SORT;
 void selectionsort(int a[],int n){
    //time complexity theta(n^2);
    for(int i=0;i<n;i++){
       int min_ind=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_ind]){
                min_ind=j;
            }
        }
        swap(a[min_ind],a[i]);
    }
 }
 //INSERTION SORT;
 void insertionsort(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0&& a[j]>key){
            a[j]=key;
        }
        a[j+1]=key;
    }
 }
 int main(){
    int arr[6]={20,5,40,60,10,30};
    bubblesort(arr,6);
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<endl;
    selectionsort(arr,6);
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<endl;
    insertionsort(arr,6);
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<" "<<arr[5]<<endl;
}