#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using std::string;

string getName()
{  
  std::cout << "What is your name?\n";
  string input{};
  std::getline(std::cin >> std::ws, input);
  return input;
}

double getAge()
{
  std::cout << "How old are you?\n";
  double ageInput{};
  std::cin >> ageInput;
  return ageInput;
}

int main()
{
  string a{getName()};
  double b{getAge()};
  int letter_count = std::count_if(a.begin(), a.end(), isalpha);

  auto it = std::find(a.begin(), a.end(), ' ');
    // Remove all the other whitespace characters
  a.erase(std::remove_if(a.begin(), it, isspace), it);
  
  a.erase(std::remove_if(it+1, a.end(), isspace), a.end());

  
  std::cout << "\nHello, " << a << "!" << " You are "   << b << " years old!\n";

  std::cout << "And your name has " << letter_count << " characters!";

  return 0;
}
