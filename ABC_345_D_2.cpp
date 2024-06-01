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

void solve(){
    ll N,H,W;
    cin >> N >> H >> W;

    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];


    auto chk = [&](const vec(Pll) v)->bool{
        vvec(bool) tl(H,vec(bool)(W));
        ll ii = 0;
        rep(h0,H)rep(w0,W){
            if(tl[h0][w0]) continue;

            auto [a,b] = v[ii];            
            rep(dh,a)rep(dw,b){
                if(h0+dh>=H || w0+dw>=W) return false;
                if(tl[h0+dh][w0+dw]) return false;
                tl[h0+dh][w0+dw] = true;
            }
            ii++;
            if(ii==v.size()){
                h0 = H; w0 = W;
            }
        }

        rep(i,H)rep(j,W) if(!tl[i][j]) return false;
        return true;
    };


    rep(us, (1<<N)){
        ll cnt = 0;
        vec(ll) ids;
        rep(i,N)if(bit(us,i)){
            ids.push_back(i);
            cnt += A[i] * B[i];
        }
        if(cnt != H*W) continue;

        ll nn = ids.size();

        vec(ll) pm(nn);
        rep(i,nn) pm[i] = i;
        do{
            rep(rot,(1<<nn)){
                vec(Pll) v;
                for(ll i:pm){
                    ll a = A[ids[i]], b = B[ids[i]];
                    if(bit(rot,i)) swap(a,b);
                    v.push_back({a,b});
                }
                if(chk(v)) sayyes;
            }
        }while(next_permutation(all(pm)));
    }
    sayno;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
