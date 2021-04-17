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

  /* ���� match_results, ���
  m[0]=a@bc.com (����ƥ��)
  m[1]=a (��1��group)
  m[2]=bc.com (��2��group)
  */
  for (int n=0; n<m.size(); n++){
    cout << "m[" << n << "]=" 
      << m[n].str() << endl;
  //�ȼ�д�� m.str(n), *(m.begin()+n) 
  }
  
  // m.prefix=Email
  cout << "m.prefix=" 
    << m.prefix().str() << endl;
  
  // m.suffix= is mine
  cout << "m.suffix=" 
    << m.suffix().str() << endl;
}

#endif // 1
