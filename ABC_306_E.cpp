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
using ld = long double;
using l3 = __int128;

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

Pll op(Pll a,Pll b){
    return {a.first+b.first, a.second+b.second};
    }
Pll ee(){return {0,0};}


struct Solver{
 
    void solve(){
        ll N,K,Q;
        cin >> N >> K >> Q;

        vec(Pll) A(N);
        rep(i,N) A[i] = {0,i};

        map<ll,ll> m;
        m[0] = N;

        vec(ll) X(Q);
        vec(Pll) Y(Q);
        rep(i,Q){
            ll xq,yq;
            cin >> xq >> yq;
            X[i] = xq-1;
            Y[i] = {yq,m[yq]};
            m[yq]++;
        }


        vec(Pll) v;
        for(Pll a:A) v.push_back(a);
        for(Pll a:Y) v.push_back(a);

        sort(all(v),greater<Pll>());

        // for(Pll vi:v) cout << vi.first << " " << vi.second << endl;
        // return;


        map<Pll,ll> m2;
        ll nn = v.size();
        rep(i,nn) m2[v[i]] = i;
        
        segtree<Pll,op,ee> seg(nn);
        for(Pll a:A) seg.set( m2[a], {a.first,1} );

        rep(i,Q){
            // if(i>4) break;
            // cout << i << " --- " << X[i] << endl;
            // cout << A[X[i]].first << " " << A[X[i]].second << " " << m2[A[X[i]]] << endl;
            // cout << Y[i].first << " " << Y[i].second << " " << m2[Y[i]] << endl;

            seg.set(m2[A[X[i]]], ee() );
            seg.set(m2[Y[i]], {Y[i].first,1} );
            A[X[i]] = Y[i];

            // rep(i,nn){
            //     Pll p = seg.get(i);
            //     cout << i << " : " << p.first << " " << p.second << endl;
            // }


            ll l=0,r=nn;
            while(r-l>1){
                ll mid = (l+r)/2;
                Pll tmp = seg.prod(0,mid);
                if(tmp.second < K) l = mid;
                else r = mid;
            }
            cout << seg.prod(0,r).first << endl;

        }
        

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
