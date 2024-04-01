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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------



// 木の直径を求める
ll calcTreeDiameter(const vvec(ll)& g){
    ll n = g.size();


    ll st = 0, gl=0;
    vec(ll) dist(n,llINF);
    rep(_,2){
        swap(st,gl);

        // stから一番遠いところをglにする
        rep(i,n) dist[i]=llINF;
        dist[st]=0;
        queue<ll> q;
        q.push(st);
        dist[st]=0;
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(ll nxt:g[now]) if(chmin(dist[nxt], dist[now]+1)) q.push(nxt);
        }
        ll dmax = 0;
        rep(i,n) if(chmax(dmax,dist[i])) gl = i;
    }

    return dist[gl];
}



void solve(){
    ll N;
    cin >> N;

    vvec(ll) g(N);
    rep(_,N-1){
        ll u,v;
        cin >> u >> v;
        --u,--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vec(ll) dp(N,1);

    auto f = [&](auto f, ll now, ll frm)->void{
        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            f(f,nxt,now);
            dp[now] += dp[nxt];            
        }
    };
    f(f,0,0);

    ll nn = N/2;
    ll ju = -1;
    vec(ll) sts;

    if(N%2==0){
        ll iu = -1;
        rep(now,N){
            if(dp[now]==nn){
                for(ll nxt:g[now]){
                    if(dp[nxt]>dp[now]) iu = nxt;
                }
                ju = now;
            }
        }
        if(iu!=-1){
            vec(ll) memo;
            vec(bool) used(N);
            used[iu] = true; used[ju] = true;
            for(ll st:{iu,ju}){
                queue<ll> q;
                q.push(st);

                while(!q.empty()){
                    ll now = q.front(); q.pop();
                    memo.push_back(now);
                    used[now] = true;
                    for(ll nxt:g[now]) if(!used[nxt]) q.push(nxt);
                }
            }

            assert(memo.size()==N);
            // rep(i,N) cout << memo[i]+1 << " "; cout << endl;

            vec(ll) ans(N);
            rep(i,N) ans[memo[i]] = memo[(i+nn)%N];
            rep(i,N) cout << ans[i]+1 << " "; cout << endl;
            return;
        }

        
    }




    rep(now,N){
        if(N-dp[now] > nn) continue;
        bool isok=true;
        for(ll nxt:g[now]){
            if(dp[nxt]>dp[now]) continue;
            if(dp[nxt]>nn) isok=false;
        }
        if(isok){
            ju = now;
            break;
        }
    }
    // rep(i,N) cerr << i << " : " << dp[i] << endl;

    assert(ju!=-1);
    vec(ll) memo;
    vec(bool) used(N);
    used[ju] = true;

    for(ll st:g[ju]){
        queue<ll> q;
        q.push(st);

        while(!q.empty()){
            ll now = q.front(); q.pop();
            memo.push_back(now);
            used[now] = true;
            for(ll nxt:g[now]) if(!used[nxt]) q.push(nxt);
        }
    }

    assert(memo.size()==N-1);

    vec(ll) ans(N);
    rep(i,N-1){
        ll j = (i+nn)%(N-1);
        ans[memo[i]] = memo[j];
    }
    ans[ju] = ju;

    rep(i,N) cout << ans[i]+1 << " "; cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
