Given a character String you have to find the Kth String in Dictionary only considering the characters given in string.


int fact[10];

void calculateFact(){
    fact[0] = 1;

    for(int i = 1; i < 10; i++){
        fact[i] = i * fact[i - 1];
    }
}
void Solve(){
    int k;
    cin >> k;

    string s;
    cin >> s;

    map<char, int>mp;
    calculateFact();

    for(int i = 0; i < size(s); i++){
        mp[s[i]]++;
    }
    string ans = "";
    int sz = size(s);

    auto it = mp.begin();

    int mn = 0;

    while(size(mp) > 0){
        auto ele = *it;
        char ch = ele.first;
        int ct = fact[sz - 1];
        
        for(auto x : mp){
            if(x.first == ch)  ct = ct / (fact[x.second - 1]);
            else ct = ct / (fact[x.second]);
        }
        if(ct < k){
            k = k - ct;
            it++;
        }else{
            ans.push_back(ch);
            mp[ch]--;
            if(mp[ch] == 0) mp.erase(ch);
            sz--;
            it = mp.begin();
        }
    }
    
    cout << ans << lb;  
}
