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
    vec(ll) A(N), B(N);
    rep(i,N) cin >> A[i] >> B[i];




    priority_queue<Pll> q0,q1;
    rep(i,N) q0.emplace(A[i]-B[i], i );
    // rep(i,N) cerr << A[i]-B[i] << ' ' << i << endl;

    ll bb = -llINF;
    vec(bool) used(N);


    vec(Pll) bv(N);
    rep(i,N) bv[i] = {B[i],i};

    sort(all(bv), greater<Pll>());

    ll res = 0;
    rep1(k,N){
        while(!q0.empty()){
            auto [d,i]  = q0.top();
            if(used[i]){
                q0.pop();
                q1.emplace(A[i],i);
            }else{
                break;
            }
        }

        Pll x0 = {-llINF,-1};
        if(!q0.empty()) x0 = q0.top();
        Pll x1 = {-llINF,-1};
        if(!q1.empty()) x1 = q1.top();
        
        if(bb>-llINF) x0.first += bb;

        if(x0.first > x1.first || x1.second==-1){
            res += x0.first;
            // cerr << "k=" << k << " " << x0.first << " " << x0.second << endl;
            chmax(bb, B[x0.second]);
            q0.pop();
        }else{
            
            res += x1.first;            
            // cerr << "k=" << k << " " << x1.first << " " << x1.second << endl;
            chmax(bb, B[x1.second]);
            q1.pop();
        }


        while(!bv.empty()){
            auto [b,i] = bv.back();
            if(b<=bb){
                bv.pop_back();
                used[i] = true;
            }else{
                break;
            }
        }


        cout << res << endl;


    }






    // rep1(k,N){
    //     ll tmp = -llINF;
    //     vec(ll) v;

    //     rep(ptn,(1<<N)){
    //         if(__builtin_popcount(ptn)!=k) continue;
    //         ll bmax = -llINF, tot = 0;
    //         rep(i,N){
    //             if(bit(ptn,i)==0) continue;
    //             chmax(bmax,B[i]);
    //             tot += A[i];
    //         }
    //         if(chmax(tmp,tot-bmax)){
    //             v.clear();
    //             rep(i,N) if(bit(ptn,i)) v.push_back(i);
    //         };
    //     }

    //     cerr << k << "---" << tmp << endl;
    //     for(auto i:v) cerr << i << ' '; cerr << endl;
    // }


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
