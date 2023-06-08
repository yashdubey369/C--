#include<bits/stdc++.h>
using namespace std;

#define int long long int
vector<int> Subarray(){
    vector<int> v={-1,0,1,2,-1,-4};
    unordered_set<int> s;
    int prefix=0;
    for(int i = 0; i <v.size(); i++)
    {
        prefix+=v[i];
    if(s.find(prefix)!=s.end()){
        auto pos=s.find(prefix);
        cout<<*pos<<" "<<i<<endl;
    }
    if(prefix==0){
        cout<<0<<" "<<i<<endl;
    }
    s.insert(prefix);
}
}
signed main(){
      Subarray();
}