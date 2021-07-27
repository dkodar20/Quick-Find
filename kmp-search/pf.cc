#include <bits/stdc++.h>
using namespace std;

namespace PrefixFunction {

        auto __pf = [](string &s, vector<int>& pi) -> void {
            int n = (int)s.length();
            pi.assign((unsigned)n, 0);

            for(int i = 1; i < n; i++){
                int j = pi[i-1];

                while(j > 0 and s[i] != s[j])
                    j = pi[j-1];

                if(s[i] == s[j])
                    j++;
                pi[i] = j;
            }
            return;
        };
}
