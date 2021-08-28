class Solution {
public:
    string longestPalindrome(string s) {
        
        
        if(s.size() < 2){
            return s;
        }
        
        int low;
        int high;
        int start= 0;
        int end = 1;
        for(int i = 1; i < s.length(); i++){
            low = i-1;
            high =i;
            while(low >= 0 && high < s.length() && s[low] == s[high]){
                if(high-low+1 > end){
                    start =low;
                    end=high- low+1;
                }
                low--;
                high++;
            }
            
            low = i-1;
            high = i+1;
            while(low >= 0 && high < s.length() && s[low] == s[high]){
                if(high-low+1 > end){
                    start =low;
                    end=high- low+1;
                }
                low--;
                high++;
            }
        }
        return s.substr(start, end);
    } 
    
//         if(s.size()== 0 || s.size() == 1){
//             return s;
//         }
        
//         int start = 0;
//         int end = 0;
//         int size = s.size();
        
//         int input[size][size]; 
//         for(int i =0; i < size; i++){
//             for(int j = 0; j <size; j++){
//                 input[i][j] = 0;
//             }
//         }
        
//         for(int i = 0;i< size; i++){
//             input[i][i] = 1;
//             start = i;
//             end = i;
//         }
        
//         for(int i = 0; i< size; i++){
//             if(s[i] == s[i+1]){
//                 input[i][i+1] = 1;
//                 start = i;
//                 end = i+1;
//             }
//         }
       
//         for(int i = 0;i< size; i++){
//             for(int j = i+2; j< size; j++){
//                 if(s[i] == s[j] && input[i+1][j-1] == 1){
//                     input[i][j]= 1;
//                     start = i;
//                     end = j;
                      
//                 }
//             }
//         }
        
//         return s.substr(start, start+end -1);
    
};