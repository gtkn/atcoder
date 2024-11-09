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
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


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


constexpr double TIME_LIMIT = 1.9;

// randのシードを固定
constexpr int Seed = 42;
mt19937 rng(Seed);




// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}




// 時間を管理するクラス
class Timer{
private:
    chrono::system_clock::time_point start;
    // 制限時間
    double limit;

public:
    // コンストラクタ
    Timer(double limit=TIME_LIMIT):limit(limit){
        start = chrono::system_clock::now();
    }

    // 経過時間を返す関数
    double elapsed(){
        chrono::system_clock::time_point now = chrono::system_clock::now();
        chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(now-start);
        return (double)ms.count();
    }

    // 経過割合を返す関数
    double elapsed_proportion(){
        return elapsed() / limit / 1000;
    }


    // 制限時間を過ぎたかどうかを判定する関数
    bool is_timeup(){
        return elapsed() > limit*1000;
    }

    // 経過時間を表示する関数
    void show(){
        cerr << "Time: " << elapsed() << "ms" << endl;
    }
};

Timer global_timer;




//---素因数分解------
vec(ll) prime_factor(ll n) {
    vec(ll) res;
    if(n%4==0) res.push_back(4);
    while(n%2==0){
        n /= 2;
    }
    for(ll f=3; f*f<=n; ++f){
        if(n%f == 0){
            res.push_back(f);
            while(n%f == 0){
                n /= f;
            }
        }
    }
    if(n!=1) res.push_back(n);
    return res;
}
void solve(){
    ll N;
    cin >> N;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    sort(all(A));

    ll th = N/2;






    auto chk = [&](ll m)->bool{
        if(m<=2) return false;
        map<ll,ll> cnt;
        for(ll ai:A) cnt[ai%m]++;
        for(auto [k,v]:cnt){
            if(v>th){
                // cerr << k << ' ' << v << endl;
                return true;
            }
        }
        return false;
    };


    set<ll> used;
    while(!global_timer.is_timeup()){
        ll ii = RandInt(0,N-2);
        ll jj = RandInt(ii+1,N-1);

        ll diff = abs(A[ii]-A[jj]);
        vec(ll) pf = prime_factor(diff);
        for(ll p:pf){
            if(used.count(p)) continue;
            if(chk(p)){
                cout << p << endl;
                return;
            }
        }
    }

    dame;













    // vec(ll) d;
    // rep(i,N)rep(j,i){
    //     d.push_back(A[i]-A[j]);
    // }

    // set<ll> st;
    // while(!d.empty()){
    //     ll x = d.back(); d.pop_back();
    //     vec(ll) pf = prime_factor(x);
    //     for(ll p:pf) st.insert(p);

    //     vec(ll) d2;
    //     for(ll y:d){
    //         for(ll p:pf){
    //             while(y%p==0) y /= p;
    //         }
    //         if(y!=1) d2.push_back(y);
    //     }
    //     d = d2;
    // }


    // for(ll p:st){
    //     if(chk(p)){
    //         cout << p << endl;
    //         // cerr << chk(p) << endl;
    //         return;
    //     }
    // }
    // dame;



    // for(ll i = th; i<N; i++){
    //     map<ll,ll> cnt;
    //     rep(j,i){
    //         vec(ll) pf = prime_factor(A[i]-A[j]);
    //         for(ll p:pf) cnt[p]++;
    //     }
    //     for(auto [k,v]:cnt){
    //         if(k>=3 && v+1>=th){
    //             cout << k << endl;
    //             // cerr << chk(k) << endl;
    //             return;
    //         }
    //     }
    // }
    // dame;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
