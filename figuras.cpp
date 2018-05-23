#include "figuras.h"


const double PI = 3.1415926535897;
float text_der = 1.0;
float text_izq = 0.0;

void CFiguras::skybox(float largo, float altura, float profundidad, GLuint text)  //Funcion creacion cielo
{

	GLfloat vertice [8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
				};

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,1.0f, 0.0f);
			//glTexCoord2f(0.0f, 0.0f); 
			glVertex3fv(vertice[0]);
			//glTexCoord2f(1.0f, 0.0f); 
			glVertex3fv(vertice[1]);
			//glTexCoord2f(1.0f, 1.0f); 
			glVertex3fv(vertice[2]);
			//glTexCoord2f(0.0f, 1.0f); 
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glNormal3f( 0.0f, -1.0f, 0.0f);
			//glTexCoord2f(0.0f, 0.0f); 
			glVertex3fv(vertice[4]);
			//glTexCoord2f(1.0f, 0.0f); 
			glVertex3fv(vertice[5]);
			//glTexCoord2f(1.0f, 1.0f); 
			glVertex3fv(vertice[6]);
			//glTexCoord2f(0.0f, 1.0f); 
        	glVertex3fv(vertice[7]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
}

void CFiguras::prisma (float altura, float largo, float profundidad, GLuint text, GLuint text2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
				};

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.

		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
}

void CFiguras::EstanteFig (GLuint text, GLuint text2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.0, 0.0, 0.0},    //Coordenadas Vértice 0 v0
				{6, 0, 0},    //Coordenadas Vértice 1 v1
				{6, 20, 0},    //Coordenadas Vértice 2 v2
				{0, 20, 0},    //Coordenadas Vértice 3 v3
				{0, 20, 5},    //Coordenadas Vértice 4 v4
				{6, 20, 5},    //Coordenadas Vértice 5 v5
				{6, 0, 5},    //Coordenadas Vértice 6 v6
				{0, 0, 5},    //Coordenadas Vértice 7 v7
				};

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.

		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text2);

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom-inferior
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
		glEnd();

		glBegin(GL_POLYGON);  //Top-superior
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
}

void CFiguras::prismaa (float altura, float largo, float profundidad, GLuint text1)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
				};

		glBindTexture(GL_TEXTURE_2D, text1);   // choose the texture to use.
		//glBindTexture(GL_TEXTURE_2D, texture[filter]);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(14.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(14.0f, 14.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 14.0f); glVertex3fv(vertice[7]);
		glEnd();
}//x

void CFiguras::prisma2 (GLuint text, GLuint text2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
		//glBindTexture(GL_TEXTURE_2D, texture[filter]);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glNormal3f( 0.0f,1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}

void CFiguras::esfera(GLfloat radio, int meridianos, int paralelos, GLuint text )
{
	
	GLdouble angulop = 3.1415/paralelos;
	GLdouble angulom = 3.1415/meridianos;
	//GLdouble angulop = 360/paralelos;
	//GLdouble angulop = 20;
	//GLdouble angulom = 20;
	GLdouble theta, phi;
	//bool even = true;
	
	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	
	glEnable ( GL_COLOR_MATERIAL );
	glColor3f(1,1,1);

	/*for(double b = 0; b <= 90-angulop; b += angulop)
	{
		for(double a = 0; a <= 360-angulom; a += angulom)
		{
			//glBegin(GL_TRIANGLES);
			glBegin(GL_POLYGON);
			glVertex3f( radio*sin((a)/180*PI)*sin((b)/180*PI), radio*cos((a)/180*PI)*sin((b)/180*PI), radio*sin((b)/180*PI) );	
			glVertex3f( radio*sin((a)/180*PI)*sin((b+angulop)/180*PI), radio*cos((a)/180*PI)*sin((b+angulop)/180*PI), radio*sin((b+angulop)/180*PI) );	
			glVertex3f( radio*sin((a+angulom)/180*PI)*sin((b)/180*PI), radio*cos((a+angulom)/180*PI)*sin((b)/180*PI), radio*sin((b)/180*PI) );	
			glVertex3f( radio*sin((a+angulom)/180*PI)*sin((b+angulop)/180*PI), radio*cos((a+angulom)/180*PI)*sin((b+angulop)/180*PI), radio*sin((b+angulop)/180*PI) );	
			glEnd();
		}
	}*/

	for(double p =-3.14/2; p < 3.14/2; p += angulop)
	{
		for(double m = 0; m < 3.14*2; m+=angulom)
		{
			//glBegin(GL_LINE_LOOP);
			glBegin(GL_POLYGON);
			

			//glBegin(GL_POINTS);
			glNormal3f( radio*cos(p + angulop)*cos(m), radio*sin(p + angulop), radio*cos(p + angulop)*sin(m));			
			glVertex3f( radio*cos(p + angulop)*cos(m), radio*sin(p + angulop), radio*cos(p + angulop)*sin(m));	

			glNormal3f( radio*cos(p + angulop)*cos(m + angulom), radio*sin(p + angulop), radio*cos(p + angulop)*sin(m + angulom));
			glVertex3f( radio*cos(p + angulop)*cos(m + angulom), radio*sin(p + angulop), radio*cos(p + angulop)*sin(m + angulom));

			glNormal3f( radio*cos(p)*cos(m + angulom), radio*sin(p), radio*cos(p)*sin(m + angulom));
			glVertex3f( radio*cos(p)*cos(m + angulom), radio*sin(p), radio*cos(p)*sin(m + angulom));

			glNormal3f(radio*cos(p)*cos(m), radio*sin(p), radio*cos(p)*sin(m));
			glVertex3f( radio*cos(p)*cos(m), radio*sin(p), radio*cos(p)*sin(m));
				
			glEnd();
		}
	}

/*
	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};
	int i, j;
	float angulom, angulop;
	angulom=2*3.141592654/meridianos;
	for(i=0;i<meridianos;i++)
	{
		angulop=3.141592654/paralelos; 
		for(j=0;j<paralelos;j++)
		{
			v1[0]=radio*cos(angulom*i)*sin(angulop*j);
			v1[1]=radio*cos(angulop*j);
			v1[2]=radio*sin(angulom*i)*sin(angulop*j);
			
			v2[0]=radio*cos(angulom*i)*sin(angulop*(j+1));
			v2[1]=radio*cos(angulop*(j+1));
			v2[2]=radio*sin(angulom*i)*sin(angulop*(j+1));
			
			v3[0]=radio*cos(angulom*(i+1))*sin(angulop*(j+1));
			v3[1]=radio*cos(angulop*(j+1));
			v3[2]=radio*sin(angulom*(i+1))*sin(angulop*(j+1));

			v4[0]=radio*cos(angulom*(i+1))*sin(angulop*j);
			v4[1]=radio*cos(angulop*j);
			v4[2]=radio*sin(angulom*(i+1))*sin(angulop*j);
			
			//glBegin(GL_LINE_LOOP);
			glBegin(GL_POLYGON);
				glVertex3fv(v1);
				glVertex3fv(v2);
				glVertex3fv(v3);
				glVertex3fv(v4);
			glEnd();
		}
	}*/

	glDisable ( GL_COLOR_MATERIAL );
}

/*void CFiguras::torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text )
{
*/
	/*float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};

	int i,j;

	GLdouble angulop = 2*3.1415/paralelos;
	GLdouble angulom = 2*3.1415/meridianos;

	float R = radioM - radiom;

	for(i=0;i<meridianos;i++)
	{
		for(j=0;j<paralelos;j++)
		{
			v1[0]=radiom*cos(angulom*i)*sin(angulop*j)+radioM*cos(angulom*i);
			v1[2]=radiom*sin(angulom*i)*sin(angulop*j)+radioM*sin(angulom*i);
			v1[1]=radiom*cos(angulop*j);
			
			v2[0]=radiom*cos(angulom*i)*sin(angulop*(j+1))+radioM*cos(angulom*i);
			v2[2]=radiom*sin(angulom*i)*sin(angulop*(j+1))+radioM*sin(angulom*i);
			v2[1]=radiom*cos(angulop*(j+1));
			
			v3[0]=radiom*cos(angulom*(i+1))*sin(angulop*(j+1))+radioM*cos(angulom*(i+1));
			v3[2]=radiom*sin(angulom*(i+1))*sin(angulop*(j+1))+radioM*sin(angulom*(i+1));
			v3[1]=radiom*cos(angulop*(j+1));
			
			v4[0]=radiom*cos(angulom*(i+1))*sin(angulop*j)+radioM*cos(angulom*(i+1));
			v4[2]=radiom*sin(angulom*(i+1))*sin(angulop*j)+radioM*sin(angulom*(i+1));
			v4[1]=radiom*cos(angulop*j);
			
			glBegin(GL_LINE_LOOP);
				glVertex3fv(v1);
				glVertex3fv(v2);
				glVertex3fv(v3);
				glVertex3fv(v4);
			glEnd();
		}
	}*/
	/*float R = 0;
	float r = 0;

	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};

	int i,j;

	GLdouble angulop = 2*3.1415/paralelos;
	GLdouble angulom = 2*3.1415/meridianos;

	r = (radioM - radiom)/2;
	R = radiom + r;

	for(i=0;i<meridianos;i++)
	{
		for(j=0;j<paralelos;j++)
		{
			
			v1[0]=R*cos(angulom*i) + r*cos(angulom*i)*cos(angulop*j);
			v1[2]=R*sin(angulom*i)+ r*sin(angulom*i)*cos(angulop*j);
			v1[1]=r*sin(angulop*j);

			glNormal3f(v1[0], v1[1], v1[2]);
			
			v2[0]=R*cos(angulom*i) + r*cos(angulom*i)*cos(angulop*(j+1));
			v2[2]=R*sin(angulom*i) + r*sin(angulom*i)*cos(angulop*(j+1));
			v2[1]=r*sin(angulop*(j+1));

			glNormal3f(v2[0], v2[1], v2[2]);

			v3[0]=R*cos(angulom*(i+1)) + r*cos(angulom*(i+1))*cos(angulop*(j+1));
			v3[2]=R*sin(angulom*(i+1)) + r*sin(angulom*(i+1))*cos(angulop*(j+1));
			v3[1]=r*sin(angulop*(j+1));

			glNormal3f(v3[0], v3[1], v3[2]);

			v4[0]=R*cos(angulom*(i+1)) + r*cos(angulom*(i+1))*cos(angulop*j);
			v4[2]=R*sin(angulom*(i+1)) + r*sin(angulom*(i+1))*cos(angulop*j);
			v4[1]=r*sin(angulop*j);

			glNormal3f(v4[0], v4[1], v4[2]);
			
			
			//glBegin(GL_LINE_LOOP);
			glBegin(GL_POLYGON);
			glColor3f(0.5,0.5,0.8);
				glVertex3fv(v1);
				glVertex3fv(v2);
				glVertex3fv(v3);
				glVertex3fv(v4);
			glEnd();
		}
	}
}*/

void CFiguras::torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos )
{

	/*float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};

	int i,j;

	GLdouble angulop = 2*3.1415/paralelos;
	GLdouble angulom = 2*3.1415/meridianos;

	float R = radioM - radiom;

	for(i=0;i<meridianos;i++)
	{
		for(j=0;j<paralelos;j++)
		{
			v1[0]=radiom*cos(angulom*i)*sin(angulop*j)+radioM*cos(angulom*i);
			v1[2]=radiom*sin(angulom*i)*sin(angulop*j)+radioM*sin(angulom*i);
			v1[1]=radiom*cos(angulop*j);
			
			v2[0]=radiom*cos(angulom*i)*sin(angulop*(j+1))+radioM*cos(angulom*i);
			v2[2]=radiom*sin(angulom*i)*sin(angulop*(j+1))+radioM*sin(angulom*i);
			v2[1]=radiom*cos(angulop*(j+1));
			
			v3[0]=radiom*cos(angulom*(i+1))*sin(angulop*(j+1))+radioM*cos(angulom*(i+1));
			v3[2]=radiom*sin(angulom*(i+1))*sin(angulop*(j+1))+radioM*sin(angulom*(i+1));
			v3[1]=radiom*cos(angulop*(j+1));
			
			v4[0]=radiom*cos(angulom*(i+1))*sin(angulop*j)+radioM*cos(angulom*(i+1));
			v4[2]=radiom*sin(angulom*(i+1))*sin(angulop*j)+radioM*sin(angulom*(i+1));
			v4[1]=radiom*cos(angulop*j);
			
			glBegin(GL_LINE_LOOP);
				glVertex3fv(v1);
				glVertex3fv(v2);
				glVertex3fv(v3);
				glVertex3fv(v4);
			glEnd();
		}
	}*/
	float R = 0;
	float r = 0;

	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};

	int i,j;

	GLdouble angulop = 2*3.1415/paralelos;
	GLdouble angulom = 2*3.1415/meridianos;

	r = (radioM - radiom)/2;
	R = radiom + r;

	for(i=0;i<meridianos;i++)
	{
		for(j=0;j<paralelos;j++)
		{
			
			v1[0]=R*cos(angulom*i) + r*cos(angulom*i)*cos(angulop*j);
			v1[2]=R*sin(angulom*i)+ r*sin(angulom*i)*cos(angulop*j);
			v1[1]=r*sin(angulop*j);

			glNormal3f(v1[0], v1[1], v1[2]);
			
			v2[0]=R*cos(angulom*i) + r*cos(angulom*i)*cos(angulop*(j+1));
			v2[2]=R*sin(angulom*i) + r*sin(angulom*i)*cos(angulop*(j+1));
			v2[1]=r*sin(angulop*(j+1));

			glNormal3f(v2[0], v2[1], v2[2]);

			v3[0]=R*cos(angulom*(i+1)) + r*cos(angulom*(i+1))*cos(angulop*(j+1));
			v3[2]=R*sin(angulom*(i+1)) + r*sin(angulom*(i+1))*cos(angulop*(j+1));
			v3[1]=r*sin(angulop*(j+1));

			glNormal3f(v3[0], v3[1], v3[2]);

			v4[0]=R*cos(angulom*(i+1)) + r*cos(angulom*(i+1))*cos(angulop*j);
			v4[2]=R*sin(angulom*(i+1)) + r*sin(angulom*(i+1))*cos(angulop*j);
			v4[1]=r*sin(angulop*j);

			glNormal3f(v4[0], v4[1], v4[2]);
			
			
			//glBegin(GL_LINE_LOOP);
			glBegin(GL_POLYGON);
				glVertex3fv(v1);
				glVertex3fv(v2);
				glVertex3fv(v3);
				glVertex3fv(v4);
			glEnd();
		}
	}
}

void CFiguras::cono(float altura, float radio, int resolucion, GLuint text)
{
	
	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};

	float angulo=2*3.14/resolucion;
	
	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	for(int i=0; i <resolucion; i++)
	{
		
		v2[0]=radio*cos(angulo*i);
		v2[1]=0;
		v2[2]=radio*sin(angulo*i);

		v3[0]=radio*cos(angulo*(i+1));
		v3[1]=0;
		v3[2]=radio*sin(angulo*(i+1));
		
		//glBegin(GL_LINE_LOOP);
        glBegin(GL_POLYGON); //Construye Base
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3f(0.0,0.0,0.0);
			glVertex3fv(v2);
			glVertex3fv(v3);
		glEnd();

		glBegin(GL_POLYGON);  //Construye Cuerpo
			glNormal3f( v2[0], 0.25f, v2[2]);
			//glNormal3fv(v2);
			glVertex3fv(v2);
			//glNormal3fv(v3);
			glVertex3fv(v3);
			//glNormal3f(0.0,altura,0);
			glVertex3f(0.0,altura,0.0);
			
		glEnd();
	}
}

void CFiguras::cilindro(float radio, float altura, int resolucion, GLuint text)
{
	
	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};
	float v5[]={0.0, 0.0, 0.0};

	float angulo=2*3.14/resolucion;

	//float ctext_s = 1/resolucion-1;
	float ctext_s = 1/resolucion;
	float ctext_t = 0.0;

	glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1, 1, 1);

	for(int i=0; i <resolucion; i++)
	{
		 
		v2[0]=radio*cos(angulo*i);
		v2[1]=0;
		v2[2]=radio*sin(angulo*i);

		v3[0]=radio*cos(angulo*(i+1));
		v3[1]=0;
		v3[2]=radio*sin(angulo*(i+1));
//	
		v4[0]=radio*cos(angulo*i);
		v4[1]=altura;
		v4[2]=radio*sin(angulo*i);

		v5[0]=radio*cos(angulo*(i+1));
		v5[1]=altura;
		v5[2]=radio*sin(angulo*(i+1));

		//glBegin(GL_LINE_LOOP);
		glBegin(GL_POLYGON);
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3f(0.0,0.0,0.0);
			glVertex3fv(v2);
			glVertex3fv(v3);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3f(0.0,altura,0.0);
			glVertex3fv(v4);
			glVertex3fv(v5);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f( v2[0], 0.0f, v2[2]);
			glVertex3fv(v2);
			glVertex3fv(v3);
			glVertex3fv(v5);
			glVertex3fv(v4);
		glEnd();
	}

	glDisable ( GL_COLOR_MATERIAL );
}	

void CFiguras::triangulo(GLuint text, GLuint text2)
	{
		GLfloat vertice [6][3] = {
				{0, 0, 0},    //Coordenadas Vértice 0 V0
				{0, 3, 0},    //Coordenadas Vértice 1 V1
				{15, 3, 0},    //Coordenadas Vértice 2 V2
				{15, 0, 0},    //Coordenadas Vértice 3 V3
				{15, 0, 15},    //Coordenadas Vértice 4 V4
				{15, 3, 15},    //Coordenadas Vértice 5 V5
				};

		glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1, 1, 1);
				
		glBegin(GL_TRIANGLES);	//Up
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(3.0f, 3.0f); glVertex3fv(vertice[5]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text2);

		glBegin(GL_POLYGON);	//catetoA
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(3.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);	//catetoB
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(3.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);	//hipotenusa
			glNormal3f( 1.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);

		glBegin(GL_TRIANGLES);	//down
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(3.0f, 3.0f); glVertex3fv(vertice[4]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
	}

void CFiguras::jardinera0(GLuint text, GLuint text2)
	{
		GLfloat vertice [9][3] = {
				{0,    0,     0},	//Coordenadas Vértice 0 V0
				{15,   0,	  0},	//Coordenadas Vértice 1 V1
				{0,    0,	-30},   //Coordenadas Vértice 2 V2
				{15,   0,	-30},   //Coordenadas Vértice 3 V3
				{0,    3,     0},	//Coordenadas Vértice 4 V4
				{15,   3,     0},	//Coordenadas Vértice 5 V5
				{0,    3,   -30},	//Coordenadas Vertice 6 V6
				{15,   3,   -30},	//Coordenadas Vertice 7 V7
				};

		glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(6.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(6.0f, 6.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 6.0f); glVertex3fv(vertice[7]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text2);

		glBegin(GL_POLYGON);	//Lado largo
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(6.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(6.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado corto
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(3.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado largo
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(6.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(6.0f, 1.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado corto
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(3.0f, 1.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();

		/*glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();*/

		glDisable ( GL_COLOR_MATERIAL );
	}

void CFiguras::jardinera1(GLuint text, GLuint text2)
	{
		GLfloat vertice [16][3] = {
				{0,    0,     0},	//Coordenadas Vértice 0 V0
				{0,    0,   -40},	//Coordenadas Vértice 1 V1
				{12.5, 0, -37.5},   //Coordenadas Vértice 2 V2
				{25,   0, -32.5},   //Coordenadas Vértice 3 V3
				{30,   0,   -25},	//Coordenadas Vértice 4 V4
				{25,   0, -22.5},	//Coordenadas Vértice 5 V5
				{17.5, 0,   -15},	//Coordenadas Vertice 6 V6
				{15,   0,     0},	//Coordenadas Vertice 7 V7
				{0,    3,     0},	//Coordenadas Vértice 8 V8
				{0,    3,   -40},	//Coordenadas Vértice 9 V9
				{12.5, 3, -37.5},   //Coordenadas Vértice 10 V10
				{25,   3, -32.5},   //Coordenadas Vértice 11 V11
				{30,   3,   -25},	//Coordenadas Vértice 12 V12
				{25,   3, -22.5},	//Coordenadas Vértice 13 V13
				{17.5, 3,   -15},	//Coordenadas Vertice 14 V14
				{15,   3,     0},   //Coordenadas Vertice 15 V15
				};

		glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1, 1, 1);

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(3.5f, 3.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 8.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(2.5f, 7.5f); glVertex3fv(vertice[2]);
			glTexCoord2f(3.5f, 3.0f); glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(2.5f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 4.5f); glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.5f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f, 2.0f); glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(3.5f, 1.5f); glVertex3fv(vertice[6]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text2);

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(8.0f, 0.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(8.0f, 1.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f); //Este no es el vector normal
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(2.5f, 0.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(2.5f, 1.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f(0.0f, 0.0f, -1.0f);  // Este no es el vector normal
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(2.5f, 0.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(2.5f, 1.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f); // Este no es el vector normal
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.5f, 0.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(1.5f, 1.0f); glVertex3fv(vertice[12]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f); //Este no es el vector normal
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[12]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f); //Este no es el vector normal
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(2.0f, 1.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f); //Este no es el vector normal
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(3.0f, 1.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f); //Este no es el vector normal
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(3.0f, 1.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(3.5f, 3.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(3.0f, 0.0f); glVertex3fv(vertice[15]);
		glEnd();

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(0.0f, 8.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(2.5f, 7.5f); glVertex3fv(vertice[10]);
			glTexCoord2f(3.5f, 3.0f); glVertex3fv(vertice[14]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(2.5f, 1.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(1.0f, 4.5f); glVertex3fv(vertice[14]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(1.0f, 1.5f); glVertex3fv(vertice[12]);
			glTexCoord2f(0.0f, 2.0f); glVertex3fv(vertice[13]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(3.5f, 1.5f); glVertex3fv(vertice[14]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
	}

void CFiguras::jardinera2(GLuint text, GLuint text2)
	{
		GLfloat vertice [16][3] = {
				{0,     0,     0},	//Coordenadas Vértice 0 V0
				{27.5,  0,     0},	//Coordenadas Vértice 1 V1
				{27.5,  0,   7.5},  //Coordenadas Vértice 2 V2
				{23.75, 0,    15},  //Coordenadas Vértice 3 V3
				{20,    0,    20},	//Coordenadas Vértice 4 V4
				{15,    0, 18.75},	//Coordenadas Vértice 5 V5
				{7.5,   0,  17.5},	//Coordenadas Vertice 6 V6
				{0,     0,  17.5},	//Coordenadas Vertice 7 V7
				{0,     3,     0},	//Coordenadas Vértice 8 V8
				{27.5,  3,     0},	//Coordenadas Vértice 9 V9
				{27.5,  3,   7.5},  //Coordenadas Vértice 10 V10
				{23.75, 3,    15},  //Coordenadas Vértice 11 V11
				{20,    3,    20},	//Coordenadas Vértice 12 V12
				{15,    3, 18.75},	//Coordenadas Vértice 13 V13
				{7.5,   3,  17.5},	//Coordenadas Vertice 14 V14
				{0,     3,  17.5},	//Coordenadas Vertice 15 V15
				};

		glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1, 1, 1);

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(3.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(6.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(5.0f, 1.5f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(3.5f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(3.5f, 5.5f); glVertex3fv(vertice[1]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text2);

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(3.5f, 1.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(3.5f, 0.0f); glVertex3fv(vertice[8]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(5.5f, 1.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(5.5f, 0.0f); glVertex3fv(vertice[9]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.5f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.5f, 0.0f); glVertex3fv(vertice[10]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.5f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.5f, 0.0f); glVertex3fv(vertice[11]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[12]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[12]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[13]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( -1.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.5f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.5f, 0.0f); glVertex3fv(vertice[14]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.5f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.5f, 0.0f); glVertex3fv(vertice[15]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[12]);
		glEnd();

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(3.0f, 1.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[13]);
		glEnd();

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(6.0f, 0.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(5.0f, 1.5f); glVertex3fv(vertice[10]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[14]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(3.5f, 0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(3.5f, 5.5f); glVertex3fv(vertice[9]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
	}

void CFiguras::elipce(GLuint text1, GLuint text2)
	{
		GLfloat vertice [46][3] = {
				{2.51,     0,     0},	//Coordenadas Vértice 0 V0
				{5,	    0,     0},	//Coordenadas Vértice 1 V1
				{10,    0,     0},  //Coordenadas Vértice 2 V2
				{15,    0,     0},  //Coordenadas Vértice 3 V3
				{20,    0,     0},	//Coordenadas Vértice 4 V4
				{25,    0,     0},	//Coordenadas Vértice 5 V5
				{30,    0,     0},	//Coordenadas Vertice 6 V6
				{32.5,  0,     0},	//Coordenadas Vertice 7 V7
				{35,    0,     0},	//Coordenadas Vértice 8 V8
				{32.5,  0,  -9.28},	//Coordenadas Vértice 9 V9
				{30,    0, -12.88}, //Coordenadas Vértice 10 V10
				{25,    0,  -17.5}, //Coordenadas Vértice 11 V11
				{20,    0, -20.52},	//Coordenadas Vértice 12 V12
				{15,    0, -22.59},	//Coordenadas Vértice 13 V13
				{10,    0, -23.96},	//Coordenadas Vertice 14 V14
				{5,     0, -24.74},	//Coordenadas Vertice 15 V15
				{0,     0,   -25},  //Coordenadas Vértice 16 V16
				{2.51,     3,     0},	//Coordenadas Vértice 17 V17
				{5,	    3,     0},	//Coordenadas Vértice 18 V18
				{10,    3,     0},  //Coordenadas Vértice 19 V19
				{15,    3,     0},  //Coordenadas Vértice 20 V20
				{20,    3,     0},	//Coordenadas Vértice 21 V21
				{25,    3,     0},	//Coordenadas Vértice 22 V22
				{30,    3,     0},	//Coordenadas Vertice 23 V23
				{32.5,  3,     0},	//Coordenadas Vertice 24 V24
				{35,    3,     0},	//Coordenadas Vértice 25 V25
				{32.5,  3,  -9.28},	//Coordenadas Vértice 26 V26
				{30,    3, -12.88}, //Coordenadas Vértice 27 V27
				{25,    3,  -17.5}, //Coordenadas Vértice 28 V28
				{20,    3, -20.52},	//Coordenadas Vértice 29 V29
				{15,    3, -22.59},	//Coordenadas Vértice 30 V30
				{10,    3, -23.96},	//Coordenadas Vertice 31 V31
				{5,     3, -24.74},	//Coordenadas Vertice 32 V32
				{0,     3,    -25},	//Coordenadas Vertice 33 V33

				{1.36,  0,    -23},	//Coordenadas Vértice 34 V34
				{1.36,  3,    -23},	//Coordenadas Vertice 35 V35
				{1.83,  0,   -21},	//Coordenadas Vertice 36 V36
				{1.83,  3,    -21},	//Coordenadas Vertice 37 V37
				{2.13, 0,    -19},	//Coordenadas Vértice 38 V38
				{2.13, 3,    -19},	//Coordenadas Vertice 39 V39
				{2.33,  0,    -17},	//Coordenadas Vertice 40 V40
				{2.33,  3,    -17},	//Coordenadas Vertice 41 V41
				{2.45,  0,    -15},	//Coordenadas Vértice 42 V42
				{2.45,  3,    -15},	//Coordenadas Vertice 43 V43
				{2.51,  0,    -12.5},	//Coordenadas Vértice 44 V44
				{2.51,  3,    -12.5},	//Coordenadas Vertice 45 V45
				};

		glBindTexture(GL_TEXTURE_2D, text1);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1, 1, 1);

		/*glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f); //1
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(2.0f, 10.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[16]);	
		glEnd();*/

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f); //2
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(2.0f, 9.5f); glVertex3fv(vertice[14]);
			glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[15]);
		glEnd();

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f); //3
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(2.0f, 9.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(0.0f, 9.5f); glVertex3fv(vertice[14]);
		glEnd();

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f); //4
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(2.0f, 8.0f); glVertex3fv(vertice[12]);
			glTexCoord2f(0.0f, 9.0f); glVertex3fv(vertice[13]);
		glEnd();

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f); //5
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(2.0f, 7.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(0.0f, 8.0f); glVertex3fv(vertice[12]);
		glEnd();

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f); //6
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(2.0f, 5.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(0.0f, 7.0f); glVertex3fv(vertice[11]);
		glEnd();

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f); //7
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 3.5f); glVertex3fv(vertice[9]);
			glTexCoord2f(0.0f, 5.0f); glVertex3fv(vertice[10]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);//8
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[9]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);//9
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[44]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);//10
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[44]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[15]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);//11
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[44]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[42]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[15]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);//12
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[42]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[40]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[15]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);//13
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[40]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[38]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[15]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);//14
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[38]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[36]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[15]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);//15
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[36]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[34]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[15]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);//15
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[34]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[16]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[15]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text2);

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( -1.0f, 0.0f, 0.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(10.0f, 0.0f); glVertex3fv(vertice[44]);
			glTexCoord2f(10.0f, 1.0f); glVertex3fv(vertice[45]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[17]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(14.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(14.0f, 1.0f); glVertex3fv(vertice[17]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[25]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, 1.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[26]);
			glTexCoord2f(4.0f, 1.0f); glVertex3fv(vertice[25]);
			glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[8]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, 1.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[27]);
			glTexCoord2f(1.5f, 1.0f); glVertex3fv(vertice[26]);
			glTexCoord2f(1.5f, 0.0f); glVertex3fv(vertice[9]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, 1.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[28]);
			glTexCoord2f(2.5f, 1.0f); glVertex3fv(vertice[27]);
			glTexCoord2f(2.5f, 0.0f); glVertex3fv(vertice[10]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, -1.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[12]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[29]);
			glTexCoord2f(2.0f, 1.0f); glVertex3fv(vertice[28]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[11]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, -1.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[30]);
			glTexCoord2f(2.0f, 1.0f); glVertex3fv(vertice[29]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[12]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, -1.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[31]);
			glTexCoord2f(1.5f, 1.0f); glVertex3fv(vertice[30]);
			glTexCoord2f(1.5f, 0.0f); glVertex3fv(vertice[13]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, -1.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[32]);
			glTexCoord2f(1.5f, 1.0f); glVertex3fv(vertice[31]);
			glTexCoord2f(1.5f, 0.0f); glVertex3fv(vertice[14]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f); //
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[16]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[33]);
			glTexCoord2f(2.0f, 1.0f); glVertex3fv(vertice[32]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[15]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text1);

		/*glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f); //1
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[17]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[18]);
			glTexCoord2f(2.0f, 10.0f); glVertex3fv(vertice[32]);
			glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[33]);
		glEnd();*/

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f); //2
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[19]);
			glTexCoord2f(2.0f, 9.5f); glVertex3fv(vertice[31]);
			glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[32]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f); //3
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[19]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[20]);
			glTexCoord2f(2.0f, 9.0f); glVertex3fv(vertice[30]);
			glTexCoord2f(0.0f, 9.5f); glVertex3fv(vertice[31]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f); //4
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[20]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[21]);
			glTexCoord2f(2.0f, 8.0f); glVertex3fv(vertice[29]);
			glTexCoord2f(0.0f, 9.0f); glVertex3fv(vertice[30]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f); //5
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[21]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[22]);
			glTexCoord2f(2.0f, 7.0f); glVertex3fv(vertice[28]);
			glTexCoord2f(0.0f, 8.0f); glVertex3fv(vertice[29]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f); //6
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[22]);
			glTexCoord2f(2.0f, 0.0f); glVertex3fv(vertice[23]);
			glTexCoord2f(2.0f, 5.0f); glVertex3fv(vertice[27]);
			glTexCoord2f(0.0f, 7.0f); glVertex3fv(vertice[28]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f); //7
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[23]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[24]);
			glTexCoord2f(1.0f, 3.5f); glVertex3fv(vertice[26]);
			glTexCoord2f(0.0f, 5.0f); glVertex3fv(vertice[27]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);//8
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[24]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[25]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[26]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);//9
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[17]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[45]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[18]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);//10
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[18]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[45]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[32]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);//11
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[45]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[43]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[32]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);//12
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[43]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[41]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[32]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);//13
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[41]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[39]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[32]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);//14
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[39]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[37]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[32]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);//15
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[37]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[35]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[32]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);//15
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[35]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[33]);
			glTexCoord2f(0.0f, 3.5f); glVertex3fv(vertice[32]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
	}

	void CFiguras::piso(GLuint text)
	{
		GLfloat vertice [8][3] = {
				{0,     0,     0},	//Coordenadas Vértice 0 V0
				{200,	0,     0},	//Coordenadas Vértice 1 V1
				{200,   0,   200},  //Coordenadas Vértice 2 V2
				{0,     0,   200},  //Coordenadas Vértice 3 V3
				{0,     1,     0},	//Coordenadas Vértice 4 V4
				{200,   1,     0},	//Coordenadas Vértice 5 V5
				{200,   1,   200},	//Coordenadas Vertice 6 V6
				{0,     1,   200},	//Coordenadas Vertice 7 V7
				};

		glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(80.0f,  0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(80.0f, 80.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  80.0f); glVertex3fv(vertice[7]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
	}

	void CFiguras::edificioExt(GLuint text)
	{
		GLfloat vertice [8][3] = {
				{0,     0,     0},	//Coordenadas Vértice 0 V0
				{35,	0,     0},	//Coordenadas Vértice 1 V1
				{35,    0,    35},  //Coordenadas Vértice 2 V2
				{0,     0,    35},  //Coordenadas Vértice 3 V3
				{0,  17.5,     0},	//Coordenadas Vértice 4 V4
				{35, 17.5,     0},	//Coordenadas Vértice 5 V5
				{35, 17.5,    35},	//Coordenadas Vertice 6 V6
				{0,  17.5,    35},	//Coordenadas Vertice 7 V7
				};

		glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(7.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(7.0f, 7.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f,  7.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(7.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(7.0f, 7.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f,  7.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(7.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(7.0f, 7.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f,  7.0f); glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(7.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(7.0f, 7.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  7.0f); glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(7.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(7.0f, 7.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f,  7.0f); glVertex3fv(vertice[7]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(7.0f,  0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(7.0f, 7.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  7.0f); glVertex3fv(vertice[7]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
	}

	void CFiguras::edificioInt(GLuint text, GLuint text2, GLuint text3)
	{
		GLfloat vertice [8][3] = {
				{0.1,   0.1,    0.1},	//Coordenadas Vértice 0 V0
				{34.9,	0.1,    0.1},	//Coordenadas Vértice 1 V1
				{34.9,  0.1,    34.9},  //Coordenadas Vértice 2 V2
				{0.1,     0.1,    34.9},  //Coordenadas Vértice 3 V3
				{0.1,   17.4,   0.1},	//Coordenadas Vértice 4 V4
				{34.9,  17.4,   0.1},	//Coordenadas Vértice 5 V5
				{34.9,  17.4,   34.9},	//Coordenadas Vertice 6 V6
				{0.1,   17.4,   34.9},	//Coordenadas Vertice 7 V7
				};

		glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );

		glBindTexture(GL_TEXTURE_2D, text2);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f,  1); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f,  1); glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f, 1); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  1); glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 1); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f,  1); glVertex3fv(vertice[7]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );

		glBindTexture(GL_TEXTURE_2D, text3);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(7.0f,  0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(7.0f, 7.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  7.0f); glVertex3fv(vertice[7]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
	}

	void CFiguras::base(GLuint text)
	{
		GLfloat vertice [8][3] = {
				{0,     0,     0},	//Coordenadas Vértice 0 V0
				{90,	0,     0},	//Coordenadas Vértice 1 V1
				{90,    0,    35},  //Coordenadas Vértice 2 V2
				{0,     0,    35},  //Coordenadas Vértice 3 V3
				{0,		3,     0},	//Coordenadas Vértice 4 V4
				{90,	3,     0},	//Coordenadas Vértice 5 V5
				{90,	3,    35},	//Coordenadas Vertice 6 V6
				{0,		3,    35},	//Coordenadas Vertice 7 V7
				};

		glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Down
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(80.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(80.0f, 80.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f,  80.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado largo
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(18.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(18.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado largo
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(18.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(18.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[6]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado corto
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(7.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(7.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[5]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado corto
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(7.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(7.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[7]);
		glEnd();

		glBegin(GL_POLYGON);	//Up
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,   0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(18.0f,  0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(18.0f, 7.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  7.0f); glVertex3fv(vertice[7]);
		glEnd();

		glDisable ( GL_COLOR_MATERIAL );
	}

	void CFiguras::edifFrente(GLuint text, GLuint text2)
	{
		GLfloat vertice [64][3] = {
				{0,     0,       0},    //Coordenadas Vértice 0 V0
				{0,	    0,    12.5},	//Coordenadas Vértice 1 V1
				{2.5,   0,      25},    //Coordenadas Vértice 2 V2
				{7.5,   0,      25},    //Coordenadas Vértice 3 V3
				{17.5,  0,      25},	//Coordenadas Vértice 4 V4
				{22.5,  0,      25},	//Coordenadas Vértice 5 V5
				{25,    0,    12.5},	//Coordenadas Vertice 6 V6
				{25,    0,       0},	//Coordenadas Vertice 7 V7
				{0,     4,       0},	//Coordenadas Vértice 8 V8
				{0,     4,    12.5},	//Coordenadas Vértice 9 V9
				{2.5,   4,      25},    //Coordenadas Vértice 10 V10
				{7.5,   4,      25},    //Coordenadas Vértice 11 V11
				{17.5,  4,      25},	//Coordenadas Vértice 12 V12
				{22.5,  4,      25},	//Coordenadas Vértice 13 V13
				{25,    4,    12.5},	//Coordenadas Vertice 14 V14
				{25,    4,       0},	//Coordenadas Vertice 15 V15
				{0,     17.5,    0},    //Coordenadas Vértice 16 V16
				{0,     16,   12.5},	//Coordenadas Vértice 17 V17
				{2.5,   14.5,   25},	//Coordenadas Vértice 18 V18
				{9,     14.5,   25},    //Coordenadas Vértice 19 V19
				{16,    14.5,   25},    //Coordenadas Vértice 20 V20
				{22.5,  14.5,   25},	//Coordenadas Vértice 21 V21
				{25,    16,   12.5},	//Coordenadas Vértice 22 V22
				{25,    17.5,    0},	//Coordenadas Vertice 23 V23
				{2.5,   17.5,    0},	//Coordenadas Vertice 24 V24
				{2.5,   16,   12.5},	//Coordenadas Vértice 25 V25
				{9,     17.5,    0},	//Coordenadas Vértice 26 V26
				{9,     16,   12.5},    //Coordenadas Vértice 27 V27
				{16,    17.5,    0},    //Coordenadas Vértice 28 V28
				{16,    16,   12.5},	//Coordenadas Vértice 29 V29
				{22.5,  17.5,    0},	//Coordenadas Vértice 30 V30
				{22.5,  16,   12.5},	//Coordenadas Vertice 31 V31
				{7.5,   14.5,   25},	//Coordenadas Vertice 32 V32
				{17.5,  14.5,   25},	//Coordenadas Vertice 33 V33

				//Coordenadas del arco
				{0.05,  0,      15},    //Coordenadas Vértice 34 V34
				{0.17,  0,      17},    //Coordenadas Vértice 35 V35
				{0.365, 0,      19},	//Coordenadas Vértice 36 V36
				{0.67,  0,      21},	//Coordenadas Vértice 37 V37
				{1.14,  0,      23},	//Coordenadas Vertice 38 V38
				{0.05,  15.7,   15},    //Coordenadas Vértice 39 V39
				{0.17,  15.46,  17},    //Coordenadas Vértice 40 V40
				{0.365, 15.22,  19},	//Coordenadas Vértice 41 V41
				{0.67,  14.98,  21},	//Coordenadas Vértice 42 V42
				{1.14,  14.74,  23},	//Coordenadas Vertice 43 V43
				{24.95, 0,      15},	//Coordenadas Vertice 44 V44
				{24.83, 0,      17},	//Coordenadas Vértice 45 V45
				{24.635,0,      19},	//Coordenadas Vertice 46 V46
				{24.33, 0,      21},	//Coordenadas Vertice 47 V47
				{23.86, 0,      23},	//Coordenadas Vértice 48 V48
				{24.95, 15.7,   15},	//Coordenadas Vertice 49 V49
				{24.83, 15.46,  17},	//Coordenadas Vértice 50 V50
				{24.635,15.22,  19},	//Coordenadas Vertice 51 V51
				{24.33, 14.98,  21},	//Coordenadas Vertice 52 V52
				{23.86, 14.74,  23},	//Coordenadas Vértice 53 V53
				{2.5,   15.7,   15},	//Coordenadas Vertice 54 V54
				{2.5,   15.46,  17},	//Coordenadas Vértice 55 V55
				{2.5,   15.22,  19},	//Coordenadas Vertice 56 V56
				{2.5,   14.98,  21},	//Coordenadas Vertice 57 V57
				{2.5,   14.74,  23},	//Coordenadas Vértice 58 V58
				{22.5,  15.7,   15},	//Coordenadas Vertice 59 V59
				{22.5,  15.46,  17},	//Coordenadas Vértice 60 V60
				{22.5,  15.22,  19},	//Coordenadas Vertice 61 V61
				{22.5,  14.98,  21},	//Coordenadas Vertice 62 V62
				{22.5,  14.74,  23},	//Coordenadas Vértice 63 V63
				};

		glBindTexture(GL_TEXTURE_2D, text);
		glEnable ( GL_COLOR_MATERIAL );
		glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Lado Concreto
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[8]);
		glEnd();

		//Puntos del arco----------------------------------------
		 glBegin(GL_POLYGON);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[34]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[39]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[17]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[34]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[35]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[40]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[39]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[35]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[36]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[41]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[40]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[36]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[37]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[42]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[41]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[37]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[38]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[43]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[42]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[38]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[18]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[43]);
		glEnd();
		//---------------

		glBegin(GL_POLYGON);	//Lado Concreto
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[10]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado Concreto
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[12]);
		glEnd();

		//Puntos del arco
		glBegin(GL_POLYGON);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[44]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[49]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[22]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[44]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[45]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[50]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[49]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[45]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[46]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[51]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[50]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[46]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[47]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[52]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[51]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[47]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[48]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[53]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[52]);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[48]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[21]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[53]);
		glEnd();
		//---------------

		glBegin(GL_POLYGON);	//Lado Concreto
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[14]);
		glEnd();

		//Puntos del arco Up
		  glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[39]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[54]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[25]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[17]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[40]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[55]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[54]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[39]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[41]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[56]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[55]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[40]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[42]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[57]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[56]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[41]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[43]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[58]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[57]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[42]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[18]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[58]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[43]);
		glEnd();
		//---------------

		//Puntos del arco Up
		glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[59]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[49]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[22]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[31]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[60]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[50]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[49]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[59]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[61]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[51]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[50]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[60]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[62]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[52]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[51]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[61]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[63]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[53]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[52]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[62]);
		glEnd();

		glBegin(GL_TRIANGLES);	//Up Concreto
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[21]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[63]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[53]);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glBegin(GL_POLYGON);	//Linea
			glVertex3f(8.75, 14.51, 25);
			glVertex3f(9.25, 14.51, 25);
			glVertex3f(9.25, 17.51, 0);
			glVertex3f(8.75, 17.51, 0);
		glEnd();

		glBegin(GL_POLYGON);	//Linea
			glVertex3f(15.75, 14.51, 25);
			glVertex3f(16.25, 14.51, 25);
			glVertex3f(16.25, 17.51, 0);
			glVertex3f(15.75, 17.51, 0);
		glEnd();

		glBegin(GL_POLYGON);	//Linea
			glVertex3f(2.5, 14.51, 25);
			glVertex3f(3.0, 14.51, 25);
			glVertex3f(3.0, 17.51, 0);
			glVertex3f(2.5, 17.51, 0);
		glEnd();

		glBegin(GL_POLYGON);	//Linea
			glVertex3f(22, 14.51, 25);
			glVertex3f(22.5, 14.51, 25);
			glVertex3f(22.5, 17.51, 0);
			glVertex3f(22, 17.51, 0);
		glEnd();

		glBegin(GL_POLYGON);	//Linea
			glVertex3f(7.5, 0, 25.01);
			glVertex3f(8.0, 0, 25.01);
			glVertex3f(8.0, 14.5, 25.01);
			glVertex3f(7.5, 14.5, 25.01);
		glEnd();

		glBegin(GL_POLYGON);	//Linea
			glVertex3f(17, 0, 25.01);
			glVertex3f(17.5, 0, 25.01);
			glVertex3f(17.5, 14.5, 25.01);
			glVertex3f(17, 14.5, 25.01);
		glEnd();

		glColor3f(1,1,1);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D, text2);
		
		glBegin(GL_POLYGON);	//Cuadro de la puerta
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3f(7.5,12.5,25);
			glTexCoord2f(2.0f,  0.0f); glVertex3f(17.5,12.5,25);
			glTexCoord2f(2.0f,  0.5f); glVertex3fv(vertice[33]);
			glTexCoord2f(0.0f,  0.5f); glVertex3fv(vertice[32]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado Cristal
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[17]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[16]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado Cristal
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[32]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[18]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado Cristal
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[12]);
			glTexCoord2f(0.77f,  0.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(0.77f,  1.0f); glVertex3fv(vertice[21]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[33]);
		glEnd();

		glBegin(GL_POLYGON);	//Lado Cristal
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[23]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[22]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Cristal
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[17]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[25]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[24]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[16]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Cristal
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[25]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[27]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[26]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[24]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Cristal
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[27]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[29]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[28]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[26]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Cristal
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[29]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[31]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[30]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[28]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Cristal
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[31]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[22]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[23]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[30]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Cristal
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[18]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[19]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[27]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[25]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Cristal
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[19]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[20]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[29]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[27]);
		glEnd();

		glBegin(GL_POLYGON);	//Up Cristal
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[20]);
			glTexCoord2f(1.0f,  0.0f); glVertex3fv(vertice[21]);
			glTexCoord2f(1.0f,  1.0f); glVertex3fv(vertice[31]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[29]);
		glEnd();

		glDisable(GL_BLEND);

		glDisable ( GL_COLOR_MATERIAL );
	}

void CFiguras::escaleras(GLuint text)
{
	GLfloat vertice [26][3] = {
				{0,    0,    0},        //Coordenadas Vértice 0 V0
				{20,   0,    0},	    //Coordenadas Vértice 1 V1
				{20,   0,    1.8125},   //Coordenadas Vértice 2 V2
				{0,    0,    1.8125},   //Coordenadas Vértice 3 V3
				{0,    2.4,  0},	    //Coordenadas Vértice 4 V4
				{20,   2.4,  0},	    //Coordenadas Vértice 5 V5
				{20,   2.4,  1.8125},	//Coordenadas Vertice 6 V6
				{0,    2.4,  1.8125},	//Coordenadas Vertice 7 V7
				{0,    0,    3.625},	//Coordenadas Vértice 8 V8
				{20,   0,    3.625},	//Coordenadas Vértice 9 V9
				{0,    1.8,  1.8125},   //Coordenadas Vértice 10 V10
				{20,   1.8,  1.8125},   //Coordenadas Vértice 11 V11
				{0,    1.8,  3.625},	//Coordenadas Vértice 12 V12
				{20,   1.8,  3.625},	//Coordenadas Vértice 13 V13
				{0,    0,    5.4375},	//Coordenadas Vertice 14 V14
				{20,   0,    5.4375},	//Coordenadas Vertice 15 V15
				{0,    1.2,  3.625},    //Coordenadas Vértice 16 V16
				{20,   1.2,  3.625},	//Coordenadas Vértice 17 V17
				{0,    1.2,  5.4375},	//Coordenadas Vértice 18 V18
				{20,   1.2,  5.4375},   //Coordenadas Vértice 19 V19
				{0,    0,    7.25},     //Coordenadas Vértice 20 V20
				{20,   0,    7.25},	    //Coordenadas Vértice 21 V21
				{0,    0.6,  5.4375},	//Coordenadas Vértice 22 V22
				{20,   0.6,  5.4375},	//Coordenadas Vertice 23 V23
				{0,    0.6,  7.25},  	//Coordenadas Vertice 24 V24
				{20,   0.6,  7.25},	    //Coordenadas Vértice 25 V25
				};

	glEnable ( GL_COLOR_MATERIAL );
	glColor3f(1,1,1);
		
	glBindTexture(GL_TEXTURE_2D, text);

	glBegin(GL_POLYGON);	//Up primer escalon
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//Up segundo escalon
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[11]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[12]);
	glEnd();

	glBegin(GL_POLYGON);	//Up tercer escalon
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[16]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[17]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[19]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[18]);
	glEnd();

	glBegin(GL_POLYGON);	//Up cuarto escalon
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[22]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[23]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[25]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[24]);
	glEnd();

	glBegin(GL_POLYGON);	//lado primer escalon
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);	//lado segundo escalon
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[12]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[13]);
	glEnd();

	glBegin(GL_POLYGON);	//lado tercer escalon
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[18]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[19]);
	glEnd();

	glBegin(GL_POLYGON);	//lado cuarto escalon
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[21]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[20]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[24]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[25]);
	glEnd();

	glBegin(GL_POLYGON);	//lado A, primer escalon
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);	//lado A, segundo escalon
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[13]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[11]);
	glEnd();

	glBegin(GL_POLYGON);	//lado A, tercer escalon
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[9]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[19]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[17]);
	glEnd();

	glBegin(GL_POLYGON);	//lado A, cuarto escalon
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[15]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[21]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[25]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[23]);
	glEnd();

	glBegin(GL_POLYGON);	//lado B, primer escalon
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//lado B, segundo escalon
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[10]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[12]);
	glEnd();

	glBegin(GL_POLYGON);	//lado B, tercer escalon
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[8]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[16]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[18]);
	glEnd();

	glBegin(GL_POLYGON);	//lado B, cuarto escalon
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[20]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[14]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[22]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[24]);
	glEnd();

	glDisable ( GL_COLOR_MATERIAL );

}

void CFiguras::edifcentral(GLuint text, GLuint text2)
{
	
	GLfloat vertice [8][3] = {
				{0,    0,      0},        //Coordenadas Vértice 0 V0
				{20,   0,      0},	      //Coordenadas Vértice 1 V1
				{20,   0,     20},        //Coordenadas Vértice 2 V2
				{0,    0,     20},        //Coordenadas Vértice 3 V3
				{0,    17.5,   0},	      //Coordenadas Vértice 4 V4
				{20,   17.5,   0},	      //Coordenadas Vértice 5 V5
				{20,   17.5,  20},	      //Coordenadas Vertice 6 V6
				{0,    17.5,  20},	      //Coordenadas Vertice 7 V7
	};

	glBindTexture(GL_TEXTURE_2D, text);
	glEnable ( GL_COLOR_MATERIAL );
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);	//Down
			glNormal3f(0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(4.0f,  4.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f,  4.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);	//Front
			glNormal3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(4.0f,  3.5f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f,  3.5f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Derecha
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(4.0f,  3.5f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  3.5f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(4.0f,  3.5f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f,  3.5f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);	//Izquierda
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f,  3.5f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f,  3.5f); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//UP
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(4.0f,  4.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  4.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);

	glBegin(GL_POLYGON);	//Puerta
			glNormal3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3f(6, 0, -0.1);
			glTexCoord2f(1.0f,  0.0f); glVertex3f(14, 0, -0.1);
			glTexCoord2f(1.0f,  1.0f); glVertex3f(14, 12.5, -0.1);
			glTexCoord2f(0.0f,  1.0f); glVertex3f(6, 12.5, -0.1);
	glEnd();

	glDisable ( GL_COLOR_MATERIAL );
}

void CFiguras::edicenTrasero(GLuint text, GLuint text2)
{
	
	GLfloat vertice [8][3] = {
				{0,    0,        0},        //Coordenadas Vértice 0 V0
				{20,   0,        0},	    //Coordenadas Vértice 1 V1
				{20,   0,        5},        //Coordenadas Vértice 2 V2
				{0,    0,        5},        //Coordenadas Vértice 3 V3
				{0,    13.125,   0},	    //Coordenadas Vértice 4 V4
				{20,   13.125,   0},	    //Coordenadas Vértice 5 V5
				{20,   13.125,   5},	    //Coordenadas Vertice 6 V6
				{0,    13.125,   5},	    //Coordenadas Vertice 7 V7
	};

	glBindTexture(GL_TEXTURE_2D, text);
	glEnable ( GL_COLOR_MATERIAL );
	glColor3f(1,1,1);

		glBegin(GL_POLYGON);	//Down
			glNormal3f(0.0f, -1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);	//Front
			glNormal3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(4.0f,  2.5f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f,  2.5f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Derecha
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(4.0f,  2.5f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  2.5f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(4.0f,  2.5f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f,  2.5f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);	//Izquierda
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(4.0f,  2.5f); glVertex3fv(vertice[4]);
			glTexCoord2f(0.0f,  2.5f); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//UP
			glNormal3f(0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(4.0f,  0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(4.0f,  1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f,  1.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);

	glBegin(GL_POLYGON);	//Puerta
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3f(8, 0, 5.1);
			glTexCoord2f(1.0f,  0.0f); glVertex3f(12, 0, 5.1);
			glTexCoord2f(1.0f,  1.0f); glVertex3f(12, 12.5, 5.1);
			glTexCoord2f(0.0f,  1.0f); glVertex3f(8, 12.5, 5.1);
	glEnd();

	glDisable ( GL_COLOR_MATERIAL );
}

void CFiguras::puertaCristal(GLuint text)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	
	glBindTexture(GL_TEXTURE_2D, text);
	glEnable ( GL_COLOR_MATERIAL );
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3f(0,0,0);
			glTexCoord2f(1.0f,  0.0f); glVertex3f(5,0,0);
			glTexCoord2f(1.0f,  2.5f); glVertex3f(5,12.5,0);
			glTexCoord2f(0.0f,  2.5f); glVertex3f(0,12.5,0);
	glEnd();

	glDisable ( GL_COLOR_MATERIAL );
	glDisable(GL_BLEND);
}

void CFiguras::panel12(GLuint text)
{
	glBindTexture(GL_TEXTURE_2D, text);
	glEnable ( GL_COLOR_MATERIAL );
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3f(0,0.3,0);
			glTexCoord2f(2.5f,  0.0f); glVertex3f(12.5,0.3,0);
			glTexCoord2f(2.5f,  1.0f); glVertex3f(12.5,5.7,0);
			glTexCoord2f(0.0f,  1.0f); glVertex3f(0,5.7,0);
	glEnd();

	glDisable ( GL_COLOR_MATERIAL );
}

void CFiguras::panel10(GLuint text)
{
	glBindTexture(GL_TEXTURE_2D, text);
	glEnable ( GL_COLOR_MATERIAL );
	glColor3f(1,1,1);

	glBegin(GL_POLYGON);
			glNormal3f(0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f,  0.0f); glVertex3f(0,0.3,0);
			glTexCoord2f(2.0f,  0.0f); glVertex3f(10,0.3,0);
			glTexCoord2f(2.0f,  1.0f); glVertex3f(10,5.7,0);
			glTexCoord2f(0.0f,  1.0f); glVertex3f(0,5.7,0);
	glEnd();

	glDisable ( GL_COLOR_MATERIAL );
}

