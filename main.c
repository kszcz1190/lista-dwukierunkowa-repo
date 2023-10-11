#include <iostream>

using namespace std;

class lista {
private:
    int *head;
    int *tail;

public:
    lista(void){};
    ~lista(void){};


    void addToFront(int a); //dodawanie na poczatek
    void addToEnd (int a); //dodawanie na koniec
    void addUnderIndex(int a, int p); //dodawanie elementu pod wskazany index
    void removeFromBack(int a); //usuniecie z konca
    void removeFromFront(int a ); //usuniecie  z poczatku
    void removeUnderIndex(int position); //usuniecie z podanego indexu
    void displayList(); //wyswietlenie listy
    void displayReverse(); // wyswietlenie listy w odwrotnej kolejnoœci
    void displayNext(); // wyswietlenie nastepnego elementu
    void displayPrevious(); // wyswietlenie poprzedniego elementu
    void cleanList(); // wyczysc liste
};

lista::lista(void)
{
    head=NULL;
    tail=NULL;
}

lista::~lista(void)
{
    if(head!=NULL) delete head;
    if(tail!=NULL) delete tail;
}

int main (){

}

int menu(int a) {

    int choice;                                            //menu operacji wykonywanych na liscie
    do {
        cout<<"--------- MENU ---------"<<endl;
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


    switch(a){

        case 1:
            cout<<"Wybrano dodanie elementu na poczatek"<<endl;

        case 2:

        case 3:

        case 4:

        case 5:

        case 6:

        case 7:

        case 8:

        case 9:

        case 10:

        case 11:

            }
    }while(choice != 0);
}

int main (){

    lista L;

    cout<<"Aktualnie twoja lista jest pusta, dodaj do niej element aby przeprawadzic na niej inne operacje"<<endl;
    L.addToFront()
    menu();
}
