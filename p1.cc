// *********************************************************************
// DNI 1: 48460003-S Francisco Bernabeu Tovar
// DNI 2: 45567904-M Julian Nicolas Herrero
// *********************************************************************

//Programa Principal

#include "lib1.h"
using namespace std;
int main(){
int op_principal,op_propietario,op_cliente,moneda=1,pasw,cont_pasw=1,numArticulos=0,elemCarrito=0;
string nombreArticulos[kTAMANYOARTICULOS];
float precioArticulos[kTAMANYOARTICULOS];
Telemento carrito[kTAMANYOARTICULOS];
do {
	cout<<endl;
	cout<<"BIENVENIDO A LA TIENDA VIRTUAL"<<endl;
	cout<<"=============================="<<endl;
	cout<<"POR FAVOR INTRODUZCA EL PERFIL DEL USUARIO:"<<endl;
	cout<<"\t1. PROPIETARIO TIENDA VIRTUAL"<<endl;
	cout<<"\t2. CLIENTE"<<endl;
	cout<<"\t0. SALIR"<<endl;
	cout<<"PULSE UNA OPCION:";
	cin>>op_principal;
	cin.get();
	if ((op_principal!=0)&&(op_principal!=1)&&(op_principal!=2))
		cout<<kM1<<endl;
	switch(op_principal){
	case 1: do {
			cout<<"INTRODUZCA EL PASSWORD:";
			cin>>pasw;
			if (pasw!=kPASSWORD) {
				cout<<kM2<<endl;
				cont_pasw++;
			}
		}
		while ((pasw!=kPASSWORD)&&(cont_pasw<=3));
		if ((cont_pasw==4)&&(pasw!=kPASSWORD)){
			cout<<kM3<<endl;
			op_principal=0;
		}
		else {
			do {
				cout<<endl;
				cout<<"MENU PRINCIPAL DEL PROPIETARIO DE LA TIENDA"<<endl;
				cout<<"==========================================="<<endl;
				cout<<"\t1. Cambiar de moneda (moneda actual: "<<DevolverNombreMoneda(moneda)<<")"<<endl;
				cout<<"\t2. Introducir articulo"<<endl;
				cout<<"\t3. Borrar articulo"<<endl;
				cout<<"\t4. Modificar el precio del articulo"<<endl;
				cout<<"\t5. Ordenar articulos por nombre"<<endl;
				cout<<"\t6. Mostrar articulos"<<endl;
				cout<<"\t0. Volver al menu principal"<<endl;
				cout<<"Pulse una opcion:";
				cin>>op_propietario;
				cin.get();
				switch (op_propietario) {
				case 1: if (CambiarMoneda(moneda)==1)
							cout<<kM4<<endl;
				break;
				case 2: switch  (IntroducirArticulo(nombreArticulos,precioArticulos,numArticulos,moneda)){
					case 1: cout<<kM5<<endl;
					break;
					case 2: cout<<kM6<<endl;
					break;
					}
				break;
				case 3: if ((BorrarArticulo(nombreArticulos,precioArticulos,numArticulos)==1))
						cout<<kM7<<endl;
				break;
				case 4: if (ModificarPrecioArticulo(nombreArticulos,precioArticulos,numArticulos,moneda)==1)
						cout<<kM7<<endl;
				break;
				case 5: OrdenarArticulosPorNombre(nombreArticulos,precioArticulos,numArticulos);
				break;
				case 6: MostrarArticulos(nombreArticulos,precioArticulos,numArticulos,moneda);
				break;
				case 0: cout<<endl; break;
				default: cout<<kM1<<endl;
				}
			}
			while (op_propietario!=0);
		}
	break;
	case 2: do {
			cout<<endl;
			cout<<"MENU PARA LOS CLIENTES DE LA TIENDA VIRTUAL"<<endl;
			cout<<"==========================================="<<endl;
			cout<<"\t1. Mostrar articulos"<<endl;
			cout<<"\t2. Anyadir articulo al carrito"<<endl;
			cout<<"\t3. Borrar carrito"<<endl;
			cout<<"\t4. Mostrar carrito"<<endl;
			cout<<"\t5. Comprar"<<endl;
			cout<<"\t0. Volver al menu principal"<<endl;
			cout<<"Pulse una opcion:";
			cin>>op_cliente;
			cin.get();
			switch (op_cliente) {
			case 1: MostrarArticulos(nombreArticulos,precioArticulos,numArticulos,moneda);
			break;
			case 2: switch(AnyadirCarrito(nombreArticulos,precioArticulos,numArticulos,carrito,elemCarrito,moneda)){
					case 1: cout<<kM7<<endl;
					break;
					case 2: cout<<kM6<<endl;
					break;
					}
			break;
			case 3: BorrarCarrito(elemCarrito);
			break;
			case 4: MostrarCarrito(carrito,elemCarrito,moneda);
			break;
			case 5: switch (Comprar(carrito,elemCarrito,moneda)){
					case 0: cout<<kM8<<endl;
					break;
					case 1: cout<<kM9<<endl;
					break;
					case 2: cout<<kM10<<endl;
					break;
				}
			break;
			case 0: cout<<endl;
			break;
			default: cout<<kM1<<endl;
			}
		}
		while (op_cliente!=0);
	break;
	case 0: cout<<"SALIDA CORRECTA DEL PROGRAMA."<<endl; break;
	}
}
while (op_principal!=0);
return (op_principal);
}





