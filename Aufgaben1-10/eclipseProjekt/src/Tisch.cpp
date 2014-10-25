//Definition eines Tisches aus 4 Beinen und einer runden Platte

#include <GL/freeglut.h>
#include "Wuerfel.h"
#include "Tisch.h"
#include "Tischplatte.h"


void Tisch (GLfloat extent)	{

	Tischplatte (extent);

	glPushMatrix(); //1. Tischbein
	glTranslatef( -extent/2.0f, 0.0f, +extent/2.0f );
	glScalef( extent/10.0f, 1.0f, extent/10.0f);
	glTranslatef( 0.0f, -extent/2.0f, 0.0f );
	Wuerfel (extent);
	glPopMatrix();

	glPushMatrix(); //2. Tischbein
	glTranslatef( -extent/2.0f, 0.0f, -extent/2.0f );
	glScalef( extent/10.0f, 1.0f, extent/10.0f);
	glTranslatef( 0.0f, -extent/2.0f, 0.0f );
	Wuerfel (extent);
	glPopMatrix();

	glPushMatrix(); //3. Tischbein
	glTranslatef( +extent/2.0f, 0.0f, +extent/2.0f );
	glScalef( extent/10.0f, 1.0f, extent/10.0f);
	glTranslatef( 0.0f, -extent/2.0f, 0.0f );
	Wuerfel (extent);
	glPopMatrix();

	glPushMatrix(); //4. Tischbein
	glTranslatef( +extent/2.0f, 0.0f, -extent/2.0f );
	glScalef( extent/10.0f, 1.0f, extent/10.0f);
	glTranslatef( 0.0f, -extent/2.0f, 0.0f );
	Wuerfel (extent);
	glPopMatrix();
}
