#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define ARRIBA 'w'
#define ABAJO 's'
#define IZQUIERDA 'a'
#define DERECHA 'd'
#define ENTER 13

using namespace std;

int azar(int a){
    a=rand()%15+3;
    return a;
}
int azarb(int b){
    b=rand()%15+5;
    return b;
}
int azarc(int c){
    c=rand()%15+3;
    return c;
}
int azard(int d){
    d=rand()%15+5;
    return d;
}

char getch2 ()
{
   char c=0;
   DWORD modo, contador;
   HANDLE ih = GetStdHandle(STD_INPUT_HANDLE);

   SetConsoleMode (ih, modo & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

   ReadConsoleA (ih, &c, 1, &contador, NULL);

   if (c == 0) {
      ReadConsoleA (ih, &c, 1, &contador, NULL);
   }

   SetConsoleMode (ih, modo); // Devolvemos control normal

   return c;
}

int gotoxy(USHORT x,USHORT y) {
   COORD cp = {x,y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
 }

int menu(const char titulo[], const char *opciones[], int n);
void menu_principal();
void menu_jugar();
void menu_instrucciones();
void menu_creditos();
void menu_score(string nombre[5],string recor[5]);



void menu_principal()
{
   bool repite = true;
   int opcion;
    string nombre[5],recor[5];
    for(int x=0;x<5;x++){
        nombre[x]=" ";
        recor[x]=" ";
   }
   // Titulo del menú y nombres de las opciones
   const char *titulo = "                                                                                                                                 \n                                                                                                                                 \n    //   ) )                                               //   ) )                                                              \n   //            __        ___     ___                    //           //     ( )      _   __       / __        ___        __    \n  //           //  ) )   //   ) )    / /    //   / /     //           //     / /     // ) )  ) )   //   ) )   //___) )   //  ) ) \n //           //        //   / /    / /    ((___/ /     //           //     / /     // / /  / /   //   / /   //         //       \n((____/ /    //        ((___( (    / /__       / /     ((____/ /    //     / /     // / /  / /   ((___/ /   ((____     //        ";
   const char *opciones[] = {"Jugar", "Instrucciones", "Creditos", "Score", "Salir"};
   int n = 5;  // Numero de opciones

   do {
      opcion = menu(titulo, opciones, n);

      switch (opcion) {
         case 1:
            menu_jugar();
            break;


         case 2:
            menu_instrucciones();
            break;

         case 3:
            menu_creditos();
            break;

         case 4:
            menu_score(nombre,recor);
            break;

         case 5:
            cout << " El programa se cerrara!! ADIOS" << endl;
            repite = false;
            system("pause>nul");
            break;
      }

   } while(repite);
}

void menu_jugar()
{
    bool repite = true;
    int opcion;

   // Titulo del menú y nombres de las opciones
    const char *titulo = "\n          / /     //   / /     //   ) )     // | |     //   ) ) \n         / /     //   / /     //           //__| |    //___/ /  \n        / /     //   / /     //  ____     / ___  |   / ___ (    \n       / /     //   / /     //    / /    //    | |  //   | |    \n ((___/ /     ((___/ /     ((____/ /    //     | | //    | |    ";
    const char *opciones[] = {"Jugar", "Regresar"};
    int n = 2;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion) {
            case 1:
                {
                ///////////////////////////////////////////////////////////////////////
                int dificultad;
                cout << "                            ---Seleccione el tipo de dificultad--"<<endl<<endl;
                cout << "1.- Facil.(Empiezas con 20k de puntos, raramente las ventanas oscilan)."<<endl<<endl;
                cout << "2.- Normal.(Empiezas con 18k de puntos, las ventanas oscilan con regularidad)."<<endl<<endl;
                cout << "3.- Pesadilla.(Empiezas con 15k de puntos, Absolute chaos)."<<endl<<endl;
                cout << "Eleccion: ";
                cin >> dificultad;
                system("cls");
                int score=0;
                if(dificultad==1){
                    score=20000;
                }else if(dificultad==2){
                    score=18000;
                }else if(dificultad==3){
                    score=15000;
                }

                int pisos=30;
                int ancho=38;
                int a=0;
                int b=0;
                int c=0;
                int d=0;
                int x=pisos-2,y=ancho-10,azarx=0,azary=0,cont=0;
                int contx[38]={0}; int conty[38]={0};
                int contx2[38]={0}; int conty2[38]={0};
                int contx3[38]={0}; int conty3[38]={0};
                int contx4[38]={0}; int conty4[38]={0};
                bool power=true;
                int tecla;
                int aux[pisos][ancho];
                int trampa=0;
                while(power){

                    score=score-(cont*10);
                    cout << "SCORE: "<<score<<" puntos."<<endl;

                    char mapilla[pisos][ancho];
                    //Ciclo para imprimir un mapa.


                    for (int i=0;i<pisos;i++){
                        for(int j=0;j<ancho;j++){

                            if(dificultad==1){
                                if(cont==0 || cont%13==0){
                                contx[j]=azar(a);
                                conty[j]=azarb(b);

                                contx3[j]=azarc(c);
                                conty3[j]=azard(d);

                            }
                            }else if(dificultad==2){
                                if(cont==0 || cont%11==0){
                                contx[j]=azar(a);
                                conty[j]=azarb(b);

                                contx3[j]=azarc(c);
                                conty3[j]=azard(d);

                            }
                            }else if(dificultad==3){
                                if(cont==0 || cont%2==0){
                                contx[j]=azar(a);
                                conty[j]=azarb(b);

                                contx3[j]=azarc(c);
                                conty3[j]=azard(d);

                            }
                            }

                            if(i==x && j==y){
                                mapilla[i][j] = '*'; //Debería mandar la posicion del jugador a mapilla
                                if(aux[i][j]==2){
                                    trampa=3;
                                }else{
                                    trampa=0;
                                }

                            }else if(i==pisos-1 && j==0){    //Imprime la esquinita inferior izquierda
                                mapilla[i][j] = char(200);
                                aux[i][j]=1;
                            }else if(i==pisos-1 && (j>0 && j<ancho/2) || i==pisos-1 && (j>ancho/2 && j<ancho-1)){  //Imprime covertura del edificio arriba y abajo.
                                mapilla[i][j] = char(205);
                                aux[i][j]=1;
                            }else if(i==pisos-1 && j==ancho-1){  //Imprime la esquinita inferior derecha
                                mapilla[i][j] = char(188);
                                aux[i][j]=1;
                            }else if(i==pisos-1 && j==ancho/2){  //Imprime la esquinita doble de en medio
                                mapilla[i][j] = char(202);
                                aux[i][j]=1;
                            }else if(i>=0 && i<pisos-1 && j==0){ //Imprime la cobertura del edificio de la izquierda
                                mapilla[i][j] = char(186);
                                aux[i][j]=1;
                            }else if(i>=0 && i<pisos-1 && j==ancho-1){ //Imprime la cobertura del edificio de la derecha
                                mapilla[i][j] = char(186);
                                aux[i][j]=1;
                            }else if(i>=0 && i<pisos-1 && j==ancho/2){ //Imprime la cobertura del edificio del medio
                                mapilla[i][j] = char(186);
                                aux[i][j]=1;
                            }else if(i>=3 && i<(pisos-contx[i]) && j==(ancho-conty[i]) || //Imprime las ventanas del edificio de la derecha
                                     i>=3 && i<(pisos-contx[i]) && j==(conty[i]) &&
                                     (i==x && j==y)==false)
                            {
                                mapilla[i][j] = char(219);
                                contx2[i]=contx[i]; conty2[i]=conty[i]; //Almacena las posiciones de las ventanas para el sig if
                                aux[i][j]=2;
                                //trampa=3;
                            }else if(i>=3 && i<(pisos-contx2[i]) && j==(ancho-conty2[i]) && ((cont%11==0)==false ) && (i==x && j==y)==false){ //Imprime las ventanas
                                mapilla[i][j] = char(219);
                                contx2[i]=contx[i]; conty2[i]=conty[i];
                                aux[i][j]=2;
                                //trampa=3;

                            }else{ //Imprime los espacios
                                mapilla[i][j] = char(176);
                                aux[i][j]=0;
                            }
                            cout << mapilla[i][j];
                        }
                    cout<<endl;
                }
                    do {
                     tecla = getch2();
                  } while (tecla != DERECHA && tecla != IZQUIERDA && tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

                    switch (tecla) {

                     case ARRIBA:   // En caso que se presione ARRIBA
                         if(x!=1){
                            if(trampa==3){
                                x=x+3;
                            }else{
                                x--;
                            }
                             //Cuando disminuye la equis sube el asterisco.
                         }
                        break;

                     case ABAJO: // En caso que se presione ABAJO
                        if(x!=pisos-2){
                            if(trampa==3){
                                x=x+3;
                            }else{
                                x++;
                            } //Cuando aumenta la equis baja el asterisco.
                        }
                        break;

                     case IZQUIERDA:
                         if(y!=1){
                            if(trampa==3){
                                x=x+3;
                                y--;
                            }else{
                                y--;
                            }
                         }
                        break;

                     case DERECHA:
                         if(y!=ancho-2){
                            if(trampa==3){
                                x=x+3;
                            }else{
                                y++;
                            }
                         }
                        break;

                     case ENTER:
                        power = false;
                        break;
                  }
                  system("cls");
                  if(x==1){
                    system("cls");
                    cout <<endl<<endl<<"SIGUIENTE NIVEL!(ingrese cualquier valor para continuar)";
                    cin >> a;
                    power = false;
                  }else if(score<=0){
                      power = false;
                  }
                  cont++;

                }
                //////////////////////////////////////////////////////////////////////////////////////////////
                if(score<=0){
                    power = false;
                    cout << endl <<"NOOB, juego terminado."<<endl;
                    cin >> x;
                }else{
                    power = true;
                }
                x=pisos-2;
                    while(power){
                    score=score-(cont*10);
                    cout << "SCORE: "<<score<<" puntos."<<endl;
                    char mapilla[pisos][ancho];
                    int aux[pisos][ancho];
                    int trampa=0;
                    //Ciclo para imprimir un mapa.

                    cout<<endl<<endl;

                    for (int i=0;i<pisos;i++){
                        for(int j=0;j<ancho;j++){

                            if(dificultad==1){
                                if(cont==0 || cont%13==0){
                                contx[j]=azar(a);
                                conty[j]=azarb(b);

                                contx3[j]=azarc(c);
                                conty3[j]=azard(d);

                            }
                            }else if(dificultad==2){
                                if(cont==0 || cont%11==0 || cont%23==0 || cont%31==0){
                                contx[j]=azar(a);
                                conty[j]=azarb(b);

                                contx3[j]=azarc(c);
                                conty3[j]=azard(d);

                            }
                            }else if(dificultad==3){
                                if(cont==0 || cont%2==0){
                                contx[j]=azar(a);
                                conty[j]=azarb(b);

                                contx3[j]=azarc(c);
                                conty3[j]=azard(d);

                            }
                            }

                            if(i==x && j==y){
                                mapilla[i][j] = '*'; //Debería mandar la posicion del jugador a mapilla
                                if(aux[i][j]==2){
                                    trampa=3;
                                }else{
                                    trampa=0;
                                }
                            }else if(i==0 && j==0 || i==0 && j==23){    //Imprime la esquinita superior izquierda
                                mapilla[i][j] = char(201);

                            }else if(i==20 && j==18){    //Imprime la esquinita doble del medio
                                mapilla[i][j] = char(203);

                            }else if(i==20 && j==14){    //Imprime la esquinita inferior derecha del primer edificio
                                mapilla[i][j] = char(200);

                            }else if(i==20 && j==23){    //Imprime la esquinita inferior izquierda del segundo edificio
                                mapilla[i][j] = char(188);

                            }else if(i==0 && j==ancho-1 || i==0 && j==14){  //Imprime la esquinita superior derecha
                                mapilla[i][j] = char(187);

                            }else if(i==0 && (j>0 && j<15) || i==0 && (j>23 && j<ancho-1) ||
                                     i==20 && (j>14 && j<18) ||
                                     i==20 && (j>18 && j<23)) //Imprime covertura del edificio arriba y abajo.
                            {
                                mapilla[i][j] = char(205);

                            }else if(i>=0 && i<pisos && j==0 || //Imprime la cobertura del edificio de la izquierda
                                     i>=0 && i<pisos && j==ancho-1 || //Imprime la cobertura del edificio de la derecha
                                     i>=20 && i<pisos && j==18 || //Imprime la cobertura del edificio del medio
                                     i>=0 && i<20 && j==14 || //Imprime la cobertura derecha del primer edificio
                                     i>=0 && i<20 && j==23) //Imprime la cobertura izquierda del segundo edificio
                                     {
                                mapilla[i][j] = char(186);

                            }else if((i>=0 && i<20)&&(j>14 && j<23)){ //Imprime los espacios vacios entre los edificios
                                mapilla[i][j] = ' ';

                            }else if(i>=3 && i<(pisos-contx[i]) && j==(ancho-conty[i]) || //Imprime las ventanas del edificio de la derecha
                                     i>=3 && i<(pisos-contx[i]) && j==(conty[i]) &&
                                     (i==x && j==y)==false)
                            {
                                mapilla[i][j] = char(219);
                                contx2[i]=contx[i]; conty2[i]=conty[i]; //Almacena las posiciones de las ventanas para el sig if
                                aux[i][j]=2; //las trampitas hehe

                            }else if(i>=3 && i<(pisos-contx2[i]) && j==(ancho-conty2[i]) && ((cont%11==0)==false)&&
                                     (i==x && j==y)==false){ //Imprime las ventanas
                                mapilla[i][j] = char(219);
                                contx2[i]=contx[i]; conty2[i]=conty[i];
                                aux[i][j]=2;//mas trampitas hehe

                            }else {
                                mapilla[i][j] = char(176); //Imprime los espacios rellenos entre los edificios
                            }
                            cout << mapilla[i][j]; //Imprime todo el mapa lol
                        }
                    cout<<endl;
                }
                    do {
                     tecla = getch2();
                  } while (tecla != DERECHA && tecla != IZQUIERDA && tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

                    switch (tecla) {

                     case ARRIBA:   // En caso que se presione ARRIBA
                         if(x!=1 && (x==21 && y>13 && y <24)==false){
                            if(trampa==3){
                                x=x+3;
                            }else{
                                x--;
                            } //Cuando disminuye la equis sube el asterisco.
                         }
                        break;

                     case ABAJO: // En caso que se presione ABAJO
                        if(x!=pisos-2){
                            if(trampa==3){
                                x=x+3;
                            }else{
                                x++;
                            }  //Cuando aumenta la equis baja el asterisco.
                        }
                        break;

                     case IZQUIERDA:
                         if(y!=1 && (x>=0 && x<21 && y==24)==false){
                            if(trampa==3){
                                x=x+3;
                                y--;
                            }else{
                                y--;
                            }
                         }
                        break;

                     case DERECHA:
                         if(y!=ancho-2 && (x>=0 && x<21 && y==13)==false){
                            if(trampa==3){
                                x=x+3;
                            }else{
                                y++;
                            }
                         }
                        break;

                     case ENTER:
                        power = false;
                        break;
                  }
                  system("cls");
                  if(x==1){
                    system("cls");
                    cout << "Haz ganado!"<<endl;
                    cout << "Tu Final Score fue de: "<<score<<" puntos. Felicidades!"<<endl;
                    cin >> x;
                    power = false;
                  }else if(score<=0){
                    power = false;
                    cout << endl <<"NOOB, juego terminado."<<endl;
                    cin >> x;
                }
                }
            }
                ///////////////////////////////////////////////////////////////////////
                break;
            case 2:
                repite = false;
                break;

        }

    } while(repite);
}

void menu_instrucciones()
{
    bool repite = true;
    int opcion;

   // Titulo del menú y nombres de las opciones
    const char *titulo = "                                                    \n                                                    \n    //    / /     //   ) ) ||   / |  / /      __    \n   //___ / /     //   / /  ||  /  | / /     ((  ) ) \n  / ___   /     //   / /   || / /||/ /         / /  \n //    / /     //   / /    ||/ / |  /         ( /   \n//    / /     ((___/ /     |  /  | /          ()    ";
    const char *opciones[] = {"Instrucciones", "Regresar"};
    int n = 2;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion) {
            case 1:
                cout<<titulo<<endl;
                gotoxy(10,8);cout << "\n\t\tI N S T R U C I O N E S \n\n";
                gotoxy(10,10);cout<<"\n\tBien venido a crazy climber\n\n\tPara pasar el nivel es necesario llegar a la asotea del edifico\n\t1.-Para eso Preciona W para escalar\n\t2.-presiona A o D para moverte hacia los lados Isquierda y derecha respectivamente\n\t3.-presiona S para bajar\n\t\n\tMientras escalas, ten cuidado con las ventanas,\n\tpues estas haran que caigas y pierdas tu valioso SCORE\n\tTienes una cantidad limitada de SCORE lograrlo\n\tuna ves llegues a la azotea habras ganado.\n\n\tPresciona enter para regresar.\n";
                system("pause>nul");
                break;

            case 2:
                repite = false;
                break;
        }

    } while(repite);
}

void menu_creditos()
{
    bool repite = true;
    int opcion;

   // Titulo del menú y nombres de las opciones
    const char *titulo = "                                                                                                \n                                                                                                \n    /|    //| |     // | |     //   / /     //   / /   //    ) )       //   ) ) \\    / /     \n   //|   // | |    //__| |    //__ / /     //____     //    / /       //___/ /   \\  / /      \n  // |  //  | |   / ___  |   //__  /      / ____     //    / /       / __  (      \\/ /    () \n //  | //   | |  //    | |  //   ) )     //         //    / /       //    ) )      / /        \n//   |//    | | //     | | //     ) )   //____/ /  //____/ /       //____/ /      / /     //  ";
    const char *opciones[] = {"Creditos", "Regresar"};
    int n = 2;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion) {
            case 1:
                cout<<titulo<<endl;
                cout<< "\n\t\tGracias por jugar nuestro grandiosa version de Crazy Climber :D\n\n\t\tDesarrollado como proyecto final para el curso de programacion I\n\n\t\tIntegrantes del equipo: \n\t\tAngel Aviles\n\t\tBrenda Gonzalez\n\t\tJuan Pedrin"<<endl;
                system("pause>nul");
                break;

            case 2:
                repite = false;
                break;
        }

    } while(repite);
}

void menu_score(string nombre[5],string recor[5])
{
    bool repite = true;
    int opcion;

   // Titulo del menú y nombres de las opciones
    const char *titulo = "                                                                              \n                                                                              \n    //   ) )     //   ) )     //   ) )     //   ) )     //   / /     //   ) ) \n   ((           //           //   / /     //___/ /     //____       ((        \n     ))        //           //   / /     / ___ (      / ____          ))      \n       ) )    //           //   / /     //   | |     //                 ) )   \n((___ / /    ((____/ /    ((___/ /     //    | |    //____/ /    ((___ / /    ";
    const char *opciones[] = {"score", "Regresar"};
    int n = 2;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion) {
            case 1:
                cout<<titulo<<endl;
                gotoxy(10,8);cout<<"\n\tNombre =  Puntuacion\n";
                for(int x=0;x<5;x++){
                    gotoxy(10,9+x);cout<<"\n\t"<<nombre[x]<<" = "<<recor[x];
                }
                system("pause>nul");
                break;

            case 2:
                repite = false;
                break;
        }

    } while(repite);
}

int menu(const char titulo[], const char *opciones[], int n)
{
   int opcionSeleccionada = 1;  // Indica la opcionSeleccionada

   int tecla;

   bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER


   do {
      system("cls");
      system("color 8f");
      gotoxy(10, 13 + opcionSeleccionada); cout << "=>" << endl;

      // Imprime el título del menú
      gotoxy(0,0); cout << titulo<<endl;

      // Imprime las opciones del menú
      for (int i = 0; i < n; ++i) {
         gotoxy(12, 14 + i); cout << i + 1 << ") " << opciones[i];
      }

      // Solo permite que se ingrese ARRIBA, ABAJO o ENTER

      do {
         tecla = getch2();
      } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

      switch (tecla) {

         case ARRIBA:   // En caso que se presione ARRIBA

            opcionSeleccionada--;

            if (opcionSeleccionada < 1) {
               opcionSeleccionada = n;
            }

            break;

         case ABAJO:
            opcionSeleccionada++;

            if (opcionSeleccionada > n) {
               opcionSeleccionada = 1;
            }

            break;

         case ENTER:
            repite = false;
            break;
      }

   } while (repite);

   return opcionSeleccionada;
}
int main()
{
   menu_principal();

   return 0;
}
