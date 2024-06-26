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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;

    vec(string) S(N);
    rep(i,N) cin >> S[i];
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    map<string,ll> mp;
    rep(i,N) mp[S[i]] = 0;
    rep(i,N) chmax(mp[S[i]],A[i]); 

    ll nn = mp.size();
    vec(string) S2;
    vec(ll) A2;
    for(auto [s,a]:mp){
        S2.emplace_back(s);
        A2.emplace_back(a);
    }


    vvec(bool) isin(nn,vec(bool)(nn,false));
    rep(i,nn)rep(j,nn){
        if(i==j) continue;
        string si = S2[i], sj = S2[j];
        ll ni = si.size(), nj = sj.size();
        if(ni >= nj) continue;;

        string ss = si + "." + sj;
        vec(int) z = z_algorithm(ss);
        for(ll st=ni; st<ni+nj+1; ++st){
            if(z[st]==ni){
                isin[j][i] = true;
                break;
            }
        }
    }


    ll st = nn*2, gl = nn*2+1;
    mf_graph<ll> mf(nn*2+2);

    rep(i,nn) mf.add_edge(st,i,A2[i]);
    rep(i,nn) mf.add_edge(nn+i,gl,A2[i]);
    rep(i,nn)rep(j,nn){
        if(isin[i][j]) mf.add_edge(i,nn+j,llINF);
    }

    ll atot = 0;
    rep(i,nn) atot += A2[i];

    ll fl = mf.flow(st,gl);

    ll ans = atot - fl;

    // cerr << atot << " " << fl << endl;
    // rep(i,nn){
    //     rep(j,nn) cerr << isin[i][j] << " "; cerr << endl;
    // }
    // rep(i,nn) cerr << S2[i] << " " << A2[i] << endl;

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
