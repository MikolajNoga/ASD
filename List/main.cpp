#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
//-------------------------------
struct element
{
  int liczba;
  element *wsk;
};
//-------------------------------
struct info
{
  element *head;
  element *tail;
};
//-------------------------------
void AddElement(int i, info *W);
void CreateList(int n, info *W);
void PrintList(info *W);
void DeleteList(info *W);
//-------------------------------
int main(){
  int n;
  info *W;
  W = new info;
  W->head = NULL;
  W->tail = NULL;
  //utworzenie listy n-elementowej
  cout << "Podaj dlugosc listy: ";
  cin >> n;
  //CreateList(n, W);
  AddElement(1,W);
  AddElement(2,W);
  AddElement(3,W);
  //wypisanie listy
    PrintList(W);
  //usuniecie calej listy
    DeleteList(W);
}
//-------------------------------
void CreateList(int n, info *W){
  for (int i=1; i<=n; i++)
      AddElement(i, W);
}
//-------------------------------
void AddElement(int i, info *W)
{
  element *nowy = new element;
  nowy->liczba = i;
  nowy->wsk = NULL;
  //dolaczenie elementu na koniec listy
  if (W->head == NULL){
    W->head = nowy;
    W->tail = nowy;
  }
  else{
    W->tail->wsk = nowy;
    W->tail = nowy;
  }
}
//-------------------------------
void PrintList(info *W)
{
  element *biezacy = W->head;
  if (W->head != NULL)
  {
    while (biezacy != NULL)
    {
      cout << biezacy->liczba << "  ";
      biezacy = biezacy->wsk;
    }
  }
  else
  {
    cout << "Lista jest pusta";
  }
}
//-------------------------------
void DeleteList(info *W)
{
  element *biezacy = W->head;
  element *usuwany;
  if (W->head != NULL)
  {
    while (biezacy != NULL)
    {
      usuwany = biezacy;
      biezacy = biezacy->wsk;
      delete usuwany;
    }
  }
  if (biezacy == NULL) cout << "\nListe usunieto\n";
}