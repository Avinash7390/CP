void Solve(){
    int n;
    cin >> n;

    vector<int>arr(n);
    for(auto &x : arr) cin >> x;

    /*
    1. Find Length of LIS
    2. Print any valid LIS
    */

    vector<int>lis;
    
    vector<int>insertedAtLen(n);
    
    for(int i = 0; i < n; i++){
        if(lis.empty() || lis.back() < arr[i]){
            lis.push_back(arr[i]);
            insertedAtLen[i] = lis.size();
        }else{
            auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
            int idx = it - lis.begin();
            lis[idx] = arr[i];
            insertedAtLen[i] = idx + 1;
        }
    }

    int lis_len = lis.size();

    cout << "Len of LIS: " << lis_len << lb;

    vector<int>lis_arr;
    int currLen = lis_len;
    
    for(int i = n - 1; i >= 0; i--){
        if(insertedAtLen[i] == currLen){
            lis_arr.push_back(arr[i]);
            currLen--;
        }
    }
    reverse(lis_arr.begin(), lis_arr.end());

    cout << "Printing LIS: " << lb;
    for(int i = 0; i < lis_arr.size(); i++){
        cout << lis_arr[i] << " ";
    } cout << lb;   
}
