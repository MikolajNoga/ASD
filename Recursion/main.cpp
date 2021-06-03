#include <iostream>

using namespace std;

long factorial(int num){
    if(num<=1)
        return 1;
    return num*factorial(num-1);
}

long oddNumberSum(int num){
    if(num==1)
        return 1;
    if (num%2==1) {
        return num+oddNumberSum(num-2);
    }
    return oddNumberSum(num-1);
}

long numberDivisibleBy3Sum(int num){
    if(num==3)
        return 3;
    if (num%3==0)
        return num+numberDivisibleBy3Sum(num-3);
    return numberDivisibleBy3Sum(num-1);
}

int arithmeticSequence(int n){
    if (n==0)
        return 0;
    return 2*arithmeticSequence(n-1)+3;
}

int anotherSequence(int n){
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    return 3*anotherSequence(n-1)-anotherSequence(n-2);
}

int main() {
    cout << "The factorial of 6 is: " << factorial(6) << endl;
    cout << "Sum of odd numbers from 1 to 10 is: " << oddNumberSum(10) << endl;
    cout << "Sum of numbers divisible by 3 from 1 to 15 is: " << numberDivisibleBy3Sum(15) << endl;
    cout << "Arithmetic sequence of n=5 is: ";
    for (int i = 0; i < 5; ++i)
        cout << arithmeticSequence(i) << ", ";
    cout << arithmeticSequence(5) << endl;
    cout << "Another sequence (zad 2e) of n=5 is: ";
    for (int i = 1; i < 5; ++i)
        cout << anotherSequence(i) << ", ";
    cout << anotherSequence(5) << endl;
    return 0;
}
