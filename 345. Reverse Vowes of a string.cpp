
// version 2 - simplified to have only one loop
class Solution
{
public:
    string reverseVowels(string &s)
    {

        int l = 0, r = s.length() - 1;

        while (l < r)
        {
            if (isVowel(s[l]))
            {
                if (isVowel(s[r]))
                {
                    swap(s[l], s[r]);
                    ++l;
                    --r;
                }
                else
                {
                    --r;
                }
            }
            else
            {
                ++l;
            }
        }
        return s;
    }

private:
    set<char> vowels{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

    bool isVowel(char c)
    {
        return vowels.find(c) != vowels.end();
    }
};

// version 1

set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

class Solution
{
public:
    bool isVowel(char c)
    {
        return vowels.find(c) != vowels.end();
    }

    string reverseVowels(string &s)
    {

        int l = 0, r = s.length() - 1;
        bool nothingToSwap = false;
        while (l < r && !nothingToSwap)
        {
            cout << l << " " << r << endl;
            // find i-th vowel from the left
            bool leftVowelFound = false, rightVowelFound = false;

            for (int i = l; i < r && (!leftVowelFound); ++i)
            {
                if (isVowel(s[i]))
                {
                    l = i;
                    leftVowelFound = true;
                }
            }

            // find i-th vowel from the right
            for (int i = r; i > l && (!rightVowelFound); --i)
            {
                if (isVowel(s[i]))
                {
                    r = i;
                    rightVowelFound = true;
                }
            }

            if (leftVowelFound && rightVowelFound)
            {
                swap(s[l], s[r]);
                r--;
                l++;
            }
            else
            {
                nothingToSwap = true;
            }
        }

        return s;
    }
};