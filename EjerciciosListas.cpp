#include "EjerciciosListas.h"

/*
 *	FUNCION AUXILIAR
PRE: Recibe una lista l simplemente encadenada y un entero
POS: Agrega el entero al comienzo de la lista, modificando a esta ultima y no retorna nada

Ejemplo
Entrada: (1,2,3,4) 6
Retorno: (6,1,2,3,4)
*/
void insertarInicio(NodoLista* &l, int dato) {
	NodoLista* nuevo = new NodoLista();
	nuevo->dato = dato;
	nuevo->sig = l;
	l = nuevo;
}

NodoLista* invertirParcial(NodoLista* l) 
{
	if (l == NULL || l->sig == NULL) return NULL;
	NodoLista* ret = NULL;
	while (l->sig != NULL) {
		insertarInicio(ret, l->dato);
		l = l->sig;
	}
	return ret;
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) // paso test
{
	if (lista == NULL || n <= 0) return;
	eliminarNesimoDesdeElFinal(lista->sig, n);
	n--;
	if (n == 0) {
		NodoLista *aBorrar = lista;
		lista = lista->sig;
		delete aBorrar;
	}
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	// IMPLEMENTAR SOLUCION
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

/*
 *	FUNCION AUXILIAR
PRE: Recibe una lista l simplemente encadenada
POS: Retorna una nueva lista con la mismas cantidad de nodos que l, con los mismos datos y en mismo orden,
	 sin compartir memoria

Ejemplo
Entrada: (1,2,3,4)
Retorno: (1,2,3,4)
*/
NodoLista* copiarLista(NodoLista* l) {
	return NULL;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	//if (l1 == NULL) {
	//	NodoLista* ret = new NodoLista;
	//	
	//	while (l2->sig != NULL) {
	//		
	//	}
	//}
	return NULL;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
