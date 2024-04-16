void Solve(){
    int n, W;

    cin >> n >> W;

    vi wt(n), p(n);
    fr(i, 0, n) cin >> wt[i];
    fr(i, 0, n) cin >> p[i];


    int dp[n + 1][W + 1];

    //state dp(i, w) = maximum profit from i to n with weight w;
    // dp[i][w] = max(p[i] + dp[i][w - wt[i - 1]], dp[i + 1][w]);

    for(int i = 0; i <= W; i++){
        dp[n][i] = (i / wt[n - 1]) * p[n - 1];
    }

    for(int i = n - 1; i >= 1; i--){
        for(int j = 0; j <= W; j++){
            if(j >= wt[i - 1]){
                dp[i][j] = max(p[i - 1] + dp[i][j - wt[i - 1]], dp[i + 1][j]);
            }else{
                dp[i][j] = dp[i + 1][j];
            }
        }
    }

    cout << dp[1][W] << lb;  
}
