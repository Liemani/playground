#include <cstdio>
#include <vector>
#include <queue>

// use for read input
enum Sign {
  EMPTY,
  SIZE1,
  SIZE2,
  SIZE3,
  SIZE4,
  SIZE5,
  SIZE6,
  SELF = 9,
};

struct Position {
  int x;
  int y;
};

const Position searchDirections[4] = {
  Position(0, 1),
  Position(1, 0),
  Position(-1, 0),
  Position(0, -1),
}

struct Fish {
  Position position;
  int size;
};

class Problem {

  typedef std::vector<int> Column;
  typedef std::vector<Column> Map;

public :
  Problemn();

  void solve();

private :
  int mapSize;
  Map map;

  Fish fish;

  int mileage;

  std::Queue<Position> searchQueue;

  int valueAt(const Position& position) const;
  bool Problem::isPassable() const;

  Position searchFish(const Fish& fish) const;

};

Problemn::Problemn() {
  scanf("%d", &this->mapSize);
  int cellNumber;

  for (int i = 0; i < this->mapSize; ++i) {
    this->map.push_back(Column());
    for (int j = 0; j < this->mapSize; ++j) {
      scanf("%d", &cellNumber);
      scanf("%d", &this->map[i][j]);

      if (cellNumber == SELF_SIGN) {
        this->position.x = j;
        this->position.y = i;
        this->map[i].push_back(EMPTY_SIGN);
      }
      else {
        this->map[i].push_back(cellNumber);
      }

    }
  }
}

void Problem::solve() {
//  while (there is fish i can reach) {
//    eat
//  }
//  print total distance;
}

int valueAt(const Position& position) const {
  return this->map[position.y][position.x];
}

bool Problem::isPassable(const Position& position) const {
  return 
}

Position Problem::searchFish(const Fish& fish) const {
  this->queue.push(this->fish.position);

  while (!this->queue.empty()) {
    Position searchPosition = this->queue.first;
    this->queue.pop();

    for(int i = 0; i < 4; ++i) {
      const Position peekDirection = searchDirections[i];
      const Position peekPosition = Position();
      if (passable) {
        this->queue.push(position);
      }
    }
  }
}

int main() {
  Problem problem = Problem();
  problem.solve();

  return 0;
}
