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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

void solve(){
    ll N,M;
    cin >> N >> M;

    vvec(Pll) g(N);
    vec(ll) W(M);
    rep(i,M){
        ll a,b,w;
        cin >> a >> b >> w;
        --a;--b;
        g[a].emplace_back(b,w);
        g[b].emplace_back(a,w);
        W[i] = w;
    }


    auto check = [&](ll th)->ll{

        vec(ll) dist(N,llINF);

        rep(st,N){
            if(dist[st]<llINF) continue;

            queue<ll> q;
            q.push(st);
            dist[st]=0;

            while(!q.empty()){
                ll now = q.front(); q.pop();
                for(Pll gi:g[now]){
                    if( gi.second > th ) continue;
                    ll nxt = gi.first;
                    if(dist[nxt]==llINF){
                        q.push(nxt);
                        dist[nxt] = dist[now] + 1;
                    }else{
                        if( abs(dist[nxt]-dist[now])%2 == 0 ){
                            // cout << th << " : " << now << ", " << dist[now] << " , " << nxt << ", " << dist[nxt] << endl;
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    };


    auto f = [&](ll idx, ll th)->ll{
        ll res = llINF;
        vec(ll) v;
        for(Pll gi:g[idx]){
            if(gi.second<=th) v.push_back(gi.second);
            else chmin(res,gi.second);
        }
        if(v.size()>=2){
            sort(all(v));
            chmin(res,v[0]+v[1]);
        }
        return res;
    };



    ll ans = llINF;
    W.push_back(0);
    sort(all(W));
    ll l = 0, r = M+1;
    while(r-l>1){
        ll mid = (l+r)/2;
        if(check(W[mid])) l = mid;
        else r = mid;
    }

    rep(i,N) chmin(ans, f(i,W[l]));

    // cout << l << " !" << endl;
    cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
