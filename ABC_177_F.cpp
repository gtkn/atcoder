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

//------------------------------------------------


struct Solver{

    void solve(){
        ll H,W;
        cin >> H >> W;

        set<Pll> s;
        multiset<ll> ms={llINF};
        rep1(i,W){
            s.emplace(i,i);
            ms.insert(0);
        }

        rep1(k,H){
            ll a,b;
            cin >> a >> b;
            
            vec(Pll) v;
            for(auto itr=s.lower_bound({a,0}); itr!=s.end() ;itr++){
                Pll si = *itr;
                if(si.first>b) break;
                v.push_back(si);
            }

            ll x=0;
            for(Pll vi:v){
                chmax(x,vi.second);
                s.erase(vi);
                ms.erase(ms.find(vi.first-vi.second));
            }

            if(b==W) b=llINF+W+10;
            if(x>0){
                s.emplace(b+1,x);
                ms.insert(b+1-x);
            }



            ll res = *ms.begin();
            if(res>=llINF) res = -1;
            else res += k;
            cout << res << endl;
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
