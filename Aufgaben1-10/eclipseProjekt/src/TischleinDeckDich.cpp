/* ----------------------------------------------------------- */
/* Graph.-DV-Praktikum Startprogramm                           */
/* ----------------------------------------------------------- */
/* Datei: Nix.cpp          W.-D. Groch                         */
/* ----------------------------------------------------------- */
/* Wie der Name sagt, tut dieses Programm so gut wie nix       */
/* Last Update:    05.07.2014   W.-D. Groch                    */
/* ----------------------------------------------------------- */

#include <iostream>
#include <GL/freeglut.h>         //laedt auch glut.h und gl.h
#include <math.h>
#include "Wuerfel.h"
#include "Tisch.h"
#include "Tischplatte.h"
#include "Boden.h"

GLfloat extent = 1.0; // Mass fuer die Ausdehnungdes Modells
GLfloat hoehe = 0.0; //steuert die Auf- und Abwärtsbewegung des Tisches
GLfloat virthoehe = 0.0; //steuert die Auf- und Abwärtsbewegung des Tisches


void Init()
{
// Hier finden jene Aktionen statt, die zum Programmstart einmalig
// durchgefuehrt werden muessen
	glClearColor ( 0.33f, 0.225f, 0.0f, 1.0f );
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
}

void RenderScene(void)
{
// Hier befindet sich der Code der in jedem frame ausgefuehrt werden muss
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// was loeschen?
   glLoadIdentity ();
   gluLookAt(5.0*extent, 5.0*extent, 10.0*extent, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Kamera-
   // sicht von wo?
   Boden (extent);
   //glClear (GL_DEPTH_BUFFER_BIT);
   glTranslatef( 0.0f, hoehe, 0.0f );
   Tisch (extent);
   glutSwapBuffers();
}

void Reshape(int width,int height)
{
// Hier finden die Reaktionen auf eine Veraenderung der Groesse des
// Graphikfensters statt
	glMatrixMode(GL_PROJECTION); // Matrix für Transf.: Frustum->Viewport
	glLoadIdentity();
	glViewport(0,0,width,height);
	glOrtho(-extent*2.0,+extent*2.0,-extent*2.0,+extent*2.0,0.0,+20.0*extent); //Frustum
	glMatrixMode(GL_MODELVIEW); // Modellierungs-/Viewing-Matrix
}

void Animate (int value)
{
	// Hier werden Berechnungen durchgefuehrt, die zu einer Animation der Szene
	// erforderlich sind. Dieser Prozess laeuft im Hintergrund und wird alle
	// wait_msec msec aufgerufen. Der Parameter "value" wird einfach nur um
	// eins inkrementiert und dem Callback wieder uebergeben.
	static GLfloat richtung = 1.0;
	virthoehe = virthoehe + (float) 0.005*richtung;
	if ( virthoehe >= -extent && virthoehe <= extent) hoehe = virthoehe;
	if ( virthoehe <= -0.5*extent) richtung = +1.0;
	if ( virthoehe >= 1.0*extent) hoehe = extent;
	if ( virthoehe >= 1.5*extent) richtung = -1.0;
   // RenderScene aufrufen.
   glutPostRedisplay();
   // Timer wieder registrieren - Animate wird so nach 10 msec mit value+=1 aufgerufen.
   int wait_msec = 10;
   glutTimerFunc(wait_msec, Animate, ++value);
}


int main(int argc, char **argv)
{
   glutInit ( &argc, argv );
   glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
   glutInitWindowSize ( 600,600 );
   glutCreateWindow ("*** TischleinDeckDich zu sehen");
   glutDisplayFunc ( RenderScene );
   glutReshapeFunc ( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0
   glutTimerFunc(10,Animate,0);
   Init();
   glutMainLoop ();
   return 0;
}
