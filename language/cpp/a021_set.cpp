#include <iostream>
#include <set>

int main(void) {
  std::set<int> set = std::set<int>();

  set.insert(6);
  set.insert(5);
  set.insert(4);
  set.insert(3);
  set.insert(2);
  set.insert(1);

//  std::cout << set.count(1) << std::endl;
//  std::cout << *set.find(1) << std::endl;

  for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it) {
    std::cout << *it << std::endl;
  }

  return 0;
}
