#define maxn  100
int seg[4*maxn];

void biuldSeg(int node, int l , int r, vector<int>&arr){
    if(l == r){
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    biuldSeg(2 * node, l, mid, arr);
    biuldSeg(2 * node + 1, mid + 1, r, arr);
    seg[node] =  seg[2 * node] + seg[2 * node + 1];
}

void update(int node, int l, int r, int pos, int val, vector<int>&arr){
    if(l == r){
        arr[pos] = val;
        seg[node] = arr[pos];
        return;
    }

    int mid = (l + r) / 2;
    if(pos > mid){
        update(2 * node + 1, mid + 1, r, pos, val, arr);
    }else{
        update(2 * node, l, mid, pos, val, arr);
    }
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

int query(int node, int qs, int qe, int l, int r, vector<int>&arr){
    if(qe < l || qs > r) return 0;
    if(qs <= l && qe >= r) return seg[node];

    int mid = (l + r) / 2;

    return query(2 * node, qs, qe, l, mid, arr) + query(2 * node + 1, qs, qe, mid + 1, r, arr);
}

void Solve(){
    int n;
    cin >> n;

    vi arr(n);
    fr(i, 0, n) cin >> arr[i];

    int l = 0, r = n - 1;
    biuldSeg(1, l, r, arr);
  //maxn is maximum size of arr.
  //node is in 1 based indexing.
}

