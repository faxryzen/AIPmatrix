#include <iostream>
#include "matrix.h"

int main()
{
  size_t M = 0, N = 0;
  std::cout << "Write two numbers - the size of the array\n";
  std::cin >> M >> N;

  if (!std::cin.good())
  {
    std::cerr << "failure to read size\n";
    return 1;
  }

  Matrix first_table(M, N);
  first_table.print(std::cout);
  std::cout << "Hey, let's add numbers there\n";
  if (!first_table.input(std::cin))
  {
    std::cerr << "failure to read numbers\n";
    return 1;
  };
  std::cout << "Cool, let's try new size\n";
  std::cin >> M >> N;

  if (!std::cin.good())
  {
    std::cerr << "failure to read size\n";
    return 1;
  }

  first_table.size(M, N);
  first_table.print(std::cout);
  std::cout << "Let's copy this matrix\n";

  Matrix second_table { first_table };

  second_table.print(std::cout);
  std::cout << "Here new width and height\n";
  std::cout << second_table.width() << " " << second_table.height() << '\n';
}
