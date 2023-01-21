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

ll eemax(){return -llINF;}
ll opmax(ll a,ll b){return max(a,b);}

ll eemin(){return llINF;}
ll opmin(ll a,ll b){return min(a,b);}

ll eesum(){return 0;}
ll opsum(ll a,ll b){return a+b;}


struct Solver{
    void solve(){
        ll N;
        cin >> N;
        string S;
        cin >> S;

        vec(ll) v(N+2);
        rep1(i,N) v[i] = S[i-1]-'a';
        v[0]=-llINF; v[N+1]=llINF;
        segtree<ll,opmax,eemax> segmax(v);
        segtree<ll,opmin,eemin> segmin(v);


        vec(ll) d(N+2);
        rep1(i,N) if(v[i-1]>v[i]) d[i]=1;


        segtree<ll,opsum,eesum> segsum(d);

        segtree<ll,opsum,eesum> tmp(N+1);
        vector<segtree<ll,opsum,eesum>> vseg(26, tmp);
        rep(i,26){
            rep1(j,N) if(v[j]==i) vseg[i].set(j,1);
        }

        


        ll Q;
        cin >> Q;
        while(Q--){
            ll t;
            cin >> t;

            if(t==1){
                ll x;
                char c;
                cin >> x >> c;
                
                ll b = v[x];
                ll a = c-'a';

                vseg[b].set(x,0);
                vseg[a].set(x,1);

                v[x]=a;
                segmax.set(x, a);
                segmin.set(x, a);

                d[x] = (1 ? v[x-1]>v[x] : 0 );
                d[x+1] = (1 ? v[x]>v[x+1] : 0 );
                segsum.set(x,d[x]);
                segsum.set(x+1,d[x+1]);
            }
            if(t==2){
                ll l,r;
                cin >> l >> r;

                

                ll lmin,lmax,mmin,mmax,rmin,rmax;
                // lmin = segmin.prod(1,l);
                // lmax = segmax.prod(1,l);
                mmin = segmin.prod(l,r+1);
                mmax = segmax.prod(l,r+1);
                // rmin = segmin.prod(r+1,N+1);
                // rmax = segmax.prod(r+1,N+1);

                //cout << lmin <<" " << lmax <<" : " << mmin <<" " << mmax <<" : " << rmin <<" " << rmax <<" ::" << segsum.prod(l,r+1)<< endl;


                ll isok=true;
                if(l<r && segsum.prod(l+1,r+1)!=0) isok=false;
                // if(l>1) if( !(lmax <= mmin || lmin>=mmax) ) isok=false;
                // if(r<N) if( !(rmax <= mmin || rmin>=mmax) ) isok=false;

                for(ll a=mmin+1; a<mmax; a++){
                    if(vseg[a].all_prod()!=vseg[a].prod(l,r+1)) isok=false;
                }


                if(isok) yn;

            }

            //cout << Q << " ; ";
            //for(ll vi:v) cout << vi <<" "; cout << endl;

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
