/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// wrzucamy na stos, potem ściągamy i mnozymy
class Solution
{
public:
    inline int handleSum(int &a, int b, int carry) // adds b to a and returns carry
    {
        int sumOfValues = a + b + carry;
        a = sumOfValues % 10;
        return sumOfValues /= 10;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        // przeniesienie to max 1  !!!!!!!!!!!!

        ListNode *l1Pointer = l1;
        ListNode *l2Pointer = l2;

        ListNode *lastElementOfl1;
        ListNode *lastElementOfl2;

        int carry = 0;

        while (l1Pointer != nullptr && l2Pointer != nullptr) // add until numbers have the same length
        {
            carry = handleSum(l1Pointer->val, l2Pointer->val, carry);

            if (l1Pointer->next == nullptr)
                lastElementOfl1 = l1Pointer;
            if (l2Pointer->next == nullptr)
                lastElementOfl2 = l2Pointer;

            l1Pointer = l1Pointer->next; // moving pointers over list
            l2Pointer = l2Pointer->next;
        }

        while (l1Pointer != nullptr && carry != 0) // case when l2 was shorter
        {
            carry = handleSum(l1Pointer->val, 0, carry);

            if (l1Pointer->next == nullptr)
                lastElementOfl1 = l1Pointer;
            l1Pointer = l1Pointer->next;
        }

        l1Pointer = lastElementOfl1;
        while (l2Pointer != nullptr) // case when l1 was shorter
        {
            carry = handleSum(l2Pointer->val, 0, carry);
            l1Pointer->next = l2Pointer;
            l1Pointer = l2Pointer;
            if (l2Pointer->next == nullptr)
                lastElementOfl1 = l2Pointer;
            l2Pointer = l2Pointer->next;
        }
        //         while (l2Pointer != nullptr) // case when l1 was shorter
        // {
        //     carry = handleSum(l2Pointer->val, 0, carry);
        //     l1Pointer->next = l2Pointer;
        //     if(l2Pointer->next==nullptr)
        //         lastElementOfl1 = l2Pointer;
        //     l2Pointer = l2Pointer->next;
        // }

        if (carry == 1) // add next node if neccessary
        {
            lastElementOfl1->next = new ListNode(carry);
        }

        return l1;
    }
};

// =============================
// this solution is slower
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// wrzucamy na stos, potem ściągamy i mnozymy
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l1It = l1;
        ListNode *l2It = l2;

        ListNode *previousL1It = l1;
        ListNode *previousL2It = l2;

        bool carry = false;

        while (l1It != nullptr && l2It != nullptr)
        {
            l1It->val += l2It->val;
            if (carry)
                ++(l1It->val);

            if (l1It->val >= 10)
            {
                l1It->val -= 10;
                carry = true;
            }
            else
            {
                carry = false;
            }

            previousL1It = l1It;
            previousL2It = l2It;

            l1It = l1It->next;
            l2It = l2It->next;
        }

        // Pozbyć się temp !!!!!!!!!!!!
        while (l2It != nullptr) // case when l2 was longer
        {
            previousL1It->next = l2It;
            if (carry)
                ++(l2It->val);
            if (l2It->val >= 10)
            {
                l2It->val -= 10;
                carry = true;
            }
            else
            {
                carry = false;
            }

            l2It = l2It->next;
            previousL1It = previousL1It->next;
        }

        while (l1It != nullptr && carry)
        {
            ++l1It->val;
            if (l1It->val >= 10)
            {
                l1It->val -= 10;
                carry = true;
            }
            else
                carry = false;

            previousL1It = l1It;
            l1It = l1It->next;
        }

        if (carry)
        {
            previousL1It->next = new ListNode(1);
        }

        return l1;
    }
};

// =============== final version, the fastest
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// wrzucamy na stos, potem ściągamy i mnozymy
class Solution
{
public:
    inline int handleSum(int &a, int b, int carry) // adds b to a and returns carry
    {
        int sumOfValues = a + b + carry;
        a = sumOfValues % 10;
        return sumOfValues /= 10;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        // przeniesienie to max 1  !!!!!!!!!!!!

        ListNode *l1Pointer = l1;
        ListNode *l2Pointer = l2;

        ListNode *lastElementOfl1;

        int carry = 0;

        while (l1Pointer != nullptr || l2Pointer != nullptr) // add until numbers have the same length
        {
            if (l1Pointer == nullptr) // przesuwamy l2 i dodajemy carry
            {
                lastElementOfl1->next = l2Pointer;

                l2Pointer->val += carry;
                carry = l2Pointer->val / 10;
                l2Pointer->val %= 10;
                lastElementOfl1 = l2Pointer;

                l2Pointer = l2Pointer->next;
            }
            else // dodajemy
            {
                if (l2Pointer == nullptr) // l1!=nullptr l2==nullptr
                {
                    // dodajemy carry aż nie będzie 0
                    if (carry == 0)
                        break;

                    l1Pointer->val += carry;
                    carry = l1Pointer->val / 10;
                    l1Pointer->val %= 10;

                    lastElementOfl1 = l1Pointer;
                    l1Pointer = l1Pointer->next;
                }
                else // l1!=nullptr l2!=nullptr
                {
                    l1Pointer->val += l2Pointer->val + carry;
                    carry = l1Pointer->val / 10;
                    l1Pointer->val %= 10;

                    lastElementOfl1 = l1Pointer;
                    l1Pointer = l1Pointer->next;
                    l2Pointer = l2Pointer->next;
                }
            }
        }

        if (carry != 0) // add next node if neccessary
        {
            lastElementOfl1->next = new ListNode(carry);
        }

        return l1;
    }
};