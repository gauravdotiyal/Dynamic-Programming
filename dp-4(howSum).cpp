#include <bits/stdc++.h>
#define ll long long
using namespace std;
int check[1000];
vector<int> v;

bool howSum(int target ,vector<int> arr){
    if(target==0) return true;
    if(target<0){
        return false;
    }

    if(check[target]==1) return true;
    if(check[target]==-1) return false;

    for(int i=0;i<arr.size();i++){
        int rem=target-arr[i];
        if(howSum(rem,arr)){
            v.push_back(arr[i]);
            check[target]=true;
            return true;
        }
        else{
            check[target]=-1;
        }
    } 

    return false;
}

int main(){

    int n;
    cin>>n;
   
    int target;
    cin>>target;

    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    

    if(howSum(target,arr)){
        cout<<"YES"<<endl;
        for(auto i:v){
            cout<<v[i]<<" ";
        }cout<<endl;    
    }

    else {
        cout<<"NO"<<endl;
    }
    return 0;
}