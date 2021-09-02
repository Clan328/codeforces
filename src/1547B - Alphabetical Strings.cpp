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

int main() {
    int t;
    cin >> t;
    while (t--) {
    	string s;
    	cin >> s;

    	bool res = true;

    	string so = s;
    	sort(all(so));
    	vi abc(27);
    	for (int i = 0; i < s.size() && res; i++) {
    		if (abc[s[i]-97] == 0) abc[s[i]-97]++;
    		else res = false;
    	}

    	if (res) {
    		bool ended = false;
    		for (int i = 0; i < 27 && res; i++) {
    			if (!ended && abc[i] == 0) ended = true;
    			if (ended && abc[i] == 1) res = false;
    		}

    		if (res) {
    			int n = s.size();
    			int lo, hi;
    			for (int i = 0; i < n; i++) {
    				if (s[i] == 'a') {
    					lo = i;
    					hi = i;
    					break;
    				}
    			}
    			int curr = 0;
    			//cout << (lo >= 0 && s[lo]-97 == curr) << nL;
    			while (res && curr < n && (lo >= 0 || hi < n)) {
    				if (lo >= 0 && s[lo]-97 == curr) {
    					curr++;
    					if (lo == hi)
    						hi++;
    					lo--;
    					//cout << lo << nL;
    				} else if (hi < n && s[hi]-97 == curr) {
    					curr++;
    					if (hi == lo)
    						lo--;
    					hi++;
    				} else
    					res = false;
    			}
    		}
    	}

    	EVAL(res);
    }

	return 0;
}