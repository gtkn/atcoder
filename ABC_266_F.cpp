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
    ll N;
    vvec(ll) g0;
    vec(ll) cc;
    vec(bool) used;
    bool aaa = false;


    bool dfs0(ll now,ll frm){
        used[now] = true;

        for(ll to:g0[now]){
            if(to==frm) continue;
            if(used[to]){
                cc.push_back(to);
                cc.push_back(now);
                aaa = true;
                return true;
            }
            if(dfs0(to,now)){
                if(cc[0]==now) aaa = false;
                if(aaa) cc.push_back(now);
                return true;
            }
        }
        return false;
    }



    void solve(){
        cin >> N;

        used.resize(N);
        vec(Pll) edge;
        g0.resize(N);

        rep(_,N){
            ll u,v;
            cin >> u >> v;
            u--;v--;
            edge.emplace_back(u,v);
            g0[u].push_back(v);
            g0[v].push_back(u);
        }

        dfs0(0,0);

        dsu d(N);
        rep(i,N) used[i]=false;
        for(ll ci:cc) used[ci]=true;



        for(ll st:cc){

            queue<ll> q;
            q.push(st);

            while(!q.empty()){
                ll now =q.front();
                d.merge(st,now);
                used[now]=true;
                q.pop();
                for(ll to:g0[now]){
                    if(used[to]) continue;
                    q.push(to);
                }
            }
        }

        ll Q;
        cin >> Q;
        while(Q--){
            ll x,y;
            cin >> x >> y;
            x--;y--;

            if(d.same(x,y)) yn;
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
