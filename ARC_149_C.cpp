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


        vvec(ll) vv(N,vec(ll)(N));

        vvec(ll) a(3),b(3);
        rep1(i,N*N){
            if(i==1 || i==2 || i==7 || i==8) continue;
            if(i&1) a[i%3].push_back(i);
            else b[i%3].push_back(i);
        }

        ll jj = N/2;
        bool f=false;
        rep(i,N){
            if(i==jj-1 && !f){
                vv[i][jj-1]=1;
                vv[i][jj]=8;
                if(N&1) jj++;
                vv[i+1][jj-1]=7;
                vv[i+1][jj]=2;
                f=true;
                continue;
            }
            if(f){
                f=false;
                continue;
            }

            rep(k,3){
                if(a[k].empty() || b[k].empty()) continue;
                vv[i][jj-1] = a[k].back();
                a[k].pop_back();
                vv[i][jj] = b[k].back();
                b[k].pop_back();
                break;
            }
        }
        vec(ll) aa,bb;
        rep(k,3) for(ll vi:a[k]) aa.push_back(vi);
        rep(k,3) for(ll vi:b[k]) bb.push_back(vi);

        rep(i,N)rep(j,N){
            if(vv[i][j]>0) continue;
            if(j<jj){
                vv[i][j] = aa.back();
                aa.pop_back();
            }else{
                vv[i][j] = bb.back();
                bb.pop_back();
            }
        }


        rep(i,N){
            rep(j,N) cout << vv[i][j] << " ";
            cout << endl;
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
