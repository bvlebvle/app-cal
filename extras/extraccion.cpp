#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

void modificar_pregunta(string &pregunta)
{
	bool first = true;

	for (int i = 0; i < pregunta.size(); i++)
	{
		if (pregunta[i] == '$')
		{
			pregunta[i] = '\\';
			if (first)
			{
				pregunta.insert(i + 1, 1, '(');
				first = false;
			}
			else
			{
				pregunta.insert(i + 1, 1, ')');
			}
		}
	}
}

int main()
{
	ifstream archivo("main.tex");
	string pregunta, alternativa_a, alternativa_b, alternativa_c, alternativa_d;
	string linea;
	int a = 0, b = 0, c = 0;
	if (archivo.is_open())
	{

		while (getline(archivo, linea))
		{
			if (linea.find("Pregunta") != string::npos)
			{
				getline(archivo, pregunta);
				cout << pregunta << endl;
			}
			if (linea.find("Alternativa-A") != string::npos)
			{
				getline(archivo, alternativa_a);
				cout << alternativa_a << endl;
			}
			if (linea.find("Alternativa-B") != string::npos)
			{
				getline(archivo, alternativa_b);
				cout << alternativa_b << endl;
			}
			if (linea.find("Alternativa-C") != string::npos)
			{
				getline(archivo, alternativa_c);
				cout << alternativa_c << endl;
			}
			if (linea.find("Alternativa-D") != string::npos)
			{
				getline(archivo, alternativa_d);
				cout << alternativa_d << endl;
			}
		}
		archivo.close();

		modificar_pregunta(pregunta);

		ofstream archivo_salida("pregunta_salida.txt");
		if (archivo_salida.is_open())
		{
			archivo_salida << pregunta << endl;
			archivo_salida << alternativa_a << endl;
			archivo_salida << alternativa_b << endl;
			archivo_salida << alternativa_c << endl;
			archivo_salida << alternativa_d << endl;
			archivo_salida.close();
		}
		else
			cout << "No se pudo crear el archivo" << endl;
	}
	return 0;
}