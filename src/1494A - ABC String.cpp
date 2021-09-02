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

bool check(string b) {
	int open = 0;
	if (count(all(b), '(') > count(all(b), ')')) {
		replace(all(b), 'A', ')');
		replace(all(b), 'B', ')');
		replace(all(b), 'C', ')');
	} else {
		replace(all(b), 'A', '(');
		replace(all(b), 'B', '(');
		replace(all(b), 'C', '(');
	}
	//cout << b << nL;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] == '(')
			open++;
		else if (b[i] == ')')
			open--;

		if (open < 0)
			return false;
	}
	return open == 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    	string a, b;
    	cin >> a;

    	bool res = a[0] != a[a.length()-1];
    	if (res) {
    		b = a;
    		replace(all(b), a[0], '(');
    		replace(all(b), a[a.length()-1], ')');
    		//cout << b << nL;
    		res = check(b);
    	}
    	EVAL(res);
    }

	return 0;
}