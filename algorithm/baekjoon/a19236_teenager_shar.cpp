#include <cstdio>
#include <utility>

typedef std::pair<int, int> Point;

struct Fish {
  int number;
  Point* direction;
};

Point directions[9] = {
  Point(0, 0),
  Point(-1, 0),
  Point(-1, -1),
  Point(0, -1),
  Point(1, -1),
  Point(1, 0),
  Point(1, 1),
  Point(0, 1),
  Point(-1, 1),
};

class Problem {

public :
  Problem();

  void solve();

private :
  Fish map[4][4];

  void readInput();

};

void Problem::readInput() {
  int number;
  int direction;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      scanf("%d, %d", &number, &direction);
      this->map[i][j].number = number;
      this->map[i][j].direction = &directions[direction];
    }
  }
}

Problem::Problem() {
}

void Problem::solve() {

}

int main() {
  Problem problem = Problem();
  problem.solve();

  return 0;
}
