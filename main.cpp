#include <iostream>
#include <stdlib.h>
#include <locale>
#include "Videojuego.h"
#include "Preguntados.h"
#include <wchar.h>

using namespace std;


int main () {

  setlocale(LC_CTYPE, "spanish");

setlocale(LC_ALL, "");
  Preguntados p1;
  p1.interfazBienvenidad();
  p1.ordenarMejoresPuntajes();


  system("pause");
  return 0;

}