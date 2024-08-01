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


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;

    vec(ll) t(N),x(N);
    rep(i,N) cin >> t[i] >> x[i];

    vec(ll) memo(N);
    vec(ll) ecnt(N+1);
    repr(i,N){
        if(t[i]==1){
            if(ecnt[x[i]]==0) continue;
            ecnt[x[i]]--;
            memo[i] = 1;
        }else{
            ecnt[x[i]]++;
        }
    }
    rep1(i,N) if(ecnt[i]>0) dame;

    ll K = 0, cnt = 0;
    vec(ll) ans;
    rep(i,N){
        if(t[i]==1){
            ans.push_back(memo[i]);
            cnt += memo[i];
        }else{
            cnt--;
        }
        chmax(K,cnt);
    }
    
    cout << K << endl;
    for(auto a: ans) cout << a << " ";
    cout << endl;



    // vvec(ll) p(N+1),e(N+1);
    // rep(i,N){
    //     if(t[i]==1) p[x[i]].push_back(i);
    //     else e[x[i]].push_back(i);
    // }

    // auto f = [&](ll th)->bool{
    //     set<ll> st;
    //     rep(i,N){
    //         if(t[i]==1){
    //             auto itr = lower_bound(all(e[x[i]]),i);
    //             if(itr==e[x[i]].end()) continue;
    //             ll next_e = *itr;

    //             auto itr2 = upper_bound(all(p[x[i]]),i);
    //             if(itr2==p[x[i]].end() || *itr2 > next_e) st.insert(x[i]);
    //         }else{
    //             if(st.find(x[i])==st.end()) return false;
    //             st.erase(x[i]);
    //         }
    //         if(st.size()>th) return false;
    //     }
    //     return true;
    // };

    // if(!f(N)) dame;


    // ll l=-1,r=N;
    // while(r-l>1){
    //     ll mid  = (l+r)/2;
    //     if(f(mid)) r = mid;
    //     else l = mid;
    // }


    // auto f2 = [&](ll th)->vec(ll){
    //     set<ll> st;
    //     vec(ll) res;
    //     rep(i,N){
    //         if(t[i]==1){
    //             auto itr = lower_bound(all(e[x[i]]),i);
    //             if(itr==e[x[i]].end()){
    //                 res.push_back(0);
    //                 continue;
    //             }
    //             ll next_e = *itr;

    //             auto itr2 = upper_bound(all(p[x[i]]),i);
    //             if(itr2==p[x[i]].end() || *itr2 > next_e){
    //                 st.insert(x[i]);
    //                 res.push_back(1);
    //             }else{
    //                 res.push_back(0);
    //             }
    //         }else{
    //             // assert(st.find(x[i])!=st.end());
    //             st.erase(x[i]);
    //         }
    //         // if(st.size()>th) return false;
    //     }
    //     return res;
    // };

    // vec(ll) ans = f2(r);
    // cout << r << endl;
    // for(auto a: ans) cout << a << " ";
    // cout << endl;   




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
