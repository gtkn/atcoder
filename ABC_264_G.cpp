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

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N;
        cin >> N;

        map<string,ll> m;

        vec(string) v(26);
        rep(i,26) v[i] = 'a'+i;

        rep(i,26) m[v[i]] = 0;
        rep(i,26)rep(j,26) m[ v[i]+v[j] ] = 0;
        rep(i,26)rep(j,26)rep(k,26) m[ v[i]+v[j]+v[k] ] = 0;
        rep(i,26)rep(j,26)rep(k,26) m[ v[i]+v[j]+v[k]+v[i] ] = 0;
        rep(i,26)rep(j,26)rep(k,26) m[ v[i]+v[j]+v[k]+v[i]+v[j] ] = 0;



        rep(i,N){
            string t;
            ll p;
            cin >> t >> p;
            m[t]=p;
        }


        rep(i,26)rep(j,26)rep(k,26){
            string s = v[i]+v[j]+v[k]+v[i]+v[j]+v[k];
        
            ll x = 0;
            rep(i,6){
                rep1(j,3){
                    if(i+j>6) break;
                    x += m[s.substr(i,j)];
                }
            }

            if(x>0){
                cout << "Infinity" << endl;
                return;
            }
        }
            

        ll ans = -llINF;
        for(auto mi:m){
            string s = mi.first;
            ll sn = s.size();

            ll x = 0;
            rep(i,sn){
                rep1(j,3){
                    if(i+j>sn) break;
                    x += m[s.substr(i,j)];
                }
            }
            chmax(ans,x);
        }
            
        cout << ans << endl;

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
