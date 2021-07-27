
#include <bits/stdc++.h>
using namespace std;

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html

namespace dft {

	using complex = complex<double>;
	const double pi = 3.14159265358979323846;

	auto __fft = y_combinator([](auto __fft, vector<complex> &a) -> void {
		
		int n = a.size();
		if (n == 1) return;

		vector<complex> a0(n/2), a1(n/2);

		for (int i = 0; 2 * i < n; i++) {
		    a0[i] = a[2*i];
		    a1[i] = a[2*i + 1];
	    }

		__fft(a0);
		__fft(a1);

		double omega = 2 * pi / n;

		complex w(1), mul(cos(omega), sin(omega));

		for (int i = 0; 2 * i < n; ++i){
			a[i] 		=   a0[i] + w * a1[i];
			a[i + n/2] 	=   a0[i] - w * a1[i];
			w *= mul;
		}

	});

	auto __inverse_fft = y_combinator([](auto __inverse_fft, vector<complex> &y) -> void {
		
		int n = y.size();
		if (n == 1) return;

		vector<complex> y0(n/2), y1(n/2);

		for (int i = 0; 2 * i < n; i++) {
		    y0[i] = y[2*i];
		    y1[i] = y[2*i + 1];
	    }

		__inverse_fft(y0);
		__inverse_fft(y1);

		double omega = -2 * pi / n;

		complex w(1), mul(cos(omega), sin(omega));

		for (int i = 0; 2 * i < n; ++i){
			y[i] 		=   (y0[i] + w * y1[i]) / (complex)2;
			y[i + n/2] 	=   (y0[i] - w * y1[i]) / (complex)2;
			w *= mul;
		}
	});
}