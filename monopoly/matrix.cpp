#include <cmath>
#include <iostream>

using namespace std;

int main() {

  int A, B; // fargeendring A til B
  double s; // Sannsynlighet for at fugl med farge A skifter farge til farge B
  double pMatrise[40][40]; // Sannsynlighetsmatrise, verdiene skal ikke endres
  double uMatrise[40][40]; // Sannsynlighetsmatrise som inneholder
                         // sluttresultatene
  double iMatrise[40][40]; // identitetsmatrisen
  double verdi;

  for (size_t i = 0; i < 40; i++) { // setter alle verdier til null
    for (size_t j = 0; j < 40; j++) {
      cin >> pMatrise[i][j];
    }
  }

  int K; // antall bær fuglen spiser
  K = 100;

  int M = K;
  for (size_t i = 0; i < 40;
       i++) { // konstruerer iMatrisen på nytt for hver spørring
    for (size_t j = 0; j < 40; j++) {
      if (i == j) {
        iMatrise[i][j] = 1;
      } else {
        iMatrise[i][j] = 0;
      }
    }
  }

  while (M != 0) {
    double aMatrise[40][40];
    for (size_t i = 0; i < 40; i++) { // kopierer pMatrise for hver gang
      for (size_t j = 0; j < 40; j++) {
        aMatrise[i][j] = pMatrise[i][j];
      }
    }

    int n = exp2(floor(log2(M))); // nærmeste eksponent under M
    int logN = floor(log2(M));

    if (M > 1) {
      for (size_t m = 0; m < logN; m++) {
        for (int rad = 0; rad < 40; rad++) {
          for (int kol = 0; kol < 40; kol++) { // kolonner i matrise 2, rader i matrise 1
            verdi = double(0);
            for (size_t i = 0; i < 40; i++) { //
              verdi += aMatrise[rad][i] * aMatrise[i][kol];
            }
            uMatrise[rad][kol] = verdi; // endrer på umatrisen.
          }
        }
        for (size_t i = 0; i < 40; i++) { // setter den midlertidige aMatrisen lik uMatrisen
          for (size_t j = 0; j < 40; j++) {
            aMatrise[i][j] = uMatrise[i][j];
          }
        }
      }
    }
    // multipliser aMatrise med iMatrise
    for (int rad = 0; rad < 40; rad++) { //
      for (int kol = 0; kol < 40; kol++) { // kolonner i matrise 2, rader i matrise 1
        verdi = 0;
        for (size_t i = 0; i < 40; i++) { //
          verdi += aMatrise[rad][i] * iMatrise[i][kol];
        }
        uMatrise[rad][kol] = verdi; // endrer på umatrisen.
      }
    }
    for (size_t i = 0; i < 40; i++) { // setter den midlertidige bMatrisen lik uMatrisen
      for (size_t j = 0; j < 40; j++) {
        iMatrise[i][j] = uMatrise[i][j];
      }
    }
    if (M == 1) {
      M = 0;
    } else {
      M = M - n;
    }
  }
  double sum = 0;
  for (size_t k = 0; k < 40; k++) { // printer ut resultat for spørringen
    cout << k << ": " << iMatrise[0][k] << "\n";
    sum += iMatrise[0][k];
  }
  cout << "sum: " << sum << "\n";
  return 0;
}
