/*Tarea tercer corte 
Autores: Yesika Ramirez - Ashley Ropero
ALSE GRUPO 5*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Puntos {
	//En esta clase se piden los puntos al usuario (Clase Base)
	// X1R1 significa coordenada x del punto 1 de la recta 1
	protected:
	float X1R1, Y1R1, X2R1, Y2R1, X1R2, Y1R2, X2R2, Y2R2;
	
	public:
	void leerpuntos() {
		cout << "Con este programa puedes saber el punto de intersección \nentre dos rectas por medio de dos puntos por recta"<<endl;
		cout << "Ingrese los puntos de la primera recta: \nPunto 1 \nCoordenada X: ";
		cin >> X1R1;
		cout << "Coordenada Y: ";
		cin >> Y1R1;
		cout << "Punto 2 \nCoordenada X: ";
		cin >> X2R1;
		cout << "Coordenada Y: ";
		cin >> Y2R1;
		cout << "Ingrese los puntos de la segunda recta: \nPunto 1 \nCoordenada X: ";
		cin >> X1R2;
		cout << "Coordenada Y: ";
		cin >> Y1R2;
		cout << "Punto 2 \nCoordenada X: ";
		cin >> X2R2;
		cout << "Coordenada Y: ";
		cin >> Y2R2;
		}
		
}; 

class Recta : public Puntos
{		//En esta clase se realizan los calculos y se imprime el resultado (Clase Derivada)
		private:
		float mrect1, mrect2, perpen1, perpen2, corterect1, corterect2, resul, resul1, interX, interY;
		public:
		void calculos(){
			//PENDIENTES DE LAS DOS RECTAS
			mrect1= (Y2R1 - Y1R1)/(X2R1 - X1R1);
			mrect2= (Y2R2 - Y1R2)/(X2R2 - X1R2);
			//SE INVIERTEN Y MULTIPLICAN POR MENOS LAS PARA COMPARARLAS (perpendicular)
			perpen1= -1/mrect2;
			perpen2= -1/mrect1;
			//CORTES CON EJE Y 
			corterect1 = Y1R1 - (X1R1*mrect1); 
			corterect2 = Y1R2 - (X1R2*mrect2);
			//PUNTO DE INTERSECCION
			interX = (corterect2 - corterect1)/(mrect1 - mrect2);
			interY = mrect2*interX + corterect2;
		}
			
		void imprimeresultado()
		{	
			calculos();
			if (mrect1 == mrect2){
			cout << "Son rectas PARALELAS, no existe punto de intersección"<< endl;
			}else if (mrect1 == perpen1 && mrect2 == perpen2){
				cout << "Las rectas son PERPENDICULARES\n";
				cout << "El punto de intersección es: (" << interX << "," << interY << ")"<<endl;
			}else {
				cout << "El punto de intersección es: (" << interX << "," << interY << ")"<<endl;
			}
			cout << "La ecuación de la recta 1 es: Y= " << mrect1 << "X + " << corterect1 <<endl;
			cout << "La ecuación de la recta 2 es: Y= " << mrect2 << "X + " << corterect2 <<endl;
		}
};

int main ()
{
	Recta rt;
	rt.leerpuntos();
	rt.imprimeresultado();	
}
