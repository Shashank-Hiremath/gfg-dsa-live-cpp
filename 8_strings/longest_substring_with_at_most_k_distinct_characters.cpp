//https://www.codingninjas.com/studio/problems/distinct-characters_2221410?leftPanelTab=3

#include<bits/stdc++.h>

int kDistinctChars(int k, string &str)
{
    // Write your code here
    unordered_map<char,int>um;
    int win=0;
    int l=0;
    for(int i=0;i<str.size();i++){
        um[str[i]]++;
        if(um.size()<=k) {

            win=max(win,i-l+1);
        }
        else{
            while(um.size()>k){
                um[str[l]]--;
                if(um[str[l]]==0) um.erase(str[l]);
                l++;

            }
        }
        
    
    }
    return win;
}