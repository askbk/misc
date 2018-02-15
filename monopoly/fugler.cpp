#include <iostream>

using namespace std;

int main() {

    int A, B; // fargeendring A til B
    double s; // Sannsynlighet for at fugl med farge A skifter farge til farge B
    double pMatrise[40][40]; // Sannsynlighetsmatrise, verdiene skal ikke endres
    double bMatrise[40][40]; // mellomleddsmatrise ved opphøying
    double uMatrise[40][40]; // Sannsynlighetsmatrise som inneholder sluttresultatene
    double verdi;

    cout.precision(8);

    for (size_t i = 0; i < 40; i++) { // setter alle verdier til null
        for (size_t j = 0; j < 40; j++) {
            cin >> pMatrise[i][j];
        }
    }

    int K; // antall bær fuglen spiser
    
    /*cout << "number of moves:";
    cin >> K;*/
    K = 2500;


    for (size_t i = 0; i < 40; i++) {   // setter alle verdier i uMatrise og bMatrise lik verdiene i pMatrise
        for (size_t j = 0; j < 40; j++) {
            uMatrise[i][j] = pMatrise[i][j];
            bMatrise[i][j] = pMatrise[i][j];
        }
    }

    for (size_t p = 1; p < K; p++) { // opphøyer matrisen i K (antall bær som er spist)
        for (int rad = 0; rad < 40; rad++) { //
            for (int kol = 0; kol < 40; kol++) { // kolonner i uMatrise, rader i pMatrise
                verdi = 0;
                for (size_t i = 0; i < 40; i++) { //
                    verdi += pMatrise[rad][i] * bMatrise[i][kol];
                }
                uMatrise[rad][kol] = verdi; // endrer på umatrisen.
            }
        }
        for (size_t i = 0; i < 40; i++) { // setter den midlertidige bMatrisen lik uMatrisen
            for (size_t j = 0; j < 40; j++) {
                bMatrise[i][j] = uMatrise[i][j];
            }
        }
    }

    for (size_t k = 0; k < 40; k++) { // printer ut resultat for spørringen
        cout << k << ": " << uMatrise[0][k] << "\n" << fixed;
    }
    return 0;
}
