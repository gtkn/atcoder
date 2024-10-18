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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    string S,T;
    cin >> S >> T;

    ll K;
    cin >> K;

    vec(char) C(K);
    vec(string) A(K);
    rep(i,K) cin >> C[i] >> A[i];

    ll sn = S.size(), tn = T.size();

    ll N = 51;
    ll M = 26;


    vec(ll) len(K);
    rep(i,K) len[i] = A[i].size();

    vvec(ll) e(M);
    rep(i,K){
        if(len[i]==1){
            e[A[i][0]-'a'].push_back(C[i]-'a');
        }
    }

    vec(ll) esz(M);
    rep(i,M) esz[i] = e[i].size();


    vvvec(ll) dp1(N,vvec(ll)(N,vec(ll)(M,llINF)));
    vvvec(ll) dp2(N,vvec(ll)(N,vec(ll)(N)));

    priority_queue<Pll> pq;

    repr(i,tn){
        for(ll j=i; j<tn; ++j){
            rep(ii,K)rep(jj,len[ii]){
                dp2[j][ii][jj] = llINF;
            }
        }
        for(ll j=i; j<tn; ++j){
            if(j==i){
                dp1[i][j][T[j]-'a'] = 0;
                pq.emplace(0,T[j]-'a');
            }else{
                rep(ii,K){
                    for(ll jj=1; jj<len[ii]; ++jj){
                        for(ll kk=i; kk<j; ++kk){
                            if( dp2[kk][ii][jj-1] < llINF && dp1[kk+1][j][A[ii][jj]-'a'] < llINF ){
                                chmin(dp2[i][ii][jj], dp2[kk][ii][jj-1]+dp1[kk+1][j][A[ii][jj]-'a']);
                            }
                        }
                    }
                    if(chmin(dp1[i][j][C[ii]-'a'], dp2[j][ii][len[ii]-1] + 1) ){
                        pq.emplace(-dp1[i][j][C[ii]-'a'],C[ii]-'a');
                    }
                }
            }
            while(!pq.empty()){
                auto [c,cc] = pq.top(); pq.pop();
                if(c == -dp1[i][j][cc]){
                    rep(ii,esz[cc]){
                        if(chmin(dp1[i][j][e[cc][ii]], dp1[i][j][cc]+1) ){
                            pq.emplace(-dp1[i][j][e[cc][ii]],e[cc][ii]);
                        }
                    }
                }
            }
            rep(ii,K) dp2[j][ii][0] = dp1[i][j][A[ii][0]-'a'];
        }
    }

    rep(i, tn+1)rep(jj, sn+1) dp2[i][K][jj] = llINF;
    dp2[0][K][0] = 0;
    rep(i,tn){
        rep(jj, sn){
            rep(j, i+1){
                dp2[i+1][K][jj+1] = min(dp2[i+1][K][jj+1], dp2[j][K][jj] + dp1[j][i][S[jj]-'a']);
            }
        }
    }

    if(dp2[tn][K][sn] == llINF) dame;
    cout << dp2[tn][K][sn] << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
