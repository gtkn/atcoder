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
 
    void solve(){
        ll N;
        cin >> N;

        vec(ll) ans;

        auto f = [&](auto f,ll c,ll x, ll nn, ll pre){
            // cout << c << " " << x << " "<<  nn << " " << pre << endl;
            if(nn==1){
                if(c%x==0){
                    ans.push_back(c/x);
                    return true;
                }
                return false;
            }

            for(ll a= max(pre+1, c/x+1 )   ;  c*nn > a*x  ; a++){
                ans.push_back(a);
                if( f(f, c*a, x*a-c, nn-1, a) ) return true;
                ans.pop_back();
            }

            return false;
        };

        if(f(f,1,1,N,1)){
            cout << "Yes" << endl;
            for(ll ai:ans) cout << ai << " "; cout << endl;

            // assert(ans.size()==N);
            // ll p = 1;
            // for(ll ai:ans) p*=ai;
            // ll chk = p;
            // for(ll ai:ans) chk -= p/ai;
            // cout << chk << endl;


        }else{
            cout << "No" << endl;
        }




    }
};



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
