#include <iostream>
#include <fstream>
using namespace std;

int main()
{int n;
    cout << "Cuanto numeros quieres generar: ";
    cin >> n;
    //---- ahora gereneramos los valores al azar
    srand(time(nullptr));

    fstream objeto("numeros.txt", ios::out);
    for( int i=0; i<n; i++)
        objeto << rand() % 100 << "\n";
    objeto.close();

    //--- Ahora vamos a leer datos del archivo numeros.txt
    //-- y generamos dos nuevos archivos:
    //--  pares.txt   que contendra solo los numeros pares de numeros.txt
    //--  imparares.txt que contendra solo los numeros impares de numeros.txt
    fstream oFuente("numeros.txt", ios::in);   //-- abrimos el archivo para leer datos
    fstream aDePares("pares.txt", ios::out); //--- se abre el archivo para escribir datos
    fstream aDeImpares( "impares.txt", ios::out);  //--- se abre el archivo para escribir

    int dato;
    while( oFuente >> dato)
    {
        if( dato % 2 ==0)
            aDePares << dato << "\n";
        else
            aDeImpares << dato << "\n";
    }

    oFuente.close();
    aDePares.close();
    aDeImpares.close();
}
