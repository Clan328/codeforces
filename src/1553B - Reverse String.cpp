#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define nL '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll MOD = 1e9 + 7;

void settings()__attribute__((constructor));

void eval(bool condition) { cout << (condition ? "yes" : "no") << nL; }
void Eval(bool condition) { cout << (condition ? "Yes" : "No") << nL; }
void EVAL(bool condition) { cout << (condition ? "YES" : "NO") << nL; }

int ipow(int a, int n) {
    if (n == 0) return 1;
    int x = ipow(a, n/2);
    if (n % 2 == 0) return x*x;
    return x*x*a;
}

template <typename T>
ostream& operator<<(ostream& stream, const vector<T>& v) {
	for (auto elem : v) 
		stream << elem << " ";
	return stream;
}

template <typename T>
istream& operator>>(istream& stream, vector<T>& v){
    for(auto &elem : v)
    	stream >> elem;
    return stream;
}

void settings() {
	#ifdef LOCAL
		freopen("io/input.txt", "r", stdin);
		freopen("io/output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
}

vi z(string s) {
    int n = s.size();
    vi z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
           x = i;
           y = i+z[i];
           z[i]++;
       }
    }
    return z;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
    	string s, t;
    	cin >> s >> t;

    	bool res = false;

    	// 1. Only right
    	vi zRight = z(t+"#"+s);
    	for (int i = t.size()+1; i < zRight.size() && !res; i++) {
    		res = (zRight[i] == t.size());
    	}

    	// cout << t+" # "+s << nL;
    	// cout << zRight << nL;

    	// 2. Only left
    	vi zLeft;
    	if (!res) {
    		string tmp = t;
	    	reverse(all(tmp));

	    	// cout << tmp + " # " + s << nL;
	    	
	    	zLeft = z(tmp+"#"+s);
	    	for (int i = t.size()+1; i < zLeft.size() && !res; i++) {
	    		res = (zLeft[i] == t.size());
	    	}
    	}

    	// cout << zLeft << nL;

    	// 3. Both
    	if (!res) {
    		for (int i = t.size()+1; i < zRight.size() && !res; i++) {
    			int r = zRight[i];

    			int l;
    			for (int j = r; j > 0 && !res; j--) {
    				l = zLeft[i+j-1-(t.size()-j)];
	    		
	    			res = (j+l >= t.size());
    			}
	    		// if (i == 6)
	    		// 	cout << r << nL;
	    	}
    	}

    	EVAL(res);
    }

	return 0;
}