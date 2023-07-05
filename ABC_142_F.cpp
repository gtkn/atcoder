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
        ll N,M;
        cin >> N >> M;

        vvec(ll) g(N);
        // vec(Pll) incnt(N);
        // rep(i,N) incnt[i].second == i;

        rep(_,M){
            ll a,b;
            cin >> a >> b;
            --a; --b;
            g[a].push_back(b);
            // incnt[b].first++;
        }

        // sort(all(incnt));

        vec(bool) used(N);
        vec(ll) v,ans;

        auto f = [&](auto f,ll now){
            v.push_back(now);
            used[now]=true;
            bool res = false;
            // cout << now << " ! " << endl;

            for(ll nxt:g[now]){
                if(used[nxt]){
                    set<ll> s;
                    ll n = v.size();
                    repr(i,n){
                        s.insert(v[i]);
                        if(v[i]==nxt) break;
                    }
                    // for(ll si:s) cout << si <<  " "; cout<<endl;

                    bool isok=true;
                    for(ll si:s){
                        ll cnt = 0;
                        for(ll x:g[si]){
                            if(sfind(s,x)) cnt++;
                        }
                        if(cnt!=1) isok=false;
                    }
                    if(isok){
                        for(ll si:s) ans.push_back(si);
                        return true;
                    }
                }else{
                    if(f(f,nxt)){
                        res = true;
                        break;
                    }
                }
            }
            v.pop_back();
            used[now]=false;
            return res;
        };


        rep(st,N){
            if(f(f,st)){
                cout << ans.size() << endl;
                for(ll ai:ans) cout << ai+1 << endl;
                return;
            }
        }

        cout << -1 << endl;
        return;


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
