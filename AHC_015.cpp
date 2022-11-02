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
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using tri = tuple<ll,ll,ll>;

//using mint = modint1000000007;
//using mint = modint998244353;


template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

#define dame { puts("-1"); return;}
#define yn {puts("Yes");}else{puts("No");}

//------------------------------------------------

ll NN = 100;
ll N = 10;
vec(char) fblr = {'F','B','L','R'};
ll cnt_debug=0;

// 0.以上1.未満の整数をランダムに返す関数
double Randdouble(){
    return 1. * rand() / RAND_MAX;
}

// a以上b以下の整数をランダムに返す関数
ll RandInt(ll a,ll b){
    return a + rand()%(b-a+1);
}



struct Timer{
    ll start; // [clocks]
    ll limit;
    ll endt;

    void begin(ll x){ // x[sec]
        start = clock();
        limit = x * CLOCKS_PER_SEC;
        endt = start + limit;
    }

    bool inTime(){
        return (clock()-start < limit);
    }

    bool inTime(ll x){ // [clocks]
        return (clock()-start < x);
    }

    ll remain(){
        return endt-clock();
    }

    ll past(){
        return clock()-start;
    }


};



struct State{
    vvec(ll) grid;
 
    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};


    State(){
        grid = vvec(ll)(N,vec(ll)(N));
    }

    void put(ll f,ll p){
        rep(i,N)rep(j,N){
            if(grid[i][j]>0) continue;
            if(--p==0){
                grid[i][j] = f;
                return;
            }
        }
        cerr << "Error in State.put" << endl;
    }

    void tilt(char d){
        if(d=='F'){
            rep(j,N){
                ll cnt = 0;
                rep(i,N) if(grid[i][j]>0) swap(grid[cnt++][j],grid[i][j]);
            }
        }else if(d=='B'){
            rep(j,N){
                ll cnt = N-1;
                repr(i,N) if(grid[i][j]>0) swap(grid[cnt--][j],grid[i][j]);
            }
        }else if(d=='L'){
            rep(i,N){
                ll cnt = 0;
                rep(j,N) if(grid[i][j]>0) swap(grid[i][cnt++],grid[i][j]);
            }
        }else if(d=='R'){
            rep(i,N){
                ll cnt = N-1;
                repr(j,N) if(grid[i][j]>0) swap(grid[i][cnt--],grid[i][j]);
            }
        }else{
            cerr << "Error in State.tilt" << endl;
        }
    }

    
    ll getScore(){
        ll res = 0;
        vvec(bool) used(N,vec(bool)(N));

        rep(sti,N)rep(stj,N){
            if(used[sti][stj]) continue;
            if(grid[sti][stj]==0){
                used[sti][stj]=true;
                continue;
            }

            queue<Pll> q; q.emplace(sti,stj);
            ll cnt = 0;
            while(!q.empty()){
                Pll q0 = q.front();
                q.pop();
                ll h0 = q0.first;
                ll w0 = q0.second;
                if(used[h0][w0]) continue;
                used[h0][w0]=true;
                cnt++;
                rep(k,4){
                    ll h1 = h0+dh[k];
                    ll w1 = w0+dw[k];
                    if(h1<0 || h1>=N || w1<0 || w1>=N) continue;
                    if(grid[h0][w0]==grid[h1][w1]) q.emplace(h1,w1);
                }
            }
            res += cnt*cnt;
        }

        return res;
    }


    ll simlate(char d, ll now, const vec(ll) &pvec, const vec(char) &answer, const vec(ll) &frv){
        tilt(d);
        for(ll i=now+1; i<NN; i++){
            put(frv[i],pvec[i]);
            tilt(answer[i]);
        }
        return getScore();
    }

};







struct Solver{

    State state;
    Timer timer;
    vec(ll) frv;

    vec(char) ans;

    ll testN = 800;
    vvec(ll) tests;

    ll d3;
    ll minfrv=0;
    ll lfrv, rfrv, bfrv;


    Solver(){
        timer.begin(1.95);
        frv.resize(NN);
        ans.resize(NN);
        tests = vvec(ll)(testN,vec(ll)(NN));
        rep(i,testN)rep(j,NN) tests[i][j] = RandInt(1,NN-j);
    }

    void input(){
        rep(i,NN) cin >> frv[i];
        vec(ll) d(4);
        rep(i,NN) d[frv[i]]++;
        
        d3=0;
        rep1(i,3) d3 += d[i]*d[i];

        d[0]=NN+N;
        rep1(i,3) if(d[i]<d[minfrv]) minfrv = i;
    }


    char monte_carlo(ll t, const vec(bool) &skip){
        vec(ll) scores(4);

        double ratio = 1.*(NN+10-t)/(NN-t)/(NN+21-t)/2;
        ll LIMIT = timer.past() + timer.remain() *ratio;

        //cout << 1.*LIMIT / CLOCKS_PER_SEC<< "[sec]" << endl;

        ll usecase = testN;
        while(timer.inTime(LIMIT) && --usecase){
            rep(i,4){
                if(skip[i]) continue;
                State tmp = state;
                scores[i] += tmp.simlate(fblr[i], t, tests[usecase], ans, frv);
            }
        }
        ll bestdir=0;
        rep(i,4) if(scores[bestdir] < scores[i]) bestdir=i;
        
        cnt_debug++;
        return fblr[bestdir];
    }


    void solve(){
        input();

        if(minfrv==1){bfrv = 1; lfrv = 2; rfrv = 3;}
        if(minfrv==2){bfrv = 2; lfrv = 1; rfrv = 3;}
        if(minfrv==3){bfrv = 3; lfrv = 1; rfrv = 2;}

        rep(t,NN-1){
            if(frv[t+1]==bfrv) ans[t]='F';
            else{
                if(frv[t]==bfrv) ans[t]='B';
                else{
                    if(frv[t+1] == lfrv){
                        if(t>0 && ans[t-1]=='R') ans[t]='B';
                        else ans[t]='R';
                    }
                    if(frv[t+1] == rfrv){
                        if(t>0 && ans[t-1]=='L') ans[t]='B';
                        else ans[t]='L';
                    }
                }
            }
        }
        ans[NN-1]='F';

        rep(t,NN){
            ll pt; cin >> pt;
            state.put(frv[t],pt);
            vec(bool) skip(4);

            if(t==NN-1) break;

            if(80<=t) ans[t] = monte_carlo(t, skip);
            else{
                if(frv[t+1]==bfrv){
                    skip[1]=true; ans[t] = monte_carlo(t, skip);
                }else if(frv[t]==bfrv){
                    ans[t] = 'B';
                }else if(frv[t+1]==lfrv){
                    skip[0]=true; skip[2]=true;
                    ans[t] = monte_carlo(t, skip);
                }else if(frv[t+1]==rfrv){
                    skip[0]=true; skip[3]=true;
                    ans[t] = monte_carlo(t, skip);
                }
            }
            state.tilt(ans[t]);
            cout << ans[t] << endl;
        }


    }


    // デバッグ用ファイルに出力
    void Submit_file(){
        ofstream outputfile("out.dat");
        for(char ai:ans){
            outputfile << ai << endl;
        }
        outputfile.close();

        rep(i,N){
            rep(j,N){
                if(state.grid[i][j]==1) cout << 'u'<< " ";
                if(state.grid[i][j]==2) cout << 'o'<< " ";
                if(state.grid[i][j]==3) cout << 'x'<< " ";
            }
            cout << endl;
        }


        cout << "score : "  << round(1000000. * state.getScore() / d3) << endl;
        cout << cnt_debug << "monte_carlo" << endl;
    }



};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve();
        //solver.Submit_file();
    }
    return 0;
}
