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
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
using point=array<ll,3>;

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

        vec(point) p(N);
        rep(i,N){
            ll x,y;
            cin >> x >> y;
            p[i] = {x,y,~i};
        }

        ll Q;
        cin >> Q;

        vec(point) q = p;
        rep(i,Q){
            ll a,b;
            cin >> a >> b;
            q.push_back({a,b,i});
        }

        sort(all(q));

        auto chk = [&](ll ii, point po){
            ll dx1,dx2,dy1,dy2;
            dx1 = p[ii][0] - po[0];
            dy1 = p[ii][1] - po[1];
            ll jj = (ii+1)%N;
            dx2 = p[jj][0] - po[0];
            dy2 = p[jj][1] - po[1];

            ll xp = dx1*dy2 - dy1*dx2;
            if(xp!=0) return (xp>0 ? 2 : 0);

            ll ip = dx1*dx2 + dy1*dy2;
            return (ip<=0 ? 1 : 0);
        };


        vec(string) ans(Q);

        ll ue=-1, sita=-1;
        for(auto qi:q ){
            if(qi[2]<0){
                ll idx = ~qi[2];
                if(ue==-1){
                    ue = idx;
                    sita = idx;
                }else{
                    if( (ue-1+N)%N == idx ) ue = idx;
                    if( (sita+1)%N == idx ) sita = idx;
                }
            }else{
                ll idx = qi[2];
                if(ue==-1){
                    ans[idx] = "OUT";                    
                }else{
                    ll g1 = chk((ue-1+N)%N, qi);
                    ll g2 = chk(sita, qi);
                    // cout << idx << " : " << g1 << " , " << g2 << endl;

                    if(g1==1 || g2==1) ans[idx] = "ON";
                    else if(g1==2 && g2==2) ans[idx] = "IN";
                    else ans[idx] = "OUT";
                }
            }
        }

        for(string ai:ans) cout << ai << endl;



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
