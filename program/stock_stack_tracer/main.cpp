//  GOAL
//  read csv file;
//  simulate stack;
//  print result to a file;

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>

#include <vector>
#include <stack>

#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::stringstream;

using std::string;

using std::vector;
using std::stack;

using std::greater;
using std::less;



typedef float DataPoint;
typedef vector<DataPoint> Record;
typedef vector<Record> Table;

float convertStringToFloat(const string& str)
{
  stringstream ss(str);
  float val;
  ss >> val;
  return val;
}

string convertFloatToString(float val)
{
  stringstream ss;
  ss << val;
  return ss.str();
}

Table readCSV(const string& filename)
{
  ifstream file(filename);
  Table data;
  string line;

  if (!file.is_open()) {
    cerr << "Error: Could not open file " << filename << endl;
    return data;
  }

  while (getline(file, line)) {
    stringstream lineStream(line);
    vector<float> row;
    string cell;

    while (getline(lineStream, cell, ',')) {
      row.push_back(convertStringToFloat(cell));
    }

    if (row.size() != 3) {
      cerr << "Warning: Row in file has unexpected number of columns" << endl;
      continue; // Skip row with wrong number of columns
    }

    data.push_back(row);
  }

  file.close();
  return data;
}

void writeToCSV(const string& filename, const vector<vector<float> >& data)
{
  ofstream file(filename);

  if (!file.is_open()) {
    cerr << "Error: Could not open file " << filename << endl;
    return;
  }

  for (size_t i = 0; i < data.size(); ++i) {
    for (size_t j = 0; j < data[i].size(); ++j) {
      file << convertFloatToString(data[i][j]);
      if (j < data[i].size() - 1) {
        file << ",";
      }
    }
    file << endl;
  }

  file.close();
  cout << "Data written to CSV file: " << filename << endl;
}

int calculateStackSize(const Table& table)
{
  int stackSize = 0;
  int maxStackSize = 0;

  for (Table::const_iterator it = table.begin(); it != table.end(); ++it)
  {
    Record record = *it;
//    cout << record[0] << ", " << record[1] << ", " << record[2] << endl;
    if (record[0] != 0.0)
    {
      stackSize += record[2];
      if (maxStackSize < stackSize)
      {
        maxStackSize = stackSize;
      }
    }
    else
    {
      stackSize -= record[2];
    }
  }

  return maxStackSize;
}

template <typename T>
class DoubleVector {
public:
  // Pushes an element onto the first stack
  void pushFirst(const T& value) {
    vector1_.push_back(value);
  }

  // Pushes an element onto the second stack
  void pushSecond(const T& value) {
    vector2_.push_back(value);
  }

  // Pops an element from the first stack and returns it
  T popFirst() {
    if (vector1_.empty()) {
      throw std::out_of_range("First stack is empty");
    }
    T value = vector1_.back();
    vector1_.pop_back();
    return value;
  }

  // Pops an element from the second stack and returns it
  T popSecond() {
    if (vector2_.empty()) {
      throw std::out_of_range("Second stack is empty");
    }
    T value = vector2_.back();
    vector2_.pop_back();
    return value;
  }

  void sortFirst() {
    sort(this->vector1_.begin(), this->vector1_.end(), greater<float>());
  }

  void sortSecond() {
    sort(this->vector2_.begin(), this->vector2_.end(), less<float>());
  }

  // Checks if the first stack is empty
  bool isEmptyFirst() const {
    return vector1_.empty();
  }

  // Checks if the second stack is empty
  bool isEmptySecond() const {
    return vector2_.empty();
  }

  // Returns the size of the first stack
  size_t sizeFirst() const {
    return vector1_.size();
  }

  // Returns the size of the second stack
  size_t sizeSecond() const {
    return vector2_.size();
  }

  Table toTable()
  {
    Table table;

    int loopCount = std::max(this->sizeFirst(), this->sizeSecond());
    for (int index = 0; index < loopCount; ++index)
    {
      Record row;

      if (this->sizeFirst() <= index)
      {
        row.push_back(0.0);
      }
      else
      {
        row.push_back(this->vector1_[index]);
      }
      if (this->sizeSecond() <= index)
      {
        row.push_back(0.0);
      }
      else
      {
        row.push_back(this->vector2_[index]);
      }

      table.push_back(row);
    }

    return table;
  }

private:
  vector<T> vector1_;  // First stack (vector)
  vector<T> vector2_;  // Second stack (vector)
};

DoubleVector<DataPoint> simulate(const Table& inputTable)
{
  DoubleVector<DataPoint> doubleVector = DoubleVector<DataPoint>();

  for (Table::const_iterator it = inputTable.begin(); it != inputTable.end(); ++it)
  {
    const Record record = *it;

    if (record[0] != 0.0)
    {
      for (int index = 0; index < record[2]; ++index)
      {
        doubleVector.pushFirst(record[0]);
        if (!doubleVector.isEmptySecond())
        {
          doubleVector.popSecond();
        }
        doubleVector.sortFirst();
      }
    }
    else
    {
      for (int index = 0; index < record[2]; ++index)
      {
        doubleVector.pushSecond(record[1]);
        doubleVector.popFirst();
        doubleVector.sortSecond();
      }
    }
  }

  return doubleVector;
}

int main(int argc, char* argv[])
{
  vector<vector<float> > table = readCSV("source.csv");

  if (table.empty()) {
    cerr << "Error: No data found in the CSV file" << endl;
    return 1;
  }

//  for (size_t i = 0; i < table.size(); ++i) {
//    for (size_t j = 0; j < table[i].size(); ++j) {
//      cout << table[i][j] << " ";
//    }
//    cout << endl;
//  }

//  int stackSize = calculateStackSize(table);
  DoubleVector<DataPoint> doubleVector = simulate(table);
  Table resultTable = doubleVector.toTable();

  const string filename = "out.csv";
  writeToCSV(filename, resultTable);

  return 0;
}
