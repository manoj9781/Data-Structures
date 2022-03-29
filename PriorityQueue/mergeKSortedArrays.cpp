#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&nums, int k)
{
    // Write your code here. 
//     priority_queue<int, vector<int>, greater<int>> pq;
//     for(int i =0 ; i < k; i++){
//         for(int j = 0; j < nums[i].size(); j++){
//             pq.push(nums[i][j]);
//         }
//     }
//     vector<int> ans;
//     for(int i = 0; i < pq.size(); i++){
//         while(pq.size() != 0){
//             ans.push_back(pq.top());
//             pq.pop();
//         }
//     }
//    return ans;
    vector<int> ans;
    for(int i = 0; i < nums.size(); i++){
        for(int j = 0; j < nums[i].size(); j++){
            ans.push_back(nums[i][j]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
