#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define RUN 'run'

// forward declarations below
int nValue;
int offset;

//extracts the linear part of the sequence
std::string findLinear() {
  if (offset > 0) {
    return std::to_string(nValue) + "n+" + std::to_string(offset);
  } else if (offset < 0) {
    return std::to_string(nValue) + "n" + std::to_string(offset);
  } else if (offset == 0) {
    return std::to_string(nValue) + "n";
  } else {
    quick_exit(1);
  }
}
// the curly bracket above might appear as an error but thats just the compiler
// being cautious, the code is fine and will run

// main code starts here, this currently doesn't work for fibonacci sequences or
// geometric, only linear and quadratic
int main() {

  int n = 1;

  // recieve values from user
  std::cout << "Enter the list you would like to test (separated by spaces): ";

  std::vector<int> values;

  // the three lines below are brainrot to make it so terminal stops listening
  // to input after you press enter
  std::string line;
  std::getline(std::cin, line);
  std::istringstream iss(line);

  int userValues;
  while (iss >> userValues) {
    values.push_back(userValues);
  }

  // determine first & second differences
  std::vector<int> firstDifference;
  for (size_t i = 0; i + 1 < values.size(); ++i) {
    int difference1 = values[i + 1] - values[i];
    firstDifference.push_back(difference1);
  }

  std::vector<int> secondDifference;
  for (size_t i = 0; i + 1 < firstDifference.size(); ++i) {
    int difference2 = firstDifference[i + 1] - firstDifference[i];
    secondDifference.push_back(difference2);
  }

  // define n^2
  std::vector<int> nSquared;
  for (n = 1; n <= values.size(); n++) {
    int square = n * n;
    nSquared.push_back(square);
  }

  // crash protection
  if (secondDifference.empty()) {
    std::cout << "Not enough data for second difference, unsafe (must enter at "
                 "least 3 numbers) \n";
    return 0;
  }

  // extract linear part of quadratic sequence
  int multiplier = secondDifference[0] / 2;

  for (int &x : nSquared) {
    x = x * multiplier;
  }

  std::vector<int> linearise;
  for (size_t i = 0; i < values.size(); ++i) {
    linearise.push_back(values[i] - nSquared[i]);
  }

  //determine the nth term for the linear sequence, the function that uses
  //these variables have been forwardly declared at the start because c++ is
  //dumb and doesn't allow nested functions
  nValue = linearise[1] - linearise[0];
  offset = linearise[0] - nValue;
  // determine the final nth term of the sequence
  if (multiplier != 0) {
    std::cout << "The nth term of the sequence is: " << multiplier << "n^2"
              << "+" << findLinear() << "\n";
    std::cout << "This is a quadratic sequence";
  } else if (multiplier == 0) {
    std::cout << "The nth term of the sequence is: " << findLinear() << "\n";
    std::cout << "This is a non-quadratic sequence";
  }

// all of the stuff in the ifndef block below will not run, if you want it to
// run then change the ifndef to ifdef
#ifndef RUN
  std::cout << "The first difference is:\n";
  for (int x : firstDifference) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  std::cout << "The second difference is:\n";
  for (int x : secondDifference) {
    std::cout << x << " ";
  }
  std::cout << "\n";

  std::cout << "The linear part of this sequence is:\n";
  for (int x : linearise) {
    std::cout << x << " ";
  }
  std::cout << "\n";
#endif
  // ifndef block ends here
}
