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

struct edge{
    ll to,c,idx;
    edge(ll to=0, ll c=0, ll idx=0):to(to),c(c),idx(idx){}
};


vec(ll) dh = {1,0,-1,0};
vec(ll) dw = {0,1,0,-1};

void solve(){
    ll N;
    cin >> N;

    string S,T;
    cin >> S >> T;

    ll slen = S.size(), tlen = T.size();


    vec(ll) s,t;
    for(char c:S) s.push_back(c-'a');
    for(char c:T) t.push_back(c-'a');

    vvec(ll) svv(26),tvv(26);
    rep(i,slen) svv[s[i]].push_back(i);
    rep(i,tlen) tvv[t[i]].push_back(i);

    vec(ll) ssize(26),tsize(26);
    rep(i,26){
        ssize[i] = svv[i].size();
        tsize[i] = tvv[i].size();
    }


    // S'でnum番目のcがある位置を返す
    auto get_pos = [&](ll c, ll num)->ll{
        if(ssize[c]*N < num) return -1;
        ll res = (num/ssize[c])*slen;
        ll ii = num%ssize[c];
        // ll ii = num - ((num-1)/ssize[c])*ssize[c];
        if(ii==0){
            res -= slen;
            res += svv[c].back();
        }else{
            res += svv[c][ii-1];
        }

        return res;
    };

    // S'でpos文字目未満にあるcの数を返す
    auto get_num = [&](ll c, ll pos)->ll{
        if(slen*N < pos) return -1;
        ll res = (pos/slen)*ssize[c];
        ll pp = pos%slen;

        ll l = 0, r = ssize[c];
        while(r-l>1){
            ll mid = (l+r)/2;
            if(svv[c][mid] < pp) l = mid;
            else r = mid;
        }
        if(!svv[c].empty() && svv[c][l] < pp) res += l+1;
        return res;
    };


    auto get_next = [&](ll c, ll start, ll k)->ll{
        ll num = get_num(c,start);
        // cerr << "  c " << c << ", start " << start << ", num " << num << endl;
        if(num==-1) return -1;
        return get_pos(c,num+k);
    };


    auto check = [&](ll k)->bool{
        ll pos = 0;
        // cerr << k << "=====" << endl;
        for(ll c:t){
            // cerr << "pos " << pos << ", c " << c << endl;

            pos = get_next(c,pos,k);
            // cerr << "next pos " << pos << endl;

            if(pos==-1) return false;
            pos++;
        }
        return true;
    };



    ll l = 0, r = llINF;
    while(r-l>1){
        // cerr << "l " << l << ", r " << r << endl;
        ll mid = (l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }

    cout << l << endl;




}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
