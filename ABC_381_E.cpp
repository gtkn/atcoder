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
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
using ld = long double;
using l3 = __int128;

using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

//using mint = modint1000000007;
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
inline Pll PllSum(Pll x, Pll y){return {x.first+y.first,x.second+y.second};}
constexpr ll llINF = 1LL << 61;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------



ll op(ll a, ll b){
    return a+b;
}
ll ee(){
    return 0;
}


void solve(){
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;

 
    vvec(ll) vv(3,vec(ll)(N));
    rep(i,N){
        if(S[i]=='/') vv[0][i] = 1;
        if(S[i]=='1') vv[1][i] = 1;
        if(S[i]=='2') vv[2][i] = 1;
    }

 
    segtree<ll,op,ee> seg0(vv[0]);
    segtree<ll,op,ee> seg1(vv[1]);
    segtree<ll,op,ee> seg2(vv[2]);


    auto f1 = [&](ll l0, ll x){
        return seg1.max_right(l0,[&](ll v){return v<x;}) + 1;
    };


    auto f2 = [&](ll r0, ll x){
        return seg2.min_left(r0,[&](ll v){return v<x;}) - 1;
    };



    while(Q--){
        ll L,R;
        cin >> L >> R;
        --L; 


        if(seg0.prod(L,R)==0){
            cout << 0 << endl;
            continue;
        }

        ll res = 0;
        if(seg0.prod(L,R)>0) res = 1;

        ll a=0,b=N;
        while(b-a>1){
            ll m = (a+b)/2;
            ll pos1 = f1(L,m);
            ll pos2 = f2(R,m);

            
            // cerr << "m : " << m << ", pos1 : " << pos1 << ", pos2 : " << pos2 << endl;

            bool mok = true;
            if(pos1>=N || pos2<0) mok = false;
            else{
                if(seg1.prod(L,pos1)<m || seg2.prod(pos2,R)<m) mok = false;
                if(pos1>pos2) mok = false;
                else if(seg0.prod(pos1,pos2)==0) mok = false;
            }

            if(mok) a = m;
            else b = m;
        }
        chmax(res,a*2+1);
        cout << res << endl;


    }
 
}
 
 
 
void solve2(){
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;


 
 
    vvec(ll) v(3);
    rep(i,N){
        if(S[i]=='/') v[0].push_back(i);
        if(S[i]=='1') v[1].push_back(i);
        if(S[i]=='2') v[2].push_back(i);
    }



    while(Q--){
        ll L,R;
        cin >> L >> R;
        L--; R--;

        vec(bool) isin(3,true);
        rep(i,3){
            auto iti = lower_bound(all(v[i]),L);
            if(iti==v[i].end()) isin[i] = false;
            else if(*iti > R) isin[i] = false;
        }
        if(!isin[0]){
            // cerr << "isin[0] is false" << endl;
            cout << 0 << endl;
            continue;
        }
        if(!isin[1] || !isin[2]){
            cout << 1 << endl;
            continue;
        }


        auto it1 = lower_bound(all(v[1]),L);
        ll idx1 = it1 - v[1].begin();

        auto it2 = upper_bound(all(v[2]),R);
        it2--;
        ll idx2 = it2 - v[2].begin();
        

        if(v[1][idx1]>v[2][idx2]){
            cout << 1 << endl;
            continue;
        }




        ll a=0,b=N;
        while(b-a>1){
            ll m = (a+b)/2;

            ll i1 = idx1 + (m-1);
            ll i2 = idx2 - (m-1);

            bool mok = true;
            if(i1>=v[1].size() || i2<0){
                mok = false;
            }else{
                ll pos1 = v[1][i1];
                ll pos2 = v[2][i2];
                if(pos1>pos2){
                    mok = false;
                }else{
                    auto it0 = upper_bound(all(v[0]),pos1);
                    if(it0==v[0].end()) mok = false;
                    else if(*it0 >= pos2) mok = false;
                }
            }
            if(m==0) mok = true;

            // cerr << "m : " << m << ", mok : " << mok << endl;
            // cerr << i1 << " " << i2 << endl;

            if(mok) a = m;
            else b = m;
        }
        cout << a*2+1 << endl;

    }









}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        // solve();
        solve2();
    }
    return 0;
}
