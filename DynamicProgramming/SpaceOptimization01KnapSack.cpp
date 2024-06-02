
void Solve(){

    // 0 , 1 knapsack problem..
    int n, W;
    cin >> n >> W;

    vector<int>wt(n), p(n);

    fr(i, 0, n) cin >> wt[i];
    fr(i, 0, n) cin >> p[i];

    // dp[i][w] -- max profit from i to n - 1 with weight w;

    // dp[i][w] = max(dp[i + 1][w], p[i] + dp[i][w - wt[i]]);



    // space optimized..


    vector<int>dp(W + 1, 0), old_dp(W + 1, 0);

    for(int i = 0; i <= W; i++){
        old_dp[i] = (i / wt[n - 1]) * p[n - 1];
    }

    for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j <= W; j++){
            if(j >= wt[i]){
                dp[j] = max(old_dp[j], p[i] + dp[j - wt[i]]);
            }else{
                dp[j] = old_dp[j];
            }
        }

        old_dp = dp;
    }

    cout << dp[W] << lb;


    // space unoptimized.

    // int dp[n][W + 1];
    // for(int w = 0; w <= W; w++){
    //     dp[n - 1][w] = (w / wt[n - 1]) * p[n - 1];
    // }

    // for(int i = n - 2; i >= 0; i--){
    //     for(int j = 0; j <= W; j++){
    //         if(j >= wt[i]){
    //             dp[i][j] = max(dp[i + 1][j], p[i] + dp[i][j - wt[i]]);
    //         }else{
    //             dp[i][j] = dp[i + 1][j];
    //         }
    //     }
    // }

    // cout << dp[0][W] << lb;
}
