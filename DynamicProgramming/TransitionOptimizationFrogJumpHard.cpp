void Solve(){

    int n, k;
    cin >> n >> k;

    // frog jump.... frog can jump from i to i + 1, i + 2, i + 3, ........, i + k
    // calculate no of ways to reach to point N.

    // normal without state optimization..

    //dp(i) -- No of ways to reach to point i.

    // state -- dp[i] = dp[i - 1] + dp[i - 2] + ....... + dp[i - k]  (i - k >= 0)

    int dp[n + 1];

    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= k; j++){
            if(i - j >= 1)
              sum += dp[i - j];
        }

        dp[i] = sum;
    } 

    cout << dp[n] << lb;

    // with transition optimization...

    // dp[i] = SUM(dp[i - j]) (1 <= j <= k,  && i - j >= 1)

    // we can store the sum of window k...

    int DP[n + 1];
    DP[1] = 1;
    int preSum[n + 1];
    preSum[1] = 1; 


    for(int i = 2; i <= n; i++){
        int x = 0;
        if(i - k - 1 >= 1){
            x = preSum[i - k - 1];
        }

        DP[i] = preSum[i - 1] - x;
        preSum[i] = preSum[i - 1] + DP[i];
    }

    cout << DP[n] << lb;
}

