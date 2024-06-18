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


void solve(){
    ll N,M;
    cin >> N >> M;
    vec(ll) D(N);
    rep(i,N) cin >> D[i];

    ll dtot = 0;
    rep(i,N) dtot += D[i];
    if(dtot!=2*(N-1)) dame;

    dsu uf(N);
    rep(_,M){
        ll a,b;
        cin >> a >> b;
        --a,--b;
        uf.merge(a,b);
        D[a]--;
        D[b]--;
    }

    auto grps = uf.groups();
    ll nn = grps.size();

    vvec(ll) vv(nn);
    rep(i,nn){
        for(ll v:grps[i]){
            rep(_,D[v]) vv[i].push_back(v);
        }
    }

    sort(all(vv),[](vec(ll) a, vec(ll) b){
        return a.size() < b.size();
    });

    // rep(i,nn){
    //     cerr << i << " ; ";
    //     for(ll v:vv[i]) cerr << v << ' ';
    //     cerr << endl;
    // }


    vec(Pll) ans;
    repr(i,nn-1){
        vec(ll) &a = vv[i];
        vec(ll) &b = vv[i+1];
        if(a.empty() || b.empty()) dame;
        ans.emplace_back(a.back(), b.back());
        a.pop_back();
        b.pop_back();
        if(a.size() < b.size()) swap(a, b);
        a.insert(a.end(), b.begin(), b.end());
    }

    // rep(i,nn){
    //     cerr << i << " ; ";
    //     for(ll v:vv[i]) cerr << v << ' ';
    //     cerr << endl;
    // }



    if(ans.size() != N-M-1) dame;
    for(auto p:ans){
        uf.merge(p.first,p.second);
        D[p.first]--;
        D[p.second]--;
    }
    if(uf.groups().size() != 1) dame;
    // rep(i,N) if(D[i]!=0) dame;



    for(auto p:ans){
        cout << p.first+1 << ' ' << p.second+1 << endl;
    }






    // vec(ll) l;
    // vec(Pll) ans;

    // rep(i,grps.size()){
    //     vec(ll) r;
    //     for(auto v:grps[i]){
    //         rep(_,D[v]) r.push_back(v);
    //     }

    //     cerr << "----" << i << endl;
    //     for(ll ri:r) cerr << ri << ' '; cerr << endl;

    //     if(i==0){
    //         l=r;
    //     }else{
    //         if(l.empty() || r.empty()) dame;
    //         ans.emplace_back(l.back(),r.back());
    //         l.pop_back();
    //         r.pop_back();
    //         if(l.size() < r.size()) swap(l,r);
    //         l.insert(l.end(),r.begin(),r.end());
    //     }
    // }

    // assert(ans.size() == N-M-1);
    // for(auto p:ans){
    //     cout << p.first+1 << ' ' << p.second+1 << endl;
    // }


    // vec(ll) idx(N);
    // rep(i,grps.size()){
    //     for(auto v:grps[i]){
    //         idx[v] = i;
    //     }
    // }


    // vec(Pll) ans;
    // vec(ll) l;
    // for(ll i:grps[idx[0]]){
    //     rep(_,D[i]) l.push_back(i);
    // }

    // rep(i,N){
    //     if(uf.same(0,i)) continue;
    //     uf.merge(0,i);

    //     vec(ll) r;
    //     for(ll j:grps[idx[i]]){
    //         rep(_,D[j]) r.push_back(j);
    //     }
    //     if(l.empty() || r.empty()) dame;

    //     ans.emplace_back(l.back(),r.back());
    //     l.pop_back();
    //     r.pop_back();
    //     if(l.size() < r.size()) swap(l,r);
    //     l.insert(l.end(),r.begin(),r.end());
    // }


    // assert(ans.size() == N-M-1);
    // for(auto p:ans){
    //     cout << p.first+1 << ' ' << p.second+1 << endl;
    // }

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
