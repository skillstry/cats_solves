#include <fstream>


int main()
{
    std::ifstream in("input.txt");
    int n;
    in >> n;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) { arr[i] = new int[n]; };
    int i = 1, j, k, p = n / 2;
    for (k = 1; k <= p; k++)
    {
        for (j = k - 1; j < n - k + 1; j++)
            arr[k - 1][j] = i++;
        for (j = k; j < n - k + 1; j++)
            arr[j][n - k] = i++;
        for (j = n - k - 1; j >= k - 1; --j)
            arr[n - k][j] = i++;
        for (j = n - k - 1; j >= k; j--)
            arr[j][k - 1] = i++;
    }
    if (n % 2 == 1)
        arr[p][p] = n * n;
    std::ofstream out("output.txt");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (j == n - 1) { out << arr[i][j] << '\n'; }
            else { out << arr[i][j] << " "; }
        }
}