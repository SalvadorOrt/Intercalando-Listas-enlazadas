#include <iostream>
#include<conio.h>
using namespace std;

class Nodo {
    public:
        int elemento;
        Nodo* next;
        Nodo(int dato) {
            this->elemento = dato;
            this->next = nullptr;
        }
};
class Lista {
public:
    Nodo* head;
    Nodo* tail;
    int length;
    Lista() {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }
    void print() {
        Nodo* temp = this->head;

        while (temp != nullptr) {
            cout << temp->elemento<<" ";
            if (temp->next) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl<<endl;
    }
    bool append(int dato) {
        Nodo* nodo = new Nodo(dato);
        if (this->length == 0) {
            this->head = nodo;
            this->tail = nodo;
        }
        else {
            this->tail->next = nodo;
            this->tail = nodo;
        }
        this->length++;
        return true;
    }
    Lista* intercalar(Lista lista) {
        Lista* lista_intercalada = new Lista();
        Nodo* temp1 = this->head;
        Nodo* temp2 = lista.head;
        if (this->length == lista.length) {//la longitud de las 2 listas tienen la misma dimension
            cout << "dimesion igual: ";
            while ((temp1 != nullptr)and (temp2 != nullptr)) {
                lista_intercalada->append(temp1->elemento);
                lista_intercalada->append(temp2->elemento);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            
        }
        if (this->length > lista.length) {//la longitud de la lista implicita es mayor al parametro
            cout << "dimesion de la lista implicita es mayor: ";
            while (temp1 != nullptr) {
                lista_intercalada->append(temp1->elemento);
                temp1 = temp1->next;
            }
            while (temp2 != nullptr) {
                lista_intercalada->append(temp2->elemento);
                temp2 = temp2->next;
            }
        }
        if (this->length < lista.length) {//la longitud de la lista implicita es menor al parametro
            cout << "dimesion de la lista implicita es menor: ";
            while (temp2 != nullptr) {
                lista_intercalada->append(temp2->elemento);
                temp2 = temp2->next;
            }
            while (temp1 != nullptr) {
                lista_intercalada->append(temp1->elemento);
                temp1 = temp1->next;
            }
        }
        return lista_intercalada;
    }
};
int main() {
    Lista* lista1 = new Lista();
    Lista* lista2 = new Lista();

    Lista* lista3 = new Lista();
    Lista* lista4 = new Lista();


    Lista* lista5 = new Lista();
    Lista* lista6 = new Lista();

    

    Lista* lista_intercalada_dimesion_igual = new Lista();
    Lista* lista_intercalada_dimesion_implicita_mayor = new Lista();
    Lista* lista_intercalada_dimesion_implicita_menor = new Lista();
    lista1->append(1);
    lista1->append(2);
    lista1->append(3);
    lista1->append(4);
    lista1->append(5);
    lista1->print();
    lista2->append(0);
    lista2->append(9);
    lista2->append(8);
    lista2->append(7);
    lista2->append(6);
    lista2->print();
    lista_intercalada_dimesion_igual = lista1->intercalar(*lista2);
    lista_intercalada_dimesion_igual->print();

    lista3->append(1);
    lista3->append(2);
    lista3->append(3);
    lista3->append(4);
    lista3->append(5);
    lista3->print();
    lista4->append(1);
    lista4->append(2);
    lista4->append(3);
    lista4->print();
    lista_intercalada_dimesion_implicita_mayor = lista3->intercalar(*lista4);
    lista_intercalada_dimesion_implicita_mayor->print();
    lista5->append(1);
    lista5->append(2);
    lista5->append(3);
    lista5->print();
    lista6->append(1);
    lista6->append(2);
    lista6->append(3);
    lista6->append(4);
    lista6->append(5);
    lista6->print();
    lista_intercalada_dimesion_implicita_menor = lista5->intercalar(*lista6);
    lista_intercalada_dimesion_implicita_menor->print();

    system("pause");
}

