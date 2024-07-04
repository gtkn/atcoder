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
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;
    vec(ll) P(N);
    rep(i,N) cin >> P[i];
    rep(i,N) P[i]--;

    ll M;
    cin >> M;
    vec(ll) a(M),b(M);
    rep(i,M) cin >> a[i] >> b[i];
    rep(i,M){
        a[i]--; b[i]--;
    }

    vvec(ll) midx(N,vec(ll)(N,-1));
    rep(i,M){
        midx[a[i]][b[i]] = i;
        midx[b[i]][a[i]] = i;
    }

    dsu uf(N);
    vvec(ll) g(N);
    rep(i,M){
        if(uf.same(a[i],b[i])) continue;
        uf.merge(a[i],b[i]);
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }


    auto grps = uf.groups();
    vec(ll) ans;
    vec(bool) used(N);



    vec(ll) pos(N);
    rep(i,N) pos[P[i]] = i;
    

    auto f = [&](ll gl)->void{
        ll st = pos[gl];

        vec(ll) dist(N,llINF);
        queue<ll> q;
        q.push(gl);
        dist[gl] = 0;

        while(!q.empty()){
            ll now = q.front(); q.pop();
            for(ll nxt:g[now]){
                if(chmin(dist[nxt],dist[now]+1)) q.push(nxt);
            }
        }

        ll now = st;
        while(now!=gl){
            for(ll nxt:g[now]){
                if(dist[nxt]!=dist[now]-1) continue;
                ans.push_back(midx[now][nxt]);
                swap(pos[P[now]],pos[P[nxt]]);
                swap(P[now],P[nxt]);
                now = nxt;
                break;
            }
        }
    };


    auto f2 = [&](auto f2, ll now, ll frm)->void{
        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            f2(f2, nxt,now);
        }
        f(now);
    };


    for(auto grp:grps){
        vec(ll) as;
        for(auto idx:grp){
            as.push_back(P[idx]);
        }
        sort(all(as));
        sort(all(grp));
        ll nn = grp.size();
        rep(i,nn)if(as[i]!=grp[i]) dame;
        f2(f2,grp[0],grp[0]);
    }

    cout << ans.size() << endl;
    for(auto a:ans) cout << a+1 << " "; cout << endl;

    // rep(i,N) cerr << P[i]+1 << " "; cerr << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
