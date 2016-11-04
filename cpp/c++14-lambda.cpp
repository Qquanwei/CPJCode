# include <iostream>

using std::cout;
using std::endl;

int main(){

  auto lambdaAdd = [](auto a,auto b){ return a+b ;};
  cout << lambdaAdd(1,3) << endl;
  return 0;
}
