#include <iostream>
using namespace std ;

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define LOG(msg) \
  cout << __FILE__ ":"  STR(__LINE__) " "  msg <<endl ;
int main()
{
 LOG("Test Message");
 LOG("One more test message");
 return 0;
}
