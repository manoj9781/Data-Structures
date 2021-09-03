class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int>map;
         for(int i = 0; i < stones.size(); i++){
            map[stones[i]]++;
       }
        int count = 0;
        for(int i = 0; i < jewels.size(); i++){
            char key = jewels[i];
            if(map.find(key) != map.end()){
                count += map[key];
            }
           
        }
        return count;
    }
};