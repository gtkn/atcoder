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
    string TT;
    cin >> TT;

    vec(string) S(N);
    rep(i,N) cin >> S[i];


    auto f0 = [](const string& t, const string& tt){
        return t==tt;
    };

    auto f1 = [](const string& t, const string& tt){
        ll n = t.size();
        ll nn = tt.size();
        if(n+1 != nn) return false;

        ll c0=0,c1=0;
        rep(i,n){
            if(t[i]==tt[i]){
                c0++;
            }else{
                break;
            }
        }

        rep(i,n){
            if(t[n-1-i]==tt[nn-1-i]){
                c1++;
            }else{
                break;
            }
        }

        return (c0+c1 >= n);
    };

    auto f2 = [](const string& t, const string& tt){
        ll n = t.size();
        ll nn = tt.size();
        if(n-1 != nn) return false;

        ll c0=0,c1=0;
        rep(i,n){
            if(t[i]==tt[i]){
                c0++;
            }else{
                break;
            }
        }

        rep(i,n){
            if(t[n-1-i]==tt[nn-1-i]){
                c1++;
            }else{
                break;
            }
        }

        return (c0+c1 >= nn);
    };

    auto f3 = [](const string& t, const string& tt){
        ll n = t.size();
        ll nn = tt.size();
        if(n != nn) return false;

        ll c0=0,c1=0;
        rep(i,n){
            if(t[i]==tt[i]){
                c0++;
            }else{
                break;
            }
        }

        rep(i,n){
            if(t[n-1-i]==tt[nn-1-i]){
                c1++;
            }else{
                break;
            }
        }

        return (c0+c1 >= n-1);
    };


    vec(ll) ans;
    rep(i,N){
        if(f0(S[i],TT)){
            ans.push_back(i);
        }else if(f1(S[i],TT)){
            ans.push_back(i);
        }else if(f2(S[i],TT)){
            ans.push_back(i);
        }else if(f3(S[i],TT)){
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    string ansstr = "";
    for(ll a:ans){
        ansstr += to_string(a+1) + " ";
    }
    if(ansstr.size()>0) ansstr.pop_back();
    cout << ansstr << endl;

    

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
