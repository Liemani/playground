#include <cassert>
#include <cstdlib>

int main(int argc, char* argv[]) {
  assert(argc == 2);
  abort();

  return 0;
}
