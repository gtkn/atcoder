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


    vec(ll) f(vec(ll) a, ll th, ll k){
        a.push_back(0);
        ll n = a.size();
        vec(ll) rv(n);
        rep(i,n) rv[a[i]] = i;

        vec(ll) res;
        segtree<ll,op,ee> seg(a);

        ll l=0;
        while(l<n){
            ll r = max(l,th)+k+1;
            chmin(r,n);
            ll x = seg.prod(l,r);
            res.push_back(x);

            k -= max(0LL, rv[x] - max(l,th) );
            l = rv[x]+1;
        }
        res.pop_back();

        return res;
    }

 
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

        vec(ll) R(N+1);
        R[0]=-1;
        rep(i,N) R[P[i]] = i;
        vec(ll) tmp = P;
        rep(i,N) tmp.push_back(P[i]);


        // 回転無し
        vec(ll) res1 = f(P,0,K);

        // ll kk = K;
        segtree<ll,op,ee> seg1(P);


        // vec(ll) res1;
        // ll l=0, r=kk+1;
        // while(kk>0){
        //     ll x = seg1.prod(l, r);
        //     res1.push_back(x);
        //     kk -= (R[x]-l);
        //     l = R[x]+1;
        //     r++;
        //     chmin(r,N);
        // }
        // while(l<N) res1.push_back(P[l++]);


        // 回転あり

        ll x = llINF, rot = 0;
        rep1(i,K){
            if(chmin(x,P[N-i])) rot = N-i;
        }

        rotate(P.begin(), P.begin()+rot, P.end());
        vec(ll) res2 = f(P, N-rot, K-(N-rot));


        // ll st = seg1.prod(N-K,N);
        // vec(ll) res2 = {st};

        // kk = K-(N-R[st]);
        // segtree<ll,op,ee> seg2(tmp);

        // l = R[st]+1;
        // r = N+kk+1;
        // while(kk>0){
        //     ll x = seg2.prod(l, r);
        //     res2.push_back(x);
        //     if(R[x]<R[st]){
        //         kk -= R[x]+N - max(N, l);
        //         l = R[x]+N+1;
        //         r = min(l+kk+1,2*N);
        //     }else{
        //         l = R[x]+1;
        //     }
        // }
        // while(l<R[st]+N) res2.push_back(tmp[l++]);


        vec(ll) ans = min(res1,res2);
        // rep(i,  min(res1.size(), res2.size())){
        //     if(res1[i]==res2[i]) continue;
        //     if(res1[i]<res2[i]) ans=res1;
        //     if(res1[i]>res2[i]) ans=res2;
        //     break;
        // }

        // if(ans.empty()){
        //     if(res1.size()<res2.size()) ans=res1;
        //     else ans=res2;
        // }


        // for(ll ai:res1) cout << ai << " "; cout<<endl;
        // for(ll ai:res2) cout << ai << " "; cout<<endl;
        for(ll ai:ans) cout << ai << " "; cout<<endl;


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
