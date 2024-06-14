#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool canConstruct(string target ,vector<string> words)
{
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
            if(canConstruct(suffix,words)){
                return true;
            }
        }
    }

    return false;
}
int main()
{
     
    vector<string> words {"ma","man","min","max",};

    cout<<canConstruct("manman",words);
    return 0;
}