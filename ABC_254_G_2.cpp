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


vec(Pll) rangeMerge_cl(vec(Pll) v){
    // 閉区間[l,r]の集合vを受け取ってマージする
    vec(Pll) res;
    if(v.empty()) return res;

    sort(all(v));
    res.push_back(v[0]);
    for(Pll vi:v){
        if(res.back().first <= vi.first && vi.first <= res.back().second){
            chmax(res.back().second, vi.second);
        }else{
            res.push_back(vi);
        }
    }

    return res;
}


void doubling(vvec(ll) &db, ll xx){
    // 0列目まで埋めたダブリングの配列の残りを計算する
    // 遷移先がない場合はxx
    ll n,m;
    n = db.size();
    m = db[0].size();

    rep(j,m-1)rep(i,n){
        if(db[i][j]==xx){
            db[i][j+1] = xx;
        }else{
            db[i][j+1] = db[ db[i][j] ][j];
        }
    }
}







void solve(){
    ll N,M,Q;
    cin >> N >> M >> Q;

    vvec(Pll) el(N);
    rep(_,M){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        el[a].emplace_back(b,c);
    }

    vec(ll) X(Q),Y(Q),Z(Q),W(Q);
    rep(i,Q) cin >> X[i] >> Y[i] >> Z[i] >> W[i];
    rep(i,Q) X[i]--, Z[i]--;

    set<ll> st;
    rep(i,N){
        for(auto [b,c]:el[i]){
            st.insert(b);
            st.insert(c);
        }
    }
    rep(i,Q){
        st.insert(Y[i]);
        st.insert(W[i]);
    }
    ll nn = 0;
    map<ll,ll> mp;
    for(ll b:st) mp[b] = nn++;
    vec(ll) pm(nn);
    for(auto [b,i]:mp) pm[i] = b;



    rep(i,N) el[i] = rangeMerge_cl(el[i]);
    rep(i,N) sort(all(el[i]));

    vec(Pll) elall;
    rep(i,N) elall.insert(elall.end(), all(el[i]));
    for(ll b:st) elall.emplace_back(b,b);
    sort(all(elall));
    {
        vec(Pll) tmp;
        for(auto [l,r]:elall){
            if(!tmp.empty() && tmp.back().second >= r) continue;
            tmp.emplace_back(l,r);
        }
        swap(tmp,elall);
    }
    vec(Pll) elall_merged = rangeMerge_cl(elall);
    
    
    sort(all(elall_merged));

    // cerr << "elall.size() = " << elall.size() << endl;



    // cerr << "nn = " << nn << endl;


    auto upper_floor = [&](ll frm, const vec(Pll)& e)->ll{
        auto itr = upper_bound(all(e), Pll(frm,llINF));
        if(itr == e.begin()) return frm;
        itr--;
        auto [b,c] = *itr;
        assert(b<=frm);
        return max(c,frm);
    };

    auto lower_floor = [&](ll frm, const vec(Pll)& e)->ll{
        auto itr = upper_bound(all(e), Pll(frm,llINF));
        if(itr == e.begin()) return frm;
        itr--;
        auto [b,c] = *itr;
        assert(b<=frm);
        if(c<frm) return frm;
        return b;
    };

    


    auto can_reach = [&](ll frm, ll to)->bool{
        ll c = upper_floor(frm,elall_merged);
        return to<=c;
    };


    ll L = 24;
    vvec(ll) db(nn,vec(ll)(L,-1));
    rep(b,nn){
        db[b][0] = mp[upper_floor(pm[b], elall)];
    }
    doubling(db,-1);
    rep(i,nn)rep(j,L) assert(db[i][j]!=-1);


    // cerr << "db.size() = " << db.size() << endl;




    auto f = [&](ll frm, ll to)->ll{
        assert(can_reach(frm,to));

        auto go_up = [&](ll _ffrm, ll k)->ll{
            ll now = _ffrm;
            rep(i,L)if(bit(k,i)) now = db[now][i];
            return now;
        };

        ll ffrm = mp[frm], tto = mp[to];


        ll l = 0, r = (1<<L);
        while(r-l>1){
            ll mid = (l+r)/2;
            if(go_up(ffrm,mid)<tto) l = mid;
            else r = mid;
        }
        return r;
    };





    rep(i,Q){
        // cerr << "i = " << i << endl;
        ll x = X[i], y = Y[i], z = Z[i], w = W[i];
        if(y>w){
            swap(y,w);
            swap(x,z);
        }

        if(y==w){
            cout << (x==z?0:1) << endl;
            continue;
        }

        if(!can_reach(y,w)){
            cout << -1 << endl;
            continue;
        }

        // cerr << "x = " << x << ", y = " << y << ", z = " << z << ", w = " << w << endl;

        ll res = w-y;

        ll y2 = upper_floor(y,el[x]);
        ll w2 = lower_floor(w,el[z]);


        if(y2>=w2){
            if(x!=z) res++;
            cout << res << endl;
            continue;
        }

        res += f(y2,w2)+1;
        cout << res << endl;

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
