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

// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}


// 0以上b未満の整数をランダムに返す関数
ll RandInt2(const ll& b){
    return rand()%b;
}


char to_char(ll n){
    if(n<26) return 'a'+n;
    return 'A'+n-26;
}


string make_string(){
    ll N = RandInt(4,30);

    string S;
    rep(_,N){
        ll x = RandInt2(52);
        S.push_back(to_char(x));
    }

    ll M = RandInt(1,5);
    rep(_,M){
        ll pos = RandInt2(N);
        S[pos] = '?';
    }

    return S;
}




mint solve_test(string S){
    ll N = S.size();
    vec(ll) pos;
    rep(i,N) if(S[i]=='?') pos.push_back(i);
    ll m = pos.size();

    ll ptn_max = 1;
    rep(_,m) ptn_max *= 52;
    mint ans = 0;
    rep(ptn,ptn_max){
        string t = S;
        ll tmp = ptn;
        rep(i,m){
            ll c = tmp % 52;
            tmp /= 52;
            t[pos[i]] = to_char(c);
        }

        vec(ll) cnt(26);
        ll cmax = 0;
        bool isok = true;
        rep(i,N-1){
            if(t[i]>='a' && t[i+1]<='Z' && cmax>=2) isok=false;
            if(t[i]<='Z'){
                cnt[t[i]-'A']++;
                chmax(cmax,cnt[t[i]-'A']);
            }
        }
        if(isok) ans++;

    }
    return ans;
}





void solve(){
    string S;
    cin >> S;

    // S = make_string();
    // cerr << S << endl;
    // cerr << solve_test(S).val() << endl;


    ll N = S.size();

    vec(ll) cnt(27);

    ll M = 300030;
    vec(mint) fa(M+1),af(M+1);
    fa[0] = 1;
    rep1(i,M) fa[i] = fa[i-1]*i;
    rep(i,M+1) af[i] = fa[i].inv();

    auto perm = [&](ll n, ll k)->mint{
        if(n<k) return 0;
        return fa[n]*af[n-k];
    };
    auto comb = [&](ll n, ll k)->mint{
        if(n<k) return 0;
        return fa[n]*af[k]*af[n-k];
    };


    vec(mint) ex(N+1);
    ex[0] = 1;
    rep1(i,N) ex[i] = ex[i-1]*26;


    auto f = [&](char c)->mint{ // cが1つだけ含まれる場合の数
        rep(i,26) if(cnt[i]>=2) return 0;
        ll n = c-'A';
        mint res = 0;
        
        ll m = cnt[26];
        ll rem = 0;
        rep(i,26)if(i!=n && cnt[i]==0) rem++;
            
        if (cnt[n]==1){
            rep(k,rem+1){
                if(m-k<0) break;
                res += perm(rem,k) * comb(m,k) * ex[m-k];
            }
        }else{
            rep(k,rem+1){
                if(m-1-k<0) break;
                res += m * perm(rem,k) * comb(m-1,k) * ex[m-1-k];
            }
        }
        return res;
    };


    vvec(mint) dp(N+1,vec(mint)(3));
    dp[0][0] = 1;

    rep(i,N){
        if(S[i]=='?'){
            for(char c = 'A'; c<='Z'; c++){
                mint x = f(c);
                dp[i+1][0] += (dp[i][0] - x);
                dp[i+1][1] += x;
                dp[i+1][1] += dp[i][1];
            }
            dp[i+1][0] += dp[i][0]*26;
            dp[i+1][2] += dp[i][1]*26;
            dp[i+1][2] += dp[i][2]*26;

            cnt[26]++;
        }else if(S[i]<='Z'){
            mint x = f(S[i]);
            dp[i+1][0] += (dp[i][0] - x);
            dp[i+1][1] += x;
            dp[i+1][1] += dp[i][1];
            
            cnt[S[i]-'A']++;
        }else{
            dp[i+1][0] += dp[i][0];
            dp[i+1][2] += dp[i][1];
            dp[i+1][2] += dp[i][2];
        }
    }

    // rep(i,N+1){
    //     rep(j,3) cout << dp[i][j].val() << ' ';
    //     cerr << " : " << S.substr(0,i) << endl;
    // }

    
    mint ans = 0;
    rep(j,3) ans += dp[N][j];
    cout << ans.val() << endl;


}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
