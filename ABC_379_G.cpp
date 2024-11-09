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
    ll H,W;
    cin >> H >> W;

    vec(string) S(H);
    rep(i,H) cin >> S[i];

    vvec(ll) vv(H,vec(ll)(W,4));
    rep(i,H)rep(j,W){
        if(S[i][j] == '?') continue;
        vv[i][j] = S[i][j] - '1';
    }

    rep(i,H)rep(j,W){
        ll ii = i+1, jj = j+1;

        if(ii<H){
            if(vv[i][j]<4 && vv[ii][j]<4 && vv[i][j] == vv[ii][j]){
                cout << 0 << endl;
                return;
            }
        }
        if(jj<W){
            if(vv[i][j]<4 && vv[i][jj]<4 && vv[i][j] == vv[i][jj]){
                cout << 0 << endl;
                return;
            }
        }
    }


    if(H<W){
        vvec(ll) vv2(W,vec(ll)(H));
        rep(i,H)rep(j,W){
            vv2[j][i] = vv[i][j];
        }
        swap(H,W);
        swap(vv,vv2);
    }




    vvec(ll) cand;

    vec(ll) tmp;
    auto f = [&](auto f)->void{
        if(tmp.size() == W){
            cand.push_back(tmp);
            return;
        }
        rep(x,3){
            if(tmp.size()>0 && tmp.back()==x) continue;
            tmp.push_back(x);
            f(f);
            tmp.pop_back();
        }
    };

    f(f);

    ll ww = cand.size();

    vec(ll) hs(ww);
    rep(i,ww){
        ll h = 0;
        rep(j,W){
            ll x = cand[i][j];
            h <<= 3;
            h |= (1<<x);
        }
        hs[i] = h;
    }



    vvec(ll) g(ww);

    rep(i,ww)rep(j,i){
        bool isok = true;
        // rep(k,W) if(cand[i][k]==cand[j][k]) isok = false;
        if(hs[i]&hs[j]) isok = false;
        if(isok){
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }

    vvec(bool) cand_isok(H,vec(bool)(ww));
    rep(i,H){
        rep(j,ww){
            const auto& c = cand[j];
            bool isok = true;
            rep(k,W){
                if(vv[i][k]<4 && vv[i][k]!=c[k]) isok = false;
            }
            cand_isok[i][j] = isok;
        }
    }

    vvec(mint) dp(H,vec(mint)(ww,0));
    rep(j,ww) if(cand_isok[0][j]) dp[0][j] = 1;


    rep(i,H-1)rep(j,ww){
        for(ll jj:g[j]){
            if(cand_isok[i+1][jj]){
                dp[i+1][jj] += dp[i][j];
            }
        }
    }

    mint ans = 0;
    rep(j,ww) ans += dp[H-1][j];
    cout << ans.val() << endl;
    








}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
