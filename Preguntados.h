#ifndef HH_Preguntados
#define HH_Preguntados
#include "Videojuego.h"
#include <iostream>
#include <string.h>


 class Preguntados : public VideoJuego {
   //ATRIBUTOS 
   private:
       int opcion;
       int preguntasAcertadas;
       int saberSisuperoMP = 1;
       int repetir = 0;
       int nVeces = 1;
       string nombreUsuario;

       vector<string> mejoresPuntajes {};
       vector<string> nombresPuntajes {};
       vector<string> interfaz {};
       vector<string> vetorTemporal {};
       vector<int> mejoresPuntajesOrdenados {};

       vector <string> respuestasITIVC {"B","C","C","C","A","C","C","C","D","B","C", "D","C","B","A","C","B","C","D","B"};
       vector <string> respuestaIpooVC {"A","C","D","D","A","A","A","A","B","D","D","D","B","B","C","D","A","C","C","C"};
       vector <string> respuestaMdiscretasVC {"A","D","A","B","A","A","A","B","A","C","B","A","B","D","A","A","A","A","D","D"};
       vector <string> respuestaFDPVC {"C","A","A","B","C","B","A","C","A","C","D","D","D","D","D","D","D","D","D","D"};
       vector <string> respuestaHistPcVC {"C","B","B","C","B","C","B","D","C","C","A","B","B","A","D","A","D","B","A","D"};


  // METODOS
   public:

       Preguntados();
      ~Preguntados();

       void interfazBienvenidad();
       void modoDeJuego();
       void preguntasITI();
       void preguntasIpoo();
       void preguntasMdiscretas();
       void preguntasFDP();
       void preguntasHistPc();
       void interfazFinal();
       void guardarMejoresPuntajes();
       void verificarRespuesta(vector<string> &);
       void iniciarJuego();
       void ordenarMejoresPuntajes();
       void f();
       void verficarSiLaOpcionEsNumero();
       void verificarSiCategoriaEsValida();



 };

 #endif