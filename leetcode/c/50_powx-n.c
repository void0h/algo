/*****************************看过题解后***********************************/

double quick_mul(double x, long long n)
{
    double y;

    if (n == 0)
        return 1.0;
    y = quick_mul(x, n/2);
    return n%2 ? y * y * x : y * y;
}
double myPow(double x, int n){
    long long N = n;
    
    return n >= 0 ? quick_mul(x, N) : 1.0/quick_mul(x, N);
}