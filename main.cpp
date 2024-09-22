#include <iostream>
#include <vector>

const int n = 15;
const int len = 10 * n / 3;

int main()
{
    std::vector<int> digits;
    std::vector<long> a(len + 1, 2); // Start with 2s
    int nines = 0;
    int predigit = 0;

    for (int j = 1; j <= n; ++j)
    {
        int q = 0;

        for (int i = len; i >= 1; --i)
        { // Work backwards
            long x = 10 * a[i] + q * i;
            a[i] = x % (2 * i - 1);
            q = x / (2 * i - 1);
        }

        a[1] = q % 10;
        q = q / 10;

        if (q == 9)
        {
            nines++;
        }
        else if (q == 10)
        {
            digits.push_back((predigit + 1));
            for (int k = 0; k < nines; ++k)
            {
                digits.push_back(0);
            }
            predigit = 0;
            nines = 0;
        }
        else
        {
            digits.push_back(predigit);
            predigit = q;
            if (nines != 0)
            {
                for (int k = 0; k < nines; ++k)
                {
                    digits.push_back(9);
                }
                nines = 0;
            }
        }
    }
    digits.push_back(predigit);
    digits.erase(digits.begin());

    for (int i = 0; i < digits.size(); ++i)
    {
        std::cout << digits[i];
    }

    return 0;
}
