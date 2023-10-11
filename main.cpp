#include <iostream>

using namespace std;

struct ListElement {
    int wartosc;
    ListElement* prev;
    ListElement* next;
    ListElement(int value ) : wartosc(value), prev(nullptr), next(nullptr){}
};

class lista {
private:
ListElement *head;
ListElement *tail;

public:
lista(void): head(nullptr),tail(nullptr){};
~lista(void);

void addToFront(int wartosc); //dodawanie na poczatek
void addToEnd (int wartosc); //dodawanie na koniec
void addUnderIndex(int wartosc, int position); //dodawanie elementu pod wskazany index
void removeFromBack(int a); //usuniecie z konca
void removeFromFront(int a ); //usuniecie  z poczatku
void removeUnderIndex(int position); //usuniecie z podanego indexu
void displayList(); //wyswietlenie listy
void displayReverse(); // wyswietlenie listy w odwrotnej kolejnoœci
void displayNext(); // wyswietlenie nastepnego elementu
void displayPrevious(); // wyswietlenie poprzedniego elementu
void cleanList(); // wyczysc liste
};

lista::~lista(void)
{
    while (head != nullptr) {
        ListElement* temp = head;
        head = head->next;
        delete temp;
    }
}

void lista::addToFront(int value) {

ListElement* newElement = new ListElement;
newElement->data = value;
newElement->prev = nullptr;
newElement->next = head;

if(head != nullptr){
    head->prev = newElement;
}

head = newElement;

if(tail == nullptr){
    tail = newElement;
}
}

void lista::addToEnd(int value) {
ListElement* newElement = new ListElement;
newElement->data = value;
newElement->prev = tail;
newElement->next = nullptr;

if( tail!= nullptr) {
    tail->next = new ListElement;
}

tail = newElement;

if(head == nullptr) {
    head = newElement;
}
}

int menu() {

int choice;                                            //menu operacji wykonywanych na liscie

    cout<<"--------- MENU ---------"<<endl;
    cout<<" 0. Wyjscie"<<endl;
    cout<<" 1. Dodaj element na poczatek"<<endl;
    cout<<" 2. Dodaj element na koniec"<<endl;
    cout<<" 3. Dodaj element pod wskazany przez ciebie index"<<endl;
    cout<<" 4. Usun element z konca"<<endl;
    cout<<" 5. Usun element z początku"<<endl;
    cout<<" 6. Usun element ze wskazanego przez ciebie indexu"<<endl;
    cout<<" 7. Wyswietl list"<<endl;
    cout<<" 8. Wyświetl liste w odwrotnej kolejnosci"<<endl;
    cout<<" 9. Wyswietl nastepny element"<<endl;
    cout<<" 10. Wyswietl poprzedni element"<<endl;
    cout<< "11. Wyczysc liste"<<endl;
    cin>> choice;


switch(choice){

    case 0:

    break;

    case 1:
        cout<<"Wybrano dodanie elementu na poczatek"<<endl;
        int wartosc;
        cout<<"Podaj wartosc elementu";
        cin>>wartosc;
        L.addToFront(wartosc);
        break;

    case 2:
        cout<<"Wybrano dodanie elementu na koniec"<<endl;
        int wartosc;
        cout<<"Podaj wartosc elementu";
        cin>>wartosc;
        L.addToEnd(wartosc);
        break;

    case 3:
       cout<<"Wybrano dodanie elementu pod wskazany przez ciebie index"<<endl;
       int wartosc, position;
       cout<<"Podaj wartosc elementu";
       cin>>wartosc;
       cout<<"Podaj index elementu";
       cin>>position;
       L.addUnderIndex(wartosc, position);
       break;

    case 4:
        cout<<"Wybrano usuniecie elementu z konca listy"<<endl;
        removeFromBack();
        break;

    case 5:
        cout<<"Wybrano usuniecie elementu z poczatku listy"<<endl;
        removeFromFront();
        break;

    case 6:
        cout<<"Wybrano usuniecie elementu ze wskazanego przez ciebie indexu"<<endl;
        int position;
        cout<<"Podaj index elementu";
        cin>>position;
        L.removeUnderIndex(position);
        break;

    case 7:
        cout<<"Wybrano wyswietlenie listy"<<endl;
        displayList();
        break;

    case 8:
        cout<<"Wybrano wyswietlenie listy w odwrotnej kolejnosci"<<endl;
        displayReverse();
        break;

    case 9:
        cout<<"Wybrano wyswietlenie nastepnego elementu"<<endl;
        displayNext();
        break;

    case 10:
        cout<<"Wybrano wyswietlenie poprzedniego elementu"<<endl;
        displayPrevious();
        break;

    case 11:
        cout<<"Wybrano wyczyszczenie listy";
        cleanList();
        break;

}
}

int main (int argc, char** argv){

lista L;

cout<<"Aktualnie twoja lista jest pusta, dodaj do niej element, aby przeprawadzic na niej inne operacje"<<endl;
L.addToFront(wartosc);
do {

menu();

}while
}
