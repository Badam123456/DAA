#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, amount;

    
    cout << "Enter number of coins: ";
    cin >> n;

    
    vector<int> coins(n);

    cout << "Enter the coin values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    
    cout << "Enter the amount: ";
    cin >> amount;

    vector<int> dp(amount + 1, amount + 1);

    
    vector<int> usedCoin(amount + 1, -1);
    dp[0] = 0;

    
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                if (dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;

                    
                    usedCoin[i] = coins[j];
                }
            }
        }
    }

    if (dp[amount] > amount)
    {
        cout << "Amount cannot be made using the given coins." << endl;
    }
    else
    {
        cout << "Minimum number of coins required: "
             << dp[amount] << endl;

        
        cout << "Coins used: ";

        int currentAmount = amount;

        while (currentAmount > 0)
        {
            int coin = usedCoin[currentAmount];

            cout << coin << " ";

            currentAmount = currentAmount - coin;
        }

        cout << endl;
    }

    return 0;
}
