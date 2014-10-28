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


void Init()
{
// Hier finden jene Aktionen statt, die zum Programmstart einmalig
// durchgefuehrt werden muessen
}

void RenderScene(void)
{
// Hier befindet sich der Code der in jedem frame ausgefuehrt werden muss
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// was loeschen?
   glutSwapBuffers();
}

void Reshape(int width,int height)
{
// Hier finden die Reaktionen auf eine Veraenderung der Groesse des
// Graphikfensters statt
}

void Animate (int value)
{
	// Hier werden Berechnungen durchgefuehrt, die zu einer Animation der Szene
	// erforderlich sind. Dieser Prozess laeuft im Hintergrund und wird alle
	// wait_msec msec aufgerufen. Der Parameter "value" wird einfach nur um
	// eins inkrementiert und dem Callback wieder uebergeben.
	std::cout << "value=" << value << std::endl;
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
   glutCreateWindow ("*** Nix zu sehen");
   glutDisplayFunc ( RenderScene );
   glutReshapeFunc ( Reshape );
   // TimerCallback registrieren; wird nach 10 msec aufgerufen mit Parameter 0
   glutTimerFunc(10,Animate,0);
   Init();
   glutMainLoop ();
   return 0;
}
