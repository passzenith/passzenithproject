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
int field [Width][High] ;
bool PlayerStop[CountPlayer];
int event;
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

void MoveCharacter(void)
{
//เปลี่ยนที่โดยการหมุนรอบตัวแล้วไปโผล่ในตำแหนงปลายทาง
}


void ZoomField(void)
{
//ซูมภาพ เล็ก หรือใหญ่
}

void ZoomField(void)
{
//หมุนดูฉาก
}

void display (void)
{
		switch (event)
		{
		case 1: //เดินถอยหลังไป ... ตา (random เอา)
			break;
		case 2: //ตกหลุม  หล่น ไปด้านล่าง field [5][5]  >> field [5][4] 
			break;
		case 3://ปีนบันไดขึ้นข้างบนง field [5][5]  >> field [5][6] 
			break; 
		case 4://หยุดเดิน 1 ตา
			//PlayerStop[Player[?]] = false;
		case 5://เดินอีกตา
			//ทำให้ทอยลุูกเต๋าใหม่อีกรอบ
			break; 
		else 
			break;
		}
}





void init(void)
{

	
}

void display (void)
{


}
int main (int argc, char **argv)
{
				
	glutInit (&argc, argv);
	
	return 0;
}
