 vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans(numRows);
        for(int i = 0; i < numRows; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                // last and first column of triangle is "1"
                if(j == 0 || j == i)
                    ans[i].push_back(1); 
                
                /*
                here, we are using previous stored results in the 
                vector, to fill next row. 
                In the row 4, we can fill column 1, as 
                {upper row's column 0 + column 1} and column 2, as
                {upper row's column 1 + column 2} and so on....
                Now, you can easily find the patttern.
                */
                else
                    ans[i].push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
        }
        return ans;
    }
    