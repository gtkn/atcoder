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
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------



void solve(){
    ll N,K;
    cin >> N >> K;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    ll nn = 200020;
    vvec(ll) memo(nn);
    rep(x,2){
        rep(i,N) memo[ A[i] ].push_back(x*N + i);
    }

    ll m = 61;
    vvec(ll) db(N,vec(ll)(m,llINF));

    for(const vec(ll) &v : memo){
        rep(i, v.size()){
            if(v[i]>=N) break;
            db[ v[i] ][0] = v[i+1]-v[i]+1;
        }
    }

    // cout << "ok?" << endl;
    // rep(i,N) cout << db[i][0] << " "; cout  << endl;

    rep(j,m-1){
        rep(i,N){
            db[i][j+1] = min(db[i][j] + db[(i+db[i][j])%N][j],llINF);
        }
    }

    ll a = 0, th = N*K;
    repr(j,m){
        if(a+db[a%N][j] < th){
            a = a + db[a%N][j];
        }
    }

    // cout << a << endl;
    // rep(j,4){
    //     rep(i,N) cout << db[i][j] << " "; cout  << endl;
    // }



    vec(ll) res;
    vec(bool) used(nn);
    for(ll i = a%N; i<N; i++){
        if(used[A[i]]){
            while(res.back()!=A[i]){
                used[res.back()] = false;
                res.pop_back();
            }
            used[res.back()] = false;
            res.pop_back();
        }else{
            res.push_back(A[i]);
            used[A[i]] = true;
        }
    }

    for(ll x:res) cout << x << " "; cout << endl;

    


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
