#include <cstdio>
#include <vector>
#include <algorithm>

class Problem {

public :
  typedef std::vector<int> Coordinates;

  Problem();
  void solve();
  void printHouseCoordinate() const;

private :
  int houseCount;
  int routerCount;

  Coordinates houseCoordinates;

};

Problem::Problem() {
  scanf("%d %d", &this->houseCount, &this->routerCount);

  int coordinate;
  for (int i = 0; i < this->houseCount; ++i) {
    scanf("%d", &coordinate);
    houseCoordinates.push_back(coordinate);
  }

  sort(this->houseCoordinates.begin(), this->houseCoordinates.end());
}

void Problem::solve() {
}

void Problem::printHouseCoordinate() const {
  printf("[ ");
  for (Problem::Coordinates::const_iterator it = this->houseCoordinates.begin(); it != this->houseCoordinates.end(); ++it) {
    printf("%d, ", *it);
  }
  printf("]");
}

int main() {
  Problem problem = Problem();
  problem.printHouseCoordinate();
  problem.solve();

  return 0;
}
