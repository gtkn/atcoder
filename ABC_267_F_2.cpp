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


Pll calcTreeDiameter(const vvec(ll)& g){
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

    return {st,gl};
}



void doubling(vvec(ll) &db, ll xx){
    // 0列目まで埋めたダブリングの配列の残りを計算する
    // 遷移先がない場合はxx
    ll n,m;
    n = db.size();
    m = db[0].size();

    rep(j,m-1)rep(i,n){
        if(db[i][j]==xx){
            db[i][j+1] = xx;
        }else{
            db[i][j+1] = db[ db[i][j] ][j];
        }
    }
}




void solve(){
    ll N;
    cin >> N;

    vvec(ll) g(N);
    rep(_,N-1){
        ll a,b;
        cin >> a >> b;
        --a,--b;
        g[a].push_back(b);
        g[b].push_back(a);

    }


    ll Q;
    cin >> Q;
    vec(ll) U(Q),K(Q);
    rep(i,Q) cin >> U[i] >> K[i], --U[i];


    auto [r0,r1] = calcTreeDiameter(g);
    ll nn = log(N)+10;
    vec(ll) ans(Q,-1);



    rep(_,2){
        vec(ll) dep(N,llINF);
        vec(ll) par(N,-1);
        queue<ll> q;
        q.push(r0);
        dep[r0] = 0;
        while(!q.empty()){
            ll now = q.front();
            q.pop();
            for(ll nxt:g[now]){
                if(chmin(dep[nxt],dep[now]+1)){
                    q.push(nxt);
                    par[nxt] = now;
                }
            }
        }
        // rep(i,N) cerr << dep[i] << " "; cerr << endl;

        vvec(ll) db(N,vec(ll)(nn));
        rep(i,N) db[i][0] = par[i];
        doubling(db,-1);


        rep(i,Q){
            ll u = U[i];
            ll k = K[i];
            // cerr << u << " " << k <<" " <<dep[u] << endl;
            if(dep[u]<k) continue;
            rep(j,nn){
                if(bit(k,j)) u = db[u][j];
            }
            ans[i] = u + 1;
            // cerr << i << " " << u << " ! " << endl; 
        }
        // rep(i,Q) cerr << ans[i] << " "; cerr <<  nl; 
        swap(r0,r1);
    }

    rep(i,Q) cout << ans[i] << nl;






}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
