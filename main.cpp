// Su nombre aqui

#include<iostream>
#include<string>
#include<stack>
using namespace std;

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
        printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
        printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
        passedAssertions++; \
    }
#define assertionReport() { \
     printf("==========================================\n"); \
     printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
     printf("\n"); \
    }
//*******************************************************

bool parentesisBal(const string &st) {
  stack<char> S;
  for (auto c: st) {
    if (c == '(') S.push(c);
    else if (S.empty()) return false;
    else S.pop();
  }
  return S.empty();
}

int main() {
  expect(parentesisBal("())") == false);
  expect(parentesisBal("((()))(())") == true);
  expect(parentesisBal("((()(())") == false);
  assertionReport();
}
