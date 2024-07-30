void countAndMerge(vector<int>&arr, int l, int r, int &counInversions){
    int mid = (l + r) / 2;

    vector<int>newArr;
    int i = l, j = mid + 1;


    int i2 = i, j2 = j;

    while(i2 <= mid && j2 <= r){
        if(arr[j2] <= arr[i2]){
            counInversions = counInversions +  (mid - i2 + 1);
            j2++;
        }else{
            i2++;
        }
    }

    while(i <= mid && j <= r){
        if(arr[i] < arr[j]){
            newArr.push_back(arr[i]);
            i++;
        }else{
            newArr.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        newArr.push_back(arr[i]);
        i++;
    }

    while(j <= r){
        newArr.push_back(arr[j]);
        j++;
    }

    for(int x = l; x <= r; x++){
        arr[x] = newArr[x - l];
    }
}

int check = 0;

void help(vector<int>&arr, int l, int r, int &counInversions){
    if(l == r) return;
    
    int mid = (l + r) / 2;

    help(arr, l, mid, counInversions);
    help(arr, mid + 1, r, counInversions);

    countAndMerge(arr, l, r, counInversions);
    
}


void Solve(){

    int n;

    cin >> n;
    vector<int>arr(n);
    fr(i, 0, n) cin >> arr[i];

    int counInversions = 0;

    help(arr, 0, n - 1, counInversions);



    cout << counInversions << lb;
}
