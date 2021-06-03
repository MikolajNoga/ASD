// Sortowanie Pozycyjne
//--------------------------------------------------------
// (C)2012 mgr Jerzy Wałaszek
// I Liceum Ogólnokształcące
// im. K. Brodzińskiego
// w Tarnowie
//--------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

const int N     =  80;  // ilość elementów
const int MAXEL = 999;  // maksymalna wartość elementu

// Procedura sortująca

void Sortuj(unsigned z1[], unsigned z2[], unsigned m)
{
    unsigned L[2],i;

    L[0] = L[1] = 0;
    for(i = 1; i <= N; i++) L[(z1[i] & m) > 0]++;
    L[1] += L[0];
    for(i = N; i >= 1; i--) z2[L[(z1[i] & m) > 0]--] = z1[i];
}

int main()
{
    unsigned d[N+1],b[N+1],i,m;
// Generujemy pseudolosową zawartość zbioru d[ ]

    srand((unsigned)time(NULL));

    for(i = 1; i <= N; i++)
    {
        d[i] = rand() % (MAXEL + 1);
        cout << setw(4) << d[i];
    }

// Ustawiamy maskę na najmłodszy bit

    m = 1;

// Sortujemy

    while(m <= MAXEL)
    {
        Sortuj(d,b,m); m <<= 1;
        Sortuj(b,d,m); m <<= 1;
    }

// Wyświetlamy wyniki

    cout << "\nPo sortowaniu:\n\n";
    for(i = 1; i <= N; i++) cout << setw(4) << d[i];
    cout << endl;
    return 0;
}