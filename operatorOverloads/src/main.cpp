#include <iostream>

class AddNum
{
  public:
    AddNum(int num) : num_(num) {};
    //() operator overload
    int operator()(int x) const
    {
        return num_ + x;
    }

  private:
    int num_;
};

int main()
{
    //functor
    auto add_num = AddNum(10);
    auto x = add_num(5);
    std::cout << "x: " << x << std::endl;
    
    //using lambda function to replace the above class
    auto add_num1 = [lambda_num = 10](int x) {return lambda_num + x;};
    auto lambda_x = add_num1(5);
    std::cout << "lamdba_x: " << lambda_x << std::endl;
}

/*  Insight of the above code
#include <iostream>

class AddNum
{

  public:
  inline AddNum(int num)
  : num_{num}
  {
  }

  inline int operator()(int x) const
  {
    return this->num_ + x;
  }


  private:
  int num_;
  public:
};



int main()
{
   // the variable type of add_num
  AddNum add_num = AddNum(10);
  int x = add_num.operator()(5);
  std::operator<<(std::cout, "x: ").operator<<(x).operator<<(std::endl);
  return 0;
}


*/