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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

void solve(){
    ll N,X,Y;
    cin >> N >> X >> Y;
    vec(ll) A(N);
    rep(i,N) cin >> A[i];


    auto f = [](const vec(ll)& va,const vec(ll)& vb, ll tgt)->vec(bool){
        ll na = va.size(), nb=vb.size();

        // cout << tgt << "!!" << endl;
        // for(ll x:va) cout << x << " "; cout << endl;
        // for(ll x:vb) cout << x << " "; cout << endl;


        vec(ll) ta;
        rep(i,(1<<na)){
            ll ii = i;
            ll tmp = 0;
            rep(j,na){
                tmp += va[j]*((ii&1)? 1 : -1);
                ii>>=1;
            }
            // cout << tmp << " ; " << i << endl;
            ta.push_back(tmp);
        }
        if(na==0) ta.push_back(0);

        set<ll> sb;
        map<ll,ll> mb;
        rep(i,(1<<nb)){
            ll ii = i;
            ll tmp = 0;
            rep(j,nb){
                tmp += vb[j]*((ii&1)? 1 : -1);
                ii>>=1;
            }
            sb.insert(tmp);
            mb[tmp] = i;
        }
        if(nb==0){
            sb.insert(0);
            mb[0]=0;
        }

        // cout << "--" << endl;
        // for(ll x:ta) cout << x << " ";cout << endl;
        // for(ll x:sb) cout << x << " ";cout << endl;


        ll xa=-1,xb=-1;
        vec(bool) res;
        rep(ii,(1<<na)){
            if(!sfind(sb, tgt-ta[ii] )) continue;

            xa = ii;
            xb = mb[tgt-ta[ii]];

            rep(i,na) res.push_back(bit(xa,i));
            rep(i,nb) res.push_back(bit(xb,i));

            break;

        }
        return res;
    };


    vec(ll) ao0,ao1,ae0,ae1;
    ll nn = N/2;
    rep(i,N){
        if(i&1){
            if(i<nn) ao0.push_back(A[i]);
            else ao1.push_back(A[i]);
        }else{
            if(i<nn) ae0.push_back(A[i]);
            else ae1.push_back(A[i]);
        }
    }


    vec(bool) bo,be;
    bo = f(ao0,ao1,X);
    be = f(ae0,ae1,Y);

    if(bo.empty() || be.empty()) sayno;


    // vec(bool) b;
    // rep(i,N){
    //     if(i&1) b.push_back(bo[i/2]);
    //     else b.push_back(be[i/2]);
    // }

    // for(bool bi:bo) cout << bi << " "; cout << endl;
    // for(bool bi:be) cout << bi << " "; cout << endl;


    cout << "Yes" << endl;
    bool pre = true;
    rep(i,N){
        ll ii = i/2;
        char c='.';

        if(i&1){
            if(pre && bo[ii]) c = 'R';
            if(pre && !bo[ii]) c = 'L';
            if(!pre && bo[ii]) c = 'L';
            if(!pre && !bo[ii]) c = 'R';
            pre = bo[ii];
        }else{
            if(pre && be[ii]) c = 'L';
            if(pre && !be[ii]) c = 'R';
            if(!pre && be[ii]) c = 'R';
            if(!pre && !be[ii]) c = 'L';
            pre = be[ii];
        }
        cout << c;
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
