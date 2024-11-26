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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


// vec(ll) dh = {1,0,-1,0};
// vec(ll) dw = {0,1,0,-1};
vec(Pll) dhw = { {1,0},{0,1},{-1,0},{0,-1} };

void solve(){
    ll N,D;
    cin >> N >> D;

    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];

    vec(ll) Z(N);
    rep(i,N) Z[i] = X[i]-Y[i];    

    mint ans = 0;

    set<ll> xs,ys;
    rep(i,N){
        xs.insert(X[i]);
        ys.insert(Y[i]);
    }

    map<ll,vector<ll>> mp;
    rep(i,N) mp[Z[i]].push_back(i);


    vec(mint) two(N+1);
    two[0] = 1;
    rep1(i,N) two[i] = two[i-1]*2;

    for(ll x0:xs)for(ll y0:ys){
        queue<ll> q;
        vec(ll) cnt(8);

        for(auto [z0,ids]:mp){
            rep(b,4){
                cnt[b] += cnt[b+4];
                cnt[b+4] = 0;
            }

            for(ll ii:ids){
                if(X[ii] < x0 || X[ii] > x0+D) continue;
                if(Y[ii] < y0 || Y[ii] > y0+D) continue;
                ll b = 4;
                if(X[ii]==x0) b |= 1;
                if(Y[ii]==y0) b |= 2;
                cnt[b]++;
                q.push(ii);
            }

            while(!q.empty()){
                ll ii = q.front();
                if(Z[ii] >= z0-D) break;
                q.pop();
                ll b = 0;
                if(X[ii]==x0) b |= 1;
                if(Y[ii]==y0) b |= 2;
                cnt[b]--;                
            }
            // cerr << z0 << " : " << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << " " << cnt[4] << " " << cnt[5] << " " << cnt[6] << " " << cnt[7] << endl;

            if(cnt[1] + cnt[3] + cnt[5] + cnt[7] == 0) continue;
            if(cnt[2] + cnt[3] + cnt[6] + cnt[7] == 0) continue;
            if(cnt[4] + cnt[5] + cnt[6] + cnt[7] == 0) continue;

            mint tmp = 0;
            // if(cnt[7] > 0){
            //     tmp += two[cnt[7]-1] * two[ cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] ];
            // }
            // if(cnt[6] > 0 && cnt[1] + cnt[3] + cnt[5] > 0){
            //     tmp += two[cnt[6]-1] * two[ cnt[1] + cnt[3] + cnt[5] - 1] * two[ cnt[0] + cnt[2] + cnt[4] ];
            // }
            // if(cnt[5] > 0 && cnt[2] + cnt[3] > 0){
            //     tmp += two[cnt[5]-1] * two[ cnt[2] + cnt[3] - 1] * two[ cnt[0] + cnt[1] + cnt[4] ];
            // }
            // if(cnt[3] > 0 && cnt[4] > 0){
            //     tmp += two[cnt[3]-1] * two[ cnt[4] - 1] * two[ cnt[0] + cnt[1] + cnt[2] ];
            // }
            // if(cnt[1] > 0 && cnt[2] > 0 && cnt[4] > 0){
            //     tmp += two[cnt[1]-1] * two[ cnt[2] - 1] * two[ cnt[4] - 1] * two[ cnt[0] ];
            // }


            // tmp += two[cnt[7]-1] * two[ cnt[0] + cnt[1] + cnt[2] + cnt[3] + cnt[4] + cnt[5] + cnt[6] ];
            // tmp += two[cnt[6]-1] * two[ cnt[1] + cnt[3] + cnt[5] - 1] * two[ cnt[0] + cnt[2] + cnt[4] ];
            // tmp += two[cnt[5]-1] * two[ cnt[2] + cnt[3] - 1] * two[ cnt[0] + cnt[1] + cnt[4] ];
            // tmp += two[cnt[3]-1] * two[ cnt[4] - 1] * two[ cnt[0] + cnt[1] + cnt[2] ];
            // tmp += two[cnt[1]-1] * two[ cnt[2] - 1] * two[ cnt[4] - 1] * two[ cnt[0] ];


            tmp+=(two[cnt[7]]-1)*two[cnt[0]+cnt[1]+cnt[2]+cnt[3]+cnt[4]+cnt[5]+cnt[6]];
            tmp+=(two[cnt[6]]-1)*(two[cnt[1]+cnt[3]+cnt[5]]-1)*two[cnt[0]+cnt[2]+cnt[4]];
            tmp+=(two[cnt[5]]-1)*(two[cnt[2]+cnt[3]]-1)*two[cnt[0]+cnt[1]+cnt[4]];
            tmp+=(two[cnt[3]]-1)*(two[cnt[4]]-1)*two[cnt[0]+cnt[1]+cnt[2]];
            tmp+=(two[cnt[1]]-1)*(two[cnt[2]]-1)*(two[cnt[4]]-1)*two[cnt[0]];

            // cerr << x0 << " " << y0 << " " << z0 << " " << tmp.val() << endl;
            ans += tmp;

        }



    }

    cout << ans.val() << endl;




    // rep(i,N){
    //     cerr << i << endl;
    //     ll cnt = 0;
    //     rep(j,N)if(j!=i){
    //         ll dx = X[j]-X[i];
    //         ll dy = Y[j]-Y[i];
    //         ll dz = Z[j]-Z[i];
    //         cerr << dx << " " << dy << " " << dz << endl;
    //         if(dx<0 || dx>D) continue;
    //         if(dy<0 || dy>D) continue;
    //         if(dz<0 || dz>D) continue;

    //         ++cnt;
    //     }

    //     cerr << i <<" " << cnt << endl;

    //     ans += mint(2).pow(cnt);
    // }

    // cout << ans.val() << endl;

    // rep(i,N) cerr << X[i] << " " << Y[i] << " " << Z[i] << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
