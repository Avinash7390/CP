vector<pair<int, int>>seg;
vector<int>arr;
pair<int, int> merge(pair<int, int>& leftVal, pair<int, int>& rightVal){
    if(leftVal.first < rightVal.first){
        return {leftVal.first, min(leftVal.second, rightVal.first)};
    }else{
        return {rightVal.first, min(rightVal.second, leftVal.first)};
    }
}

void biuldSeg(int node, int l , int r){
    if(l == r){
        seg[node] = {arr[l], 1e9};
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
        seg[node] = {arr[pos], 1e9};
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

pair<int, int> query(int node, int qs, int qe, int l, int r){
    if(qe < l || qs > r) return {1e9, 1e9};
    if(qs <= l && qe >= r) return seg[node];

    int mid = (l + r) / 2;
    pair<int, int>lval = query(2 * node, qs, qe, l, mid);
    pair<int, int>rval = query(2 * node + 1, qs, qe, mid + 1, r);

    return merge(lval, rval);
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
        int type;
        cin >> type;

        if(type == 1){
            int qs, qe;
            cin >> qs >> qe;
            qs--, qe--;
            pair<int, int> ans = query(1, qs, qe, l, r);
            cout <<"second minimum of Range : "<< ans.second << lb;
        }else{
            int pos, val;
            cin >> pos >> val;
            pos--;
            update(1, l, r, pos, val);
            cout << "Updated Array : ";
            for(auto x : arr){
                cout << x << " ";
            } cout << lb;
        }

    }

    
}
