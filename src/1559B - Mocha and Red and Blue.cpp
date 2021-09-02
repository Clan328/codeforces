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
    	int n;
    	cin >> n;

    	string s = "";
    	char c;
    	cin >> c;
    	s += c;
    	for (int i = 1; i < n; i++) {
    		cin >> c;
    		if (c != '?') {
	    		s += c;
	    	} else {
	    		if (s[i-1] == 'R')
	    			s += 'B';
	    		else if (s[i-1] == 'B')
	    			s += 'R';
	    		else
	    			s += '?';
	    	}
    	}

    	// if (n > 1 && s[0] == '?') {
    	// 	if (s[1] == 'R')
    	// 		s[0] = 'B';
    	// 	else
    	// 		s[0] = 'R';
    	// } else if (s[0] == '?')
    	// 	s[0] = 'B';

    	if (s[n-1] == '?')
    		s[n-1] = 'B';
    	for (int i = n-2; i >= 0; i--) {
    		if (s[i] == '?') {
    			if (s[i+1] == 'R')
	    			s[i] = 'B';
	    		else
	    			s[i] = 'R';
    		}
    	}

    	cout << s << nL;
    }

	return 0;
}