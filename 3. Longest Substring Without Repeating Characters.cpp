

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> encounteredInSub; // pair of letter, index of encountered letter in substring

        int answer = 0;
        int currentLength = 0;

        int r = 0, l = 0;
        for (; r < s.size(); ++r)
        {
            char newLetter = s[r];
            map<char, int>::iterator foundCharIt = encounteredInSub.find(newLetter);

            if ((foundCharIt != encounteredInSub.end() && foundCharIt->second >= l)) // letter was not encountered previously
            {
                if (r - l > answer)
                    answer = r - l;
                l = foundCharIt->second + 1;
            }
            encounteredInSub[newLetter] = r;
        }

        if (r - l > answer)
        {
            answer = r - l;
        }
        return answer;
    }
};