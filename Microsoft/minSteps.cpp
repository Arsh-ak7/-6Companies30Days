class Solution
{
public:
    int minSteps(int D)
    {
        // code here
        D = abs(D);
        int steps = 0;
        int sum = 0;
        while (steps < D || (steps - D) % 2 != 0)
        {
            sum++;
            steps += sum;
        }
        return sum;
    }
};
