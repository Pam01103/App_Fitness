#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    int OP=0;
    
    do
    {
    	cout<<"\n ********************** Menu Principal **************************\n";
    	cout<<"                    1. Ingesta de calorias\n";
    	cout<<"                    2. Quema de calorias\n";
    	cout<<"                    3. Registro de rendimiento\n";
    	cout<<"                    4. Calculos ";
    	cin>>OP; 
    	//utilizamos un switch con la finalidad de crear diferentes menus que sean amigables con el usuario 
    	switch(OP)
    	{
    		case 1:break; 
    		case 2: break; 
    		case 3:
    		int opcionR;
    		// submenu 3 
    		system("cls");
    		cout<<"------------------BIENVENIDO A TU REGISTRO DE RENDIMIENTO--------------------\n";
    		cout<<"                 Cuentanos, que entrenaste el dia de hoy?\n";
    		cout<<"                           1.Tren superior...\n";
    		cout<<"                           2.Tren inferior...\n";
    		cin>>opcionR;
    		//submenu de diferentes entrenamientos
    		switch(opcionR)
    		{
    			case 1: 
    			string ejercicios[5];
    			int series[4];
    			double pesos[4];
    			system("cls");
    			cout<<"....................PERFECTO ESCOGISTE TREN SUPERIOR........................\n";
	    		cout<<"Se estima que para tener un entrenamiento correcto se espera un maximo de 5 ejercicios por sesion\n";
	    		cout<<"           Cada ejercicio debe consistir en 3 series de 8 a 12 repeticiones \n";
	    		cout<<"           En las cuales debes incrementar el peso semana a semana, aproximadamente 2.5 kg...\n";
	    		cout<<"           Esto te permitira tener un aumento de masa muscular y reduccion de grasa...\n"; 
	    		cout<<"                                                                                             \n";                  
				cout<<"           Sabiendo esto, cuentanos ¿Como estuvo tu entrenamiento?\n"; 
				     
	    		for(int i=0; i<1; i++)
	    		{
	    			cout<<"\n                        Ejercicio: \n";
	    			cin>> ejercicios[i];
	    			for (int j=0; j<2; j++)
	    			{
	    				cout<<"            Cuantas reps hiciste en tu serie #   "<<j+1<<" ?\n";
	    				cin>>series[j];
	    				for(int k=0; k<1;k++)
	    				{
	    					cout<<"         Cuanto peso cargaste en tu rep #   "<<k+1<<" ?\n";
	    					//solo se necesita preguntar una vez 
	    				    cin>>pesos[k];
						}
					}		
				}
				system("cls");
				cout<<"....................TUS DATOS SON LOS SIGUIENTES..........................\n";
				cout<<"\n............................EJERCICIOS..................................\n";
				for (int g =0; g<5; g++)
				{
					cout<<ejercicios[g]<<"\t";
				}
				cout<<"\n....................REPETICIONES EN 4 SERIES ...........................\n";
				for (int h =0; h<4; h++)
				{
					cout<<series[h]<<"\t";
				}
				cout<<"\n....................PESOS EN TUS REPETICIONES ..........................\n";
				for (int l =0; l<4; l++)
				{
					cout<<pesos[l]<<"kg"<<"\t";
				}
				
				//system("PAUSE");
    			break;
    			
			}
    		
    		
			break; 
    		case 4: break;
		}
		
	}while (OP!=5);
    system("PAUSE");
	return 0;
}
 
