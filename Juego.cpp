#include "Juego.h"

void Juego::cargarJuego(){
//Instaciar los objetos
	Tablero mapa;
	mapa.cargarTablero("tablero.txt");//se carga el tablero desde un archivo plano
	Avatar jugador(mapa);
	jugador.respawn();
//Interacción de objetos
	int i = 0;
	mapa.position(jugador.getPosX(), jugador.getPosY());
	mapa.mostrarTablero();
	jugador.guardarRuta();
	cout<<"Ubicación actual del Avatar en el tablero: " << "[" << jugador.getPosX() << "," << jugador.getPosY() <<"]" << endl;
	while ((jugador.getPosX() != 9) || (jugador.getPosY() != 9)){
		jugador.mapearNuevosCaminos();
		jugador.CompararCaminos();
		if (jugador.esPosibleContinuar()){
			cout << "No es posible encontrar una salida" << endl;
			break;
		}
		//jugador.mostrarCaminosPosibles();
		jugador.moverAvatar();
		jugador.guardarRuta();
		cout<<"Ruta recorrida por el Avatar en el tablero:"<<endl;
		cout<<"Ubicación actual del Avatar en el tablero: " << "[" << jugador.getPosX() << "," << jugador.getPosY() <<"]" << endl;
		mapa.position(jugador.getPosX(), jugador.getPosY());
		mapa.mostrarTablero();
		i++;
	}
	jugador.imprimirSolucion();
	cout << "Tomo " << i << " Ciclos para completar" << endl;
}