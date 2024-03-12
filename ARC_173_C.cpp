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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;

    vec(ll) P(N);
    rep(i,N) cin >> P[i];


    // // 乱数生成器を初期化
    // unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // std::default_random_engine generator(seed);

    // // 3以上100以下のランダムな整数Nを生成
    // std::uniform_int_distribution<int> distribution(3, 20);
    // ll N = distribution(generator);

    // // 長さNのベクターを生成し、1からNまでの順列で初期化
    // std::vector<ll> P(N);
    // std::iota(P.begin(), P.end(), 1); // iotaは連続する値でベクターを埋める

    // // ランダムにシャッフルしてランダムな順列を生成
    // std::shuffle(P.begin(), P.end(), generator);


    // for(ll pi:P) cout << pi << " "; cout << endl;


    rep(i,N){
        ll res = llINF;

        if(i==0 || i==N-1){
            if(i==N-1) reverse(all(P));
        
            ll cnt=0;
            for(ll j=1; j<N; j++){
                if(P[j]>P[0]) cnt++;
                else cnt--;
                if(j%2==0 && cnt!=0){
                    res = j+1;
                    break;
                }
            }
        }else if( (P[i-1]>P[i]) == (P[i+1]>P[i])  ){
            res = 3;
        }else{
            bool f;
            for(ll d=1; i+d<N; d++){
                ll j = i+d;
                if(d==1){
                    f = (P[i] < P[j]);
                    continue;
                }
                bool f2 = (P[i] < P[j]);
                if(f==f2){
                    chmin(res, d+1+(d&1));
                    break;
                }
                f = f2;
            }


            for(ll d=1; i-d>=0; d++){
                ll j = i-d;
                if(d==1){
                    f = (P[i] < P[j]);
                    continue;
                }
                bool f2 = (P[i] < P[j]);
                if(f==f2){
                    chmin(res, d+1+(d&1));
                    break;
                }
                f = f2;
            }

        }

        if(res>N) res = -1;
        cout << res << " ";
    }
    cout << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
