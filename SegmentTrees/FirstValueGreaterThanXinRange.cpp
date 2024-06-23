// given a range you have to query the first value which is greater than X in that range
//time complexity : O(q * logn * logn) = O(q * (logn)^2)

vector<int>seg;
vector<int>arr;
int merge(int leftVal, int rightVal){
    return max(leftVal, rightVal);
}

void biuldSeg(int node, int l , int r){
    if(l == r){
        seg[node] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    biuldSeg(2 * node, l, mid);
    biuldSeg(2 * node + 1, mid + 1, r);
    seg[node] = merge(seg[2 * node], seg[2 * node + 1]); // merging
}

void update(int node, int l, int r, int pos, int val){
    if(l == r){
        arr[pos] = val;
        seg[node] = arr[pos];
        return;
    }

    int mid = (l + r) / 2;
    if(pos > mid){
        update(2 * node + 1, mid + 1, r, pos, val);
    }else{
        update(2 * node, l, mid, pos, val);
    }
    seg[node] = merge(seg[2 * node], seg[2 * node + 1]);
}

int query(int node, int qs, int qe, int l, int r){
    if(qe < l || qs > r) return -1e9;
    if(qs <= l && qe >= r) return seg[node];

    int mid = (l + r) / 2;

    return merge(query(2 * node, qs, qe, l, mid), query(2 * node + 1, qs, qe, mid + 1, r));
}

void Solve(){
    int n;
    cin >> n;
    arr.resize(n);
    seg.resize(4 * n);

    fr(i, 0, n) cin >> arr[i];

    int l = 0, r = n - 1;
    biuldSeg(1, l, r);

    int q;
    cin >> q;

    while(q--){
        int ans = -1;
        int qs, qe, x;
        cin >> qs >> qe >> x;

        int s = qs, e = qe;

        while(s <= e){
            int mid = (s + e) / 2;
            int maxi = query(1, s, mid, l, r);

            if(maxi > x){
                ans = maxi;
                if(s == e) break;
                e = mid;
            }else{
                s = mid + 1;
            }
        }

        cout << ans << lb;
    }
        
}

