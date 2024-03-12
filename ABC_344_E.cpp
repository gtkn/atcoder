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
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
constexpr ll llINF = 1LL << 60;
constexpr int iINF = 1e9;
constexpr char nl = '\n';

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------

map<ll,ll> compressCoordinates(vec(ll) &v){
    // 値の集合vを受け取って座標圧縮する
    // res[val] = idx
    // v[idx] = val となるように入力のvも変更する

    sort(all(v));
    v.erase(unique(all(v)),v.end());

    ll nn = v.size();
    map<ll,ll> res;
    rep(i,nn) res[ v[i] ] = i;

    return res;
}


void solve(){
    ll N;
    cin >> N;

    vec(ll) A(N);
    rep(i,N) cin >> A[i];

    ll Q;
    cin >> Q;

    vvec(ll) vv(Q,vec(ll)(3,-1));

    rep(i,Q){
        cin >> vv[i][0];
        if(vv[i][0]==1){
            cin >> vv[i][1] >> vv[i][2];
        }else{
            cin >> vv[i][1];
        }
    }

    
    vec(ll) rev = A;
    rep(i,Q){
        rev.push_back(vv[i][1]);
        rev.push_back(vv[i][2]);
    }
    rev.push_back(llINF);
    rev.push_back(0);



    sort(all(rev));
    rev.erase(unique(all(rev)),rev.end());

    ll nn = rev.size();
    map<ll,ll> m;
    rep(i,nn) m[ rev[i] ] = i;



    // ll nn = 0;
    // map<ll,ll> m;
    // for(ll si:s) m[si] = nn++;

    // vec(ll) rev;
    // for(ll si:s) rev.push_back(si);
    
    // assert(rev.size()==nn);


    vec(ll) gf(nn,-1),gr(nn,-1);

    rep(i,N-1){
        ll a0 = m[A[i]], a1 = m[A[i+1]];
        gf[a0] = a1;
        gr[a1] = a0;
    }
    {
        ll a0 = m[0], a1 = m[A[0]];
        gf[a0] = a1;
        gr[a1] = a0;    
    }
    {
        ll a0 = m[A[N-1]], a1 = m[llINF];
        gf[a0] = a1;
        gr[a1] = a0;
    }


    // for(auto mi:m) cerr << mi.first << " : " << mi.second << endl;


    for(const auto &v:vv){
        ll t,x,y;
        t = v[0]; x=v[1]; y=v[2];

        // cerr << "=====" << t << "," << x << "," << y << "======" << endl;
        // rep(i,nn) cerr << i << " -> " << gf[i] << " : " << rev[i] << " -> " << ( gf[i]>=0? rev[gf[i]] : llINF ) << endl;
        // rep(i,nn) cerr << i << " <- " << gr[i] << " : " << rev[i] << " <- " << rev[gr[i]] << endl;


        if(t==1){
            ll xx = m[x], yy = m[y];
            ll zz = gf[xx];

            gf[xx] = yy;
            gr[yy] = xx;

            gf[yy] = zz;
            gr[zz] = yy;

        }else{
            ll xx = m[x];
            ll ww = gr[xx], zz = gf[xx];

            gf[ww] = zz;
            gr[zz] = ww;

            gf[xx] = -1;
            gr[xx] = -1;
        }

    }

    vec(ll) ans;
    ll now = m[0];
    assert(gf[m[llINF]]==-1);

    // rep(_,2*N+2*Q){
    while(now>=0){
        ll a = rev[now];
        if(0<a && a<llINF) ans.push_back(a);
        now = gf[now];
        if(now<0) break;
    }

    for(ll ai:ans) cout << ai << " "; cout << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
