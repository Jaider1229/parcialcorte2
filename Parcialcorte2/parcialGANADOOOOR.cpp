#include <iostream>

#include <stdio.h>


using namespace std;

struct Nodo {
    int dato, prio;
    Nodo *siguiente;
};


void insertarpila(Nodo *&, int, int);
void mostrarpilas(Nodo *);
void eliminar(Nodo *&, int);
void insertarcola(Nodo *&, Nodo *&, int, int);
void mostrarcolas(Nodo *);
void eliminar(Nodo *&,Nodo *&,int);
void menu();

Nodo *frente = NULL;
Nodo *fin = NULL;
Nodo *pila = NULL;

int main()
{
    menu();
    
    return 0;
    
}

void menu() {
    int opcion;

    do {
        cout << "\t. MENU \n";
        cout << "\n1. Para Ingresar a Pilas ";
        cout << "\n2. Para Ingresar a Colas ";
        cout << "\n3. Salir";
        cout << "\nOpcion:  ";
        cin >> opcion;

        switch (opcion) {
            case 1:
            	
                while(opcion = 1){
                 cout<<"Usted Esta en el menu de pilas:  "<<endl;
                 
                     int opcion2, dato, prio, prioridadEliminar;

                     do {
                    cout << "\n \t. MENU \n"<<endl;
                    cout << "\n1. Ingresar un numero";
                    cout << "\n2. Eliminar un numero por prioridad";
                    cout << "\n3. Mostrar los datos";
                    cout << "\n4. Salir";
                    cout << "\nOpcion:   ";
                    cin >> opcion2;
                    
                    switch (opcion2) {
                            case 1:
                            cout << "Ingresar un numero: ";
                            cin >> dato;
        
                            cout << "Ingresar una prioridad: ";
                            cin >> prio;
        
                            insertarpila(pila, dato, prio);
                            break;
        
                            case 2:
                            cout << "Ingrese la prioridad que desea eliminar: ";
                            cin >> prioridadEliminar;
                             eliminar(pila, prioridadEliminar);
                                break;
        
                             case 3:
                             cout << "La lista de numeros ingresados es:   ";
                             mostrarpilas(pila);
                            break;
                            }
                            
                            cout << "\t. MENU \n";
                            cout << "\n1. Desea segir en pilas ";
        		            cout << "\n2. Para Ingresar a Colas ";
        		         	cout << "\n3. Salir";
        					cout << "\nOpcion:  ";
        					cin >> opcion;
        
                         } while (opcion2 != 4);
                    }
                  
                
            case 2:
            	
                while(opcion = 2){
                	 cout<<"Usted Esta en el menu de colas:  "<<endl;
                	 
                       int opcion2, dato, prio, prioridadEliminar;

                            do {
                                cout << "\n\t. MENU \n"<<endl;
                                cout << "\n1. Ingresar un numero";
                                cout << "\n2. Eliminar un numero por prioridad";
                                cout << "\n3. Mostrar los datos";
                                cout << "\n4. Salir";
                                cout << "\nOpcion:   ";
                                cin >> opcion2;
                        
                                switch (opcion2) {
                                    case 1:
                                        cout << "Ingresar un numero: ";
                                        cin >> dato;
                        
                                        cout << "Ingresar una prioridad: ";
                                        cin >> prio;
                        
                                        insertarcola(frente, fin, dato, prio);
                                        break;
                        
                                    case 2:
                                        cout << "Ingrese la prioridad que desea eliminar: ";
                                        cin >> prioridadEliminar;
                                        eliminar(frente, fin, prioridadEliminar);
                                        break;
                        
                                    case 3:
                                        cout << "La lista de numeros ingresados es:   ";
                                        mostrarcolas(frente);
                                        break;
                                }
                            } while (opcion2 != 4);
                       }
                 break;
                
             }
    } while (opcion != 3);
  }
void insertarpila(Nodo *&pila, int n, int p) {
    Nodo *pilas = new Nodo();
    pilas->dato = n;
    pilas->prio = p;
    pilas->siguiente = pila;
    pila = pilas;

    cout << "Se ingreso el numero " << pilas->dato << " con una prioridad de: " << pilas->prio;
}

void mostrarpilas(Nodo *pila) {
    Nodo *actual = pila;

    while (actual != NULL) {
        cout << actual->dato << " - " << actual->prio << " -> ";
        actual = actual->siguiente;
    }
}

void eliminar(Nodo *&pila, int prioridadEliminar) {
    if (pila != NULL) {
        Nodo *aux = pila;
        Nodo *ant = NULL;

        while (aux != NULL) {
            if (aux->prio == prioridadEliminar) {
                if (ant == NULL) {
                    pila = aux->siguiente;
                } else {
                    ant->siguiente = aux->siguiente;
                }
                delete aux;
                cout << "Se eliminaron todos los nodos con prioridad " << prioridadEliminar << endl;
                return;
            }
            ant = aux;
            aux = aux->siguiente;
        }
        cout << "No se encontraron nodos con la prioridad especificada" << endl;
    } else {
        cout << "La pila está vacía" << endl;
    }
}

void insertarcola(Nodo *&frente, Nodo *&fin, int n, int p) {
    Nodo *nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->prio = p;
    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
    } else {
        fin->siguiente = nuevo;
    }

    fin = nuevo;

    cout << "Se ingreso el numero " << nuevo->dato << " con una prioridad de: " << nuevo->prio << endl;
}

void mostrarcolas(Nodo *frente) {
    Nodo *actual = frente;

    while (actual != NULL) {
        cout << actual->dato << " - " << actual->prio << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void eliminar(Nodo *&frente, Nodo *&fin, int prioridadEliminar) {
    if (frente != NULL) {
        Nodo *aux = frente;
        Nodo *ant = NULL;

        while (aux != NULL) {
            if (aux->prio == prioridadEliminar) {
                if (ant == NULL) {
                    frente = aux->siguiente;
                } else {
                    ant->siguiente = aux->siguiente;
                }
                delete aux;
                cout << "Se eliminaron todos los nodos con prioridad " << prioridadEliminar << endl;
                return;
            }
            ant = aux;
            aux = aux->siguiente;
        }
        cout << "No se encontraron nodos con la prioridad especificada" << endl;
    } else {
        cout << "La cola está vacía" << endl;
    }
}

