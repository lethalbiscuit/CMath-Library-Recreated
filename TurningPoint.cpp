#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::vector<double> terms;

    std::cout << "Enter the terms of your parabola (a b c): ";

    std::string line;
    std::getline(std::cin, line);

    std::istringstream iss(line);
    double value;

    while (iss >> value) {
        terms.push_back(value);
    }

    // Validate input
    if (terms.size() != 3) {
        std::cout << "Please enter exactly 3 terms.\n";
        return 1;
    }

    double a = terms[0];
    double b = terms[1];
    double c = terms[2];

    if (a == 0) {
        std::cout << "This is not a quadratic equation.\n";
        return 1;
    }

    // Complete the square
    double h = b / (2 * a);
    double k = c - (b * b) / (4 * a);

    std::cout << "The completed square form is:\n";
    std::cout << a << "(x";

    if (h >= 0)
        std::cout << " + " << h;
    else
        std::cout << " - " << -h;

    std::cout << ")^2";

    if (k >= 0)
        std::cout << " + " << k;
    else
        std::cout << " - " << -k;

    std::cout << "\n";

    std::cout << "The turning point is: ("
              << -h << ", " << k << ")\n";

    return 0;
}
