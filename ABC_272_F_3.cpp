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

// using mint = modint1000000007;
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



void solve(){
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;


    string ssxtt = S + S + T + T;
    // vector<int> ssxtt;
    // rep(i,N) ssxtt.push_back(2*(S[i]-'a'));
    // rep(i,N) ssxtt.push_back(2*(S[i]-'a'));
    // ssxtt.push_back(iINF);
    // rep(i,N) ssxtt.push_back(2*(T[i]-'a')+1);
    // rep(i,N) ssxtt.push_back(2*(T[i]-'a')+1);
    // for(ll x: ssxtt) cerr << (char)(x+'a'); cerr << endl;

    vector<int> sa = suffix_array(ssxtt);

    vector<mint> hash(ssxtt.size() + 1, 0);
    vector<mint> power(ssxtt.size() + 1, 1);
    mint base = 31;
    
    for (int i = 0; i < ssxtt.size(); ++i) {
        hash[i + 1] = hash[i] * base + (ssxtt[i] - 'a' + 1);
        power[i + 1] = power[i] * base;
    }

    auto get_hash = [&](int l, int r) {
        return hash[r] - hash[l] * power[r-l];
    };


    vec(Pll) v;
    Pll cnt = {0,0};
    mint prev = 0;
    

    for(ll idx:sa){
        bool ist = false;
        if(idx < N){
            ist=false;
        }else if(idx < 2*N){
            continue;
        }else if(idx < 3*N){
            ist=true;
        }else{
            continue;
        }

        mint h = get_hash(idx, idx+N);
        if(h != prev){
            v.push_back(cnt);
            cnt = {0,0};
            prev = h;
        }
        if(ist) cnt.second++;
        else cnt.first++;
    }
    v.push_back(cnt);

    ll ans = 0;
    ll scnt = 0;
    for(auto [s,t]:v){
        scnt += s;
        ans += t * scnt;
    }

    cout << ans << endl;




    // ll scnt = 0, tcnt = 0;
    // ll ans = 0;
    // for(ll idx:sa){
    //     if(idx < N){
    //         scnt++;
    //         // rep(i,N) cerr << (char)(ssxtt[idx+i]/2+'a'); cerr << " : S" << endl;
    //     }else if(idx < 2*N){
    //         continue;
    //     }else if(idx == 2*N){
    //         continue;
    //     }else if(idx < 3*N+1){
    //         ans+=scnt;
    //         tcnt++;
    //         // rep(i,N) cerr << (char)(ssxtt[idx+i]/2+'a'); cerr << " : T" << endl;
    //     }else{
    //         continue;
    //     }
    // }

    // cout << ans << endl;



    // string ss = S + S;
    // string tt = T + T;

    // vector<int> sa = suffix_array(ss);
    // vector<int> ta = suffix_array(tt);

    // vector<int> lcpa = lcp_array(ss, sa);





    // ll M = 26;
    // vvec(ll) svv(M),tvv(M);
    // rep(i,N) svv[S[i]-'a'].push_back(i);
    // rep(i,N) tvv[T[i]-'a'].push_back(i);

    // ll ans = 0;
    // rep(j,M)rep(i,j) ans += (ll)svv[i].size() * (ll)tvv[j].size();

    // // cerr << "ans: " << ans << endl;

    // // rep(i,M){
    // //     cerr << i << " ---" << endl;
    // //     for(ll si:svv[i]) cerr << si << " "; cerr << endl;
    // //     for(ll ti:tvv[i]) cerr << ti << " "; cerr << endl;
    // // }


    // auto f = [&](auto f, vec(ll) s, vec(ll) t, ll x)->void{
    //     if(x==N){
    //         ans += (ll)s.size() * (ll)t.size();
    //         return;
    //     }

    //     vvec(ll) ss(M),tt(M);
    //     for(ll si:s) ss[S[(si+x)%N]-'a'].push_back(si);
    //     for(ll ti:t) tt[T[(ti+x)%N]-'a'].push_back(ti);

    //     // if(x==1) cerr << S[s[0]] << " !" << endl;
    //     // rep(i,M){
    //     //     cerr << i << " ---" << endl;
    //     //     for(ll si:ss[i]) cerr << si << " "; cerr << endl;
    //     //     for(ll ti:tt[i]) cerr << ti << " "; cerr << endl;
    //     // }


    //     rep(j,M)rep(i,j) ans += (ll)ss[i].size() * (ll)tt[j].size();
    //     rep(i,M)if(!ss[i].empty() && !tt[i].empty()) f(f, ss[i], tt[i], x+1);
    // };

    // rep(i,M) if(!svv[i].empty() && !tvv[i].empty()) f(f,svv[i],tvv[i],1);

    // cout << ans << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
