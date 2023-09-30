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
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define nodame { puts("No"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){

    vvvec(ll) vvv(3,vvec(ll)(4,vec(ll)(4)));

    rep(i,3){
        rep(j,4){
            string s; cin >> s;
            rep(k,4) vvv[i][j][k] = (s[k]=='#');
        }
    }


    ll chk = 0;
    rep(i,3)rep(j,4)rep(k,4) chk+=vvv[i][j][k];
    if(chk!=16) nodame;




    auto mov = [](vvec(ll) vv, ll dh, ll dw)->vvec(ll){
        vvec(ll) res = vvec(ll)(4,vec(ll)(4));
        bool isok=true;

        rep(i,4)rep(j,4){
            if(!vv[i][j]) continue;
            ll ii = i+dh, jj = j+dw;
            if(ii>=0 && ii<4 && jj>=0 && jj<4){
                res[ii][jj] = vv[i][j];
            }else{
                vv[0][0]=-llINF;
                return res;
            }
        }
        return res;
    };


    auto rot = [](vvec(ll) vv)->vvec(ll){
        vvec(ll) res(4,vec(ll)(4));
        rep(i,4)rep(j,4) res[3-j][i] = vv[i][j];
        return res;
    };



    vvvec(ll) p0,p1,p2;
    vvec(ll) now;


    // now = vvv[0];
    // rep(i,4){
    //     rep(j,4) cout << now[i][j]; cout << endl;
    // }
    // rep(_,3){
    //     cout << "=-" << endl;
    //     now = rot(now);
    //     rep(i,4){
    //         rep(j,4) cout << now[i][j]; cout << endl;
    //     }

    // }
    // return;

    now = vvv[0];
    rep(r,1){        
        for(ll h=-3; h<=3; h++)for(ll w=-3; w<=3; w++){
            vvec(ll) tmp = mov(now, h,w);
            if(tmp[0][0]== -llINF) continue;
            p0.push_back(tmp);
        }
        now = rot(now);
    }

    now = vvv[1];
    rep(r,4){        
        for(ll h=-3; h<=3; h++)for(ll w=-3; w<=3; w++){
            vvec(ll) tmp = mov(now, h,w);
            if(tmp[0][0]== -llINF) continue;
            p1.push_back(tmp);
        }
        now = rot(now);
    }
    
    now = vvv[2];
    rep(r,4){        
        for(ll h=-3; h<=3; h++)for(ll w=-3; w<=3; w++){
            vvec(ll) tmp = mov(now, h,w);
            if(tmp[0][0]== -llINF) continue;
            p2.push_back(tmp);
        }
        now = rot(now);
    }
    

    auto check = [](vvec(ll) vv){
        bool res = true;
        rep(i,4)rep(j,4) if(vv[i][j]!=1) res=false;
        return res;
    };

    string ans = "No";
    for(auto vv0:p0)for(auto vv1:p1)for(auto vv2:p2){
        vvec(ll) cnt(4,vec(ll)(4));
        rep(i,4)rep(j,4) cnt[i][j] += vv0[i][j];
        rep(i,4)rep(j,4) cnt[i][j] += vv1[i][j];
        rep(i,4)rep(j,4) cnt[i][j] += vv2[i][j];

        if(check(cnt)) ans = "Yes";
    }
    cout << ans << endl;



}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
