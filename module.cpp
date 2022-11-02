#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define rep1(i,n) for (ll i = 1; i <= (n); ++i)
#define repr(i,n) for (ll i = (n)-1; i >= 0; --i)
#define rep1r(i,n) for (ll i = (n); i > 0; --i)
#define bit(n,k) ((n>>k)&1) //nのk　bit目
#define vec(T) vector<T>
#define vvec(T) vec(vec(T))
using ll = long long;
using P = pair<int,int>;
#define all(x) x.begin(),x.end()
#define watch(x) cout << (#x) << " is " << (x) << endl
#define sfind(s,x) (s.find(x)!=s.end())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll llINF = 1LL << 60;
const int iINF = 1e9;

using mint = modint998244353;

using bs = bitset<8>;

//==================================================================================


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




// setからランダムに値を得る
ll set_random(set<ll> &s)
{
    auto it = s.cbegin();
    int random = rand() % s.size();
    advance(it, random);
 
    return *it;
}


// vectorの重複削除
/*
vec(ll) v={1,2,5,23,5};
sort(all(v));
v.erase(unique(all(v)), v.end());
*/



// ラムダ式
auto qpush = [&](ll cost, int id){
};


// 配列をシャッフル
//random_device seed_gen;
//mt19937 engine(seed_gen());
//shuffle(all(v), engine);


// ファイル出力
/*
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream outputfile("test.txt");
    outputfile<<"test";
    outputfile.close();
}
*/


// 構造体とそれ用の比較演算子
struct State{
    ll score;
    ll X[21];
    char LastMove;
    ll LastPos;
};

bool operator>(const State& a, const State& b){
    return (a.score > b.score);
}


    // 0.以上1.未満の整数をランダムに返す関数
    double Randdouble(){
        return 1. * rand() / RAND_MAX;
    }

    // vectorの途中を反転
    // reverse(ans.begin()+a, ans.begin()+b);


    // a以上b以下の整数をランダムに返す関数
    ll RandInt(ll a,ll b){
        return a + rand()%(b-a+1);
    }



        /*
        // LIS
        segtree<ll,op,ee> sega(N+1),segb(N+1);
        for(ll vi:va){
            ll x = sega.prod(0,vi);
            sega.set(vi,x+1);
        }
        */



    // インタラクティブな問題でflush必要なとき
    //cout << ans << endl; //で通るが
    //cout << ans << endl << flush; //でもOK


    // LCA tekina
    struct LCA{
        ll N,ln;
        vvec(ll) g;
        vvec(ll) par;
        vec(ll) dep;

        void _dfs(ll now,ll frm){
            par[now][0] = frm;
            dep[now] = dep[frm]+1;

            for(ll nxt:g[now]){
                if(nxt==frm) continue;
                _dfs(nxt,now);
            }
        }


        LCA(vvec(ll) _g, ll rt = 0){
            g = _g;
            N = g.size();
            ln = log2(N) + 1;
            dep.resize(N);
            par = vvec(ll)(N,vec(ll)(ln));

            dep[rt] = -1;
            _dfs(rt,rt);

            rep(j,ln){
                if(j==0) continue;
                rep(i,N) par[i][j] = par[ par[i][j-1] ][j-1];
            }
        }


        ll get_dist(ll a,ll b){
            return dep[a] + dep[b] - 2*dep[get_lca(a,b)];
        }

        ll get_lca(ll a,ll b){
            if(dep[a]<dep[b]) swap(a,b);
            ll dd=dep[a]-dep[b];
            ll ex=0;
            while(dd){
                if(dd&1) a = par[a][ex];
                dd >>= 1;
                ex++;
            }

            if(a==b) return(a);
            repr(i,ln){
                if(par[a][i]==par[b][i]) continue;
                a = par[a][i];
                b = par[b][i];
            }
            return par[a][0];
        }

    };






    //--- kitamasa法 ---
    // https://qiita.com/hidekikangeki/items/716ff998732f43050164
    // 以下で、数列Aの第N項(1-indexed)をAの第1~K項の線形和で表す係数を求めてくれる
    // kitamasa kita(vec(mint)(K,1),K);
    // auto res = kita.calculate(N-1);
    // TDPC_Tで使った

    struct kitamasa{
        ll n;//次数
        vector<mint> a;//漸化式の係数
        vector<vector<mint>> mem;//a_n+i = \sum a_j mem[i][n-1-j]
        //kitamasa(漸化式の係数,次数)
        kitamasa(vector<mint> c,ll N) : a(c),n(N){
            vector<mint> r(2*n,0);
            rep(i,n)r[i]=c[i];
            mem.push_back(r);
            rep(i,n+1){
                mem.push_back(oneplass(mem[i]));
            }
        }
        //畳み込み
        vector<mint> closs(vector<mint> b){
            vector<mint> res(2*n,0);  
            repr(i,2*n-2+1){//? vrep(i,2*n-2+1){
                mint a=0;
                rep(j,i+1){
                    a+=b[j]*b[i-j];
                }
                res[i]=a;
            }
            return res;
        }
        //a_l の係数-> a_l+1 の係数
        vector<mint> oneplass(vector<mint> b){
            vector<mint> res(2*n,0);
            rep(i,n-1){
                res[i]=b[i+1]+b[0]*a[i];
            }
            res[n-1]=b[0]*a[n-1];
            return res;
        }
        //a_l の係数-> a_2*l の係数
        vector<mint> twotimes(vector<mint> b){
            vector<mint> res(2*n,0);
            auto bb=closs(b);
            rep(i,n-1){
                rep(j,n){
                    bb[2*n-2-j]+=bb[n-2-i]*mem[i][n-1-j];
                }
                bb[n-2-i]=0;
            }
            rep(i,n){
                res[n-1-i]=bb[2*n-2-i];
            }
            return res;
        }
        //calculate(n)=a_nの係数
        vector<mint> calculate(int m){
            vector<mint> res(2*n,0);
            if(m<n){
                res[m]=a[m];
                return res;
            }
            if(m<=2*n){
                return mem[m-n];
            }else{
                if(m%2==0){
                    auto b=calculate(m/2);
                    res=twotimes(b);
                }else{
                    auto b=calculate((m-1)/2);
                    res=twotimes(b);
                    res=oneplass(res);
                }
            }
            return res;
        }
    };




//---自作SCC---
    struct SCC{
        ll n;
        vvec(ll) gf,gr;
        vec(bool) used;
        vec(ll) memo;

        SCC(ll _n, vvec(ll) _gf, vvec(ll) _gr){
            n = _n;
            gf = _gf;
            gr = _gr;
            assert(n==gf.size() && n==gr.size());
            used.resize(n);
        }

        void dfsf(ll now){
            used[now] = true;
            for(auto to:gf[now]) if(!used[to]) dfsf(to);
            memo.push_back(now);
            return;
        }

        vec(ll) tmp;

        void dfsr(ll now){
            tmp.push_back(now);
            used[now]=true;
            for(auto to:gr[now]) if(!used[to]) dfsr(to);
            return;
        }



        vvec(ll) get_group(){
            rep(i,n) used[i] = false;
            memo.clear();

            rep(st,n) if(!used[st]) dfsf(st);

            rep(i,n) used[i] = false;
            
            vvec(ll) res;
            reverse(all(memo));
            for(auto st:memo){
                if(used[st]) continue;
                tmp.clear();
                dfsr(st);
                res.push_back(tmp);
            }

            return res;
        }

    };




//---月ごとの日数---
    vec(ll) md = {31,28,31, 30,31,30, 31,31,30, 31,30,31};



//---ベクトルとか行列の掛け算---
    vvec(mint) vvxvv(vvec(mint) const& vv1, vvec(mint) const& vv2){
        ll h,w,d;
        h = vv1.size(); w=vv1[0].size(); d=vv2[0].size();
        assert(w==vv2.size());

        vvec(mint) res(h,vec(mint)(d));
        rep(i,h)rep(j,d)rep(k,w) res[i][j]+=vv1[i][k]*vv2[k][j];
        return res;
    }


    vec(mint) vvxv(vvec(mint) const& vv, vec(mint) const& v){
        ll h,w;
        h = vv.size(); w=vv[0].size();
        assert(w==v.size());

        vec(mint) res(h);
        rep(i,h)rep(j,w) res[i]+=vv[i][j]*v[j];
        return res;
    }

    mint vxv(vec(mint) const& v1, vec(mint) const& v2){
        ll h;
        h = v1.size();
        assert(h==v2.size());

        mint res=0;
        rep(i,h) res+=v1[i]*v2[i];
        return res;
    }



// multisetで1つだけ消す
//ms.erase(ms.find(5));


    // floor(sqrt(N))
    // https://atcoder.jp/contests/abc243/editorial/3510
    ll llsqrt(ll N){
        ll sqrtN=sqrt(N)-1;
        while(sqrtN+1<=N/(sqrtN+1))sqrtN++;
        return sqrtN;
    }



// オーバーフローとmod考慮したpow
    ll mypow(ll x, ll y, ll modnum){
        assert(y>=0);
        if(x%modnum==0) return 0;

        auto mul = [&](ll a, ll b){
            a%=modnum;
            b%=modnum;
            ll br = sqrt(b);
            ll ep = b-(br*br);
            ll res = (a*ep)%modnum;
            a = (a*br)%modnum;
            a = (a*br)%modnum;
            res = (a+res)%modnum;
            return res;
        };

        ll res = 1;
        while(y){
            if(y&1) res = mul(res,x);
            x = mul(x,x);
            y >>= 1;
        }
        return res;
    }



//---自分で構造体定義するsegtree---
struct T{mint ans,cnt,sum; };
T op(T a, T b){// A[i]はa<b
    mint var = a.ans + b.ans + b.sum*a.cnt - a.sum*b.cnt;
    return T{ var, a.cnt+b.cnt, a.sum+b.sum };
    }
T e(){return T({0,0,0});}
 

//---区間max,区間addのlazy_segtreeのテンプレート---
ll op(ll a, ll b){ return max(a,b);}
ll ee(){return 0;}
ll mapping(ll f, ll x){return f+x;}
ll composition(ll f,ll g){return f+g;}
ll id(){return 0;}
//lazy_segtree<ll, op, e, ll, mapping, composition, id> ls(N+1);




    //---modintで組み合わせ扱う用の構造体---
    struct mcomb{
        ll nmax;
        vec(mint) fa,af;
        mcomb(ll sz=200020){
            nmax = sz;
            fa.resize(nmax+1);
            fa[0]=1;
            rep1(i,nmax) fa[i]=fa[i-1]*i;
            af.resize(nmax+1);
            rep(i,nmax+1) af[i]=fa[i].inv();
        }
        mint c(ll n, ll k){
            if(n<k || k<0 || n>nmax) return 0;
            return fa[n]*af[k]*af[n-k];
        }
    };



//---転倒数-fenwicktree--
ll inversions(vector<int> A){
  int N = A.size();
  ll ans=0;
  fenwick_tree<int> ft(N);
  for(auto ai:A){
    ans += ft.sum(ai,N);
    ft.add(ai,1);
  }
  return ans;
}




//---転倒数-分割統治法ver--
//https://kira000.hatenadiary.jp/entry/2019/02/23/053917#:~:text=%E8%BB%A2%E5%80%92%E6%95%B0%20(inversion%20number)%20%E3%81%A8,%E6%95%B0%E3%81%BE%E3%81%9F%E3%81%AF%E5%8F%8D%E8%BB%A2%E6%95%B0%E3%81%A8%E3%81%84%E3%81%86.
ll merge_cnt(vector<int> &a) {
    int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<int> b(a.begin(), a.begin()+n/2);
    vector<int> c(a.begin()+n/2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    int ai = 0, bi = 0, ci = 0;
    // merge の処理
    while (ai < n) {
        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {
            a[ai++] = b[bi++];
        } else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}








//---整数pow  x^y----
ll powll(ll x, ll y){
  assert(y>=0);
  ll res = 1;
  while(y){
    if(y&1) res *= x;
    x *= x;
    y >>= 1;
  }
  return res;
}






//---vector<P> を表示する----------------------
void showP(vector<P> vp){
  int n = vp.size();
  rep(i,n){
    cout << "first : " << vp[i].first << ", second : " << vp[i].second << endl;
  }
  //cout << "first : " << vp[n-1].first << ", second : " << vp[n-1].second;
  return;
}



// グループ分けを管理するデータ構造
//   parentにサイズを持たせる実装は後で(https://atcoder.jp/contests/abc177/editorial/90)
//---Union Find---
struct UnionFind{
  // グループのサイズ、要素の親idx、要素から親までのランクの配列
  vector<int> gsize,parent,rank;

  //コンストラクタ　各配列を初期化
  UnionFind(int N){
    gsize = vector<int>(N,1);
    parent = vector<int>(N,-1);
    rank = vector<int>(N);
  }

  //親を求める
  int findparent(int x){
    if(parent[x]<0) return x;
    else return parent[x] = findparent(parent[x]); //rankが小さくなるよう親を再設定
  }

  // 2要素x,yの属するグループを合併
  bool unite(int x, int y){
    x = findparent(x);
    y = findparent(y);
    if(x==y) return false;
    
    if(rank[x] < rank[y]) swap(x,y);
    parent[y] = x;
    gsize[x] += gsize[y];
    gsize[y] = 0;
    if(rank[x]==rank[y]) rank[x]++;
    return true;
  }

  // 2要素x,yが同じ集合に属するかどうか
  bool same(int x, int y){
    return findparent(x) == findparent(y);
  }
};



//---snuke mint---
// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){} //ll = x; x = x%mod+mod)%mod; と同じらしい
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};
istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}
 



//---素因数分解------
map<ll, ll > prime_factor(ll n) {
    map<ll, ll > pf;
    for(ll f=2; f*f<=n; ++f){
        while(n%f == 0){
            pf[f]++;
            n /= f;
        }
    }
    if(n!=1) pf[n] = 1;
    return pf;
}



//---n進数Aのm(>=0)桁目---
int nAm(int A,int n,int m) {
    int ans = (A % int(pow(n,m+1)+0.5))/int(pow(n,m)+0.5);
    return ans;
}



// combination
//vector<vector<ll>> comb(int N, int K){
ll comb(int N, int K){
  vector<vector<ll>> v(N+1,vector<ll>(N+1,0));
  for(int i = 0;i <=N; i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <= N;k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }

  /*
  rep(i,N+1){
    rep(j,N) cout << v[i][j] << " ";
    cout << v[i][N] << endl;
  }
  */
  return v[N][K];
}

// high speed combination? 列挙
//vector<vector<ll>> comb(int N, int K){
ll mycomb(int N, int K){
  if(N<K || N<0 || K <0) return 0;
  K = min(K,N-K);
  vector<vector<ll>> v(N+1,vector<ll>(K+1,0));
  rep(i,N+1) v[i][0]=1;
  rep(i,K+1) v[i][i]=1;

  for(int i=1; i<=N; i++){
    for(int j=1; j<=min(i,K); j++){
      v[i][j] = v[i-1][j-1] + v[i-1][j];      
    }
  }
  return v[N][K];
}

// 最大公約数
int gcd(int a, int b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
int lcm(int a, int b){
   return a * b / gcd(a, b);
}


// extgcd
// {g,x,y} : ax+by=g 
tuple<ll,ll,ll> extgcd(ll a,ll b){
    if(b==0) return {a,1,0};
    ll g,x,y;
    tie(g,x,y) = extgcd(b,a%b);
    return {g,y,x-a/b*y};
}




//---組み合わせを先に計算しておくやつ---
vvec(int) nCk(int N){
    vvec(int) res(N+1,vec(int)(N+1));
    rep(ni,N+1){
        res[ni][0]=1;
        //res[ni][ni]=1;
    }
    rep1(ni,N){
        rep1(ki,ni){
            res[ni][ki] = res[ni-1][ki-1] + res[ni-1][ki];
        }
    }
    return res;
}


//---組み合わせを先に計算しておくやつの構造体---
struct combination{
    int N;
    vvec(mint) nk;

    combination(int N=1){
        N=N;
        nk = vvec(mint)(N+1,vec(mint)(N+1));

        rep(ni,N+1) nk[ni][0]=1;
        rep1(ni,N) rep1(ki,ni) nk[ni][ki] = nk[ni-1][ki-1] + nk[ni-1][ki];
    }
};





//---階乗を先に計算しておくやつ---
vec(int) factorial(int k){
    vec(int) res(k+1);
    res[0]=1;
    rep1(i,k) res[i] = res[i-1]*i;
    return res;
}



//---stringを反転させる---
string strrev(string s){
    reverse(s.begin(),s.end());
    return s;
}


//---ファイル書き出し--
void fileout(string s){
    ofstream outputfile("tmp.dat");
    outputfile<<s;
    outputfile.close();
}


//---sort lambda---
/*
    sort(K.begin(),K.end(),[](P const& a, P const& b){
        if(a.second != b.second) return a.second>b.second;
        return a.first > b.first;
    });
*/


//---main---------------------------------------------
int main(){
  string s;
  cin >> s;
  cout << "original : " << s <<endl;
  string sr;
  sr = strrev(s);
  cout << "reverse : " << sr << endl;
  cout << "original? : " << s << endl;
  cout << s.size() << ", " << s.length() << endl;


  return 0;
}
