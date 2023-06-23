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


struct Solver{
 
    void solve(){
        ll N,Q;
        cin >> N >> Q;

        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        vec(ll) L(Q),R(Q);
        rep(i,Q) cin >> L[i] >> R[i];
        rep(i,Q) L[i]--;

        ll th=1010;
        vec(bool) tmp(th,true);
        tmp[0]=false; tmp[1]=false;
        vec(ll) so;
        for(ll i=2; i<th; i++){
            if(tmp[i]){
                so.push_back(i);
                for(ll j=i*2; j<th; j+=i) tmp[j]=false;
            }
        }
        ll son = so.size();

        map<ll,ll> os;
        rep(i,son) os[so[i]] = i;

        vvec(ll) vv(son,vec(ll)(N));

        vec(ll) B(N);
        rep(i,N){
            ll a = A[i];
            for(ll s:so){
                while(a%s==0){
                    a/=s;
                    vv[os[s]][i]++;
                }
            }
            B[i]=a;
        }


        // rep(i,son){
        //     cout << so[i] << ": ";
        //     rep(j,N) cout << vv[i][j] << " ";
        //     cout << endl;
        //     if(so[i]>10) break;
        // }



        vvec(ll) cum(son,vec(ll)(N+1));
        rep(i,son){
            rep(j,N) cum[i][j+1] = cum[i][j] + vv[i][j];
        }


        auto myprod = [&](ll _l,ll _r)->bool{
            bool res = true;
            rep(i,son){
                ll x = cum[i][_r]-cum[i][_l];
                if(x%3!=0) res=false;
            }
            return res;
        };


        vec(ll) v(Q);
        rep(i,Q) v[i] = i;

        ll nn = sqrt(N)+1;

        sort(all(v),[&](ll const& a,ll const& b){
            if(L[a]/nn != L[b]/nn) return L[a]/nn < L[b]/nn;
            return R[a] < R[b];
        });


        vec(bool) ans(Q);
        set<ll> stmp;
        for(ll bi:B) stmp.insert(bi);
        stmp.insert(1);
        map<ll,ll> sm;
        ll ctmp = 0;
        for(ll si:stmp) sm[si]=ctmp++;
        rep(i,N) B[i] = sm[B[i]];

        vec(ll) fac(stmp.size());
        ll c3 = 0;
        ll l=0,r=0;

        auto addx = [&](ll x){
            if(x==0) return;
            if(fac[x]%3==0) c3--;
            fac[x]++;
            if(fac[x]%3==0) c3++;
        };
        auto remx = [&](ll x){
            if(x==0) return;
            if(fac[x]%3==0) c3--;
            fac[x]--;
            if(fac[x]%3==0) c3++;
        };


        for(ll vi:v){
            ll tol = L[vi], tor=R[vi];

            while(r<tor){
                addx(B[r]);
                r++;
            }
            
            while(r>tor){
                r--;
                remx(B[r]);
            }

            while(l<tol){
                remx(B[l]);
                l++;
            }

            while(l>tol){
                l--;
                addx(B[l]);
            }

            // cout << vi <<" : " << tol << " ~ " << tor << endl;
            // for(auto mi:fac) cout << mi.first << " " << mi.second << endl;

            ans[vi] = (c3==0) & myprod(L[vi],R[vi]);

        }
    
        rep(i,Q) if(ans[i]) yn;
    
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
