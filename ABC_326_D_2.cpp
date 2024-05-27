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
    string R,C;
    cin >> R;
    cin >> C;


    vec(ll) vr(N),vc(N);
    rep(i,N) vr[i] = R[i]-'A';
    rep(i,N) vc[i] = C[i]-'A';


    vvec(ll) rcand;
    rep(i,N)rep(j,N)rep(k,N){
        if(i==j || j==k || k==i) continue;
        rcand.push_back({i,j,k});
    }

    // cerr << rcand.size() << endl;
    // for(auto r:rcand){
    //     for(auto rr:r){
    //         cerr << rr << " ";
    //     }
    //     cerr << endl;
    // }


    vvec(ll) ans;

    vvec(bool) cused(N,vec(bool)(3));
    vvec(ll) vv(N,vec(ll)(N,-1));


    auto f = [&](auto f, ll rcnt)->void{

        if(rcnt==N){
            rep(i,N)rep(j,3) if(!cused[i][j]) return;

            rep(i,N){
                rep(j,N){
                    if(vv[i][j]==-1) continue;
                    if(vv[i][j]!=vr[i]) return;
                    break;
                }
            }

            rep(j,N){
                rep(i,N){
                    if(vv[i][j]==-1) continue;
                    if(vv[i][j]!=vc[j]) return;
                    break;
                }
            }

            ans = vv;
            return;
        }


        for(auto rr:rcand){
            bool isok=true;
            rep(i,3) if(cused[rr[i]][i]) isok=false;
            if(!isok) continue;

            rep(i,3) cused[rr[i]][i] = true;
            rep(i,3) vv[rcnt][rr[i]] = i;
            f(f,rcnt+1);
            rep(i,3) cused[rr[i]][i] = false;
            rep(i,3) vv[rcnt][rr[i]] = -1;
        }

    };


    f(f,0);

    if(ans.size()==0) sayno;
    cout << "Yes" << endl;
    rep(i,N){
        rep(j,N){
            if(ans[i][j]==-1) cout << ".";
            else cout << (char)('A'+ans[i][j]);
        }
        cout << endl;
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
