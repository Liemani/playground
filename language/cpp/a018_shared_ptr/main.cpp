#include <iostream>

// interface
class IAmSharedData {

public :
  explicit IAmSharedData(int value) : data_(std::make_shared<Data>(value)) {}
  void describe();

private :
  class Data;
  std::shared_ptr<Data> data_;

  explicit IAmSharedData(std::shared_ptr<Data> data) : data_(std::move(data)) {}

};

class IAmSharedData::Data {

public:
  int value;

  Data(int value);

  void describe();

};

// implementation
void IAmSharedData::describe() {
  std::cout << "data : ";
  this->data_.get()->describe();
  std::cout << std::endl;
}

IAmSharedData::Data::Data(int value)
: value(value)
{ }

void IAmSharedData::Data::describe() {
  std::cout << this->value;
}

//namespace {
//class DerivedData : public IAmSharedData::Data {
//public :
//  int value;
//
//  DerivedData(int value);
//
//  virtual void sampleInspectorMethod() const;
//  virtual void sampleMutatorMethod();
//  virtual shared_ptr<Data> clone() const;
//}
//
//DerivedData::DerivedData(int value)
//: value(value)
//{ }
//
//}

int main(int argc, char* argv[]) {
  int value = 42;
  IAmSharedData iAmSharedData = IAmSharedData(42);
  iAmSharedData.describe();

  return 0;
}
