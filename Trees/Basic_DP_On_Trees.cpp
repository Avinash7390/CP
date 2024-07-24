
void countNodesInEachSubtree(int node, int parent, vector<vector<int>>&edges, vector<int>&sub_count){
    sub_count[node] = 1;

    for(auto child : edges[node]){
        if(child != parent){
            countNodesInEachSubtree(child, parent, edges, sub_count);
            sub_count[node] += sub_count[child];
        }
    }
}

void findGCDofEachSubtree(int node, int parent, vector<vector<int>>&edges, vector<int>&sub_gcd){
    sub_gcd[node] = node;

    for(auto child : edges[node]){
        if(child != parent){
            findGCDofEachSubtree(child, parent, edges, sub_count);
            sub_gcd[node] = gcd(sub_gcd[node], sub_gcd[child]);
        }
    }
}

void sumOfDistanceFromAllNodesInEachSubTree(int node, int parent, 
    vector<vector<int>>&edges, vector<int>&sub_count, vector<int>&sum){

    //sum[u] = SUM(sum[v] + sizeofSubtree(v)) {v : children(u)};

    sum[node] = 0;
    sub_count[node] = 1;

    for(auto child : edges[node]){
        if(child != parent){
            dfs(child, node, edges, sub_count, sum);

            sum[node] += sum[child] + sub_count[child];
            sub_count[node] += sub_count[child];
        }
    }
}



void Solve(){

    int n;
    cin >> n;

    vector<vector<int>>edges(n, vector<int>());
    vector<int>sub_count(n, 0);

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[v].push_back(u);
        edges[u].push_back(v);
    } 
}
