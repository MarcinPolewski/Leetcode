class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
            }
        }
        return vector<int>();
    }
};

// ===========================================

struct Element
{
    int index, value;
    Element(int a, int b) : index(a), value(b) {}
    Element() = default;
    bool operator<(const Element &other) const
    {
        return value != other.value ? (value < other.value) : (index < other.index);
    }
    bool operator<(int other) const
    {
        return value < other;
    }
};

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // sort nums without loosing information about indexes
        vector<Element> temp;
        for (int i = 0; i < nums.size(); ++i)
            temp.push_back(Element(i, nums[i]));
        sort(temp.begin(), temp.end());

        // for every element of nums find with binary search if element exists
        for (auto it = temp.begin(); it != temp.end(); ++it)
        {
            int seekedValue = target - (*it).value;
            auto foundElement = lower_bound(it + 1, temp.end(), seekedValue);
            if (foundElement != temp.end() && (*foundElement).value + (*it).value == target)
                return vector<int>{(*foundElement).index, (*it).index};
        }
        return vector<int>();
    }
};