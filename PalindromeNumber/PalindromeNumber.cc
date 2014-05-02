#include <iostream>

class Solution {
public:
  bool isPalindrome(int x) {
    std::cout << "x = " << x << std::endl;

    if( x < 0 ) return false;
    if( x == 0 ) return true;

    if( x/1000000000 > 0 ) {
      if( x/1000000000 == x%10 ) {
	if( x/100000000%10 == x%100/10 ) {
	  if( x/10000000%10 == x%1000/100 ) {
	    if( x/1000000%10 == x%10000/1000 ) {
	      if( x/100000%10 == x%100000/10000 ) {
		return true;
	      }
	    }
	  }
	}
      }
    }
    else if( x/100000000 > 0 ) {
      if( x/100000000 == x%10 ) {
	if( x/10000000%10 == x%100/10 ) {
	  if( x/1000000%10 == x%1000/100 ) {
	    if( x/100000%10 == x%10000/1000 ) {
	      return true;
	    }
	  }
	}
      }
    }
    else if( x/10000000 > 0 ) {
      if( x/10000000 == x%10 ) {
	if( x/1000000%10 == x%100/10 ) {
	  if( x/100000%10 == x%1000/100 ) {
	    if( x/10000%10 == x%10000/1000 ) {
	      return true;
	    }
	  }
	}
      }
    }
    else if( x/1000000 > 0 ) {
      if( x/1000000 == x%10 ) {
	if( x/100000%10 == x%100/10 ) {
	  if( x/10000%10 == x%1000/100 ) {
	    // std::cout << x/1000%10 << std::endl;
	    return true;
	  }
	}
      }
    }
    else if( x/100000 > 0 ) {
      if( x/100000 == x%10 ) {
	if( x/10000%10 == x%100/10 ) {
	  // std::cout << x/1000%10 << std::endl;
	  if( x/1000%10 == x%1000/100 ) {
	    return true;
	  }
	}
      }
    }
    else if( x/10000 > 0 ) {
      if( x/10000 == x%10 ) {
	// std::cout << x/1000%10 << std::endl;
	if( x/1000%10 == x%100/10 ) {
	  return true;
	}
      }
    }
    else if( x/1000 > 0 ) {
      if( x/1000 == x%10 ) {
	// std::cout << x/100%10 << std::endl;
	if( x/100%10 == x%100/10 ) {
	  return true;
	}
      }
    }
    else if( x/100 > 0 ) {
      if( x/100 == x%10 ) {
	// std::cout << x/10%10 << std::endl;
	return true;
      }
    }
    else if( x/10 > 0 ) {
      // std::cout << "div = " << x/10 << std::endl;
      // std::cout << "rest = " << x%10 << std::endl;
      if( x/10 == x%10 ) {
	return true;
      }
    }
    else if( x/10 == 0 ) return true;
    return false;
        
  }
};

int main()
{
  Solution a;
  bool result = false;

  result = a.isPalindrome(2143412);
  if( result ) std::cout << "is a palindrome" << std::endl;
  else std::cout << "is NOT a palindrome" << std::endl;
  
  result = a.isPalindrome(214412);
  if( result ) std::cout << "is a palindrome" << std::endl;
  else std::cout << "is NOT a palindrome" << std::endl;
  
  result = a.isPalindrome(21412);
  if( result ) std::cout << "is a palindrome" << std::endl;
  else std::cout << "is NOT a palindrome" << std::endl;
  
  result = a.isPalindrome(2112);
  if( result ) std::cout << "is a palindrome" << std::endl;
  else std::cout << "is NOT a palindrome" << std::endl;
  
  result = a.isPalindrome(212);
  if( result ) std::cout << "is a palindrome" << std::endl;
  else std::cout << "is NOT a palindrome" << std::endl;

  result = a.isPalindrome(10);
  if( result ) std::cout << "is a palindrome" << std::endl;
  else std::cout << "is NOT a palindrome" << std::endl;

  result = a.isPalindrome(2);
  if( result ) std::cout << "is a palindrome" << std::endl;
  else std::cout << "is NOT a palindrome" << std::endl;

  // std::cout << 2143483412/100000000%10 << std::endl;
  // std::cout << 2143483412%100/10 << std::endl;

  // std::cout << 2143483412/100000000%10 << std::endl;
  // std::cout << 2143483412%100/10 << std::endl;


  // std::cout << "rest = " << 10%10 << std::endl;

  return 0;
}
