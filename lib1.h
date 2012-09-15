// *********************************************************************
// DNI 1: 48460003-S Francisco Bernabeu Tovar
// DNI 2: 45567904-M Julian Nicolas Herrero
// *********************************************************************

//libreria lib1.h

#include <iostream>
#include <string>

using namespace std;


//ESTRUCTURAS
struct Telemento{
	string articulo;
	unsigned short int cantidad;
	float precio;
};


// DECLARACION DE CONSTANTES
const int kPASSWORD=1234, kTAMANYOARTICULOS=20, kTAMANYOTARJETA=12;
const float kCAMBIOPESETAS=166.386, kCAMBIODOLARES=1.22;
const string kM1="M1:OPCION INCORRECTA.";
const string kM2="M2:PASSWORD NO VALIDO.";
const string kM3="M3:HA AGOTADO LAS OPORTUNIDADES. ADIOS.";
const string kM4="M4:VALOR INCORRECTO. NO SE HA CAMBIADO LA MONEDA.";
const string kM5="M5:YA EXISTE EL ARTICULO.";
const string kM6="M6:ERROR. NO CABEN MAS ARTICULOS.";
const string kM7="M7:NO EXISTE EL ARTICULO.";
const string kM8="M8:COMPRA REALIZADA CON EXITO.";
const string kM9="M9:VALORES INCORRECTOS DE LA TARJETA O FECHA DE CADUCIDAD.";
const string kM10="M10:NO SE HA COMPRADO NINGUN ARTICULO.";


// PROTOTIPOS DE FUNCIONES
string DevolverNombreMoneda (int);
int CambiarMoneda (int &);
float ConvertirMoneda (int, int, float);
int IntroducirArticulo (string[], float[], int &, int);
int BorrarArticulo (string[], float[], int &);
int ModificarPrecioArticulo (string[], float[], int, int);
void OrdenarArticulosPorNombre (string[], float[], int);
void MostrarArticulos (string[], float[], int, int);
int AnyadirCarrito (string[], float[], int, Telemento[], int &, int);
void BorrarCarrito (int &);
void MostrarCarrito (Telemento[], int, int);
int Comprar (Telemento[], int &, int);







