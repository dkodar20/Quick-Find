
#include "fft-search/string-find.cc"
using namespace std;
void solve();

int main() {

	string t = "abcdeabcdef", p = "a*cd";

	for (auto i: fft_search(t, p))
		cout << i << " ";

	cout << "\n";
}