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
ll op(ll a,ll b){
    return min(a,b);
    //if(a.first<b.first) return a;
    //else return b;
}
ll ee(){return llINF;}

struct Solver{

 
    void solve(){
        ll N,K;
        cin >> N >> K;

        vec(ll) P(N);
        rep(i,N) cin >> P[i];

        if(K==0){
            rep(i,N) cout << P[i] << " ";
            cout << endl;
            return;
        }


        vec(ll) v;
        rep(i,N) v.emplace_back(P[i]);
        rep(i,N) v.emplace_back(P[i]);

        vec(ll) res1,res2;

        segtree<ll,op,ee> seg(v);

        ll a0 = llINF;
        ll k0 = 0;
        rep1(i,K) if(chmin(a0, v[N-i])) k0=i;


        ll l,r;
        l = N-k0;
        ll rr = l+N;

        res1.push_back(v[l]);
        r = l+K+1;
        l++;

        while(k0<K && l<r ){
            ll x = seg.prod(l,r);
            res1.push_back(x);
            while(v[l]!=x && l<r){
                if(l>=N) k0++;
                l++;
            }
            if(l>=N && r<rr) r++;
            l++;
        }

        while(l<rr){
            res1.push_back(v[l]);
            l++;
        }
        while(k0<K){
            res1.pop_back();
            k0++;
        }

        //for(ll x:tmp) cout <<x  << " ";cout << endl;


        //--
        l=N;
        r=N+K+1;
        rr=2*N;


        k0=0;
        while(k0<K && l<r ){
            ll x = seg.prod(l,r);
            res2.push_back(x);
            while(v[l]!=x && l<r){
                if(l>=N) k0++;
                l++;
            }
            if(l>=N && r<rr) r++;
            l++;
        }

        while(l<rr){
            res2.push_back(v[l]);
            l++;
        }
        while(k0<K){
            res2.pop_back();
            k0++;
        }

        //for(ll x:res2) cout <<x  << " ";cout << endl;

        vec(ll) ans = min(res1,res2);


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
