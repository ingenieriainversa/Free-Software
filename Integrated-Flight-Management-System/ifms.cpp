#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ifms.h"

int main() {
	char sel_1;
	do {
		system("cls");
		printf("\n Gesti%cn de vuelos\n\n", 162);
		printf("\tAlta nuevo vuelo\t(Pulsar A)\n");
		printf("\tOfertas del mes\t\t(Pulsar O)\n");
		printf("\tComprar plazas\t\t(Pulsar C)\n");
		printf("\tVuelos del mes\t\t(Pulsar V)\n");
		printf("\tSalir\t\t\t(Pulsar S)\n\n");
		printf(" Teclear una opci%cn v%clida (A|O|C|V|S): ", 162, 160);
		scanf("%c", &sel_1);
		switch (sel_1) {
		case 'A':
			AltaNuevoVuelo(numeroDeVuelosTotal);
			break;
		case 'O':
			OfertasDelMes();
			break;
		case 'C':
			ComprarPlazas(numeroDeVuelosTotal);
			break;
		case 'V':
			CalendarioMes();
			break;
		case 'S':
			exit(0);
			break;
		case '\n':
			break;
		default:
			Error();
		}
	} while (sel_1 != 'A' || sel_1 != 'O' || sel_1 != 'C' || sel_1 != 'V' || sel_1 != 'S');
}
