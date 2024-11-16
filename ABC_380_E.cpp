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




// //---prod:和, apply:一括変更 のlazy_segtreeのテンプレート---
// struct S{ll sz,val;};
// struct F{ll k;};

// S op(S a,S b){return S{a.sz+b.sz, a.val+b.val};}
// S ee(){return S{0,0};}

// S mapping(F f, S x){
//     if(f.k>=0) return S{ x.sz, x.sz*f.k};
//     return x;
// }
// F composition(F f,F g){
//     if(f.k>=0) return f;
//     return g;
// }
// F id(){return F{-1};}




struct UnionFind{
    // グループのサイズ、要素の親idx、要素から親までのランクの配列
    vector<int> gsize,parent,rank;

    // グループに含まれるidxの最大、最小
    vector<int> gmax, gmin;
    //コンストラクタ　各配列を初期化
    UnionFind(int N){
        gsize = vector<int>(N,1);
        parent = vector<int>(N,-1);
        rank = vector<int>(N);
        gmax = vector<int>(N);
        gmin = vector<int>(N);
        rep(i, N) {
            gmax[i] = i;
            gmin[i] = i;
        }
    }

    //親を求める
    int findparent(int x){
        if(parent[x]<0) return x;
        else return parent[x] = findparent(parent[x]); //rankが小さくなるよう親を再設定
    }

    // 2要素x,yの属するグループを合併
    bool unite(int x, int y){
        x = findparent(x);
        y = findparent(y);
        if(x==y) return false;
        
        if(rank[x] < rank[y]) swap(x,y);
        parent[y] = x;
        gsize[x] += gsize[y];
        gsize[y] = 0;
        gmax[x] = max(gmax[x], gmax[y]);
        gmin[x] = min(gmin[x], gmin[y]);
        if(rank[x]==rank[y]) rank[x]++;
        return true;
    }

    // 要素xが属するグループの最大値
    int getmax(int x){
        return gmax[findparent(x)];
    }

    // 要素xが属するグループの最小値
    int getmin(int x){
        return gmin[findparent(x)];
    }

    
    // 2要素x,yが同じ集合に属するかどうか
    bool same(int x, int y){
        return findparent(x) == findparent(y);
    }


    // 要素xが属するグループのサイズ
    int size(int x){
        return gsize[findparent(x)];
    }



};





void solve(){
    ll N,Q;
    cin >> N >> Q;


    set<tri> st;
    rep(i,N) st.insert(tri{i,i+1,i}); // l, r, c

    vec(ll) ccnt(N,1);


    while(Q--){
        ll t;
        cin >> t;

        if(t==1){
            ll x,c;
            cin >> x >> c;
            x--; c--;

            auto it = st.upper_bound(tri{x,llINF,llINF});
            it--;
            ll l = get<0>(*it);
            ll r = get<1>(*it);
            ll nowc = get<2>(*it);

            ccnt[nowc]-=r-l;
            ccnt[c]+=r-l;

            st.erase(it);

            if(l>0){
                auto it2 = st.upper_bound(tri{l-1,llINF,llINF});
                it2--;
                ll l2 = get<0>(*it2);
                ll r2 = get<1>(*it2);
                ll nowc2 = get<2>(*it2);
                if(nowc2==c){
                    st.erase(it2);
                    l = l2;
                }
            }

            if(r<N){
                auto it2 = st.upper_bound(tri{r,llINF,llINF});
                it2--;
                ll l2 = get<0>(*it2);
                ll r2 = get<1>(*it2);
                ll nowc2 = get<2>(*it2);
                if(nowc2==c){
                    st.erase(it2);
                    r = r2;
                }
            }

            st.insert(tri{l,r,c});



        }else{
            ll c;
            cin >> c;
            c--;

            cout << ccnt[c] << endl;
        }
    }








    // UnionFind uf(N);
    // vec(ll) col(N);
    // rep(i,N) col[i] = i;
    // vec(ll) ccnt(N,1);

    // auto getcol = [&](ll x){
    //     return col[ uf.findparent(x) ];
    // };


    // while(Q--){
    //     ll t;
    //     cin >> t;

    //     if(t==1){
    //         ll x,c;
    //         cin >> x >> c;
    //         x--; c--;

    //         ll sz = uf.size(x);
    //         ll nowc = getcol(x);

    //         ccnt[nowc]-=sz;
    //         ccnt[c]+=sz;
    //         col[x] = c;

    //         ll l = uf.getmin(x);
    //         ll r = uf.getmax(x);


    //         if(l-1>=0 && getcol(l-1)==c){
    //             uf.unite(l-1,x);
    //         }

    //         if(r+1<N && getcol(r+1)==c){
    //             uf.unite(r+1,x);
    //         }


    //     }else{
    //         ll c;
    //         cin >> c;
    //         c--;

    //         cout << ccnt[c] << endl;
    //     }

    //     // rep(i,N) cerr << getcol(i) << " "; cerr << endl;


    // }









    // lazy_segtree<S, op, ee, F, mapping, composition, id> segl(N), segr(N), segc(N);
    // rep(i,N) segl.set(i,S{1,i});
    // rep(i,N) segr.set(i,S{1,i+1});
    // rep(i,N) segc.set(i,S{1,i});

    // vec(ll) ccnt(N,1);

    // while(Q--){
    //     ll t;
    //     cin >> t;

    //     if(t==1){
    //         ll x,c;
    //         cin >> x >> c;
    //         x--; c--;

    //         // cerr << "x = " << x << " c = " << c << endl;

    //         ll l = segl.get(x).val;
    //         ll r = segr.get(x).val;
    //         ll nowc = segc.get(x).val;

    //         ccnt[nowc]-=r-l;
    //         ccnt[c]+=r-l;

    //         if(l>0){
    //             ccnt[ segc.get(l-1).val ]--;
    //             ccnt[c]++;
    //         }
    //         if(r<N){
    //             ccnt[ segc.get(r).val ]--;
    //             ccnt[c]++;
    //         }

    //         ll l2 = max(l-1,0LL);
    //         ll r2 = min(r+1,N);

    //         // cerr << "l = " << l << " r = " << r << endl;
    //         // cerr << "l2 = " << l2 << " r2 = " << r2 << endl;

    //         segl.apply(l2,r2,F{l2});
    //         segr.apply(l2,r2,F{r2});
    //         segc.apply(l2,r2,F{c});


    //     }else{
    //         ll c;
    //         cin >> c;
    //         c--;

    //         cout << ccnt[c] << endl;
    //     }

    //     rep(i,N) cerr << segc.get(i).val << " "; cerr << endl;

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
