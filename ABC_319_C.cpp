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
#define nodame { puts("No"); return;}
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
    vvec(ll) c(3,vec(ll)(3));
    rep(i,3)rep(j,3) cin >> c[i][j];

    // vec(ll) cv(9);
    // rep(i,9) cin >> cv[i];


    vec(ll) v;
    rep(i,9) v.push_back(i);
    ll num = 0;
    do{
        vvec(ll) now(3,vec(ll)(3,-1));
        for(ll vi:v){
            ll i,j;
            i = vi/3; j = vi%3;
            now[i][j] = c[i][j];

            ll a,b;
            a = now[(i+1)%3][j]; b = now[(i+2)%3][j];
            if(a!=-1 && a==b){
                num++;
                break;
            }

            a = now[i][(j+1)%3]; b = now[i][(j+2)%3];
            if(a!=-1 && a==b){
                num++;
                break;
            }

            if(i==j){
                a = now[(i+1)%3][(j+1)%3]; b = now[(i+2)%3][(j+2)%3];
                if(a!=-1 && a==b){
                    num++;
                    break;
                }
            }

            if((i+j)==2){
                a = now[(i+1)%3][(j+2)%3]; b = now[(i+2)%3][(j+1)%3];
                if(a!=-1 && a==b){
                    num++;
                    break;
                }
            }
        }
    }while(next_permutation(v.begin(),v.end()));//vは次の順列になる

    ll den = 1;
    rep1(i,9) den*=i;


    double ans = 1.*(den-num)/den;
    printf("%.9f\r\n",ans);


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
