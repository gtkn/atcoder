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
        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        ll tot = 0;
        rep(i,N) tot += A[i];

        ll nn = N*(N+1)/2;

        if(tot%N>0 && (tot+nn)%N>0 ){
            cout << "No" << endl;
            return;
        }

        vvec(ll) ans;
        ll amax=-llINF, amin=llINF;
        ll imax=-1, imin=-1;

        if(tot%N>0){
            vec(ll) v0(N);
            rep(i,N) v0[i]=i+1;
            rep(i,N) A[i]+=v0[i];
            ans.push_back(v0);
        }



        auto update = [&](){
            amax = -llINF; amin=llINF;
            rep(i,N) if(chmax(amax,A[i])) imax = i;
            rep(i,N) if(chmin(amin,A[i])) imin = i;
        };


        update();

        while(amax!=amin){
            vec(ll) v1(N),v2(N);
            ll cnt = 1;
            rep(i,N){
                if(i==imax) v1[i]=N-1;
                else if(i==imin) v1[i]=N;
                else v1[i] = cnt++;
            }

            cnt = N;
            rep(i,N){
                if(i==imax) v2[i]=1;
                else if(i==imin) v2[i]=2;
                else v2[i] = cnt--;
            }

            ans.push_back(v1);
            ans.push_back(v2);

            A[imax]--;
            A[imin]++;

            update();
        }

        ll M = ans.size();

        cout << "Yes" << endl;
        cout << M << endl;
        rep(i,M){
            rep(j,N) cout << ans[i][j] << " "; cout << endl;
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
