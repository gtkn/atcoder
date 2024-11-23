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
using mint = modint998244353;
// using mint = modint;
// mint::set_mod(P);


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


struct S{
    bool iswin;
    ll start,len,pred_len;
    S(bool iswin=false, ll start=-1, ll len=-1, ll pred_len=0):iswin(iswin),start(start),len(len),pred_len(pred_len){}
};

S op(S a, S b){
    if(!a.iswin) return a;
    return b;
}

S ee(){
    return S(true);
}


void solve(){
    ll N,L,R;
    cin >> N >> L >> R;

    set<Pll> rngs;
    rngs.insert({1,N});

    auto update = [&](ll a,ll b)->void{
        auto it = rngs.upper_bound({a,llINF});
        it--;
        auto [l,r] = *it;
        // cerr << "update range : " << l << " " << r << ", " << a << " " << b << endl;
        rngs.erase(it);
        // cerr << "add " << l << " " << a-1 << endl;
        if(l<=a-1) rngs.insert({l,a-1});
        // cerr << "add " << a+b << " " << r << endl;
        if(a+b<=r) rngs.insert({a+b,r});

        return;
    };

    if(L==R && (N&1) != (L&1)){
        vec(ll) gr(N+1,-1);
        gr[0] = 0;
        vec(bool) v(N+1);
        rep1(i,N){
            vec(ll) memo;
            rep(l,i){
                ll r = i-l-L;
                if(r<0) break;
                memo.push_back( gr[l]^gr[r] );
            }
            for(ll j:memo) v[j] = true;
            rep(j,N+1){
                if(v[j]) continue;
                gr[i] = j;
                break;
            }
            // assert(gr[i]!=-1);
            for(ll j:memo) v[j] = false;
        }
        // rep(i,N+1) cerr << gr[i] << " "; cerr << endl;


        if(gr[N]==0){
            cout << "Second" << endl;
            ll a,b;
            cin >> a >> b;
            update(a,b);
        }
        else{
            cout << "First" << endl;
            // cerr << "!" << endl;
        }

        while(true){
            bool answered = false;
            ll now_gr = 0;
            for(auto [li,ri]:rngs){
                ll w = ri-li+1;
                now_gr ^= gr[w];
            }
            // cerr << "now_gr : " << now_gr << endl;
            // assert(now_gr!=0);


            for(auto [li,ri]:rngs){
                ll w = ri-li+1;
                if(gr[w]==0) continue;
                rep(l,w){
                    ll r = w-l-L;
                    if(r<0) break;
                    // assert(r>=0);
                    ll nxt_gr = now_gr ^ gr[l] ^ gr[r] ^ gr[w];
                    if(nxt_gr!=0) continue;
                    ll x = li + l;
                    cout << x << " " << L << endl;
                    // for(auto [li,ri]:rngs) cerr << "rng : " << li << " ~ " << ri << endl;
                    update(x,L);
                    answered = true;
                    break;
                }
                if(answered) break;
            }
            // assert(answered);
            // cerr << "rngs size : " << rngs.size() << endl;
            // for(auto [li,ri]:rngs) cerr << "rng : " << li << " ~ " << ri << endl;

            ll a,b;
            cin >> a >> b;
            if(a==0 && b==0) break;
            if(a==-1 && b==-1) break;
            update(a,b);
        }

        return;
    }



    cout << "First" << endl;
    ll c = N/2;
    ll r0;
    {
        ll y = L;
        if((y&1)!=(N&1)) y++;
        ll x = c - y/2 + 1;
        cout << x << " " << y << endl;
        update(x,y);
        r0 = x+y-1;
    }

    // cerr << "r0 : " << r0 << ", c : " << c << endl;
    while(true){
        // for(auto [li,ri]:rngs) cerr << "rng : " << li << " ~ " << ri << endl;
        ll a,b;
        cin >> a >> b;
        if(a==0 && b==0) break;
        if(a==-1 && b==-1) break;
        update(a,b);

        ll x, y = b;
        if(a-1<c){
            x = a + r0 ;
        }else{
            x = a - r0;
        }
        cout << x << " " << y << endl;
        update(x,y);
        
    }







    // vec(S) v(N+1);
    // rep(i,N+1) v[i] = S{false,-1,-1,i};
    // segtree<S,op,ee> seg(v);

    // rep1(l,N){
    //     rep(start,l){
    //         ll l1 = start;
    //         if(seg.get(l1).iswin) continue;
    //         ll l2max = l - (start+L);
    //         ll l2min = l - (start+R);
    //         if(l2max<0) continue;
    //         chmax(l2min,0LL);
    //         S ss = seg.prod(l2min,l2max+1);
    //         if(ss.iswin) continue;
    //         ll l2 = ss.pred_len;
    //         if(l==4){
    //             cerr << "l1 : " << l1 << ", l2 : " << l2 << endl;
    //             cerr << l2min << " " << l2max << endl;
    //         }
    //         seg.set(l,S(true,start,l-l1-l2,l));
    //         break;
    //     }
    // }

    // rep(i,N+1) cout << seg.get(i).iswin << " " << seg.get(i).start << " " << seg.get(i).len << " " << seg.get(i).pred_len << endl;


    // set<Pll> rngs;
    // rngs.insert({1,N});

    // auto update = [&](ll a,ll b)->void{
    //     auto it = rngs.upper_bound({a,llINF});
    //     it--;
    //     auto [l,r] = *it;
    //     cerr << "update range : " << l << " " << r << ", " << a << " " << b << endl;
    //     // assert(l <= a && a <= r);
    //     rngs.erase(it);
    //     if(l<=a-1) rngs.insert({l,a-1});
    //     if(a+b<=r) rngs.insert({a+b,r});
    // };

    // auto f = [&]()->void{
    //     // assert(rngs.size() > 0);
    //     auto [l,r] = *rngs.begin();
    //     ll len = r-l+1;
    //     // cerr << "pred range : " << l << " " << r << ", " << len << endl;

    //     S ss = seg.get(len);
    //     // assert(ss.iswin);
    //     // cerr << "pred seg : " << ss.start << " " << ss.len << endl;

    //     ll x = l + ss.start;
    //     ll y = ss.len;

    //     update(x,y);
    //     cout << x << " " << y << endl;
    //     // return {x,y};
    // };




    // if(seg.get(N).iswin){
    //     cout << "First" << endl;
    //     f();
    // }else{
    //     cout << "Second" << endl;
    // }

    // while(true){
    //     for(auto [li,ri]:rngs) cerr << "rng : " << li << " " << ri << endl;
    //     ll a,b;
    //     cin >> a >> b;
    //     if(a==0 && b==0) break;
    //     if(a==-1 && b==-1) break;
    //     update(a,b);
    //     f();
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
