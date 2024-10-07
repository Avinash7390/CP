int getLIS(vector<int>&arr){
    int sz = arr.size();
    vector<int>lis;
    
    for(int i = 0; i < arr.size(); i++){
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

    int l1 = 0, l2 = 0;
    
    vector<int>nums1, nums2;
    for(int i = 0; i < n; i++){
        if(arr[i] < arr[pos] && i < pos) nums1.push_back(arr[i]);
        if(arr[i] > arr[pos] && i > pos) nums2.push_back(arr[i]);
    }

    l1 = getLIS(nums1);
    l2 = getLIS(nums2);

    int finalLis = getLIS(arr);
    cout << "L1: "<<l1 << ", L2: " << l2 << lb;

    cout << "LIS containing element " << arr[pos] << " is : " << l1 + l2 + 1 << lb;

    if(finalLis == l1 + l2 + 1){
        cout << "Yes element is present in LIS" << lb;
    }else{
        cout << "element is not present in LIS" << lb;
    }   
}
