/*
 * Integrated Flight Management System v0.01
 * ifms.cpp
 * Copyleft - 2014  Javier Dominguez Gomez
 * Written by Javier Dominguez Gomez <jdg@member.fsf.org>
 * GnuPG Key: 6ECD1616
 * Madrid, Spain
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
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
