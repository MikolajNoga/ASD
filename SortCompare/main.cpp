#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

void tempArrAssign(int temp[], int arr[]){
    for (int i = 0; i < 100; i++) {
        temp[i] = arr[i];
    }
}

// quickSort
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

// kolajkaPriorytetowa

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

// sortowanie przez wstawianie

void insertionSort(int arr[],int arrLength){
    int temp1, temp2;
    for(int i = arrLength - 2; i >= 0; i--)
    {
        temp2 = arr[i];
        temp1 = i + 1;
        while((temp1 < arrLength) && (temp2 > arr[temp1]))
        {
            arr[temp1 - 1] = arr[temp1];
            temp1++;
        }
        arr[temp1 - 1] = temp2;
    }
}

// sortowanie przez wybór

void selectionSort(int arr[], int arrLength){
    int pMin;
    for(int i = 0; i < arrLength - 1; i++)
    {
        pMin = i;
        for(int j = i + 1; j < arrLength; j++)
            if(arr[j] < arr[pMin]) pMin = j;
        swap(arr[pMin], arr[i]);
    }
}

// sortowanie bąbelkowe

void bubbleSort(int arr[], int arrLength){
    for(int i = 0; i < arrLength - 1; i++)
        for(int j = 0; j < arrLength - 1; j++)
            if(arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

// sortowanie kubełkowe

void bucketSort(int arr[], int arrLength){
    const int WMIN = 0;
    const int WMAX = 200;
    int lw[WMAX - WMIN + 1];

    for(int i = WMIN; i <= WMAX; i++)
        lw[i - WMIN] = 0;
    for(int i = 0; i < arrLength; i++)
        lw[arr[i] - WMIN]++;
    int j = 0;
    for( int i = WMIN; i <= WMAX; i++)
        while(lw[i - WMIN]--)
            arr[j++] = i;
}

// sortowanie pozycyjne + zliczanie

void radixAndCountingSort(int arrLength, int arr[]){
    int C[10];
    int temp[100];
    tempArrAssign(temp,arr);
    // przejście po cyfrach jedności
    for (int i = 0; i < 10; ++i){
        C[i] = 0;
    }
    for (int i = 0; i < arrLength; i++) {
        C[arr[i] % 10] = C[arr[i] % 10] + 1;
    }
    for (int i = 1; i < 10; ++i)
        C[i] = C[i] + C[i-1];
    for (int i = arrLength-1; i >= 0 ; i--) {
        arr[C[temp[i] % 10] - 1] = temp[i];
        C[temp[i]%10] = C[temp[i]%10] - 1;
    }
    // przejście po cyfrach dzięsiątek
    tempArrAssign(temp,arr);
    for (int i = 0; i < 10; ++i){
        C[i] = 0;
    }
    for (int i = 0; i < arrLength; i++) {
        C[arr[i] / 10 % 10] = C[arr[i] / 10 % 10] + 1;
    }
    for (int i = 1; i < 10; ++i)
        C[i] = C[i] + C[i-1];
    for (int i = arrLength-1; i >= 0 ; i--) {
        arr[C[temp[i] / 10 % 10] - 1] = temp[i];
        C[temp[i]/10 % 10] = C[temp[i]/ 10 % 10] - 1;
    }
    // przejście po cyfrach setek
    tempArrAssign(temp,arr);
    for (int i = 0; i < 10; ++i){
        C[i] = 0;
    }
    for (int i = 0; i < arrLength; i++) {
        C[arr[i] / 100 % 10] = C[arr[i] / 100 % 10] + 1;
    }
    for (int i = 1; i < 10; ++i)
        C[i] = C[i] + C[i-1];
    for (int i = arrLength-1; i >= 0 ; i--) {
        arr[C[temp[i] / 100 % 10] - 1] = temp[i];
        C[temp[i]/100 % 10] = C[temp[i]/100 % 10] - 1;
    }
}

void selectionSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]);
void insertionSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]);
void pileSortTimeCounting(int *tempArr, int *randArr, int *preSortedArr, int *reverseSortedArr);
void quickSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]);
void bubbleSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]);
void radixAndCountingSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]);
void bucketSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]);

int main() {
    srand(time(NULL));
    int randArr[100];
    for (int i = 0; i < 100; i++) {
        randArr[i] = rand() % 100 + 100;
    }
    int preSortedArr[100];
    for (int i = 0; i < 100; i++) {
        preSortedArr[i] = i+100;
    }
    int reverseSortedArr[100];
    for (int i = 0; i < 100; i++) {
        reverseSortedArr[i] = 200-i;
    }
    int tempArr[100];

    quickSortTimeCounting(tempArr,randArr,preSortedArr,reverseSortedArr);

    pileSortTimeCounting(tempArr, randArr, preSortedArr, reverseSortedArr);

    insertionSortTimeCounting(tempArr,randArr,preSortedArr,reverseSortedArr);

    selectionSortTimeCounting(tempArr,randArr,preSortedArr,reverseSortedArr);

    bubbleSortTimeCounting(tempArr,randArr,preSortedArr,reverseSortedArr);

    radixAndCountingSortTimeCounting(tempArr,randArr,preSortedArr,reverseSortedArr);

    bucketSortTimeCounting(tempArr,randArr,preSortedArr,reverseSortedArr);

    return 0;
}

void selectionSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]){
    tempArrAssign(tempArr,preSortedArr);
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    selectionSort(tempArr,100);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();

    tempArrAssign(tempArr,reverseSortedArr);
    chrono::steady_clock::time_point beginReverse = chrono::steady_clock::now();
    selectionSort(tempArr,100);
    chrono::steady_clock::time_point endReverse = chrono::steady_clock::now();

    tempArrAssign(tempArr,randArr);
    chrono::steady_clock::time_point beginRand = chrono::steady_clock::now();
    selectionSort(tempArr,100);
    chrono::steady_clock::time_point endRand = chrono::steady_clock::now();

    cout << "SelectionSort randArr: " << chrono::duration_cast<chrono::nanoseconds> (endRand - beginRand).count() << "[ns]\n";
    cout << "SelectionSort preArr: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n";
    cout << "SelectionSort reverseArr: " << chrono::duration_cast<chrono::nanoseconds> (endReverse - beginReverse).count() << "[ns]\n\n";
}

void quickSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]){

    tempArrAssign(tempArr,preSortedArr);
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    quicksort(tempArr,0,99);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();

    tempArrAssign(tempArr,reverseSortedArr);
    chrono::steady_clock::time_point beginReverse = chrono::steady_clock::now();
    quicksort(tempArr,0,99);
    chrono::steady_clock::time_point endReverse = chrono::steady_clock::now();

    tempArrAssign(tempArr,randArr);
    chrono::steady_clock::time_point beginRand = chrono::steady_clock::now();
    quicksort(tempArr,0,99);
    chrono::steady_clock::time_point endRand = chrono::steady_clock::now();

    cout << "Quicksort randArr: " << chrono::duration_cast<chrono::nanoseconds> (endRand - beginRand).count() << "[ns]\n";
    cout << "Quicksort preArr: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n";
    cout << "Quicksort reverseArr: " << chrono::duration_cast<chrono::nanoseconds> (endReverse - beginReverse).count() << "[ns]\n\n";
}

void pileSortTimeCounting(int *tempArr, int *randArr, int *preSortedArr, int *reverseSortedArr){
    tempArrAssign(tempArr,preSortedArr);
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    buildHeap(tempArr,100);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();

    tempArrAssign(tempArr,reverseSortedArr);
    chrono::steady_clock::time_point beginReverse = chrono::steady_clock::now();
    buildHeap(tempArr,100);
    chrono::steady_clock::time_point endReverse = chrono::steady_clock::now();

    tempArrAssign(tempArr,randArr);
    chrono::steady_clock::time_point beginRand = chrono::steady_clock::now();
    buildHeap(tempArr,100);
    chrono::steady_clock::time_point endRand = chrono::steady_clock::now();

    cout << "PileSort randArr: " << chrono::duration_cast<chrono::nanoseconds> (endRand - beginRand).count() << "[ns]\n";
    cout << "PileSort preArr: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n";
    cout << "PileSort reverseArr: " << chrono::duration_cast<chrono::nanoseconds> (endReverse - beginReverse).count() << "[ns]\n\n";
}

void insertionSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]){
    tempArrAssign(tempArr,preSortedArr);
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    insertionSort(tempArr,100);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();

    tempArrAssign(tempArr,reverseSortedArr);
    chrono::steady_clock::time_point beginReverse = chrono::steady_clock::now();
    insertionSort(tempArr,100);
    chrono::steady_clock::time_point endReverse = chrono::steady_clock::now();

    tempArrAssign(tempArr,randArr);
    chrono::steady_clock::time_point beginRand = chrono::steady_clock::now();
    insertionSort(tempArr,100);
    chrono::steady_clock::time_point endRand = chrono::steady_clock::now();

    cout << "InsertionSort randArr: " << chrono::duration_cast<chrono::nanoseconds> (endRand - beginRand).count() << "[ns]\n";
    cout << "InsertionSort preArr: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n";
    cout << "InsertionSort reverseArr: " << chrono::duration_cast<chrono::nanoseconds> (endReverse - beginReverse).count() << "[ns]\n\n";
}

void bubbleSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]){
    tempArrAssign(tempArr,preSortedArr);
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    bubbleSort(tempArr,100);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();

    tempArrAssign(tempArr,reverseSortedArr);
    chrono::steady_clock::time_point beginReverse = chrono::steady_clock::now();
    bubbleSort(tempArr,100);
    chrono::steady_clock::time_point endReverse = chrono::steady_clock::now();

    tempArrAssign(tempArr,randArr);
    chrono::steady_clock::time_point beginRand = chrono::steady_clock::now();
    bubbleSort(tempArr,100);
    chrono::steady_clock::time_point endRand = chrono::steady_clock::now();

    cout << "BubbleSort randArr: " << chrono::duration_cast<chrono::nanoseconds> (endRand - beginRand).count() << "[ns]\n";
    cout << "BubbleSort preArr: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n";
    cout << "BubbleSort reverseArr: " << chrono::duration_cast<chrono::nanoseconds> (endReverse - beginReverse).count() << "[ns]\n\n";
}

void radixAndCountingSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]){
    tempArrAssign(tempArr,preSortedArr);
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    radixAndCountingSort(100,tempArr);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();

    tempArrAssign(tempArr,reverseSortedArr);
    chrono::steady_clock::time_point beginReverse = chrono::steady_clock::now();
    radixAndCountingSort(100,tempArr);
    chrono::steady_clock::time_point endReverse = chrono::steady_clock::now();

    tempArrAssign(tempArr,randArr);
    chrono::steady_clock::time_point beginRand = chrono::steady_clock::now();
    radixAndCountingSort(100,tempArr);
    chrono::steady_clock::time_point endRand = chrono::steady_clock::now();

    cout << "RadixAndCountingSort randArr: " << chrono::duration_cast<chrono::nanoseconds> (endRand - beginRand).count() << "[ns]\n";
    cout << "RadixAndCountingSort preArr: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n";
    cout << "RadixAndCountingSort reverseArr: " << chrono::duration_cast<chrono::nanoseconds> (endReverse - beginReverse).count() << "[ns]\n\n";
}

void bucketSortTimeCounting(int tempArr[],int randArr[],int preSortedArr[],int reverseSortedArr[]){
    tempArrAssign(tempArr,preSortedArr);
    chrono::steady_clock::time_point beginPre = chrono::steady_clock::now();
    bucketSort(tempArr,100);
    chrono::steady_clock::time_point endPre = chrono::steady_clock::now();

    tempArrAssign(tempArr,reverseSortedArr);
    chrono::steady_clock::time_point beginReverse = chrono::steady_clock::now();
    bucketSort(tempArr,100);
    chrono::steady_clock::time_point endReverse = chrono::steady_clock::now();

    tempArrAssign(tempArr,randArr);
    chrono::steady_clock::time_point beginRand = chrono::steady_clock::now();
    bucketSort(tempArr,100);
    chrono::steady_clock::time_point endRand = chrono::steady_clock::now();

    cout << "BucketSort randArr: " << chrono::duration_cast<chrono::nanoseconds> (endRand - beginRand).count() << "[ns]\n";
    cout << "BucketSort preArr: " << chrono::duration_cast<chrono::nanoseconds> (endPre - beginPre).count() << "[ns]\n";
    cout << "BucketSort reverseArr: " << chrono::duration_cast<chrono::nanoseconds> (endReverse - beginReverse).count() << "[ns]\n\n";
}
