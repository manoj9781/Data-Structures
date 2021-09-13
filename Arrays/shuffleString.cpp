class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.size();
        int array[n];
        string str;
        for(int i=0;i<n;i++)
        {
           array[indices[i]]=s[i]; 
            
        }
        for(int i=0;i<n;i++)
        {
           str.push_back(array[i]);
        }
        return str;
    }
};