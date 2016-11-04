/*
  c++14中lambda表达式参数类型可以为auto类型
*/
# include <iostream>

using std::cout;
using std::endl;

int main(){

  auto lambdaAdd = [](auto a,auto b){ return a+b ;};
  cout << lambdaAdd(1,3) << endl;
  return 0;
}
