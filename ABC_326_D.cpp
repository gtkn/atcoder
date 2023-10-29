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
#define sayno { puts("No"); return;}
#define sayyes { puts("Yes"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------


void solve(){
    ll N;
    cin >> N;

    string R,C;
    cin >> R >> C;

    string abc = "ABC";
    while(abc.size() < N) abc.push_back('.');
    sort(all(abc));
    
    vvec(string) vvr(3);

    do{
        for(char c:abc){
            if(c!='.'){
                vvr[c-'A'].push_back(abc);
                break;
            }
        }
    }while(next_permutation(all(abc)));
     

    // rep(i,3){
    //     cout << i << "---" << endl;
    //     for(string s:vvr[i]) cout << s << endl;
    // }


    vec(string) res;
    auto dfs = [&](auto dfs)->bool{

        vec(bool) cc(N);
        for(string r:res){
            rep(i,N){
                if(cc[i]) continue;
                if(r[i]=='.') continue;

                if(C[i]!=r[i] ) return false;
                else cc[i]=true;
            }
        }

        vec(ll) cnt(N);
        for(string r:res){
            rep(i,N){
                if(r[i]=='.') continue;
                ll ii = r[i]-'A';
                if(bit(cnt[i],ii)) return false;
                cnt[i] |= (1<<ii);
            }
        }


        if(res.size()==N){
            bool chk = true;
            rep(i,N) chk &= cc[i];
            rep(i,N) chk &= cnt[i]==7;
            if(chk) return true;
        }

        ll ii = res.size();
        for(string r:vvr[R[ii]-'A']){
            res.push_back(r);
            if(dfs(dfs)) return true;
            res.pop_back();
        }
        return false;
    };

    if(dfs(dfs)){
        cout << "Yes" << endl;
        rep(i,N) cout << res[i] << endl;
    }else{
        cout << "No" << endl;
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
