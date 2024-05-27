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
    ll to,i,j;
    edge(ll to, ll i, ll j):to(to),i(i),j(j){}
};



void solve(){
    ll N,L,R;
    cin >> N >> L >> R;
    R++;

    ll nn = (1<<N);
    vvec(edge) g(nn+1);

    rep(now,nn){
        rep(i,N+1){
            ll j=now;
            bool isok = true;
            rep(_,i){
                if(j&1) isok = false; 
                j >>= 1;
            }
            if(isok){
                ll nxt = now + (1<<i);
                g[now].push_back(edge(nxt,i,j));
                g[nxt].push_back(edge(now,i,j));
            }
        }
    }

    // cerr << "graph made" << endl;
    // rep(i,nn+1){
    //     cerr << i << ": ";
    //     for(auto e:g[i]){
    //         cerr << e.to << " ";
    //     }
    //     cerr << endl;
    // }



    vec(ll) dist(nn+1,llINF);
    priority_queue<Pll,vector<Pll>,greater<Pll>> pq;
    auto pqpush = [&](ll d, ll pos){
        if(chmin(dist[pos],d)) pq.push({d,pos});
    };

    pqpush(0,R);

    while(!pq.empty()){
        auto [d,now] = pq.top(); pq.pop();
        if(dist[now]<d) continue;
        for(auto e:g[now]){
            ll nxt = e.to;
            pqpush(d+1,nxt);
        }
    }

    // cerr << "dijkstra done" << endl;
    // rep(i,nn+1) cerr << i << ": " <<  dist[i] << endl;


    ll now = L;
    vec(Pll) v;
    while(now!=R){
        // cerr << now << endl;
        // if(now==0) return;
        for(auto [nxt,i,j]:g[now]){
            if(dist[nxt]!=dist[now]-1) continue;
            if(nxt < now) i+=100;
            // cerr << now << " " << nxt << " " << i << " " << j << endl;
            v.push_back({i,j});
            now = nxt;
            break;
        }
    }

    // cerr << "v made" << endl;

    ll ans = 0;
    for(auto [i,j]:v){
        ll c = 1;
        if(i>=100){
            c = -1;
            i -= 100;
        }
        cout << "? " << i << " " << j << endl << flush;
        ll T;
        cin >> T;
        ans += c*T;
        ans = mod(ans,100);
    }

    cout << "! " << ans << endl << flush;

    
}


int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
