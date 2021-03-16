#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <queue>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

const ll MOD = 10e9 + 7;

void settings()__attribute__((constructor));

void eval(bool condition) { cout << (condition ? "Yes" : "No") << endl; }
void EVAL(bool condition) { cout << (condition ? "YES" : "NO") << endl; }

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

    vi sum(3);
    while(n--) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	sum[0] += x;
    	sum[1] += y;
    	sum[2] += z;
    }

    EVAL(sum[0] == 0 && sum[1] == 0 && sum[2] == 0);

	return 0;
}