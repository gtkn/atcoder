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
#define watch(x) cout << (#x) << " is " << (x) << endl
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

struct Solver{

    ll N,M;
    vvec(ll) g;
    vec(bool) used;
    vec(ll) v;
    vec(ll) ans;

    vec(ll) cnt;

    void f(ll now){
        used[now]=true;
        ans.push_back(now);
        cnt[now]++;
        for(ll to:g[now]){
            if(used[to]) continue;
            f(to);
            ans.push_back(now);
            cnt[now]++;
            if(cnt[to]%2!=v[to]){
                ans.push_back(to);
                ans.push_back(now);
                cnt[to]++; cnt[now]++;
            }
        }
        return;
    }


    void solve(){
        cin >> N >> M;
        g.resize(N);
        cnt.resize(N);
        used.resize(N);

        rep(_,M){
            ll u,v;
            cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        string S;
        cin >> S;
        for(char ci:S) v.push_back(ci-'0');

        f(0);
        if(cnt[0]%2!=v[0]) ans.pop_back();

        if(false){
            vec(ll) aa(N);
            for(ll ai:ans) aa[ai]++;
            rep(i,N) cout << aa[i]%2;
            cout << endl;
        }

        cout << ans.size() << endl;
        for(ll ai:ans) cout << ai+1 << " ";
        cout << endl;
        

    }
};


int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
