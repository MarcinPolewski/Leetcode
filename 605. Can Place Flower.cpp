
version 3

    // version 2 - cleaned up code
    class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int howManyHolesToFind = n;

        if (n == 0 || flowerbed.size() == 1 && flowerbed[0] == 0)
        {
            return true;
        }

        for (int i = 0; i < flowerbed.size() - 1 && howManyHolesToFind != 0; ++i)
        {
            cout << i << endl;
            if (flowerbed[i] == 1)
            {
                ++i;
            }
            else if (flowerbed[i + 1] == 0)
            {
                // we are guaranteed, that left is clear
                --howManyHolesToFind;
                flowerbed[i] = 1;
                ++i;
            }
            else
            {
                i += 2;
            }
        }

        if (flowerbed[flowerbed.size() - 1] == 0 &&
            flowerbed[flowerbed.size() - 2] == 0)
        {
            --howManyHolesToFind;
        }

        return howManyHolesToFind <= 0;
    }
};

// version 1 - quite slow

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int howManyLeftToFind = n;

        if (n == 0)
        {
            return true;
        }

        if (flowerbed.size() == 1 && flowerbed[0] == 0)
        {
            return n == 1;
        }

        if (3 * n > 2 * flowerbed.size()) // n > (2/3) * flowerbed.size()
        {
            return false;
        }

        if (flowerbed.size() > 1 && flowerbed[0] == 0 && flowerbed[1] == 0)
        {
            flowerbed[0] = 1;
            --howManyLeftToFind;
            cout << "a";
        }

        for (int holeIdx = 1; holeIdx < flowerbed.size() - 1 && howManyLeftToFind != 0; ++holeIdx)
        {
            if (flowerbed[holeIdx] == 0 &&
                flowerbed[holeIdx - 1] == flowerbed[holeIdx + 1] &&
                flowerbed[holeIdx - 1] == flowerbed[holeIdx])
            {
                flowerbed[holeIdx] = 1;
                --howManyLeftToFind;
                cout << "b";
            }
        }

        if (howManyLeftToFind != 0 && flowerbed.size() > 2 &&
            flowerbed[flowerbed.size() - 1] == 0 &&
            flowerbed[flowerbed.size() - 2] == 0)
        {
            --howManyLeftToFind;
            cout << "d";
        }

        return howManyLeftToFind == 0;
    }
};