class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX;
        int minIndex = 0;
        for(int i = 0; i < prices.size(); i++){
            if(minimum > prices[i]){
                minimum = prices[i];
                minIndex = i;
            }
        }
        cout << minimum << " " << minIndex << endl;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++){
            int profit = prices[i] - minimum;
            if( minIndex < i && profit > maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};