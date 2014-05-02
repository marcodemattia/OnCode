#include <iostream>
#include <string>

/*
  This is really horrible. It works, but it can be streamlined.
*/

class Solution {
public:
  int atoi(const char *str)
  {
    int sign = 1;
    int result = 0;
    int finalResult = 0;
    int i = 0;
    const char * s;
    for( s = str; *s; s++, ++i ) {

      result = finalResult*10;

      // std::cout << "result = " << result << std::endl;
      // std::cout << "finalResult = " << finalResult << std::endl;

      if( finalResult > 214748364 && (*s == '0' || *s == '1' || *s == '2' || *s == '3'
				      || *s == '4' || *s == '5' || *s == '6' || *s == '7'
				      || *s == '8' || *s == '9')) {
	if(sign == 1) return 2147483647;
	return -2147483648;
      }

      if( result == 2147483640 && sign == 1 && ((*s == '8')||(*s == '9'))) return 2147483647;
      if( result == 2147483640 && sign == 1 && *s == '0') return 2147483640;
      if( result == 2147483640 && sign == -1 && *s == '9') return -2147483648;
      if( result == 2147483640 && sign == -1 && *s == '0') return -2147483640;


      if( i > 0 && (*s == '-' || *s == '+') && str[i-1] != ' ' ) {
	return finalResult;
      }
      else if( *s == '-' ) sign = -1;
      // else if( *s == '0' ) result += 0;
      else if( *s == '1' ) result += 1;
      else if( *s == '2' ) result += 2;
      else if( *s == '3' ) result += 3;
      else if( *s == '4' ) result += 4;
      else if( *s == '5' ) result += 5;
      else if( *s == '6' ) result += 6;
      else if( *s == '7' ) result += 7;
      else if( *s == '8' ) result += 8;
      else if( *s == '9' ) result += 9;
      else if( *s == ' ' ) {
	if( i > 0 && *s != str[i-1] ) {
	  return finalResult*sign;
	}
      }
      else if( *s != '+' && *s != '0' ) {
	// std::cout << "result = " << result << std::endl;
	return finalResult*sign;
      }
      // std::cout << "result = " << result << std::endl;
      finalResult = result;
    }
    return finalResult*sign;
  }
};

int main()
{
  
  Solution a;
  const char str[] = "     -11919730356x";
  printf("str = %s", str);
  std::cout << std::endl;
  std::cout << "result = " << a.atoi(str) << std::endl;
  return 0;
}
