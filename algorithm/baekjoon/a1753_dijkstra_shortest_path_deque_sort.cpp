#include <cstdio>
#include <list>
#include <utility>
#include <vector>
#include <cstring>
#include <deque>
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
  std::deque<int> searchDeque;
  int entry;

  Graph(int nodeCount, int arrowCount, int entry);
  ~Graph();

  void simulate();
  void printShortestDistance() const ;

  struct GraphLess {
    ::Graph& graph;

    GraphLess(::Graph& graph);

    bool operator()(int lhs, int rhs) const;
  } graphLess;
};

Graph::Graph(int nodeCount, int arrowCount, int entry)
: arrowList(new ::ArrowList[nodeCount]),
  nodeCount(nodeCount),
  distance(new unsigned int[nodeCount]),
  isVisited(std::vector<bool>(nodeCount)),
  searchDeque(std::deque<int>()),
  entry(entry),
  graphLess(GraphLess(*this))
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

  this->searchDeque.push_back(entry);
}

Graph::~Graph() {
  delete [] this->arrowList;
  delete [] this->distance;
}

void Graph::simulate() {
  while (!this->searchDeque.empty()) {
    std::sort(this->searchDeque.begin(), this->searchDeque.end(), this->graphLess);

    int nodeNumber = this->searchDeque.front();
    this->searchDeque.pop_front();

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
        this->searchDeque.push_back(destination);

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

Graph::GraphLess::GraphLess(::Graph& graph)
: graph(graph)
{
}

bool Graph::GraphLess::operator()(int lhs, int rhs) const {
  const unsigned int lhsDistance = this->graph.distance[lhs];
  const unsigned int rhsDistance = this->graph.distance[rhs];

  return lhsDistance < rhsDistance;
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
