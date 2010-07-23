#include <GL/glut.h>	
GLUquadricObj *theObj;	// Declare Quadric variable

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 0.0);	
	glColor3f(0.0, 0.0, 1.0);		
	glMatrixMode(GL_PROJECTION);		
	glLoadIdentity();
    	glOrtho(-50,50,-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	theObj = gluNewQuadric();		// Create Quadric object to theObj.
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	// Anti-Alias
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glPushMatrix();
	glRotatef(180, 0.0, 1.0, 1.0);
	gluQuadricDrawStyle(theObj, GLU_LINE);	
	gluSphere(theObj, 40.0, 50, 20);			// For Sphere
	//gluCylinder(theObj, 10, 20, 40, 20, 20);		// For Cylinder
	//gluDisk(theObj, 10, 40, 20, 10);			// For Disk
	//gluPartialDisk(theObj, 10, 40, 20, 10, 0, 270);	// For PartialDisk

	glPopMatrix();
	glutSwapBuffers();
	glFlush ( );     
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv);                       
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
	glutInitWindowPosition (50, 50);	
	glutInitWindowSize(400, 400);	
	glutCreateWindow("Quadric object");	
	init();				
	glutDisplayFunc(myDisplay);	
	glutIdleFunc(myDisplay);
	glutMainLoop();	
    return 0;	
}
