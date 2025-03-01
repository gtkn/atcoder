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


using P = pair<int,int>;
#define pb push_back
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"{";for(const T& v:vc) o<<v<<",";o<<"}";return o;}
#define fs first
#define sc second

template<class T>
vector<T> operator+(const vector<T>& a, const vector<T>& b){
	vector<T> c = a;
	c.insert(c.end(),all(b));
	return c;
}

struct edge{
	int u,v,c;
	edge(int u,int v,int c):u(u),v(v),c(c){}
//	edge(){}
	friend ostream& operator<<(ostream &o,const edge& e){
		return o<<"edge(" << e.u << "," << e.v << ", c = " << e.c << ")";
	}

};

struct TreeDecomp{
	int V;	//tree size
	int B;	//max bag size ( = tw+1)
	vector<vector<int>> T;	//tree-decomp
	vector<vector<int>> bags;

	TreeDecomp(){}
	TreeDecomp(int V,int B,const vector<vector<int>>& T, const vector<vector<int>>& bags):V(V),B(B),T(T),bags(bags){}
}TD;

/*
	return pair(a & !b ,b & !a);
*/
pair<vector<int>,vector<int>> getdif(const vector<int>& a, const vector<int>& b){
	//naive
	vector<int> x,y;
	for(int v:a){
		if(!binary_search(all(b),v)) x.pb(v);
	}
	for(int v:b){
		if(!binary_search(all(a),v)) y.pb(v);
	}
	return make_pair(x,y);
}

int N,M;
vector<edge> es;	//edges
vector<int> ts;		//terminals
vector<bool> isTerminal;

struct UnionFind{
	int N;
	vector<int> par;

	UnionFind(int N):N(N){
		par.resize(N);
		rep(i,N) par[i]=i;
	}
	UnionFind(const vector<int>& par):par(par){
		N = par.size();
	}
	int find(int x){
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(x>y) swap(x,y);		//roots have the smallest id
		par[y]=x;
	}
	void normalize(){
		rep(i,N) par[i] = find(i);
	}
};
UnionFind ins(UnionFind UF,int I){
//	puts("---------ins--------");
	int N = UF.N;
//	show(N);

//	show(I);
	vector<int>& vs = UF.par;
//	show(vs);
	vector<int> nvs(N+1);
	rep(i,N) nvs[(i<I?i:i+1)] = vs[i]<I?vs[i]:vs[i]+1;
	nvs[I] = I;
//	puts("end ins");
	return UnionFind(nvs);
}
UnionFind ers(UnionFind UF,int I){
	//if become disconnected, return UF.N = -1
	int N = UF.N;
	assert(I<N);
	vector<int> vs;
	rep(i,N) if(UF.same(i,I)) vs.pb(i);
	if(vs.size() == 1){	//alone
		UF.N = -1;
		return UF;
	}
	int r = vs[0]==I ? vs[1] : vs[0];

	vector<int> nvs(N-1);
	rep(i,N-1){
		int id = i<I ? i : i+1;
		if(UF.same(id,I)){
			nvs[i] = r;
		}else{
			nvs[i] = UF.par[id];
		}
		if(nvs[i]>=I) nvs[i]--;
	}
	return UnionFind(nvs);
}
UnionFind glue(UnionFind UF,int x,int y){
	assert(x<UF.N);
	assert(y<UF.N);
	UF.unite(x,y);
	UF.normalize();
	return UF;
}
UnionFind merge(UnionFind a, UnionFind b){
	int N = a.N;
	rep(i,N) a.unite(i,b.find(i));
	a.normalize();
	return a;
}

struct State;

struct Prev{
	State* from;
	int u,v;
	Prev(State* from, int u, int v): from(from),u(u),v(v){}
};

struct State{
	UnionFind UF;		//size = popcount(s)
	int cost;
	vector<Prev> prevs;
	State(const UnionFind& UF,int cost,const vector<Prev>& prevs): UF(UF),cost(cost),prevs(prevs){}
	State(const UnionFind& UF,int cost): UF(UF),cost(cost),prevs({}){}
	State(): UF(UnionFind(0)){}	//defined dummy for map<int,State>
	friend ostream& operator<<(ostream &o,const State& x){
		return o<<"state: " << x.UF.par << " cost = " << x.cost;
	}
};

struct Data{
	int N;
	vector<int> vs;
	vector<vector<State>> states;	//states[s] = {(UF,cost)}

	Data(){
		N = 0;
		vs = {};
		states = {};
	};
	Data(const vector<int>& vs, const vector<vector<State>>& states): vs(vs),states(states){
		N = vs.size();
	}
//	Data(const vector<int>& vs): vs(vs){
//		N = vs.size();
//		states.resize(1<<N);
//	}
	friend ostream& operator<<(ostream &o,const Data& x){
		o<<"data:"<<endl;
		o<<"  vs = "<<x.vs<<endl;
		rep(s,1<<x.N){
			o<<"  states["<<s<<"] = "<<x.states[s]<<endl;
		}
		o<<endl;
		return o;
	}

};

void rmc(vector<State>& states){
	map<vector<int>,State> mp;
	for(auto state: states){
		vector<int>& vi = state.UF.par;
		if(!mp.count(vi) || mp[vi].cost>state.cost){
			mp[vi] = state;
		}
	}
	states.clear();
	for(auto it:mp){
		states.pb(it.sc);
	}
}

Data leaf(){
	return Data({},{{State(UnionFind(0),0)}});
}
Data introduce(Data d,int v){
//	printf("! introduce ");
//	cout<<d.vs<<"  add "<<v<<endl;

	int N = d.N;
	vector<int>& vs = d.vs;
	auto& states = d.states;
//	show(states);

	int nN = N+1;
	vector<int> nvs = vs;
	nvs.pb(v);
	sort(all(nvs));

	int vid = -1;	// index of v in nvs
	rep(i,nN) if(nvs[i] == v) vid = i;
	assert(vid != -1);

	vector<vector<State>> nstates(1<<nN);
	rep(s,1<<nN){
//		show(s);
//		show(nN);
//		show(vid);
//		show(states.size());
		int ps = 0;
		rep(i,N) if(bit(s, i<vid?i:i+1 )) ps |= 1<<i;
		if(bit(s,vid)){
			//insert singleton {v}
			for(const State& state: states[ps]){
				int vid_inUF = 0;
				rep(i,vid) if(bit(s,i)) vid_inUF++;
				nstates[s].pb(State(ins(state.UF,vid_inUF),state.cost,state.prevs));
			}
		}else if(isTerminal[v]){
			nstates[s] = {};
		}else{
			nstates[s] = states[ps];
		}
	}
//	puts("done intro");
	return Data(nvs,nstates);
}
Data forget(Data d,int v){
//	printf("! forget ");
//	cout<<d.vs<<"  erase "<<v<<endl;

	int N = d.N;
	vector<int>& vs = d.vs;
	auto& states = d.states;

	int nN = N-1;
	vector<int> nvs;
	int eraseid = -1;
	rep(i,N){
		if(vs[i] == v){
			eraseid = i;
		}else{
			nvs.pb(vs[i]);
		}
	}
	assert(eraseid != -1);

	vector<vector<State>> nstates(1<<nN);
	rep(s,1<<nN){
		vector<State>& vstate = nstates[s];
		int ps = 0;
		rep(i,eraseid) if(bit(s,i)) ps |= 1<<i;
		for(int i=eraseid;i<nN;i++) if(bit(s,i)) ps |= 1<<(i+1);

		// ps[v] = 0
		vstate = states[ps];

		ps |= 1<<eraseid;
		// ps[v] = 1
		int eraseid_inUF = 0;
		rep(i,eraseid) if(bit(ps,i)) eraseid_inUF++;
		for(const State& state: states[ps]){
			auto nUF = ers(state.UF,eraseid_inUF);
			if(nUF.N == -1) continue;	// become disconnected !!
			vstate.pb(State(nUF,state.cost,state.prevs));
		}
		rmc(vstate);
	}
	return Data(nvs,nstates);
}

vector<Data> important_datas;

Data introduce_edge(Data _d,int x,int y,int c){
	int ox = x, oy = y;

	important_datas.pb(_d);
	auto& d = important_datas.back();

	int N = d.N;
	vector<int>& vs = d.vs;
	auto& states = d.states;

	vector<int> nvs = vs;

	{	//convert x,y to id in vs
		int xid = -1, yid = -1;
		rep(i,N){
			if(vs[i]==x) xid = i;
			if(vs[i]==y) yid = i;
		}
		assert(xid != -1);
		assert(yid != -1);
		x = xid, y = yid;
	}

	vector<vector<State>> nstates(1<<N);
	rep(s,1<<N){
		vector<State>& vstate = nstates[s];
		vstate = states[s];	//don't use edge
		if(bit(s,x) && bit(s,y)){
			int xinUF = 0, yinUF = 0;
			rep(i,x) if(bit(s,i)) xinUF++;
			rep(i,y) if(bit(s,i)) yinUF++;
			for(State& state: states[s]){
				vstate.pb( State(glue(state.UF,xinUF,yinUF), state.cost+c, {Prev(&state,ox,oy)} ) );
			}
			rmc(vstate);
		}
	}
	return Data(nvs,nstates);
}
Data join(Data a,Data b){
	assert(a.vs == b.vs);
	int N = a.N;
	vector<int>& vs = a.vs;

	vector<int> nvs = vs;

	vector<vector<State>> nstates(1<<N);
	rep(s,1<<N){
		vector<State>& vstate = nstates[s];
		for(const State& sa: a.states[s]) for(const State& sb: b.states[s]){
			vstate.pb(State(merge(sa.UF,sb.UF),sa.cost+sb.cost,sa.prevs+sb.prevs));
		}
		rmc(vstate);
	}
	return Data(nvs,nstates);
}

map<P,int> unintroduced_edges;	//e,cost

Data dfs(int v,int p=-1){
//	printf("dfs %d,%d\n",v,p);
	vector<Data> dats;
	for(int u: TD.T[v]) if(u!=p){
		Data d = dfs(u,v);
		auto vv = getdif(TD.bags[u],TD.bags[v]);
		for(int x:vv.fs) d = forget(d,x);
		for(int x:vv.sc) d = introduce(d,x);
		dats.pb(d);
	}
	if(dats.empty()){	//leaf
		Data d = leaf();
//		show(TD.bags[v]);
		for(int x: TD.bags[v]) d = introduce(d,x);
		dats.pb(d);
	}
	while(dats.size()>1){
		int K = dats.size();
		Data nd = join(dats[K-2],dats[K-1]);
		rep(i,2) dats.pop_back();
		dats.pb(nd);
	}
	Data& d = dats[0];
	for(int x: TD.bags[v]) for(int y: TD.bags[v]) if(x<y){
		if(unintroduced_edges.count(P(x,y))){
			int c = unintroduced_edges[P(x,y)];
			d = introduce_edge(d,x,y,c);
			unintroduced_edges.erase(P(x,y));
		}
	}
//	printf("end dfs %d,%d\n",v,p);
//	printf("the result is below\n");
//	show(dats.front());
	return dats.front();
}

void recover(State* state, vector<P>& ansEdges){
	for(Prev prev: state->prevs){
		ansEdges.pb(P(prev.u,prev.v));
		recover(prev.from,ansEdges);
	}
}
void validate(int ans, vector<P> ansEdges){
	map<P,int> e2c;
	rep(i,M) e2c[P(es[i].u,es[i].v)] = e2c[P(es[i].v,es[i].u)] = es[i].c;
	int sum = 0;
	for(P e:ansEdges){
		sum += e2c[e];
	}
	assert(ans == sum);

	UnionFind UF(N);
	for(P e:ansEdges){
		UF.unite(e.fs,e.sc);
	}
	int T = ts.size();
	bool isconnected = 1;
	rep(i,T){
		if(!UF.same(ts[0],ts[i])) isconnected = 0;
	}
	assert(isconnected);

	set<int> vs;
	for(P e:ansEdges){
		vs.insert(e.fs);
		vs.insert(e.sc);
	}
	bool istree = vs.empty() || (vs.size() == ansEdges.size()+1);
	assert(istree);
}


vector<P> mySolve(){
//	input();
//	printf("B = %d, N = %d, M = %d, V = %d\n",TD.B,N,M,TD.V);
//	return 0;
//	long long Esum = 0;
//	rep(i,M){
//		Esum += es[i].c;
//	}
//	show(Esum);
//	return 0;
	// puts("-----mySolve-----");
	// show(N);
	// show(M);
	// show(es);
	// show(ts);
	// show(isTerminal);
	// show(TD.V);
	// show(TD.B);
	// show(TD.T);
	// show(TD.bags);

	int r = -1, lastv = -1;
	rep(x,TD.V){
		for(int v: TD.bags[x]) if(binary_search(all(ts),v)){
			r = x;
			lastv = v;
		}
	}
	assert(r != -1);

	TD.T.pb({r});
	TD.T[r].pb({TD.V});
	TD.bags.pb({lastv});
	TD.V ++;

	rep(i,M){
		int x = es[i].u;
		int y = es[i].v;
		int c = es[i].c;
		if(x>y) swap(x,y);
		unintroduced_edges[P(x,y)] = c;
	}

	Data d = dfs(TD.V-1);

	int ans = 1e9;
	State best;
	for(const auto& state: d.states[1]){
//		show(state);
		if(ans > state.cost){
			ans = state.cost;
			best = state;
		}
	}
//	show(ans);
	vector<P> ansEdges;
	recover(&best, ansEdges);
//	show(ansEdges);
	validate(ans,ansEdges);

	return ansEdges;
}

extern "C" {
	/*
		input:

			N: 
			M: 
			edges: x1 y1 c1 x2 y2 c2 ... xM yM cM
			T: num of terminals
			terminals: t1 t2 .. tT

			V: the number of vertices in tree-decomposition
			td: 
				k1 v1 v2 .. v_{k1}
				k2 v1 v2 .. v_{k2}
				:
				kV v1 v2 .. v_{kV}
			
			tedges:
				x1 y1
				x2 y2
				:
				x_{K-1} y_{K-1}

		output:
			return K: the number of edges used
			ans:
				x1 y1 x2 y2 .. x_K y_K
	*/
	int solve(int N, int M, int* edges, int T, int* terminals, int V, int* td, int* tedges, int* ans){
		::N = N;
		::M = M;
		es.clear();
		ts.clear();
		isTerminal.clear();
		rep(i,M){
			es.pb(edge(edges[i*3],edges[i*3+1],edges[i*3+2]));
		}
		isTerminal = vector<bool>(N,false);
		rep(i,T){
			ts.pb(terminals[i]);
			isTerminal[ts.back()] = 1;
		}
		sort(all(ts));

		vector<vector<int>> Tree(V),bags(V);

		int I = 0;
		int B = 0;
		rep(i,V){
			int K = td[I++];
			chmax(B,K);
			rep(k,K){
				bags[i].pb(td[I++]);
			}
			sort(all(bags[i]));
		}
		rep(i,V-1){
			int u = tedges[i*2], v = tedges[i*2+1];
			Tree[u].pb(v);
			Tree[v].pb(u);
		}

		TD = TreeDecomp(V,B,Tree,bags);

		vector<P> ansEdges = mySolve();

		int K = ansEdges.size();
		rep(i,K){
			ans[i*2] = ansEdges[i].fs;
			ans[i*2+1] = ansEdges[i].sc;
		}
		return K;
	}
}



template<typename T> class SteinerTree {
    private:
        struct edge {
            int to;
            T cost;
        };
        int V;
        vector<vector<edge> > G;
        vector<vector<T> > dp;
        const T inf = numeric_limits<T>::max() / 10;
        using pti = pair<T, int>;
     
    public:
        SteinerTree(int node_size) : V(node_size), G(V){}
        void add_edge(int u, int v, T cost){
            G[u].push_back((edge){v, cost}), G[v].push_back((edge){u, cost});
        }
        T solve(vector<int>& terminal){
            int t = (int)terminal.size();
            if(t == 0) return (T)0;
            dp.resize((1 << t), vector<T>(V, inf));
            for(int i = 0; i < t; i++){
                dp[(1 << i)][terminal[i]] = 0;
            }
            for(int i = 1; i < (1 << t); i++){
                for(int j = 0; j < V; j++){
                    for(int k = i; k > 0; k = (k - 1) & i){
                        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i ^ k][j]);
                    }
                }
                if(i == (1 << t) - 1) break;
                priority_queue<pti, vector<pti>, greater<pti> > que;
                for(int j = 0; j < V; j++){
                    que.push(make_pair(dp[i][j], j));
                }
                while(!que.empty()){
                    pti p = que.top();
                    que.pop();
                    int v = p.second;
                    if(dp[i][v] < p.first) continue;
                    for(auto& e : G[v]){
                        if(dp[i][e.to] > dp[i][v] + e.cost){
                            dp[i][e.to] = dp[i][v] + e.cost;
                            que.push(make_pair(dp[i][e.to], e.to));
                        }
                    }
                }
            }
            return dp[(1 << t) - 1][terminal[0]];
        }

        vector<int> get_used_vertices() {
            vector<int> used_vertices;
            for (int i = 0; i < V; ++i) {
                for (int j = 0; j < (1 << isTerminal.size()); ++j) {
                    if (dp[j][i] != inf) {
                        used_vertices.push_back(i);
                        break;
                    }
                }
            }
            return used_vertices;
        }

    };





void solve(){
    ll N,K;
    cin >> N >> K;

    vvec(ll) C(N,vec(ll)(N));
    rep(i,N)rep(j,N) cin >> C[i][j];

    ll Q;
    cin >> Q;

    vec(Pll) qs(Q);
    rep(i,Q){
        ll s,t;
        cin >> s >> t;
        --s; --t;
        if(s>t) swap(s,t);
        qs[i] = Pll(s,t);
    }

    // vvec(ll) vv(N);
    vector<set<ll>> mem(N);
    vec(ll) cs(N);

    for(ll s=K; s<N; ++s){
        SteinerTree<ll> st(N);
        rep(i,N)rep(j,N)if(i!=j){
            st.add_edge(i,j,C[i][j]);
        }
        vec(int) v;
        rep(i,K) v.push_back(i);
        v.push_back(s);
        ll res = st.solve(v);
        cs[s] = res;

        vec(int) m = st.get_used_vertices();
        for(int vi:m) mem[vi].insert(s);
    }

    map<Pll,ll> memo;
    for(auto [s,t]:qs){
        if(memo.count(Pll(s,t))){
            cout << memo[Pll(s,t)] << endl;
            continue;
        }
        ll res = llINF;
        if(mem[s].count(t)) chmin(res,cs[s]);
        if(mem[t].count(s)) chmin(res,cs[t]);
        if(res==llINF){
            SteinerTree<ll> st(N);
            rep(i,N)rep(j,N)if(i!=j){
                st.add_edge(i,j,C[i][j]);
            }
            vec(int) v;
            rep(i,K) v.push_back(i);
            v.push_back(s);
            v.push_back(t);
            res = st.solve(v);           
        }
        cout << res << endl;
        memo[Pll(s,t)] = res;

    }





    // while(Q--){
    //     ll s,t;
    //     cin >> s >> t;
    //     --s; --t;

    //     if(s>t) swap(s,t);

    //     if(memo.count(Pll(s,t))){
    //         cout << memo[Pll(s,t)] << endl;
    //         continue;
    //     }


    //     SteinerTree<ll> st(N);
    //     rep(i,N)rep(j,N)if(i!=j){
    //         st.add_edge(i,j,C[i][j]);
    //     }
    

    //     vec(int) v;
    //     rep(i,K) v.push_back(i);
    //     v.push_back(s);
    //     v.push_back(t);

    //     ll res = st.solve(v);
    //     cout << res << endl;

    //     memo[Pll(s,t)] = res;

    // }





}



int main(){
    int testcasenum=1;
    //cin >> testcasenum;
    rep1(ti,testcasenum){
        solve();
    }
    return 0;
}
