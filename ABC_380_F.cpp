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
// using mint = modint;
// mint::set_mod(P);


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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,M,L;
    cin >> N >> M >> L;
    vec(ll) A(N),B(M),C(L);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];
    rep(i,L) cin >> C[i];

    vec(ll) X = A;
    X.insert(X.end(),B.begin(),B.end());
    X.insert(X.end(),C.begin(),C.end());

    // ll tmp = 1;
    // rep(i,12) tmp*=3;
    // cerr << tmp << endl;

    ll nn = N+M+L;
    ll ptot = 1;
    rep(_,nn) ptot*=3;

    auto p2v = [&](ll p){
        vec(ll) v;
        rep(i,nn){
            v.push_back(p%3);
            p/=3;
        }
        reverse(all(v));
        return v;
    };

    auto v2p = [&](vec(ll) v){
        ll p = 0;
        rep(i,nn){
            p *= 3;
            p += v[i];
        }
        return p;
    };



    vec(bool) dp(ptot);
    vec(bool) used(ptot);


    auto f = [&](auto f, ll p)->bool{
        if(used[p]) return dp[p];
        // cerr << "p = " << p << endl;

        vec(ll) v = p2v(p);
        vec(ll) a,b,c;
        rep(i,nn){
            if(v[i]==0) c.push_back(i);
            if(v[i]==1) b.push_back(i);
            if(v[i]==2) a.push_back(i);
        }
        ll an = a.size(), bn = b.size(), cn = c.size();

        bool iswin = false;
        for(ll ii:a)for(ll jj:c){
            ll aval = X[ii];
            ll cval = X[jj];

            vec(ll) v2 = v;
            rep(i,nn){
                if(v2[i]==1) v2[i] = 2;
                else if(v2[i]==2) v2[i] = 1;
            }
            // rep(i,nn) cerr << v2[i] << " "; cerr << endl;

            v2[ii] = 0;
            ll p2 = v2p(v2);
            if(!f(f,p2)){
                iswin = true;
                break;
            }
            if(aval > cval){
                v2[jj] = 1;
                ll p3 = v2p(v2);
                if(!f(f,p3)){
                    iswin = true;
                    break;
                }
            }
        }

        used[p] = true;
        return dp[p] = iswin;

    };



    vec(ll) vinit(nn);
    rep(i,N) vinit[i] = 2;
    rep(i,M) vinit[N+i] = 1;

    ll pinit = v2p(vinit);

    if(f(f,pinit)) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;    


    // cerr << pinit << endl;
    // rep(i,ptot) cerr << dp[i] << " "; cerr << endl;




    // rep(p,ptot){
    //     vec(ll) v = p2v(p);

    //     vec(ll) a,b,c;
    //     rep(i,nn){
    //         if(v[i]==0) c.push_back(i);
    //         if(v[i]==1) b.push_back(i);
    //         if(v[i]==2) a.push_back(i);
    //     }

    //     ll an = a.size(), bn = b.size(), cn = c.size();

    //     bool iswin = false;
    //     for(ll ii:a)for(ll jj:c){
    //         ll aval = X[ii];
    //         ll cval = X[jj];

    //         vec(ll) v2 = v;
    //         rep(i,nn){
    //             if(v2[i]==1) v2[i] = 2;
    //             if(v2[i]==2) v2[i] = 1;
    //         }

    //         v2[ii] = 0;
    //         ll p2 = v2p(v2);
    //         // cerr << "p2 = " << p2 << endl;
    //         if(!dp[p2]){
    //             iswin = true;
    //             break;
    //         }
    //         if(aval > cval){
    //             v2[jj] = 1;
    //             ll p3 = v2p(v2);
    //             // cerr << "p3 = " << p3 << endl;
    //             if(!dp[p3]){
    //                 iswin = true;
    //                 break;
    //             }
    //         }
    //     }
    // }


    // vec(ll) vinit(nn);
    // rep(i,N) vinit[i] = 2;
    // rep(i,M) vinit[N+i] = 1;

    // ll pinit = v2p(vinit);

    // if(dp[pinit]) cout << "Takahashi" << endl;
    // else cout << "Aoki" << endl;    



    // auto f = [&](ll p)->bool{
    //     vec(ll) v;
    //     rep(i,nn){
    //         v.push_back(p%3);
    //         p/=3;
    //     }

    //     vec(ll) a,b,c;
    //     rep(i,nn){
    //         if(v[i]==0) a.push_back(i);
    //         if(v[i]==1) b.push_back(i);
    //         if(v[i]==2) c.push_back(i);
    //     }

    //     ll amax = 0;
    //     ll cmin = llINF;
    //     for(auto ai:a) chmax(amax,A[ai]);
    //     for(auto ci:c) chmin(cmin,C[ci]);



    // };






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
