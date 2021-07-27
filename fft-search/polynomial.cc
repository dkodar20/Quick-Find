
#include "fft.cc"
using namespace std;

class Polynomial {

	public:
	vector<complex<double>> coeff;

	friend Polynomial operator * (Polynomial const &, Polynomial const &);

};

Polynomial operator * (Polynomial const &c1, Polynomial const &c2){

	using complex = complex<double>;
	using namespace dft;

	vector<complex> a(c1.coeff.begin(), c1.coeff.end()), b(c2.coeff.begin(), c2.coeff.end());

	int n = 1;
	while (n < a.size() + b.size())
		n <<= 1;

	a.resize(n);
	b.resize(n);

	__fft(a);
	__fft(b);

	for (int i = 0; i < n; ++i)
		a[i] *= b[i];

	__inverse_fft(a);

	Polynomial result;
	result.coeff.assign(n, 0);

	for (int i = 0; i < n; ++i)
		result.coeff[i] = a[i];

	return result;
}
