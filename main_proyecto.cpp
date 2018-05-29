//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): Baca Velazquez Norma Elizabeth*********************************//
//*************			Mayo Palma Karla			******//
//*************	Visual Studio 2010-2015				******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015
#if (_MSC_VER == 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
static GLuint ciudad_display_list;	//Display List for the Monito



CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

CTexture text1;//cielo
CTexture text2;//carretera
CTexture text3;//pasto
CTexture text4;//edificio de en frente
CTexture text5;//pared blanca
CTexture text6;//Piedra volcanica
CTexture text7;//ParedGris
CTexture text8;//LogoAurrera
CTexture text9;//PuertaAurrera
CTexture text10;//Pisoestacionamiento
CTexture text11;//ParedEstacionameintoEdifico


CFiguras fig1;//funcion cielo
CFiguras fig2;//Función edicio de en frente
CFiguras fig3;//piso de piedra volcanica
CFiguras fig4;//super mercado
CFiguras fig5;//puerta super
CFiguras piso;//funcion piso
CFiguras pasto;//funcion piso

			  //Figuras 3D


//Animación 
bool reset = true;
float movKit = 0.0;
bool g_fanimacion = false;
float anim_llantas = 0;
bool avanza = true;
bool adelante = true;




void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);

	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadTGA("cemento1.tga");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadBMP("pasto.bmp");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	text4.LoadTGA("edificio.tga");
	text4.BuildGLTexture();
	text4.ReleaseImage();

	text5.LoadTGA("ParedBlanca.tga");
	text5.BuildGLTexture();
	text5.ReleaseImage();

	text6.LoadTGA("piedravolcanica.tga");
	text6.BuildGLTexture();
	text6.ReleaseImage();

	text7.LoadTGA("ParedGris.tga");
	text7.BuildGLTexture();
	text7.ReleaseImage();

	text8.LoadTGA("logoaurrera.tga");
	text8.BuildGLTexture();
	text8.ReleaseImage();

	text9.LoadTGA("PuerAlumfron.tga");
	text9.BuildGLTexture();
	text9.ReleaseImage();

	text10.LoadTGA("PisoEstacionamiento.tga");
	text10.BuildGLTexture();
	text10.ReleaseImage();

	text11.LoadTGA("ParedEstEdif.tga");
	text11.BuildGLTexture();
	text11.ReleaseImage();

	

	//Carga de Figuras

	//kiosco._3dsLoad("kiosco.3ds");
	//kiosco.Scale(0.02);

	//kit.VertexNormals();


	//END NEW//////////////////////////////

	objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
							//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();


	glPushMatrix();
	glRotatef(g_lookupdown, 1.0f, 0, 0);

	gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
		objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
		objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);


	glPushMatrix();
		glPushMatrix(); //Creamos cielo
			glDisable(GL_LIGHTING);
			glTranslatef(0, 50, 0);
			fig1.skybox(300.0, 300.0, 300.0, text1.GLindex);
			glEnable(GL_LIGHTING);
		glPopMatrix();
	//glBindTexture(GL_TEXTURE_2D....)
	//glTexCoord2f( coordenadas)
			glPushMatrix(); //Carretera
				glDisable(GL_LIGHTING);
				glTranslatef(0, -99.9, 0);
				glScalef(2,0,10);
				piso.prisma(.01,30.0,30.0, text2.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //Pasto en frente de edificio
				glDisable(GL_LIGHTING);
				glTranslatef(-64, -99.9,-90);
				glScalef(2.4, 0,4);
				pasto.prisma(.01, 30.0, 30.0, text3.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //Edificio de enfrente
				glDisable(GL_LIGHTING);
				glTranslatef(-124.5, -59.8, -89.8);
				glScalef(50,80,120);
				fig2.prisma2(text5.GLindex, text4.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //Entradas edificio
				glDisable(GL_LIGHTING);
				glTranslatef(-88, -99.8, -72);
				glScalef(5, 0,1);
				fig3.prisma(.01, 5.0, 5.0, text6.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //Entradas edificio
				glDisable(GL_LIGHTING);
				glTranslatef(-88, -99.8, -81.5);
				glScalef(5, 0, 1);
				fig3.prisma(.01, 5.0, 5.0, text6.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //Entradas edificio
				glDisable(GL_LIGHTING);
				glTranslatef(-52, -99.8, -76.3);
				glScalef(9.5, 0,2.8);
				fig3.prisma(.01, 5.0, 5.0, text6.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //super mercado
				glDisable(GL_LIGHTING);
				glTranslatef(-124.5,-84.8, 50);
				glScalef(50,30,80);
				fig4.prisma2(text7.GLindex, text7.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //anuncio
				glDisable(GL_LIGHTING);
				glTranslatef(-100,-62.5, 50);
				glScalef(0.1, 15,60);
				fig4.prisma2(text7.GLindex,text8.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //Entrada aurrera
				glDisable(GL_LIGHTING);
				glTranslatef(-99.5,-92.5,50);
				//glScalef(0.1,5, 6);
				fig5.prisma(15,0.1,30, text9.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //Estacionamiento Edificio
				glDisable(GL_LIGHTING);
				glTranslatef(-124,-99.8,-9.5);
				//glScalef(0.1,5, 6);
				piso.prisma(0.1,52,40.3, text10.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //ParedEstacionamientoEdificio
				glDisable(GL_LIGHTING);
				glTranslatef(-124.5,-87,10);
				fig2.prisma(25,50,0.1, text11
					.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glPushMatrix(); //RejaEstacionamientoedificio
				glDisable(GL_LIGHTING);
				glTranslatef(-99.5, -92.5,-10);
				//glScalef(0.1,5, 6);
				fig2.prisma(15, 0.1,40, text9.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
		glPopMatrix();
			

	

	//Para que el coche conserve sus colores
	glDisable(GL_COLOR_MATERIAL);
	glTranslatef(0, 2, 0);
	glScalef(0.3, 0.3, 0.3);
	//Pongo aquí la carroceria del carro
	

										  //tent  

										  //Cambia algo de la camara	
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);

	glPopMatrix();
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}
void animacion()
{

	if (g_fanimacion)
	{

		if (movKit<35)
		{
			movKit += 1.0;
		}

		else
		{
			movKit = 0.0;
			g_fanimacion = false;

		}
		glutPostRedisplay();
	}
}
void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1,500.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case ' ':		//Poner algo en movimiento
		g_fanimacion ^= true; //Activamos/desactivamos la animacíon
		reset ^= true;
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(800, 800);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto Final"); // Nombre de la Ventana
										//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
