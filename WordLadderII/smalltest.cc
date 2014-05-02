#include <iostream>
#include <string>

int main()
{

  std::string a("this");
  // for( int i=0; i<a.size(); ++i ) {
    // std::cout << a[i] << std::endl;
  // }
  // for( std::string::const_iterator it=a.begin(); it!=a.end(); ++it ) {
  for( int i=0; i<a.size(); ++i ) {
    std::string c(a);
    for( char l = 'a'; l <= 'z'; ++l ) {
      c[i] = l;
      std::cout << c << std::endl;
    }
    // std::cout << *it << std::endl;
  }

}
