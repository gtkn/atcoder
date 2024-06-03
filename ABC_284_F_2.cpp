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
    string T;
    cin >> T;

    ll nn = 2*N;
    string R = T;
    reverse(all(R));


    if(T==R){
        cout << T.substr(0,N) << endl;
        cout << N << endl;
        return;
    }
    string A = T.substr(0,N);
    string B = T.substr(N,N);
    reverse(all(B));

    vec(int) zx = z_algorithm(A+B+".");
    vec(int) zy = z_algorithm(B+A+".");

    rep(i,N){
        if(zx[nn-i]==i && zy[N+i]==N-i){
            cout << T.substr(0,i) + T.substr(i+N,N-i) << endl;
            cout << i << endl;
            return;
        }
    }
    dame;




}



void solve2(){
    ll N;
    cin >> N;
    string T;
    cin >> T;

    ll nn = 2*N;
    string R = T;
    reverse(all(R));


    if(T==R){
        cout << T.substr(0,N) << endl;
        cout << N << endl;
        return;
    }


    vec(int) z0 = z_algorithm(T.substr(0,N)+"."+T.substr(N,N)+"."+R.substr(0,N)+"."+R.substr(N,N)+".");
    vec(int) z1 = z_algorithm(R.substr(0,N)+"."+R.substr(N,N)+"."+T.substr(0,N)+"."+T.substr(N,N)+".");

    // cerr << " ";
    // rep(i,2*nn+2) cerr << i%10 << " "; cerr << endl;
    // for(int zi:z0) cerr << zi << " "; cerr << endl;
    // for(int zi:z1) cerr << zi << " "; cerr << endl;



    for(ll i=nn+2; i<nn+2+N; ++i){
        ll a = z0[i];
        ll b = z1[nn+2+a];
        if(i+a!=nn+2+N) continue;
        if(nn+2+a+b!=nn+2+N) continue;;
        if(a+b==N){
            // string S = T.substr(0,a) + T.substr(a+N,b);
            // string S2 = T.substr(a,N);
            // reverse(all(S2));

            // if(S!=S2){
            //     rep(k,N){
            //         if(S[k]==S2[k]) continue;
            //         cerr << "error" << endl;
            //         cerr << S[k] << " " << S2[k] << endl;
            //         return;
            //     }
            // }

            // cerr << i << "!" <<i-nn-2<< endl;
            cout << T.substr(0,a) + T.substr(a+N,b) << endl;
            cout << a << endl;
            return;
        }
    }

    dame;




}





int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve2();
    }
    return 0;
}
