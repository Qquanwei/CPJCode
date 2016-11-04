/*
  该文件用于介绍c++11的foreach语法，用于对普通数组，以及支持迭代器的类型使用
*/
# include <iostream>
# include <vector>
# include <map>
# include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::map;



int main(){
  int array[]={1,3,2,6,1,3};

  cout << "array foreach" << endl;
  for(auto i : array){
    cout << i << " ";
  }
  cout << endl;

  cout << "vector foreach" << endl;
  vector<float> varray={1,2,5,2,3,5};
  for(auto i : varray){
    cout << i << " ";
  }
  cout << endl;

  cout << "map foreach" << endl;
  map<string,int> mmap={
    {"one",1},
    {"two",2},
    {"three",3}
  };
  for(auto i : mmap){
    cout << i.first << " " << i.second << " " << endl;
  }
  return 0;
}
