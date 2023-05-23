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

   

    void solve(){
        ll N;
        cin >> N;
        vec(ll) A(N);
        rep(i,N) cin >> A[i];
        rep(i,N) A[i]--;
        vec(ll) B = A;
        sort(all(B));

        vvec(ll) vv(4,vec(ll)(4));
        rep(i,N) vv[B[i]][A[i]]++;

        // rep(i,4){
        //     rep(j,4) cout << vv[i][j] << " "; cout << endl;
        // }

        ll ans = 0;
        rep(i,4) vv[i][i]=0;
        rep(i,4)rep(j,i){
            ll x = min(vv[i][j], vv[j][i]);
            ans += x;
            vv[i][j] -= x;
            vv[j][i] -= x;            
        }

        for(ll a=0; a<4; a++) for(ll b=a+1; b<4; b++)for(ll c=b+1; c<4; c++){
            vec(ll) v = {a,b,c};
            do{
                vec(ll) tmp=v; tmp.push_back(v[0]);
                ll x = llINF;
                rep(i,3) chmin(x, vv[tmp[i]][tmp[i+1]]);
                ans += 2*x;
                // if(x>0){
                //     cout << "x=" << x << endl;
                //     rep(i,3)cout << v[i] << " ";
                //     cout<<endl;
                // }
                rep(i,3) vv[tmp[i]][tmp[i+1]] -= x;
            }while(next_permutation(v.begin(),v.end()));//vは次の順列になる
        }

        vec(ll) v={0,1,2,3};
        do{
            ll x = llINF;
            vec(ll) tmp=v; tmp.push_back(v[0]);
            rep(i,4) chmin(x, vv[tmp[i]][tmp[i+1]]);
            ans += 3*x;
            rep(i,4) vv[tmp[i]][tmp[i+1]] -= x;
        }while(next_permutation(v.begin(),v.end()));//vは次の順列になる



        cout << ans << endl;
        // rep(i,4){
        //     rep(j,4) cout << vv[i][j] << " "; cout << endl;
        // }


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
