class Solution
{
public:
    int sumOfSq(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            int digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {

        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end())
        {
            seen.insert(n);
            n = sumOfSq(n);
        }
        return n == 1;
    }
};