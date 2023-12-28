/*------------------------------------- Avinash MNNIT Allahabad, Prayagraj----------------------------------------*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
using namespace chrono;
using ll = long long;
using ull = unsigned long long;
using lld = long double;
#define pi pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, pair<int, int>>
#define lb "\n"
#define fr(i, a, b) for (int i = (a); i < (b); i++)
#define frr(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define pb(x) push_back(x)
#define SUM(x) accumulate(all(x), 0LL)
#define map map<int, int>
#define umap unordered_map<int, int>
ll mod = 1e9 + 7;
/*---------------------------------------------------------------------------------------------------------------------------*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
}

struct Interactor{
    int hiddenNumber;
    int QueriesTillNow;
    int Querylimit;
    bool printInteraction;

    Interactor(){
        hiddenNumber = getRandomNumber(1, 100);
        QueriesTillNow = 0;
        Querylimit = 10;
        printInteraction = false;
    }
    void checkTotalQueries(){
        if(QueriesTillNow >= Querylimit){
            cout<<"Made more query than querylimit "<<Querylimit<< " for the hiddenNumber"<<hiddenNumber<<endl;
        }
        assert(QueriesTillNow < Querylimit); 
        // it call exit(1) when condition is false;
    }

    char make_query(int x){
        checkTotalQueries();
        QueriesTillNow++;
        if(printInteraction)
           cout<<"? "<<x<<endl;
        if(x < hiddenNumber) return '<';
        else if(x > hiddenNumber) return '>';
        else return '=';
    }

    void IsvalidOutput(int x){
        if(x != hiddenNumber){
            cout<<"Failed for "<<hiddenNumber<<endl;
        }else{
            cout<<"Passed for "<<hiddenNumber<<endl;
        }
    }
};

void query(int x){
    cout<<"? "<<x<<endl;
}


void solve(){

    fr(iterations, 0, 10){

        Interactor interactor = Interactor();
        int l = 1, r = 100;

        int ans = -1;

        while(l <= r){
            int mid = (l + r) / 2;
            // query(mid); // this thing asking online judge for output.

            char codeForcesOutput;
            //cin>>codeForcesOutput;

            codeForcesOutput = interactor.make_query(mid);
            // cout<<codeForcesOutput<<endl;
            if(codeForcesOutput == '='){
                ans = mid;
                break;
            }else{
                if(codeForcesOutput == '<'){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
        }

        interactor.IsvalidOutput(ans);
    }

    //while submiting on codeforces just remove the interactor and take input from codeforces.
}

int32_t main()
{
    init_code();
    int t;
    //cin>>t;
    t = 1;

    while(t--){
        solve();
    }
}



