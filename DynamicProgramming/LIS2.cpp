int getLIS(int start, int posUpto, vector<int>&arr){
    int sz = arr.size();
    vector<int>lis;
    
    for(int i = start; i <= posUpto; i++){
        if(lis.empty() || lis.back() < arr[i]){
            lis.push_back(arr[i]);
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            int idx = it - lis.begin();
            lis[idx] = arr[i];
        }
    }

    return lis.size();
}
void Solve(){
    int n, pos;
    cin >> n >> pos;

    vector<int>arr(n);
    for(auto &x : arr) cin >> x;


    /*
    1. Find LIS [given that ith element of the arr must be included]
    2. Check if ith element of the arr is part of LIS or not
    */

    int l1 = 0;
    
    vector<int>lis1;

    for(int i = 0; i <= pos; i++){
        if(lis1.empty() || lis1.back() < arr[i]){
            lis1.push_back(arr[i]);
            if(i == pos){
                l1 = lis1.size();
            }
        }else{
            auto idx = lower_bound(lis1.begin(), lis1.end(), arr[i]) - lis1.begin();
            lis1[idx] = arr[i];

            if(i == pos){
                l1 = idx + 1;
            }
        }
    }

    int l2 = 0;
    vector<int>lis2;

    for(int i = pos; i < n; i++){
        if(lis2.empty() || lis2.back() < arr[i]){
            lis2.push_back(arr[i]);
        }else{
            auto idx = lower_bound(lis2.begin(), lis2.end(), arr[i]) - lis2.begin();
            if(idx != 0) lis2[idx] = arr[i];
        }
    }
    l2 = lis2.size();

    int finalLis = getLIS(0, n - 1, arr);
    cout << "L1: "<<l1 << ", L2: " << l2 << lb;

    cout << "LIS containing element " << arr[pos] << " is : " << l1 + l2 - 1 << lb;

    if(finalLis == l1 + l2 - 1){
        cout << "Yes element is present in LIS" << lb;
    }else{
        cout << "element is not present in LIS" << lb;
    }   
}
