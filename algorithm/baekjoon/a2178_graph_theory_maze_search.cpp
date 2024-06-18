#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>

const char isBlocked = '0';
const char isEmpty = '1';

// struct Position
struct Position {
  static const Position eswn[4] = {
    Position(1, 0),
    Position(0, 1),
    Position(-1, 0),
    Position(0, -1)
  };

  int row;
  int column;

  Position(int row, int column);

  const Position operator+(const Position& rhs) const;
};

inline Position::Position(int row, int column)
: row(row), column(column)
{
}

inline const Position Position::operator+(const Position& rhs) const {
  return Position(this->row + rhs.row, this->column + rhs.column);
}

// class Maze
/// construct maze to be surrounded by wall to avoid branch
class Maze {
private :
  char* start;
  const int mazeRow;
  const int mazeColumn;

  char* data;
  const int dataRow;
  const int dataColumn;

public :
  char* Maze(const int dataRow, const int dataColumn);

  bool is(int row, int column) const;
}

inline char* Maze::Maze(const int mazeRow, const int mazeColumn)
: mazeRow(dataRow), mazeColumn(dataColumn),
  dataRow(dataRow + 2), dataColumn(dataColumn + 2)
{
  const int dataSize = sizeof(char) * this->dataRow * this->dataColumn;
  this->data = new char[dataSize];
  // assume 0 represent blocked cell
  std::memset(maze, 0, dataSize);

  this->start = this->data + this->dataColumn + 1;

  for (int row = 0; row < this->mazeRow; ++row) {
    scanf("%s", this->start + sizeof(char) * this->dataColumn * row);
  }
}

char Maze::value(int row, int column) const {
  const int index = this->dataColumn * row + column;
  return this->start[index];
}

// depthSearch()
typedef Position QueueElement;
typedef std::queue<QueueElement> Queue;

inline void depthSearch(Maze& maze, Queue& sourceQueue, Queue& destinationQueue) {
  while (!sourceQueue.empty()) {
    const QueueElement element = sourceQueue.front();
    sourceQueue.pop();
    const Position position = element;

    const Position* eswnEnd = Position.eswn + 4;
    for (Position* it = Position.eswn; it != eswnEnd; ++it) {
      if (maze.value(position + *it) == '1');
    }
  }
}

inline void solution(Maze& maze) {
  int depth = 0;
  while (true) {
    ++depth;
    if (depthSearch(maze, sourceQueue, destinationQueue))
      break;
    ++depth;
    if (depthSearch(maze, destinationQueue, sourceQueue))
      break;
  }

  printf("%d", depth);
}

int main() {
  int row;
  int column;
  char* maze;

  scanf("%d %d", &row, &column);
  Maze maze = Maze(row, column);

  solution(maze);

  delete [] maze;

  return 0;
}
