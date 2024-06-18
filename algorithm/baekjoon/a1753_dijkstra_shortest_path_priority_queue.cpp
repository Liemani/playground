#include <cstdio>
#include <list>
#include <utility>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <climits>

/// - Type argument
///   first : destination
///   second : weight
typedef std::pair<int, int> Arrow;
typedef std::list< ::Arrow> ArrowList;

/// - Type argument
///   first : distance
///   second : node number
typedef std::pair<int, int> PriorityQueueElement;

struct Greater {
  bool operator()(const PriorityQueueElement& lhs, const PriorityQueueElement& rhs) const {
    return lhs.first > rhs.first;
  }
};

typedef std::priority_queue<PriorityQueueElement, std::vector<PriorityQueueElement>, ::Greater> PriorityQueue;

// struct Graph
struct Graph {
  ::ArrowList* arrowList;
  int nodeCount;
  unsigned int* distance;
  std::vector<bool> isVisited;
  PriorityQueue searchQueue;
  int entry;

  Graph(int nodeCount, int arrowCount, int entry);
  ~Graph();

  int popSmallestDistanceNumber();
  void simulate();
  void printShortestDistance() const ;
};

inline Graph::Graph(int nodeCount, int arrowCount, int entry)
: arrowList(new ::ArrowList[nodeCount]),
  nodeCount(nodeCount),
  distance(new unsigned int[nodeCount]),
  isVisited(std::vector<bool>(nodeCount)),
  searchQueue(PriorityQueue()),
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

  ::PriorityQueueElement queueElement = ::PriorityQueueElement(0, entry);
  this->searchQueue.push(queueElement);
}

inline Graph::~Graph() {
  delete [] this->arrowList;
  delete [] this->distance;
}

inline void Graph::simulate() {
  while (!this->searchQueue.empty()) {
    const PriorityQueueElement queueElement = this->searchQueue.top();
    const int nodeNumber = queueElement.second;
    this->searchQueue.pop();

    if (this->isVisited[nodeNumber]) {
      continue;
    }

    ::ArrowList& arrowList = this->arrowList[nodeNumber];

    for (::ArrowList::iterator it = arrowList.begin(); it != arrowList.end(); ++it) {
      ::Arrow arrow = *it;

      const int destination = arrow.first;
      const int weight = arrow.second;

      if (this->isVisited[destination]) {
        continue;
      }
      else {
        const unsigned int destinationDistance = this->distance[destination];
        const unsigned int newDestinationDistance = this->distance[nodeNumber] + weight;

        if (newDestinationDistance < destinationDistance) {
          this->distance[destination] = newDestinationDistance;
          ::PriorityQueueElement queueElement = ::PriorityQueueElement(newDestinationDistance, destination);
          this->searchQueue.push(queueElement);
        }
      }
    }

    this->isVisited[nodeNumber] = true;
  }
}

inline void Graph::printShortestDistance() const {
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
