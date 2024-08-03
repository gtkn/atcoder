//title
#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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






void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];
    rep(i,N) A[i]--;

    vvec(ll) pos(10);
    rep(i,N) pos[A[i]].push_back(i);


    vvec(ll) delq(N+1);
    multiset<ll> st;

    rep(j,N){
        ll aj = A[j];
        for(ll d=-4; d<=4; ++d){
            ll ai = aj-d;
            ll ak = aj+d;
            if(ai<0 || ai>=10 || ak<0 || ak>=10) continue;

            auto itr1 = lower_bound(all(pos[ai]),j);
            if(itr1 == pos[ai].begin()) continue;
            ll i = *(--itr1);

            auto itr2 = upper_bound(all(pos[ak]),j);
            if(itr2 == pos[ak].end()) continue;
            ll k = *itr2;

            // cerr << i << ' ' << j << ' ' << k << "," << d << endl;
            // ans += (i+1)*(N-k);

            st.insert(k);
            delq[i+1].push_back(k);
        }
    }


    ll ans = 0;
    rep(i,N){
        for(auto k: delq[i]){
            st.erase(st.find(k));
        }
        if(st.empty()) continue;
        ll k = *st.begin();
        ans += N-k;
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
