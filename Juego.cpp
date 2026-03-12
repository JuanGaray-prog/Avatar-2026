#include "Juego.h"

void Juego::cargarJuego(){
	for(int nivel = 1; nivel <= 3; nivel++){
		cout<<"tablero" + to_string(nivel) + ".txt";
		cout << "===== NIVEL " << nivel << " =====" << endl;
	//Instaciar los objetos
		Tablero mapa;
		
		string nombre = "tablero" + to_string(nivel) + ".txt";
		
		mapa.cargarTablero(nombre);//se carga el tablero desde un archivo plano
		Avatar jugador(mapa);
		jugador.respawn();
	//Interacción de objetos
		int i = 0;
		mapa.position(jugador.getPosX(), jugador.getPosY());
		mapa.mostrarTablero();
		jugador.guardarRuta();
		cout<<"Ubicacion actual del Avatar en el tablero: " << "[" << jugador.getPosX() << "," << jugador.getPosY() <<"]" << endl;
		while ((jugador.getPosX() != mapa.getTamano()-1) || (jugador.getPosY() != mapa.getTamano()-1)){
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
		cout << "Nivel " << nivel << " completado!" << endl;
	}

}