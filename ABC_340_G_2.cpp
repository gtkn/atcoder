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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


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
    ll N;
    cin >> N;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];
    rep(i,N) A[i]--;

    vvec(ll) g(N);
    rep(_,N-1){
        ll u,v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LCA lca(g);
    vec(ll) dep = lca.dep;


    vec(ll) y(N);
    vec(Pll) inout(N);
    ll cnt = 0;
    auto dfs1 = [&](auto dfs1, ll now ,ll frm)->void{
        y[now] = cnt++;
        inout[now].first = cnt;
        for(ll nxt:g[now])if(nxt!=frm){
            dfs1(dfs1, nxt, now);
            cnt++;
        }
        inout[now].second = cnt;
    };
    dfs1(dfs1,0,0);


    vvec(ll) vv(N);
    rep(i,N) vv[A[i]].push_back(i);


    vvec(ll) gg(N);


    mint ans = 0;

    auto dfs2 = [&](auto dfs2, ll now, ll frm, ll c)->mint{
        mint res = 1;
        vec(mint) memo;
        for(ll nxt:gg[now])if(nxt!=frm){
            memo.push_back(dfs2(dfs2, nxt, now, c) );
            res *= memo.back()+1;
        }
        ans += res;
        if(A[now]!=c){
            for(mint m:memo){
                ans -= m;
            }
            ans--;
            res--;
        }
        
        // cerr << now << " " << res.val() << endl;

        return res;
    };



    // cerr << "inout" << endl;
    // rep(i,N){
    //     cerr << i << " : " << inout[i].first << " " << inout[i].second << endl;
    // }




    for(vec(ll)& v:vv){
        sort(all(v),[&](ll a,ll b){
            return y[a] < y[b];
        });
    }


    rep(c,N){
        vec(ll) v = vv[c];
        if(v.empty()) continue;

        rep(i, vv[c].size()-1){
            v.push_back( lca.get_lca(vv[c][i], vv[c][i+1]) );
        }

        sort(all(v),[&](ll a,ll b){
            return y[a] < y[b];
        });
        v.erase(unique(all(v)),v.end());

        vec(ll) memo;
        for(ll vi:v){
            if(memo.empty()){
                memo.push_back(vi);
                continue;
            }
            while(!memo.empty() && inout[memo.back()].second < inout[vi].first){
                memo.pop_back();
            }
            if(!memo.empty()){
                gg[memo.back()].push_back(vi);
                gg[vi].push_back(memo.back());
            }
            memo.push_back(vi);
        }

    
        dfs2(dfs2,v[0],v[0],c);


        // cerr << c << " ---- " << ans.val() << endl;
        // cerr << "vvc" << endl;
        // for(ll vi:vv[c]){
        //     cerr << vi << " ";
        // }
        // cerr << endl;


        // // cerr << "v" << endl;
        // // for(ll vi:v){
        // //     cerr << vi << " ";
        // // }
        // // cerr << endl;

        // cerr << "gg" << endl;
        // rep(i,N){
        //     cerr << i << " : ";
        //     for(ll vi:gg[i]){
        //         cerr << vi << " ";
        //     }
        //     cerr << endl;
        // }



        for(ll vi:v){
            gg[vi].clear();
        } 

    }


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
