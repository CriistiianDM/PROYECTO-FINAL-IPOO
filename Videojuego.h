#ifndef HH_VideoJuego
#define HH_VideoJuego
#include <iostream>
#include <vector>
#include <string.h>

 using namespace std;
 
 class VideoJuego {

     // ATRIBUTOS
     private:
         
         vector <string> preguntasITIV {};
         vector <string> preguntasIpooV {};
         vector <string> preguntasMdiscretasV {};
         vector <string> preguntasFDPV {};
         vector <string> preguntasHistPcV {};
         vector <string> copiaPreguntasV {};
         vector <string> respuestasITIV {};
         vector <string> respuestaIpooV {};
         vector <string> respuestaMdiscretasV {};
         vector <string> respuestaFDPV {};
         vector <string> respuestaHistPcV {};
         vector <string> temporal{};
         vector <string> temporalRespuestas{};

    // METODOS
     public:

        VideoJuego();
       ~VideoJuego();

        int randomAnterior = 0;
        int categoria = 1;
        int intentosFallidos = 0;
        int puntajeAcumulado = 0; 
        int valorPregunta  = 0;
        int valorRam = 0 ;
        int personaJugando = 0;
        int maximasPreguntas = 0;
        string guardarRespuesta;

        virtual void preguntasITI();
        virtual void preguntasIpoo();
        virtual void preguntasMdiscretas();
        virtual void preguntasFDP();
        virtual void preguntasHistPc();
        void interfazJuego(vector<string> &, vector<string> &);
        void archivos(vector<string> &, vector<string> & , string & ,  string &);
        void abrirArchivos(vector<string> & , string &);
        void noRepetirPreguntas(vector<string> &);
 };







#endif