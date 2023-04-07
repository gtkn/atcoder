//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
        string S,T;
        cin >> S >> T;

        string x = "";
        rep(_,2) x+=S;
        rep(_,N) x+="a";
        rep(_,2) x+=T;
        rep(_,N) x+="z";

        vec(int) sa = suffix_array(x);        

        ll ans = 0, cnt = 0;
        for(int idx : sa){
            if(idx<N) cnt++;
            if(idx>=3*N && idx<4*N) ans += cnt;
        }

        cout << ans << endl;




        // vec(string) vs(N),vt(N);

        // rep(i,N){
        //     vs[i] = S;
        //     rotate(S.begin(), S.begin()+1, S.end());

        //     vt[i] = T;
        //     rotate(T.begin(), T.begin()+1, T.end());
        // }

        // sort(all(vs));
        // sort(all(vt));

        // ll ans = 0;
        // ll cnt=0;
        // rep(i,N){
        //     while(cnt<N && vs[cnt]<=vt[i]){
        //         // cout << vs[cnt] <<" , " << vt[i] << endl;
        //         cnt++;
        //     }
        //     ans += cnt;
        // }

        // cout << ans << endl;
        

        
        // set<string> se;
        // rep(i,N){
        //     se.insert(S);
        //     // cout << S << endl;
        //     rotate(S.begin(), S.begin()+1, S.end());
        // }

        // ll ans = 0;
        // rep(i,N){
        //     auto itr = se.lower_bound(T);
        //     ans += distance(se.begin(), itr);
        //     rotate(T.begin(), T.begin()+1, T.end());
        // }

        // cout << ans << endl;

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
