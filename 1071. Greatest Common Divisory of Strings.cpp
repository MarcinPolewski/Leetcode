#include <algorithm>

// version 2 - checking only lengths of substrings that are common divisors of str1.length() and str2.length()

#include <algorithm>

class Solution
{
public:
    bool doStringsHaveGCDOfLength(string const &str1, string const &str2, int GCDLength)
    {
        int commonLength = min(str1.length(), str2.length());

        // check common part
        int gcdIdx = 0;
        for (int i = 0; i < commonLength; ++i)
        {
            if (str1[i] != str2[i] || str1[i] != str1[gcdIdx])
                return false;

            gcdIdx = (gcdIdx + 1) % GCDLength;
        }

        // pattern didn't match completely - to remove when GCDLength is only common dividers
        if (gcdIdx != 0)
            return false;

        gcdIdx = 0;
        for (int str1Idx = commonLength; str1Idx < str1.length(); ++str1Idx)
        {
            if (str1[str1Idx] != str1[gcdIdx])
                return false;

            gcdIdx = (gcdIdx + 1) % GCDLength;
        }

        // pattern didn't match completely - to remove when GCDLength is only common dividers
        if (gcdIdx != 0)
            return false;

        gcdIdx = 0;
        for (int str2Idx = commonLength; str2Idx < str2.length(); ++str2Idx)
        {
            if (str2[str2Idx] != str2[gcdIdx])
                return false;

            gcdIdx = (gcdIdx + 1) % GCDLength;
        }

        // pattern didn't match completely - to remove when GCDLength is only common dividers
        if (gcdIdx != 0)
            return false;

        return true;
    }

    int greatestCommonDivisor(int a, int b)
    {
        while (b)
        {
            a = b;
            b = a % b;
        }
        return a;
    }

    set<int> findCommonDivisors(int a, int b)
    {

        int gcd = greatestCommonDivisor(a, b);
        set<int> divisors = {1, gcd};

        for (int i = 2; i * i <= gcd; i++)
        {
            if (gcd % i == 0)
            {
                divisors.insert(i);
                if (i != gcd / i) // Avoid duplicate when n is a perfect square
                    divisors.insert(gcd / i);
            }
        }

        return divisors;
    }

    string gcdOfStrings(string const &str1, string const &str2)
    {
        int commonLength = min(str1.length(), str2.length());

        set<int> commonDivisors = findCommonDivisors(str1.length(), str2.length());

        for (auto it = commonDivisors.rbegin(); it != commonDivisors.rend(); ++it)
        {
            if (doStringsHaveGCDOfLength(str1, str2, *it))
            {
                return str1.substr(0, *it);
            }
        }
        return "";
    }
};

// ===== version 1 =====

class Solution
{
public:
    bool doStringsHaveGCDOfLength(string const &str1, string const &str2, int GCDLength)
    {
        int commonLength = min(str1.length(), str2.length());

        // check common part
        int gcdIdx = 0;
        for (int i = 0; i < commonLength; ++i)
        {
            if (str1[i] != str2[i] || str1[i] != str1[gcdIdx])
                return false;

            gcdIdx = (gcdIdx + 1) % GCDLength;
        }

        // pattern didn't match completely - to remove when GCDLength is only common dividers
        if (gcdIdx != 0)
            return false;

        gcdIdx = 0;
        for (int str1Idx = commonLength; str1Idx < str1.length(); ++str1Idx)
        {
            if (str1[str1Idx] != str1[gcdIdx])
                return false;

            gcdIdx = (gcdIdx + 1) % GCDLength;
        }

        // pattern didn't match completely - to remove when GCDLength is only common dividers
        if (gcdIdx != 0)
            return false;

        gcdIdx = 0;
        for (int str2Idx = commonLength; str2Idx < str2.length(); ++str2Idx)
        {
            if (str2[str2Idx] != str2[gcdIdx])
                return false;

            gcdIdx = (gcdIdx + 1) % GCDLength;
        }

        // pattern didn't match completely - to remove when GCDLength is only common dividers
        if (gcdIdx != 0)
            return false;

        return true;
    }

    string gcdOfStrings(string const &str1, string const &str2)
    {
        int commonLength = min(str1.length(), str2.length());

        // <- not neccessary to check all lenghts, only common dividers of str1 and str2 length
        for (int GCDLength = commonLength; GCDLength >= 1; --GCDLength)
        {
            if (doStringsHaveGCDOfLength(str1, str2, GCDLength))
            {
                return str1.substr(0, GCDLength);
            }
        }
        return "";
    }
};

// Notes / ideas"
/*
    - count number of letter for each str for ABCABC ->
        2*A 2*B 2*C , here 2 is the GCD(except the whole word)
        ABAABA, 4*A 2*B , here
    - strings must have the same beginning, iterate over both as long as letter match?
    - gcd must start at the beginning of str - check each length
*/