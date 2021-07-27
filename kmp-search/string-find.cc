#include "prefixfunction.cc"
using namespace std;

vector<int> kmp_search(string text, string pattern)
{
        int m = (int)pattern.length(),
            n = (int)text.length();

        string temp = pattern+"#"+text;
        vector<int> pi,
                    result;

        using namespace PrefixFunction;
        __pf(temp, pi);

        for(int i = m+1; i < n+m; i++)
            if(pi[(unsigned)i] == m)
                result.push_back(i-2*m);

        return result;
}
