/*
  断言一定会输出成功，会给出提示
*/

# include <iostream>
# include <cassert>

using std::cout;
using std::endl;

int main(){
  assert(cout << " output done!" << endl );
  return 0;
}
