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
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("0"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){
    ll N, M;
    cin >> N >> M;

    vec(ll) A(M),B(M),C(M);
    rep(i,M){
        cin >> A[i] >> B[i] >> C[i];
        A[i]--; B[i]--; C[i]--;
    }

    
    vec(ll) vk(N,-1), vb(N,N-1);
    vvec(ll) g(N);

    vvec(ll) vv(N);
    rep(i,M) vv[C[i]].push_back(i);



    repr(c,N){
        if(vv[c].empty()) continue;

        if(vv[c].size()>1){
            map<ll,ll> mp;
            for(auto i:vv[c]){
                ll a = A[i], b = B[i];
                mp[a]++; mp[b]++;
            }
            ll center = -1;
            for(auto mi:mp){
                if(mi.second==vv[c].size()){
                    center = mi.first;
                }
            }
            if(center==-1) dame;
            
            for(auto mi:mp){
                if(mi.first==center){
                    vk[mi.first] = c;
                }else{
                    chmin(vb[mi.first],c-1);
                }
            }
        }else{
            ll a = A[vv[c][0]], b = B[vv[c][0]];
            chmin(vb[a],c);
            chmin(vb[b],c);
        }

        for(auto i:vv[c]){
            ll a = A[i], b = B[i];
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }






    // auto f = [&](ll now, ll x)->bool{
    //     if(vk[now]>x) return false;
    //     if(x<0) return false;

    //     for(ll nxt:g[now]){
    //         if(vk[nxt]>x) continue;
    //         vk[nxt] = vb[nxt];
    //     }
    //     vb[now] = x;

    //     return true;
    // };


    // repr(c,N){
    //     if(vv[c].empty()) continue;

    //     if(vv[c].size()>1){
    //         map<ll,ll> mp;
    //         for(auto i:vv[c]){
    //             ll a = A[i], b = B[i];
    //             mp[a]++; mp[b]++;
    //         }
    //         ll center = -1;
    //         for(auto mi:mp){
    //             if(mi.second==vv[c].size()){
    //                 center = mi.first;
    //             }
    //         }
    //         if(center==-1) dame;

    //         for(auto mi:mp){
    //             if(mi.first==center){
    //                 if(!f(mi.first,c)) dame;
    //                 vk[mi.first] = c;
    //             }else{
    //                 if(!f(mi.first,c-1)) dame;
    //             }
    //         }
    //     }else{
    //         ll a = A[vv[c][0]], b = B[vv[c][0]];
    //         if(!f(a,c)) dame;
    //         if(!f(b,c)) dame;
    //     }

    //     for(auto i:vv[c]){
    //         ll a = A[i], b = B[i];
    //         g[a].push_back(b);
    //         g[b].push_back(a);
    //     }

    // }


    // vec(ll) d(N);
    // mint ans = 1;
    // vec(bool) used(N);

    // rep(now,N){
    //     if(vk[now]>=0){
    //         assert(!used[vk[now]]);
    //         used[vk[now]] = true;
    //         continue;
    //     }
    //     ll x = vb[now];
    //     for(ll nxt:g[now]){
    //         if(vk[nxt]>=0) continue;
    //         if(vb[nxt]==x){
    //             vk[nxt] = x;
    //             ans*=2;
    //             x--;
    //             break;
    //         }
    //     }
    //     if(x<0) dame;
    //     d[x]++;
    // }

    // ll rem = 0;
    // rep(i,N){
    //     if(!used[i]) rem++;

    //     rep1(j,d[i]){
    //         ans *= j;
    //         ans *= rem;
    //         rem--;
    //     }
    // }

    // cout << ans.val() << endl;

    

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
