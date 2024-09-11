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
//using mint = modint998244353;


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

//---素因数分解------
map<ll, ll > prime_factor(ll n) {
    map<ll, ll > pf;
    for(ll f=2; f*f<=n; ++f){
        while(n%f == 0){
            pf[f]++;
            n /= f;
        }
    }
    if(n!=1) pf[n] = 1;
    return pf;
}



void solve(){
    ll N,Q;
    cin >> N >> Q;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(ll) L(Q),R(Q);
    rep(i,Q) cin >> L[i] >> R[i];
    rep(i,Q) L[i]--;

    vec(ll) v(Q);
    rep(i,Q) v[i] = i;

    ll M = 1000; // sqrt(N);

    sort(all(v),[&](ll i, ll j){
        if(L[i]/M == L[j]/M) return R[i] < R[j];
        return L[i] < L[j];
    });

    vector<map<ll,ll>> pfs(N);
    rep(i,N) pfs[i] = prime_factor(A[i]);
    

    set<ll> st;
    rep(i,N) for(auto [k,v]:pfs[i]) st.insert(k);
    map<ll,ll> mp;
    ll nn = 0;
    for(ll x:st) mp[x] = nn++;

    vvec(Pll) pfs2(N);
    rep(i,N){
        for(auto [k,v]:pfs[i]){
            pfs2[i].push_back({mp[k],v});
        }
    }


    vec(ll) now(nn);
    ll cnt = 0;
    vec(bool) ans(Q);

    // auto iscube = [&]()->bool{
    //     for(auto [k,v]:mp){
    //         if(v%3!=0) return false;
    //     }
    //     return true;
    // };

    auto mul = [&](ll ii){
        for(auto [k,v]:pfs2[ii]){
            ll a0 = now[k], a1 = now[k]+v;
            if(a0%3>0 && a1%3==0) cnt--;
            if(a0%3==0 && a1%3>0) cnt++;
            now[k] = a1;
        }
    };

    auto div = [&](ll ii){
        for(auto [k,v]:pfs2[ii]){
            ll a0 = now[k], a1 = now[k]-v;
            if(a0%3>0 && a1%3==0) cnt--;
            if(a0%3==0 && a1%3>0) cnt++;
            now[k] = a1;
        }
    };


    ll l = 0, r = 0;
    for(ll idx:v){
        while(l < L[idx]){
            div(l);
            l++;
        }

        while(l > L[idx]){
            l--;
            mul(l);
        }

        while(r < R[idx]){
            mul(r);
            r++;
        }

        while(r > R[idx]){
            r--;
            div(r);
        }

        ans[idx] = (cnt==0);
    }

    rep(i,Q) if(ans[i]) sayyn;


}




const ll MOD = (1LL<<61)-1;

void solve2(){
    ll N,Q;
    cin >> N >> Q;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    vec(ll) L(Q),R(Q);
    rep(i,Q) cin >> L[i] >> R[i];
    rep(i,Q) L[i]--;


    vector<map<ll,ll>> pfs(N);
    rep(i,N) pfs[i] = prime_factor(A[i]);
    

    set<ll> st;
    rep(i,N) for(auto [k,v]:pfs[i]) st.insert(k);
    map<ll,ll> mp;
    ll nn = 0;
    for(ll x:st) mp[x] = nn++;

    vvec(Pll) pfs2(N);
    rep(i,N){
        for(auto [k,v]:pfs[i]){
            pfs2[i].push_back({mp[k],v});
        }
    }



    vec(bool) ans(Q,true);
    rep(_,10){
        vec(ll) h(nn);
        rep(i,nn) h[i] = rand()%MOD;

        vec(ll) dp(N+1);
        vec(ll) cnt(nn);
        rep(i,N){
            dp[i+1] = dp[i];
            for(auto [k,v]:pfs2[i]){
                dp[i+1] -= h[k]*cnt[k];
                cnt[k] += v;
                cnt[k] %= 3;
                dp[i+1] += h[k]*cnt[k];
            }
        }

        rep(i,Q){
            ll res = dp[R[i]]-dp[L[i]];
            if(res!=0) ans[i] = false;
        }
    }

    rep(i,Q) if(ans[i]) sayyn;


}


int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        // solve();
        solve2();
    }
    return 0;
}
