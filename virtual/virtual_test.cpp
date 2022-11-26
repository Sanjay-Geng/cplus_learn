#include <iostream>

class NoneVirtual
{
 public:
  void setData(int a, int b)
  {
    m_int_1 = a;
    m_int_2 = b;
  }
  void showData()
  {
    std::cout << m_int_1 << " " << m_int_1 << std::endl;
  }

 private:
  int m_int_1 = 4;
  int m_int_2 = 5;
};

class HasVirtual
{
 public:
  virtual void setData(int a, int b)
  {
    m_int_1 = a;
    m_int_2 = b;
  }
  virtual void showData()
  {
    std::cout << m_int_1 << " " << m_int_1 << std::endl;
  }

 private:
  int m_int_1 = 4;
  int m_int_2 = 5;
};

int main()
{
  NoneVirtual A;
  HasVirtual B;

  std::cout << std::endl << std::endl;
  std::cout << "NoneVirtual class A size: " << sizeof(A) << std::endl;
  std::cout << "HasVirtual  class B size: " << sizeof(B) << std::endl;

  std::cout << "setData addr: " << (void*)(&HasVirtual::setData) << std::endl;
  std::cout << "showData addr: " << (void*)(&HasVirtual::showData) << std::endl;
  return 0;
}
