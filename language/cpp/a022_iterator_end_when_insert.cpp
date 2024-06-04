// summary : vector.end() is changed after push_back() or pop_back()
//  after push_back(), previous end() has the value
//  set.end() is not changed after insert() or erase()
//  set.begin() after erase(), index for insert becomes `begin` index

#include <iostream>

#define PLAYGROUND001

#ifdef PLAYGROUND001
#endif
#include <set>

inline bool checkBeginEqual(std::set<int>::iterator begin, const std::set<int>& set) {
  return begin == set.begin();
}

inline bool checkEndEqual(std::set<int>::iterator end, const std::set<int>& set) {
  return end == set.end();
}

bool checkSetContainsIT(const std::set<int>& set, std::set<int>::iterator end) {
  for (std::set<int>::const_iterator it = set.begin(); it != set.end(); ++it) {
    if (end == it) {
      std::cout << *it;
      return true;
    }
  }
  return false;
}

int main(void) {
  std::set<int> set = std::set<int>();
  std::set<int>::iterator end;
  std::set<int>::iterator begin;
  std::set<int>::iterator second;
  bool checkResult;

  begin = set.begin();
  set.insert(6);
  checkResult = checkEndEqual(begin, set);
  std::cout << checkResult << std::endl;

  begin = set.begin();
  second = set.begin();
  ++second;
  set.erase(6);
  checkResult = checkEndEqual(begin, set);
  std::cout << checkResult << std::endl;
  checkResult = checkEndEqual(second, set);
  std::cout << checkResult << std::endl;

  set.insert(5);
  set.insert(4);
  set.insert(3);
  set.insert(2);

  end = set.end();
  set.insert(1);
  checkResult = checkEndEqual(end, set);
  std::cout << checkResult << std::endl;

  checkResult = checkSetContainsIT(set, end);
  std::cout << checkResult << std::endl;

  end = set.end();
  set.erase(1);
  checkResult = checkEndEqual(end, set);
  std::cout << checkResult << std::endl;

  end = set.end();
  checkResult = checkEndEqual(end, set);
  std::cout << checkResult << std::endl;

  return 0;
}

#ifdef PLAYGROUND000
#include <vector>

inline bool checkEndEqual(std::vector<int>::iterator end, const std::vector<int>& vector) {
  return end == vector.end();
}

bool checkVectorContainsIT(const std::vector<int>& vector, std::vector<int>::iterator end) {
  for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it) {
    if (end == it) {
      std::cout << *it;
      return true;
    }
  }
  return false;
}

int main(void) {
  std::vector<int> vector = std::vector<int>();
  std::vector<int>::iterator end;

  vector.push_back(6);
  vector.push_back(5);
  vector.push_back(4);
  vector.push_back(3);
  vector.push_back(2);

  end = vector.end();
  vector.push_back(1);
  bool checkResult = checkEndEqual(end, vector);
  std::cout << checkResult << std::endl;

  checkResult = checkVectorContainsIT(vector, end);
  std::cout << checkResult << std::endl;

  end = vector.end();
  vector.pop_back();
  checkResult = checkEndEqual(end, vector);
  std::cout << checkResult << std::endl;

  end = vector.end();
  checkResult = checkEndEqual(end, vector);
  std::cout << checkResult << std::endl;

  return 0;
}
#endif
