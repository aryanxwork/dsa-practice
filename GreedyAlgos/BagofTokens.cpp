#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int bagOfTokensScore(vector<int> &tokens, int power)
{
    sort(tokens.begin(), tokens.end());
    int i = 0;
    int j = tokens.size() - 1;
    int maxScore = 0;
    int score = 0;
    for (int k = 0; k < tokens.size(); k++)
    {
        if (power >= tokens[i])
        {
            // face up
            score++;
            maxScore = max(score, maxScore);
            power -= tokens[i];
            i++;
        }
        else if (score >= 1)
        {
            // face down
            score--;
            power += tokens[j];
            j--;
        }
    }
    return maxScore;
}