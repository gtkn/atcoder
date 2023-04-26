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
using ld = long double;

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


ll op(ll a,ll b){return a+b;}
ll ee(){return 0;}




struct Solver{

    void solve(){
        ll N;
        cin >> N;
        vec(ll) A(N),B(N);
        rep(i,N) cin >> A[i] >> B[i];

        ll Q;
        cin >> Q;
        vec(tri) qu(Q);
        rep(i,Q){
            ll t;
            cin >> t;
            if(t<3){
                ll x,y;
                cin >> x >> y;
                qu[i] = {t,x-1,y};
            }else{
                ll x;
                cin >> x;
                qu[i] = {t,x,-1};
            }
        }
    
        set<ll> s;
        rep(i,N) s.insert(A[i]);
        for(tri qi:qu) if(qi[0]==1) s.insert(qi[2]);

        ll nn=s.size();
        vec(ll) mr;
        for(ll si:s) mr.push_back(si);
        sort(all(mr));
        reverse(all(mr));

        map<ll,ll> m;
        rep(i,nn) m[mr[i]] = i;

        // segtree<ll,op,ee> numseg(nn),totseg(nn);
        fenwick_tree<ll> numfw(nn),totfw(nn);
        rep(i,N) numfw.add( m[A[i]], B[i] );
        rep(i,N) totfw.add( m[A[i]], B[i]*A[i]);

        for(tri qi:qu){
            if(qi[0]<3){
                ll x,y;
                x = qi[1]; y=qi[2];

                numfw.add( m[A[x]], -B[x]);
                totfw.add( m[A[x]], -A[x]*B[x]);

                if(qi[0]==1) A[x] = y;
                else B[x]=y;

                numfw.add( m[A[x]], B[x]);
                totfw.add( m[A[x]], A[x]*B[x]);
            }else{
                ll x=qi[1];
                if(numfw.sum(0,nn) < x){
                    cout << -1 << endl;
                    continue;
                }


                ll l=0,r=nn+1;
                while(r-l>1){
                    ll mid = (l+r)/2;
                    if(numfw.sum(0,mid) <= x) l=mid;
                    else r=mid;
                }

                ll res = totfw.sum(0,l);
                ll rem = x-numfw.sum(0,l);
                res += mr[l]*rem;

                cout << res << endl;


            }
            

        }







        


    
    
    
    }







    void solve_(){
        ll N;
        cin >> N;
        vec(ll) A(N),B(N);
        rep(i,N) cin >> A[i] >> B[i];

        ll Q;
        cin >> Q;
        vec(tri) qu(Q);
        rep(i,Q){
            ll t;
            cin >> t;
            if(t<3){
                ll x,y;
                cin >> x >> y;
                qu[i] = {t,x-1,y};
            }else{
                ll x;
                cin >> x;
                qu[i] = {t,x,-1};
            }
        }

        vec(tri) v(N);
        rep(i,N) v[i] = {A[i],B[i],i};
        ll cnt = N;

        vec(ll) memo(N);
        rep(i,N) memo[i]=i;

        for(tri qi:qu){
            if(qi[0]==3) continue;
            if(qi[0]==1){
                ll x,y,idx;
                x = qi[1]; y=qi[2]; idx=memo[x];
                // v.emplace_back(y, v[idx][1], cnt);
                v.push_back({y, v[idx][1], cnt});
            }
            if(qi[0]==2){
                ll x,y,idx;
                x = qi[1]; y=qi[2]; idx=memo[x];
                // v.emplace_back(v[idx][0], y, cnt);
                v.push_back({v[idx][0], y, cnt});
            }
            cnt++;
        }

        sort(all(v));
        reverse(all(v));


        vec(ll) ten(cnt), num(cnt), tot(cnt);
        rep(i,cnt){
            if(v[i][2]<N){
                ten[i] = v[i][0];
                num[i] = v[i][1];
                tot[i] = v[i][0]*v[i][1];
                memo[v[i][2]] = i;
            }
        }

        vec(ll) rv(cnt);
        rep(i,cnt) rv[v[i][2]] = i;

        segtree<ll,op,ee> numseg(num),totseg(tot);

        // rep(i,cnt) cout << i << " ; " << v[i][0] << ", " << v[i][1] << ", " << v[i][2] << endl;

        ll tmp=N;
        rep(i_,Q){
            tri qi=qu[i_];
            if(qi[0]<3){
                ll x,y;
                x=qi[1]; y=qi[2];
                ll idx,jdx;
                idx = memo[x];
                jdx = rv[tmp];
                memo[x] = jdx;
                tmp++;
                tri vi,vj;
                vi = v[idx]; vj=v[jdx];

                // cout << i_ <<" -- "<< tmp << endl;
                // cout << idx << " ; " << vi[0] << ", " << vi[1] << ", " << vi[2] << endl;
                // cout << jdx << " ; " << vj[0] << ", " << vj[1] << ", " << vj[2] << endl;

                // ten[jdx]=y; num[jdx]=num[idx]; tot[jdx]=y*num[idx];
                // ten[idx]=0; num[idx]=0; tot[idx]=0;
                ten[idx]=0; num[idx]=0; tot[idx]=0;
                ten[jdx]=vj[0]; num[jdx]=vj[1]; tot[jdx]=vj[0]*vj[1];

                // cout << idx << " ; " << vi[0] << ", " << vi[1] << ", " << vi[2] << endl;
                // cout << jdx << " ; " << vj[0] << ", " << vj[1] << ", " << vj[2] << endl;


                numseg.set(idx,num[idx]); totseg.set(idx,tot[idx]); 
                numseg.set(jdx,num[jdx]); totseg.set(jdx,tot[jdx]);
            }
            if(qi[0]==3){
                ll x=qi[1];

                if(numseg.all_prod()<x){
                    cout << -1 << endl;
                    // cout << numseg.all_prod() << "tot" << endl;
                    continue;
                }

                ll l=0, r=cnt;
                while(r-l>1){
                    ll m=(l+r)/2;
                    if(numseg.prod(0,m) <= x) l=m;
                    else r=m;
                }

                ll res = totseg.prod(0,l);
                ll rem = x-numseg.prod(0,l);

                res += ten[l]*rem;

                cout << res << endl;
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
