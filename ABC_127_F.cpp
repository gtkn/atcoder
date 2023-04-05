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
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

using ll = long long;
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
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------



struct Solver{
 
    
    struct slope_trick{
        ll C, fmin;
        priority_queue<ll> L;
        priority_queue<ll,vector<ll>,greater<ll>> R;

        slope_trick(){
            C=0; fmin=0;
            L.push(-llINF);
            R.push(llINF);
        }

        // LeRUの方
        void addr(ll a){
            fmin += max(L.top() - a, 0LL);

            L.push(a);
            R.push(L.top());
            L.pop();
        }

        void addl(ll a){
            fmin += max(a-R.top(), 0LL);

            R.push(a);
            L.push(R.top());
            R.pop();
        }

        void addc(ll b){
            C += b;
        }


    };


    void solve(){
        ll Q;
        cin >> Q;

        slope_trick st;

        while(Q--){
            ll t; cin >> t;
            if(t==1){
                ll a,b;
                cin >> a >> b;

                st.addc(b);
                st.addl(a);
                st.addr(a);

            }else{
                cout << st.L.top() << " " << st.C + st.fmin << endl;

            }


        }



    }



    // なぜかTLEする、あとで調べる
    void solve_botu(){
        ll Q;
        cin >> Q;

        vec(tri) q(Q);
        set<ll> s;
        rep(i,Q){
            cin >> q[i][0];
            if(q[i][0]==1){
                cin >> q[i][1] >> q[i][2];
                s.insert(q[i][1]);
            }
        }

        map<ll,ll> m;
        ll cnt = 0;
        for(ll si:s) m[si] = cnt++;


        fenwick_tree<ll> fw(cnt+10);
        priority_queue<ll> l,r;
        l.push(-llINF);
        r.push(llINF);
        multiset<ll> used;

        ll tot = 0;
        rep(i,Q){
            if(q[i][0]==1){
                ll x = q[i][1];
                rep(_,2){
                    if( l.top() > x){
                        r.push(l.top());
                        l.pop();
                        l.push(x);
                    }else{
                        r.push(x);
                    }
                }

                fw.add( m[x], x);
                tot += q[i][2];
                used.insert(x);

            }else{
                ll n=used.size();
                ll th = (n-1)/2;

                // ll l=-1e9-10, r=1e9+10;
                // while(r-l>1){
                //     ll mid = (l+r)/2;
                //     auto itr = used.lower_bound(mid);
                //     if(distance(used.begin(), itr) <= th ) l=mid;
                //     else r=mid;
                // }
                ll x = l.top();
                ll a = distance(used.begin(), used.lower_bound(x) );
                
                ll res = tot;
                res += a*x - fw.sum(0,m[x]);
                res += fw.sum(m[x],cnt+10) - (n-a)*x;

                cout << l.size() << endl;
                cout << x << " " << res << endl;
            }

        }





    }
};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
    }
    return 0;
}
