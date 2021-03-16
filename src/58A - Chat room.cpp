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
    string s;
    cin >> s;

    vector<bool> visited(5, false);

    for (int i = 0; i < s.length(); i++) {
    	bool prev = true;
    	int l;
    	
    	if (s[i] == 'h') l = 0;
    	else if (s[i] == 'e') l = 1;
    	else if (s[i] == 'l' && !visited[2]) l = 2;
    	else if (s[i] == 'l') l = 3;
    	else if (s[i] == 'o') l = 4;
    	else l = -1;
    	if (l != -1) {
    		for (int j = 0; j < l; j++) {
	    		if (!visited[j]) {
	    			prev = false;
	    			break;
	    		}
	    	}
	    	if (prev) {
	    		visited[l] = true;
	    		if (l == 4)
	    			break;
	    	}
    	}
    }

    EVAL(visited[4]);

	return 0;
}