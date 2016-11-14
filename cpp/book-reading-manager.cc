// compile with c++11
// 图书管理程序
# include <iostream>
# include <vector>
# include <fstream>
# include <iterator>
# include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;
using std::advance;

#define DEFAULT_CONFIG "/usr/local/etc/book-manager.conf"

struct status{
  //读完列表
  vector<string> readedlist;
  //当前行为
  int currentaction;
  status(string file=DEFAULT_CONFIG): filename(file){
    ifstream in(filename);
    string name;
    while(in.is_open()  && !in.eof()){
      in >> name;
      readedlist.push_back(name);
    }
    in.close();
  }
  ~status(){
    //将配置写入文件
    ofstream out;
    out.open(filename,std::ios::out);
    for(auto name : readedlist){
      out << name << endl;
    }
    out.close();
  }
private:
  string filename;
}CONFIG;

void initDraw(){}
void draw(){
  for(int i=0;i<CONFIG.readedlist.size();++i){
    cout << i+1 << ": " << CONFIG.readedlist[i] << endl;
  }
  cout << "action:"  <<endl;
  cout << "\ta :add book" <<endl;
  cout << "\tl :list books"<<endl;
  cout << "\td :delete book"<<endl;
}
void addBook(){
  string name;
  cout << "please type bookname:";
  cin >> name;
  CONFIG.readedlist.push_back(name);
}
void deleteBook(){
  int index(0);
  cout << "input your book index: ";
  cin >> index;
  if(index > 0 && (index < CONFIG.readedlist.size()+1)){
    auto first = CONFIG.readedlist.begin();
    advance(first,index-1);
    CONFIG.readedlist.erase(first);
    cout << "remove done!" << endl;;
  }else{
    cout << "index error,over!" << endl;
  }
}
int main(){
  string action="l";
  initDraw();
  do{
    switch(action.c_str()[0]){
    case 'a':
      addBook();
      break;
    case 'd':
      deleteBook();
      break;
    default:
      draw();
      break;
    }
    action = "";
    cin >> action;
  }while(action.compare("quit"));
  return 0;
}
