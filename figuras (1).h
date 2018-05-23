//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text);	//Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma (float altura, float largo, float profundidad, GLuint text, GLuint text2);//Funcíon creacion prisma
	void prismaa (float altura, float largo, float profundidad, GLuint text1);
	void prisma2 (GLuint text, GLuint text2);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	void triangulo(GLuint text, GLuint text2);
	void jardinera0(GLuint text, GLuint text2);
	void jardinera1(GLuint text, GLuint text2);
	void jardinera2(GLuint text, GLuint text2);
	void elipce(GLuint text1, GLuint text2);
	void piso(GLuint text);
	void edificioExt(GLuint text);
	void edificioInt(GLuint text, GLuint text2, GLuint text3);
	void base(GLuint text);
	void edifFrente(GLuint text, GLuint text2);
	void escaleras(GLuint text);
	void edifcentral(GLuint text, GLuint text2);
	void edicenTrasero(GLuint text, GLuint text2);
	void puertaCristal(GLuint text);
	void panel12(GLuint text);
	void panel10(GLuint text);
	void EstanteFig (GLuint text, GLuint text2);

	//void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text );
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);

};
