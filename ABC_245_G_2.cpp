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



struct twomin{
    Pll p1,p2; // {value, index}, p1.first >= p2.first
    twomin(Pll p1={llINF,-1}, Pll p2={llINF,-1}):p1(p1),p2(p2){};

    bool add(Pll p){
        bool res = false;
        
        if(p1.second == p.second){
            res = chmin(p1.first,p.first);
        }else if(p2.second == p.second){
            res = chmin(p2.first,p.first);
        }else{        
            if(p2.first >= p.first){
                swap(p2,p);
                res = true;
            }
        }
        if(p1.first >= p2.first){
            swap(p2,p1);
        }
        return res;
    }

    void show(){
        cerr << p1.first << ", " << p1.second << " / " << p2.first << ", " << p2.second << endl;
    }
};


void solve(){
    ll N,M,K,L;
    cin >> N >> M >> K >> L;
    vec(ll) A(N),B(L);
    rep(i,N) cin >> A[i];
    rep(i,L) cin >> B[i];
    rep(i,N) A[i]--;
    rep(i,L) B[i]--;

    vec(ll) U(M),V(M),C(M);
    vvec(Pll) g(N);
    rep(i,M){
        cin >> U[i] >> V[i] >> C[i];
        U[i]--; V[i]--;
        g[U[i]].push_back({V[i],C[i]});
        g[V[i]].push_back({U[i],C[i]});
    }

    vec(ll) d1(N,-1),d2(N,-1),c1(N,-1);

    priority_queue<tri, vec(tri), greater<tri>> pq;
    for(ll b:B) pq.emplace(0,A[b],b);

    while(!pq.empty()){
        auto [dist,frm,now] = pq.top();
        pq.pop();

        if(d1[now] == -1){
            d1[now] = dist;
            c1[now] = frm;
        }else if (d2[now] == -1 && c1[now] != frm){
            d2[now] = dist;
        }else{
            continue;
        }


        for(auto [nxt,c]:g[now]){
            pq.emplace(dist+c,frm,nxt);
        }
    }

    vec(ll) ans(N,-1);
    rep(i,N){
        if(c1[i] != A[i]) ans[i] = d1[i];
        else ans[i] = d2[i];
    }
    rep(i,N) cout << ans[i] << " "; cout << endl;






    // vec(twomin) dp(N);
    // priority_queue<tri, vec(tri), greater<tri>> pq;
    // auto push = [&](ll dist, ll frm, ll pos){
    //     if(dp[pos].add({dist,frm})){
    //         pq.push({dist,frm,pos});
    //     }
    // };  
    // for(ll b:B){
    //     push(0,A[b],b);
    // }

    // // rep(i,N) dp[i].show();
    

    // while(!pq.empty()){
    //     auto [dist,frm,now] = pq.top();
    //     pq.pop();
        
    //     if(dp[now].p1.second == frm){
    //         if(dp[now].p1.first < dist) continue;
    //     }        
    //     if(dp[now].p2.first < dist) continue;
    //     for(auto [nxt,c]:g[now]){
    //         push(dist+c,frm,nxt);
    //     }
    // }

    // vec(ll) ans(N,llINF);
    // rep(i,N){
    //     if(dp[i].p1.second != A[i]) chmin(ans[i], dp[i].p1.first);
    //     if(dp[i].p2.second != A[i]) chmin(ans[i], dp[i].p2.first);
    //     if(ans[i]>=llINF) ans[i] = -1;
    // }
    // rep(i,N) cout << ans[i] << " "; cout << endl;








}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
