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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------



void solve(){
    ll N;
    cin >> N;

    vec(ll) t(N),x(N);
    rep(i,N) cin >> t[i]>> x[i];

    vvec(ll) vv(N+1);
    rep(i,N)if(t[i]==1) vv[x[i]].push_back(i);

    vec(ll) ans(N,-1);


    repr(i,N){
        if(t[i]==1) continue;

        ll xi = x[i];
        while(!vv[xi].empty() && vv[xi].back() > i ){
            vv[xi].pop_back();
        }
        
        if(vv[xi].empty()){
            // cerr << i << "!!" << endl;
            dame;
        }

        ans[vv[xi].back()] = 1;
        vv[xi].pop_back();

    }


    ll kmin = 0, k=0;
    vec(ll) cnt(N+1);
    rep(i,N){
        if(t[i]==1){
            if(ans[i]==1){
                cnt[ x[i] ]++;
                k++;
            }else{
                ans[i] = 0;
            }
        }
        if(t[i]==2){
            assert(cnt[x[i]]>0);
            cnt[x[i]]--;
            k--;
        }
        chmax(kmin,k);
    }

    cout << kmin << endl;
    for(ll ai:ans){
        if(ai==-1) continue;
        cout << ai << " ";
    }
    cout << endl;



    // rep(i,N){
    //     if(t[i]==1) cout << x[i] << "    " << ans[i] << endl;
    //     else cout << "    " << x[i] << endl;
    // }


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
