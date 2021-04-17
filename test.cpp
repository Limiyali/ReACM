#if 0
#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main() {
	string str("Email a@bc.com abc");
	regex e("([[:w:]]+)@([[:w:]]+\\.com)");
	smatch m; 
	bool found = regex_search(str, m, e);
	cout << "m.size=" 
    << m.size() << endl;

  /* 迭代 match_results, 输出
  m[0]=a@bc.com (整个匹配)
  m[1]=a (第1个group)
  m[2]=bc.com (第2个group)
  */
  for (int n=0; n<m.size(); n++){
    cout << "m[" << n << "]=" 
      << m[n].str() << endl;
  //等价写法 m.str(n), *(m.begin()+n) 
  }
  
  // m.prefix=Email
  cout << "m.prefix=" 
    << m.prefix().str() << endl;
  
  // m.suffix= is mine
  cout << "m.suffix=" 
    << m.suffix().str() << endl;
}

#endif // 1
