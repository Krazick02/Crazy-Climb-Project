#include <iostream>#include <iostream>
#include <windows.h>

#define ARRIBA 'w'
#define ABAJO 's'
#define ENTER 13
using namespace std;

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
                cout << "PIUM PIUUM"<<endl;
                system("pause>nul");
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
                gotoxy(10,10);cout<<"\n\tBien venido a crazy climber\n\n\tPara pasar el nivel es necesario llegar a la azotea del edifico\n\t1.-Para eso Preciona W para escalar\n\t2.-presiona A o D para moverte hacia los lados Isquierda y derecha respectivamente\n\tMientras escalas, ten cuidado con los objetos que caen\n\tde las ventanas de los inquilinos, pues estas haran que caigas y pierdas una vida\n\tTienes tres vidas para lograrlo\n\tuna ves llegues a la azotea habras ganado,\n\n\tPresciona a para regresar.\n";
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
      system("color 1e");
      gotoxy(10, 13 + opcionSeleccionada); cout << "=>" << endl;

      // Imprime el título del menú
      gotoxy(0,0); cout << titulo;

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
                cout << "PIUM PIUUM"<<endl;
                system("pause>nul");
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
                gotoxy(10,10);cout<<"\n\tBien venido a crazy climber\n\n\tPara pasar el nivel es necesario llegar a la asotea del edifico\n\t1.-Para eso Preciona W para escalar\n\t2.-presiona A o D para moverte hacia los lados Isquierda y derecha respectivamente\n\tMientras escalas, ten cuidado con los objetos que caen\n\tde las ventanas de los inquilinos, pues estas haran que caigas y pierdas una vida\n\tTienes tres vidas para lograrlo\n\tuna ves llegues a la azotea habras ganado,\n\n\tPresciona a para regresar.\n";
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
      gotoxy(0,0); cout << titulo;

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
