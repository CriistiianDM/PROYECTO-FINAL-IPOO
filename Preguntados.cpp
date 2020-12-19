#include "Preguntados.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <locale>
#include <ctime>


//Constructor
Preguntados::Preguntados() {} 
//Destructor
Preguntados::~Preguntados() {}

/*Funcion de Tipo void
  Se encarga de Mostrar al Usuario la Interfaz de Bienvenida 
  Además de permitir seguir una ruta de las posibles opciones a escoger
*/
 void Preguntados::interfazBienvenidad() {

     fflush(stdin);
     system("cls");
     string nombreArchivo = "Interfaces.txt";
     abrirArchivos(interfaz,nombreArchivo);
     nVeces = 1;
     cout<<"\n";
     for (int i = 0 ; i < 15 ; i++) {
       cout<<"\t"<<interfaz[i]<<endl;
     }

     cout<<"\t      Inserte una opcion: "; cin>>opcion;
     verficarSiLaOpcionEsNumero();
     switch (opcion) {

       case 1:
       modoDeJuego();

       break;
       case 2:
       f();
       break;
       case 3:
       exit(1);
       break;

     }
 }
/*
  Funcion de Tipo void
  Esta Funcion Permite Seleccionar Que Tipo de Preguntas Desea Responder durante
  el juego
*/
  void Preguntados::modoDeJuego() {
     system("cls");
     fflush(stdin);

     cout<<"\n";
     if (repetir == 0) {
     for (int i = 15 ; i < 31 ; i++) {
       cout<<"\t"<<interfaz[i]<<endl;
     }

     cout<<"\t      INSERTE SU NOMBRE: "; cin>>nombreUsuario;
     }
     fflush(stdin);
     system("cls");

     cout<<"\n";
     for (int i = 31 ; i < 52 ; i++) {
       cout<<"\t"<<interfaz[i]<<endl;
     }

     cout<<"\t      Inserte Modo De juego: ";  cin>>categoria;
     verificarSiCategoriaEsValida();
     iniciarJuego();
   
  }
/*
  Funcion de tipo void
  Mostrar en pantalla las preguntas, respuestas e interactuar con el usuario.
  Además de Validar si es Posible la Continuacion del juego Según la categoria de ITI (Introduccion a la Tecnología Informatica).
  
*/
  void Preguntados::preguntasITI() {

    while (intentosFallidos < 3 && maximasPreguntas <= 19) {
       VideoJuego::preguntasITI();
       verificarRespuesta(respuestasITIVC);
    }

    if (intentosFallidos >= 2) {
     guardarMejoresPuntajes();
     interfazFinal();
    }
 
  }
/*
  Funcion de tipo void
  Mostrar en pantalla las preguntas, respuestas e interactuar con el usuario.
  Además de Validar si es Posible la Continuacion del juego Según la categoria de IPOO (Introduccion a la Programacion Orientada a Objetos).
  
*/
  void Preguntados::preguntasIpoo() {

    while (intentosFallidos < 3 && maximasPreguntas <= 19) {
       VideoJuego::preguntasIpoo();
       verificarRespuesta(respuestaIpooVC);
    }

    if (intentosFallidos >= 2) {
     guardarMejoresPuntajes();
     interfazFinal();
    }
 
    
  }
  /*
  Funcion de tipo void
  Mostrar en pantalla las preguntas, respuestas e interactuar con el usuario.
  Además de Validar si es Posible la Continuacion del juego Según la categoria de Matematicas
  Discretas.
  
*/

  void Preguntados::preguntasMdiscretas() {

    while (intentosFallidos < 3 && maximasPreguntas <= 19) {
       VideoJuego::preguntasMdiscretas();
       verificarRespuesta(respuestaMdiscretasVC);
    }

    if (intentosFallidos >= 2) {
     guardarMejoresPuntajes();
     interfazFinal();
    }
 

  }

 /*
  Funcion de tipo void
  Mostrar en pantalla las preguntas, respuestas e interactuar con el usuario.
  Además de Validar si es Posible la Continuacion del juego Según la categoria de FDP (Fundamentos de Programacion).
  
*/
  void Preguntados::preguntasFDP() {

    while (intentosFallidos < 3 && maximasPreguntas <= 19) {
       VideoJuego::preguntasFDP();
       verificarRespuesta(respuestaFDPVC);
    }

    if (intentosFallidos >= 2) {
     guardarMejoresPuntajes();
     interfazFinal();
    }
 
  }
/*
  Funcion de tipo void
  Mostrar en pantalla las preguntas, respuestas e interactuar con el usuario.
  Además de Validar si es Posible la Continuacion del juego Según la categoria de Historia de la Computadora.
  
*/
  void Preguntados::preguntasHistPc() {

    while (intentosFallidos < 3 && maximasPreguntas <= 19) {
       VideoJuego::preguntasHistPc();
       verificarRespuesta(respuestaHistPcVC);
    }

    if (intentosFallidos >= 2) {
     guardarMejoresPuntajes();
     interfazFinal();
    }
 
  }
 /*
  Fucion tipo void 
  Mostrar en pantalla la interfaz final de juego cuando
  ya terminan los intentos y si entra a los mejores puntaje sera felicitado
 */

  void Preguntados::interfazFinal() {

     mejoresPuntajes.clear();

     string  abrirMP = "MejoresPuntaje.txt";

     abrirArchivos(mejoresPuntajes ,abrirMP );

     int tamMejoreP = mejoresPuntajes.size()-1;

     if (tamMejoreP == 4 || tamMejoreP == 5) {
       if ((puntajeAcumulado > atoi((mejoresPuntajes[4]).c_str()) ) && tamMejoreP == 5) {
            saberSisuperoMP = 2;
      }

    }
  
   switch(saberSisuperoMP) { 

     case 1: 
       system("cls");
       cout<<"\t *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *"<<endl;
       cout<<"\t *                                                             *"<<endl;
       cout<<"\t *                   *    FIN DEL JUEGO   *                    *"<<endl;
       cout<<"\t *     __________________________________________________      *"<<endl;
       cout<<"\t *    |                                                  |     *"<<endl;
       cout<<"\t *    |                                                  |     *"<<endl; 
       cout<<"\t *    | PREGUNTAS ACERTADAS: "<<preguntasAcertadas<<"    |     *"<<endl;     
       cout<<"\t *    | PUNTOS ACUMULADO: "<<puntajeAcumulado<<"         |     *"<<endl; 
       cout<<"\t *    |                                                  |     *"<<endl;
       cout<<"\t *    |             GRACIAS POR HABER JUGADO!!!!         |     *"<<endl;
       cout<<"\t *    |                                                  |     *"<<endl;
       cout<<"\t *    |__________________________________________________|     *"<<endl;  
       cout<<"\t *                                                             *"<<endl;  

       cout<<"\t *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *"<<endl;  
       break;
  
     case 2:
       system("cls");
       cout<<"\t *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *"<<endl;
       cout<<"\t *                                                             *"<<endl;
       cout<<"\t *                   *    FIN DEL JUEGO   *                    *"<<endl;
       cout<<"\t *     __________________________________________________      *"<<endl;
       cout<<"\t *    |                                                  |     *"<<endl;
       cout<<"\t *    | ! FELICITACIONES HAS ENTRADO  EN LOS 5 MEJORES   |     *"<<endl; 
       cout<<"\t *    |                   PUNTAJES !                     |     *"<<endl;  
       cout<<"\t *    | PREGUNTAS ACERTADAS: "<<preguntasAcertadas<<"    |     *"<<endl;     
       cout<<"\t *    | PUNTOS ACUMULADO: "<<puntajeAcumulado<<"         |     *"<<endl; 
       cout<<"\t *    |                                                  |     *"<<endl;
       cout<<"\t *    |             GRACIAS POR HABER JUGADO!!!!         |     *"<<endl;
       cout<<"\t *    |                                                  |     *"<<endl;
       cout<<"\t *    |__________________________________________________|     *"<<endl;  
       cout<<"\t *                                                             *"<<endl;  
       cout<<"\t *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *"<<endl; 
       break;                   
    }
  }

/*
  Funcion de Tipo Void
  Se Encarga de Guardar los 5 Mejores Puntajes y Su Nombre en un Archivo .txt,
  Escribiendo Cada uno en Archivos Separados para ordenarlos posteriormente.
*/
  void Preguntados::guardarMejoresPuntajes() {
     string e = "NombresPuntajes.txt";
     string s = "MejoresPuntaje.txt";

     ofstream  mejoresPuntajesArch;
     ofstream  nombresArch;

     mejoresPuntajesArch.open(s,ios::out | ios::app);
     nombresArch.open(e,ios::out | ios::app);

     abrirArchivos(mejoresPuntajes ,s );

     int tamV = mejoresPuntajes.size() ;
   
     if (mejoresPuntajesArch && nombresArch) {

        if (tamV < 6 && puntajeAcumulado != 0) {

            mejoresPuntajesArch<<puntajeAcumulado<<"\n";
            nombresArch<<nombreUsuario<<"\n";
        }
        
      }
      else {
      cout<<"No se pudo insertar el usuario "<<endl;
      }


       mejoresPuntajesArch.close();
       nombresArch.close();
  }
 

/*
  Funcion de Tipo Void
  Se Encarga de Verificar que el usuario ingrese la respuesta correcta  a la pregunta, la cual está
  Almacenada en Vectore Previamente Definidos.
*/
  void Preguntados::verificarRespuesta(vector<string> &vectorCorrectaRespuesta) {
        
       fflush(stdin);
       int iniciarVectorTemporarl = 0;

       if (iniciarVectorTemporarl == 0 && vetorTemporal.size() == 0 ) {

        for (int i = 0 ; i < vectorCorrectaRespuesta.size() ; i++ ) {
            vetorTemporal.push_back( vectorCorrectaRespuesta.at(i));    
          }
           iniciarVectorTemporarl = 1;
       }

       if (guardarRespuesta == "A" || guardarRespuesta == "B" || guardarRespuesta == "C"|| guardarRespuesta == "D" ) {

         if (guardarRespuesta == vetorTemporal[valorRam-1]) {
           cout<<"\t Felicitaciones has acertado!!!!! :3 "<<endl;
           puntajeAcumulado += valorPregunta;
           vetorTemporal.erase(vetorTemporal.begin() + (valorRam - 1)); 
           preguntasAcertadas++;

         } 
         else {
           cout<<"\t No has hacertado!!!! F en el chat "<<endl;
           vetorTemporal.erase(vetorTemporal.begin() + (valorRam - 1)); 
           intentosFallidos++;

         }

     }
      else {
       
       do {

         cout<<"\t Inserte una opcion validad en mayusculas!!!  :"; cin>>guardarRespuesta;
        
         if (guardarRespuesta == "A" || guardarRespuesta == "B" || guardarRespuesta == "C"|| guardarRespuesta == "D" ) {
           break;
         }

       } while (guardarRespuesta != "A" || guardarRespuesta != "B" || guardarRespuesta != "C"|| guardarRespuesta != "D");

       verificarRespuesta(vectorCorrectaRespuesta);

     }

     system("pause");
  }

 /*
  Funcion de Tipo Void
  Esta Funcion es la Encargada de Iniciar El Juego,  dependiendo del tipo de preguntas que el 
  el usuario desee.

 */
 void Preguntados::iniciarJuego() {
   switch (categoria) {
     case 1:
     preguntasITI();
     if (maximasPreguntas == 20 && intentosFallidos < 3) {
       maximasPreguntas = 0;
       repetir = 1;
       modoDeJuego();
     }
    
     break;
     case 2:
     preguntasIpoo();
     if (maximasPreguntas == 20 && intentosFallidos < 3) {
       maximasPreguntas = 0;
       repetir = 1;
       modoDeJuego();
     }
     break;
     case 3:
     preguntasMdiscretas();
     if (maximasPreguntas == 20 && intentosFallidos < 3) {
       maximasPreguntas = 0;
       repetir = 1;
       modoDeJuego();
     }
     break;
     case 4:
     preguntasFDP();
     if (maximasPreguntas == 20 && intentosFallidos < 3) {
       maximasPreguntas = 0;
       repetir = 1;
       modoDeJuego();
     }
     
     break;
     case 5:
     preguntasHistPc();
     if (maximasPreguntas == 20 && intentosFallidos < 3) {
       maximasPreguntas = 0;
       repetir = 1;
       modoDeJuego();
     }

     break;
     case 6:
     int ramdomCategroria;
      srand((unsigned)time(0));
      ramdomCategroria = 1 + (rand() % 5);
      categoria = ramdomCategroria;
      iniciarJuego();
     break;
   }
 }
 /*
 Fucion tipo void
 ordena los puntajes y los nombres de mayo a menor en sos respectivos archivos
 */
 void Preguntados::ordenarMejoresPuntajes( ) {
    mejoresPuntajes.clear();

    int aux , num , mayor;

    string  abrirMN = "NombresPuntajes.txt";
    string  abrirMP = "MejoresPuntaje.txt";
    string  crearArchivoTemp = "Temp.txt";
    string  crearArchivoTempTwo = "TempTwo.txt";
    string auxNombre;
   
    abrirArchivos(nombresPuntajes , abrirMN );
    abrirArchivos(mejoresPuntajes ,abrirMP );
    
    int tamMejoreP = mejoresPuntajes.size();
    tamMejoreP -= 1;

    ofstream  archivoTemp;
    ofstream  archivoTempTwo;

    archivoTemp.open(crearArchivoTemp,ios::out | ios::app);
    archivoTempTwo.open(crearArchivoTempTwo,ios::out | ios::app);
   
   if (tamMejoreP == 4 || tamMejoreP == 5) {
     if ((puntajeAcumulado > atoi((mejoresPuntajes[4]).c_str()) ) && tamMejoreP == 5) {
            mejoresPuntajes[4] = to_string(puntajeAcumulado);
            nombresPuntajes[4] = nombreUsuario;
     }

   }
    
    for (int x = 0 ; x < tamMejoreP ; x++) {
       for (int i = 0 ; i < tamMejoreP ; i++) {

          num = atoi((mejoresPuntajes[i+1]).c_str());
          mayor = atoi((mejoresPuntajes[i]).c_str());

          if (mayor <= num ) {
            aux = num;
            auxNombre = nombresPuntajes[i+1];
            mejoresPuntajes[i] = to_string(aux);
            mejoresPuntajes[i+1] = to_string(mayor);
            nombresPuntajes[i+1] = nombresPuntajes[i];
            nombresPuntajes[i] = auxNombre;
            
           }
       }
    }
  
    if (archivoTemp) {
      for (int i = 0 ; i < tamMejoreP ; i++) {
         archivoTemp<<mejoresPuntajes[i]<<"\n";
         archivoTempTwo<<nombresPuntajes[i]<<"\n";
       }
    }
    else {
       cout<<"No se pudo abrir... "<<endl;
    }

   archivoTemp.close();
   archivoTempTwo.close();
   remove("MejoresPuntaje.txt");
   remove("NombresPuntajes.txt");
   rename("Temp.txt","MejoresPuntaje.txt");
   rename("TempTwo.txt","NombresPuntajes.txt");

 }

/*
  Funcion de Tipo Void
  Se Encarga e Mostrar en pantalla Los Mejores Puntajes y Sus Correspondientes Dueños.
*/
 void Preguntados::f() {
     mejoresPuntajes.clear();
     string s = "MejoresPuntaje.txt";
     abrirArchivos(mejoresPuntajes ,s );

     string n = "NombresPuntajes.txt";
     abrirArchivos(nombresPuntajes ,n );

     int tamanoV = mejoresPuntajes.size()-1;
    cout<<"\t*  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *"<<endl; 
     
  
      for (int i = 0 ; i < tamanoV ; i++) {
        cout << "\t\t\t\t\t "<< "[" << i+1 << "] " << mejoresPuntajes[i] << "\t" << nombresPuntajes[i] << " \t  "  <<endl;
     }
     

    cout<<"\t*  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *"<<endl;
    system("pause");
    interfazBienvenidad();
 }
 /*
  Function tipo void 
  Mostrar un mensaje si la persona conoca una letra en lugar de un numero y permitirle ingresar de nuevo la entrada
 */
 void Preguntados::verficarSiLaOpcionEsNumero() {
   
    if (opcion) {

       while (opcion < 0 || opcion > 3) {
       fflush(stdin);
       cout<<"\t * Inserte una opcion valida!!! :"; cin>>opcion;
      
      }
  
    }
    if (!cin.good()) { 
      cin.clear();
      cin.ignore();
      nVeces += 1;
    
      if (2 == nVeces  ) {
       cout<<"Hey bro, las opciones son solo en numeros "<<endl;
       cout<<"\t      Inserte una opcion: "; 
       cin>>opcion;
       
     }

      cin>>opcion;
   
     verficarSiLaOpcionEsNumero(); 
    }
    
    
 }
/*
 Funcion tipo void
 Verifica si se coloca un numero diferente a los numeros de las categorias en el juego, tambien si se coloca una repuesta diferente a un numero y permite volver a ingresar una respuesta
*/
  void Preguntados::verificarSiCategoriaEsValida() {
    
  if (categoria) {

       while (categoria < 0 || categoria > 6) {
       fflush(stdin);
       cout<<"\t * Inserte una opcion valida!!! :"; cin>>categoria;
      
      }
  
    }
    if (!cin.good()) { 
      cin.clear();
      cin.ignore();
      nVeces += 1;
    
      if (2 == nVeces  ) {
       cout<<"Hey bro, las opciones son solo en numeros "<<endl;
       cout<<"\t      Inserte una opcion: "; 
       cin>>categoria;
       
     }

      cin>>categoria;
      verificarSiCategoriaEsValida();
   
    }

  }