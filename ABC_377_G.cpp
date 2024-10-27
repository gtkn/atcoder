//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
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
    vvec(ll) g; // 子への辺
    vector<ll> cnt; // そのノードに該当する文字列が追加された数
    ll sigma = 26; // アルファベットの数
    ll maxsize; // ノード数の最大
    ll gcnt = 1; // すでに使ったノードの数

    vector<ll> dp;

    TrieTree(ll maxsize):maxsize(maxsize){
        g = vvec(ll)(maxsize,vec(ll)(sigma));
        cnt = vec(ll)(maxsize);
        dp = vec(ll)(maxsize,llINF);
        dp[0] = 0;
    }

    ll add(const string& s){
        ll l = s.size();
        ll res = l;
        ll now = 0;

        vec(ll) path;

        for(char c:s){
            ll x = c-'a';
            if(g[now][x]==0) g[now][x] = gcnt++;
            now = g[now][x];

            path.push_back(now);
            l--;
            chmin(res, dp[now] + l);
        }
        cnt[now]++;

        assert(path.size() == s.size());
        reverse(all(path));
        rep(i,path.size()){
            ll pos = path[i];
            chmin(dp[pos], i);
        }

        return res;
    }


};





void solve(){
    ll N;
    cin >> N;

    TrieTree trie(200200);

    rep(_,N){
        string s;
        cin >> s;
        ll res = trie.add(s);
        cout << res << endl;
    }


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
