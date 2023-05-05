#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

struct usuario { //Se crea la estructura usuario para guardar unformación y acceder a ella de manera más fácil
	double peso;
	double altura;
	double anios;
	double calorias;
};

struct tiempo { //Se usa esta estructura para facilitar cálculos de pérdida de calorías.
	double horas;
	double minutos;
};

//FUNCIONES
//Se declaran las funciones que se utilizan a lo largo de todo el código.
void ingesta_calorias(); 
void validacion_ingesta(bool&, string, string, string);
void validacion_quema(bool&, string, string);

void quema_calorias();
void registro_rendimiento();

int contadorx = 0; //Este contador bloquea la segunda opción del menú si no se ha accesado a la tercera primero.
int opcionR; //Menú
// Se declaran los nombres de los datos de estructuras:
usuario datos;
tiempo tiempo_entr;
int main()
{
	char OP = 0;
	string input;
	do
	{//Se imprime el menú
		system("cls");
		cout << "\n ********************** Menu Principal **************************\n";
		cout << "                    1. Ingesta de calorias\n";
		cout << "                    2. Quema de calorias\n";
		cout << "                    3. Registro de rendimiento\n";
		cout << "                    4. Salir\n ";
		cout << "                      Ingrese una opcion: ";
		cin >> input; //Lee la opción del menú.
		if (input.length() == 1)
		{
			OP = input[0];
			switch (OP) //utilizamos un switch con la finalidad de crear diferentes menus que sean amigables con el usuario
			{
			case '1': //Para la ingesta de calorias, pedimos datos al usuario para conocer las calorias que deben consumir y las que consumen
				ingesta_calorias();
				break;
			case '2': //Primero se debe registrar un rendimiento. Luego se determinan las calorías quemadas en cada sesión.
				quema_calorias();
				break;
			case '3':
				registro_rendimiento(); //Se registran los ejercicios y las repeticiones que se hizo en cada ejercicio.
				break;
			case '4':
				break;
			default://En caso de ingresar una opsión inválida
				cout << "Opcion no valida, por favor ingrese otra opcion." << endl;
				system("pause");
				break;
			}
		}
		else //En caso de ingresar una opsión inválida
		{
			cout << "Opcion no valida, por favor ingrese otra opcion." << endl;
			system("pause");
		}

	} while (OP != '4');
	system("PAUSE");
	return 0;
	system("cls");
	cout << "Recuerda que para mantener un estilo de vida saludable la ingesta de calorias debe ser mayor a la quema de calorias en el gimnasio.\nConsulta a un especialista para obtener ayuda." << endl;
	cout << "Gracias por usar el programa\n\n";
}

double peso, altura, anios;
void ingesta_calorias() //Se manda a llamar desde la opción 1. Aquí se registran las calorías correspondientes.
{
	float calorias_consumidas = 0, calorias_necesarias; //Se declaran variables como númeors
	char genero = ' ', opcionI, prot, verd, gras, carb; //Para las validaciones, estas variables se registran primero como char
	string in, in_peso, in_altura, in_anios, in_prot, in_verd, in_gras, in_carb; //Para las validaciones, estas variables se registran primero como strings
	bool valido;
	do
	{
		system("cls");
		cout << "------------------BIENVENIDO A TU REGISTRO DE INGESTA DE CALORIAS--------------------\n";
		cout << "Primero, hay que conocer la cantidad de calorias que necesitas. Eres hombre o mujer?";
		cout << "\n1. Hombre \n2. Mujer" << endl;
		cin >> in; //Preguntamos el genero, y usamos un switch para la opcion elegida
		if (in.length() == 1)
		{
			genero = in[0];
			switch (genero)
			{
			case '1':
				do //La acción se repite hasta que se regrese la función con valores válidos.
				{
					valido = true;
					system("cls");
					cout << "Para los hombres, la formula es la siguiente:\n 66 + (13.7 x peso corporal en kg) + (5 x altura en cm) - (6.75 x edad en anios)" << endl;
					cout << "Ingresa tu peso corporal en kilogramos: ";
					cin >> in_peso;
					cout << "Ingresa tu altura en cm: ";
					cin >> in_altura;
					cout << "Ingresa tu edad en anios: ";
					cin >> in_anios;
					validacion_ingesta(valido, in_peso, in_altura, in_anios); //Se manda a llamar la función de validación
				} while (!valido);

				calorias_necesarias = 66 + (13.7 * peso) + (5 * altura) - (6.75 * anios); //Formula obtenida en internet
				cout << "La cantidad de calorias que necesitas es: " << calorias_necesarias << endl;
				system("pause");
				break;
			case '2':
				do//La acción se repite hasta que se regrese la función con valores válidos.
				{
					valido = true;
					system("cls");
					cout << "Para las mujeres, la formula es la siguiente:\n 655 + (9.6 x peso corporal en kg) + (1.8 x altura en cm) - (4.7 x edad en anios)" << endl;
					cout << "Ingresa tu peso corporal en kilogramos: ";
					cin >> in_peso;
					cout << "Ingresa tu altura en cm: ";
					cin >> in_altura;
					cout << "Ingresa tu edad en anios: ";
					cin >> in_anios;
					validacion_ingesta(valido, in_peso, in_altura, in_anios); //Se manda a llamar la función de validación
				} while (!valido); //Permite continuar una vez sea válido.

				calorias_necesarias = 655 + (9.6 * peso) + (1.8 * altura) - (4.7 * anios); //Formula obtenida en internet
				cout << "La cantidad de calorias que necesitas es: " << calorias_necesarias << endl;
				system("pause");
				break;
			default: //En caso de no haber obtenido una respuesta válida del usuario.
				cout << "Opcion no valida. Por favor intenta de nuevo." << endl;
				system("pause");
				break;
			}
		}
		else //En caso de no haber obtenido una respuesta válida del usuario
		{
			cout << "Opcion no valida. Por favor intenta de nuevo." << endl;
			system("pause");
		}

	} while (genero != '1' && genero != '2');

	do
	{ //Usamos un ciclo do while para que el usuario pueda ingresar las opciones varias veces
		system("cls");
		cout << "Ahora, veamos la cantidad de calorias que consumes. Ingresa cada opcion las veces necesarias." << endl;
		cout << "1. Proteinas \n2. Frutas y Verduras \n3. Grasas \n4. Hidratos de carbono \n5. Salir" << endl; //Submenu para que el usuario elija el tipo de alimento
		cout << "Cantidad acumulada: " << calorias_consumidas << endl;
		cout << "Opcion: ";
		cin >> in;
		if (in.length() == 1) //Permite que sólo se ingresen valores de un sólo carácter
		{
			opcionI = in[0];
			switch (opcionI)
			{
			case '1': //Se busca como char para validar
				do
				{   //Aqui, el usuario puede elegir las veces necesarias cada alimento por cada 100 gramos y se van sumando las calorias hasta que decida salir
					system("cls");
					cout << "1. Pollo (100 gramos = 239 calorias)" << endl;
					cout << "2. Carne (100 gramos = 143 calorias)" << endl;
					cout << "3. Pescado (100 gramos = 206 calorias)" << endl;
					cout << "4. Lacteos (100 gramos = 46 calorias)" << endl;
					cout << "5. Huevo (100 gramos = 155 calorias)" << endl;
					cout << "6. Salir" << endl;
					cin >> in_prot;
					if (in.length() == 1)
					{
						prot = in_prot[0]; //En cada uno de los casos se calculan e imprimen las calorías consumidas, y se agregan al total
						switch (prot)
						{
						case '1':
							calorias_consumidas += 239;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '2':
							calorias_consumidas += 143;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '3':
							calorias_consumidas += 206;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '4':
							calorias_consumidas += 46;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '5':
							calorias_consumidas += 155;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '6':
							break;
						default:
							cout << "Opcion no valida. Por favor intenta de nuevo." << endl;
							system("pause"); //En caso de no haber obtenido una respuesta válida del usuario.
							break;
						}
					}
					else
					{
						cout << "Opcion no valida. Por favor intenta de nuevo." << endl;//En caso de no haber obtenido una respuesta válida del usuario.
						system("pause");
					}
				} while (prot != '6');
				break;
			case '2':
				do
				{   //Aqui, el usuario puede elegir las veces necesarias cada alimento por cada 100 gramos y se van sumando las calorias hasta que decida salir
					system("cls");
					cout << "1. Espinacas (100 gramos = 23 calorias)" << endl;
					cout << "2. Lechuga (100 gramos = 15 calorias)" << endl;
					cout << "3. Manzana (100 gramos = 52 calorias)" << endl;
					cout << "4. Platano (100 gramos = 89 calorias)" << endl;
					cout << "5. Limon (100 gramos = 29 calorias)" << endl;
					cout << "6. Salir" << endl;
					cin >> in_verd;
					if (in_verd.length() == 1) //Este paso se añade como paso de seguridad extra.
					{
						verd = in_verd[0];
						switch (verd)
						{
						case '1':
							calorias_consumidas += 23;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '2':
							calorias_consumidas += 15;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '3':
							calorias_consumidas += 52;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '4':
							calorias_consumidas += 89;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '5':
							calorias_consumidas += 29;
							cout << "Cantidad agregada." << endl; system("pause");
							break;
						case '6':
							break;
						default:
							cout << "Opcion no valida. Por favor intenta de nuevo." << endl;
							system("pause");
							break;
						}
					}
				} while (verd != '6'); //Se rompe el ciclo
				break;
			case '3': //Aqui, el usuario debe ingresar las grasas que consume en gramos y se hace el calculo en calorias
				system("cls");
				cout << "Que cantidad de grasas consumes en gramos? (1 gramo = 9 calorias): ";
				cin >> in_gras;
				valido = true;
				for (int i = 0; i < in_gras.length(); i++) //Este bloque se dedica a validar que el gramaje indicado sea de un valor correcto.
				{
					if (!isdigit(in_gras[i]))
					{
						valido = false;
					}
				}
				if (valido) //Si es válido, se procede a la siguiente validación
				{
					gras = stoi(in_gras);
					if (gras < 0) //Comprueba que sea un número positivo el ingresado.
					{
						valido = false;
					}
				}
				if (!valido) //Se marca como inválido y se repite la operación
				{
					cout << "Cantidad no valida. Por favor vuelve a intentar." << endl; system("pause");
				}
				else //Se declara válido y continúa.
				{
					calorias_consumidas += gras * 9;
					cout << "Cantidad agregada." << endl; system("pause");
				}

				break;
			case '4': //Aqui, el usuario debe ingresar los carbohidratos que consume en gramos y se hace el calculo en calorias
				system("cls");
				cout << "Que cantidad de carbohidratos consumes en gramos? (1 gramo = 4 calorias): ";
				cin >> in_carb;
				valido = true;
				for (int i = 0; i < in_carb.length(); i++) //Comprueba que la cantidad de carbohidratos perteneza a números
				{
					if (!isdigit(in_carb[i]))
					{
						valido = false;
					}
				}
				if (valido) //Si lo anterior es válido, se procede con la siguiente validación.
				{
					carb = stoi(in_carb); //Comprueba que el número ingresado sea positivo
					if (carb < 0)
					{
						valido = false;
					}
				}
				if (!valido)//Se declara el valor dado como inválido, se repite el proceso.
				{
					cout << "Cantidad no valida. Por favor vuelve a intentar." << endl; system("pause");
				}
				else //Se declara el valor dado como válido, continúa el programa.
				{
					calorias_consumidas += carb * 4;
					cout << "Cantidad agregada." << endl; system("pause");
				}

				break;
			case '5':
				break;
			default://En caso de no haber obtenido una respuesta válida del usuario.
				cout << "Opcion no valida. Por favor intenta de nuevo." << endl;
				system("pause");
				break;
			}
		}
		else//En caso de no haber obtenido una respuesta válida del usuario.
		{
			cout << "Opcion no valida. Por favor intenta de nuevo." << endl;
			system("pause");
		}

	} while (opcionI != '5');
}

//La siguiente función se encarga de validar que todos los valores obtenidos en ingesta sean números positivos.
void validacion_ingesta(bool& valido, string in_peso, string in_altura, string in_anios)
{

	for (int i = 0; i < in_peso.length(); i++) //Revisa que el valor ingresado para peso sea un número.
	{
		if (!isdigit(in_peso[i]) && in_peso[i] != '.')
		{
			valido = false; //Se declara como falso
		}
	}
	for (int i = 0; i < in_altura.length(); i++) //Se revisa que la altura sea un número.
	{
		if (!isdigit(in_altura[i]) && in_altura[i] != '.')
		{
			valido = false;
		}
	}
	for (int i = 0; i < in_anios.length(); i++) //Revisa que el valor ingresado como años sea un número
	{
		if (!isdigit(in_anios[i]) && in_anios[i] != '.')
		{
			valido = false;
		}
	}
	if (valido) //Si todos los anteriores son correctos, siguen las siguientes validaciones
	{
		peso = stod(in_peso);
		altura = stod(in_altura);
		anios = stod(in_anios);
		if (peso < 0 || altura < 0 || anios < 0) //Se revisa que todos los números dados sean mayores a cero
		{
			valido = false;
		}
		else //Se aceptan y se continúa con el código
		{
			usuario temp = { peso, altura, anios };
			datos = temp;
		}
	}
	if (!valido) //Los valores ingresados se declaran como inválidos y se repite la función.
	{
		cout << "Uno de los datos que ingresaste es invalido. Por favor vuelve a ingresar tus datos." << endl;
		system("pause");
	}
}

void quema_calorias()
{
	if (contadorx != 0) //Se usa este condicional para evitar que se registren quemas de calorias sin ejercicio previo
	{
		system("cls");

		string calculo_cal[3][2] = { {"1","0"},{"2","0"},{"3","0"} };
		string calculos[3] = { "horas", "minutos", "calorias quemadas" };
		//	De acuerdo a nuestra investigacion, establecimos una relacion para aproximar las calorias quemadas por minuto y hora
		cout << "\t\tQuema de Calorias" << endl;
		bool valido2;
		do
		{
			valido2 = true; //Se crea el bool de validación para los datos de horas y minutos
			cout << "Por cuanto tiempo ejercitaste?\n1. Horas: ";
			cin >> calculo_cal[0][1];
			cout << "2. Minutos: ";
			cin >> calculo_cal[1][1];
			validacion_quema(valido2, calculo_cal[0][1], calculo_cal[1][1]);
			system("cls");

		} while (!valido2);

		switch (opcionR) //Se usa la opcion ingresada anteriormente en registro de entrenamiento
		{
		case 1:
			cout << "----> Tren superior <----" << endl;
			cout << "\nEn una sesion de entrenamiento de 30 minutos se queman alrededor de 30 calorias." << endl;
			datos.calorias = 5 * tiempo_entr.minutos + 300 * tiempo_entr.horas;
			//Se hace el calculo aproximado de calorias quemadas.
			cout << "Has quemado aproximadamente " << datos.calorias << " calorias" << endl;
			cout << "Recuerda que la quema de calorias puede variar de acuerdo a tu peso, edad y tiempo efectivo de ejercicio por sesion." << endl;
			system("pause");
			break;
		case 2:
			cout << "\nTren inferior" << endl;
			cout << "\nIncluyendo superseries y ejercicios compuestos, puedes llegar a quemar entre 350 y 700 calorias en una sesion de una hora." << endl;
			datos.calorias = 8 * tiempo_entr.minutos + 525 * tiempo_entr.horas;
			//Se hace el calculo aproximado de calorias quemadas.
			cout << "Has quemado aproximadamente " << datos.calorias << " calorias" << endl;
			cout << "Dependiendo de tu peso y de la intensidad del ejercicio, puedes llegar a quemar muchas calorias en un entrenamiento de piernas. ";
			system("pause");
			break;
		default://En caso de no haber obtenido una respuesta válida del usuario.
			cout << "Opcion no valida!" << endl;
			system("pause");
			break;
		}


	}
	else { //En caso de no haber registrado primero rendimiento
		cout << "\n\t\tQuema de Calorias" << endl;
		cout << "Primero accede a la opcion 3 del menu." << endl;
		system("pause");
	}
}

void registro_rendimiento()
{
	//MEMORIA DINÁMICA
	//Se declaran las variables que se van a usar:
	double* producto, * pesos;
	int mayor = 0, menor = 0;
	string* ejercicios;
	int* series;
	series = (int*)calloc(4, 4 * sizeof(int));
	producto = (double*)calloc(4, 4 * sizeof(double));
	pesos = (double*)calloc(4, 4 * sizeof(double));
	ejercicios = (string*)calloc(4, 1 * sizeof(string));
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




//Esta función comprueba que los valores iniciados en quema de calorías sean válidos
void validacion_quema(bool& valido, string in_horas, string in_minutos)
{
	for (int i = 0; i < in_horas.length(); i++) //Se comprueba que las horas sean un número
	{
		if (!isdigit(in_horas[i]) && in_horas[i] != '.')
		{
			valido = false;
		}
	}
	for (int i = 0; i < in_minutos.length(); i++) //Se comprueba que el valor dado para minutos sea válido.
	{
		if (!isdigit(in_minutos[i]) && in_minutos[i] != '.')
		{
			valido = false;
		}
	}
	if (valido) //Si lo anterior se comprobó, se continúa con las siguientes validaciones:
	{
		double horas = stod(in_horas);
		double minutos = stod(in_minutos);
		if (horas < 0 || minutos <= 0) //Comprueba que los valores dados para minutos y segundos sean mayores a cero.
		{
			valido = false;
		}
		else //Se fuardan los valores dentro de la estructura de tiempo.
		{
			tiempo temp = { horas, minutos };
			tiempo_entr = temp;
		}
	}
	if (!valido)////En caso de no haber obtenido una respuesta válida del usuario.
	{
		cout << "Uno de los datos que ingresaste es invalido. Por favor vuelve a ingresar tus datos." << endl;
		system("pause");
	}
}