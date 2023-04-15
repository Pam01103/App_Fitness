#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

void ingesta_calorias();
void quema_calorias();
void registro_rendimiento();

int contadorx = 0;
int opcionR;
int main()
{
	char OP=0;
	string input;
	do
	{
		system("cls");
		cout << "\n ********************** Menu Principal **************************\n";
		cout << "                    1. Ingesta de calorias\n";
		cout << "                    2. Quema de calorias\n";
		cout << "                    3. Registro de rendimiento\n";
		//cout << "                    4. Calculos\n"; //Se prevee cubrir esta opcion una vez vistos más temas.
		cout << "                    5. Salir\n ";
		cout << "                      Ingrese una opcion: ";
		cin >> input;
		if (input.length() == 1)
		{
			OP = input[0];
			switch (OP) //utilizamos un switch con la finalidad de crear diferentes menus que sean amigables con el usuario
			{
			case '1': //Para la ingesta de calorias, pedimos datos al usuario para conocer las calorias que deben consumir y las que consumen
				ingesta_calorias();
				break;
			case '2':
				quema_calorias();
				break;
			case '3':
				registro_rendimiento();
				break;
			case '4':
				cout << "Proximamente!!" << endl;
				system("pause");
				break;
			case '5':
				break;
			default:
				cout << "Opcion no valida, por favor ingrese otra opcion." << endl;
				system("pause");
				break;
			}
		}
		else
		{
			cout << "Opcion no valida, por favor ingrese otra opcion." << endl;
			system("pause");
		}
			
	} while (OP != '5');
	system("PAUSE");
	return 0;
	system("cls");
	cout << "Recuerda que para mantener un estilo de vida saludable la ingesta de calorias debe ser mayor a la quema de calorias en el gimnasio.\nConsulta a un especialista para obtener ayuda." << endl;
	cout << "Gracias por usar el programa\n\n";
}

void ingesta_calorias()
{
	int opcionI, genero, anios, altura, prot, verd, gras, carb;
	float calorias_consumidas = 0, calorias_necesarias, peso;
	do
	{
		system("cls");
		cout << "------------------BIENVENIDO A TU REGISTRO DE INGESTA DE CALORIAS--------------------\n";
		cout << "Primero, hay que conocer la cantidad de calorias que necesitas. Eres hombre o mujer?";
		cout << "\n1. Hombre \n2. Mujer" << endl;
		cin >> genero; //Preguntamos el genero, y usamos un switch para la opcion elegida
		switch (genero)
		{
		case 1:
			cout << "Para los hombres, la formula es la siguiente:\n 66 + (13.7 x peso corporal en kg) + (5 x altura en cm) - (6.75 x edad en anios)" << endl;
			cout << "Ingresa tu peso corporal en kilogramos: ";
			cin >> peso;
			cout << "Ingresa tu altura en cm: ";
			cin >> altura;
			cout << "Ingresa tu edad en anios: ";
			cin >> anios;
			calorias_necesarias = 66 + (13.7 * peso) + (5 * altura) - (6.75 * anios); //Formula obtenida en internet
			cout << "La cantidad de calorias que necesitas es: " << calorias_necesarias << endl;
			system("pause");
			break;
		case 2:
			cout << "Para las mujeres, la formula es la siguiente:\n 655 + (9.6 x peso corporal en kg) + (1.8 x altura en cm) - (4.7 x edad en anios)" << endl;
			cout << "Ingresa tu peso corporal en kilogramos: ";
			cin >> peso;
			cout << "Ingresa tu altura en cm: ";
			cin >> altura;
			cout << "Ingresa tu edad en anios: ";
			cin >> anios;
			calorias_necesarias = 655 + (9.6 * peso) + (1.8 * altura) - (4.7 * anios); //Formula obtenida en internet
			cout << "La cantidad de calorias que necesitas es: " << calorias_necesarias << endl;
			system("pause");
			break;
		default:
			cout << "Opcion no valida. Por favor intenta de nuevo." << endl;
			system("pause");
			break;
		}
	} while (genero != 1 && genero != 2);

	do
	{ //Usamos un ciclo do while para que el usuario pueda ingresar las opciones varias veces
		system("cls");
		cout << "Ahora, veamos la cantidad de calorias que consumes. Ingresa cada opcion las veces necesarias." << endl;
		cout << "1. Proteinas \n2. Frutas y Verduras \n3. Grasas \n4. Hidratos de carbono \n5. Salir" << endl; //Submenu para que el usuario elija el tipo de alimento
		cin >> opcionI;
		switch (opcionI)
		{
		case 1:
			do
			{   //Aqui, el usuario puede elegir las veces necesarias cada alimento por cada 100 gramos y se van sumando las calorias hasta que decida salir
				system("cls");
				cout << "1. Pollo (100 gramos = 239 calorias)" << endl;
				cout << "2. Carne (100 gramos = 143 calorias)" << endl;
				cout << "3. Pescado (100 gramos = 206 calorias)" << endl;
				cout << "4. Lacteos (100 gramos = 46 calorias)" << endl;
				cout << "5. Huevo (100 gramos = 155 calorias)" << endl;
				cout << "6. Salir" << endl;
				cin >> prot;
				switch (prot)
				{
				case 1:
					calorias_consumidas += 239;
					break;
				case 2:
					calorias_consumidas += 143;
					break;
				case 3:
					calorias_consumidas += 206;
					break;
				case 4:
					calorias_consumidas += 46;
					break;
				case 5:
					calorias_consumidas += 155;
					break;
				default:
					break;
				}
			} while (prot != 6);
			break;
		case 2:
			do
			{   //Aqui, el usuario puede elegir las veces necesarias cada alimento por cada 100 gramos y se van sumando las calorias hasta que decida salir
				system("cls");
				cout << "1. Espinacas (100 gramos = 23 calorias)" << endl;
				cout << "2. Lechuga (100 gramos = 15 calorias)" << endl;
				cout << "3. Manzana (100 gramos = 52 calorias)" << endl;
				cout << "4. Platano (100 gramos = 89 calorias)" << endl;
				cout << "5. Limon (100 gramos = 29 calorias)" << endl;
				cout << "6. Salir" << endl;
				cin >> verd;
				switch (verd)
				{
				case 1:
					calorias_consumidas += 23;
					break;
				case 2:
					calorias_consumidas += 15;
					break;
				case 3:
					calorias_consumidas += 52;
					break;
				case 4:
					calorias_consumidas += 89;
					break;
				case 5:
					calorias_consumidas += 29;
					break;
				default:
					break;
				}
			} while (verd != 6);
			break;
		case 3: //Aqui, el usuario debe ingresar las grasas que consume en gramos y se hace el calculo en calorias
			system("cls");
			cout << "Que cantidad de grasas consumes en gramos? (1 gramo = 9 calorias): ";
			cin >> gras;
			calorias_consumidas += gras * 9;
			break;
		case 4: //Aqui, el usuario debe ingresar los carbohidratos que consume en gramos y se hace el calculo en calorias
			system("cls");
			cout << "Que cantidad de carbohidratos consumes en gramos? (1 gramo = 4 calorias): ";
			cin >> carb;
			calorias_consumidas += carb * 4;
			break;
		default:
			break;
		}
	} while (opcionI != 5);
}

void quema_calorias()
{
	if (contadorx != 0) //Se usa este condicional para evitar que se registren quemas de calorias sin ejercicio previo
			{
				system("cls");
				// Una vez sepamos usar matrices de diferentes tipos de variables, organizaremos mejor la sig matriz:
				float calculo_cal[3][2] = { {1,0},{2,0},{3,0} };
				string calculos[3] = { "horas", "minutos", "calorias quemadas" };
				//	De acuerdo a nuestra investigacion, establecimos una relacion para aproximar las calorias quemadas por minuto y hora
				cout << "\t\tQuema de Calorias" << endl;
				cout << "Por cuanto tiempo ejercitaste?\n1. Horas: ";
				cin >> calculo_cal[0][1];
				cout << "\t2. Minutos: ";
				cin >> calculo_cal[1][1];
				switch (opcionR) //Se usa la opcion ingresada anteriormente en registro de entrenamiento
				{
				case 1:
					cout << "\n\nTren superior" << endl;
					cout << "\nEn una sesion de entrenamiento de 30 minutos se queman alrededor de 30 calorias." << endl;
					calculo_cal[2][1] = 5 * calculo_cal[1][1] + 300 * calculo_cal[0][1];
					//Se hace el calculo aproximado de calorias quemadas.
					cout << "Has quemado aproximadamente " << calculo_cal[2][1] << " calorias" << endl;
					cout << "Recuerda que la quema de calorias puede variar de acuerdo a tu peso, edad y tiempo efectivo de ejercicio por sesion." << endl;
					system("pause");
					break;
				case 2:
					cout << "\nTren inferior" << endl;
					cout << "\nIncluyendo superseries y ejercicios compuestos, puedes llegar a quemar entre 350 y 700 calorias en una sesion de una hora." << endl;
					calculo_cal[2][1] = 8 * calculo_cal[1][1] + 525 * calculo_cal[0][1];
					//Se hace el calculo aproximado de calorias quemadas.
					cout << "Has quemado aproximadamente " << calculo_cal[2][1] << " calorias" << endl;
					cout << "Dependiendo de tu peso y de la intensidad del ejercicio, puedes llegar a quemar muchas calorias en un entrenamiento de piernas. ";
					system("pause");
					break;
				default:
					cout << "Opcion no valida!" << endl;
					system("pause");
					break;
				}


			}
			else {
				cout << "\n\t\tQuema de Calorias" << endl;
				cout << "Primero accede a la opcion 3 del menu." << endl;
				system("pause");
			}
}

void registro_rendimiento()
{
	int series[4];
	double pesos[4];
	string ejercicios[1];
	double producto[4];
	int mayor = 0, menor = 0;
	contadorx++;
	// submenu 3 
	system("cls");
	cout << "------------------BIENVENIDO A TU REGISTRO DE RENDIMIENTO--------------------\n";
	cout << "                 Cuentanos, que entrenaste el dia de hoy?\n";
	cout << "                           1.Tren superior...\n";
	cout << "                           2.Tren inferior...\n";
	cin >> opcionR;
	//submenu de diferentes entrenamientos
	//utilizacion de switch para validaciones y un submenu 
	switch (opcionR)
	{
	case 1:
		//declaracion de variables 

		//Imprimimos instrucciones para el usuario
		system("cls");
		cout << "....................PERFECTO ESCOGISTE TREN SUPERIOR........................\n";
		cout << "Se estima que para tener un entrenamiento correcto se espera un maximo de 5 ejercicios por sesion\n";
		cout << "           Cada ejercicio debe consistir en 3 series de 8 a 12 repeticiones \n";
		cout << "           En las cuales debes incrementar el peso semana a semana, aproximadamente 2.5 kg...\n";
		cout << "           Esto te permitira tener un aumento de masa muscular y reduccion de grasa...\n";
		cout << "Se recomienda que cuando estemos haciendo pesas procuremos que el corazon este por encima de los 90 latidos,\nDe esta manera la quema de calorias sera optima";
		cout << "                                                                                             \n";
		cout << "           Sabiendo esto, cuentanos ¿Como estuvo tu entrenamiento?\n";

		//Pedimos al usuario los datos y los guardamos en vestores
		for (int i = 0; i < 1; i++)
		{
			cout << "\n                        Ejercicio: \n";
			cin >> ejercicios[i];
			for (int j = 0; j < 4; j++)
			{
				cout << "            Cuantas reps hiciste en tu serie #   " << j + 1 << " ?\n";
				cin >> series[j];
			}
			for (int k = 0; k < 4; k++)
			{
				cout << "         Cuanto peso cargaste en tu rep #   " << k + 1 << " ?\n";
				//solo se necesita preguntar una vez 
				cin >> pesos[k];
			}
		}
		system("cls");
		//Impresion de resultados utilizando fors
		cout << "....................TUS DATOS SON LOS SIGUIENTES..........................\n";
		cout << "\n............................EJERCICIOS..................................\n";
		for (int g = 0; g < 1; g++)
		{
			cout << ejercicios[g] << "\t";
		}
		cout << "\n....................REPETICIONES EN 4 SERIES ...........................\n";
		for (int h = 0; h < 4; h++)
		{
			cout << series[h] << "\t";
		}
		cout << "\n....................PESOS EN TUS REPETICIONES ..........................\n";
		for (int l = 0; l < 4; l++)
		{
			cout << pesos[l] << "kg" << "\t";
		}
		cout << "\n";
		cout << "\n....................RENDIMIENTO.............. ..........................\n";
		cout << "     Se espera que para tu siguiente sesion logres cargar entre ...";
		// creamos un for para recorrer el veector e imprimirlo 
		for (int g = 0; g < 1; g++)
		{
			cout << ejercicios[g] << "\t";
		}
		cout << "\n";
		// creamos un for para multiplicar los valores de dciho por otros
		for (int t = 0; t < 4; t++)
		{
			cout << "\t";
			producto[t] = pesos[t] + 2.5;
			cout << producto[t] << "Kg";
		}
		cout << "     \n Tus mayores y menores cargas fueron ...\n";
		//Recorremos el vector con un for, utilizamos un operador unario para encontrar el tamaño del operando
		for (int w = 0; w < sizeof(pesos) / sizeof(pesos[0]); w++)
		{
			// utilizamos ifs para crear las condiciones de uso con base en el operador de tamaño
			if (pesos[w] > mayor) mayor = pesos[w];
			//el valor en la posicion del vector es mayor o menor se guarda en la variable mayor o menor para despues pasar a la siguiente posisicion y actualizar el valor de la variable 
			if (pesos[w] < menor) menor = pesos[w];
		}
		cout << "\n el mayor peso fue de:  " << mayor << "\n";
		cout << "\n El menor peso fue de:  " << menor << "\n";
		system("pause");
		break;

	case 2:
		//Imprimimos instrucciones para el usuario
		system("cls");
		cout << "....................PERFECTO ESCOGISTE TREN INFERIOR ........................\n";
		cout << "Se estima que para tener un entrenamiento correcto se espera un maximo de 5 ejercicios por sesion\n";
		cout << "           Cada ejercicio debe consistir en 3 series de 8 a 12 repeticiones \n";
		cout << "           En las cuales debes incrementar el peso semana a semana, aproximadamente 3.5 kg...\n";
		cout << "           Esto te permitira tener un aumento de masa muscular y reduccion de grasa...\n";
		cout << "                                                                                             \n";
		cout << "           Sabiendo esto, cuentanos ¿Como estuvo tu entrenamiento?\n";

		//Pedimos al usuario los datos y los guardamos en vestores
		for (int i = 0; i < 1; i++)
		{
			cout << "\n                        Ejercicio: \n";
			cin >> ejercicios[i];
			for (int j = 0; j < 4; j++)
			{
				cout << "            Cuantas reps hiciste en tu serie #   " << j + 1 << " ?\n";
				cin >> series[j];
			}
			for (int k = 0; k < 4; k++)
			{
				cout << "         Cuanto peso cargaste en tu rep #   " << k + 1 << " ?\n";
				//solo se necesita preguntar una vez 
				cin >> pesos[k];
			}
		}
		system("cls");
		//Impresion de resultados utilizando fors
		cout << "....................TUS DATOS SON LOS SIGUIENTES..........................\n";
		cout << "\n............................EJERCICIOS..................................\n";
		for (int g = 0; g < 1; g++)
		{
			cout << ejercicios[g] << "\t";
		}
		cout << "\n....................REPETICIONES EN 4 SERIES ...........................\n";
		for (int h = 0; h < 4; h++)
		{
			cout << series[h] << "\t";
		}
		cout << "\n....................PESOS EN TUS REPETICIONES ..........................\n";
		for (int l = 0; l < 4; l++)
		{
			cout << pesos[l] << "kg" << "\t";
		}
		cout << "\n";
		cout << "\n....................RENDIMIENTO.............. ..........................\n";
		cout << "     Se espera que para tu siguiente sesion logres cargar entre ...\n";
		// creamos un for para recorrer el veector e imprimirlo 
		for (int g = 0; g < 1; g++)
		{
			cout << ejercicios[g] << "\t";
		}
		cout << "\n";
		// creamos un for para multiplicar los valores de dciho por otros
		for (int t = 0; t < 4; t++)
		{
			cout << "\t";
			producto[t] = pesos[t] + 3.5;
			cout << producto[t] << "Kg";
		}
		cout << "     \n Tus mayores y menores cargas fueron ...\n";
		//Recorremos el vector con un for, utilizamos un operador unario para encontrar el tamaño del operando
		for (int w = 0; w < sizeof(pesos) / sizeof(pesos[0]); w++)
		{
			// utilizamos ifs para crear las condiciones de uso con base en el operador de tamaño
			if (pesos[w] > mayor) mayor = pesos[w];
			//el valor en la posicion del vector es mayor o menor se guarda en la variable mayor o menor para despues pasar a la siguiente posisicion y actualizar el valor de la variable 
			if (pesos[w] < menor) menor = pesos[w];
		}
		cout << "\n el mayor peso fue de:  " << mayor << "\n";
		cout << "\n El menor peso fue de:  " << menor << "\n";
		system("pause");
		break;

	default: cout << "Usted ha ingresado una opcion incorrecta";
		break;
	}
}
