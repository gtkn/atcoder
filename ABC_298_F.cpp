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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

struct Solver{
    struct edge{
        ll to,c;
        edge(ll to=0, ll c=0):to(to),c(c){}
    };

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };

 
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};
 
    void solve(){
        ll N;
        cin >> N;

        vec(ll) R(N),C(N),X(N);
        rep(i,N) cin >> R[i] >> C[i] >> X[i];

        set<ll> sr,sc;
        rep(i,N) sr.insert(R[i]);
        rep(i,N) sc.insert(C[i]);

        map<ll,ll> mr,mc;
        ll nr=0,nc=0;
        for(ll si:sr) mr[si]=nr++;
        for(ll si:sc) mc[si]=nc++;

        vec(ll) totr(nr),totc(nc);

        vector<set<ll>> memo(nr);

        map<Pll,ll> rcx;

        rep(i,N){
            ll rr = mr[R[i]], cc = mc[C[i]];
            totr[rr] += X[i];
            totc[cc] += X[i];
            memo[rr].insert(cc);
            rcx[{rr,cc}] = X[i];
        }

        vec(Pll) vc;
        rep(i,nc) vc.emplace_back(totc[i],i);
        sort(all(vc));

        // rep(i,nr) cout << i << " ; " << totr[i] << endl;
        // rep(i,nc) cout << i << " ; " << totc[i] << endl;


        ll ans = 0;
        rep(rr,nr){
            repr(i,nc){
                ll tmp = totr[rr] + vc[i].first;
                ll cc = vc[i].second;
                
                ll chk=0;
                if(sfind(memo[rr], cc)) chk=rcx[{rr,cc}];
                // ll chk = rcx[{rr,cc}];

                // cout << rr <<" ," << cc << " : " << tmp <<" - " << chk << endl;

                chmax(ans, tmp-chk);
                if(chk==0) break;
            }
        }

        cout << ans << endl;


    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
