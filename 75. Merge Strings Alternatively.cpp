#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        string result = "";
        int commonLength = min(word1.length(), word2.length());

        cout << commonLength << endl;

        for (int i = 0; i < commonLength; ++i)
        {
            result += word1[i];
            result += word2[i];
        }

        for (int i = commonLength; i < word1.length(); ++i)
            result += word1[i];

        for (int i = commonLength; i < word2.length(); ++i)
            result += word2[i];

        return result;
    }
};

int main()
{
    Solution s;
    string result = s.mergeAlternately("abc", "cdf");
    cout << result << "\n";

    return 0;
}