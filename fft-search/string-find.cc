
#include "polynomial.cc"
using namespace std;

vector<int> fft_search(string text, string pattern){

	using complex = complex<double>;
	const double pi = 3.14159265358979323846;
	Polynomial t, p;

	int n = text.size(), m = pattern.size();
	int wildcards = 0;

	t.coeff.assign(n, 0); p.coeff.assign(m, 0);

	double ang = 2 * pi / 26;

	for (int i = 0; i < n; ++i)
		t.coeff[i] = complex(cos(ang * (text[i] - 'a')), sin(ang * (text[i] - 'a'))); 

	for (int i = 0; i < m; ++i){
		if ('a' <= pattern[m - i - 1] and pattern[m - i - 1] <= 'z')
			p.coeff[i] = complex(cos(ang * (pattern[m - i - 1] - 'a')), -1 * sin(ang * (pattern[m - i - 1] - 'a'))); 
		else
			p.coeff[i] = 0, wildcards++;
	}

	Polynomial transform = p * t;

	vector<int> result;

	double precision  = 0.000000001;

	for (int i = 0; i < transform.coeff.size(); ++i){
		if (abs(transform.coeff[i].real() - (m - wildcards)) < precision)
			result.push_back(i - m + 1);
	}

	return result;
};
