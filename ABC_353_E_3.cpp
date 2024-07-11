//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep1(i,n) for (ll i = 1; i <= (n); ++i)
#define repr(i,n) for (ll i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (ll i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目

#define vec(T) vector<T>
#define vvec(T) vector<vec(T)>
#define vvvec(T) vector<vvec(T)>
#define vvvvec(T) vector<vvvec(T)>

//typedef vector<mint>vi;
//typedef vector<vi>vvi;
//typedef vector<vvi>vvvi;
//typedef vector<vvvi>vvvvi;

#define all(x) x.begin(),x.end()
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct TrieTree{
    vector<map<char,ll>> g;
    vector<ll> cnt;

    TrieTree(): g(1),cnt(1){}

    ll add(const string& s){
        ll now = 0;
        for(char c:s){
            if(!g[now].count(c)){
                g[now][c] = g.size();
                g.push_back({});
                cnt.push_back(0);
            }
            now = g[now][c];
        }
        cnt[now]++;
        return now;
    }

    vector<ll> A,B; // 先祖の数、子孫の数
    ll dfs(ll now, ll num){
        num += cnt[now];
        A[now] = num;
        
        B[now] += cnt[now];
        for(auto mi:g[now]){
            B[now] += dfs(mi.second, num);
        }

        return B[now];
    }

    // addした後にこれで初期化
    void calc_AB(){
        A = vector<ll>(g.size());
        B = vector<ll>(g.size());
        dfs(0, 0);
    }

};


void solve(){
    ll N;
    cin >> N;

    TrieTree trie;

    rep(_,N){
        string s;
        cin>> s;
        trie.add(s);
    }

    trie.calc_AB();

    ll ans = 0;
    bool isfirst = true;
    for(ll bi:trie.B){
        // cerr << bi << endl;
        if(isfirst){
            isfirst = false;
            continue;
        }
        ans += bi*(bi-1)/2;
    }

    cout << ans << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
