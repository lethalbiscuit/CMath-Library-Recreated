#pragma once
namespace mth{
    struct Roots{
        double x1;
        double x2;
    };
    
    struct Fraction{
        long long int numerator;
        long long int denominator;
    };

    Roots solveQuadratic(double a, double b, double c);
    Fraction decimalToFrac(long double num);
    double pwr(double base, double exponent);
    double pwrInt(double base, long long exponent);
    double nthRoot(double num, int root);
    double sqrt(double num);
    double cbrt(double num);
    unsigned long long factorial(unsigned long long num);
    double abs(double num);
    int flr(double num);
    int ceil(double num);
    bool isDecimal(double num);
    long long int HCF(long long int a, long long int b);
    void printFrac(long double num);
    int rnd(double num);
    double mpnt(double lower, double upper);
    double determineUpper(double lower, double mpnt);
    double determineLower(double mpnt, double upper);
    double trunc(double num);
    double ldexp(double x, double y);
    double fmod(double x, double y);
    double log(double base, double argument);
    double ln(double argument);
    int fib(int n);
    int remquo(double x, double y, int* z);
    double frexp(double x, int* y = nullptr);
    double exp(double x);
}