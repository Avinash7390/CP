/*------------------------------------- Avinash MNNIT Allahabad, Prayagraj----------------------------------------*/
#include <bits/stdc++.h>
#include <iostream>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
/*-----------------------------------------------------------------------------------------------------------------*/

using namespace __gnu_pbds;
using namespace std;
using namespace chrono;

/*------------------------------------------------------------------------------------------------------------------*/

using ll = long long;
using ull = unsigned long long;
using lld = long double;
ll mod = 1e9 + 7;

/*-------------------------------------------------------------------------------------------------------------------*/

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#define pi pair<int, int>
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, pair<int, int>>
#define PI 3.141592653589793238462
#define lb "\n"

/*---------------------------------------------------------------------------------------------------------------------*/

#define set_bits(x) __builtin_popcountll(x)
#define fr(i, a, b) for (int i = (a); i < (b); i++)
#define frr(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define size(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define pb(x) push_back(x)
#define SUM(x) accumulate(all(x), 0LL)

/*---------------------------------------------------------------------------------------------------------------------------*/
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/

ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}

/*-----------------------------------------------------------------------------------------------------------------------------*/
void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
}
/*-------------------------------------------------------------------------------------------------------------------------------*/
struct Interactor{

    int hiddenNO;
    Interactor(){
        hiddenNO = 19;
    }

    string query(int num){
        if(hiddenNO %  num == 0) return "yes";
        return "no";
    }
};

void solve(){
    vi arr = {2, 3, 4, 5, 9, 7, 11, 13, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49};

    // 4, 9, 25, 49 are for the perfect square hidden number.
    // Interactor it = Interactor();
    int ct = 0;
    bool fl = true;
    fr(i, 0, size(arr)){
        cout<<arr[i]<<endl;
        // string ans = it.query(arr[i]);
        string ans;
        // cout<<ans<<endl;
        cin>>ans;
        if(ans == "yes"){
            ct++;
        }

        if(ct >= 2){
            cout<<"composite"<<endl;
            fl = false;
            break;
        }
        if(i == 18){
            if(ct == 1)
               cout<<"prime"<<endl;
            break;
        }
    }

    if(ct == 0){
        cout<<"prime"<<endl;
    }
    
}
/***********************************************************************************************************************************/

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

/************************************************************************************************************************************/

