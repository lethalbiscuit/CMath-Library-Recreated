#include "cmathLibRecreatedHeader.hpp"
#include <iostream>
#include <vector>

int main(){
    std::vector<unsigned long long> factorialValues {1, 1, 2, 6, 24, 120, 720};

    std::cout << "Enter the amount of factorial values you want to test: ";
    int valueAmount;
    std::cin >> valueAmount;

    for (std::size_t i = factorialValues.size(); i <= valueAmount; ++i){
        factorialValues.push_back(factorialValues[i - 1] * i);
    }

    for (std::size_t i = 0; i < factorialValues.size(); ++i){
        unsigned long long functionAnswer = mth::factorial(i);
        if (functionAnswer == factorialValues[i]){
            std::cout << "-----------------------------------------------------------------------------------" << 
                         "\nFunction answered correctly at value: " << i <<
                         "\nFunction answered: " << mth::factorial(i) << 
                         "\nAnd the correct answer was: " << factorialValues[i] << "\n";
        }
        else{
            std::cout << "-----------------------------------------------------------------------------------" << 
            "\nFunction incorrect at value: " << i << 
            "\nFunction answered: " << mth::factorial(i) <<
            "\nAnd the correct answer was: " << factorialValues[i] << "\n";
        }
    }
    return 0;
}