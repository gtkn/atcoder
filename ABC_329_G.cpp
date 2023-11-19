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

#define dame { puts("0"); return;}
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
    rep(i,M) cin >> S[i] >> T[i];
    rep(i,M) S[i]--;
    rep(i,M) T[i]--;


    vec(ll) go01(N);

    rep(i,M){
        ll a = lca.get_lca(S[i],T[i]);

        // cout << S[i] << " " << T[i] << " ; " << a <<","<<g[a][0]<<", " << lca.get_lca(S[i],g[a][0]) << endl;  

        if(a==S[i] || a==T[i]) continue;

        if(lca.get_lca(S[i],g[a][0]) == g[a][0]){
            go01[a] |= 1;
        }else{
            go01[a] |= 2;
        }
    }

    // rep(i,N) cout << i << " ;go  " << go01[i] << endl;


    rep(i,N) if(go01[i]==3) dame;

    vvec(ll) bin(N,vec(ll)(3)), bout(N,vec(ll)(3));
    rep(i,M){
        ll s=S[i], t=T[i];
        ll a = lca.get_lca(s,t);

        if(a==s){
            if( lca.get_lca(g[a][0], t) == g[a][0] ){
                bin[s][0]++;
                bout[t][2]++;
            }else{
                bin[s][1]++;
                bout[t][2]++;
            }
        }else if(a==t){
            if( lca.get_lca(g[a][0], s) == g[a][0]){
                bin[s][2]++;
                bout[t][0]++;
            }else{
                bin[s][2]++;
                bout[t][1]++;
            }
        }else{
            bin[s][2]++;
            bout[t][2]++;
        }
    }

    // rep(i,N){
    //     cout << "---" << i << endl;
    //     rep(j,3) cout << bin[i][j] << " "; cout << endl;
    //     rep(j,3) cout << bout[i][j] << " "; cout << endl;
    // }



    vvec(mint) dp(N,vec(mint)(K+1,1));
    vvec(ll) bcnt(N,vec(ll)(K+1,-1));
    vvec(bool) used(N,vec(bool)(K+1));


    auto f = [&](auto f,ll now,ll k)->pair<mint,ll>{
        if(k>K || k<0) return {0,-1};
        if(used[now][k]) return {dp[now][k],bcnt[now][k]};
        used[now][k]=true;

        ll kk = k - bout[now][2];
        ll kmemo = kk;
        mint res = 0;


        if(g[now].size()==0){
            res=1;
        }
        if(g[now].size()==1){
            kk += bin[now][0];
            pair<mint,ll> fres = f(f,g[now][0],kk);
            res = fres.first;
            kk = fres.second;
            kk -= bout[now][0];
        }
        if(g[now].size()==2){
            vec(mint) rv(2);
            vec(ll) kv(2,-1);

            rep(i,2){
                vec(ll) pt = {i,1-i};
                if(go01[now]==1 && pt[0]!=0) continue;
                if(go01[now]==2 && pt[0]!=1) continue;

                kk = kmemo;
                mint tmp = 1;

                for(ll x:pt){
                    kk += bin[now][x];
                    pair<mint,ll> fres = f(f,g[now][x],kk);
                    tmp *= fres.first;
                    kk = fres.second;
                    kk -= bout[now][x];
                }
                rv[i] = tmp; kv[i]=kk;
            }
            kk = 0; res = 0;
            rep(i,2){
                if(kv[i]>=0){
                    kk = kv[i];
                    res += rv[i];
                }
            }
        }

        kk += bin[now][2];

        if(kk>K){
            dp[now][k] = 0;
            bcnt[now][k] = -1;
        }else{
            dp[now][k] = res;
            bcnt[now][k] = kk;
        }

        // cout <<"out : "<< now << " " << k << " ; " << dp[now][k].val() <<"  ," << bcnt[now][k] << endl;

        return {dp[now][k],bcnt[now][k]};

    };


    auto [ans, _] = f(f,0,0);

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
