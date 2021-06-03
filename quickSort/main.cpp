# include <iostream>

using namespace std;

int partition(int A[], int lo, int hi){
    int pivot = A[hi];
    int i = lo;
    int temp;

    for (int j = lo; j < hi; j++) {
        if (A[j] < pivot){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
        }
    }
    temp = A[i];
    A[i] = A[hi];
    A[hi] = temp;
    return i;
}


void quicksort(int A[], int lo, int hi) {
    if (lo < hi) {
        int q = partition(A, lo, hi);
        quicksort(A, lo, q - 1);
        quicksort(A, q+1, hi);
    }
}

int main() {
    int A[] = {5,3,99,23,4,1,6};
    cout << "UNSORTED: [";
    for (int i = 0; i < 6; i++) {
        cout << A[i] << ",";
    }
    cout << A[6] << "]" << endl;
    quicksort(A, 0, 6);
    cout << "SORTED: [";
    for (int i = 0; i < 6; i++) {
        cout << A[i] << ",";
    }
    cout << A[6] << "]";
}