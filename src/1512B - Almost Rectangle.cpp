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
	#ifndef ONLINE_JUDGE
		freopen("io/input.txt", "r", stdin);
		freopen("io/output.txt", "w", stdout);
	#endif

	ios::sync_with_stdio(0);
    cin.tie(0);
}

struct Point {
	int x, y;
};

int main() {
    int t;
    cin >> t;

    while (t--) {
    	int n;
    	cin >> n;

    	Point p1 = {-1, -1}, p2 = {-1, -1};
    	vector<string> mat(n);
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			char in;
    			cin >> in;
    			mat[i] += in;
    			if (in == '*') {
	    			if (p1.x == -1)
	    				p1 = {i, j};
	    			else
	    				p2 = {i, j};
    			}
    		}
    	}

    	if (p1.x == p2.x) {
    		if (p1.x > 0) {
    			mat[0][p2.y] = '*';
    			mat[0][p1.y] = '*';
    		} else {
				mat[1][p2.y] = '*';
    			mat[1][p1.y] = '*';
    		}
    	} else if (p1.y == p2.y) {
			if (p1.y > 0) {
    			mat[p1.x][0] = '*';
    			mat[p2.x][0] = '*';
    		} else {
				mat[p2.x][1] = '*';
    			mat[p1.x][1] = '*';
    		}
    	} else {
    		mat[p1.x][p2.y] = '*';
    		mat[p2.x][p1.y] = '*';
    	}

    	for (int i = 0; i < n; i++)
    		cout << mat[i] << nL;
    }

	return 0;
}