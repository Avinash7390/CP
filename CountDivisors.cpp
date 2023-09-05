
//for a single number..
int countDivisers(int n){
    int ct = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i == 0){
            ct++;

            if(i * i != n) ct++;
        }
    }
    return ct;
}

//count divisers for numbers in range [left to right]

void countDivisers(int l, int r){
    vector<int>arr(r + 1, 0);
    //Time C -- O(nlogn)
    for(int i = 1; i<=r; i++){
        for(int j = i; j<=r; j+=i){
            arr[j]++;
        }
    }

    for(int i = l; i<=r; i++){
        cout<<arr[i]<<" ";
    }
}

