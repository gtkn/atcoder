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
    ll N,M;
    cin >> N >> M;

    vvec(ll) vv0(N,vec(ll)(N)); // vv[i][j] ; iがjに 1:勝ち, -1:負け, 0:未定, -10:自分
    rep(i,N) vv0[i][i] = -10;
    vec(ll) wcnt0(N); // 勝ち数

    rep(_,M){
        ll w,l;
        cin >> w >> l;
        --w, --l;
        vv0[w][l] = 1;
        vv0[l][w] = -1;
        wcnt0[w]++;
    }


    vec(ll) ans;

    rep(k,N){
        vvec(ll) vv = vv0;
        vec(ll) wcnt = wcnt0;

        rep(j,N){
            if(vv[k][j]!=0) continue;
            vv[k][j] = 1;
            vv[j][k] = -1;
            wcnt[k]++;
        }

        bool isok = true;
        rep(i,N)if(i!=k && wcnt[i] >= wcnt[k]) isok=false;
        if(!isok) continue;

        set<vector<ll>> dp_now;
        dp_now.insert(wcnt);

        rep(i,N)rep(j,i)if(vv[i][j]==0){
            set<vector<ll>> dp_nxt;
            for(vec(ll) w:dp_now){
                if(w[i] >= w[j] && w[j]+1 < wcnt[k]){
                    w[j]++;
                    dp_nxt.insert(w);
                    w[j]--;
                }
                if(w[i] <= w[j] && w[i]+1 < wcnt[k]){
                    w[i]++;
                    dp_nxt.insert(w);
                    w[i]--;
                }
            }
            swap(dp_now,dp_nxt);
        }

        if(dp_now.size() > 0) ans.push_back(k);



        // set<vector<ll>> dp_now;
        // dp_now.insert(wcnt);

        // rep(i,N)rep(j,i)if(vv[i][j]==0){
        //     set<vector<ll>> dp_nxt;
        //     for(vec(ll) w:dp_now){
        //         for(ll x:{i,j}){
        //             if(w[x]+1 >= wcnt[k]) continue;
        //             w[x]++;
        //             dp_nxt.insert(w);
        //             w[x]--;
        //         }
        //     }
        //     swap(dp_now,dp_nxt);
        // }

        // if(dp_now.size() > 0) ans.push_back(k);


        // rep(i,N)rep(j,i)if(vv[i][j]==0){
        //     if(wcnt[i] < wcnt[j]){
        //         vv[i][j] = 1;
        //         vv[j][i] = -1;
        //         wcnt[i]++;
        //     }else{
        //         vv[i][j] = -1;
        //         vv[j][i] = 1;
        //         wcnt[j]++;
        //     }
        // }

        // bool isok = true;
        // rep(i,N)if(i!=k && wcnt[i] >= wcnt[k]) isok=false;
        // if(isok) ans.push_back(k);

    }

    for(auto a:ans) cout << a+1 << " "; cout << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
