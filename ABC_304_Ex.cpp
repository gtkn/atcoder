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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define damedame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
 
    void solve(){
        ll N,M;
        cin >> N >> M;

        scc_graph scc(N);
        dsu d(N);
        vvec(ll) gf(N),gr(N);

        rep(_,M){
            ll s,t;
            cin >> s >> t;
            --s; --t;
            scc.add_edge(s,t);
            d.merge(s,t);
            gf[s].push_back(t);
            gr[t].push_back(s);
        }

        vec(ll) L(N),R(N);
        rep(i,N) cin >> L[i] >> R[i];
        rep(i,N) --L[i];

        vec(ll) gmemo(N);
        ll gcnt = 0;
        for(auto g:d.groups()){
            for(ll gi:g) gmemo[gi]=gcnt;
            gcnt++;
        }


        vvec(ll) gvv(gcnt);

        auto sccvv = scc.scc();
        for(auto v:sccvv){
            if(v.size()>1) damedame;
            gvv[ gmemo[v[0]] ].push_back(v[0]);
        }


        for(auto g:gvv){
            repr(i,g.size()){
                ll now = g[i];
                for(ll nxt:gr[now]) chmin(R[nxt], R[now]-1);
            }
            rep(i,g.size()){
                ll now = g[i];
                for(ll nxt:gf[now]) chmax(L[nxt], L[now]+1);
            }
        }
        rep(i,N) if(L[i]>=R[i]) damedame;


        // rep(i,gcnt){
        //     ll nn = gvv[i].size();
        //     repr(j,nn-1){
        //         chmin(R[gvv[i][j]],  R[gvv[i][j+1]]-1 );
        //     }

        //     rep(j,nn-1){
        //         chmax(L[gvv[i][j+1]], L[gvv[i][j]]+1);
        //     }

        //     rep(j,nn) if(L[gvv[i][j]]>=R[gvv[i][j]]) damedame;
        // }


        // vec(tri) vt(N);
        // rep(i,N) vt[i] = {R[i],L[i],i};
        // sort(all(vt));


        // // rep(i,gcnt){
        // //     for(ll gi:gvv[i]) cout << gi+1 << " -> "; cout << endl;
        // // }
        // // rep(i,N) cout << i+1 << " : "<< L[i] << "~ "<< R[i] << endl;

        // vec(ll) ans(N);

        // rep(i,N){
        //     ans[vt[i][2]] = i;
        //     // cout << vt[i][2]+1 << " : " << i << " // " << vt[i][1] << "~" << vt[i][0] << endl;
        //     if( i<vt[i][1] || i>=vt[i][0] ) damedame;
        // }

        // cout << "Yes" << endl;
        // for(ll ai:ans) cout << ai+1 << " ";cout <<endl;



        vvec(Pll) ri(N+1);
        rep(i,N) ri[ L[i] ].emplace_back(R[i],i);

        priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
        
        vec(ll) ans(N);
        rep(i,N){
            for(Pll x:ri[i]) pq.push(x);

            Pll x = pq.top();
            pq.pop();
            ll now = x.second;

            if(i<L[now] || i>=R[now]) damedame;
            ans[x.second] = i;
        }

        cout << "Yes" << endl;
        for(ll ai:ans) cout << ai+1 << " ";cout <<endl;




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
