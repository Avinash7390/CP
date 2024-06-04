

void Solve(){
    int n, k;
    cin >> n >> k;

    vector<int>arr(n);
    fr(i, 0, n) cin >> arr[i];

    vector<int>preSum(k + 1, 0);

    vector<int>dp(k + 1, 0);
    dp[0] = 1;
    for(int i = 0; i <= k; i++){
        preSum[i] = (i > 0) ? (preSum[i - 1] + dp[i]) : dp[i];
    }

    for(int i = n - 1; i >= 0; i--){
        vector<int>temp(k + 1, 0); 
        for(int j = 0; j <= k; j++){
            int rightSum = preSum[j];
            int leftSum = 0;
            if(j >= arr[i]){
                leftSum = j - arr[i] - 1 >= 0 ? preSum[j - arr[i] - 1] : 0;
            }
            dp[j] = mod_sub(rightSum, leftSum, m);
            temp[j] = (j - 1 >= 0) ?  mod_add(temp[j - 1], dp[j], m) : dp[j];
        }
        preSum = temp;
    }

    cout << dp[k] << lb;
}


//problem link : https://atcoder.jp/contests/dp/tasks/dp_m
