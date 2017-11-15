// GD-Praktikum:   teil_1.cpp  (Teil 1: Start-Programm)
// Hergenroether / Groch    Last Update: 05.07.2014

#include <iostream> 
#include "GL/freeglut.h"         //lädt alles für OpenGL
#include "gdv.h"

float angle = 0.0f;


void Init()
{
	// Hier finden jene Aktionen statt, die zum Programmstart einmalig 
	// durchgeführt werden müssen
	glutInitWindowPosition(-1, -1);
	glutInitWindowSize(600, 600);         // Fenster-Konfiguration
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Jens; Dennis");   // Fenster-Erzeugung
	glutDisplayFunc(RenderScene);         // Zeichenfunktion bekannt machen
	glutReshapeFunc(Reshape);  //ResizeFunktion bekanntmachen
	glutIdleFunc(RenderScene); 
}

void RenderScene() //Zeichenfunktion
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();   // Aktuelle Model-/View-Transformations-Matrix zuruecksetzen
	//
	
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	//square(1,0);
	square(0.5, 0);
	//square(0.5, 1);
	angle += 0.01f;
	glutSwapBuffers(); //with GLUT_DOUBLE using two buffers, changing happens here
}

void Reshape(int width, int height)
{
	// Hier finden die Reaktionen auf eine Veränderung der Größe des 
	// Graphikfensters statt

	if (height == 0)height = 1; //Prevent divide by zero
	float ratio = width / height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height); //Viewport to entire window
	glMatrixMode(GL_MODELVIEW);

}

void Animate(int value)
{
	// Hier werden Berechnungen durchgeführt, die zu einer Animation der Szene  
	// erforderlich sind. Dieser Prozess läuft im Hintergrund und wird alle 
	// 1000 msec aufgerufen. Der Parameter "value" wird einfach nur um eins 
	// inkrementiert und dem Callback wieder uebergeben. 
	std::cout << "value=" << value << std::endl;
	// RenderScene aufrufen
	glutPostRedisplay();
	// Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
	int wait_msec = 10;
	glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);                // GLUT initialisieren
	Init();
	glutMainLoop();
	
	
	
	
	// TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0  
	//glutTimerFunc(10, Animate, 0);
	
	return 0;
}

void square(float size, float position) {

	glBegin(GL_POLYGON);
	glColor4f(1.0, 0.0, 0.0, 1.0);
	glVertex3f((-0.5+position) *size, (-0.5 + position) *size, (-0.5 + position) *size);
	glVertex3f((0.5 + position) * size, (-0.5 + position) * size, (-0.5 + position) * size);
	glVertex3f((0.5 + position) * size, (0.5 + position) *size, (-0.5 + position) * size);
	glVertex3f((-0.5 + position) * size, (0.5 + position) * size, (-0.5 + position) * size);
	glEnd();
	

}
