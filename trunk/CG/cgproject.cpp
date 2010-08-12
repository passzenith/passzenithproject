#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
//ตัวแปรที่กำหนดไว้
const int CountPlayer = 4; //number player มี 1-4 คน   
const int Width = 12;  //กระดานกว้างเท่าไร
const int High = 12;  //กระดานสูงเท่าไร
int DiceNumber = 0;
int Player[] = {0,1,2,3}; // เบอร์คนเล่น
int PlayerDice[CountPlayer];// เบอร์คนเล่น,ค่าที่ทอยลูกเต๋า >>PlayerDice[Player[0]] = 2 เป็นต้น 
int PlayerLocation[CountPlayer]; //เบอร์คนเล่น,ตำแหน่งคนเล่นในปัจจุบัน
int PlayerRank[CountPlayer]; //เบอร์คนเล่น,อันดับผู้เล่นในปัจจุบัน (เช่น คนที่ 1 ได้อันดับสาม)
int PlayerCharacter[CountPlayer];//เบอร์คนเ่ล่น,ตัวละครที่เลือก   ไว้สำหรับมีกรณีผู้เล่นตั้งชื่อเองได้
int PlayerTurn[CountPlayer];//เบอร์คนเล่น,ลำดับการเดิน  มาจากการทอยลูกเต๋าครั้งแรก
int Field [Width][High] ;
bool PlayerStop[CountPlayer];
int event;
int gameevnt;
//function


int ChooseCharacter(int PlayerCharacter ) 
{
		// บันทึกว่า  player คนไหน เลือกตัวละครอะไร 

return 0;
}

int ChooseTurn(PlayerTurn)
{
		//บันทึกลำดับการเล่น
return 0;
}

int PitchDice(int PlayerDice)
{
       // บันทึกการทอยลูกเต๋าในแต่ละตา
return 0;
}

int Ranking(int PlayerRank)
{
       // บันทึกตำแหน่งปัจจุบัน
return 0;
}

int Ranking(int PlayerRank)
{
       // บันทึกอันดับการเล่นที่เปลี่ยนไป
return 0;
}

void MoveCharacter()
{
//เปลี่ยนที่โดยการหมุนรอบตัวแล้วไปโผล่ในตำแหนงปลายทาง
}
void FieldEvent()
{
	//กำหนดว่า ที่ field [x][y] มีค่า gameevent = ?
}


/*

void SpecialKeys( int key, int x, int y)//ถ้าทำเป็นเมาสบังคับไม่ได้
{

   switch ( key )    
	{ 				 
        
      	//เปลี่ยนมุมกล้อง
       case GLUT_KEY_RIGHT:

		break;

		case GLUT_KEY_UP:

			break;
        
        case GLUT_KEY_LEFT:

			break;
		
        case GLUT_KEY_DOWN:

			break;
		
        
        case GLUT_KEY_PAGE_UP:

			break;
            
       
        case GLUT_KEY_PAGE_DOWN:

			break;
				// zoomin zoom out
        case GLUT_KEY_F1:                          

            break;
           
        case GLUT_KEY_F2:

        break;
		else 
			break;
}

*/
void display (void)
{
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear display window.
	
		glEnable (GL_LINE_SMOOTH);
		glEnable (GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
     


		glPushMatrix();
		glutWireCube(20.0) //ตัวแทนละคร
		
		switch (gameevent)
		{
		case 1: //เดินถอยหลังไป ... (random เอา)
			break;
		case 2: //ตกหลุม  หล่น ไปด้านล่าง field [5][5]  >> field [5][4] 
			break;
		case 3://ปีนบันไดขึ้นข้างบน field [5][5]  >> field [5][6] 
			break; 
		case 4://หยุดเดิน 1 ตา
			//PlayerStop[Player[?]] = false;
		case 5://เดินอีกตา
			//ทำให้ทอยลุูกเต๋าใหม่อีกรอบ
			break; 
		else 
			// เดินปกติ
		break;
		}
		
		
		glPopMatrix();
        glPopMatrix();
        glutSwapBuffers();
        glFlush ( );   


}





void init(void)
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0, 1.0, 1.0, 0.0 );	// Set display-window color to White
	glColor3f(1.0, 1.0, 1.0);	
	glMatrixMode(GL_PROJECTION);	
	//glRotatef (45.0, 0.0, 1.0, 1.0);  //Set  axis 
    glOrtho(-50,50,-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

void display (void)
{


}
int main (int argc, char **argv)
{
				
	glutInit (&argc, argv);

	lutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (50, 50);
	glutInitWindowSize (500, 500);
	glutCreateWindow ("demo");
	init ( );
	glutDisplayFunc (display);
	glutSpecialFunc(SpecialKeys) ;
	glutMainLoop ( );
	
	return 0;
}
