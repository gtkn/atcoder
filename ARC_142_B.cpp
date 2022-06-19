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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{ 
 
    void solve(){
        ll N;
        cin >> N;



        vvec(ll) ans(N,vec(ll)(N));

        auto f = [&](ll st,ll cnt){
            ll n = N-st*2-1;
            vec(Pll) v;

            if(n==0){
                v.emplace_back(st,st);
            }else{
                ll x=st,y=st;
                rep(dx,n) v.emplace_back(x+dx,y);
                x = st + n; y=st;
                rep(dy,n) v.emplace_back(x,y+dy);
                x = st; y= st + n;
                rep1r(dx,n) v.emplace_back(x+dx,y);
                x = st; y=st;
                rep1r(dy,n) v.emplace_back(x,y+dy);
            }

            //ans[v.back().first][v.back().second] = cnt++;
            //v.pop_back();
            
            ll nn = v.size();
            if(nn>=2){
                swap(v[nn-1],v[nn-2]); 
            }
            for(Pll vi:v) ans[vi.first][vi.second] = cnt++;

            return cnt;
        };

        ll x = 1;
        for(ll i=0; 2*i<N; i+=2){
            x = f(i,x);
        }
        for(ll i=1; 2*i<N; i+=2){
            x = f(i,x);
        }
        assert(x-1==N*N);

        rep(i,N){
            rep(j,N) cout << ans[i][j] << " "; cout << endl;
        }






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
