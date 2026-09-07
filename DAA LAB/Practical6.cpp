#include <iostream>
#include <iomanip>
using namespace std;

#define MAX 100
#define INF 999999

/*
    Matrix Chain Multiplication using Dynamic Programming

    Time Complexity:
    Best Case    : O(n^3)
    Average Case : O(n^3)
    Worst Case   : O(n^3)

    Space Complexity:
    O(n^2)
*/

int matrixChain(int p[], int n)
{
    int dp[MAX][MAX] = {0};

    // Cost of multiplying one matrix is 0
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;

    // Chain length
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i <= n - l + 1; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INF;

            for (int k = i; k < j; k++)
            {
                int q = dp[i][k]
                      + dp[k + 1][j]
                      + p[i - 1] * p[k] * p[j];

                if (q < dp[i][j])
                    dp[i][j] = q;
            }
        }
    }

    // Display DP Table
    cout << "\n============================================\n";
    cout << "        DP COST TABLE\n";
    cout << "============================================\n\n";

    cout << setw(6) << " ";

    for (int j = 1; j <= n; j++)
        cout << setw(8) << "A" + to_string(j);

    cout << "\n";

    for (int i = 1; i <= n; i++)
    {
        cout << setw(6) << "A" + to_string(i);

        for (int j = 1; j <= n; j++)
        {
            if (j < i)
                cout << setw(8) << "-";
            else
                cout << setw(8) << dp[i][j];
        }

        cout << endl;
    }

    return dp[1][n];
}

int main()
{
    int n;
    int p[MAX];

    cout << "============================================\n";
    cout << "       MATRIX CHAIN MULTIPLICATION\n";
    cout << "============================================\n";

    cout << "\nEnter number of matrices: ";
    cin >> n;

    cout << "\nEnter " << n + 1 << " dimensions:\n";
    cout << "Example: For A1(10x20), A2(20x30), enter:\n";
    cout << "10 20 30\n\n";

    for (int i = 0; i <= n; i++)
        cin >> p[i];

    // Display matrices
    cout << "\n============================================\n";
    cout << "             MATRIX DETAILS\n";
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

    // Calculate minimum multiplication cost
    int result = matrixChain(p, n);

    cout << "\n============================================\n";
    cout << "              FINAL RESULT\n";
    cout << "============================================\n";

    cout << "\nMinimum Scalar Multiplications = "
         << result << endl;

    cout << "\n============================================\n";

    return 0;
}