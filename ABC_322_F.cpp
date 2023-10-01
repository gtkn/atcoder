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
using tri = tuple<ll,ll,ll>;
// using tri = array<ll,3>;

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


struct  Data{
    ll mx[2], l[2], r[2], len;

    Data(){
        rep(t,2) mx[t] = l[t] = r[t] = 0;
        len = 0;
    }
    Data(char c){
        rep(t,2) mx[t] = l[t] = r[t] = ( c==('0'+t));
        len = 1;
    }


    Data flip() const{
        Data res = *this;
        swap(res.mx[0], res.mx[1]);
        swap(res.l[0], res.l[1]);
        swap(res.r[0], res.r[1]);
        return res;
    }

    static Data merge(const Data& ld, const Data& rd){
        Data res;
        rep(t,2){
            res.l[t] = ld.l[t];
            if(ld.l[t]==ld.len) res.l[t] += rd.l[t];

            res.r[t] = rd.r[t];
            if(rd.r[t]==rd.len) res.r[t] += ld.r[t];

            res.mx[t] = max( {ld.mx[t], rd.mx[t], ld.r[t]+rd.l[t]} );
        }
        res.len = ld.len + rd.len;
        return res;
    }

};



Data op(Data a,Data b){return Data::merge(a,b);}
Data ee(){return Data();}

Data mapping(bool f, Data x){ return (f? x.flip() : x);}
bool composition(bool f,bool g){ return f^g;}
bool id(){return false;}




void solve(){
    ll N,Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vec(Data) v(N);
    rep(i,N) v[i] = Data(S[i]);

    lazy_segtree<Data, op, ee, bool, mapping, composition, id> lseg(v);


    while(Q--){
        ll c,l,r;
        cin >> c >> l >> r;
        l--;
        if(c==1){
            lseg.apply(l,r,true);
        }else{
            cout << lseg.prod(l,r).mx[1] << endl;
        }
    }

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
