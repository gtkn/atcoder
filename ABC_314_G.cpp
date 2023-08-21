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
    ll N,M,H;
    cin >> N >> M >> H;
    vec(ll) A(N),B(N);
    rep(i,N) cin >> A[i] >> B[i];

    vec(ll) tot(M+1);
    vec(ll) ans(M+1);
    ll totall=0;

    set<Pll> s0,s1;
    rep1(i,M) s0.emplace(0,i);
    vec(bool) in1(M+1);
    ll tots1 = 0;


    auto s1update = [&](ll ii,ll dd, ll th)->void{
        tots1 += dd;
        s1.emplace(dd,ii);
        in1[ii] = true;
        
        while(!s1.empty()){
            Pll tmp = *s1.begin();
            if(tots1-tmp.first > th){
                s1.erase(tmp);
                in1[tmp.second] = false;
                s0.emplace(-tmp.first, tmp.second);
                tots1 -= tmp.first;
            }else{
                break;
            }
        }
        return;
    };


    rep(i,N){
        ll ai=A[i], bi=B[i];
        totall += ai;
        ll th = max((ll)-1, totall-H);
        ll pre = tot[bi];
        tot[bi] += ai;

        if( in1[bi] ){
            s1.erase( {pre,bi} );
            tots1 -= pre;
            s1update(bi, tot[bi], th);            
        }else{
            s0.erase( {-pre,bi} );
            s0.emplace( -tot[bi],bi );
            Pll tmp = *s0.begin();
            s0.erase(tmp);
            s1update(tmp.second, -tmp.first, th);
        }

        // cout << i << "-----" << endl;
        // for(Pll x:s0) cout << x.first<< " , " << x.second << " / "; cout <<" :::s0" << endl;
        // for(Pll x:s1) cout << x.first<< " , " << x.second << " / "; cout <<" :::s1" << endl;
        // cout << pre << " , " << totall << " , " << tots1 << " , " << th << endl;
        // rep1(j,M) cout << tot[j] << " "; cout << endl;
        // rep1(j,M) cout << in1[j] << " "; cout << endl;


        chmax( ans[s1.size()], i+1 );
    }

    ll res = 0;
    rep(i,M+1){
        chmax(res, ans[i]);
        cout << res << " ";
    }
    cout << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
