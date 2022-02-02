void subsetSum(int index, int sum, vector<int> &ans, vector<int> input, int n){
    if(index == n){
        ans.push_back(sum);
        return;
    }
    subsetSum(index + 1, sum + input[index], ans, input, n);
    subsetSum(index + 1, sum , ans, input, n);
}

vector<int> subSetSum2(vector<int> input, int n){
    vector<int> ans;
    subsetSum(0, 0, ans, input, n);
    return ans;
}
