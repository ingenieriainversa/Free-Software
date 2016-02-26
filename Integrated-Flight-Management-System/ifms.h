#pragma once

/* Definicion de constantes */
const int max_char_codigo = 6;	// Numero maximo de caracteres para el codigo de vuelo.
const int max_char_hora = 5;	  // Numero maximo de caracteres para la hora.
const int max_char_mes = 2;		  // Numero maximo de caracteres para el mes.
const int max_meses = 24;		    // Numero maximo de meses.
const int max_vuelos_mes = 50;	// Numero maximo de vuelos por cada mes.
const int max_vuelos_total = max_meses * max_vuelos_mes; // Numero maximo de vuelos en total.

/* Definicion de variables globales */
int numeroDeVuelosTotal, numeroDeMesesUtilizados, meses_no_disponibles, error_alpha, error_digit, error_disponibilidad, contadorTablaVuelos, maximo_plazas;

/* Struct con todas las variables necesarias para anadir nuevos vuelos */
struct GestionVuelosMes {
	char codigoDeVuelo[max_char_codigo+1], hora[max_char_hora+1], tempCodigoDeVuelo[max_char_codigo+1], tempHora[max_char_hora+1];
	int id, dia, mes, anno, plazasInicial, plazasActual, tempDia, tempMes, tempAnno, tempPlazasInicial, tempPlazasActual;
	float precio, tempPrecio;
	bool vueloCompleto;
} Vuelo[max_vuelos_total];

/* Struct con todas las variables necesarias para controlar los vuelos ya registrados */
struct DatosNuevoMes {
	int anno, mes, numeroVuelos;
	bool mesCompleto;
} nuevoMes[max_meses];

/* Procedimiento para continuar despues de una accion determinada */
void Next() {
	char c;
	while (c != '\n') {
		c = getchar();
		printf("\n\tPulsa INTRO para continuar.");
	}
	getchar();
}

/* Procedimiento para control de error al introducir una opcion en el menu principal */
void Error() {
	system("cls");
	printf("\n Gesti%cn de vuelos\n\n", 162);
	printf("\n\tATENCI%cN: Opcion inv%clida", 224, 160);
	Next();
}

/* Procedimeinto para pintar las lineas horizontales en
 * la tabla de "ofertas del mes" y "comprar plazas" */
void Linea(int longitud, char posicion) {
	int esquinaIzq, esquinaDer;

	 /* Los extremos de las lineas cambian dependiendo si se trata de la linea superior, media o inferior. */
	switch (posicion) {
	case 'U': /* Posicion arriba (Up) */
		esquinaIzq = 201;
		esquinaDer = 187;
		break;
	case 'M': /* Posicion en medio (Middle) */
		esquinaIzq = 204;
		esquinaDer = 185;
		break;
	case 'B': /* Posicion abajo (Bottom) */
		esquinaIzq = 200;
		esquinaDer = 188;
		break;
	}

	printf("%c", esquinaIzq);
	for (int k = 0; k <= longitud; k++) {
		printf("%c", 205);
	}
	printf("%c\n", esquinaDer);
}

/* Funcion para control de error en la longitud de la cadena del codigo de vuelo */
bool CompruebaLongCodigo(int i) {
	bool resultado = false;

	if (strlen(Vuelo[i].codigoDeVuelo) == max_char_codigo) {
		resultado = true;
	} else {
		resultado = false;
	}
	return resultado;
}

/* Procedimiento para control de error en los caracteres de la cadena del codigo de vuelo. */
void CompruebaCaracteresCodigo(int i) {
	/* Inicializacion de variables para el control de errores en caracteres */
	error_alpha = 0;
	error_digit = 0;

	/* Debe comenzar por dos letras mayusculas. */
	for (int k = 0; k <= 1; k++) {
		if (!isupper(Vuelo[i].codigoDeVuelo[k])) {
			error_alpha++;
		}
	}

	/* Debe terminar con cuatro digitos. */
	for (int z = 2; z <= max_char_codigo - 1; z++) {
		if (!isdigit(Vuelo[i].codigoDeVuelo[z])) {
			error_digit++;
		}
	}
}

/* Procedimiento para control de errores generales en la cadena del codigo de vuelo. */
void CompruebaCadenaCodigo(int i) {
	CompruebaCaracteresCodigo(i);

	/* Pide codigo de vuelo mientras no se cumpla la condicion de
	 * longitud (6 caracteres) y de formato (dos letras mayusculas y cuatro digitos). */
	while (CompruebaLongCodigo(i) == false || error_alpha != 0 || error_digit != 0) {
		if (CompruebaLongCodigo(i) == false) {
			printf("\tERROR: El c%cdigo introducido \"%s\" tiene %d caracteres y debe tener %d.\n\n", 162, Vuelo[i].codigoDeVuelo,
					strlen(Vuelo[i].codigoDeVuelo), max_char_codigo);
		} else if (error_alpha != 0 || error_digit != 0) {
			printf("\tERROR: El c%cdigo introducido \"%s\" no tiene el formato\n\t       esperado (AB1234). Errores en letras: %d - Errores en d%cgitos: %d.\n\n", 162, Vuelo[i].codigoDeVuelo, error_alpha, 161, error_digit);
		}
		fflush (stdin);
		printf("\t%cC%cdigo de vuelo?\t", 168, 162);
		scanf("%s", Vuelo[i].codigoDeVuelo);

		CompruebaCaracteresCodigo(i);
	}
}

/* Funcion para control de meses no disponibles. Sirve para saber si se pueden dar de alta
 * nuevos meses. De lo contrario se tendrian que utilizar los meses existentes para dar de
 * alta nuevos vuelos siempre que estos no superen el numero de vuelos maximo. */
int ContadorMesesNoDisponiblesAnno(int i) {
	meses_no_disponibles = 0;

	for (int j = 0; j <= max_meses - 1; j++) {
		if (Vuelo[i].anno != nuevoMes[j].anno) {
			meses_no_disponibles++;
		}
	}
	return meses_no_disponibles;
}

/* FuciÛn para control de errores generales en el anno. */
bool CompruebaAnno(int i) {
	bool resultado = true;

	if (numeroDeMesesUtilizados == max_meses && ContadorMesesNoDisponiblesAnno(i) == max_meses) {
		/* Por ejemplo, si ya se han dado de alta el numero maximo de meses, no se podran dar de alta
		 * mas vuelos en ningun anno nuevo, pero si se podran dar de alta vuelos en meses ya utilizados
		 * de otros annos, siempre y cuando el mes elegido aun pueda albergar mas vuelos. */
		printf("\tERROR: No puedes utilizar mas a%cos, usa uno que ya este dado\n\t       de alta y que tenga meses con vuelos disponibles.\n\n", 164);
		resultado = false;
	}
	return resultado;
}

/* Funcion para control de error en el anno: No puede ser un numero negativo. */
bool CompruebaAnnoNegativo(int anno) {
	bool resultado = true;

	/* Comprueba si el anno es un numero negativo. */
	if (anno < 0) {
		printf("\tERROR: El a%co introducido \"%d\" no puede ser un n%cmero negativo.\n\n", 164, anno, 163);
		resultado = false;
	}
	return resultado;
}

/* Funcion para control de meses no disponibles. Sirve para saber si se pueden dar de alta
 * nuevos meses. De lo contrario se tendrian que utilizar los meses existentes para dar de
 * alta nuevos vuelos siempre que estos no superen el numero de vuelos maximo. */
int ContadorMesesNoDisponibles(int i) {
	meses_no_disponibles = 0;

	for (int j = 0; j <= max_meses - 1; j++) {
		if (Vuelo[i].anno != nuevoMes[j].anno || (Vuelo[i].anno == nuevoMes[j].anno && Vuelo[i].mes != nuevoMes[j].mes)) {
			meses_no_disponibles++;
		}
	}
	return meses_no_disponibles;
}

/* Funcion que comprueba si el mes es un numero comprendido entre 1 y 12 inclusive. */
bool CompruebaMesRango(int mes) {
	bool resultado = true;

	if (mes < 1 || mes > 12) {
		printf("\tERROR: El mes introducido \"%d\" no es v%clido.\n\n", mes, 160);
		resultado = false;
	}
	return resultado;
}

/* Procedimiento para control de errores generales en el mes. */
void CompruebaMes(int i) {

	for (int k = 0; k <= max_meses - 1; k++) {
		/* Comprobacion para saber si se trata de un mes valido (entre 1 y 12) y si el mes de
		 * ese anno aun puede registrar vuelos. De lo contrario pedira introducir otro mes. */
		while ((CompruebaMesRango(Vuelo[i].mes) == false) || (Vuelo[i].anno == nuevoMes[k].anno && Vuelo[i].mes == nuevoMes[k].mes && nuevoMes[k].mesCompleto == true) || (numeroDeMesesUtilizados == max_meses && ContadorMesesNoDisponibles(i) == max_meses)) {

			if (Vuelo[i].anno == nuevoMes[k].anno && Vuelo[i].mes == nuevoMes[k].mes && nuevoMes[k].mesCompleto == true) {
				printf("\tERROR: El mes \"%d\" del a%co \"%d\" ya est%c completo.\n\n", Vuelo[i].mes, 164, Vuelo[i].anno, 160);
				k = 0;
			} else if (numeroDeMesesUtilizados == max_meses && ContadorMesesNoDisponibles(i) == max_meses) {
				printf("\tERROR: No puedes utilizar mas meses, usa uno que ya este\n\t       dado de alta y que tenga vuelos disponibles.\n\n");
				k = 0;
			}

			fflush (stdin);
			printf("\t%cMes?\t\t\t", 168);
			scanf("%d", &Vuelo[i].mes);
		}
	}

	for (int e = 0; e <= max_meses - 1; e++) {
		if (Vuelo[i].anno == nuevoMes[e].anno && Vuelo[i].mes == nuevoMes[e].mes && nuevoMes[e].numeroVuelos < max_vuelos_mes) {
			/* Busca vuelos que coincidan en anno y mes. En ese caso suma un vuelo a ese
			 * mes, siempre y cuando el numero de vuelos sea menor al maximo permitido. */
			nuevoMes[e].numeroVuelos = nuevoMes[e].numeroVuelos + 1;
			if (nuevoMes[e].numeroVuelos == max_vuelos_mes) {
				nuevoMes[e].mesCompleto = true;
			}
			return;
		} else if (nuevoMes[e].numeroVuelos == 0 && numeroDeMesesUtilizados != max_meses) {
			/* Si no esta cubierto el cupo de meses y no hay nungun vuelo registrado anteriormente que coincida
			 * con el anno y mes introducido se incuye uno nuevo justo despues del ultimo vuelo registrado, excepto
			 * en el caso del primer vuelo, en ese caso este se guardara en la primera posicion. */
			nuevoMes[e].anno = Vuelo[i].anno;
			nuevoMes[e].mes = Vuelo[i].mes;
			nuevoMes[e].numeroVuelos = nuevoMes[e].numeroVuelos + 1;
			numeroDeMesesUtilizados++;
			return;
		}
	}
}

/* Funcion que devuelve los dias que tiene un mes en un anno
 * determinado teniendo en cuenta annos bisiestos. */
int CalcularDiasMes(int ano, int mes) {
	int dias;
	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
		dias = 31;
	} else if (mes == 2) {
		if ((ano % 4 == 0) && (ano % 100 != 0 || ano % 400 == 0)) {
			dias = 29;
		} else {
			dias = 28;
		}
	} else {
		dias = 30;
	}
	return dias;
}

/* Funcion para control de error en el dia introducido. Por ejemplo un 30 de febrero o un -3 de junio. */
bool CompruebaDia(int anno, int mes, int dia) {
	bool resultado = true;
	if (dia < 1 || dia > CalcularDiasMes(anno, mes)) {
		printf("\tERROR: El d%ca introducido \"%d\" no es v%clido para el mes %d del a%co %d.\n\n", 161, dia, 160, mes, 164, anno);
		resultado = false;
	}
	return resultado;
}

/* Funcion para control de error en la longitud de
 * la cadena hora: Ha de tener 5 caracteres. */
bool CompruebaLongHora(int i) {
	bool resultado = false;

	if (strlen(Vuelo[i].hora) == max_char_hora) {
		resultado = true;
	} else {
		resultado = false;
	}
	return resultado;
}

/* Procedimiento para control de error en los caracteres de la cadena hora. */
void CompruebaCaracteresHora(int i) {
	error_alpha = 0;
	error_digit = 0;

	/* Control de horas: Han de ser dos digitos */
	for (int k = 0; k <= 1; k++) {
		if (!isdigit(Vuelo[i].hora[k])) {
			error_digit++;
		}
	}

	/* Control de horas: No puede ser menor que 00 ni mayor que 23
	 * En ASCII:	0 = 48		3 = 51
	 * 				1 = 49		5 = 53
	 * 				2 = 50		9 = 57 */
	if (Vuelo[i].hora[0] < 48 || Vuelo[i].hora[0] > 50) {
		error_digit++;
	} else if ((Vuelo[i].hora[0] == 48 || Vuelo[i].hora[0] == 49) && (Vuelo[i].hora[1] < 48 || Vuelo[i].hora[1] > 57)) {
		error_digit++;
	} else if ((Vuelo[i].hora[0] == 50) && (Vuelo[i].hora[1] < 48 || Vuelo[i].hora[1] > 51)) {
		error_digit++;
	}

	/* Control del separador de horas y minutos: Ha de ser el caracter de dos puntos */
	if (Vuelo[i].hora[2] != ':') {
		error_alpha++;
	}

	/* Control de minutos: Han de ser digitos */
	for (int y = 3; y <= max_char_hora - 1; y++) {
		if (!isdigit(Vuelo[i].hora[y])) {
			error_digit++;
		}
	}

	/* Control de minutos: No puede ser menor que 00 ni mayor que 59
	* En ASCII:		0 = 48		3 = 51
	*				1 = 49		5 = 53
	*				2 = 50		9 = 57 */
	if (Vuelo[i].hora[3] < 48 || Vuelo[i].hora[3] > 53) {
		error_digit++;
	} else if (Vuelo[i].hora[4] < 48 || Vuelo[i].hora[4] > 57) {
		error_digit++;
	}
}

/* Procedimiento para control de errores generales en la cadena hora. */
void CompruebaCadenaHora(int i) {
	CompruebaCaracteresHora(i);

	while (CompruebaLongHora(i) == false || error_alpha != 0 || error_digit != 0) {
		if (CompruebaLongHora(i) == false) {
			printf("\tERROR: La hora introducida \"%s\" tiene %d caracteres y debe tener %d.\n\n", Vuelo[i].hora, strlen(Vuelo[i].hora), max_char_hora);
		} else if (error_alpha != 0 || error_digit != 0) {
			printf("\tERROR: La hora introducida \"%s\" no es v%clida o no\n\t       tiene el formato esperado (HH:MM).\n\n", Vuelo[i].hora, 160);
		}

		fflush (stdin);
		printf("\t%cHora?\t\t\t", 168);
		scanf("%s", Vuelo[i].hora);

		CompruebaCaracteresHora(i);
	}
}

/* Funcion que comprueba que el numero de plazas que se introduce es un numero mayor que cero. */
bool CompruebaPlazasVuelo(int i) {
	bool resultado = true;

	if (Vuelo[i].plazasInicial <= 0) {
		printf("\tERROR: El n%cmero de plazas ha de ser un n%cmero mayor que 0.\n\n", 163, 163);
		resultado = false;
	}
	return resultado;
}

/* Funcion que comprueba que el precio que se introduce es un numero mayor que cero. */
bool CompruebaPrecioVuelo(int i) {
  bool resultado = true;

	if (Vuelo[i].precio <= 0) {
		printf("\tERROR: El precio ha de ser un n%cmero mayor que 0.\n\n", 163);
		resultado = false;
	}
	return resultado;
}

/* Procedimiento para dar de alta nuevos vuelos. */
void AltaNuevoVuelo(int &i) {
	system("cls");
	printf("\n Nuevo vuelo:\n\n");

	/* Mientras se puedan dar de alta vuelos por que no se ha llenado el cupo total. */
	if (numeroDeVuelosTotal != max_vuelos_total) {

		/* Pide codigo de vuelo hasta que tenga un valor aceptado por la norma de formato. */
		printf("\t%cC%cdigo de vuelo?\t", 168, 162);
		scanf("%s", Vuelo[i].codigoDeVuelo);
		CompruebaCadenaCodigo(i);

		/* Pide anno hasta que tenga un valor correcto. */
		do {
			fflush (stdin);
			printf("\t%cA%co?\t\t\t", 168, 164);
			scanf("%d", &Vuelo[i].anno);
		} while (CompruebaAnno(i) == false || CompruebaAnnoNegativo(Vuelo[i].anno) == false);

		/* Pide mes hasta que tenga un valor correcto. */
		fflush (stdin);
		printf("\t%cMes?\t\t\t", 168);
		scanf("%d", &Vuelo[i].mes);
		CompruebaMes(i);

		/* Pide dia hasta que tenga un valor correcto. */
		do {
			fflush(stdin);
			printf("\t%cD%ca?\t\t\t", 168, 161);
			scanf("%d", &Vuelo[i].dia);
		} while (CompruebaDia(Vuelo[i].anno, Vuelo[i].mes, Vuelo[i].dia) == false);

		/* Pide la hora del vuelo hasta que tenga un valor aceptado por la norma de formato. */
		fflush(stdin);
		printf("\t%cHora?\t\t\t", 168);
		scanf("%s", Vuelo[i].hora);
		CompruebaCadenaHora(i);

		/* Pide numero de plazas del vuelo hasta que tenga un valor correcto. */
		do {
			fflush(stdin);
			printf("\t%cPlazas del vuelo?\t", 168);
			scanf("%d", &Vuelo[i].plazasInicial);
		} while (CompruebaPlazasVuelo(i) == false);
		Vuelo[i].plazasActual = Vuelo[i].plazasInicial;

		/* Pide el precio del vuelo hasta que tenga un valor correcto. */
		do {
		  fflush(stdin);
      printf("\t%cPrecio inicial?\t", 168);
      scanf("%f", &Vuelo[i].precio);
		}while (CompruebaPrecioVuelo(i) == false);

		/* Si ha ido bien sumamos un vuelo mas al contador total "numeroDeVuelosTotal",
		 * el cual hemos pasado al procedimiento como argumento por referencia. */
		i++;
		system("cls");
		printf("\n Nuevo vuelo:\n\n");
		printf("\n\tDatos introducidos correctamente.\n");
	} else {
		printf("\n\tERROR: No es posible dar de alta mas vuelos, se ha superado el n%cmero m%cximo de vuelos (%d).\n\n", 163, 160, max_vuelos_total);
	}
	Next();
}

/* Procedimiento para pintar la tabla de vuelos. */
void TablaVuelos(int dia, int mes, int anno, int &contadorTablaVuelos) {
	float tarifa;
	/* Linea superior de la tabla. */
	Linea(42, 'U');
	/* Cabecera. */
	printf("%c  Vuelo   C%cdigo   Hora    Plazas   Precio %c\n", 186, 162, 186);
	/* Linea media de la tabla. */
	Linea(42, 'M');
	contadorTablaVuelos = 1;

	/* Por cada vuelo, ordena por precio y muestra los 5 primeros en orden ascendente (primero el mas barato). */
	for (int i = 0; i < numeroDeVuelosTotal; i++) {
		for (int j = i + 1; j < numeroDeVuelosTotal; j++) {
			if (Vuelo[j].precio < Vuelo[i].precio) {

				/* Orden de los codigos de vuelo. */
				strcpy(Vuelo[i].tempCodigoDeVuelo, Vuelo[j].codigoDeVuelo);
				strcpy(Vuelo[j].codigoDeVuelo, Vuelo[i].codigoDeVuelo);
				strcpy(Vuelo[i].codigoDeVuelo, Vuelo[i].tempCodigoDeVuelo);

				/* Orden de los dias. */
				Vuelo[i].tempDia = Vuelo[j].dia;
				Vuelo[j].dia = Vuelo[i].dia;
				Vuelo[i].dia = Vuelo[i].tempDia;

				/* Orden de los meses. */
				Vuelo[i].tempMes = Vuelo[j].mes;
				Vuelo[j].mes = Vuelo[i].mes;
				Vuelo[i].mes = Vuelo[i].tempMes;

				/* Orden de los annos. */
				Vuelo[i].tempAnno = Vuelo[j].anno;
				Vuelo[j].anno = Vuelo[i].anno;
				Vuelo[i].anno = Vuelo[i].tempAnno;

				/* Orden de las horas. */
				strcpy(Vuelo[i].tempHora, Vuelo[j].hora);
				strcpy(Vuelo[j].hora, Vuelo[i].hora);
				strcpy(Vuelo[i].hora, Vuelo[i].tempHora);

				/* Orden de las plazas iniciales. */
				Vuelo[i].tempPlazasInicial = Vuelo[j].plazasInicial;
				Vuelo[j].plazasInicial = Vuelo[i].plazasInicial;
				Vuelo[i].plazasInicial = Vuelo[i].tempPlazasInicial;

				/* Orden de las plazas disponibles actuales. */
				Vuelo[i].tempPlazasActual = Vuelo[j].plazasActual;
				Vuelo[j].plazasActual = Vuelo[i].plazasActual;
				Vuelo[i].plazasActual = Vuelo[i].tempPlazasActual;

				/* Orden de los precios. */
				Vuelo[i].tempPrecio = Vuelo[j].precio;
				Vuelo[j].precio = Vuelo[i].precio;
				Vuelo[i].precio = Vuelo[i].tempPrecio;
			}
		}

		/* Calculo del precio en funcion de las plazas que que queden libres. */
		if (Vuelo[i].plazasActual > Vuelo[i].plazasInicial * 0.5) {
			/* Hasta 50% de plazas disponibles precio x1 */
			tarifa = 1;
		} else if (Vuelo[i].plazasActual > Vuelo[i].plazasInicial * 0.3) {
			/* Hasta 30% de plazas disponibles precio x2 */
			tarifa = 2;
		} else if (Vuelo[i].plazasActual > Vuelo[i].plazasInicial * 0.15) {
			/* Hasta 15% de plazas disponibles precio x3 */
			tarifa = 3;
		} else if (Vuelo[i].plazasActual > Vuelo[i].plazasInicial * 0.05) {
			/* Hasta 5% de plazas disponibles precio x5 */
			tarifa = 5;
		} else if (Vuelo[i].plazasActual == 0) {
			/* Si no hay plazas disponibles precio x0 */
			tarifa = 0;
		}

		/* Asignacion de un id a cada vuelo, para su listado y seleccion. */
		Vuelo[i].id = contadorTablaVuelos;

		/* Se imprimen los datos del vuelo. */
		if ((dia == 0 || dia == Vuelo[i].dia) && mes == Vuelo[i].mes && anno == Vuelo[i].anno && contadorTablaVuelos <= 5) {
			printf("%c  %4d    %-6s   %-5s     %3d    %6.2f %c\n", 186, Vuelo[i].id, Vuelo[i].codigoDeVuelo, Vuelo[i].hora, Vuelo[i].plazasActual, Vuelo[i].precio * tarifa, 186);
			contadorTablaVuelos++;
		}
	}
	Linea(42, 'B');
	printf("\n\n");
}

/* Funcion que devuelve true si en un dia/mes/anno hay
 * vuelos, por el contrario devuelve false. */
bool CompruebaVuelosFecha(int dia, int mes, int anno) {
	bool resultado = false;
	for (int i = 0; i < numeroDeVuelosTotal; i++) {
		if (dia == Vuelo[i].dia && mes == Vuelo[i].mes && anno == Vuelo[i].anno) {
			resultado = true;
		} else if (dia == 0 && mes == Vuelo[i].mes && anno == Vuelo[i].anno) {
			resultado = true;
		}
	}
	return resultado;
}

/* Procedimiento para mostrar por pantalla las ofertas de une mes
 * y anno, en orden creciente por precio. Solo las 5 primeras. */
void OfertasDelMes() {
	int odmMes, odmAnno;

	system("cls");
	printf("\n Ofertas del mes:\n\n");
	if (numeroDeVuelosTotal != 0) {

		/* Pregunta el anno hasta el valor introducido sea un valor igual o mayor que cero. */
		do {
			printf("\t%cA%co?\t", 168, 164);
			scanf("%d", &odmAnno);
		} while (CompruebaAnnoNegativo(odmAnno) == false);

		/* Pregunta el mes hasta que el valor introducido sea un valor correcto, o sea de 1 a 12 inclusive. */
		do {
			fflush (stdin);
			printf("\t%cMes?\t", 168);
			scanf("%d", &odmMes);
		} while (CompruebaMesRango(odmMes) == false);

		system("cls");
		printf("\n Ofertas del mes:\n\n");
		if (CompruebaVuelosFecha(0, odmMes, odmAnno) == false) {
			printf("\n\tERROR: No existe nung%cn vuelo registrado en la fecha %d/%d.\n\n", 163, odmMes, odmAnno);
		} else {
			TablaVuelos(0, odmMes, odmAnno, contadorTablaVuelos);
			printf("\tTotal vuelos registrados: %d\n", numeroDeVuelosTotal);
		}
	} else {
		printf("\n\tERROR: A%cn no se han registrado vuelos. Vuelva al men%c\n\t       principal para registrar uno.\n", 163, 163);
	}
	Next();
}

/* Funcion que devuelve false si el vuelo elegido no pertenece a
 * la lista o si el vuelo elegido ya no tiene plazas disponibles.
 * Si todos los vuelos de la fecha elegida estan ocupados devuelve
 * true y vuelve al menu principal para que elijas otra fecha.*/
bool ComprarPlazasElegirVuelo(int anno, int mes, int dia, int cpVuelo, int contadorTablaVuelos) {
	bool resultado = true;
	int vuelosFechaCompletos = 0;
	if (cpVuelo <= 0 || cpVuelo > contadorTablaVuelos - 1) {
		printf("\tERROR: Debe elegir un n%cmero de vuelo existente en la tabla.\n\n", 163);
		resultado = false;
	} else {
		for (int i = 0; i < numeroDeVuelosTotal; i++) {
			if (Vuelo[i].anno == anno && Vuelo[i].mes == mes && Vuelo[i].dia == dia && Vuelo[i].plazasActual == 0) {
				vuelosFechaCompletos++;
			}
		}

		if (vuelosFechaCompletos == contadorTablaVuelos - 1) {
			printf("\n\tERROR: Todos los vuelos de %d/%d/%d est%cn completos. Elija otra fecha.\n\n", anno, mes, dia, 160);
			resultado = true;
			Next();
		} else {
			for (int i = 0; i < numeroDeVuelosTotal; i++) {
				if (cpVuelo == Vuelo[i].id && Vuelo[i].plazasActual == 0 && contadorTablaVuelos - 1 > 1) {
					printf("\tERROR: El n%cmero de vuelo elegido ya no tiene vuelos disponibles, elija otro.\n\n", 163);
					resultado = false;
				}
			}
		}
	}
	return resultado;
}

/* Funcion que devuelve false si el numero de plazas introducido es igual o menor
 * que cero o cuando el numero de plazas es un numero superior a las disponibles. */
bool ComprarPlazasNumeroPlazas(int cpPlazas, int maximo_plazas) {
	bool resultado = true;
	if (cpPlazas <= 0) {
		printf("\tERROR: Debe elegir un n%cmero de plazas mayor que 0.\n\n", 163);
		resultado = false;
	} else if (cpPlazas > maximo_plazas) {
		printf("\tERROR: Debe elegir un n%cmero de plazas igual o inferior a las disponibles.\n\n", 163);
		resultado = false;
	}
	return resultado;
}

/* Procedimiento para comprar plazas de vuelos ya existentes. */
void ComprarPlazas(int i) {
  system("cls");
  printf("\n Comprar plazas:\n\n");
  if (numeroDeVuelosTotal != 0) {
    int cpDia, cpMes, cpAnno, cpVuelo, cpPlazas;

    /* Pregunta el anno hasta el valor introducido sea un valor igual o mayor que cero. */
    do {
      printf("\t%cA%co?\t\t\t", 168, 164);
      scanf("%d", &cpAnno);
    } while (CompruebaAnnoNegativo(cpAnno) == false);

    /* Pregunta el mes hasta que el valor introducido sea un valor correcto, o sea de 1 a 12 inclusive. */
    do {
      fflush (stdin);
      printf("\t%cMes?\t\t\t", 168);
      scanf("%d", &cpMes);
    } while (CompruebaMesRango(cpMes) == false);

    /* Pregunta el dia hasta que el valor introducido sea correcto respecto a los dias de un mes y anno. */
    do {
      fflush (stdin);
      printf("\t%cD%ca?\t\t\t", 168, 161);
      scanf("%d", &cpDia);
    } while (CompruebaDia(cpAnno, cpMes, cpDia) == false);

    system("cls");
    printf("\n Comprar plazas:\n\n");
    if (CompruebaVuelosFecha(cpDia, cpMes, cpAnno) == false) {
      /* Si no hay ningun vuelo en la fecha indicada muestra un error y vuelve al menu anterior. */
      printf("\n\tERROR: No existe nung%cn vuelo registrado para la fecha %d/%d/%d.\n\n", 163, cpDia, cpMes, cpAnno);
    } else {
      /* Si existen vuelos en la fecha indicada muestra una tabla con la informacion sobre los vuelos. */
      TablaVuelos(cpDia, cpMes, cpAnno, contadorTablaVuelos);

      /* Pregunta el vuelo que se quiere elegir hasta que el valor introducido sea un vuelo de la lista. */
      do {
        fflush (stdin);
        printf("\tElegir vuelo: \t\t\t");
        scanf("%d", &cpVuelo);
      } while (ComprarPlazasElegirVuelo(cpAnno, cpMes, cpDia, cpVuelo, contadorTablaVuelos) == false);

      /* Calculo del maximo de plazas disponibles para el vuelo seleccionado. */
      for (int i = 0; i < numeroDeVuelosTotal; i++) {
        if (cpVuelo == Vuelo[i].id && Vuelo[i].plazasActual >= 5) {
          maximo_plazas = 5;
        } else if (cpVuelo == Vuelo[i].id && Vuelo[i].plazasActual < 5) {
          maximo_plazas = Vuelo[i].plazasActual;
        }
      }

      /* Si el numero de plazas disponibles en mayor que cero permite comprar plazas. */
      if (maximo_plazas > 0) {

        /* Pregunta el numero de plazas que se quieren comprar hasta que el valor introducido sea un valor correcto. */
        do {
          fflush (stdin);
          printf("\tN%cmero de plazas (m%cximo %d):\t", 163, 160, maximo_plazas);
          scanf("%d", &cpPlazas);
        } while (ComprarPlazasNumeroPlazas(cpPlazas, maximo_plazas) == false);

        /* Se resta al numero de plazas disponibles actual el numero de plazas que se han comprado. */
        for (int i = 0; i < numeroDeVuelosTotal; i++) {
          if (cpVuelo == Vuelo[i].id && cpDia == Vuelo[i].dia && cpMes == Vuelo[i].mes && cpAnno == Vuelo[i].anno) {
            Vuelo[i].plazasActual = Vuelo[i].plazasActual - cpPlazas;
          }
        }

        /* Si ha ido bien se muestra un mensaje de confirmacion y se vuelve al menu anterior. */
        system("cls");
        printf("\n Comprar plazas:\n\n");
        printf("\n\tCompra realizada con %cxito.\n", 130);
      }
    }
  } else {
    printf("\n\tERROR: A%cn no se han registrado vuelos. Vuelva al men%c\n\t       principal para registrar uno.\n", 163, 163);
  }
  Next();
}

/* Procedimeinto para pintar las lineas horizontales en calendario */
void LineaCalendario(int longitud, char posicion) {
	int cruce;

	switch (posicion) {
	case 'U': /* Posicion arriba (Up) */
		cruce = 203;
		break;
	case 'B': /* Posicion abajo (Bottom) */
		cruce = 206;
		break;
	}

	printf("\t");
	for (int k = 0; k <= longitud; k++) {
		if (k != 19) {
			printf("%c", 205);
		} else {
			printf("%c", cruce);
		}
	}
	printf("\n");
}

/* Procedimiento que imprime la cabecera del mes en un calendario */
void Cabecera(int anno, int mes) {
	char *nombreMes;

	switch (mes) {
	case 1:  nombreMes = "ENERO";break;
	case 2:  nombreMes = "FEBRERO";break;
	case 3:  nombreMes = "MARZO";break;
	case 4:  nombreMes = "ABRIL";break;
	case 5:  nombreMes = "MAYO";break;
	case 6:  nombreMes = "JUNIO";break;
	case 7:  nombreMes = "JULIO";break;
	case 8:  nombreMes = "AGOSTO";break;
	case 9:  nombreMes = "SEPTIEMBRE";break;
	case 10: nombreMes = "OCTUBRE";break;
	case 11: nombreMes = "NOVIEMBRE";break;
	case 12: nombreMes = "DICIEMBRE";break;
	}
	printf("\n\t%-14s%13d\n", nombreMes, anno);
	LineaCalendario(26, 'U');
	printf("\tLU  MA  MI  JU  VI %c SA  DO\n", 186);
	LineaCalendario(26, 'B');
}

/* Funcion para obtener el numero del dia de la semana de cualquier fecha (Calendario Gregoriano).
 * Donde:	0 = Domingo		2 = Martes		4 = Jueves		6 = sabado
 * 			1 = Lunes		3 = Miercoles	5 = Viernes */
int DiaDeLaSemana(int anno, int mes) {
	int a = (14 - mes) / 12;
	int y = anno - a;
	int m = mes + 12 * a - 2;
	int dia = 1;
	return (dia + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

/* Procedimiento para pintar los puntos en los huecos vacios del clendario. */
void Puntos(int p, int max) {
	if (p == max) {
		printf("%c  .  ", 186);
	} else if (p == max - 1) {
		printf(" . ");
	} else {
		if (p == 0) {
			printf("\t");
		}
		printf(" .  ");
	}
}

/* Procedimiento que imprime el calendario con los dias de un mes y anno. */
void CalendarioMes() {
  system("cls");
  printf("\n Vuelos del mes:\n\n");
  if (numeroDeVuelosTotal != 0) {
    int anno, mes;

    /* Pregunta el anno hasta el valor introducido sea un valor igual o mayor que cero. */
    do {
      printf("\t%cA%co?\t", 168, 164);
      scanf("%d", &anno);
    } while (CompruebaAnnoNegativo(anno) == false);

    /* Pregunta el mes hasta que el valor introducido sea un valor correcto, o sea de 1 a 12 inclusive. */
    do {
      fflush (stdin);
      printf("\t%cMes?\t", 168);
      scanf("%d", &mes);
    } while (CompruebaMesRango(mes) == false);

    system("cls");
    printf("\n Vuelos del mes:\n\n");

    /* Imprime la cabecera del calendario. */
    Cabecera(anno, mes);
    int z = 1;

    /* Arreglo para que el primer dia de la semana sea Lunes y no Domingo. */
    if (DiaDeLaSemana(anno, mes) == 0) {
      z = 6;
    } else {
      z = DiaDeLaSemana(anno, mes) - 1;
    }

    for (int p = 0; p < z; p++) {
      Puntos(p, 5);
    }

    int diasMes = CalcularDiasMes(anno, mes);

    for (int dia = 1; dia <= diasMes; dia++) {
      z++;

      /* Si el dia tiene vuelos muestra el numero de dia en el calendario, de lo contrario
       * muestra dos guiones medios --. */
      if (z == 6 || z == 13 || z == 20 || z == 27 || z == 34) {
        if (CompruebaVuelosFecha(dia, mes, anno) == true) {
          printf("%c %2d  ", 186, dia);
        } else {
          printf("%c --  ", 186);
        }
      } else if (z == 5 || z == 12 || z == 19 || z == 26 || z == 33) {
        if (CompruebaVuelosFecha(dia, mes, anno) == true) {
          printf("%2d ", dia);
        } else {
          printf("-- ");
        }
      } else {

        /* Este if es para tabular el calendario entero. */
        if (z == 1 || z == 8 || z == 15 || z == 22 || z == 29 || z == 36) {
          printf("\t");
        }

        if (CompruebaVuelosFecha(dia, mes, anno) == true) {
          printf("%2d  ", dia);
        } else {
          printf("--  ");
        }
      }

      if (z % 7 == 0) {
        printf("\n");
      }
    }

    if (z == 29 || z == 30 || z == 31 || z == 32 || z == 33 || z == 34) {
      for (int p = z; p <= 34; p++) {
        Puntos(p, 33);
      }
    } else if (z == 36 || z == 37) {
      for (int p = z; p <= 41; p++) {
        Puntos(p, 40);
      }
    }
  } else {
    printf("\n\tERROR: A%cn no se han registrado vuelos. Vuelva al men%c\n\t       principal para registrar uno.\n", 163, 163);
  }
  printf("\n");
  Next();
}
