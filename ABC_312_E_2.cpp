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

    ll nn = 100;

    vec(ll) X1(N),X2(N),Y1(N),Y2(N),Z1(N),Z2(N);
    rep(i,N) cin >> X1[i] >> Y1[i] >> Z1[i] >> X2[i] >> Y2[i] >> Z2[i];


    vec(ll) ans(N);
    rep(_,3){
        vvec(ll) l(nn+1),r(nn+1);
        rep(i,N){
            l[X1[i]].push_back(i);
            r[X2[i]].push_back(i);
        }

        vvec(ll) vv(nn+1,vec(ll)(nn+1,-1));
        rep(x,nn+1){
            for(ll i:r[x]){
                for(ll y=Y1[i];y<Y2[i];++y){
                    for(ll z=Z1[i];z<Z2[i];++z){
                        vv[y][z]=i;
                    }
                }
            }
            for(ll i:l[x]){
                set<ll> st;
                for(ll y=Y1[i];y<Y2[i];++y){
                    for(ll z=Z1[i];z<Z2[i];++z){
                        if(vv[y][z]!=-1){
                            st.insert(vv[y][z]);
                        }
                    }
                }
                ans[i]+=st.size();
                for(ll j:st) ans[j]++;
            }
            for(ll i:r[x]){
                for(ll y=Y1[i];y<Y2[i];++y){
                    for(ll z=Z1[i];z<Z2[i];++z){
                        vv[y][z]=-1;
                    }
                }
            }
        }

        // rep(i,N) cerr << ans[i] << " "; cerr << endl;

        swap(X1,Y1);
        swap(X2,Y2);
        swap(Y1,Z1);
        swap(Y2,Z2);
    }

    rep(i,N) cout << ans[i] << endl;
        



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
