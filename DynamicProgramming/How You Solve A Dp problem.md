## How to solve or Approch a DP problem..

> [!NOTE]
> 1. State : Try to define the state of dp. When you say dp[i][j] , what do you mean by that exactly.
> 2. Transition : What is the relation between your subproblems
> 3. Base Case: What is Trivial case , or where your your transition fn fails and you cant handle it using if-else statements.
> 4. Final - Subproblem: You should know what you are calculating. or What is Your biggest Subproblem.
> 5. Below is the example of above 4 steps using min path sum of a grid.

    void solve(){  
        vector<vector<int>> grid(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        
        vector<vector<int>> dp(n, vector<int>(m));
        
        // state
        // dp[i][j] = min sum path from (i, j) to (n - 1, m - 1)
        
        // transition
        // dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j]
        
        // base case
        // dp[n - 1][m - 1] = grid[n - 1][m - 1]
        dp[n - 1][m - 1] = grid[n - 1][m - 1];
        
        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(i == n - 1 && j == m - 1){
                    continue;
                }
                if(i == n - 1){ // last row
                    dp[i][j] = dp[i][j + 1] + grid[i][j];
                } else if(j == m - 1){ // last column
                    dp[i][j] = dp[i + 1][j] + grid[i][j];
                }else { // normal case
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
                }
            }
        }
        // final subproblem
        // dp[0][0] (min sum path from (0, 0) to (n - 1, m - 1))
        cout << dp[0][0] << endl;
    }
