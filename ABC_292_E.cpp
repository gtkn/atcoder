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
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N,M;
        cin >> N >> M;

        vvec(ll) g(N);
        rep(_,M){
            ll a,b;
            cin >> a >> b;
            a--;b--;
            g[a].push_back(b);
        }

        ll ans = 0;
        rep(st,N){
            vec(bool) used(N);
            queue<ll> q;
            q.push(st);
            while(!q.empty()){
                ll q0 = q.front();
                q.pop();
                if(used[q0]) continue;
                used[q0]=true;
                ans++;
                for(ll to:g[q0]) if(!used[to]) q.push(to);
            }
            ans--;
        }
        ans -= M;
        cout << ans << endl;



        // vvec(bool) g(N,vec(bool)(N));
        // rep(_,M){
        //     ll a,b;
        //     cin >> a >> b;
        //     a--;b--;
        //     g[a][b]=true;
        // }

        // queue<Pll> q;
        // rep(a,N){
        //     rep(b,N){
        //         if(!g[a][b]) continue;
        //         rep(c,N){
        //             if(!g[b][c])
        //         }
        //     }
        // }


        // scc_graph sg(N);
        // dsu d(N);
        // vec(set<ll>) gf(N),gr(N);


        // rep(_,M){
        //     ll a,b;
        //     cin >> a >> b;
        //     a--;b--;
        //     sg.add_edge(a,b);            
        //     d.merge(a,b);
        //     gf[a].insert(b);
        //     gr[b].insert(a);
        // }

        // ll ans = 0;
        // queue<Pll> q;
        // rep(i,N){
        //     for(ll frm:gr[i]){
        //         for(ll nxt:gf[i]){
        //             if(!sfind(gf[frm],nxt) && frm!=nxt) q.emplace(frm,nxt);
        //         }
        //     }
        // }

        // while(!q.empty()){
        //     Pll q0 = q.front();
        //     q.pop();
        //     ll a,b;
        //     a = q0.first; b = q0.second;
        //     if(sfind(gf[a],b) || a==b) continue;
        //     gf[a].insert(b);
        //     gr[b].insert(a);
        //     ans++;

        //     for(ll frm:gr[a]){
        //         if(!sfind(gf[frm],b)) q.emplace(frm,b);
        //     }

        //     for(ll nxt:gf[b]){
        //         if(!sfind(gf[a],nxt)) q.emplace(a,nxt);
        //     }
        // }

        // cout << ans << endl;


        // auto scc = sg.scc();
        // vec(ll) cnt(N);
        // ll ans = 0;

        // for(auto v:scc){
        //     ll nn = v.size();

        //     ll tmp = 0;
        //     for(ll vi:v) for(ll par:gr[vi]) tmp += cnt[par];

        //     ans += tmp*nn;
        //     ans += nn*(nn-1);
        //     tmp += nn;
        //     for(ll vi:v) cnt[vi] = tmp;



        //     // ll ld = d.leader(v[0]);
        //     // ll nn = v.size();
        //     // cout << ld << " , " << nn << " , " << cnt[ld] << endl;

        //     // ans += cnt[ld]*nn;
        //     // ans += nn*(nn-1);
        //     // cnt[ld] += nn;
        // }

        // ans -= M;
        // cout << ans << endl;



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
