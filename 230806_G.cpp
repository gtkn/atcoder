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
//using tri = tuple<ll,ll,ll>;
using tri = array<ll,3>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

map<ll,ll> compressCoordinates(vec(ll) &v){
    // 値の集合vを受け取って座圧する
    // res[val] = idx
    // v[idx] = val となるように入力のvも変更する

    sort(all(v));
    v.erase(unique(all(v)),v.end());

    ll nn = v.size();
    map<ll,ll> res;
    rep(i,nn) res[ v[i] ] = i;

    return res;
}


vec(Pll) rangeMerge(vec(Pll) v){
    // 半開区間[l,r)の集合vを受け取ってマージする
    vec(Pll) res;
    if(v.empty()) return res;

    sort(all(v));
    res.push_back(v[0]);
    for(Pll vi:v){
        if(res.back().first <= vi.first && vi.first < res.back().second){
            chmax(res.back().second, vi.second);
        }else{
            res.push_back(vi);
        }
    }
    return res;
}


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
    vec(ll) A(M),B(M),C(M);
    rep(i,M) cin >> A[i] >> B[i] >> C[i];

    rep(i,M) A[i]--;

    vec(ll) X(Q),Y(Q),Z(Q),W(Q);
    rep(i,Q) cin >> X[i] >> Y[i] >> Z[i] >> W[i];

    rep(i,Q) X[i]--;
    rep(i,Q) Z[i]--;


    vec(ll) za={0};
    rep(i,M) za.push_back(B[i]);
    rep(i,M) za.push_back(C[i]);
    rep(i,Q) za.push_back(Y[i]);
    rep(i,Q) za.push_back(W[i]);

    auto az = compressCoordinates(za);
    ll nn = za.size();




    vvec(Pll) el(N,{{0,0}});
    rep(i,M) el[A[i]].emplace_back(az[B[i]], az[C[i]]);
    rep(i,N) el[i] = rangeMerge_cl(el[i]);



    vec(Pll) elall = {{0,0}};
    rep(i,M) elall.emplace_back(az[B[i]], az[C[i]]);
    elall = rangeMerge_cl(elall);


    // rep(i,N){
    //     cout << "---" << i << endl;
    //     for(Pll e:el[i]) cout << e.first << " " << e.second << " : " << za[e.first] << " " << za[e.second] << endl;
    // }
    // cout << "---all"  << endl;
    // for(Pll e:elall) cout << e.first << " " << e.second << " : " << za[e.first] << " " << za[e.second] << endl;




    vec(ll) chk(nn);
    rep(i,nn) chk[i]=i;
    for(Pll e:elall){
        for(ll i=e.first; i<=e.second; i++) chk[i]=e.first;
    }



    
    auto gotop = [&](ll a, ll b){
        // ビルaのb階から行ける最上階を求める
        ll res = b;
        auto itr = upper_bound(all(el[a]), make_pair(b+1,-llINF) );
        ll d = distance(el[a].begin(), itr)-1;
        if(d>=0) chmax(res, el[a][d].second);
        return res;
    };

    auto gobtm = [&](ll a, ll b){
        // ビルaのb階から行ける最下階を求める
        ll res = b;
        auto itr = upper_bound(all(el[a]), make_pair(b+1,-llINF) );
        ll d = distance(el[a].begin(), itr)-1;
        if(d>=0) if(el[a][d].second >= b) chmin(res, el[a][d].first);
        return res;
    };


    ll lnn = log2(nn)+2;
    vvec(ll) db(nn,vec(ll)(lnn, llINF));

    vec(ll) memo(nn);
    rep(i,M) chmax(memo[ az[B[i]] ], az[C[i]]);
    ll tmp = 0;
    rep(i,nn){
        chmax(tmp, memo[i]);
        db[i][0] = max(i, tmp);
    }
    doubling(db, llINF);


    auto upk = [&](ll now,ll k){
        ll cnt = 0;
        while(k){
            if(k&1) now = db[now][cnt];
            k>>=1;
            cnt++;
        }
        return now;
    };



    rep(qi,Q){
        ll xi,yi,zi,wi;
        xi = X[qi];
        yi = az[Y[qi]];
        zi = Z[qi];
        wi = az[W[qi]];




        if(yi > wi){
            swap(xi,zi);
            swap(yi,wi);
        }

        ll res = abs(za[wi]-za[yi]);

        yi = gotop(xi, yi);
        wi = gobtm(zi, wi);

        // cout << za[yi] << " " << za[wi] << endl;

        if(yi>=wi){
            if(xi!=zi) res++;
            cout << res << endl;
            continue;
        }


        if(chk[yi]!=chk[wi]){
            cout << -1 << endl;
            continue;
        }


        ll l=0,r=(1<<lnn);
        while(r-l>1){
            ll mid = (l+r)/2;
            if(upk(yi,mid) >= wi ) r=mid;
            else l=mid;
        }
        res += r+1;


        // // for(ll ii=0; ii<lnn && yi<wi; ii++){
        // while(yi<wi){
        //     auto itr = lower_bound(all(db[yi]), wi);
        //     if(itr != db[yi].begin()) itr--;

        //     ll d = distance(db[yi].begin(), itr);
        //     res += (1<<d);

        //     ll nxt = *itr;

        //     // cout <<yi << " " << za[yi] << " to "<<  nxt << " " << za[nxt] << "::" << d << endl;

        //     yi = nxt;
        // }
        // res++;

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
