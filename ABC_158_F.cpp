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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

ll op(ll a,ll b){return max(a,b);}
ll ee(){return -llINF;}

struct Solver{
    vvec(ll) g;

    mint dfs(ll now, ll frm){
        mint res = 1;
        for(ll to:g[now]) if(to!=frm) res *= dfs(to,now);        
        return res+1;
    }


    void solve(){
        ll N;
        cin >> N;

        g.resize(2*N+1);

        vec(ll) X(N),D(N);
        rep(i,N) cin >> X[i] >> D[i];

        vec(Pll) v;
        v.emplace_back(-llINF, llINF);
        rep(i,N) v.emplace_back(X[i],X[i]+D[i]);
        sort(all(v));


        set<ll> s;
        for(Pll vi:v){
            s.insert(vi.first);
            s.insert(vi.second);
        }

        map<ll,ll> m;
        ll cnt = 0;
        for(ll si:s) m[si]=cnt++;

        rep(i,N+1){
            v[i].first = m[v[i].first];
            v[i].second= m[v[i].second];
        }

        segtree<ll,op,ee> seg(cnt+10);
        rep(i,N+1){
            ll x = seg.prod(v[i].first+1, cnt+10);
            //cout << i <<"m"<< x << endl;
            if(x>-llINF) g[x].push_back(v[i].first);
            seg.set(v[i].second, v[i].first);
        }

        mint ans = dfs(0,0)-1;

        cout << ans.val() << endl;


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
