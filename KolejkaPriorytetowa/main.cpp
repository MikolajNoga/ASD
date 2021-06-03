#include <iostream>
#include <ctime>

using namespace std;

    void heapify(int tab[], int tabLength, int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int temp;

        if (left < tabLength && tab[left] > tab[largest])
            largest = left;
        if (right < tabLength && tab[right] > tab[largest])
            largest = right;

        if (largest != i) {
            temp = tab[i];
            tab[i] = tab[largest];
            tab[largest] = temp;
            heapify(tab, tabLength, largest);
        }
    }

void buildHeap(int tab[], int tabLength){
    // ostatni index który ma "dzieci"
    int startIdx = (tabLength / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        heapify(tab, tabLength, i);
    }
}

void printHeap(int tab[], int tabLength){
    cout << "tab: [";
    for (int i = 0; i < tabLength-1; ++i)
        cout << tab[i] << ",";
    cout << tab[tabLength-1] << "]" << endl;
}

int maximum(int tab[]){ return tab[0]; }

int extractMax(int tab[], int tabLength){
    int temp = tab[tabLength-1];
    tab[tabLength-1] = tab[0];
    tab[0] = temp;
    heapify(tab,tabLength-1,0);
    return tabLength-1;
}

void increaseKey(int tab[], int index, int newKeyValue, int tabLength){
    tab[index] = newKeyValue;
    // Chciałem tutaj odwołać się do heapify tylko ale nie
    // wiedziałem jak sprawdzić czy "dziecko" jest "lewe" czy "prawe"
    buildHeap(tab,tabLength);
}

int insert(int newElement, int tab[], int tabLength){
    tab[tabLength] = newElement;
    tabLength++;
    // tak samo jak powyżej
    buildHeap(tab,tabLength);
    return tabLength;
}

int main(){
    srand(time(NULL));
    // tablica 100 elementowa, ponieważ nie jest
    // dynamiczna i żeby nie trzeba było tworzyć
    // nowej podczas insert'u
    int tab[100];
    for (int i=0; i<20; i++)
        tab[i] = rand() % 20;

    int tabLength = 20;

    buildHeap(tab,tabLength);
    printHeap(tab,tabLength);
    cout << "Wartosc max: " << maximum(tab) << endl;
    tabLength = extractMax(tab,tabLength);
    printHeap(tab,tabLength);
    increaseKey(tab, 7, 20, tabLength);
    printHeap(tab,tabLength);
    tabLength = insert(13,tab,tabLength);
    printHeap(tab,tabLength);

    return 0;
}