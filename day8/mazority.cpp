#include <bits/stdc++.h> 
#include<unordered_map>
int findMajorityElement(int arr[], int n) {
	// Write your code here.
     unordered_map<int,int>mp;
        for(int i = 0;i<n;i++)mp[arr[i]]++;
//         int n = arr.size();
        int ele = -1;
        for(auto p : mp){
            if(p.second > n/2)
                ele = p.first;
        }
        return ele;
}
