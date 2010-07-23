#include <GL/glut.h>	

void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 0.0);	
	glColor3f(0.0, 0.0, 1.0);	
	glMatrixMode(GL_PROJECTION);	
    	glOrtho(-50,50,-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	
	// Anti-Alias
	glEnable (GL_LINE_SMOOTH);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPushMatrix();
	glRotatef (90, 0.0, 1.0, 1.0);	
	//glutSolidSphere (40, 50, 20);
	glutWireSphere (40, 50, 20);
	//glutSolidCube (40);
	//glutWireCube (40); 
	//glutSolidCone (20, 40, 20, 20);
	//glutWireCone (20, 40, 20, 10); 
	//glutSolidTorus (10, 20, 10, 20);
	//glutWireTorus (10, 20, 10, 10); 
	
	//glScalef (30,30,0.0);
	//glutSolidDodecahedron ( );
	//glutWireDodecahedron ( ); 
	//glutSolidOctahedron ( );
	//glutWireOctahedron ( ); 
	//glutSolidTetrahedron ( );
	//glutWireTetrahedron ( ); 
	//glutSolidIcosahedron ( );
	//glutWireIcosahedron ( ); 
	//glutSolidTeapot (25);
	//glutWireTeapot (25); 
	
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
	glutCreateWindow("Geometric object from GLUT");	
	init();			
	glutDisplayFunc(myDisplay);	
	glutIdleFunc(myDisplay);
	glutMainLoop();	
    return 0;	
}
