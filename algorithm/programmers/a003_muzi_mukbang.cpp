#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;

    vector<int> sorted_food_times = food_times;
    sort(sorted_food_times.begin(), sorted_food_times.end());

    const size_t food_times_size = food_times.size();
    int sorted_food_index = 0;
    long long finish_a_food_time_count = (food_times_size - sorted_food_index) * sorted_food_times[sorted_food_index];

    int previous_food_times = 0;
    int current_food_times = 0;
    while (k >= finish_a_food_time_count) {
      k -= finish_a_food_time_count;
      previous_food_times = current_food_times;
      current_food_times = sorted_food_times[sorted_food_index];
      ++sorted_food_index;

      if (sorted_food_index == food_times_size) {
        return -1;
      }

      finish_a_food_time_count = (food_times_size - sorted_food_index) * (current_food_times - previous_food_times);
    }

    k %= (food_times_size - sorted_food_index);

    while (true) {
      if (k == 0) {
        break;
      }

      ++answer;

      if (food_times[answer] > current_food_times) {
        --k;
      }
    }

    while (true) {
      if (food_times[answer] <= current_food_times) {
        ++answer;
      }
      else {
        break;
      }
    }

    return answer + 1;
}

#include <iostream>

void testCase003() {
  vector<int> food_times;

  food_times.push_back(3);
  food_times.push_back(1);
  food_times.push_back(2);

  int returnValue = solution(food_times, 5);  // 1

  std::cout << "answer : " << returnValue << std::endl;
}

void testCase004() {
  vector<int> food_times;

  food_times.push_back(4);
  food_times.push_back(2);
  food_times.push_back(3);
  food_times.push_back(6);
  food_times.push_back(7);
  food_times.push_back(1);
  food_times.push_back(5);
  food_times.push_back(8);

  int returnValue = solution(food_times, 16); // 3

  std::cout << "answer : " << returnValue << std::endl;
}

void testCase005() {
  vector<int> food_times;

  food_times.push_back(5);
  food_times.push_back(0);
  food_times.push_back(3);
  food_times.push_back(3);
  food_times.push_back(1);

  int returnValue = solution(food_times, 9);  // 4

  std::cout << "answer : " << returnValue << std::endl;
}


int main() {
  testCase005();

  return 0;
}
