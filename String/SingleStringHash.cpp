struct Hashing1{
    int n;
    const ll p = 31;
    ll m = 1000000007;
    string s;
    vector<ll>hash;
    vector<ll>powerOfP;
    vector<ll>invPowerOfP;
    Hashing1(string queryString){
        s = queryString;
        n = size(queryString);
        hash.resize(n);
        powerOfP.resize(n);
        invPowerOfP.resize(n);
        calculatePowerOfP();
        calculateInvPowerOfP();
        buildHash();
    }

    void calculatePowerOfP(){
        powerOfP[0] = 1LL;
        for(int i = 1; i < n; i++){
            powerOfP[i] = mod_mul(powerOfP[i - 1], p, m);
        }
    }

    void calculateInvPowerOfP(){
        invPowerOfP[n - 1] = mminvprime(powerOfP[n - 1], m);
        for(int i = n - 2; i >= 0; i--){
            invPowerOfP[i] = mod_mul(p, invPowerOfP[i + 1], m);
        }
    }

    void buildHash(){
        ll currHash = 0;
        
        for(int i = 0; i < n; i++){ 
            hash[i] = mod_mul(s[i] - 'a' + 1, powerOfP[i], m);
            hash[i] = mod_add(hash[i], currHash, m);
            currHash = hash[i];
        }
    }

    ll substringHash(int l, int r){
        ll val1 = hash[r];
        ll val2 = l > 0 ? hash[l - 1] : 0LL;

        ll res = mod_sub(val1, val2, m);

        res = mod_mul(res, invPowerOfP[l], m);
        return res;
    }
};
