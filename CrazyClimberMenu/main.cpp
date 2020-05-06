#include <iostream>
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
void menu_score();

int main()
{
   menu_principal();

   return 0;
}

void menu_principal()
{
   bool repite = true;
   int opcion;

   // Titulo del menú y nombres de las opciones
   const char *titulo = "                                 Crazy Climber MENU";
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
            menu_score();
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
    const char *titulo = "Jugar!!";
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
    const char *titulo = "INSTRUCCIONES!!";
    const char *opciones[] = {"Instrucciones", "Regresar"};
    int n = 2;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion) {
            case 1:
                cout << "Press F to pray respects";
                cout <<endl<< "Casual W A S D ";
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
    const char *titulo = "CREDITOS!!";
    const char *opciones[] = {"Creditos", "Regresar"};
    int n = 2;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion) {
            case 1:
                cout<< "Gracias por jugar nuestro grandiosa version de Crazy Climber :D"<<endl;
                cout << "Desarrollado como proyecto final para la carrera de Ing. en desarrollo de software de la UABCS"<<endl;
                cout<< "Integrantes del equipo: "<<endl;
                cout <<endl<< "Angel Aviles"<<endl;
                cout <<endl<< "Brenda Gonzalez"<<endl;
                cout <<endl<< "Juan Pedrin"<<endl;
                system("pause>nul");
                break;

            case 2:
                repite = false;
                break;
        }

    } while(repite);
}

void menu_score()
{
    bool repite = true;
    int opcion;

   // Titulo del menú y nombres de las opciones
    const char *titulo = "SCORE!!";
    const char *opciones[] = {"score", "Regresar"};
    int n = 2;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion) {
            case 1:
                cout << "1.- CJ: 532200 pts."<<endl;
                cout << "2.-Rem: 514190 pts."<<endl;
                cout << "3.-Manuel: 482997 pts."<<endl;
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
      system("color 0e");
      gotoxy(5, 3 + opcionSeleccionada); cout << "                                        ==>" << endl;

      // Imprime el título del menú
      gotoxy(15, 2); cout << titulo;

      // Imprime las opciones del menú
      for (int i = 0; i < n; ++i) {
         gotoxy(50, 4 + i); cout << i + 1 << ") " << opciones[i];
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
