/*
   如果使用 g++ pre-define-for-g++.cc -D DEBUG 编译，则会预定义个DEBUG变量
   否则则没有，可通过外部宏来开启或关闭程序的某项功能
*/
# include <iostream>

using std::endl;
using std::cout;

int main(){
#ifdef DEBUG
  cout << "you using -D DEBUG" << endl;
#else
  cout << "you don't using -D flags" << endl;
#endif
  return 0;
}
