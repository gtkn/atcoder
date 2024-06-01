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
constexpr ll llINF = 1LL << 61;
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
    ll Q,K;
    cin >> Q >> K;

    set<ll> st;
    map<ll,ll> mf,mr;
    st.insert(-llINF);
    st.insert(llINF);
    mf[-llINF] = 2*llINF;
    mf[llINF] = 2*llINF;
    mr[-llINF] = 2*llINF;
    mr[llINF] = 2*llINF;

    map<ll,ll> gp;
    gp[-llINF] = 0;
    gp[llINF] = 1;


    vec(ll) sz = {1,1};
    ll nn = 2;





    auto merge = [&](ll l,ll r)->void{
        if(mf[l] > K) return;

        if(sz[gp[l]] < sz[gp[r]]){
            ll id = gp[r];
            ll now = l;
            sz[id] += sz[gp[l]];
            sz[gp[l]] = 0;
            while(mr[now]<=K){
                gp[now] = id;
                now = now-mr[now];
            }
        }else{
            ll id = gp[l];
            ll now = r;
            sz[id] += sz[gp[r]];
            sz[gp[r]] = 0;
            while(mf[now]<=K){
                gp[now] = id;
                now = now+mf[now];
            }
        }
    };


    auto split = [&](ll l, ll r)->void{
        sz[gp[l]]--;
        if(mf[l] <= K){
            return;
        }

        ll lsz = distance(st.begin(), st.upper_bound(l) );
        ll id = nn++;
        sz[id] = 0;
        if(lsz*2 < st.size()){
            ll now = l;
            while(mr[now]<=K){
                gp[now] = id;
                sz[id]++;
                sz[gp[r]]--;
                now = now-mr[now];
            }
        }else{
            ll now = r;
            while(mf[now]<=K){
                gp[now] = id;
                sz[id]++;
                sz[gp[l]]--;
                now = now+mf[now];
            } 
        }
    };



    while(Q--){
        ll t,x;
        cin >> t >> x;

        if(t==1){
            if(st.find(x)==st.end()){
                auto itr = st.upper_bound(x);
                ll r = *itr;
                ll l = *(--itr);

                st.insert(x);

                mf[l] = x-l;
                mf[x] = r-x;
                mr[x] = x-l;
                mr[r] = r-x;

                gp[x] = nn++;
                sz.push_back(1);

                merge(l,x);
                merge(x,r);
            }else{
                st.erase(x);

                auto itr = st.upper_bound(x);
                ll r = *itr;
                ll l = *(--itr);

                mf[l] = r-l;
                mf[x] = llINF;
                mr[x] = llINF;
                mr[r] = r-l;

                split(l,r);
            }

            cerr << "-----" << endl;
            cerr << "st: ";
            for(auto p:st){
                cerr << p << " ";
            }
            cerr << endl;
            cerr << "mf: ";
            for(auto p:mf){
                cerr << p.first << " " << p.second << "/ ";
            }
            cerr << endl;
            cerr << "mr: ";
            for(auto p:mr){
                cerr << p.first << " " << p.second << "/ ";
            }
            cerr << endl;
            cerr << "gp: ";
            for(auto p:gp){
                cerr << p.first << " " << p.second << "/ ";
            }
            cerr << endl;
            cerr << "sz: ";
            for(auto p:sz){
                cerr << p << " ";
            }
            cerr << endl;



        }else{
            cout << sz[gp[x]] << endl;
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
