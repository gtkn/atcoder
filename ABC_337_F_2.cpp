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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){
    ll N,M,K;
    cin >> N >> M >> K;

    vec(ll) C(N);
    rep(i,N) cin >> C[i];
    rep(i,N) C[i]--;


    if(K==1){
        rep(_,N) cout << M << endl;
        return;
    }



    vec(ll) C2 = C;
    C2.insert(C2.end(),all(C));


    vec(ll) b(N); // 色iの個数
    for(ll ci:C) b[ci]++;

    ll r = 0;
    vec(ll) cnt(N); // 箱に入っている連続区間の中の色iの数
    ll mcnt = 0;

    while(r<N && mcnt<M){
        ll ci = C2[r];
        if(cnt[ci]%K==0) mcnt++;
        cnt[ci]++;
        r++;
    }


    auto f = [&](ll ii)->ll{
        ll nn = (cnt[ii]+K-1)/K; // 色iiが使っている箱の数
        return min(b[ii], nn*K);
    };


    ll res = 0;
    rep(i,N) res += f(i);


    vec(ll) ans;
    rep(l,N){
        ans.push_back(res);

        ll ci = C2[l];

        res -= f(ci);
        cnt[C2[l]]--;
        res += f(ci);

        if(cnt[ci]%K!=0) continue;
        
        while(r<N+l+1){
            ll cr = C2[r];
            r++;

            res -= f(cr);
            cnt[cr]++;
            res += f(cr);

            if(cnt[cr]%K==1) break;
        }
    }

    for(ll ai:ans) cout << ai << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
