#include <iostream>
using namespace std;

/*=============================================================
                    COIN CHANGE PROBLEM
                  USING DYNAMIC PROGRAMMING

    Problem:
    ---------------------------------------------------------
    Given a set of coin denominations and a target amount,
    find:

    1. Minimum number of coins required to make the amount.
       Also display the coins used.

    2. Total number of different ways to make the amount.

    Example:
    ---------------------------------------------------------
    Coins  = {1, 2, 5}
    Amount = 5

    Minimum Coins:
        5

    Minimum Coins Required = 1
    Coins Used = 5

    Number of Ways:
        5
        2 + 2 + 1
        2 + 1 + 1 + 1
        1 + 1 + 1 + 1 + 1

        Total Ways = 4


    Dynamic Programming:
    ---------------------------------------------------------
    Minimum Coins:
        dp[i] stores the minimum number of coins required
        to make amount i.

    selected[i] stores the coin selected to obtain the
    minimum number of coins for amount i.

    Number of Ways:
        dp[i] stores the total number of combinations that
        can make amount i.


    Time Complexity:
        Minimum Coins : O(n * Amount)
        Number of Ways: O(n * Amount)

    Space Complexity:
        O(Amount)

    Where:
        n      = Number of coin denominations
        Amount = Target amount
=============================================================*/


#define MAX 100
#define INF 999999


/*=============================================================
                MINIMUM COINS FUNCTION

    Finds:
        1. Minimum number of coins
        2. Coins used to obtain the minimum

    Example:
        Coins = {12, 34, 16, 6}
        Amount = 24

        Minimum Coins = 2
        Coins Used = 12 + 12
=============================================================*/

int minimumCoins(int coin[], int n, int amount, int selected[])
{
    int dp[MAX];

    // Amount 0 requires 0 coins
    dp[0] = 0;

    // Initially, all amounts are impossible
    for(int i = 1; i <= amount; i++)
    {
        dp[i] = INF;
        selected[i] = -1;
    }


    // Calculate minimum coins for every amount
    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(coin[j] <= i)
            {
                // Check whether using this coin gives
                // a smaller number of coins
                if(dp[i - coin[j]] != INF &&
                   dp[i - coin[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coin[j]] + 1;

                    // Store the coin used
                    selected[i] = coin[j];
                }
            }
        }
    }


    // If amount cannot be made
    if(dp[amount] == INF)
        return -1;

    return dp[amount];
}


/*=============================================================
                NUMBER OF WAYS FUNCTION

    Finds the total number of different combinations
    that can make the given amount.

    Example:
        Coins = {1, 2, 5}
        Amount = 5

        Total Ways = 4
=============================================================*/

int numberOfWays(int coin[], int n, int amount)
{
    int dp[MAX];

    // Initialize DP array
    for(int i = 0; i <= amount; i++)
        dp[i] = 0;

    // One way to make amount 0:
    // choose no coins
    dp[0] = 1;


    // Process every coin
    for(int i = 0; i < n; i++)
    {
        for(int j = coin[i]; j <= amount; j++)
        {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }

    return dp[amount];
}


/*=============================================================
                        MAIN FUNCTION
=============================================================*/

int main()
{
    int coin[MAX];
    int n, amount;

    // Array to remember the selected coin
    int selected[MAX];


    cout << "=============================================\n";
    cout << "          COIN CHANGE - DYNAMIC PROGRAMMING\n";
    cout << "=============================================\n";


    // Input number of coins
    cout << "\nEnter number of coin denominations: ";
    cin >> n;


    // Input coin values
    cout << "Enter coin values: ";

    for(int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }


    // Input target amount
    cout << "Enter target amount: ";
    cin >> amount;


    // Calculate minimum coins
    int minCoins = minimumCoins(
        coin,
        n,
        amount,
        selected
    );


    // Calculate number of ways
    int ways = numberOfWays(
        coin,
        n,
        amount
    );


    /*=========================================================
                            OUTPUT
    =========================================================*/

    cout << "\n\n=============================================\n";
    cout << "                  RESULT\n";
    cout << "=============================================\n";


    cout << "Coin Denominations : ";

    for(int i = 0; i < n; i++)
    {
        cout << coin[i];

        if(i < n - 1)
            cout << ", ";
    }


    cout << "\nTarget Amount      : " << amount;

    cout << "\n---------------------------------------------\n";


    /*---------------------------------------------------------
                    MINIMUM COIN RESULT
    ---------------------------------------------------------*/

    if(minCoins == -1)
    {
        cout << "Minimum Coins      : Cannot make the amount\n";
        cout << "Coins Used         : None\n";
    }
    else
    {
        cout << "Minimum Coins      : " << minCoins << "\n";

        cout << "Coins Used         : ";

        int current = amount;

        bool first = true;

        /*
            Trace backwards from target amount.

            Example:
                amount = 24
                selected[24] = 12

                24 - 12 = 12
                selected[12] = 12

                12 - 12 = 0

            Therefore:
                12 + 12
        */

        while(current > 0)
        {
            if(!first)
                cout << " + ";

            cout << selected[current];

            current = current - selected[current];

            first = false;
        }

        cout << "\n";
    }


    /*---------------------------------------------------------
                    NUMBER OF WAYS RESULT
    ---------------------------------------------------------*/

    cout << "Number of Ways     : " << ways << "\n";


    cout << "=============================================\n";


    return 0;
}

/*
OUTPUT:
=============================================
          COIN CHANGE - DYNAMIC PROGRAMMING
=============================================

Enter number of coin denominations: 4
Enter coin values: 12
34
16
6
Enter target amount: 24


=============================================
                  RESULT
=============================================
Coin Denominations : 12, 34, 16, 6
Target Amount      : 24
---------------------------------------------
Minimum Coins      : 2
Coins Used         : 12 + 12
Number of Ways     : 3
=============================================

*/