#include <bits/stdc++.h>
using namespace std;
long long computeHash(string s, int m)
{
    long long hash = 0;
    for (int i = 0; i < m; i++)
    {
        hash += s[i] * pow(10, m - i - 1);
    }
    return hash;
}
void rabinKarp(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    long long patternHash = computeHash(pattern, m);
    long long textHash = computeHash(text.substr(0, m), m);

    long long highestPower = pow(10, m - 1);

    for (int i = 0; i <= n - m; i++)
    {

        // Hash matched
        if (patternHash == textHash)
        {

            bool match = true;

            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }

            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Rolling hash update
        if (i < n - m)
        {

            textHash =
                (textHash - text[i] * highestPower) * 10 + text[i + m];
        }
    }
}

int main()
{

    string text = "AABAACAADAABAABA";
    string pattern = "AABA";

    rabinKarp(text, pattern);

    return 0;
}