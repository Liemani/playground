#include <cstdio>
#include <list>
#include <utility>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
#include <climits>

typedef std::pair<int, int> Arrow;
typedef std::list< ::Arrow> ArrowList;

// struct Graph
struct Graph {
  ::ArrowList* arrowList;
  int nodeCount;
  unsigned int* distance;
  std::vector<bool> isVisited;
  std::list<int> searchList;
  int entry;

  Graph(int nodeCount, int arrowCount, int entry);
  ~Graph();

  int popSmallestDistanceNumber();
  void simulate();
  void printShortestDistance() const ;
};

Graph::Graph(int nodeCount, int arrowCount, int entry)
: arrowList(new ::ArrowList[nodeCount]),
  nodeCount(nodeCount),
  distance(new unsigned int[nodeCount]),
  isVisited(std::vector<bool>(nodeCount)),
  searchList(std::list<int>()),
  entry(entry)
{
  for (int i = 0; i < arrowCount; ++i) {
    int source;
    int destination;
    int weight;

    scanf("%d %d %d", &source, &destination, &weight);

    --source;
    --destination;

    ::Arrow arrow = ::Arrow(destination, weight);
    this->arrowList[source].push_front(arrow);
  }

  memset(this->distance, -1, sizeof(int) * nodeCount);
  this->distance[entry] = 0;

  this->searchList.push_back(entry);
}

Graph::~Graph() {
  delete [] this->arrowList;
  delete [] this->distance;
}

int Graph::popSmallestDistanceNumber() {
  unsigned int smallestDistance = UINT_MAX;
  std::list<int>::iterator smallestNumberIterator;

  for (std::list<int>::iterator it = this->searchList.begin(); it != this->searchList.end(); ++it) {
    const unsigned int distance = this->distance[*it];

    if (distance < smallestDistance) {
      smallestDistance = distance;
      smallestNumberIterator = it;
    }
  }

  const int smallestNumber = *smallestNumberIterator;
  this->searchList.erase(smallestNumberIterator);

  return smallestNumber;
}

void Graph::simulate() {
  while (!this->searchList.empty()) {
    int nodeNumber = this->popSmallestDistanceNumber();

    ::ArrowList& arrowList = this->arrowList[nodeNumber];

    for (::ArrowList::iterator it = arrowList.begin(); it != arrowList.end(); ++it) {
      ::Arrow arrow = *it;

      const int destination = arrow.first;
      const int weight = arrow.second;

      if (this->isVisited[destination]) {
        continue;
      }
      else {
        const unsigned int newDestinationDistance = this->distance[nodeNumber] + weight;
        const unsigned int destinationDistance = this->distance[destination];
        this->distance[destination] = std::min(destinationDistance, newDestinationDistance);
        this->searchList.push_back(destination);

      }
    }

    this->isVisited[nodeNumber] = true;
  }
}

void Graph::printShortestDistance() const {
  unsigned int* const distanceEnd = this->distance + this->nodeCount;
  for (unsigned int* it = this->distance; it < distanceEnd; ++it) {
    if (*it == UINT_MAX) {
      printf("INF\n");
    }
    else {
      printf("%u\n", *it);
    }
  }
}

// solution
inline void solution(::Graph& graph) {
  graph.simulate();
  graph.printShortestDistance();
}

// main
int main(void) {
  int nodeCount;
  int arrowCount;
  int entry;

  scanf("%d %d\n%d", &nodeCount, &arrowCount, &entry);
  --entry;

  ::Graph graph = ::Graph(nodeCount, arrowCount, entry);
  ::solution(graph);

  return 0;
}
