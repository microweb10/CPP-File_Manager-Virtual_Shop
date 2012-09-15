// *********************************************************************
// DNI 1: 48460003-S Francisco Bernabeu Tovar
// DNI 2: 45567904-M Julian Nicolas Herrero
// *********************************************************************

//funciones lib1.cc

#include "lib1.h"

using namespace std;


//funcion DevolverNombreMoneda
string DevolverNombreMoneda(int moneda){
	string nombremoneda;
	switch(moneda) {
	case 1: nombremoneda="EUROS";break;
	case 2: nombremoneda="PESETAS";break;
	case 3: nombremoneda="DOLARES";break;
	}
return(nombremoneda);
}


//funcion CambiarMoneda
int CambiarMoneda(int &moneda){
	int aux;
	cout<<"INTRODUZCA NUEVA MONEDA (1-EUROS, 2-PESETAS, 3-DOLARES): ";
	cin>>aux;
	if ((aux<1)||(aux>3))
		aux=1;
	else {
		moneda=aux;
		aux=0;
	}
return(aux);
}


//funcion ConvertirMoneda
float ConvertirMoneda (int origen, int destino, float precio){
	switch (origen){
	case 1: if (destino==2)
			precio=precio*kCAMBIOPESETAS;
		else
			precio=precio*kCAMBIODOLARES;
		break;
	case 2: if (destino==1)
			precio=precio/kCAMBIOPESETAS;
		else
			precio=precio/kCAMBIOPESETAS*kCAMBIODOLARES;
		break;
	case 3: if (destino==1)
			precio=precio/kCAMBIODOLARES;
		else
			precio=precio/kCAMBIODOLARES*kCAMBIOPESETAS;
		break;
	}
return (precio);
}


//funcion IntroducirArticulo
int IntroducirArticulo (string nombreArticulos[], float precioArticulos[], int &numArticulos, int moneda){
	int aux=2,i=0;
	string articulo;
	float precio;
	if (numArticulos<kTAMANYOARTICULOS){
		cout<<"NUEVO ARTICULO"<<endl;
		cout<<"=============="<<endl;
		cout<<"NOMBRE: ";
		getline (cin,articulo);
		while ((i<numArticulos)&&(articulo!=nombreArticulos[i]))
			i++;
		if (i!=numArticulos)
			aux=1;
		else {
			nombreArticulos[numArticulos]=articulo;
			cout<<"PRECIO ("<<DevolverNombreMoneda(moneda)<<"): ";
			cin>>precio;
			if (moneda != 1)
				precioArticulos[numArticulos]=ConvertirMoneda(moneda,1,precio);
			else
				precioArticulos[numArticulos]=precio;
			numArticulos++;
			aux=0;
		}
	}
return (aux);
}


//funcion BorrarArticulo
int BorrarArticulo (string nombreArticulos[], float precioArticulos[], int &numArticulos){
	int aux,i=0;
	string nombre;
	cout<<"BORRAR ARTICULO"<<endl;
	cout<<"==============="<<endl;
	cout<<"NOMBRE: ";
	getline (cin,nombre);
	while ((i<numArticulos)&&(nombre!=nombreArticulos[i]))
		i++;
	if (i==numArticulos)
		aux=1;
	else {
		for (i;i<numArticulos-1;i++){
			nombreArticulos[i]=nombreArticulos[i + 1];
			precioArticulos[i]=precioArticulos[i + 1];
		}
		numArticulos--;
		aux=0;
	}
return (aux);
}


//funcion ModificarPrecioArticulo
int ModificarPrecioArticulo (string nombreArticulos[], float precioArticulos[], int numArticulos, int moneda){
	int aux=0,i=0;
	float nuevoPrecio;
	string nombre;
	cout<<"MODIFICAR EL PRECIO DEL ARTICULO"<<endl;
	cout<<"================================"<<endl;
	cout<<"NOMBRE: ";
	getline (cin,nombre);
	while ((i<numArticulos)&&(nombre!=nombreArticulos[i]))
		i++;
	if (i==numArticulos)
		aux=1;
	else {
		if (moneda!=1){
			cout<<"PRECIO ACTUAL: "<<ConvertirMoneda(1,moneda,precioArticulos[i])<<" " 				<<DevolverNombreMoneda(moneda)<<endl;
			cout<<"NUEVO PRECIO ("<<DevolverNombreMoneda(moneda)<<"): ";
			cin>>nuevoPrecio;											precioArticulos[i]=ConvertirMoneda(moneda,1,nuevoPrecio);
		}
		else {
			cout<<"PRECIO ACTUAL: "<<precioArticulos[i]<<" "<<DevolverNombreMoneda(moneda)<<endl;
			cout<<"NUEVO PRECIO ("<<DevolverNombreMoneda(moneda)<<"): ";
			cin>>nuevoPrecio;
			precioArticulos[i]=nuevoPrecio;
		}
	}
return (aux);
}


//funcion OrdenarArticulosPorNombre (metodo por seleccion)
void OrdenarArticulosPorNombre (string nombreArticulos[], float precioArticulos[], int numArticulos){
	int i=1,j,k;
	string nombreAux;
	float precioAux;
	for (i;i<numArticulos;i++)
		for (j=numArticulos-1;j>=i;j--)
			if (nombreArticulos[j-1]>nombreArticulos[j]){
				nombreAux=nombreArticulos[j];
				precioAux=precioArticulos[j];
				nombreArticulos[j]=nombreArticulos[j-1];
				precioArticulos[j]=precioArticulos[j-1];
				nombreArticulos[j-1]=nombreAux;
				precioArticulos[j-1]=precioAux;
			}
return;
}


//funcion MostrarArticulos
void MostrarArticulos (string nombreArticulos[], float precioArticulos[], int numArticulos, int moneda){
	int i;
	cout<<"LOS ARTICULOS DE LA TIENDA"<<endl;
	cout<<"=============================="<<endl;
	for (i=0;i<numArticulos;i++){
		cout<<"NOMBRE: "<<nombreArticulos[i]<<endl;
		if (moneda!=1)
			cout<<"PRECIO ACTUAL: "<<ConvertirMoneda(1,moneda,precioArticulos[i])<<" "<<DevolverNombreMoneda(moneda)<<endl;
		else
			cout<<"PRECIO ACTUAL: "<<precioArticulos[i]<<" "<<DevolverNombreMoneda(moneda)<<endl;
		cout<<"=============================="<<endl;
	}
return;
}


//funcion AnyadirCarrito
int AnyadirCarrito (string nombreArticulos[], float precioArticulos[], int numArticulos, 
		    Telemento carrito[], int &elemCarrito, int moneda){
	int aux=2,i=0;
	string articulo;
	if (elemCarrito<kTAMANYOARTICULOS){
		cout<<"ANYADIR ARTICULO AL CARRITO"<<endl;
		cout<<"==========================="<<endl;
		cout<<"NOMBRE: ";
		getline (cin,articulo);
		while ((i<numArticulos)&&(articulo!=nombreArticulos[i]))
			i++;
		if (i==numArticulos)
			aux=1;
		else {
			carrito[elemCarrito].articulo=articulo;
			carrito[elemCarrito].precio=precioArticulos[i];
			cout<<"PRECIO ("<<DevolverNombreMoneda(moneda)<<"): ";
			if (moneda!=1)
				cout<<ConvertirMoneda(1,moneda,precioArticulos[i])<<endl;
			else
				cout<<precioArticulos[i]<<endl;
			cout<<"CANTIDAD: ";
			cin>>carrito[elemCarrito].cantidad;
			elemCarrito++;
			aux=0;
		}
	}
return (aux);
}


//funcion BorrarCarrito
void BorrarCarrito (int &elemCarrito){
	elemCarrito=0;
return;
}


//funcion MostrarCarrito
void MostrarCarrito (Telemento carrito[], int elemCarrito, int moneda){
	int i=0;
	float total=0;
	cout<<"EL CARRITO ACTUAL ES:"<<endl;
	cout<<"============================="<<endl;
	for (i;i<elemCarrito;i++){
		cout<<"NOMBRE: "<<carrito[i].articulo<<endl;
		cout<<"CANTIDAD: "<<carrito[i].cantidad<<endl;
		if (moneda!=1){
			cout<<"PRECIO ACTUAL: "<<ConvertirMoneda(1,moneda,carrito[i].precio)<<" 							"<<DevolverNombreMoneda(moneda)<<endl;
			cout<<"SUBTOTAL: "<<carrito[i].cantidad*ConvertirMoneda(1,moneda,carrito[i].precio)<<" 					"<<DevolverNombreMoneda(moneda)<<endl;
			cout<<"============================="<<endl;
			total+=(carrito[i].cantidad*ConvertirMoneda(1,moneda,carrito[i].precio));
		}
		else {
			cout<<"PRECIO ACUTAL: "<<carrito[i].precio<<" "<<DevolverNombreMoneda(moneda)<<endl;
			cout<<"SUBTOTAL: "<<carrito[i].cantidad*carrito[i].precio<<" "<<DevolverNombreMoneda 			(moneda)<<endl;
			cout<<"============================="<<endl;
			total+=(carrito[i].cantidad*carrito[i].precio);
		}
	}
	cout<<"TOTAL: "<<total<<" "<<DevolverNombreMoneda(moneda)<<endl;
return;
}


//funcion Comprar
int Comprar (Telemento carrito[], int &elemCarrito, int moneda){
	int fechaCad[2], i=0, j=0, aux=2;
	string tarjeta;
	string datosPers;
	float total=0;
	for (i;i<elemCarrito;i++){
		if (moneda!=1)
			total+=(ConvertirMoneda(1,moneda,carrito[i].precio)*carrito[i].cantidad);
		else
			total+=(carrito[i].precio*carrito[i].cantidad);
	}
	cout<<"COMPRAR"<<endl;
	cout<<"============================="<<endl;
	cout<<"TOTAL (+16 %IVA): "<<total*1.16<<" "<<DevolverNombreMoneda(moneda)<<endl;
	if (total!=0){
		cout<<"NOMBRE: ";
		getline (cin,datosPers);
		cout<<"DIRECCION: ";
		getline (cin,datosPers);
		cout<<"LOCALIDAD: ";
		getline (cin,datosPers);
		cout<<"INTRODUZCA TARJETA: ";
		getline (cin,tarjeta);
		cout<<"FECHA DE CADUCIDAD:"<<endl;
		cout<<"\tMES: ";
		cin>>fechaCad[0];
		cout<<"\tANYO: ";
		cin>>fechaCad[1];
		if (((fechaCad[0]<1)||(fechaCad[0]>12))||((fechaCad[1]< 4)||(fechaCad[1]>10)))
			aux=1;
		else{
			while ((tarjeta[j]>='0')&&(tarjeta[j]<='9'))
				j++;
			if (j==kTAMANYOTARJETA){
				elemCarrito=0;
				aux=0;
			}
			else 
				aux=1;
		}
	}
return (aux);
}

















