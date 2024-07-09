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


vec(ll) dh = {1,0,-1,0,1,1,-1,-1};
vec(ll) dw = {0,1,0,-1,-1,1,-1,1};

void solve(){
    ll N;
    cin >> N;

    vec(ll) X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];

    set<Pll> st;
    rep(i,N){
        st.insert({X[i],Y[i]});
        rep(k,8){
            st.insert({X[i]+dh[k],Y[i]+dw[k]});
        }
    }

    ll nn = st.size();
    vec(Pll) pp;
    for(auto p:st) pp.push_back(p);

    auto idx = [&](Pll p){
        auto itr = lower_bound(all(pp),p);
        if(*itr == p) return (ll)(itr - pp.begin());
        else return (ll)(-1);
    };


    vec(bool) wall(nn);
    rep(i,N) wall[idx({X[i],Y[i]})] = true;

    dsu uf(nn);
    rep(i,N){
        ll x0 = X[i], y0 = Y[i];
        rep(k,8){
            Pll p = {x0 + dh[k], y0 + dw[k]};
            uf.merge(idx({x0,y0}),idx(p));
        }
    }

    auto grps = uf.groups();

    vec(ll) inout(nn,-1); // -1:in, 0:wall, 1:out
    rep(i,N) inout[idx({X[i],Y[i]})] = 0;

    for(auto grp:grps){
        Pll leftBottom = {llINF, llINF};
        for(auto i:grp){
            Pll p = pp[i];
            if(p.first < leftBottom.first || (p.first == leftBottom.first && p.second < leftBottom.second)){
                leftBottom = p;
            }
        }

        set<ll> st(all(grp));

        queue<Pll> q;
        q.push(leftBottom);

        while(!q.empty()){
            auto now = q.front(); q.pop();
            if(inout[idx(now)] == 1) continue;
            inout[idx(now)] = 1;
            rep(k,4){
                Pll nxt = {now.first + dh[k], now.second + dw[k]};
                // if(mp.find(nxt)==mp.end()) continue;
                // if(wall[mp[nxt]]) continue;
                if(st.find(idx(nxt)) == st.end()) continue;
                if(inout[idx(nxt)] != -1) continue;
                q.push(nxt);
            }
        }
    }


    ll H = 200020;
    vvec(Pll) vv(H);
    rep(i,nn){
        auto [x,y] = pp[i];
        // cerr << x << " " << y << " " << inout[i] << endl;
        vv[y+1].emplace_back(x,inout[i]);
    }

    rep(i,H) sort(all(vv[i]));
    ll ans = 0;


    // rep(i,H){
    //     if(vv[i].empty()) continue;
    //     cerr << "--- y=" << i-1 << endl;
    //     for(auto [x,io]:vv[i]){
    //         cerr << x << " " << io << endl;
    //     }
    // }

    for(auto v:vv){
        ll stone = 0;
        vec(ll) hist = {-10,-10};
        ll cnt = 0, pred = -1;
        for(auto [x,io]:v){

            bool flag = false;
            if(io != hist.back()){
                hist.push_back(io);
                flag = true;
            }
            ll hs = hist.size();

            // cerr << x << " " << io << " " << cnt << endl;

            if(io==1){
                if(hist[hs-3]==-1 && hist[hs-2]==0 && hist[hs-1]==1 && flag){
                    cnt--;
                    if(cnt==0){
                        // cerr << x << " " << pred << " " << stone << endl;
                        ans += x - pred - stone;
                        pred = -1;
                        stone = 0;
                    }
                }
            }
            if(io==0){
                if(cnt>0){
                    stone++;
                }
            }
            if(io==-1){
                if(hist[hs-3]==1 && hist[hs-2]==0 && hist[hs-1]==-1 && flag){
                    if(cnt==0) pred = x;
                    cnt++;
                }
            }
        }
    }

    cout << ans << endl;




}



void solve2(){
    ll N;
    cin >> N;


    vec(Pll) p,pp;
    rep(_,N){
        ll x,y;
        cin >> x >> y;
        p.emplace_back(x,y);
        rep(dx,3)rep(dy,3) pp.emplace_back(x+dx-1,y+dy-1);
    }

    pp.emplace_back(llINF,llINF);
    sort(all(pp));
    pp.erase(unique(all(pp)),pp.end());

    auto idx = [&](Pll q){
        auto itr = lower_bound(all(pp),q);
        if(*itr == q) return (ll)(itr - pp.begin());
        else -1;
    };



    // -1:stone, 0:in, 1:out
    ll nn = pp.size();
    vec(ll) visited(nn);
    visited.back() = 1;
    
    dsu uf(nn); 
    for(auto [x,y]:p){
        ll i = idx({x,y});
        visited[i] = -1;
        rep(dx,3)rep(dy,3){
            ll j = idx({x+dx-1,y+dy-1});
            if(j==-1) continue;
            uf.merge(i,j);
        }
    }


    vec(Pll) d4 = {{1,0},{0,1},{-1,0},{0,-1}};
    for(auto v:uf.groups()){
        set<ll> st(all(v));
        queue<ll> q({*st.begin()});
        visited[*st.begin()] = 1;
        while(q.size()){
            ll i = q.front(); q.pop();
            auto [x,y] = pp[i];
            for(auto [dx,dy]:d4){
                ll j = idx({pp[i].first+dx,pp[i].second+dy});
                if(j==-1) continue;
                if(visited[j]) continue;
                if(st.find(j)==st.end()) continue;
                visited[j] = 1;
                q.push(j);
            }
        }
    }

    ll ans = 0;
    ll dep = 0;
    ll start = -1;
    ll prev1 = 1, prev2 = 1;
    ll stone = 0;

    rep1(i,nn-1){
        if(pp[i].first != pp[i-1].first){
            dep = 0;
            start = 0;
            prev1 = 1;
            prev2 = 1;
            stone = 0;
            continue;
        }

        if(visited[i]==-1){
            if(dep) stone++;
        }
        if(visited[i]==0){
            if(prev2==1 && prev1==-1){
                if(dep==0) start = pp[i].second;
                dep++;
            }
        }
        if(visited[i]==1){
            if(prev2==0 && prev1==-1){
                dep--;
                if(dep==0){
                    ans += pp[i].second - start - stone;
                    start = -1;
                    stone = 0;
                }
            }
        }
        if(prev1 != visited[i]){
            prev2 = prev1;
            prev1 = visited[i];
        }
    }

    cout << ans << endl;



}

int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
        // solve2();
    }
    return 0;
}
