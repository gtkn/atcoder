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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

void doubling(vvec(ll) &db, ll xx){
    // 0列目まで埋めたダブリングの配列の残りを計算する
    // 遷移先がない場合はxx
    ll n,m;
    n = db.size();
    m = db[0].size();

    rep(j,m-1)rep(i,n){
        if(db[i][j]==xx){
            db[i][j+1] = xx;
        }else{
            db[i][j+1] = db[ db[i][j] ][j];
        }
    }
}


void solve(){
    ll N,M,Q;
    cin >> N >> M >> Q;

    vec(ll) A(M),B(M),S(M),T(M);
    vvec(Pll) vv(N);
    rep(i,M){
        cin >> A[i] >> B[i] >> S[i] >> T[i];
        --A[i]; --B[i];
        vv[A[i]].emplace_back(S[i],i);
    }

    rep(i,N) sort(all(vv[i]));
    // rep(i,N){
    //     cerr << i << " ; ";
    //     for(auto [s,_]:vv[i]) cerr << s << " "; cerr << endl;
    // }

    ll rm = sqrt(M)+10;
    vvec(ll) db(M,vec(ll)(rm,-1));
    rep(i,M){
        auto itr = lower_bound(all(vv[B[i]]),Pll(T[i],0) );
        if(itr != vv[B[i]].end()){
            db[i][0] = itr->second;
        }
    }


    doubling(db,-1);

    // rep(i,M){
    //     rep(j,rm) cerr << db[i][j] << " "; cerr << endl;
    // }
    // cerr << "--" << endl;



    auto f = [&](ll st,ll th)->ll{
        ll now = st;
        repr(j,rm){
            if(db[now][j] == -1) continue;
            ll nxt = db[now][j];
            if(S[nxt] >= th) continue;
            now = nxt;
        }
        return now;
    };


    while(Q--){
        ll x,y,z;
        cin >> x >> y >> z;
        --y;

        auto itr = lower_bound(all(vv[y]),Pll(x,0) );
        if(itr == vv[y].end()){
            cout << y+1 << nl;
            continue;
        }

        ll b0 = itr->second;
        if(S[b0] >= z){
            cout << y+1 << endl;
            continue;
        }

        ll b = f(b0, z);
        // cerr << "b : " << b << endl;
        if(T[b] >= z){
            cout << A[b]+1 << " " << B[b]+1 << endl;
        }else{
            cout << B[b]+1 << endl;
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
