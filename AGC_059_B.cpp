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
inline ll mod(ll a, ll m) {return (a % m + m) % m;}
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define sayyn {puts("Yes");}else{puts("No");}
#define sayfs {puts("First");}else{puts("Second");}

//------------------------------------------------


void solve(){
    ll N;
    cin >> N;

    vec(ll) cnt(N+1);
    rep(_,N){
        ll c; cin >> c;
        cnt[c]++;
    }

    vec(Pll) v;
    rep1(i,N) if(cnt[i]>0) v.emplace_back(cnt[i],i);

    ll k = v.size();

    if(k==1){
        rep(_,N) cout << v[0].second << " "; cout << endl;
        return;
    }


    ll atot = 0;
    for(Pll vi:v) atot += vi.first;
    
    if(atot<2*k-2){
        for(Pll vi:v) rep(_,vi.first) cout << vi.second << " ";
        cout << endl;
        return;
    }


    vvec(ll) g(k);

    sort(all(v));
    reverse(all(v));
    ll used = 1;
    rep(i,k){
        rep(_, v[i].first - (i>0)){
            g[i].push_back(used);
            g[used].push_back(i);
            used++;
            if(used==k) break;
        }
        if(used==k) break;
    }

    // rep(i,k){
    //     cout << i << " ; " << v[i].first << " , " << v[i].second << endl;
    //     for(ll j:g[i]) cout << j << " ,"; cout << endl;
    // }


    vec(ll) ans;

    auto f = [&](auto f, ll now, ll frm)->void{
        if(now!=frm){
            ans.push_back(v[now].second);
            v[now].first--;
        }


        for(ll nxt:g[now]){
            if(nxt==frm) continue;
            f(f,nxt,now);
            ans.push_back(v[now].second);
            v[now].first--;
        }

        // cout << "end " << now <<"," << v[now].second << ", " << v[now].first << endl;

        rep(_, v[now].first) ans.push_back(v[now].second);
    };

    f(f,0,0);

    for(ll ai:ans) cout << ai << " "; cout << endl;




}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
