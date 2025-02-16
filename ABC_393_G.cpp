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
    
    


void solve(){
    ll N,P,Q;
    cin >> N >> P >> Q;
    vvec(ll) A(N,vec(ll)(N));
    rep(i,N) rep(j,N) cin >> A[i][j];

    rep(i,N)rep(j,N) A[i][j] *= Q;

    {
        vec(ll) v;
        rep(i,N)rep(j,N) v.push_back(A[i][j]);
        sort(all(v));
        ll mid = v[N*N/2];
        ll diff = 0;
        rep(i,N)rep(j,N) diff += abs(A[i][j]-mid);
        if(diff<=P){
            double ans = 1.*diff/Q;
            printf("%.10f\n",ans);
            rep(i,N){
                rep(j,N) cout << 1.*mid/Q << ' '; cout << endl;
            }
            return;
        }
    }

    vvec(ll) B = A;
    vvec(ll) best_B = B;
    ll diff = 0;
    ll U = 0;
    rep(i,N)rep(j,N-1) U += abs(A[i][j]-A[i][j+1]);
    rep(i,N-1)rep(j,N) U += abs(A[i][j]-A[i+1][j]);
    ll best_U = llINF;

    auto isok = [&](ll i,ll j, ll d)->bool{
        if(i<0||N<=i||j<0||N<=j) return false;
        ll new_diff = diff;
        new_diff -= abs(A[i][j]-B[i][j]);
        new_diff += abs(A[i][j]-B[i][j]-d);
        if(new_diff > P) return false;
        return true;
    };

    double start_temp = 0.5;
    double end_temp = 0.01;
    double temp = start_temp;

    while(!global_timer.is_timeup()){
        double elapsed_proportion = global_timer.elapsed_proportion();
        temp = start_temp * pow(end_temp / start_temp, elapsed_proportion);

        ll i = rand()%N;
        ll j = rand()%N;
        ll d = rand() % (2 * P + 1) - P;

        if(!isok(i,j,d)) continue;

        ll new_U = U;
        if(j+1<N) new_U -= abs(B[i][j]-B[i][j+1]);
        if(j-1>=0) new_U -= abs(B[i][j]-B[i][j-1]);
        if(i+1<N) new_U -= abs(B[i][j]-B[i+1][j]);
        if(i-1>=0) new_U -= abs(B[i][j]-B[i-1][j]);
        if(j+1<N) new_U += abs(B[i][j]+d-B[i][j+1]);
        if(j-1>=0) new_U += abs(B[i][j]+d-B[i][j-1]);
        if(i+1<N) new_U += abs(B[i][j]+d-B[i+1][j]);
        if(i-1>=0) new_U += abs(B[i][j]+d-B[i-1][j]);

        double delta_U = new_U - U;
        if(delta_U < 0 || exp(-delta_U / temp) > (double)rand() / RAND_MAX){
            best_U = new_U;
            diff -= abs(A[i][j]-B[i][j]);
            diff += abs(A[i][j]-B[i][j]-d);
            U = new_U;
            B[i][j] += d;
            best_B = B;
        }        
    }

    double ans = 1.*best_U/Q;
    printf("%.10f\n",ans);
    rep(i,N){
        rep(j,N) cout << 1.*best_B[i][j]/Q << ' '; cout << endl;
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
