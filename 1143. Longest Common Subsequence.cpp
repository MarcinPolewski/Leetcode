
#define N 1005

int dynamicTable[N][N];

class Solution
{
public:
    int longestCommonSubsequence(string &s1, string &s2)
    {
        int ansLength = 0;

        for (int i = 1; i <= s1.length(); ++i)
        {
            for (int j = 1; j <= s2.length(); ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dynamicTable[i][j] = dynamicTable[i - 1][j - 1] + 1;
                    if (dynamicTable[i][j] > ansLength)
                    {
                        ansLength = dynamicTable[i][j];
                    }
                }
                else
                {
                    dynamicTable[i][j] = max(dynamicTable[i - 1][j], dynamicTable[i][j - 1]);
                }
            }
        }

        return ansLength;
    }
};