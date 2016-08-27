#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

void runEratosthenesSieve(int upperBound) {
      int upperBoundSquareRoot = (int)sqrt((double)upperBound);
      bool *isComposite = new bool[upperBound + 1];
      memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
      for (int m = 2; m <= upperBoundSquareRoot; m++) {
            if (!isComposite[m]) {
                  cout << m << " ";
                  for (int k = m * m; k <= upperBound; k += m)
                        isComposite[k] = true;
            }
      }
      for (int m = upperBoundSquareRoot; m <= upperBound; m++)
            if (!isComposite[m])
                  cout << m << " ";
      delete [] isComposite;
}

int main( void ){
	runEratosthenesSieve(100000);
}
