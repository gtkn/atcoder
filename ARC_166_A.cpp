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
    ll N;
    cin >> N;
    string S,T;
    cin >> S >> T;

    S+="C"; T+="C";
    // cout << S << " ,,," << T << endl;

    auto f = [](string ss, string tt)->bool{
        // cout << ss << " / " << tt << endl;
        ll nn = ss.size();
        if(nn==0) return true;

        if(tt[0]=='A'){
            if(ss[0]=='B') return false;
            if(ss[0]=='C') ss[0]='A';
        }
        if(tt[nn-1]=='B'){
            if(ss[nn-1]=='A') return false;
            if(ss[nn-1]=='C') ss[nn-1] = 'B';
        }


        ll acnt=0,bcnt=0;
        rep(i,nn){
            if(ss[i]=='A') acnt--;
            if(ss[i]=='B') bcnt--;
        }
        rep(i,nn){
            if(tt[i]=='A') acnt++;
            if(tt[i]=='B') bcnt++;
        }

        if(acnt<0 || bcnt<0) return false;


        rep(i,nn){
            if(ss[i]=='C'){
                if(acnt>0) ss[i]='A';
                else ss[i]='B';
                acnt--;
            }
        }


        vec(ll) sv,tv;
        rep(i,nn) if(ss[i]=='B') sv.push_back(i);
        rep(i,nn) if(tt[i]=='B') tv.push_back(i);

        assert(sv.size() == tv.size());
        rep(i,sv.size()) if(sv[i] < tv[i]) return false;
    

        return true;
    };


    ll st = 0, cnt = 0;
    rep(i,N+1){
        if(S[i]!='C' &&  T[i]=='C') nodame;
        if(S[i]=='C' &&  T[i]=='C'){
            if(!f(S.substr(st,i-st), T.substr(st,i-st))) nodame;
            st = i+1;
        }
    }
    cout << "Yes" << endl;



}

void solve__(){
    ll N;
    cin >> N;
    string S,T;
    cin >> S >> T;

    string S0 = S;

    rep(i,N){
        if(S[i]=='A'){
            if(T[i]=='B'){
                if(i+1<N && S[i+1]!='A'){
                    S[i] = 'B';
                    S[i+1] = 'A';
                }else nodame;
            }else if(T[i]=='C') nodame;
        }else if(S[i]=='B'){
            if(T[i]=='A'){
                if(i>0 && T[i-1]=='B' && S0[i-1] == 'C'){
                    S[i-1] = 'B';
                    S[i] = 'A';
                }else nodame;
            }else if(T[i]=='C') nodame;
        }else{
            S[i]=T[i];
        }
    }
    cout << "Yes" << endl;


}



void solve_(){
    ll N;
    cin >> N;
    string S,T;
    cin >> S >> T;

    vec(ll) s(N),t(N);
    rep(i,N) s[i] = S[i]-'A';
    rep(i,N) t[i] = T[i]-'A';

    if(N==1){
        if(S=="C" || S==T) yn;
        return;
    }



    map<Pll,ll> m;
    ll cnt = 0;
    rep(i,3)rep(j,3) m[{i,j}] = cnt++;

    vvec(bool) vv(cnt,vec(bool)(cnt));
    rep(i,cnt) vv[i][i] = true;
    vv[m[{0,1}]][m[{1,0}]] = true;
    vv[m[{0,2}]][m[{0,0}]] = true;
    vv[m[{0,2}]][m[{0,1}]] = true;
    vv[m[{1,2}]][m[{1,0}]] = true;
    vv[m[{1,2}]][m[{1,1}]] = true;
    vv[m[{1,2}]][m[{1,2}]] = true;
    vv[m[{2,0}]][m[{0,0}]] = true;
    vv[m[{2,0}]][m[{1,0}]] = true;
    vv[m[{2,1}]][m[{0,1}]] = true;
    vv[m[{2,1}]][m[{1,0}]] = true;
    vv[m[{2,1}]][m[{1,1}]] = true;
    rep(i,cnt) vv[m[{2,2}]][i] = true;

    rep(i,N-1){
        ll s0,s1,t0,t1;
        s0 = s[i]; s1 = s[i+1];
        t0 = t[i]; t1 = t[i+1];

        if(!vv[m[{s0,s1}]][m[{t0,t1}]]) nodame;
        s[i+1] = t1;
    }

    cout << "Yes" << endl;




}



int main(){
    int testcasenum=1;
    cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
