#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <constant.h>

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

void Event ()
{
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
}