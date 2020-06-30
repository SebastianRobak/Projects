

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack> 
#include <list> 
#include <queue>
#include <string>
#include "DoublyList.h"
#include "Heap.h"
#include "Queue.h"
#include "SinglyList.h"
#include "Stack.h"

#define STACK_SIZE 2
#define QUEUE_SIZE 3
#define HEAP_SIZE 15
#define MAX_NUMB 10
#define MIN_NUMB 0

using namespace std;
int main()
{
    bool quit = true, end = true;
    int structure_choice, m, x;
    char choice;
    list<int>::iterator it1, it2;
    double z, a;

    stack<int> stackstl;
    list<int> liststl;
    queue<int> queuestl;
    myStack<double> my_stack(STACK_SIZE);
    myQueue<double> my_queue(QUEUE_SIZE);
    SinglyList<double> my_singlylist;
    DoublyList<double> my_doublylist;
    Heap<double> my_heap(HEAP_SIZE);


    srand(static_cast<unsigned int>(time(NULL)));
    
    while (end)
    {
        quit = true;
        cout << "Prosze wybrac strukture z ktorej chcesz skorzystac wpisujac jej numer:\n1 - std::stack\n2 - std::queue\n3 - std::list\n4 - stack\n5 - queue\n6 - SinglyLinkedList\n7 - DoublyLinkedList\n8 - Heap\n9 - Zakoncz program\n";
        cin >> structure_choice;
        switch (structure_choice)
        {
        case 1:
        {
            while (quit)
            {
                cout << "\nProsze wybrac wpisujac litere co chcesz zrobic w stosie z stl:\na - dodawanie losowego elementu na szczyt stosu\nb - dodawanie na stos m losowych elementów\nc - wyswietlanie element na szczycie stosu\nd - usuniecie elementu na szczycie stosu\ne - k razy usuniecie element ze szczytu stosu\nf - wyswietl liczbe elementów na stosie\nq - wroc do wyboru struktury" << endl;
                cin >> choice;
                switch (choice)
                {
                case 'a':
                {x = rand() % MAX_NUMB + MIN_NUMB;

                stackstl.push(x);

                }
                break;

                case 'b':
                {cout << "Prosze podac liczbe elementow ktore maja byc dodane" << endl;
                cin >> m;
                for (int i = 0; i < m; ++i)
                {
                    x = rand() % MAX_NUMB + MIN_NUMB;
                    stackstl.push(x);
                }
                }
                break;
                case 'c':
                {
                    if (!stackstl.empty())
                        cout << "Element na szczycie stosu to: " << stackstl.top() << endl;
                    else cout << "Stos jest pusty\n";
                }
                break;
                case 'd':
                {
                    if (!stackstl.empty()) stackstl.pop();
                    else cout << "Nie mozna usunac bo stos jest pusty\n";
                }
                break;
                case 'e':
                {
                    cout << "Prosze podac ile elementow ma zostac usunietych" << endl;
                    cin >> m;
                    for (int i = 0; i < m; ++i)
                    {

                        if (!stackstl.empty()) stackstl.pop();
                        else {
                            cout << "Kolejka jest juz pusta, nie mozna usunac wiecej elementow" << endl;
                            break;
                        }
                    }

                }
                break;
                case 'f':
                {
                    cout << "Ilosc elementow na stosie to:" << stackstl.size() << endl;
                }
                break;
                case 'q':
                {
                    quit = false;
                }
                break;
                default:
                {
                    cout << "Prosze wybrac poprawna opcje" << endl;
                }

                }
            }
            break;
        }
        case 2:
        {

            while (quit)
            {
                cout << "\nProsze wybrac wpisujac litere co chcesz zrobic na kolejce z stl:\na - dodanie losowego elementu na koniec kolejki\nb - dodaj l elementów na koniec kolejki\nc - usuniecie element z poczatku kolejki\nd - usuniecie k elementów z poczatku kolejki\ne - wyswietlenie pierwszego elementu kolejki\nf - wyswietlenie liczby elementów w kolejce\nq - wroc do wyboru struktury" << endl;
                cin >> choice;
                switch (choice)
                {
                case 'a':
                {
                    x = rand() % MAX_NUMB + MIN_NUMB;
                    queuestl.push(x);

                }
                break;
                case 'b':
                {cout << "Prosze podac liczbe elementow ktore maja byc dodane" << endl;
                cin >> m;
                for (int i = 0; i < m; ++i)
                {
                    x = rand() % MAX_NUMB + MIN_NUMB;
                    queuestl.push(x);
                }
                }
                break;
                case 'c':
                {if (!queuestl.empty()) queuestl.pop();
                else cout << "Kolejka jest pusta" << endl;
                }
                break;
                case 'd':
                {
                    cout << "Prosze podac ile elementow ma zostac usunietych" << endl;
                    cin >> m;
                    for (int i = 0; i < m; ++i)
                    {
                        if (!queuestl.empty()) queuestl.pop();
                        else {
                            cout << "Kolejka jest juz pusta, nie mozna usunac wiecej elementow" << endl;
                            break;
                        }
                    }
                }
                break;
                case 'e':
                {   if (!queuestl.empty())
                    cout << "Element na poczatku kolejki to: " << queuestl.front() << endl;
                else cout << "Kolejka nie ma elementow" << endl;

                }
                break;
                case 'f':
                {
                    cout << "Ilosc elementow w kolejce to: " << queuestl.size() << endl;
                }
                break;
                case 'q':
                {
                    quit = false;
                }
                break;
                default:
                {
                    cout << "Prosze wybrac poprawna opcje" << endl;
                }

                }
            }
            break;
        }
        case 3:
        {
            while (quit)
            {
                cout << "\nProsze wybrac wpisujac litere co chcesz zrobic na liscie z stl:\na - wyswietlanie zawartosci listy\nb - wyswietlenie liczby elementów listy\nc - wyswietlenie ostatniego elementu listy\nd - wyswietlenie pierwszego elementu listy\ne - dodanie losowego elementu na poczatku listy\nf - dodanie losowego elementu na koncu listy\ng - dodanie k elementów na poczatku listy\nh - dodanie l elementów na koncu listy\ni - usuwanie elementu na koncu listy\nj - usuwanie j elementów na koncu listy\nk - usuwanie wszystkich elementów z listy\nq - wroc do wyboru struktury" << endl;
                cin >> choice;
                switch (choice)
                {
                case 'a':
                {
                    if (!liststl.empty()) {
                        cout << "\nElementy:\n";
                        for (auto i = liststl.cbegin(); i != liststl.end(); ++i)
                            cout << *i << " ";
                    }
                    else cout << "Lista jest pusta\n";
                }
                break;

                case 'b':
                {
                    if (!liststl.empty())
                        cout << "Liczba elementow w liscie to: " << liststl.size() << endl;
                    else cout << "Lista jest pusta\n";
                }
                break;
                case 'c':
                {
                    if (!liststl.empty())
                        cout << "Ostatni element na liscie to: " << liststl.back() << endl;
                    else cout << "Lista jest pusta\n";

                }
                break;
                case 'd':
                {
                    if (!liststl.empty())
                        cout << "Pierwszy element na liscie to: " << liststl.front() << endl;
                    else cout << "Kolejka nie ma elementow" << endl;
                }
                break;
                case 'e':
                {
                    x = rand() % MAX_NUMB + MIN_NUMB;

                    liststl.push_front(x);
                }
                break;
                case 'f':
                {
                    x = rand() % MAX_NUMB + MIN_NUMB;

                    liststl.push_back(x);
                }
                break;
                case 'g':
                {
                    cout << "Prosze podac liczbe elementow ktore maja byc dodane" << endl;
                    cin >> m;
                    for (int i = 0; i < m; ++i)
                    {
                        x = rand() % MAX_NUMB + MIN_NUMB;
                        liststl.push_front(x);
                    }
                }
                break;
                case 'h':
                {
                    cout << "Prosze podac liczbe elementow ktore maja byc dodane" << endl;
                    cin >> m;
                    for (int i = 0; i < m; ++i)
                    {
                        x = rand() % MAX_NUMB + MIN_NUMB;
                        liststl.push_back(x);
                    }
                }
                break;
                case 'i':
                {
                    if (!liststl.empty()) liststl.pop_back();
                    else cout << "Kolejka jest pusta" << endl;
                }
                break;
                case 'j':
                {
                    if (!liststl.empty()) {
                        cout << "Prosze podac ile elementow ma zostac usunietych\n";
                        cin >> m;
                        if (m <= static_cast<signed int>(liststl.size())) {
                            
                            it1 = liststl.begin();
                            it2 = liststl.begin();

                            advance(it1, (liststl.size() - m ));
                            advance(it2, liststl.size());
 
                            liststl.erase(it1, it2);
                        }
                        else cout << "Lista ma tylko " << liststl.size() << " elementow, Prosze podac odpowiednia wartosc\n";
                    }
                    else cout << "Lista jest pusta\n";
                }
                break;
                case 'k':
                {
                    if (!liststl.empty()) {
                        it1 = liststl.begin();
                        it2 = liststl.begin();

                        advance(it2, liststl.size());
                        liststl.erase(it1, it2);
                    }
                    else cout << "Lista jest pusta\n";
                }
                break;
                case 'q':
                {
                    quit = false;
                }
                break;
                default:
                {
                    cout << "Prosze wybrac poprawna opcje" << endl;
                }

                }
            }
            break;
        }
        case 4:
        {
            while (quit)
            {
                cout << "\nProsze wybrac wpisujac litere co chcesz zrobic w stosie:\na - dodawanie elementu na szczyt stosu\nb - usuwanie elementu ze stosu\nc - wyswietlanie element na szczycie stosu\nd - sprawdzanie czy stos nie jest pusty\ne - wyswietlanie liczby elementów na stosie\nq - wroc do wyboru struktury" << endl;
                cin >> choice;
                switch (choice)
                {
                case 'a':
                {
                    cout << "Prosze podac element ktory ma byc dodany";
                    cin >> z;
                    my_stack.push(z);
                }
                break;

                case 'b':
                {
                    my_stack.pop();
                }
                break;
                case 'c':
                {
                    my_stack.show_top();
                }
                break;
                case 'd':
                {
                    if (my_stack.Empty()) cout << "Stos jest pusty\n";
                    else cout << "Stos nie jest pusty\n";
                }
                break;
                case 'e':
                {
                    cout << "Ilosc elementow na stosie to:" << my_stack.size() << endl;
                }
                break;
                case 'q':
                {
                    quit = false;
                }
                break;
                default:
                {
                    cout << "Prosze wybrac poprawna opcje" << endl;
                }

                }

            }
            break;
        }
        case 5:
        {
            while (quit)
            {
                cout << "\nProsze wybrac wpisujac litere co chcesz zrobic w kolejce:\na - dodanie elementu na koniec kolejki\nb - usuwanie elementu z kolejki\nc - sprawdzanie czy kolejka jest pusta\nd - wyswietlenie pierwszego elementu w kolejce\ne - wyswietlenie liczby elementów w kolejce\nq - wroc do wyboru struktury" << endl;
                cin >> choice;
                switch (choice)
                {
                case 'a':
                {
                    cout << "Prosze podac element ktory ma byc dodany";
                    cin >> z;
                    my_queue.enqueue(z);

                }
                break;
                case 'b':
                {
                    my_queue.dequeue();
                }
                break;
                case 'c':
                {
                    if (my_queue.Empty()) cout << "Kolejka jest pusta\n";
                    else cout << "Kolejka nie jest pusta\n";
                }
                break;
                case 'd':
                {
                    my_queue.front_elem();
                }
                break;
                case 'e':
                {
                    cout << "Ilosc elementow w kolejce to: " << my_queue.size() << endl;
                }
                break;
                case 'q':
                {
                    quit = false;
                }
                break;
                default:
                {
                    cout << "Prosze wybrac poprawna opcje" << endl;
                }

                }
            }
            break;
        }
        case 6:
        {
            while (quit)
            {
                cout << "\nProsze wybrac wpisujac litere co chcesz zrobic na jednokierunkowej liscie:\na - sprawdzenie czy lista jest pusta\nb - dodanie elementu do listy na poczatek\nc - dodanie elementu do listy na koniec\nd - wstawienie elementu do listy po elemencie z zadanym kluczem\ne - usuniecie poczatkowego elementu z listy\nf - usuniecie ostatniego elementu z listy\ng - usuniecie wybranego elementu z listy\nh - wyswietlenie zawartosci listy\ni - wyswietlenie pierwszego elementu\nj -wyswietlenie ostatniego elementu\nq - wroc do wyboru struktury" << endl;
                cin >> choice;
                switch (choice)
                {
                case 'a':
                {
                    if (my_singlylist.Empty()) cout << "Lista jest pusta\n";
                    else cout << "Lista nie jest pusta\n";
                }
                break;
                case 'b':
                {
                    cout << "Prosze podac element ktory ma byc dodany";
                    cin >> z;
                    my_singlylist.push_front(z);
                }
                break;
                case 'c':
                {
                    cout << "Prosze podac element ktory ma byc dodany";
                    cin >> z;
                    my_singlylist.push_back(z);

                }
                break;
                case 'd':
                {
                    cout << "Prosze podac klucz po ktorym ma byc wstawiony nowy element\n";
                    cin >> a;
                    cout << "Prosze podac element ktory ma byc dodany";
                    cin >> z;
                    my_singlylist.push_after_key(a, z);
                }
                break;
                case 'e':
                {
                   my_singlylist.pop_front();
                }
                break;
                case 'f':
                {
                   my_singlylist.pop_back();
                }
                break;
                case 'g':
                {
                        cout << "Prosze podac klucz wedlug ktorego zostanie usuniety element\n";
                        cin >> a;
                        my_singlylist.pop_key(a);
                }
                break;
                case 'h':
                {
                        my_singlylist.display();
                }
                break;
                case 'i':
                {
                        my_singlylist.display_first();
                }
                break;
                case 'j':
                {
                        my_singlylist.display_last();
                }
                break;
                case 'q':
                {
                    quit = false;
                }
                break;
                default:
                {
                    cout << "Prosze wybrac poprawna opcje" << endl;
                }

                }
            }
        }
        break;
        
            case 7:
            {
                    while (quit)
                    {
                        cout << "\nProsze wybrac wpisujac litere co chcesz zrobic na dwukierunkowej liscie:\na - sprawdzenie czy lista jest pusta\nb - dodanie elementu do listy na poczatek\nc - dodanie elementu do listy na koniec\nd - wstawienie elementu do listy po elemencie z zadanym kluczem\ne - usuniecie poczatkowego elementu z listy\nf - usuniecie ostatniego elementu z listy\ng - usuniecie wybranego elementu z listy\nh - wyswietlenie zawartosci listy\ni - wyswietlenie pierwszego elementu\nj -wyswietlenie ostatniego elementu\nq - wroc do wyboru struktury" << endl;
                        cin >> choice;
                        switch (choice)
                        {
                        case 'a':
                        {
                            if (my_doublylist.Empty()) cout << "Lista jest pusta\n";
                            else cout << "Lista nie jest pusta\n";
                        }
                        break;
                        case 'b':
                        {
                            cout << "Prosze podac element ktory ma byc dodany";
                            cin >> z;
                            my_doublylist.push_front(z);
                        }
                        break;
                        case 'c':
                        {
                            cout << "Prosze podac element ktory ma byc dodany";
                            cin >> z;
                            my_doublylist.push_back(z);

                        }
                        break;
                        case 'd':
                        {
                            cout << "Prosze podac klucz po ktorym ma byc wstawiony nowy element\n";
                            cin >> a;
                            cout << "Prosze podac element ktory ma byc dodany";
                            cin >> z;
                            my_doublylist.push_after_key(a, z);
                        }
                        break;
                        case 'e':
                        {
                            my_doublylist.pop_front();
                        }
                        break;
                        case 'f':
                        {
                            my_doublylist.pop_back();
                        }
                        break;
                        case 'g':
                        {
                            cout << "Prosze podac klucz wedlug ktorego zostanie usuniety element\n";
                            cin >> a;
                            my_doublylist.pop_key(a);
                        }
                        break;
                        case 'h':
                        {
                            my_doublylist.display();
                        }
                        break;
                        case 'i':
                        {
                            my_doublylist.display_first();
                        }
                        break;
                        case 'j':
                        {
                            my_doublylist.display_last();
                        }
                        break;
                        case 'q':
                        {
                            quit = false;
                        }
                        break;
                        default:
                        {
                            cout << "Prosze wybrac poprawna opcje" << endl;
                        }

                        }
                    }
                
            }
            break;
            case 8:
            {

                    while (quit)
                    {
                        cout << "\nProsze wybrac wpisujac litere co chcesz zrobic w kopcu:\na - budowa kopca na podstawie tablicy n losowych elementów\nb - przywracanie w³asnosci kopca\nc - dodanie elementu do kopca\nd - usuniecie korzenia kopca\ne - wyswietlenie rozmiaru kopca\nf - czytelne wyswietlanie kopca\nq - wroc do wyboru struktury" << endl;
                        cin >> choice;
                        switch (choice)
                        {
                        case 'a':
                        {
                            cout << "Prosze podaj liczbe elementow do zbudowania kopca\n";
                            cin >> m;
                            my_heap.build(m);

                        }
                        break;
                        case 'b':
                        {
                            my_heap.restore();
                        }
                        break;
                        case 'c':
                        {
                            cout << "Prosze podac element ktory ma zostac dodany\n";
                            cin >> a;
                            my_heap.push(a);
                        }
                        break;
                        case 'd':
                        {
                            my_heap.pop();
                        }
                        break;
                        case 'e':
                        {
                            cout << "Liczba poziomow kopca to: " << my_heap.size() << endl;
                        }
                        break;
                        case 'f':
                        {
                            my_heap.display();
                        }
                        break;
                        case 'q':
                        {
                            quit = false;
                        }
                        break;
                        default:
                        {
                            cout << "Prosze wybrac poprawna opcje" << endl;
                        }

                        }
                    }
                    break;
            }
            break;
            case 9:
            {
                end = false;
            }
            break;
            default:
            {
                cout << "Bledny numer, prosze wybrac ponownie poprawny numer" << endl;
            }
    }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
