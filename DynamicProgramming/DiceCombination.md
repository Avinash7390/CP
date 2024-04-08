

    void Solve(){
    
        ll n;
        cin >> n;
    
        ll dp[n + 1 + 6];
        dp[1] = 1;
        dp[2] = 2;
    
        // dp(i) = no of ways to get sum i
        // dp(i) = sum of(dp(i - j)) {1 <= j <= 6  && i - j > 0}; -- it means if you want sum i and you get a 
        //dice no j when you toss the dice and you have 6 possibilities of dice
    
        for(int i = 3; i <= 6; i++){
            ll sum = 0;
            for(int j = 1; j < i; j++){
                sum += (dp[i - j]) % m;
            }
            dp[i] = sum + 1;
        }
    
        for(int i = 7; i <= n; i++){
            ll sum = 0;
            for(int j = 1; j <= 6; j++){
                sum = (sum + dp[i - j]) % m;
            }
            dp[i] = sum;
        }
    
        cout << dp[n] << lb;
    }
