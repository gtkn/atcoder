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


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("0"); return;}
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
    vec(ll) A(N);
    rep(i,N) cin >> A[i];
    rep(i,N) A[i]--;


    vvec(ll) vv(N);
    vec(bool) used_num(N);
    vec(bool) used_pos(N);

    rep(i,N){
        if(A[i]==i){
            ll n = vv[i].size();
            vv[i].push_back(i);
            rep1(j,n){
                if(used_num[vv[i][j]]) dame;
                used_pos[vv[i][j-1]] = true;
                used_num[vv[i][j]] = true;
            }            
            vv[i].clear();
        }
        if(A[i]>i){
            vv[A[i]].push_back(i);
        }
        if(A[i] < i){
            dame;
        }
    }
    rep(i,N) if(!vv[i].empty()) dame;


    priority_queue<ll,vec(ll),greater<ll>> pq;
    rep(i,N) if(!used_num[i]) pq.push(i);


    ll cnt = 0;
    mint ans = 1;

    rep(i,N){
        if(used_pos[i]){            
            continue;
        }
        while(!pq.empty() && pq.top() <= i){
            pq.pop();
            cnt++;
        }
        if(cnt<=0) dame;
        ans *= cnt;
        cnt--;
    }
    if(cnt>0) dame;

    cout << ans.val() << endl;  



    // vec(ll) B(N);
    // rep(i,N) B[i] = i;

    // vec(ll) perm(N);
    // rep(i,N) perm[i] = i;

    // auto f = [&](const vec(ll) &p)->bool{
    //     vec(ll) v = B;
    //     while(1){
    //         bool isok = true;
    //         rep(i,N){
    //             if(v[i] < p[v[i]]){
    //                 v[i] = p[v[i]];
    //                 isok = false;
    //                 break;
    //             }            
    //         }
    //         if(isok) break;
    //     }
    //     rep(i,N) if(A[i] != v[i]) return false;
    //     return true;
    // };

    // ll ans2 = 0;
    // do{
    //     if(f(perm)){
    //         ans2++;
    //         rep(i,N) cerr << perm[i]+1 << " "; cerr << endl;
    //     }
    // }while(next_permutation(all(perm)));

    // cout << ans2 << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
