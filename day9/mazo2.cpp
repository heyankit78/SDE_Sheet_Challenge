#include <bits/stdc++.h> 
#include<unordered_map>
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int ele = -1;
    vector<int>ans;
    int n = arr.size();
    unordered_map<int,int>mp;
    for(auto i : arr)mp[i]++;
    for(auto it : mp){
        if(it.second > n/3){
            ans.push_back(it.first);
        }
    }
    return ans;
}
