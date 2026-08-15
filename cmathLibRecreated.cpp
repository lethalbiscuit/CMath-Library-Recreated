#include <iostream>
#define ERROR -1
namespace mth{
    // FORWARD DECLARATIONS & CONSTS BELOW--------------------------------------------------------------------------------------------------------------------------------
    double sqrt(double num);
    double nthRoot(double num, int root);
    double cbrt(double num);
    double abs(double num);
    double pwrInt(double base, long long exponent);
    double pwr(double base, double exponent);
    int flr(double num);
    const double rf = 2.236067977500; //Square root of 5
    const double phi = 1.618033988750; //Golden Ratio
    const double pi = 3.141592653589;
    const double e = 2.718281828459;
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------
    
    struct Roots{
        double x1;
        double x2;
    };
    
    struct Fraction{
        long long int numerator;
        long long int denominator;
    };
    
    struct Sine{ //Currently obsolete
        const double sin0 = 0;
        const double sin30 = 0.5;
        const double sin45 = sqrt(2)/2;
        const double sin60 = sqrt(3)/2;
        const double sin90 = 1;
    };
    
    struct Cosine{ //Currently obsolete
        const double cos0 = 1;
        const double cos30 = sqrt(3)/2;
        const double cos45 = sqrt(2)/2;
        const double cos60 = 0.5;
        const double cos90 = 0;
    };
    
    // Annoying forward declarations that have to be after the structs above ------------------------------------------------------------------------------------
    
    Fraction decimalToFrac(long double num);
    
    //-----------------------------------------------------------------------------------------------------------------------------------------------------------
    
    // Power function to handle decimal exponents
    double pwr(double base, double exponent){
        if (exponent < 0){
        return 1.0 / pwr(base, -exponent);
        }
        long long integerPart = flr(exponent);
        double fractionalPart = exponent - integerPart;

        double result = pwrInt(base, integerPart);

        double fraction = 0.5;
        double rootValue = nthRoot(base, 2);

        for (int i = 0; i < 30; i++)
        {
            if (fractionalPart >= fraction)
            {
                result *= rootValue;
                fractionalPart -= fraction;
            }

            rootValue = nthRoot(rootValue, 2);
            fraction /= 2.0;
        }

        return result;
    }

    // Same function as above but with an integer exponent
    double pwrInt(double base, long long exponent) {
    double result = 1.0;

    for (long long i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
    }

    // Calculates the root of something using Newton's method
    double nthRoot(double num, int root){
        if (root <= 0){
            std::cout << "Root must be positive.\n";
            return ERROR;
        }

        if (num < 0 && root % 2 == 0){
            std::cout << "Can't take an even root of a negative number.\n";
            return ERROR;
        }

        if (num == 0){
            return 0;
        }
        double x = (num > 1) ? num / root : 1.0;
        const double epsilon = 1e-10;

        for (int i = 0; i < 1000; i++){
            x = ((root - 1) * x +
                 num / pwrInt(x, static_cast<long long>(root - 1)))
                / root;

            if (abs(pwrInt(x, static_cast<long long>(root)) - num) < epsilon)
                return x;
        }

        return x;
    }   
    
    // Shortcut function for calculating square roots
    double sqrt(double num){
        double result = nthRoot(num, 2);
        return result;
    }

    // Shortcut function for calculating cube roots
    double cbrt(double num){
        double result = nthRoot(num, 3);
        return result;
    }

    // Pretty self explanatory, solves a quadratic when user inputs a,b,c terms 
    Roots solveQuadratic(double a, double b, double c) {
      double discriminant = b * b - 4 * a * c;
    
      return{
        (-b + nthRoot(discriminant, 2)) / (2.0 * a),
        (-b - nthRoot(discriminant, 2)) / (2.0 * a)
      };
    }

    // Returns the factorial value of a number
    long long int factorial(int num){

        if (num == 0){
            return 1;
        }
        else if (num < 0){
            std::cout << "Number cannot be less than zero.\n";
            return ERROR;
        }
        else{
            for (int i = num - 1; i >= 1; i--){
            num *= i;
            }
            return num;
        }
    }

    // Determines the absolute value of a number using ternary operator, essentially does "if num < 0 return -num, else return num"
    double abs(double num){
        return num < 0 ? -num : num;
    }

    // Floors a number (rounds down) by casting double -> int
    int flr(double num){
        int whole = static_cast<int>(num);

        if (num < 0 && num != whole){
            return whole - 1;
        }

        return whole;
    }

    // Ceils a number (rounds up)
    int ceil(double num){
        int whole = flr(num);

        if (num == whole){
            return whole;
        }

        return whole + 1;
    }

    // Checks if a number is a decimal or not
    bool isDecimal(double num){
        if ((num - flr(num)) > 0){
            return true;
        }
        else{
            return false;
        }
    }

    // Determines Highest Common Factor
    long long int HCF(long long int a, long long int b){
        while (b != 0){
            long long int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Converts a decimal to a fraction with 6 digits of precision, thus all fractions outputted from this function should be considered tiny approximations
    Fraction decimalToFrac(long double num){
        long long int denominator = 100000;
        long long int numerator = (long long int)(num * denominator);

        long long int divisor = HCF(numerator, denominator);

        Fraction result;
        result.numerator = numerator / divisor;
        result.denominator = denominator / divisor;

        return result;
    }

    // A shortcut to printing the fractions calculated with the decimalToFrac function
    void printFrac(long double num){
        Fraction f = decimalToFrac(num);
        std::cout << f.numerator << "/" << f.denominator;
    }

    // Rounds a positive or negative number up or down
    int rnd(double num){
        if (num >= 0){
            return flr(num + 0.5);
        }
        else{
            return ceil(num - 0.5);
        }
    }

    // Finds the middle point between two numbers
    double mpnt(double lower, double upper){
        return (lower + upper) / 2;
    }

    // Finds the upper bound when you input a lower bound and middle point, probably can't cope with negatives
    double determineUpper(double lower, double mpnt){
        double difference = mpnt - lower;
        double upper = mpnt + difference;
        return upper;
    }

    // Finds the lower bound when you input an upper bound and middle point
    double determineLower(double mpnt, double upper){
        double difference = upper - mpnt;
        double lower = mpnt - difference;
        return lower;
    }

    // Removes the decimal part of a number but returns value with type double
    double trunc(double num){
        return num >= 0 ? static_cast<double>(flr(num)) : static_cast<double>(ceil(num));
    }

    // Returns x * 2 ^ y
    double ldexp(double x, double y){
        return x*pwr(2, y);
    }

    // Performs modulo on objects of type double and can return decimal remainders
    double fmod(double x, double y){
        return x - trunc(x / y) * y;
    }

    // Calculates logarithm with any base and exponent
    double log(double base, double argument){
        if (base <= 0 || base == 1 || argument <= 0){
            std::cout << "Invalid log, exiting...\n";
            return ERROR;
        }

        double low = 0.0;
        double high = argument;
        const double epsilon = 1e-10;

        while (high - low > epsilon){
            double mid = (low + high) / 2.0;

            if (pwr(base, mid) < argument)
                low = mid;
            else
                high = mid;
        }

        return (low + high) / 2.0;
    }

    // Simple function to calculate natural log using the previously defined log() function
    double ln(double argument){
        double result = log(e, argument);
        return result;
    }

    // Simplified version of Binet's formula for working out the nth fibonacci number without having to know the previous ones
    int fib(int n){
        int result = rnd((pwrInt(phi, n)) / rf);
        return result;
    }

    // Calculates x/y rounded to the nearest integer, writes the result to the memory at pointer z and returns the remainder. 
    // Quotient = the amount of times a number fit into another within division
    // Remainder = the leftover after fitting number into the other the maximum amount of times
    // This function is stupid.
    int remquo(double x, double y, int* z){
        if (y == 0){
            std::cout << "Division by zero in remquo function, exiting...";
            return ERROR;
        }

        *z = rnd(x / y);
        
        return x - (*z * y);
    }

    // With x expressed as m*2^n, returns the value of m (a value between 0.5 and 1.0) and writes the value of n to the memory at the pointer y
    double frexp(double x, int* y = nullptr){
        if (x == 0.0){
            if (y) *y = 0;
            return 0.0;
        }

        int e = 0;
        double m = abs(x);

        while (m >= 1.0){
            m /= 2.0;
            e++;
        }

        while (m < 0.5){
            m *= 2.0;
            e--;
        }

        if (x < 0){
            m = -m;
        }

        if (y){
            *y = e;
        }
        return m;
    }

    //Function for working out e^x
    double exp(double x){
        return pwr(e, x);
    }
    
}    
int main(){
    return 0;
}
