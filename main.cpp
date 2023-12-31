#include <iostream>

using namespace std;

struct ListElement {
    int wartosc;
    ListElement* prev;
    ListElement* next;
    ListElement(int value) : wartosc(value), prev(nullptr), next(nullptr) {} // Konstruktor przyjmujący wartość
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
void removeFromBack(); //usuniecie z konca
void removeFromFront(); //usuniecie  z poczatku
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

ListElement *newElement = new ListElement(value);
newElement->wartosc = value;
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
    ListElement* newElement = new ListElement(value);
    newElement->prev = tail;
    newElement->next = nullptr;

    if (tail != nullptr) {
        tail->next = newElement;
    }

    tail = newElement;

    if (head == nullptr) {
        head = newElement;
    }
}

void lista::addUnderIndex(int wartosc, int position) {
    ListElement* newElement = new ListElement(wartosc);

    if (head == nullptr) { // Jeśli lista jest pusta, ustaw nowy element jako głowę i ogon
        head = newElement;
        tail = newElement;
        return;
    }

    if (position <= 0) { // Jeśli pozycja jest mniejsza lub równa 0, dodaj na początek
        newElement->next = head;
        head->prev = newElement;
        head = newElement;
        return;
    }

    int index = 0;
    ListElement* current = head;

    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }

    if (current == nullptr) { // Jeśli przekroczono koniec listy, dodaj na koniec
        newElement->prev = tail;
        tail->next = newElement;
        tail = newElement;
    } else { // W przeciwnym razie wstaw nowy element przed obecny element
        newElement->prev = current->prev;
        newElement->next = current;
        current->prev->next = newElement;
        current->prev = newElement;
    }
}



void lista::removeFromBack() {
    if (tail != nullptr) {
        ListElement *elementToRemove = tail;

        if (elementToRemove->prev != nullptr) {
            tail = elementToRemove->prev;
            tail->next = nullptr;
        } else {
            // Jeśli to był ostatni element na liście
            head = nullptr;
            tail = nullptr;
        }

        delete elementToRemove;
        cout << "Usunięto element z końca listy." << endl;
    } else {
        cout << "Lista jest pusta, nie można usunąć żadnego elementu." << endl;
    }
}

void lista::removeFromFront() {
    if (head != nullptr) {
        ListElement *elementToRemove = head;

        if (elementToRemove->next != nullptr) {
            head = elementToRemove->next;
            head->prev = nullptr;
        } else {
            // Jeśli to był ostatni element na liście
            head = nullptr;
            tail = nullptr;
        }

        delete elementToRemove;
        cout << "Usunięto element z początku listy." << endl;
    } else {
        cout << "Lista jest pusta, nie można usunąć żadnego elementu." << endl;
    }
}

void lista::removeUnderIndex(int position) {
    if (position < 0) {
        cout << "Błędna pozycja. Indeks musi być nieujemny." << endl;
        return;
    }

    if (head == nullptr) {
        cout << "Lista jest pusta, nie można usunąć elementu." << endl;
        return;
    }

    if (position == 0) {
        removeFromFront();  // Jeśli usuwamy element o indeksie 0, wywołujemy removeFromFront
        return;
    }

    ListElement *current = head;
    int index = 0;

    while (current != nullptr && index < position) {
        current = current->next;
        index++;
    }

    if (current == nullptr) {
        cout << "Podana pozycja przekracza rozmiar listy." << endl;
    } else {
        // Usuwamy element na podanej pozycji
        ListElement *elementToRemove = current;
        if (elementToRemove->prev != nullptr) {
            elementToRemove->prev->next = elementToRemove->next;
        } else {
            head = elementToRemove->next;
        }
        if (elementToRemove->next != nullptr) {
            elementToRemove->next->prev = elementToRemove->prev;
        } else {
            tail = elementToRemove->prev;
        }

        delete elementToRemove;
        cout << "Usunięto element z pozycji " << position << endl;
    }
}

void lista::displayList() {
    if (head == nullptr) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    ListElement *current = head;
    cout << "Zawartosc listy: ";
    while (current != nullptr) {
        cout << current->wartosc << " ";
        current = current->next;
    }
    cout << endl;
}

void lista::displayReverse() {
    if (tail == nullptr) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    ListElement *current = tail;
    cout << "Zawartosc listy: ";
    while (current != nullptr) {
        cout << current->wartosc << " ";
        current = current->prev;
    }
    cout << endl;
}

void lista::displayNext() {
    if (head == nullptr) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    ListElement *current = head;
    cout << "Nastepny element: ";
    if (current->next != nullptr) {
        cout << current->next->wartosc;
    } else {
        cout << "Brak nastepnego elementu.";
    }
    cout << endl;
}

void lista::displayPrevious() {
    if (head == nullptr) {
        cout << "Lista jest pusta." << endl;
        return;
    }

    ListElement *current = head;
    cout << "Poprzedni element: ";
    if (current->prev != nullptr) {
        cout << current->prev->wartosc;
    } else {
        cout << "Brak poprzedniego elementu.";
    }
    cout << endl;
}

void lista::cleanList() {
    while (head != nullptr) {
        ListElement *temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}


int menu(lista& L) {


int choice;                                            //menu operacji wykonywanych na liscie
    cout<<endl<<endl;
    cout<<"--------- MENU ---------"<<endl;
    cout<<" 0. Wyjscie"<<endl;
    cout<<" 1. Dodaj element na poczatek"<<endl;
    cout<<" 2. Dodaj element na koniec"<<endl;
    cout<<" 3. Dodaj element pod wskazany przez ciebie index"<<endl;
    cout<<" 4. Usun element z konca"<<endl;
    cout<<" 5. Usun element z poczatku"<<endl;
    cout<<" 6. Usun element ze wskazanego przez ciebie indexu"<<endl;
    cout<<" 7. Wyswietl liste"<<endl;
    cout<<" 8. Wyswietl liste w odwrotnej kolejnosci"<<endl;
    cout<<" 9. Wyswietl nastepny element"<<endl;
    cout<<"10. Wyswietl poprzedni element"<<endl;
    cout<<"11. Wyczysc liste"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Pozycja z menu: ";
    cin>> choice;


switch(choice){

    case 0:
        cout<<"Wyjscie"<<endl;
    return 0;

    case 1:
        cout<<"Wybrano dodanie elementu na poczatek"<<endl;
        int a;
        cout<<"Podaj wartosc elementu: ";
        cin>>a;
        L.addToFront(a);
        break;

    case 2:
        cout<<"Wybrano dodanie elementu na koniec"<<endl;
        int b;
        cout<<"Podaj wartosc elementu: ";
        cin>>b;
        L.addToEnd(b);
        break;

    case 3:
       cout<<"Wybrano dodanie elementu pod wskazany przez ciebie index"<<endl;
       int c, p1;
       cout<<"Podaj wartosc elementu: ";
       cin>>c;
       cout<<"Podaj index elementu: ";
       cin>>p1;
       L.addUnderIndex(c, p1);
       break;

    case 4:
        cout<<"Wybrano usuniecie elementu z konca listy"<<endl;
        L.removeFromBack();
        break;

    case 5:
        cout<<"Wybrano usuniecie elementu z poczatku listy"<<endl;
        L.removeFromFront();
        break;

    case 6:
        cout<<"Wybrano usuniecie elementu ze wskazanego przez ciebie indexu"<<endl;
        int p2;
        cout<<"Podaj index elementu: ";
        cin>>p2;
        L.removeUnderIndex(p2);
        break;

    case 7:
        cout<<"Wybrano wyswietlenie listy"<<endl;
        L.displayList();
        break;

    case 8:
        cout<<"Wybrano wyswietlenie listy w odwrotnej kolejnosci"<<endl<<endl;
        L.displayReverse();
        break;

    case 9:
        cout<<"Wybrano wyswietlenie nastepnego elementu"<<endl<<endl;
        L.displayNext();
        break;

    case 10:
        cout<<"Wybrano wyswietlenie poprzedniego elementu"<<endl;
        L.displayPrevious();
        break;

    case 11:
        cout<<"Wybrano wyczyszczenie listy";
        L.cleanList();
        break;

}
}

int main (int argc, char** argv){

lista L;
int wartosc;

cout<<"Aktualnie twoja lista jest pusta, wpisz pierwszy element, aby przeprawadzic na niej inne operacje: ";
cin>>wartosc;
L.addToFront(wartosc);

int result;
do {
result = menu(L);

}while(result!= 0
       );
return 0;
}
