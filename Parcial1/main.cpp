#include <iostream>
#include "funciones.h"


using namespace std;

int main()
{
    int xo,yo,xd,yd,d,alphao,alphad,opc=1;
    cout<<"                        BIENVENIDO                        "<<endl<<endl;
    cout<<"Este es el sistema de simulacion defensivo en una battalla por el territorio"<<endl;
    cout<<"Para comenzar la simulacion debes ingresar los siguientes datos:"<<endl;
    cout<<"Posicion x ofensiva: ";cin>>xo;
    cout<<"Posicion y ofensiva: ";cin>>yo;
    cout<<"Posicion x defensiva: ";cin>>xd;
    cout<<"Posicion y defensiva: ";cin>>yd;
    d=abs(xd-xo);
    cout<<"Angulo de elevasion ofensivo: ";cin>>alphao;
    cout<<"Angulo de elevasion defensivo: ";cin>>alphad;
    cout<<"En el campo de batalla ocurren las siguientes 4 sitaciones: "<<endl<<endl;
    while(opc!=5){
        cout<<"1. Generar Disparos Ofensivos que Dañen el cañon enemigo."<<endl;
        cout<<"2. Generar Disparos Defensivos que Dañen el cañon enemigo."<<endl;
        cout<<"3. Dado un disparo ofensivo, generar al menos 3 sin importar la destruccion enemiga."<<endl;
        cout<<"4. Dado un disparo ofensivo, generar al menos 3 sin dañar ningun cañon."<<endl;
        cout<<"5. Rendirse.(Esta no es una opcion.)"<<endl;
        cout<<"Elija una de las opciones anteriores: ";cin>>opc;
        switch (opc) {
            case 1:

            break;
            case 2:

            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
                cout<<"Rendido, Perdiste."<<endl;
            break;
            default:
                cout<<"Opcion NO DISPONIBLE."<<endl;
            break;
        }

    }

    movParabolico(0,5,100000,10,45,300,0.1,1,100000);
    return 0;
}
