class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        int j = 1;
        for(int i = 0; i < encoded.size(); i++){
            int k = ans[j-1] ^ encoded[i];
            ans.push_back(k);
            j++;
        }
        return ans;
    }
};