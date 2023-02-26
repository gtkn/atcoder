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
#define sfind(s,x) (s.find(x)!=s.end())

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

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------



struct Solver{
 
    void solve(){
        ll N,M;
        cin >> N >> M;
        vvec(ll) g(N);
        vec(ll) v(N);
        

        dsu d(N);

        rep(_,M){
            ll x,y;
            cin >> x >> y;
            x--;y--;
            d.merge(x,y);
            g[x].push_back(y);
            v[y]++;
        }


        if(d.groups().size()>1){
            cout << "No" << endl;
            return;
        }


        vec(ll) ans(N);
        ll st = -1;

        rep(i,N){
            if(v[i]>0) continue;
            if(st!=-1){
                cout << "No" << endl;
                return;
            }
            st = i;
        }


        queue<ll> q;
        q.push(st);
        ll cnt = 1;

        while(!q.empty()){
            ll q0 = q.front(); q.pop();

            assert(v[q0]==0);
            ans[q0] = cnt++;

            for(ll to:g[q0]){
                v[to]--;
                if(v[to]==0) q.push(to);
                if(q.size()>1){
                    cout << "No" << endl;
                    return;
                }
            }
        }


        cout << "Yes" << endl;
        rep(i,N) cout << ans[i] << " "; cout << endl;





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
