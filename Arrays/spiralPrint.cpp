class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> ans;
        int total = row * col;
        int count = 0;
        
        int startRow = 0;
        int endColumn = col-1;
        int endRow = row-1;
        int startColumn = 0;
        while(count < total){
            for(int index = startRow; count < total && index <= endColumn; index++){
                ans.push_back(matrix[startRow][index]);
                count++;
            }
            startRow++;
           //print ending column
            for(int index = startRow; count < total && index<=endRow; index++) {
                ans.push_back(matrix[index][endColumn]);
                count++;
            }
            endColumn--;
            
            //print ending row
            for(int index = endColumn; count < total && index>=startColumn; index--) {
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;
            
            //print starting column
            for(int index = endRow; count < total && index>=startRow; index--) {
                ans.push_back(matrix[index][startColumn]);
                count++;
            }
            startColumn++;
        } 
        return ans;
        }
    
};