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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

void solve(){
    ll N,M;
    cin >> N >> M;
    vec(string) S(N);
    rep(i,N) cin >> S[i];

    vvvec(ll) vvv(N,vvec(ll)(10));
    rep(i,N){
        rep(j,M) vvv[i][S[i][j]-'0'].push_back(j);
    }
    rep(i,N)rep(d,10){
        ll nn = vvv[i][d].size();
        rep1(x,N){
            rep(j,nn){
                vvv[i][d].push_back( vvv[i][d][j] + M*x ); 
            }
            if(vvv[i][d].size()>N) break;
        }
    }


    auto f = [&](ll d,ll th)->bool{
        vvec(ll) g(N);
        rep(i,N){
            for(ll t:vvv[i][d]){
                if(t>th) break;
                if(g[i].size()>N) break;
                g[i].push_back(t);
            }
        }

        set<ll> s;
        rep(i,N) for(ll to:g[i]) s.insert(to);
        map<ll,ll> m;
        ll cnt = 0;
        for(ll si:s) m[si]=cnt++;

        mf_graph<ll> mfg(N+cnt+2);
        ll st = N+cnt, gl = N+cnt+1;

        rep(i,N) mfg.add_edge(st,i,1);
        rep(i,N) for(ll to:g[i]) mfg.add_edge(i, N+m[to], 1);
        rep(i,cnt) mfg.add_edge(N+i,gl,1);

        return (mfg.flow(st,gl) == N);
    };


    ll ans = llINF;
    rep(d,10){
        ll l = N-2, r = N*M+1;
        while(r-l>1){
            ll mid = (l+r)/2;
            if(f(d,mid)) r=mid;
            else l=mid;
        }
        chmin(ans,r);
    }

    if(ans>N*M) ans = -1;
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
