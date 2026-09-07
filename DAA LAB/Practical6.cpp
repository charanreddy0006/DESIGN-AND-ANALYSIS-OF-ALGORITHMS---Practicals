/*
    =========================================================
              MATRIX CHAIN MULTIPLICATION
              Using Dynamic Programming
    =========================================================

    Aim:
    Find the minimum number of scalar multiplications
    required to multiply a chain of matrices.

    Description:
    Matrix multiplication can be performed in different
    orders. Each order may require a different number of
    scalar multiplications. This program finds the most
    efficient multiplication order.

    Approach:
    - Use Dynamic Programming.
    - Store minimum multiplication costs in a DP table.
    - Store the split position to find the optimal order.
    - Display the matrix details, DP table, minimum cost,
      and optimal multiplication order.

    Example:
    A1 = 2 x 4
    A2 = 4 x 6
    A3 = 6 x 8

    Optimal Order:
    (A1 x A2) x A3

    Minimum Multiplications:
    144

    Time Complexity  : O(n^3)
    Space Complexity : O(n^2)
    =========================================================
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX 100
#define INF 999999

// Function to print optimal parenthesization
void printOrder(int split[MAX][MAX], int i, int j)
{
    // Only one matrix
    if (i == j)
    {
        cout << "A" << i;
        return;
    }

    cout << "(";

    // Print left part
    printOrder(split, i, split[i][j]);

    cout << " x ";

    // Print right part
    printOrder(split, split[i][j] + 1, j);

    cout << ")";
}


// Matrix Chain Multiplication
int matrixChain(int p[], int n, int split[MAX][MAX])
{
    int dp[MAX][MAX] = {0};

    // Cost of multiplying one matrix is 0
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    // l = chain length
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;

            dp[i][j] = INF;

            for (int k = i; k < j; k++)
            {
                int cost =
                    dp[i][k]
                    + dp[k + 1][j]
                    + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;

                    // Store best splitting position
                    split[i][j] = k;
                }
            }
        }
    }

    // Display DP Cost Table
    cout << "\n============================================\n";
    cout << "              DP COST TABLE\n";
    cout << "============================================\n\n";

    cout << setw(8) << " ";

    for (int j = 1; j <= n; j++)
    {
        cout << setw(10) << ("A" + to_string(j));
    }

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << setw(8) << ("A" + to_string(i));

        for (int j = 1; j <= n; j++)
        {
            if (j < i)
            {
                cout << setw(10) << "-";
            }
            else
            {
                cout << setw(10) << dp[i][j];
            }
        }

        cout << endl;
    }

    return dp[1][n];
}


int main()
{
    int n;
    int p[MAX];

    // Stores optimal split positions
    int split[MAX][MAX] = {0};

    cout << "============================================\n";
    cout << "       MATRIX CHAIN MULTIPLICATION\n";
    cout << "============================================\n";

    cout << "\nEnter number of matrices: ";
    cin >> n;

    cout << "\nEnter " << n + 1 << " dimensions:\n";

    cout << "Example: For A1(10x20), A2(20x30), enter:\n";
    cout << "10 20 30\n\n";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }


    // Display Matrix Details
    cout << "\n============================================\n";
    cout << "              MATRIX DETAILS\n";
    cout << "============================================\n";

    for (int i = 1; i <= n; i++)
    {
        cout << "A" << i
             << " = "
             << p[i - 1]
             << " x "
             << p[i]
             << endl;
    }


    // Calculate minimum cost
    int minimumCost = matrixChain(p, n, split);


    // Display Final Result
    cout << "\n============================================\n";
    cout << "               FINAL RESULT\n";
    cout << "============================================\n";

    cout << "\nOptimal Multiplication Order = ";

    printOrder(split, 1, n);

    cout << endl;

    cout << "\nMinimum Scalar Multiplications = "
         << minimumCost
         << endl;

    cout << "\n============================================\n";

    return 0;
}


/*
OUTPUT:
============================================
       MATRIX CHAIN MULTIPLICATION
============================================

Enter number of matrices: 3

Enter 4 dimensions:
Example: For A1(10x20), A2(20x30), enter:
10 20 30

2
3
4
5

============================================
              MATRIX DETAILS
============================================
A1 = 2 x 3
A2 = 3 x 4
A3 = 4 x 5

============================================
              DP COST TABLE
============================================

                A1        A2        A3
      A1         0        24        64
      A2         -         0        60
      A3         -         -         0

============================================
               FINAL RESULT
============================================

Optimal Multiplication Order = ((A1 x A2) x A3)

Minimum Scalar Multiplications = 64

============================================
*/