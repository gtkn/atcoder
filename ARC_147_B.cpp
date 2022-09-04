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

        vec(ll) P(N+1);
        rep1(i,N) cin >> P[i];

        vec(ll) R(N+1);
        rep1(i,N) R[P[i]] = i;


        vec(char) ab;
        vec(ll) v;

        rep1(i,N){
            if((P[i]+i)&1==0) continue;

            ll j = i;
            while((P[j]+i)&1==1) j++;

            while(j>i){
                //cout << i << " , " << j << endl;
                if(j-i>1){
                    swap(P[j],P[j-2]);
                    R[P[j]] = j;
                    R[P[j-2]] = j-2;
                    ab.push_back('B');
                    v.push_back(j-2);
                    j-=2;                            
                }else{
                    swap(P[j],P[j-1]);
                    R[P[j]] = j;
                    R[P[j-1]] = j-1;
                    ab.push_back('A');
                    v.push_back(j-1);
                    j-=1;
                }
            }
        }


        rep1(i,N){
            while(R[i]>i){
                ll j = R[i];
                swap(P[j],P[j-2]);
                R[P[j]] = j;
                R[P[j-2]] = j-2;
                ab.push_back('B');
                v.push_back(j-2);                                
            }
        }




        ll ans = v.size();
        cout << ans << endl;
        rep(i,ans) cout << ab[i] << " " << v[i] << endl;

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
