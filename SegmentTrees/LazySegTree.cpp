vector<int>seg;
vector<int>arr;
vector<int>lazy;

void build(int node, int l, int r){
    if(l == r){
        tree[node] = arr[l];
        return;
    }

    int m = l + (r - l) / 2;
    build(2 * node, l, m);
    build(2 * node + 1, m + 1, r);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}


void push(int l, int r, int node){
    if(lazy[node] != 0){
        if(l != r){

            seg[node] = seg[node] + lazy[node] * (r - l + 1);
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
            lazy[node] = 0;
        }
    }
}


void update(int node, int l, int r, int qs, int qe, int val){
    push(l, r, node);

    if(r < qs || l > qe) return 

    if(l >= qs && r <= qe){
        lazy[node] = val;
        push(l, r, node);
        return;
    }


    int m = l + (r - l) / 2;

    update(2 * node, l, m, qs, qe, val);
    update(2 * node + 1, m + 1, r, qs, qe, val); 
}

int query(int node, int l, int r, int qs, int qe){
    push(l, r, node);
    
    if(r < qs || l > qe) return 0;
    if(l >= qs && r <= qe) return seg[node];

    int mid = l + (r - l) / 2;

    int left = query(2 * node, l, mid, qs, qe);
    int right = query(2 * node + 1, mid + 1, r, qs, qe);

    return left + right; 

}

void Solve(){

    int n;
    cin >> n;

    seg.resize(4 * n);
    lazy.resize(4 * n);
    arr.resize(n);
}
