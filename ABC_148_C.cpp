//title
#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{


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
        ll N,Q;
        cin >> N >> Q;

        vec(ll) P(N);
        rep1(i,N-1) cin >> P[i];

        vvec(ll) g(N);
        rep1(i,N-1){
            g[P[i]-1].push_back(i);
            g[i].push_back(P[i]-1);
        }


        /*
        rep(i,N){
            cout << i << " ; ";
            for(ll to : g[i]) cout << to << " ";
            cout << endl;
        }
        */


        LCA lca(g);

        vec(Pll) dep;
        rep(i,N) dep.emplace_back(lca.dep[i],i);

        //rep(i,N) cout <<dep[i].second << " dep "<<  dep[i].first << endl;

        vec(bool) bw(N);

        ll th = sqrt(N);

        while(Q--){
            ll M; cin >> M;
            vec(ll) v(M);
            rep(i,M) cin >> v[i];
            
            vec(Pll) a;
            rep(i,M) a.push_back(dep[v[i]-1]);
            sort(all(a));
            
            ll res = 0;
            rep(i,M) bw[v[i]-1] = true;

            set<ll> big;


            for(Pll ai:a){
                ll st = ai.second;
                if(!bw[st]) continue;
                res++;

                queue<ll> q;
                q.push(st);
                //cout << "st -- " << st << endl;

                while(!q.empty()){
                    ll now = q.front();
                    q.pop();

                    //cout << "now : "<< now << endl;
                    
                    if(!bw[now]) continue;
                    bw[now] = false;

                    if(g[now].size()>th){
                        big.insert(now);
                        res += g[now].size() - ((now==0)? 0 : 1);
                        //cout << "big : " << now << " , " << g[now].size() - ((now==0)? 0 : 1) << endl;
                        continue;
                    }

                    for(ll to:g[now]){
                        if(sfind(big,to)){
                            res-=2;
                            //cout << res << " ! " << endl;
                            continue;
                        }
                        if(to == P[now]-1) continue;
                        if(bw[to]) q.push(to);
                        else res++;
                    }                    
                }
            }

            cout << res << endl;
            //break;
        }



    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
