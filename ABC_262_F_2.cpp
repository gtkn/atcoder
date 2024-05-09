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
    ll N, K;
    cin >> N >> K;

    vec(ll) p(N);
    rep(i,N) cin >> p[i];
    // rep(i,N) p[i]--;



    auto f = [](vec(ll) v, vec(ll) c, ll rem)->vec(ll){
        priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
        vec(ll) res;
        v.push_back(-1);
        c.push_back(0);
        ll nn = v.size();
        assert(nn == c.size());

        ll now = 0;
        while(now < nn){
            pq.emplace(v[now],now);
            // cerr << "add : " << v[now] << " " << now << endl;
            rem -= c[now];
            now++;
            if(rem < 0) break;
        }

        ll pre = -1;
        while(!pq.empty()){
            while(!pq.empty()){
                auto [val,idx] = pq.top();
                pq.pop();
                // cerr << "pop : " << val << " " << idx << endl;
                
                if(idx < pre) continue;
                res.push_back(val);
                // cerr << "push : " << val << endl;
                pre = idx;

                if(c[idx]>0 && now < nn){
                    // cerr << "add : " << v[now] << " " << now << endl;
                    pq.emplace(v[now],now);
                    now++;
                }
            }
        }

        assert(res.back()==-1);
        res.pop_back();
        return res;
    };


    vec(ll) v0 = p;
    vec(ll) c0(N,1);    
    vec(ll) res0 = f(v0,c0,K);

    // cerr << "res0: ";
    // for(auto r: res0) cerr << r << " "; cerr << endl;


    vec(ll) v1,c1;
    ll pmin = llINF, ii = N;
    rep1(d,K){
        ll i = N-d;
        if(chmin(pmin,p[i])) ii = i;
    }
    for(ll i=ii+1; i<N; ++i){
        v1.push_back(p[i]);
        c1.push_back(0);
    }
    for(ll i=0; i<ii; ++i){
        v1.push_back(p[i]);
        c1.push_back(1);
    }
    vec(ll) tmp = f(v1,c1, K-(N-1-ii)-1);
    vec(ll) res1 = {pmin};
    res1.insert(res1.end(), all(tmp));

    // cerr << "res1: ";
    // for(auto r: res1) cerr << r << " "; cerr << endl;
    



    vec(ll) ans;
    rep(i, min(res0.size(), res1.size()) ){
        if(res0[i] < res1[i]){
            ans = res0;
            break;
        }
        if(res0[i] > res1[i]){
            ans = res1;
            break;
        }
    }

    if(ans.empty()){
        if(res0.size() < res1.size()) ans = res0;
        else ans = res1;
    }

    for(auto a: ans) cout << a << " "; cout << endl;

}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
