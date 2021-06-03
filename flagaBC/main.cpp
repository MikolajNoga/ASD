#include <iostream>

using namespace std;

int main() {
    char tab[] = {'b','c','c','c','b','b','c','c','b'};
    for (int i = 0; i < 9; ++i) {
        cout << tab[i] << " ";
    }
    char temp;
    for (int i = 0; i < 9; ++i) {
        for (int j = i+1; j < 9; ++j) {
            if (tab[i]>tab[j]){
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < 9; ++i) {
        cout << tab[i] << " ";
    }
    return 0;
}
