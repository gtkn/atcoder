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
// using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


const ll MOD = 998244353;

void solve(){
    ll N,Q;
    cin >> N >> Q;
    vec(ll) A(N+1);
    rep1(i,N) cin >> A[i];

    vec(ll) B(N+1),C(N+1),D(N+1);


    auto update = [&]()->void{
        rep1(i,N){
            B[i] = B[i-1] + A[i];
            if(B[i]>=MOD) B[i] -= MOD;
        }
        rep1(i,N){
            C[i] = C[i-1] + B[i];
            if(C[i]>=MOD) C[i] -= MOD;
        }
        rep1(i,N){
            D[i] = D[i-1] + C[i];
            if(D[i]>=MOD) D[i] -= MOD;
        }
    };


    update();
    // rep1(i,N) cerr << D[i].val() << endl;


    vec(Pll) memo(N);
    ll tail=0;
    ll th = sqrt(N);
    vec(ll) A2 = A;
    while(Q--){
        ll t; cin >> t;
        if(t==1){
            ll x,v;
            cin >> x >> v;
            // memo.push_back({x,v});
            memo[tail++] = {x,v};
            A2[x] = v;
        }else{
            ll x;
            cin >> x;
            ll res = D[x];
            rep(i,tail){
                auto [pos,val] = memo[i];
                if(A2[pos] != val) continue;
                if(pos>x) continue;
                res += MOD + (A2[pos] - A[pos]) * ( ((x-pos+1) * (x-pos+2)/2 )%MOD ) %MOD;
                // res += ( (A2[pos] - A[pos])%MOD ) * ((x-pos+1) * (x-pos+2)/2 )%MOD;
                // res = mod(res,MOD); 
            }
            cout << res%MOD << nl;
        }

        if(tail>=th){
            // A = A2;
            rep(i,tail) A[memo[i].first] = memo[i].second;
            update();
            // memo.clear();
            tail=0;
        }
    }





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
