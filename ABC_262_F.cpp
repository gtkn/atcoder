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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------
ll op(ll a,ll b){return min(a,b);}
ll ee(){return llINF;}

struct Solver{

 
    void solve(){
        ll N,K;
        cin >> N >> K;

        vec(ll) P(2*N);
        rep(i,N) cin >> P[i];
        rep(i,N) P[N+i] = P[i];
        P.push_back(0);

        vec(ll) pp(N+1);
        rep(i,N) pp[P[i]] = i;


        vec(ll) ans;
        rep(i,N) ans.push_back(P[i]);

        auto chk = [&](vec(ll) v){
            ll n = min(ans.size(), v.size());
            rep(i,n){
                if(ans[i]<v[i]) return false;
                if(ans[i]>v[i]) return true;
            }
            return (ans.size() > v.size() );
        };


        segtree<ll,op,ee> seg(P);


        rep(i,K){
            ll l = N-i;
            ll r = l+K;
            ll cnt = 0;
            vec(ll) tmp;

            while(cnt<K-i){
                ll x = seg.prod(l,r);
                ll idx = pp[x];
                if(idx<l) idx+=N;
                if(x>P[r]) idx=r;
                x = P[idx];
                //cout << i << " : "<< l << "~"<<r <<", " << idx << ", " << x << endl;

                tmp.push_back(x);
                while(l<idx){
                    if(l>=N) cnt++;
                    l++;
                }
                l=idx+1;
                if(idx>=N) r++;
            }
            //cout << i << " ; "; for(ll x:tmp) cout << x << " ";cout<<endl;
            while(l<2*N-i) tmp.push_back(P[l++]);

            if(chk(tmp)) ans = tmp;            

        }

        for(ll x:ans) cout << x <<" ";cout<<endl;


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
