#include "EjerciciosComienzo.h"

int suma(int a, int b) {
    return a + b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) { // paso tests
	for (int i = desde; i <= hasta; i++) {
		cout << i << "*" << tablaDel << "=" << i * tablaDel;
		if (i != hasta) cout << ";";
	}
	cout << endl;
}

/*
PRE: Recibe dos enteros positivos
POS: Imprime el máximo común divisor entre los dos números
*/
int mcdEuclides(int n, int d) { // funcion aux
	int* mayor;
	int* menor;
	if (n > d) {
		mayor = &n;
		menor = &d;
	}
	else {
		mayor = &d;
		menor = &n;
	}
	if ((*mayor % *menor) == 0) {
		return *menor;
	}
	else {
		return mcdEuclides(*menor, *mayor % *menor);
	}
}

/*
PRE:  Recibe un entero
POS:  Devuelve el valor absoluto de ese número
	  */
int valorAbsoluto(int n) {
	if (n < 0) return -1 * n;
	return n;
}

void simplificar(int n, int d) {
	if (n == 0) {
		cout << n << "/" << d << endl;
		return;
	}
	bool esNegativo = n * d < 0;
	n = valorAbsoluto(n);
	d = valorAbsoluto(d);
	int mcd = mcdEuclides(n, d);
	n /= mcd;
	d /= mcd;
	
	if (esNegativo) cout << "-";
	cout << n << "/" << d << endl;
}

int ocurrencias123Repetidos(int* vector, int largo) { // paso tests
	int ocurrencias = 0;
	int estado = 0;
	for (int i = 0; i < largo; i++) {
		if (vector[i] == estado) continue;

		if (vector[i] == estado + 1) {
			estado++;
			if (estado == 3) {
				ocurrencias++;
				estado = 0;
			}
		}
		else {
			estado = 0;
		}
	}
	return ocurrencias;
}

int maximoNumero(unsigned int n) { //paso test
	int maximo;
	cin >> maximo;
	n--;
	while (n--) {
		int valor;
		cin >> valor;
		if (valor > maximo) maximo = valor;
	}
    return maximo;
}

void ordenarVecInt(int *vec, int largoVec) { //paso test
	for (int i = 0; i < largoVec - 1; i++) {
		for (int j = 0; j < largoVec - 1 - i; j++) {
			if (vec[j] > vec[j + 1]) {
				int temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){ // paso test
	int l3 = l1 + l2;
	if (l3 == 0) return NULL;
	int* v3 = new int[l3];
	int p1 = 0;
	int p2 = 0;
	for (int i = 0; i < l3; i++) {
		if (p1 >= l1) {
			v3[i] = v2[p2];
			p2++;
			continue;
		}
		else if (p2 >= l2){
			v3[i] = v1[p1];
			p1++;
			continue;
		}

		if (v1[p1] > v2[p2]) {
			v3[i] = v2[p2];
			p2++;
		}
		else {
			v3[i] = v1[p1];
			p1++;
		}
	}
	return v3;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2) // paso test
{
	bool esSubConjunto = true;
	for (int i = 0; i < l1 && esSubConjunto; i++) {
		bool esta = false;
		for (int j = 0; j < l2 && !esta; j++) {
			if (v1[i] == v2[j]) esta = true;
		}
		if (!esta) esSubConjunto = false;
	}
	return esSubConjunto;
}

char* invertirCase(char* str) // da error al compilar por alguna razon
{
	//int i = 0;
	//while (str[i] != '\0') {
	//	if (str[i] >= 'a' && str[i] <= 'z') {
	//		int valor = (int)str[i];
	//		valor -= 32;
	//		str[i] = (char)valor;
	//	}
	//	else if (str[i] >= 'A' && str[i] <= 'Z') {
	//		int valor = (int)str[i];
	//		valor += 32;
	//		str[i] = (char)valor;
	//	}
	//	i++;
	//}
	//return str;
	return NULL;
}
/*
PRE:  Recibe un mapa representado por una matriz, de dimensiones col x fil, en la cual 'A' representa un lugar donde hay agua, y 'T' donde hay tierra
	  también recibe cuatro enteros, los primeros dos son las coordenadas (indices) de una 'T' y los siguientes dos son la cantidad de columnas y filas
	  que tiene el mapa respectivamente.
POS:  Modifica al mapa que se le ha pasado "explorando" toda la isla en la que se encuentre la 'T' que se le ha pasado, donde se encuentre una 'T',
	  se pondrá una 'A'.
	  */
void explorarIsla(char** mapa, int i, int j, int col, int fil) { // funcion aux
	mapa[i][j] = 'A';
	for (int k = i - 1; k <= i + 1; k++) {
		for (int l = j - 1; l <= j + 1; l++) {
			if (k >= 0 && k < col && l >= 0 && l < fil) {
				if (mapa[k][l] == 'T') {
					explorarIsla(mapa, k, l, col, fil);
				}
			}

		}
	}
}

int islas(char** mapa, int col, int fil){ //paso test
	char** copiaMapa = new char*[col];

	for (int i = 0; i < col; i++) {
		copiaMapa[i] = new char[fil];
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < fil; j++) {
			copiaMapa[i][j] = mapa[i][j];
		}
	}
	int cantIslas = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < fil; j++) {
			if (copiaMapa[i][j] == 'T') {
				cantIslas++;
				explorarIsla(copiaMapa, i, j, col, fil);
			}
		}
	}
	for (int i = 0; i < col; i++) {
		delete[] copiaMapa[i];
	}
	delete[] copiaMapa;
    return cantIslas;
}
/*
PRE: Recibe dos strings

POS: Devuelve en forma de booleano si el segundo string que se le pasa es un subString del primero 
*/
bool esSubstring(char* str, char* substr) { // funcion aux
	int largosubstr = 0;
	for (int z = 0; substr[z] != '\0'; z++) {
		largosubstr++;
	}

	int vanSeguidas = 0;
	for (int j = 0; j < largosubstr; j++) {
		for (int i = j; str[i] != '\0'; i++) {
			if (str[i] == substr[vanSeguidas]) {
				vanSeguidas++;
				if (vanSeguidas == largosubstr) {
					return true;
				}
			}
			else {
				vanSeguidas = 0;
			}
		}
	}
	
	return false;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)  // paso test
{
	int ocurrencias = 0;
	for (int i = 0; i < largoVecStr; i++) {
		if (esSubstring(vecStr[i], substr)) ocurrencias++;
	}
    return ocurrencias;
}
/*
PRE: Recibe dos strings

POS: Copia todos los caracteres del primer string al segundo, incluyendo el '\0'
*/
void copiarString(char* strOrigen, char* strDestino) { //funcion aux
	int i = 0;
	while (strOrigen[i] != '\0') {
		strDestino[i] = strOrigen[i];
		i++;
	}
	strDestino[i] = '\0';
}

/*
PRE: Recibe un string

POS: Devuelve el largo del string incluyendo al caracter '\0'
*/
int largoString(char* str) { //función aux
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	i++;
	return i;
}

/*
PRE: Recibe dos strings

POS: Devuelve true si el primer string "precede al segundo", en otro caso devuelve false
*/
bool ordenStr(char* str1, char* str2) { // funcion aux
	int i = 0;
	while (true) {
		if (str1[i] == '\0' || str2[i] == '\0') return false;
		if (str1[i] < str2[i]) return true;
		if (str1[i] > str2[i]) return false;
		i++;
	}
	return false;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	char** nuevoVecStr = new char* [largoVecStr]; // array de strings a retornar ordenado

	bool* indicesUsados = new bool[largoVecStr]; // array para ir marcando los indices que ya movi, para hacer como un inserction sort virtual
	for (int i = 0; i < largoVecStr; i++) {
		indicesUsados[i] = false;
	}

	int indiceDestino = 0;
	while (indiceDestino < largoVecStr) {
		int menorIndiceActual = 0;

		for (int i = 0; i < largoVecStr; i++) {
			bool indiceUsado = indicesUsados[i];
			if (!indiceUsado && ordenStr(vecStr[i], vecStr[menorIndiceActual])) menorIndiceActual = i;
		}

		nuevoVecStr[indiceDestino] = new char [largoString(vecStr[menorIndiceActual])];
		copiarString(vecStr[menorIndiceActual], nuevoVecStr[indiceDestino]);
		indiceDestino++;
	}

	delete[] indicesUsados;
	return nuevoVecStr;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}
