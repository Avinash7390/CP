#include<bits/stdc++.h>
#include<iostream>

using namespace std;

//vector<vector<vector<int>>>dp(N+1, vector<vector<int>>(X+2, vector<int>(2, -1)));
int DigitDp(string &num, int N, int X, bool tight, vector<vector<vector<int>>>&dp){
    //finding out the total numbers whose digit sum is in the range of [0, X];
    // numbers could be in the range of [0, R];

    if(X < 0) return 0;
    // when we have only one digit the then the base case comes in picture..
    if(N == 1){
        if(tight && X >=0 && X <= (num[num.size() - N] - '0')) return 1;
        if(!tight && X >=0 && X <= 9) return 1; 
        return 0;
    }
    if(dp[N][X][tight] != -1) return dp[N][X][tight];

    int ans = 0;
    int ub = 0;
    if(tight){
        ub = num[num.size() - N] -'0';
    }else{
        ub = 9;
    }
    //for a perticular digit in num trying out all the digits that can come at that
    //place..
    // if some digit dig come at one place the the bound reduces
    // to X - dig. for further digits.
    for(int dig = 0; dig <= ub; dig++){
        ans = ans + DigitDp(num, N-1, X-dig, (tight)&&(dig == ub), dp);
    }

    return dp[N][X][tight] = ans;
}

int main(){
    string L = "";
    string R = "1533445";
    int N = R.size();
    int X = 18;
    vector<vector<vector<int>>>dp(100, vector<vector<int>>(X+2, vector<int>(2, -1)));

    int ans = DigitDp(R, N, X, 1, dp);
    cout<<ans<<endl;

    return 0;
}
