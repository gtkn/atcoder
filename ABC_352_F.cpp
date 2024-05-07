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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

void solve(){
    ll N, M ;
    cin >> N >> M;

    dsu uf(N);
    vvec(Pll) g(N);
    rep(_,M){
        ll a,b,c;
        cin >> a >> b >> c;
        --a; --b;
        g[b].emplace_back(a,c);
        g[a].emplace_back(b,-c);
        uf.merge(a,b);
    }



    vvec(int) vv;
    vec(int) one;
    for(auto v:uf.groups()){
        if(v.size()==1) one.push_back(v[0]);
        else vv.emplace_back(v);
    }

    ll nn = vv.size();

    vvec(Pll) vv2(nn);
    rep(i,nn){
        map<ll,ll> mp;
        queue<Pll> q;
        q.emplace(vv[i][0],0);

        while(!q.empty()){
            auto [now,x] = q.front(); q.pop();
            mp[now] = x;
            for(auto [nxt,d]:g[now]){
                if(mp.find(nxt)!=mp.end()) continue;
                q.emplace(nxt, x+d);
            }
        }

        ll xmin = 0;
        for(auto [k,v]:mp) chmin(xmin,v);
        for(auto [k,v]:mp) vv2[i].emplace_back(k,v-xmin);
        sort(all(vv2[i]));
    }



    vector<set<ll>> cand(N);

    auto f = [&](auto f, ll idx, ll now)->bool{
        if(idx==nn) return true;

        bool res = false;
        rep(st,N){
            ll nxt = 0;
            bool isok = true;
            for(auto [i,d]:vv2[idx]){
                if(st+d >= N) isok = false;
                nxt |= (1<<(st+d));
            }
            if(!isok) continue;
            if(now&nxt) continue;

            if( f(f,idx+1,now|nxt) ){
                for(auto [i,d]:vv2[idx]){
                    cand[i].insert(st+d);
                }
                res = true;
            }
        }
        return res;
    };

    f(f,0,0);


    // cerr << "cand: " << endl;
    // rep(i,N){
    //     cerr << i << " : ";
    //     for(ll x:cand[i]) cerr << x << " "; cerr << endl;
    // }
    // cerr << "one :" << endl;
    // for(ll x:one) cerr << x << " "; cerr << endl;


    vec(ll) ans(N,-1);
    rep(i,N){
        if(cand[i].size()==1){
            ans[i] = *cand[i].begin()+1;
        }
    }


    vec(bool) rem(N,true);
    rep(i,N)for(ll x:cand[i]) rem[x] = false;
    ll rcnt = 0;
    rep(i,N) rcnt += rem[i];
    if(rcnt==1 && one.size()==1){
        rep(i,N)if(rem[i]) ans[one[0]] = i+1;
    }


    rep(i,N) cout << ans[i] << " "; cout << endl;




    





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
