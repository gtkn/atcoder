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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    
    void solve(){
        ll N,M;
        cin >> N >> M;

        vvec(ll) gf(N),gr(N);
        rep(_,M){
            ll a,b;
            cin >> a >> b;
            --a; --b;
            gf[a].push_back(b);
            gr[b].push_back(a);
        }

        vec(bool) okf(N),okr(N);
        queue<ll> q;
        q.push(0);
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(ll nxt:gf[now]){
                if(okf[nxt]) continue;
                okf[nxt]=true;
                q.push(nxt);
            }
        }

        q.push(0);
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(ll nxt:gr[now]){
                if(okr[nxt]) continue;
                okr[nxt]=true;
                q.push(nxt);
            }
        }

        vec(bool) ok(N);
        rep(i,N) ok[i] = (okf[i] & okr[i]);

        // rep(i,N) cout << i+1 << " : " << ok[i] << endl;

        ll x = 0;
        vec(ll) dist(N,-1);
        q.push(0);
        dist[0]=0;
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(ll nxt:gf[now]){
                if(!ok[nxt]) continue;
                if(dist[nxt]==-1){
                    dist[nxt] = dist[now]+1;
                    q.push(nxt);
                }else{
                    ll y = abs(dist[now]+1-dist[nxt]);
                    if(y) x = gcd(x, y);
                }
            }
        }

        if(x==0) x=3;
        while(x%2==0) x/=2;
        while(x%5==0) x/=5;
        if(x==1) yn;
        


    }
};



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
