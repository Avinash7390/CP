Time - Complexity : O(logN)

void dfs(int node, int par, vector<vector<int>>&edges, vector<vector<int>>&parent){

    parent[0][node] = par;

    for(auto child : edges[node]){
        if(child != par) dfs(child, node, edges, parent);
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

void Solve(){

    //Kth parent of a node..

    int n;
    cin >> n;

    vector<vector<int>>edges(n, vector<int>());

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

    int node, k;
    cin >> node >> k;
    node--;

    int ans = KthParent(node, k, parent, maxPower);

    cout << ans + 1 << lb; 
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
