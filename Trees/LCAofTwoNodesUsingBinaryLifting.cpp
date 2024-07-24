Time Complexity - O(logN * logN)

void dfs(int node, int par, vector<vector<int>>&edges, vector<vector<int>>&parent){

    parent[0][node] = par;

    for(auto child : edges[node]){
        if(child != par) dfs(child, node, edges, parent);
    }
}

void dfs1(int node, int par, vector<vector<int>>&edges, vector<int>&levels, int currLevel){
    levels[node] = currLevel;

    for(auto child : edges[node]){
        if(child != par) dfs1(child, node, edges, levels, currLevel + 1);
    }

}
int KthParent(int node, int k, vector<vector<int>>&parent, int maxPower){
    int currNode = node;

    for(int i = maxPower - 1; i >= 0; i--){

        if(k & (1 << i)){
            currNode = parent[i][currNode];

            if(currNode == -1) return -1;
        }
    }

    return currNode;
}

int LCA(int a, int b, vector<int>&levels, vector<vector<int>>&parent, int maxPower){

    if(a == b) return a;

    if(levels[a] > levels[b]){
        a = KthParent(a, levels[a] - levels[b], parent, maxPower);
    }else{
        b = KthParent(b, levels[b] - levels[a], parent, maxPower);
    }

    if(a == b) return a;

    int s = 1, e = size(levels);
    int ans = -1;

    while(s <= e){
        int m = s + (e - s) / 2;

        int parA = KthParent(a, m, parent, maxPower);
        int parB = KthParent(b, m, parent, maxPower);

        if(parA == parB){
            ans = m;
            e = m - 1;
        }else{
            s = m + 1;
        }
    }

    return KthParent(a, ans, parent, maxPower);
}

void Solve(){

    //Kth parent of a node..
    // 106 ->  1    1   0  1   0   1   0
    //        64 -> 32 ->  8   ->  2

    // calculate  [2^i]th Parent of each node.

    int n;
    cin >> n;

    vector<vector<int>>edges(n, vector<int>());
    vector<int>levels(n, 0);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[v].push_back(u);
        edges[u].push_back(v);
    }

    int maxPower = log(n) + 10;

    vector<vector<int>>parent(maxPower, vector<int>(n));

    dfs(0, -1, edges, parent);
    dfs1(0, -1, edges, levels, 0);

    for(int i = 1; i < maxPower; i++){
        for(int node = 0; node < n; node++){
            int intermediate = parent[i - 1][node];

            if(intermediate != -1){
                parent[i][node] = parent[i - 1][intermediate];
            }else{
                parent[i][node] = -1;
            }
        }
    }

    int a, b;
    cin >> a >> b;
    a--;
    b--;

    int lca = LCA(a, b, levels, parent, maxPower);

    cout << lca + 1 << lb;
}

/************************************************************************************************************************************/

int32_t main()
{

    FAStIO();
    init_code();
    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }
}

/************************************************************************************************************************************/
