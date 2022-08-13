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
 
    void solve(){
        ll N,M,E;
        cin >> N >> M >> E;

        vec(Pll) edge;
        rep(_,E){
            ll u,v;
            cin >> u >> v;
            edge.emplace_back(u-1,v-1);
        }

        ll Q; cin >> Q;
        vec(ll) X(Q);
        rep(i,Q) cin >> X[i];
        rep(i,Q) X[i]--;

        vec(bool) usededge(E,true);
        rep(i,Q) usededge[X[i]] = false;


        ll nm = N+M;
        vvec(ll) g(nm);
        rep(i,E){
            if(!usededge[i]) continue;
            g[edge[i].first].push_back(edge[i].second);        
            g[edge[i].second].push_back(edge[i].first);
        }
       

        vec(ll) used(nm);
        ll cnt = 0;

        rep(st,nm){
            if(used[st]) continue;
            if(st<N) continue;

            queue<ll> q;
            q.push(st);

            while(!q.empty()){
                ll now = q.front();
                q.pop();
                if(used[now]) continue;
                used[now] = true;
                if(now<N) cnt++;

                for(ll to:g[now]) if(!used[to]) q.push(to);
            }

        }



        vec(ll) ans;
        reverse(all(X));

        for(ll xi:X){
            ans.push_back(cnt);
            ll a,b;
            a = edge[xi].first; b=edge[xi].second;

            g[a].push_back(b);        
            g[b].push_back(a);
            usededge[xi]=true;

            if(used[a]==used[b]) continue;
            if(used[b]) swap(a,b);


            queue<ll> q;
            q.push(b);

            while(!q.empty()){
                ll now = q.front();
                q.pop();
                if(used[now]) continue;
                used[now] = true;
                if(now<N) cnt++;

                for(ll to:g[now]) if(!used[to]) q.push(to);
            }

        }

        reverse(all(ans));
        for(ll ai:ans ) cout << ai << endl;








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
