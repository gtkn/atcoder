//title
//#define _GLIBCXX_DEBUG
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

random_device seed_gen;
mt19937 engine(seed_gen());

// 0.以上1.未満の整数をランダムに返す関数
double Randdouble(){
    return 1. * rand() / RAND_MAX;
}

// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}

// setからランダムに値を得る
ll random_set(set<ll> &s){
    auto it = s.cbegin();
    int random = rand() % s.size();
    advance(it, random);
    return *it;
}



//---------------------
int main(){
    // 定数
    ll TIMELIMIT = 0.95 * CLOCKS_PER_SEC;
    ll start_time = clock();





    // 読み込み
    ll N,K,L;
    cin >> N >> K >> L;

    vec(ll) A(K+1),B(K+1);
    rep1(i,K) cin >> A[i] >> B[i];

    vvec(ll) C(N,vec(ll)(N));
    rep(i,N)rep(j,N) cin >> C[i][j];


    // その他変数
    ll pmax=0,pmin=llINF,qmax=0,qmin=llINF;
    double pave=0., qave=0.;

    vec(ll) pvec(L+1),qvec(L+1);
    vec(ll) ans(K+1), ans_tmp(K+1);
    vec(set<ll>) rev_ans(L+1);
    vvec(set<ll>) vvs(L+1,vec(set<ll>)(L+1));


    vector<set<ll>> g(K+1);
    vvec(bool) gvv(K+1,vec(bool)(K+1)); // 地区の隣接グラフgの行列表現


    // 隣接する地区リスト
    rep(i,N)rep(j,N){
        ll now = C[i][j];
        if(now==0) continue;
        if(i<N-1){
            ll to = C[i+1][j];
            if(now!=to && to!=0) g[now].insert(to); g[to].insert(now);
        }
        if(j<N-1){
            ll to = C[i][j+1];
            if(now!=to && to!=0) g[now].insert(to); g[to].insert(now);
        }
    }

    rep1(i,K) for(ll j:g[i]) gvv[i][j]=true;


    // P,Qの平均に近いほうが良いはず
    pave = 0.;
    qave = 0.;
    rep1(i,K) pave += A[i];
    rep1(i,K) qave += B[i];    
    pave /= (ll)L;
    qave /= (ll)L;
    

















    return 0;
}
