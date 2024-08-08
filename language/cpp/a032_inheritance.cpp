#define a004



#ifdef a004
#include <cstdio>

class Base {
public :
  virtual void print() const { printf("base\n"); }
};

class Derived : public Base {
public :
  void print() const { printf("derived\n"); }
};

class Descendant : public Derived {
public :
  void print() const { printf("descendant\n"); }
};



void test001() {
  Base* base = new Base();
  base->print();
  delete base;
}

void test002() {
  Base* base = new Derived();
  base->print();
  delete base;
}

void test003() {
  Base* base = new Descendant();
  base->print();
  delete base;
}

void test004() {
  Derived* derived = new Descendant();
  derived->print();
  delete derived;
}

int main() {
  test001();
  test002();
  test003();
  test004();

  return 0;
}
#endif



#ifdef a003
#include <cstdio>

class Base {
public :
  void print() const { printf("base\n"); }
};

class Derived : public Base {
public :
  void print() const { printf("derived\n"); }
};

class Descendant : public Derived {
public :
  void print() const { printf("descendant\n"); }
};



void test001() {
  Base* base = new Base();
  base->print();
  delete base;
}

void test002() {
  Base* base = new Derived();
  base->print();
  delete base;
}

void test003() {
  Base* base = new Descendant();
  base->print();
  delete base;
}

void test004() {
  Derived* derived = new Descendant();
  derived->print();
  delete derived;
}

int main() {
  test001();
  test002();
  test003();
  test004();

  return 0;
}
#endif
