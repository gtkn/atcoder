//title
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)
#define repr(i,n) for (int i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (int i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk bit目
#define vec(T) vector<T>
#define vvec(T) vector<vector<T>>
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

//------------------------------------------------

struct Solver{
 
    void solve(){
        ll N,L;
        cin >> N >> L;

        vvec(ll) vv(N);
        rep(i,N){
            string s;
            cin >> s;
            for(char si:s) vv[i].push_back(si-'a');
        }


        vec(mint) mp(27);
        rep(i,27) mp[i] = mint(i).pow(L);


        mint ans = 0;
        rep(i,(1<<N)){
            if(i==0) continue;
            ll nn = __builtin_popcount(i);
            vec(ll) v(26);
            rep(j,N){
                if(bit(i,j)) for(ll k:vv[j]) v[k]++;
            }
            ll cnt=0;
            for(ll vi:v) if(vi==nn) cnt++;
            if(nn%2==1) ans += mp[cnt];
            else ans -= mp[cnt];
            //cout << i << " : " << nn << "," << cnt << endl;
        }

        cout << ans.val() << endl;



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
