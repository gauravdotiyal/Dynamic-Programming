#include <bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<string,bool> memo;
bool canConstruct(string target ,vector<string> words,unordered_map<string,bool> memo)
{

    if(memo.find(target)!=memo.end()){
       return memo[target];
    }
    if(target==""){
        return true;
    }
     
    int totalcount=0;
    for(int i=0;i<words.size();++i){
        size_t pos=target.find(words[i]);
        if(pos==0)
        {
            string suffix=target;
            suffix.erase(pos,words[i].size());
            if(canConstruct(suffix,words,memo)){
                memo[target]=true;
                return true;
            }
        }
    }
    
    memo[target]=false;
    return false;
}
int main()
{
     
    vector<string> words {"ma","man","min","max",};

    cout<<canConstruct("manman",words,memo);
    return 0;
}