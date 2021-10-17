49. Group Anagrams
Medium

7102

257

Add to List

Share
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            map[strs[i]].push_back(temp);
        }
        
        for(auto it = map.begin(); it != map.end(); it++){
            ans.push_back(it -> second);
        }
        return ans;
    }
};