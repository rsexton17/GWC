//Goldbach's weak conjecture
#include <iostream>
#include <cstdio>
using namespace std;

bool IsPrime(int n) {
  if (n == 0) return false;
  if (n == 1) return false;
  if (n == 2) return true;
  for (int i = 2; i < (n/2)+1; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int NextPrime(int n) {
  while (true) {
    n++;
    if (IsPrime(n)) return n;
  }
}

bool GWC(int ans, int num1, int num2, int num3) {
  if (ans % 2 == 0) {
    cout << "Not odd\n";
    return 0;
  }
  if (ans == num1 + num2 + num3) {
    printf("%d=%d+%d+%d", ans, num1, num2, num3);
    return 1;
  }
  else if (ans >= num1 + num2 + NextPrime(num3)) GWC(ans, num1, num2, NextPrime(num3));
  else if (ans >= num1 + NextPrime(num2) + num3) GWC(ans, num1, NextPrime(num2), num3);
  else if (ans >= NextPrime(num1) + num2 + num3) GWC(ans, NextPrime(num1), num2, num3);
  else return 0;
}

int main() {
  int n = 0;
  while (true) {
    cout << "Enter an odd number: ";
    cin >> n;
    GWC(n, 2, 2, 3);
    cout << endl;
  }
}
