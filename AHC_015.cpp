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



struct Solver{
    
    ll NN = 100;
    ll N = 10;
    ll FN = 4;

    ll frv[110];
    vec(char) fblr = {'F','B','L','R'};
    vec(ll) ans_memo;
    ll d3=0;

    vec(int) dh = {1,0,-1,0};
    vec(int) dw = {0,1,0,-1};

    struct abc{
        ll a,b,c;
        abc(ll a=0, ll b=0, ll c=0):a(a),b(b),c(c){}
    };



   // 0.以上1.未満の整数をランダムに返す関数
    double Randdouble(){
        return 1. * rand() / RAND_MAX;
    }

    // a以上b以下の整数をランダムに返す関数
    ll RandInt(ll a,ll b){
        return a + rand()%(b-a+1);
    }


    ll getScore(vvec(ll) const &now){
        ll res = 0;

        vvec(bool) used(N,vec(bool)(N));

        rep(sti,N)rep(stj,N){
            if(used[sti][stj]) continue;
            ll x = now[sti][stj];
            if(x==0) continue;

            queue<Pll> q;
            q.emplace(sti,stj);
            ll cnt=0;
            while(!q.empty()){
                Pll q0 = q.front();
                q.pop();
                ll h0=q0.first;
                ll w0=q0.second;
                if(used[h0][w0]) continue;
                used[h0][w0]=true;
                cnt++;

                rep(i,4){
                    ll h1 = h0 + dh[i];
                    ll w1 = w0 + dw[i];
                    if(h1<0 || h1>=N || w1<0 || w1>=N) continue;
                    if(used[h1][w1] || now[h1][w1]!=x) continue;
                    q.emplace(h1,w1);
                }
            }
            res += cnt*cnt;
        }
        //cout << res << " / " << d3 << endl;
        res = round( 1000000. * res / d3);
        return res;
    }


    ll getLength(vvec(ll) const &now){
        ll res = 0;

        vvec(bool) used(N,vec(bool)(N));

        rep(sti,N)rep(stj,N){
            if(used[sti][stj]) continue;
            ll x = now[sti][stj];
            if(x==0) continue;

            queue<Pll> q;
            q.emplace(sti,stj);
            ll cnt=0;
            while(!q.empty()){
                Pll q0 = q.front();
                q.pop();
                ll h0=q0.first;
                ll w0=q0.second;
                if(used[h0][w0]) continue;
                used[h0][w0]=true;

                rep(i,4){
                    ll h1 = h0 + dh[i];
                    ll w1 = w0 + dw[i];
                    if(h1<0 || h1>=N || w1<0 || w1>=N) continue;
                    if(!used[h1][w1] && now[h1][w1]==x) q.emplace(h1,w1);
                    if(now[h1][w1]!=x) cnt++;
                }
            }
            res += cnt;
        }
        return res;
    }


    void solve_0(){        
        rep(i,NN){
            cin >> frv[i];
        }

        vvec(ll) vv(N,vec(ll)(N));
        vvvec(ll) tmp(4, vvec(ll)(N,vec(ll)(N)));

        vec(ll) dcnt(FN);

        rep(i,NN) dcnt[frv[i]]++;
        
        d3 = 0;
        rep(i,FN) d3 += dcnt[i]*dcnt[i];
        


        //---
        rep(t,NN){
            // 入れる
            ll pt; cin >> pt;
            ll cnt=0;
            rep(i,N){
                rep(j,N){
                    if(vv[i][j]>0) continue;
                    cnt++;
                    if(cnt==pt){
                        vv[i][j]=frv[t];
                        break;
                    }
                }
                if(cnt>=pt) break;
            }        



            // 傾ける候補
            // F
            rep(j,N){
                vec(ll) v;
                rep(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                rep(i,N) tmp[0][i][j] = v[i];
            }
            // B
            rep(j,N){
                vec(ll) v;
                repr(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                repr(i,N) tmp[1][i][j] = v[N-1-i];
            }
            // L
            rep(i,N){
                vec(ll) v;
                rep(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                rep(j,N) tmp[2][i][j] = v[j];
            }
            // R
            rep(i,N){
                vec(ll) v;
                repr(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                repr(j,N) tmp[3][i][j] = v[N-1-j];
            }

            


            // 回答
            ll scr = -1;
            ll ans = -1;
            rep(i,4) if(chmax(scr, getScore(tmp[i]) )) ans = i;
            
            scr = llINF;
            //rep(i,4) if(chmin(scr, getLength(tmp[i]) )) ans = i;
            
            //ans = frv[t];



            cout << fblr[ans] << endl << flush;
            ans_memo.push_back(ans);
            vv = tmp[ans];


        }
    }


    void solve_1(){        
        srand(clock());
        rep(i,NN) cin >> frv[i];

        vec(ll) dcnt(FN);
        rep(i,NN) dcnt[frv[i]]++;        
        d3 = 0;
        rep(i,FN) d3 += dcnt[i]*dcnt[i];

        ll TIMELIMIT = 1.95 * CLOCKS_PER_SEC;
        ll STARTTIME = clock();

        vec(ll) ans_tmp(NN);
        rep(i,NN) ans_tmp[i] = frv[i];//RandInt(0,3);
        ans_memo = ans_tmp;

        // 焼きなます
        ll testN = 10;
        ll nowscr = 0;
        ll _cnt = 0;
        while(clock()-STARTTIME < TIMELIMIT){
            // 摂動
            vec(abc) sousa;
            rep(_, RandInt(1,1)){
                ll a = RandInt(0,NN);
                ll b = ans_tmp[a];
                ll c = (b+RandInt(1,3))%4;
                sousa.emplace_back( a, b, c);
                ans_tmp[a]=c;
            }


            // スコア
            ll totscr = 0;
            rep(_tcnt,testN){
                vvec(ll) vv(N,vec(ll)(N));
                rep(t,NN){
                    // 入れる
                    ll pt = RandInt(1,100-t);
                    ll cnt=0;
                    rep(i,N){
                        rep(j,N){
                            if(vv[i][j]>0) continue;
                            cnt++;
                            if(cnt==pt){
                                vv[i][j]=frv[t];
                                break;
                            }
                        }
                        if(cnt>=pt) break;
                    }        

                    // 傾ける
                    if(ans_tmp[t]==0){ // F
                        rep(j,N){
                            vec(ll) v;
                            rep(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                            while(v.size()<N) v.push_back(0);
                            rep(i,N) vv[i][j] = v[i];
                        }
                    }
                    if(ans_tmp[t]==1){ // B
                        rep(j,N){
                            vec(ll) v;
                            repr(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                            while(v.size()<N) v.push_back(0);
                            repr(i,N) vv[i][j] = v[N-1-i];
                        }
                    }
                    if(ans_tmp[t]==2){ // L
                        rep(i,N){
                            vec(ll) v;
                            rep(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                            while(v.size()<N) v.push_back(0);
                            rep(j,N) vv[i][j] = v[j];
                        }
                    }
                    if(ans_tmp[t]==3){ // R
                        rep(i,N){
                            vec(ll) v;
                            repr(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                            while(v.size()<N) v.push_back(0);
                            repr(j,N) vv[i][j] = v[N-1-j];
                        }
                    }

                }
                totscr += getScore(vv);
            }

            cout << totscr << endl;


            double dt = 1.*(clock()-STARTTIME)/TIMELIMIT;
            //double T = 10 * 1./(1. + exp(dt*2.-1.)); // シグモイド的な
            double T = 30. * (1-dt);
            double probability = exp( min(0., 1.*(totscr-nowscr)/T ) );

            if(Randdouble() < probability){
                ans_memo = ans_tmp;
                nowscr = totscr;
            }

            _cnt++;
        }
        //cout << _cnt * testN << " !  " << endl;

        rep(t,NN){
            ll pt; cin >> pt;
            //cout << fblr[ ans_memo[t] ] << endl << flush;
        }
    }




    void solve_2(){        
        rep(i,NN) cin >> frv[i];

        vvec(ll) vv(N,vec(ll)(N));

        vec(ll) dcnt(FN);
        rep(i,NN) dcnt[frv[i]]++;        
        d3 = 0;
        rep(i,FN) d3 += dcnt[i]*dcnt[i];
        


        //---
        rep(t,NN){
            // 入れる
            ll pt; cin >> pt;
            ll cnt=0;
            ll xi,xj;
            rep(i,N){
                rep(j,N){
                    if(vv[i][j]>0) continue;
                    cnt++;
                    if(cnt==pt){
                        vv[i][j]=frv[t];
                        xi=i; xj=j;
                        break;
                    }
                }
                if(cnt>=pt) break;
            }
            /*
            cout << pt << " , " << frv[t] << " : " << xi << " , " << xj << endl;
            rep(i,N){
                rep(j,N){
                    if(vv[i][j]==0) cout << '_' << " ";
                    if(vv[i][j]==1) cout << 'u' << " ";
                    if(vv[i][j]==2) cout << 'o' << " ";
                    if(vv[i][j]==3) cout << 'd' << " ";
                }
                cout << endl;
            }
            if(t>3) return;
            */


            ll ans = 1;//B
            for(ll i=xi+1; i<N; i++){
                if(vv[i][xj]==0) continue;

                bool chk=false;
                if(vv[i][xj]==frv[t]) chk = true;
                if(i-1>=0 && xj-1>=0 && vv[i-1][xj-1]==frv[t]) chk=true;
                if(i-1>=0 && xj+1>=0 && vv[i-1][xj+1]==frv[t]) chk=true;
                
                if(chk) ans=1;//B
                else ans=2;//L
                break;
            }


            // 回答            
            cout << fblr[ans] << endl << flush;
            ans_memo.push_back(ans);

            // 傾ける
            if(ans==0){ // F
                rep(j,N){
                    vec(ll) v;
                    rep(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                    while(v.size()<N) v.push_back(0);
                    rep(i,N) vv[i][j] = v[i];
                }
            }
            if(ans==1){ // B
                rep(j,N){
                    vec(ll) v;
                    repr(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                    while(v.size()<N) v.push_back(0);
                    repr(i,N) vv[i][j] = v[N-1-i];
                }
            }
            if(ans==2){ // L
                rep(i,N){
                    vec(ll) v;
                    rep(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                    while(v.size()<N) v.push_back(0);
                    rep(j,N) vv[i][j] = v[j];
                }
            }
            if(ans==3){ // R
                rep(i,N){
                    vec(ll) v;
                    repr(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                    while(v.size()<N) v.push_back(0);
                    repr(j,N) vv[i][j] = v[N-1-j];
                }
            }
        }


        /*
        cout << "scr : " << getScore(vv) << endl;
        rep(i,N){
            rep(j,N) cout << vv[i][j] << " ";
            cout << endl;
        }
        cout << "-----" << endl;

        rep(i,N){
            rep(j,N){
                if(vv[i][j]==1) cout << 'u' << " ";
                if(vv[i][j]==2) cout << 'o' << " ";
                if(vv[i][j]==3) cout << 'd' << " ";
            }
            cout << endl;
        }
        */

    }




    void solve_4(){     
        ll startt = clock();   
        rep(i,NN) cin >> frv[i];

        vvec(ll) vv(N,vec(ll)(N));
        vvvec(ll) tmp(4, vvec(ll)(N,vec(ll)(N)));

        vec(ll) dcnt(FN);
        rep(i,NN) dcnt[frv[i]]++;        
        d3 = 0;
        rep(i,FN) d3 += dcnt[i]*dcnt[i];
        
        //ll th = NN-6;
        ll rmax = 2;
        ll testN = 60;


        //---
        rep(t,NN){
            // 入れる
            ll pt; cin >> pt;
            ll cnt=0;
            rep(i,N){
                rep(j,N){
                    if(vv[i][j]>0) continue;
                    cnt++;
                    if(cnt==pt){
                        vv[i][j]=frv[t];
                        break;
                    }
                }
                if(cnt>=pt) break;
            }        



            // 傾ける候補
            // F
            rep(j,N){
                vec(ll) v;
                rep(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                rep(i,N) tmp[0][i][j] = v[i];
            }
            // B
            rep(j,N){
                vec(ll) v;
                repr(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                repr(i,N) tmp[1][i][j] = v[N-1-i];
            }
            // L
            rep(i,N){
                vec(ll) v;
                rep(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                rep(j,N) tmp[2][i][j] = v[j];
            }
            // R
            rep(i,N){
                vec(ll) v;
                repr(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                repr(j,N) tmp[3][i][j] = v[N-1-j];
            }

            vec(ll) scores(4);
            ll rr = min(rmax, NN-1-t);
            vvec(ll) ptnvv(testN);
            rep(i,testN){
                rep1(j,rr) ptnvv[i].push_back( RandInt(1, 100-t-j) );
            }
            //cout << t <<" : " << rr << endl;

            rep(k,4){
                for(auto ptv:ptnvv)rep(sousa, (1<<(2*rr)) ){
                    vv = tmp[k];
                    ll x = sousa;

                    rep(ri,rr){
                        pt = ptv[ri];
                        cnt=0;
                        rep(i,N){
                            rep(j,N){
                                if(vv[i][j]>0) continue;
                                cnt++;
                                if(cnt==pt){
                                    vv[i][j]=frv[t];
                                    break;
                                }
                            }
                            if(cnt>=pt) break;
                        }
                        ll svi = x%4;
                        x/=4;



                        // 傾ける候補
                        // F
                        if(svi==0){
                            rep(j,N){
                                vec(ll) v;
                                rep(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                                while(v.size()<N) v.push_back(0);
                                rep(i,N) vv[i][j] = v[i];
                            }
                        }
                        // B
                        if(svi==1){
                            rep(j,N){
                                vec(ll) v;
                                repr(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                                while(v.size()<N) v.push_back(0);
                                repr(i,N) vv[i][j] = v[N-1-i];
                            }
                        }
                        // L
                        if(svi==2){
                            rep(i,N){
                                vec(ll) v;
                                rep(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                                while(v.size()<N) v.push_back(0);
                                rep(j,N) vv[i][j] = v[j];
                            }
                        }
                        // R
                        if(svi==3){
                            rep(i,N){
                                vec(ll) v;
                                repr(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                                while(v.size()<N) v.push_back(0);
                                repr(j,N) vv[i][j] = v[N-1-j];
                            }
                        }

                    }

                    scores[k] += getScore(vv);
                }
            }

            //rep(k,4) cout << scores[k] <<" "; cout << " : " << t << endl;

            // 回答
            ll scr = -1;
            ll ans = -1;
            rep(i,4) if(chmax(scr, scores[i] )) ans = i;

            cout << fblr[ans] << endl << flush;
            ans_memo.push_back(ans);
            vv = tmp[ans];


        }

        //cout << (clock() - startt)/CLOCKS_PER_SEC <<"sec"<< endl;

    }


    void solve_5(){     
        ll startt = clock();   
        rep(i,NN) cin >> frv[i];

        vvec(ll) vv(N,vec(ll)(N));
        vvvec(ll) tmp(4, vvec(ll)(N,vec(ll)(N)));

        vec(ll) dcnt(FN);
        rep(i,NN) dcnt[frv[i]]++;        
        d3 = 0;
        rep(i,FN) d3 += dcnt[i]*dcnt[i];
        
        ll th = NN-6;
        //ll rmax = 2;
        //ll testN = 10;


        //---
        rep(t,NN){
            // 入れる
            ll pt; cin >> pt;
            ll cnt=0;
            rep(i,N){
                rep(j,N){
                    if(vv[i][j]>0) continue;
                    cnt++;
                    if(cnt==pt){
                        vv[i][j]=frv[t];
                        break;
                    }
                }
                if(cnt>=pt) break;
            }        



            // 傾ける候補
            // F
            rep(j,N){
                vec(ll) v;
                rep(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                rep(i,N) tmp[0][i][j] = v[i];
            }
            // B
            rep(j,N){
                vec(ll) v;
                repr(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                repr(i,N) tmp[1][i][j] = v[N-1-i];
            }
            // L
            rep(i,N){
                vec(ll) v;
                rep(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                rep(j,N) tmp[2][i][j] = v[j];
            }
            // R
            rep(i,N){
                vec(ll) v;
                repr(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                while(v.size()<N) v.push_back(0);
                repr(j,N) tmp[3][i][j] = v[N-1-j];
            }

            vec(ll) scores(4);

            if(t>th){
                ll rr = NN-1-th-1;
                cout << t <<" , " << rr <<endl;
                rep(k,4){
                    rep(ptn,rr*(rr+1)/2)rep(sousa, (1<<(2*rr)) ){
                        vv = tmp[k];
                        ll px = ptn;
                        vec(ll) ptv;
                        rep1(i,rr){
                            ptv.push_back(px%i);
                            px/=i;
                        }
                        reverse(all(ptv));



                        ll sx = sousa;

                        rep(ri,rr){
                            pt = ptv[ri];
                            ll svi = sx%4;
                            sx/=4;

                            cnt=0;
                            rep(i,N){
                                rep(j,N){
                                    if(vv[i][j]>0) continue;
                                    cnt++;
                                    if(cnt==pt){
                                        vv[i][j]=frv[t];
                                        break;
                                    }
                                }
                                if(cnt>=pt) break;
                            }
                            


                            // 傾ける候補
                            // F
                            if(svi==0){
                                rep(j,N){
                                    vec(ll) v;
                                    rep(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                                    while(v.size()<N) v.push_back(0);
                                    rep(i,N) vv[i][j] = v[i];
                                }
                            }
                            // B
                            if(svi==1){
                                rep(j,N){
                                    vec(ll) v;
                                    repr(i,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                                    while(v.size()<N) v.push_back(0);
                                    repr(i,N) vv[i][j] = v[N-1-i];
                                }
                            }
                            // L
                            if(svi==2){
                                rep(i,N){
                                    vec(ll) v;
                                    rep(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                                    while(v.size()<N) v.push_back(0);
                                    rep(j,N) vv[i][j] = v[j];
                                }
                            }
                            // R
                            if(svi==3){
                                rep(i,N){
                                    vec(ll) v;
                                    repr(j,N) if(vv[i][j]>0) v.push_back(vv[i][j]);
                                    while(v.size()<N) v.push_back(0);
                                    repr(j,N) vv[i][j] = v[N-1-j];
                                }
                            }

                        }

                        scores[k] += getScore(vv);
                    }
                }
            }else{
                rep(k,4) scores[k] = getScore(tmp[k]);
            }
        
            //rep(k,4) cout << scores[k] <<" "; cout << " : " << t << endl;

            // 回答
            ll scr = -1;
            ll ans = -1;
            rep(i,4) if(chmax(scr, scores[i] )) ans = i;

            cout << fblr[ans] << endl << flush;
            ans_memo.push_back(ans);
            vv = tmp[ans];


        }

        cout << (clock() - startt)/CLOCKS_PER_SEC <<"sec"<< endl;

    }



    // デバッグ用ファイルに出力
    void Submit_file(){
        ofstream outputfile("out.dat");
        for(ll ai:ans_memo){
            outputfile << fblr[ai] << endl;
        }
        outputfile.close();
    }



};



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        Solver solver;
        solver.solve_4();
        //solver.Submit_file();
    }
    return 0;
}
