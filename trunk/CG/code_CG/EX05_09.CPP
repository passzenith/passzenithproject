#include <GL/glut.h>      	

GLubyte text [27] = {'H', 'e', 'l', 'l', 'o', '.', '.', '.', 'O', 'p', 'e', 'n', 'G', 'L', ' ','P', 'r', 'o', 'g', 'r', 'a', 'm', 'm', 'e', 'r', 's', '.'};
GLint k;
GLint xRaster=100, yRaster=450;

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);		
	glLineWidth (4.0);			
	glMatrixMode (GL_PROJECTION);       	
	glLoadIdentity ();
	gluOrtho2D (0.0, 500.0, 0.0, 500.0);
}

void myDisplay (void)
{
	glClear (GL_COLOR_BUFFER_BIT);	
	glColor3f (1.0, 0.0, 0.0);	
	glRasterPos2i(xRaster,yRaster);		// Specify position to display.
	for (k=0; k<27; k++)			// Loop forward.
		// Display 27 characters.
		glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, text [k]);
	
	glColor3f (0.0, 1.0, 0.0);		// Set color to green.
	glRasterPos2i(xRaster,yRaster-50);	// Specify position to display.
	for (k=26; k>=0; k--)			// Loop backward.
		// Display 27 characters.
		glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, text [k]);	

	glColor3f (0.0, 0.0, 1.0);		// Set color to blue.
	for (k=0; k<14; k++)			// Loop forward.
	{
		glRasterPos2i(xRaster,yRaster-100);	// Specify position to display.
		// Display 14 characters.
		glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, text [k]);	
		yRaster-=20;				// Decrease yRaster.
	};

	glColor3f (1.0, 0.0, 1.0);		// Set color to Magenta.
	xRaster=100, yRaster=50;			// Specify xRaster and yRaster

		for (k=0; k<14; k++)			// Loop forward.
	{
		glRasterPos2i(xRaster,yRaster);	// Specify position to display.
		// Display 14 characters.
		glutBitmapCharacter (GLUT_BITMAP_TIMES_ROMAN_24, text [k]);	
		xRaster+=20;				// Increase xRaster.
		yRaster+=20;				// Increase yRaster.
	};


	// For Stroke Character
	glColor3f (0.0, 0.0, 0.0);		// Set color to Black.
	for (k=0; k<11; k++)			// Loop forward.
		// Display 10 characters.
		glutStrokeCharacter (GLUT_STROKE_ROMAN, text [k]);	

	glFlush ( );     
}

void main (int argc, char** argv)
{
	glutInit (&argc, argv);                   
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   	
	glutInitWindowPosition (50, 50);		
	glutInitWindowSize (500, 500);		
	glutCreateWindow ("Display Characters on screen."); 

	init ( );					
	glutDisplayFunc (myDisplay);		
	glutMainLoop ( );			
}
