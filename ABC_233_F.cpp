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

//------------------------------------------------

struct Solver{

    ll N,M;
    vvec(Pll) g;
    vec(ll) v;
    vec(ll) ans;
    bool isok=true;

    void f(ll st){
        ll gl=st;
        rep(i,N) if(v[i]==st) gl=i;
        if(st==gl) return;

        vec(ll) dp(N,llINF);
        dp[st]=0;
        queue<ll> q;
        q.push(st);
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(Pll gi:g[now]){
                ll to = gi.first;
                if(dp[to]<llINF) continue;
                dp[to]=dp[now]+1;
                q.push(to);
            }
        }


        //cout << st << " -> " << gl << " : " << dp[gl] << endl;
        if(dp[gl]==llINF){
            isok=false;
            return;
        }

        ll now = gl;
        while(now!=st){
            for(Pll gi:g[now]){
                ll to = gi.first;
                if(dp[to]==dp[now]-1){
                    swap(v[now],v[to]);
                    now = to;
                    ans.push_back(gi.second);
                    break;
                }
            }
        }
        return;
    }

    vec(bool) used;
    vec(ll) jun;
    void dfs(ll now){
        if(used[now]) return;
        used[now]=true;
        jun.push_back(now);
        for(Pll gi:g[now]) dfs(gi.first);
    }



    void solve(){
        cin >> N;
        g.resize(N);
        v.resize(N);
        used.resize(N);

        rep(i,N) cin >> v[i];
        rep(i,N) v[i]--;
        cin >> M;

        dsu d(N);

        rep1(i,M){
            ll a,b;
            cin >> a >> b;
            a--;b--;
            if(d.same(a,b)) continue;
            d.merge(a,b);
            g[a].emplace_back(b,i);
            g[b].emplace_back(a,i);
        }

        rep(i,N) dfs(i);
        reverse(all(jun));
        for(ll ji:jun) f(ji);

        //assert(jun.size()==N);
        //if(isok) rep(i,N) assert(v[i]==i);
        
        if(isok){
            cout << ans.size() << endl;
            for(ll ai:ans) cout << ai << " "; cout<<endl;
        }else{
            cout << -1 << endl;
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
