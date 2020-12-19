#include "Videojuego.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <string.h>
#include <vector>


 //Construtor
 VideoJuego::VideoJuego() {

 }


 
//Destrutor
 VideoJuego::~VideoJuego() {}
/*
  
  PROPOSITO:: Iniciar el juego con la categoría correspondiente.
  FUNCIONALIDA:: : Inicializar y llamar las funciones(archivos,interfazJuego) con sus parámetros.  
*/
 void VideoJuego::preguntasITI() { 
   string preguntasTxt = "PreguntasITI.txt";
   string respuestasTxt = "RespuestasITI.txt";

   archivos (preguntasITIV, respuestasITIV, preguntasTxt , respuestasTxt );
   interfazJuego(preguntasITIV,respuestasITIV);
   
 }
/*
  
  PROPOSITO:: Iniciar el juego con la categoría correspondiente.
  FUNCIONALIDA:: : Inicializar y llamar las funciones(archivos,interfazJuego) con sus parámetros.  
*/
 void VideoJuego::preguntasIpoo() {
   string preguntasTxt = "PreguntasIPOO.txt";
   string respuestasTxt = "RespuestasIPOO.txt";

   archivos (preguntasIpooV, respuestaIpooV, preguntasTxt , respuestasTxt ); 
   interfazJuego(preguntasIpooV,respuestaIpooV);
   
 }
/*
  
  PROPOSITO:: Iniciar el juego con la categoría correspondiente.
  FUNCIONALIDA:: : Inicializar y llamar las funciones(archivos,interfazJuego) con sus parámetros.  
*/
 void VideoJuego:: preguntasMdiscretas() {
    
   string preguntasTxt = "PreguntasMTD.txt";
   string respuestasTxt = "RespuestasMTD.txt";

   archivos (preguntasMdiscretasV, respuestaMdiscretasV, preguntasTxt , respuestasTxt ); 
   interfazJuego(preguntasMdiscretasV,respuestaMdiscretasV);
   
 }
/*
  
  PROPOSITO:: Iniciar el juego con la categoría correspondiente.
  FUNCIONALIDA:: : Inicializar y llamar las funciones(archivos,interfazJuego) con sus parámetros.  
*/
 void VideoJuego::preguntasFDP() {
   string preguntasTxt = "PreguntasFDP.txt";
   string respuestasTxt = "RespuestasFDP.txt";

   archivos (preguntasFDPV, respuestaFDPV, preguntasTxt , respuestasTxt );
   interfazJuego(preguntasFDPV,respuestaFDPV);
 }
/*
  
  PROPOSITO:: Iniciar el juego con la categoría correspondiente.
  FUNCIONALIDA:: : Inicializar y llamar las funciones(archivos,interfazJuego) con sus parámetros.  
*/
 void VideoJuego::preguntasHistPc() {
   string preguntasTxt = "PreguntasHistPc.txt";
   string respuestasTxt = "RespuestasHistP.txt";

   archivos (preguntasHistPcV, respuestaHistPcV, preguntasTxt , respuestasTxt );
   interfazJuego(preguntasHistPcV,respuestaHistPcV);
   
 }
/*
  PARAMETROS::Recibe 2 vectores por referencia de tipo string.

  PROPOSITO::: Mostrar en pantalla las preguntas, respuestas, intentos Fallidos, puntaje Acumulado y valor de la pregunta

  FUNCIONALIDA::: Al iniciar la función se realiza una copia de los parámetros y se limpia su contenido, se le da un valor a cada pregunta luego se muestra en pantalla las preguntas  y respuestas y se guarda la opción inserta por usuario y se borran del vector temporal las respuestas y preguntas que se mostraron anteriormente
*/

 void VideoJuego::interfazJuego( vector<string> & vectorPreguntas , vector<string> & vectorRespuestas) {

  int numVecesEjecuta = 0;
  
  if (numVecesEjecuta == 0 && temporal.size() == 0) {
   for (int i = 0; i < vectorPreguntas.size(); i++)
  {
    temporal.push_back(vectorPreguntas.at(i));
    temporalRespuestas.push_back(vectorRespuestas.at(i));
  }
     numVecesEjecuta = 1;
   }
   vectorPreguntas.clear();
   vectorRespuestas.clear();

   int p =2;
   int i = 0;
   int tamV = temporal.size();
   
   fflush(stdin);
   system("cls");

   srand((unsigned)time(0));
   cout<<numVecesEjecuta<<endl;
   cout<<tamV<<" tam vector preguntaCopia"<<endl;
   valorRam = 1 + (rand() % tamV);
   
 
   cout << "Pregunta: " << valorRam <<endl;

   (4 >=  valorRam)? valorPregunta = 100 : (8 >= valorRam)? valorPregunta = 200 
   : (12 >= valorRam )? valorPregunta = 300 : (16 >= valorRam )?  valorPregunta = 400 :
   (20 >= valorRam)? valorPregunta = 500 : false;


   cout<<"\t * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *"<<endl;
   cout<<"\t *      _____________________            _________________     *"<<endl;
   cout<<"\t *     |                     |          |                 |    *"<<endl;
   cout<<"\t *     |VALOR PREGUNTA: "<<valorPregunta<<"  |          |PREGUNTA # ["<<i<<"]   |    *"<<endl;
   cout<<"\t *     |_____________________|          |_________________|    *"<<endl;
   cout<<"\t *     |                     |                                 *"<<endl;
   cout<<"\t *     |PUNTUACION: "<<puntajeAcumulado<<"        |                                 *"<<endl;
   cout<<"\t *     |_____________________|                                 *"<<endl;
   cout<<"\t *     |                     |                                 *"<<endl;
   cout<<"\t *     |Intentos Fallidos: " << intentosFallidos<<" |                                 *"<<endl;
   cout<<"\t *     |_____________________|                                 *"<<endl;
   cout<<"\t *                                                             *"<<endl;
   cout<<"\t *                                                             *"<<endl;
   cout<<"\t *                  *#*      CSMC       *#*                    *"<<endl;
   cout<<"\t *                                                             *"<<endl;
   cout<<"\t *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *"<<endl;
   cout<<"\t "<<temporal[valorRam-1]<<endl;
   cout<<"\t *  - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  *"<<endl;
   cout<<"\t *  _________________________________________________________  *"<<endl;
   cout<<"\t * |                                                         | *"<<endl;
   cout<<"\t * | "<<temporalRespuestas[valorRam-1]<<"                     |  *"<<endl;  
   cout<<"\t *  __________________________________________________________ *"<<endl;
   cout<<"\t *                                                             *"<<endl;
   cout<<"\t * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *"<<endl;
   cout<<"\t Ingrese la respuesta: "; cin>>guardarRespuesta;

  

   temporal.erase(temporal.begin() + (valorRam - 1)); 
   temporalRespuestas.erase(temporalRespuestas.begin() + (valorRam - 1)); 
  numVecesEjecuta  += 1;
  maximasPreguntas += 1;
   

 }

 /*
  PARAMETROS::Recibe 4 parámetros 2 de tipo string y 2 vectores tipo string.

  PROPOSITO::Abrir y almacenar las preguntas y respuestas

  FUNCIONALIDA:: Al iniciar la función se abren los archivos txt que contienen las preguntas y respuestas, los cuales se guardaran en vectores.
 
 */
 void VideoJuego::archivos (vector<string> &vectorPreguntas, vector<string> &vectorRespuestas , string &preguntasTxt ,  string & respuestasTxt) {

          
   ifstream preguntasArch;
   ifstream respuestasArch;

   string pregunta , respuesta;

   preguntasArch.open(preguntasTxt,ios::in);
   respuestasArch.open(respuestasTxt,ios::in);
 

   if (preguntasArch.fail()) {

    cout<<"El archivo no se puede abrir "<<endl;
   }
   else {
  
     while (!preguntasArch.eof()) {
       
       getline(preguntasArch,pregunta);
       vectorPreguntas.push_back(pregunta);

       getline(respuestasArch,respuesta);
       vectorRespuestas.push_back(respuesta);

     }

   }

    preguntasArch.close();
    respuestasArch.close();
 }
/*
 PARAMETROS:: Recibe 1 vector tipo string por referencia y un dato de tipo string por referencia

 PROPOSITO:: Abrir y almacenar 

 FUNCIONALIDA:: abre el archivo y pasa su contenido a un vector.
*/
 void VideoJuego::abrirArchivos(vector<string> & vectorAbrir , string & nombreArchivo) {

    string interfaz;
    ifstream abrirArch;

    abrirArch.open(nombreArchivo,ios::in);


    if (abrirArch.fail()) {

      cout<<"No se pudo abrir el archivo "<<endl;

    }
    else {
      while (!abrirArch.eof()) {

        getline(abrirArch,interfaz);
        vectorAbrir.push_back(interfaz);
        
      }
    }
    abrirArch.close();

 }
