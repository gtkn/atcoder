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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};

void solve(){
    ll N,M,K;
    cin >> N >> M >> K;

    vvec(Pll) g(N+1);
    rep1(i,M){
        ll u,v;
        cin >> u >> v;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    rep1(i,N) g[0].emplace_back(i,0);

    if(K&1) sayno;
    


    vvec(Pll) tf(N+1);
    vec(Pll) par(N+1);
    vec(bool) used(N+1);

    auto f = [&](auto f, ll now)->void{
        used[now] = true;
        for(auto [nxt, idx]:g[now]){
            if(used[nxt]) continue;
            tf[now].emplace_back(nxt,idx);
            par[nxt] = {now,idx};
            f(f,nxt);
        }
    };

    f(f,0);


    ll cnt = 0;
    vec(ll) ans;
    vec(bool) ison(N+1);

    auto f2 = [&](auto f2, ll now)->void{

        for(auto [nxt,idx]:tf[now]){
            f2(f2,nxt);

            if(!ison[nxt] && cnt!=K && idx>0){
                ison[nxt]=true;
                cnt++;
                if(ison[now]){
                    ison[now] = false;
                    cnt--;
                }else{
                    ison[now] = true;
                    cnt++;
                }
                ans.push_back(idx);
            }
        }
    };

    f2(f2,0);

    if(cnt!=K) sayno;

    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for(ll ai:ans) cout << ai << " "; cout << endl;









    // rep1(i,N){
    //     cerr << i << "<-" << par[i].first << " : " << par[i].second << endl;
    // }


    // queue<ll> q;
    // vec(bool) ison(N+1);
    // rep1(i,N) if(tf[i].empty()) q.push(i);
    // vec(ll) ans;
    // ll cnt = 0;

    // while(!q.empty()){
    //     ll now = q.front(); q.pop();
    //     if(ison[now]) continue;

    //     auto [frm,idx] = par[now];
    //     if(idx==0) continue;

    //     ison[now] = true; cnt++;

    //     if(ison[frm]){
    //         ison[frm] = false;
    //         cnt--;
    //     }else{
    //         ison[frm] = true;
    //         cnt++;
    //     }

    //     ans.push_back(idx);

    //     if(cnt==K) break;
    // }

    // cout << ans.size() << endl;
    // for(ll ai:ans) cout << ai << " "; cout << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
