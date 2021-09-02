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

ll howMany(ll n) {
	if (n < 10)
		return n;

	ll temp = n;
	int digits = 0;
	bool isPerfect = true;
	int prev = temp % 10;
	while (temp != 0) {
		digits++;
		if (isPerfect)
			isPerfect = (prev == temp % 10);
		if (temp != 0)
			prev = temp % 10;
		temp /= 10;
	}

	//cout << " " << prev-1 << " " << isPerfect << nL;

	string s = "";
	string p = to_string(prev);
	for (int i = 0; i < digits; i++)
		s += p;

	int in = stoi(s);

	return (prev-(n<in)) + howMany(ipow(10, digits-1)-1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
    	ll n;
    	cin >> n;

    	cout << howMany(n) << nL;
    }

	return 0;
}