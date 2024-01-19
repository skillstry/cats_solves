#include <iostream>
#include <fstream>
bool dim_is_valid(long long dim, long long w, long long h, long long n)
{
    return  (dim / w) * (dim / h) >= n;
}

long long f(long long w, long long h, long long n)
{
    long long R = 1;
    while (!dim_is_valid(R, w, h, n))
    {
        R *= 2;
    }
    long long L = R / 2;
    while (R - L > 1)
    {
        long long N = (L + R) / 2;
        if (!dim_is_valid(N, w, h, n))
        {
            L = N;
        }
        else
        {
            R = N;
        }
    }
    return  R;
}
int main()
{
    long long w = 0;
    long long h = 0;
    long long n = 0;

    std::fstream in("diploma.in");
    in >> w >> h >> n;
    in.close();
    std::ofstream out("diploma.out");
    out << f(w, h, n);
    return 0;
}