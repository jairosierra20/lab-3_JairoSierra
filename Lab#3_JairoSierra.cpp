#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std:: string;
#include <vector>
using std::vector;
  int menu();
  int ejercicio1(int, int);
  int ejercicio2(int);
  int ejercicio3();
  int* primos();
  int* inicializar(int);
int main()
{
	int opcion = 0;
	do{
		int a=0,b=0;
		int num=0;
		int* array=inicializar(25);
	switch(opcion=menu()){
		case 1:
			cout<<"Ingrese a: "<<endl;
			cin>>a;
			if(a<=0){
			cout<<"No se pueden ingresar negativos"<<endl;
			cout<<"Ingrese a: "<<endl;
                        cin>>a;
			}
			cout<<"Ingrese b: "<<endl;
			cin>>b;
			if(b<=0){
			  cout<<"No se permiten numeros negativos"<<endl;
			  cout<<"Ingrese b: "<<endl;
                        cin>>b;
			}
			cout<<"El MCD de los numeros ingresados es: "<<ejercicio1(a,b)<<endl;
	         break;
			case 2:
	                  cout<<"Ingrese el numero: "<<endl;
			  cin>>num;
			  if(num<=0){
			    cout<<"Ingrese el numero: "<<endl;
                          cin>>num;
			  }
	                   ejercicio2(num);
			 
			break;
				case 3:
					ejercicio3();
				break;
					case 4:
						cout<<"El programa se cerrara"<<endl;
					break;
	}
}while(opcion!=4);
	}
int menu(){
	while(true){
  	//cout<<"MENU"<<endl;
  	//mostrar tres opciones
  	//1.- Ejercicio1
  	//2.- Ejercicio2
  	//3.- Ejercicio3
  	//4.- salir
  	cout<<"MENU"<<endl
  	<<"1.- Ejercicio1"<<endl
  	<<"2.- Ejercicio2"<<endl
  	<<"3.- Ejercicio3"<<endl
  	<<"4.- salir"<<endl;
  	//pedir al usuario una opcion
  	cout<<"Ingrese una opcion: ";
  	int opcion =0;
  	//leer la opcion
  	cin>>opcion;
  	//validar la opcion
  	if(opcion>=1 && opcion<= 4){
  		//si es valido retornar
  		return opcion;
	  }
	  else{

  	//else mostrar mensaje de error al usuario
  	cout<<"La opcion elegida no es valida, ingrese un valor entre 1 y 4"<<endl;
  }
  }//end del while
  	return 0;
  }
int* inicializar(int size){
    int* tem = new int[size];
    return tem;
}

int ejercicio1(int a, int b){
   if(a<b){
      return ejercicio1(b,a);
   }
   else if(b==0){
      return a;
   }else{
      return ejercicio1(b,int(a%b));
   }
}
int* primos(){
  int* array=new int[25];
  //Se llena el array con los numeros primos
  array[0]=2;
  array[1]=3;
  array[2]=5;
  array[3]=7;
  array[4]=11;
  array[5]=13;
  array[6]=17;
  array[7]=19;
  array[8]=23;
  array[9]=29;
  array[10]=31;
  array[11]=37;
  array[12]=41;
  array[13]=43;
  array[14]=47;
  array[15]=53;
  array[16]=59;
  array[17]=61;
  array[18]=67;
  array[19]=71;
  array[20]=73;
  array[21]=79;
  array[22]=83;
  array[23]=89;
  array[24]=97;
  return array;
}
int ejercicio2(int num){
	int contador=0;//variable para los elevados
	int a=0;//variable para la posicion del arreglo de primos
   int* array = primos();//arreglo de primos
  cout<<num<<"= ";
   while(num>1){
      if(num%array[a]==0){
         contador++;
	 num=num/array[a];
      }else{
	if(contador!=0){
	     cout<<"("<<array[a]<<"^"<<contador<<")*";
	  }
        a++;
	contador=0;
      }
   }
   cout<<"("<<array[a]<<"^"<<contador<<")";

   cout<<endl;

   return 0;
}
int ejercicio3(){
	
   int opcion=0;//variable para la opcion del menu
   vector<string> arreglo1;
   vector<string> codigos;
   vector<string> continentes;
   while(opcion!=6){
   cout<<"Menu"<<endl;
   cout<<"1) Insertar una guerra"<<endl;
   cout<<"2) Buscar Guerra"<<endl;
   cout<<"3) Eliminar Guerra"<<endl;
   cout<<"4) Listar todas las guerras"<<endl;
   cout<<"5) Listar guerras por continentes"<<endl;
   cout<<"6) Salir"<<endl;
   cout<<"Ingrese una opcion: "<<endl;
   cin>>opcion;
   string codigo="",guerra="",anio1="",anio2="",paises="",cont="",pais="";//variables para los datos de las guerras
   int resp=1;//variable para ingresar los paises en el while
   string cadena="";//variable para guardar la cadena de forma bonita
   string cadena2="";//variable para guardar la cadena cpon ; y ,
   int pos=0;//variable para la posicion que el usuario eliminara
   switch(opcion){
     case 1:
	     cout<<"Ingrese el codigo: "<<endl;
	     cin>>codigo;
	     codigos.push_back(codigo);
	     cadena2+=codigo+";";
	     cout<<"Ingrese nombre de la guerra: "<<endl;
	     cin>>guerra;
	     cadena2+=guerra+";";
	     cout<<"Ingrese año de inicio: "<<endl;
	     cin>>anio1;
	     cadena2+=anio1+";";
	     cout<<"Ingrese año de fin: "<<endl;
	     cin>>anio2;
	     cadena2+=anio2+";";
	     while(resp==1){
	        cout<<"Ingrese el pais: "<<endl;
		cin>>pais;
		cadena2+=pais+",";
		paises+=pais+",";
		cout<<"Continua [1/0]"<<endl;
		cin>>resp;
	     }
	     cadena2+=";";
	     cout<<"Ingrese el continente: "<<endl;
	     cin>>cont;
	     continentes.push_back(cont);
	     cadena2+=cont+";";
	     cadena+="Guerra de "+guerra+" llevada a cabo entre "+anio1+" y "+anio2+" donde participaron "+paises+" en el continente de "+cont;
	     arreglo1.push_back(cadena);
	     break;
     case 2:
	     cout<<"Ingrese el codigo de la guerra que desea buscar :"<<endl;
	     cin>>codigo;
	     for(int i=0;i<codigos.size();i++){
	       if(codigos[i]==codigo){
	         cout<<i<<"- "<<arreglo1[i]<<endl;
	       }
	     }
	     
	     break;
     case 3:
	     cout<<"Ingrese la posicion que desea eliminar "<<endl;
             cin>>pos;
	     arreglo1.erase(arreglo1.begin()+pos);
	     cout<<"Se elimino exitosamente"<<endl;
	     break;
     case 4:
	     for(int i=0;i<arreglo1.size();i++){
	       cout<<i<<"- "<<arreglo1[i]<<endl;
	     }
	     break;
     case 5:
	     cout<<"Ingrese el continente que quiere buscar: "<<endl;
	     cin>>cont;
	     for(int i=0;i<continentes.size();i++){
	       if(continentes[i]==cont){
	         cout<<i<<"- "<<arreglo1[i]<<endl;
	       }
	     }

        }
   }
}

