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
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

void solve(){
    ll N, M ;
    cin >> N >> M;

    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];

    vec(ll) X(M),Y(M);
    rep(i,M) cin >> X[i] >> Y[i];
    rep(i,M) X[i]--;
    rep(i,M) Y[i]--;


    vvec(bool) xy(N,vec(bool)(N));
    rep(i,M){
        xy[X[i]][Y[i]] = true;
        xy[Y[i]][X[i]] = true;
    }

    rep(i,N){
        if(xy[i][i] && A[i]<B[i]) swap(A[i],B[i]);
    }

    vec(double) D(N);
    rep(i,N) D[i] = (B[i]-A[i])*0.5;

    vec(ll) P,Q;
    vec(bool) isq(N);
    rep(i,N){
        if(D[i]<0) P.push_back(i);
        else{
            Q.push_back(i);
            // isq[i]=true;
        }
    }

    double ans0 = 0;
    rep(i,N) ans0 += A[i];

    ll pn = P.size(), qn = Q.size();
    
    vec(bool) quse0(qn);


    rep(i,qn)rep(j,i){
        if(!xy[Q[i]][Q[j]]) continue;
        quse0[i]=true;
        quse0[j]=true;
    }


    // cout << ans0 << endl;
    // rep(i,N) cout << A[i] << " "; cout << endl;
    // rep(i,N) cout << B[i] << " "; cout << endl;
    // rep(i,N) cout << D[i] << " "; cout << endl;
    // for(ll x:P) cout << x << " "; cout << endl;
    // for(ll x:Q) cout << x << " "; cout << endl;



    double ans = ans0;

    if(pn<N/2){
        rep(ptn, (1<<pn)){
            double dsum = 0;
            vec(bool) quse = quse0;
            rep(i,pn){
                if(!bit(ptn,i)) continue;
                dsum += D[P[i]];
                rep(j,qn) if(xy[P[i]][Q[j]]) quse[j]=true;                
            }

            rep(i,qn) if(quse[i]) dsum += D[Q[i]];
            chmax(ans, ans0+dsum);
        }

    }else{
        ll qnn = (1<<qn);
        vvec(double) dp(pn+1,vec(double)( qnn, -llINF ));

        auto f = [&](ll x){
            double res = 0;
            rep(i,qn) if(bit(x,i)) res += D[Q[i]];
            return res;            
        };

        ll qtmp = 0;
        repr(i,qn){
            qtmp <<= 1;
            qtmp |= quse0[i];
        }
        dp[0][qtmp] = f(qtmp);

        // cout << qtmp <<"  ; " << f(qtmp ) << endl;

        rep(i,pn)rep(j,qnn){
            chmax(dp[i+1][j],dp[i][j]);
            
            ll jj = j;
            double dsum = D[P[i]];
            rep(k,qn){
                if(xy[P[i]][Q[k]]){
                    if(!bit(jj,k)) dsum += D[Q[k]];
                    jj |= (1<<k);
                }
            }

            chmax(dp[i+1][jj], dp[i][j] +dsum );
        }

        rep(j,(1<<qn)) chmax(ans, ans0+dp[pn][j]);
    }

    printf("%.8f\r\n",ans);

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
