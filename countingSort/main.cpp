#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    const int N    = 80;
    const int KMIN =  0;
    const int KMAX = 26;

    struct
    {
        unsigned klucz;
        char     wyraz[3];
    } d[N],b[N];

    unsigned L[KMAX - KMIN + 1];
    int i,j,v;

    cout << "  Sortowanie Przez Zliczanie\n"
            "------------------------------\n"
            "  (C)2005 mgr Jerzy Walaszek\n\n"
            "Przed sortowaniem:\n\n";

// Generujemy losowe elementy do sortowania oraz ich klucze

    srand((unsigned)time(NULL));

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < 3; j++) d[i].wyraz[j] = 65 + rand() % 3;
        d[i].klucz = 0;
        v = 1;
        for(j = 2; j >= 0; j--)
        {
            d[i].klucz += v * (d[i].wyraz[j] - 65);
            v *= 3;
        }
    }

// Wyświetlamy wygenerowane elementy

    for(i = 0; i < N; i++)
        cout << ' ' << d[i].wyraz[0] << d[i].wyraz[1] << d[i].wyraz[2];
    cout << endl;

// Zerujemy liczniki

    for(i = KMIN; i <= KMAX; i++) L[i - KMIN] = 0;

// Zliczamy wystąpienia kluczy

    for(i = 0; i < N; i++) L[d[i].klucz - KMIN]++;

// Obliczamy pozycje końcowe elementów

    for(i = KMIN + 1; i <= KMAX; i++) L[i - KMIN] += L[i - KMIN - 1];

// Przepisujemy elementy z d[ ] do b[ ]

    for(i = N - 1; i >= 0; i--) b[(L[d[i].klucz - KMIN]--) - 1] = d[i];

// Wyświetlamy wyniki w b[ ]

    cout << "Po sortowaniu:\n\n";
    for(i = 0; i < N; i++)
        cout << ' ' << b[i].wyraz[0] << b[i].wyraz[1] << b[i].wyraz[2];
    cout << endl;
    return 0;
}