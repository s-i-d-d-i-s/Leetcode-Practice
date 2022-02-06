#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define ADJ map<int,set<int>>
#define vpii vector<pii>
#define pb push_back
#define ed end()
#define bg begin()
#define sz size()
#define ln length()
#define all(x) x.begin(),x.end()
#define endl '\n'
#define NL cout << '\n';
#define F first
#define S second
#define disp(x) for(auto t : x )cout<<t<<" ";
#define for0(n) for(int i = 0 ; i < n ; i++)
#define for0j(n) for(int j = 0 ; j < n ; j++)
#define oldfor(v) for(auto it = v.begin(); it != v.end(); ++it)
#define SS << ' ' <<
#define arrin(a,n) vi a(n);for0(n){cin >> a[i];}
#define pf(x) cout << x << endl;
#define gridin(num,n,m) for0(n){for0j(m) cin >> num[i][j];}
#define dispgrid(num,n,m) for0(n){for0j(m) cout << num[i][j] << ' '; cout << endl;}
#define tks(x) string x;cin >> x;
#define tk(a) int a;cin >> a;
#define tk2(a,b)tk(a)tk(b)
#define tk3(a,b,c)tk2(a,b)tk(c)
#define tk4(a,b,c,d)tk2(a,b)tk2(c,d)
#define tk5(a,b,c,d,e)tk4(a,b,c,d)tk(e)
#define tk6(a,b,c,d,e,f)tk3(a,b,c)tk3(d,e,f)
#define tk7(a,b,c,d,e,f,g)tk6(a,b,c,d,e,f)tk(g)
#define tk8(a,b,c,d,e,f,g,h)tk7(a,b,c,d,e,f,g)tk(h)
#define addEdge(adj) tk2(u,v) adj[u].insert(v);adj[v].insert(u);
#define test tk(tt)while(tt--)
#define YES cout << "YES" <<endl;
#define Yes cout << "Yes" <<endl;
#define NO cout << "NO" <<endl;
#define No cout << "No" <<endl;
#define yes cout << "yes" <<endl;
#define no cout << "no" <<endl;
#define accuracy chrono::steady_clock::now().time_since_epoch().count()

template < typename F, typename S >
ostream &operator <<(ostream & os, const map<F,S> &v){os << "[";oldfor(v){if(it!=v.bg)os<< ", ";os<< it->F<<" = "<<it->S;}return os << "]";}

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;
        map<char,int> freq1,freq2;
        for(auto x:s1){
            freq1[x]++;
        }
        for(int i=0;i<s1.length();i++){
            freq2[s2[i]]++;
        }
        if(freq1 == freq2)return true;
        for(int i=s1.length();i<s2.length();i++){
            freq2[s2[i-s1.length()]]--;
            if(freq2[s2[i-s1.length()]]==0){
                freq2.erase(s2[i-s1.length()]);
            }
            freq2[s2[i]]++;
            if(freq1 == freq2)return true;
        }
        return false;
    }
};