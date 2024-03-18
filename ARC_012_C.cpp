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
#define sayno { puts("NO"); return;}
#define sayyes { puts("YES"); return;}
#define sayyn {puts("YES");}else{puts("NO");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

vec(Pll) d = { {1,0},{0,1},{1,1},{1,-1} };



void solve(){
    ll N = 19;
    vec(string) b(N);
    rep(i,N) cin >> b[i];

    ll bcnt=0, wcnt=0;
    rep(i,N)rep(j,N){
        if(b[i][j]=='o') bcnt++;
        if(b[i][j]=='x') wcnt++;
    }


    auto f = [](ll N, vec(string) const& b)->bool{

        rep(i,N)rep(j,N){
            if(b[i][j]=='.') continue;
            char now = b[i][j];

            for(auto [di,dj]:d){
                bool is5 = true;
                rep(k,5){
                    ll ii = i+di*k, jj = j+dj*k;
                    if(ii<0 || ii>=N || jj<0 || jj>=N){
                        is5=false;
                        break;
                    }
                    if(b[ii][jj]!=now){
                        is5=false;
                        break;
                    }
                }
                if(is5){
                    return false;
                }
            }            
        }
        return true;

    };



    if(bcnt==0 && wcnt==0){
        sayyes;
    }else if(bcnt==wcnt){
        string ans = "NO";
        rep(i,N)rep(j,N){
            if(b[i][j]!='x') continue;
            b[i][j]='.';
            if(f(N,b)) ans = "YES";
            b[i][j]='x';            
        }
        cout << ans << endl;
        return;
    }else if(bcnt==wcnt+1){
        string ans = "NO";
        rep(i,N)rep(j,N){
            if(b[i][j]!='o') continue;
            b[i][j]='.';
            if(f(N,b)) ans = "YES";
            b[i][j]='o';
        }
        cout << ans << endl;
        return;
    }else{
        sayno;
    }





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
