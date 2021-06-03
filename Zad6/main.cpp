#include<time.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

int main(){
    srand( time( NULL ) );
    int A[20];
    for (int i=0; i<20; i++)
        A[i] = rand() % 20;

    /***** WYŚWIETLENIE ZAWARTOŚCI NIE POSORTOWANEJ TABLICY ******/
    cout << "A= [";
    for (int i=0; i<19; i++)
        cout << A[i] << ", ";
    cout << A[19] << "]" << endl;

    /***** Tutaj umieść rozwiązanie zadania ******/
    int key;
    int i;
    for (int j = 1; j < 20; ++j) {
        key = A[j];
        i = j-1;
        while (i>=0 && A[i]>key){
            A[i+1]=A[i];
            i = i-1;
        }
        A[i + 1] = key;
    }
    /***** WYŚWIETLENIE ZAWARTOŚCI POSORTOWANEJ TABLICY ******/
    cout << "A= [";
    for (int i=0; i<19; i++)
        cout << A[i] << ", ";
    cout << A[19] << "]" << endl;
}