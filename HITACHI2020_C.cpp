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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct edge{
    ll to,c;
    edge(ll to=0, ll c=0):to(to),c(c){}
};

struct abc{
    ll a,b,c;
    abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;
    
    vvec(ll) g(N);
    rep(_,N-1){
        ll a,b;
        cin >> a >> b;
        --a;--b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vvec(ll) vv(3);
    rep1(i,N) vv[i%3].push_back(i);
    vec(ll) ans(N),dep(N,-1);

    vvec(ll) vv2(2);


    queue<ll> q;
    q.push(0);
    dep[0]=0;
    while(!q.empty()){
        ll now = q.front(); q.pop();
        vv2[dep[now]&1].push_back(now);
        for(ll nxt:g[now]){
            if(dep[nxt]>=0) continue;
            q.push(nxt);
            dep[nxt]=dep[now]+1;
        }
    }


    if( vv2[0].size() > vv[0].size() && vv2[1].size() > vv[0].size()  ){
        for(ll i:vv2[0]){
            ll x = 1;
            if(vv[x].empty()) x=0;
            ans[i] = vv[x].back();
            vv[x].pop_back();
        }
        for(ll i:vv2[1]){
            ll x = 2;
            if(vv[x].empty()) x=0;
            ans[i] = vv[x].back();
            vv[x].pop_back();
        }

    }else{
        if(vv2[1].size() <= vv[0].size()) swap(vv2[0], vv2[1]);

        vec(bool) used(N+1);
        for(ll i:vv2[0]){
            ans[i] = vv[0].back();
            vv[0].pop_back();
            used[ans[i]] = true;
        }

        ll cnt=1;
        rep(i,N){
            if(ans[i]>0) continue;
            while(used[cnt]) cnt++;
            ans[i]=cnt;
            used[cnt]=true;
        }

    }






  
    for(ll ai:ans) cout << ai << " "; cout << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
