#include "kmp-search/string-find.cc"
#include "fft-search/string-find.cc"

using namespace std;

int main() {

	string t = "abcdeabcdef", p = "abcd";
	cout << "Using fft-search\n";
	for (auto i: fft_search(t, p))
		cout << i << " ";

	cout << "\n";
	
	cout << "Using kmp-search\n";
	for(auto i: kmp_search(t, p))
		cout << i << " ";
	
	cout << "\n";
}
