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
        ll N,L,R;
        cin >> N >> L >> R;
        vec(ll) A(N);
        rep(i,N) cin >> A[i];

        // ll nn = 60;

        sort(all(A));

        vector<ll> s;
        for(ll ai:A){
            for(ll si:s){
                if( (ai^si) < ai){
                    ai^=si;
                }
            }
            for(auto &&si:s){
                if( (ai^si) < si){
                    si^=ai;
                }       
            }
            if(ai) s.push_back(ai);
        }

        sort(all(s));
        ll nn = s.size();
        for(ll x=L-1; x<=R-1; x++){
            ll res = 0;
            rep(i,nn){
                if(bit(x,i)) res ^= s[i];
            }
            cout << res <<  " ";
        }
        cout << endl;



        // for(ll ai:A){
        //     ll now=ai;
        //     for(ll si:s){
        //         rep(j,nn) if(bit(now,j) && bit(si,j)) now -= (1<<j);
        //     }
        //     s.insert(now);
        // }

        // cout << " --- " << endl;
        // for(ll si:s){
        //     cout << si << " ; ";
        //     repr(j,nn) cout << (bit(si,j)? 1: 0); cout << endl;
        // }


        // vec(ll) v(nn+1),cnt(nn+1);
        // for(ll si:s){
        //     if(si==0) continue;
        //     ll ni = 2;
        //     rep(i,nn){
        //         if(si<ni){
        //             assert(v[i]==0);
        //             v[i]=si;
        //             break;
        //         }
        //         ni <<= 1;
        //     }
        // }
        // ll nowc = 0;
        // rep1(i,nn) cnt[i] = cnt[i-1] + (v[i-1]>0? 1 : 0);
        // rep(i,nn){
        //     if(v[i]>0) nowc++;
        //     cnt[i] = nowc;
        // }



 

        // rep(i,nn+1) cout << i << " ; " << v[i] << " , " << cnt[i] << endl;


        // vec(ll) two(nn+1);
        // two[0]=1;
        // rep1(i,nn) two[i]=two[i-1]*2;

        // auto f = [&](ll x){
        //     ll a = 0;
        //     ll res = 0;
        //     repr(i,nn){
        //         bool xi = bit(x,i);
        //         bool ai = bit(a,i);
        //         // cout << i << " :  " << xi << "/" << ai << " : " << res << endl;

        //         if(!xi && !ai) continue;
        //         if(!xi &&  ai) break;
        //         if( xi && !ai){
        //             res += two[cnt[i]];
        //             if(v[i]==0) break;
        //             else a+=v[i];
        //         }
        //         if( xi &&  ai) continue;
        //     }
        //     return res;
        // };

        // for(ll th=L; th<=R; th++){
        //     ll ok=0,ng=llINF;
        //     while(ng-ok>1){
        //         ll mid = (ok+ng)/2;
        //         // cout << mid << " , " << f(mid) << endl;
        //         if(f(mid) < th) ok = mid;
        //         else ng = mid;
        //     }
        //     cout << ok << " ";
        // }
        // cout << endl;





        // cout << f(3) << endl;
        // rep1(i,10) cout << f(i) << endl;

        // rep(i,N){
        //     cout << i << ", " << A[i] << " : ";
        //     repr(j,nn) cout << (bit(A[i],j)? 1: 0); cout << endl;
        // }

        // set<ll> ss;
        // rep(pt,(1<<N)){
        //     ll now = 0;
        //     rep(i,N) if(bit(pt,i)) now^=A[i];
        //     ss.insert(now);
        // }

        // cout << " --- " << endl;
        // for(ll si:ss){
        //     cout << si << " ; ";
        //     repr(j,nn) cout << (bit(si,j)? 1: 0); cout << endl;
        // }





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
