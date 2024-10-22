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


ll op(ll a, ll b){
    return min(a,b);
}
ll ee(){
    return llINF;
}


void solve(){
    ll N,K;
    cin >> N >> K;
    vec(ll) p(N);
    rep(i,N) cin >> p[i];
    rep(i,N) p[i]--;


    auto f = [](vec(ll) v, vec(ll) cost, ll k)->vec(ll){
        ll n = v.size();
        vec(ll) pos(200020,-1);
        rep(i,n) pos[v[i]] = i;

        segtree<ll, op, ee> seg(v);
        vec(ll) cum(n+1);
        rep(i,n) cum[i+1] = cum[i] + cost[i];

        // cerr << "--- " << n << " ," << k << endl;
        // rep(i,n) cerr << v[i] << " "; cerr << endl;
        // rep(i,n) cerr << cost[i] << " "; cerr << endl;

        vec(ll) res = {v[0]};
        ll now = 1;
        while(now<n){
            ll l=now, r=n;
            while(r-l>1){
                ll m = (l+r)/2;
                if(cum[m]-cum[now] <= k) l = m;
                else r = m;
            }
            ll x = seg.prod(now, r);
            // cerr << "now : " << now << ", r : " << r << ", x : " << x << "," << pos[x] << endl;
            res.push_back(x);
            // k -= pos[x] - now;
            k -= (cum[pos[x]] - cum[now]);
            now = pos[x]+1;
            if(k==0) break;
        }
        while(now<n){
            res.push_back(v[now]);
            now++;
        }
        while(k>0){
            res.pop_back();
            k--;
        }

        return res;
    };

    // auto compare_lexicographically = [](const vec(ll) &a, const vec(ll) &b) -> bool {
    //     return lexicographical_compare(all(a), all(b));
    // };



    vec(ll) ans = f(p, vec(ll)(N,1), K);

    vec(ll) d(N,-1);
    rep(i,N) d[p[i]] = i;
    rep(st,N){
        if(d[st]>K) continue;
        vec(ll) v;
        for(ll i = d[st]; i<N; i++) v.push_back(p[i]);
        vec(ll) cost(v.size(), 1);
        auto tmp = f(v, cost, K-d[st]);
        
        // cerr << "d : " << st << ", " << d[st] << endl; 
        // for(ll x:v) cerr << x << " "; cerr << endl;
        // for(ll x:tmp) cerr << x << " "; cerr << endl;

        if( lexicographical_compare(all(tmp), all(ans)) ) swap(tmp,ans);
        break;

    }


    vec(ll) c(N,-1);
    rep(i,N) c[p[i]] = N-i;
    rep(st,N){
        if(c[st]>K) continue;
        vec(ll) v, cost;
        rep(i,N){
            if(N-c[st]+i < N){
                v.push_back(p[ N-c[st]+i ]);
                cost.push_back(0);
            }else{
                v.push_back(p[ -c[st]+i ]);
                cost.push_back(1);
            }
        }
        auto tmp = f(v,cost,K-c[st]);

        // cerr << "c : " << st << ", " << c[st] << endl; 
        // for(ll x:v) cerr << x << " "; cerr << endl;
        // for(ll x:cost) cerr << x << " "; cerr << endl;
        // for(ll x:tmp) cerr << x << " "; cerr << endl;

        if( lexicographical_compare(all(tmp), all(ans)) ) swap(tmp,ans);
        break;
    }

    for(ll x:ans) cout << x+1 << ' '; cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
