#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <set>
#include <numeric>

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

const ll MOD = 10e9 + 7;

void settings()__attribute__((constructor));

void eval(bool condition) { cout << (condition ? "yes" : "no") << nL; }
void Eval(bool condition) { cout << (condition ? "Yes" : "No") << nL; }
void EVAL(bool condition) { cout << (condition ? "YES" : "NO") << nL; }

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

int main() {
    int n;
    cin >> n;
    vi c(n);
    cin >> c;

    int lIdx = 0, rIdx = n-1, a = 0, b = 0;
    for (int i = 0; i < n; i++) {
    	int points;
    	if (max(c[lIdx], c[rIdx]) == c[lIdx]) {
    		points = c[lIdx];
    		lIdx++;
    	} else {
    		points = c[rIdx];
    		rIdx--;
    	}

    	if (i % 2 == 0)
    		a += points;
    	else
    		b += points;
    }

    cout << a << " " << b << nL;

	return 0;
}