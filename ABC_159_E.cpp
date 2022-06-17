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
        ll H,W,K;
        cin >> H >> W >> K;

        vvec(ll) vv(H);
        rep(i,H){
            string s; cin >> s;
            for(char si:s) vv[i].push_back(si-'0');
        }


        ll ans = llINF;

        rep(s,(1<<(H-1))){
            ll res = 0;
            ll gn=0;
            vec(ll) v(H),m(H);
            ll chk=0;
            bool ff=false;
            rep(i,H){
                m[i]=gn;
                chk += vv[i][0];
                if(chk>K) ff=true;
                if(bit(s,i)){
                    gn++;
                    chk=0;
                }
            }
            if(ff) continue;
            res+=gn;

            rep(j,W){
                vec(ll) dv(H);
                rep(i,H){
                    dv[m[i]] += vv[i][j];
                }
                bool f=false;
                rep(i,H) if(v[i]+dv[i]>K) f=true;

                if(f) rep(i,H) v[i]=0;
                rep(i,H) v[i]+=dv[i];
                if(f) res++;
            }
            chmin(ans,res);
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
