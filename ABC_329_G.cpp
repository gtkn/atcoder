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
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------



    // LCA tekina
    struct LCA{
        ll N,ln;
        vvec(ll) g;
        vvec(ll) par;
        vec(ll) dep;

        void _dfs(ll now,ll frm){
            par[now][0] = frm;
            dep[now] = dep[frm]+1;

            for(ll nxt:g[now]){
                if(nxt==frm) continue;
                _dfs(nxt,now);
            }
        }


        LCA(vvec(ll) _g, ll rt = 0){
            g = _g;
            N = g.size();
            ln = log2(N) + 1;
            dep.resize(N);
            par = vvec(ll)(N,vec(ll)(ln));

            dep[rt] = -1;
            _dfs(rt,rt);

            rep(j,ln){
                if(j==0) continue;
                rep(i,N) par[i][j] = par[ par[i][j-1] ][j-1];
            }
        }


        ll get_dist(ll a,ll b){
            return dep[a] + dep[b] - 2*dep[get_lca(a,b)];
        }

        ll get_lca(ll a,ll b){
            if(dep[a]<dep[b]) swap(a,b);
            ll dd=dep[a]-dep[b];
            ll ex=0;
            while(dd){
                if(dd&1) a = par[a][ex];
                dd >>= 1;
                ex++;
            }

            if(a==b) return(a);
            repr(i,ln){
                if(par[a][i]==par[b][i]) continue;
                a = par[a][i];
                b = par[b][i];
            }
            return par[a][0];
        }

    };





void solve(){
    ll N,M,K;
    cin >> N >> M >> K;

    vvec(ll) g(N);
    rep1(i,N-1){
        ll p; cin >> p;
        g[p-1].push_back(i);
    }

    LCA lca(g);

    vec(ll) S(M),T(M);
    rep(i,M) cin >> S[i];
    rep(i,M) cin >> T[i];
    rep(i,M) S[i]--;
    rep(i,M) T[i]--;
    // rep(i,M) A[i] = lca.get_lca(S[i],T[i]);
    vvec(ll) memo(N);
    rep(i,M) memo[ lca.get_lca(S[i],T[i]) ].push_back(i);

    vec(ll) B(N);
    rep(i,M) B[S[i]]++;




    auto f = [&](auto f,ll now, ll &k)->mint{
        bool go0=false,go1=false;
        ll a0=0,a1=0;

        // cout << "now " << now << endl;


        if(g[now].size()==0){
            k += B[now];
            mint res = 1;
            if(k>K) res=0;
            return res;
        }


        for(ll b:memo[now]){
            bool t0 = false;
            if( lca.get_lca(T[b], g[now][0] ) == g[now][0] ){
                if(S[b]==now){
                    a0++;
                }else{
                    go1=true;
                }
            }else{
                if(T[b]!=now){
                //     pass;                    
                // }else{
                    if(S[b]==now){
                        a1++;
                    }else{
                        go0=true;
                    }
                }
            }
        }


        if(g[now].size()==1){
            k += a0;
            mint res = f(f,g[now][0],k);
            k += B[now]-a0;
            return res;
        }


        if(go0 && go1) return mint(0);

        mint res0=1,res1=1;
        ll k0=k, k1=k;

        {
            // 0->1
            k0 += a0;
            res0 = f(f,g[now][0],k0);
            k0 += a1;
            res0 *= f(f,g[now][1],k0);
            k0 += B[now]-a0-a1;
            if(k0>K) res0 = 0;

        }
        {
            // 1->0
            k1 += a1;
            res1 = f(f,g[now][1],k1);
            k1 += a0;
            res1 *= f(f,g[now][0],k1);
            k1 += B[now]-a0-a1;
            if(k1>K) res1 = 0;
        }

        if(go0){
            k = k0;
            return res0;
        }
        if(go1){
            k = k1;
            return res1;
        }

        assert(k0==k1);
        k = k0;

        if(res0==mint(0)) return res1;
        if(res1==mint(0)) return res0;
        return res0*res1;
    };


    ll _k = 0;
    mint ans = f(f,0,_k);

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
