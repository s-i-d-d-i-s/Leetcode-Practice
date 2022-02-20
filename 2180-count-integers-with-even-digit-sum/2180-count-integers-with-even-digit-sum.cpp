
#define pii pair<int,int>
#define vi vector<int>
#define mii map<int,int>
#define ADJ map<int,set<int>>
#define vpii vector<pii>
#define fmap gp_hash_table

// Shorthand Macros
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
#define TT third
#define disp(x) for(auto t : x )cout<<t<<" ";
#define for0(n) for(int i = 0 ; i < n ; i++)
#define for0j(n) for(int j = 0 ; j < n ; j++)
#define oldfor(v) for(auto it = v.begin(); it != v.end(); ++it)
#define SS << ' ' <<
#define acum accumulate
#define arrin(a,n) vi a(n);for0(n){cin >> a[i];}
#define arrinp(a,n) vpii a(n);for0(n){cin >> a[i].F;a[i].S=i;}
#define pf(x) cout << x << endl;
#define Check pf("Check")
#define gridin(num,n,m) for0(n){for0j(m) cin >> num[i][j];}
#define dispgrid(num,n,m) for0(n){for0j(m) cout << num[i][j] << ' '; cout << endl;}

#define MOD 1000000007

template<typename F, typename S>
ostream& operator<<(ostream& os,const pair<F,S> &p){return os << "(" << p.F << ", " << p.S << ")";}

template < typename T >
ostream &operator<<(ostream &os,const vector<T> &v){os<< "{";oldfor(v){if(it!=v.bg)os<<", ";os<<*it;}return os << "}";}

template < typename T >
ostream &operator << (ostream &os, const set<T> &v){os << "[";oldfor(v){if(it!=v.bg)os<< ", ";os << *it;}return os << "]";}

template < typename T >
ostream &operator << (ostream &os, const multiset<T> &v){os << "[";oldfor(v){if(it!=v.bg) os << ", ";os<<*it;}return os << "]";}

template < typename F, typename S >
ostream &operator <<(ostream & os, const map<F,S> &v){os << "[";oldfor(v){if(it!=v.bg)os<< ", ";os<< it->F<<" = "<<it->S;}return os << "]";}

int sum(int n){
	int res=0;
	while(n>0){
		res+=n%10;
		n/=10;
	}
	return res;
}

class Solution {
public:
    int countEven(int num) {
    	int res=0;
        for(int i=1;i<=num;i++){
        	if(sum(i)%2==0){
        		res++;
        	}
        }
        return res;
    }
};

