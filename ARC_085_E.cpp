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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


struct MaxFlow{

    struct edge{
        ll to,cap,rev;
        edge(ll to=0, ll cap=0,ll rev=0):to(to),cap(cap),rev(rev){}
    };


    struct edge_status{
        ll from,to,cap,flow;
        edge_status(ll from, ll to=0, ll cap=0,ll flow=0):from(from),to(to),cap(cap),flow(flow){}
    };


    ll n,m;
    vvec(edge) g;
    vec(bool) used;
    vec(edge_status) status;
    
    vec(ll) level, iter;

    MaxFlow(ll n=0):n(n){
        assert(n>0);
        g.resize(n);
        m=0;
        used.resize(n);
        level.resize(n);
        iter.resize(n);
    }


    void add_edge(ll u, ll v, ll cap){
        g[u].emplace_back( v, cap, g[v].size() );
        g[v].emplace_back( u, 0, g[u].size()-1 );
        status.emplace_back(u,v,cap,g[u].size()-1);
        m++;
    }

    ll dfs(ll now,ll gl, ll f){
        if(now==gl) return f;
        used[now]=true;

        for(edge &e:g[now]){
            if(used[e.to] || e.cap==0) continue;
            ll d = dfs(e.to, gl, min(f, e.cap));
            if(d>0){
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }


    ll flow(ll st,ll gl){
        ll res = 0, pre=-1;
        while(res!=pre){
            rep(i,n) used[i]=false;
            pre = res;
            res += dfs(st,gl,llINF);
        }
        return res;
    }


    void bfs(ll st){
        rep(i,n) level[i]=-1;
        queue<ll> q;
        level[st]=0;
        q.push(st);
        while(!q.empty()){
            ll now = q.front(); q.pop();
            for(edge &e:g[now]){
                if(e.cap==0 || level[e.to]>=0) continue;
                level[e.to] = level[now]+1;
                q.push(e.to);
            }
        }
    }

    ll dfs2(ll now,ll gl, ll f){
        if(now==gl) return f;

        for(ll &i = iter[now]; i<g[now].size(); i++){
            edge &e = g[now][i];
            if(e.cap==0 || level[now] >= level[e.to]) continue;
            ll d = dfs2(e.to, gl, min(f, e.cap));
            if(d>0){
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }


    ll flow_dinic(ll st,ll gl){
        ll res = 0, pre=-1;
        while(res!=pre){
            bfs(st);
            if(level[gl]<0) break;
            rep(i,n) iter[i]=0;
            pre = res;
            ll d;
            while( (d=dfs2(st,gl,llINF)) ) res += d;
        }
        return res;
    }



    vec(edge_status) edges(){
        vec(edge_status) res = status;
        for(edge_status &e:res){
            e.flow = e.cap - g[e.from][e.flow].cap;
        }
        return res;
    }


};






void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    // mf_graph<ll> g(N+2);
    MaxFlow g(N+2);
    ll st=N, gl=N+1;

    ll ans = 0;
    rep(i,N){
        if(A[i]>=0){
            ans+=A[i];
            g.add_edge(st,i,A[i]);
        }else{
            g.add_edge(i,gl,-A[i]);
        }
    }

    rep(i,N){
        ll a = i+1;
        for(ll b = 2*a; b<=N; b+=a){
            g.add_edge(b-1,a-1,llINF);
        }
    }


    ans -= g.flow_dinic(st,gl);
    cout << ans << endl;


    // for(auto e:g.edges()){
    //     cout << e.from << " " << e.to << " " << e.cap <<" " << e.flow << endl;
    // }


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
