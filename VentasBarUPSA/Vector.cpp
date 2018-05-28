#pragma once

#include <iostream>

using namespace std;

//T tipoElem;
const int MAX = 50;
template <class T>
public class Vector
{
private:
	T v[MAX];
	int n;

public:
	Vector()
	{
		n = 0;
	}

	void setElem(T x, int p) {
		v[p] = x;
	}

	T getElem(int p) {
		return v[p];
	}

	void setDim(int d) {
		n = d;
	}

	int getDim() {
		return n;
	}

	void leer();

	void imprimir();

	bool vacio()
	{
		return n == 0;
	}

	bool lleno()
	{
		return n == MAX;
	}

	void eliminarUlt(int p)
	{
		eliminar(n - 1);
	}

	void insertar(T x, int p);

	void insertarUlt(T x)
	{
		insertar(x, n);
	}

	void insertarPri(T x)
	{
		insertar(x, 0);
	}

	void eliminar(int p);

	void eliminarUlt()
	{
		eliminar(n - 1);
	}

	void eliminarPri()
	{
		eliminar(0);
	}


}; //end class
template <class T>
void Vector<T>::leer()
{
	int m;
	cout << "Cantidad de Clientes :";
	cin >> m;
	setDim(m);
	for (int i = 0; i<m; i++) {
		// crear el cliente
		char* dato1 = new char();  char* dato2 = new char(); char* dato3 = new char();
		cout << "ingrese nit :" << endl;
		cin >> dato1;
		cout << "ingrese nombre :" << endl;
		cin >> dato2;
		cout << "ingrese apellidos :" << endl;
		cin >> dato3;
		
		Persona personaAct(dato1, dato2, dato3, 'C');
		//Persona x("111", "manuel", "saavedra", 'C');
		//x.setNIT("111"); x.setNombres("manuel"); x.setApellidos("saavedra"); x.setTipo('C');
		//x = new Persona("111", "manuel", "saavedra", 'C');
		//cout << ":"; cin >> x;
		setElem(personaAct, i);
	}
}
template <class T>
void Vector<T>::imprimir()
{
	for (int i = 0; i<getDim(); i++) {
		cout << "NIT: " << getElem(i).getNIT() << ",		NOMBRES : " << getElem(i).getTipo() << endl;
	}
	cout << endl;
}
template <class T>
void Vector<T>::insertar(T x, int p) {
	if (p<0 || p >= n) {
		cout << "Posicion no valida...!!!";
		return;
	}
	if (lleno()) {
		cout << "Vector lleno...!!!";
		return;
	}
	int k = n - 1;
	while (k >= p) {
		v[k + 1] = v[k];
		k--;
	}
	v[p] = x;
	n = n + 1;
}

template <class T>
void Vector<T>::eliminar(int p) {
	if (p<0 || p >= n) {
		cout << "Posicion no valida...!!!";
		return;
	}
	if (vacio()) {
		cout << "Vector vacio...!!!";
		return;
	}
	int k = p + 1;
	while (k < n) {
		v[k - 1] = v[k];
		k++;
	}
	n = n - 1;
}