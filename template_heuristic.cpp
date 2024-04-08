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

constexpr double TIME_LIMIT = 2.9;

// randのシードを固定
constexpr int Seed = 42;
mt19937 rng(Seed);




// 0.以上1.未満の整数をランダムに返す関数
double Randdouble(){
    return 1. * rand() / RAND_MAX;
}

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






// 座標を持つ構造体
struct Coordinate
{
    ll h,w;
    Coordinate(ll h=0, ll w=0):h(h),w(w){}
};





class Solver{
private:



public:
    Solver(){
        // 初期化
    }

    // ansを出力する関数
    void output(bool is_calc_cost=true){
        cerr << "=== Output ===" << endl;
        cerr << "=== End ===" << endl;
        if(is_calc_cost){
            ll score = 0;
            cerr << "Score = " << score << endl;
        }
    }


    // 適当な解答を出力する関数、幅固定で区切る
    void solve_sample(){
    }

};



int main(){
    ll N;
    cin >> N;

    Solver solver;
    solver.solve_sample();

    solver.output(true);


    return 0;
}
