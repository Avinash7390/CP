void dfs(int node, int par, vector<vector<int>>&edges, vector<int>&dp, vector<int>&sub){

    dp[node] = 0;
    sub[node] = 1;

    for(auto child : edges[node]){
        if(child != par){
            dfs(child, node, edges, dp, sub);
            dp[node] += dp[child] + sub[child];
            sub[node] += sub[child]; 
        }
    }
}

void changeRoot(int newRoot, int prevRoot, vector<int>&dp, vector<int>&sub){
    //remove the contibution of previous root.
    dp[prevRoot] -= (dp[newRoot] + sub[newRoot]);
    sub[prevRoot] -= sub[newRoot];

    //get the contibution of curr root.
    dp[newRoot] += dp[prevRoot] + sub[prevRoot];
    sub[newRoot] += sub[prevRoot];

}

void ReRoot(int currNode, int par, vector<vector<int>>&edges, vector<int>&dp, vector<int>&sub, vector<int>&ans){

    ans[currNode] = dp[currNode];
    for(auto child : edges[currNode]){
        if(child != par){
            changeRoot(child, currNode, dp, sub);
            dfs(child, currNode, edges, dp, sub, ans);
            changeRoot(currNode, child, dp, sub);
        }
    }
}

void Solve(){

    int n;
    cin >> n;

    vector<vector<int>>edges(n, vector<int>());
    vector<int>sub(n, 0);
    vector<int>ans(n, 0);
    vector<int>dp(n, 0);
    dfs(0, -1, edges, dp, sub);
    ReRoot(0, -1, edges, dp, sub, ans);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[v].push_back(u);
        edges[u].push_back(v);
    } 
}
