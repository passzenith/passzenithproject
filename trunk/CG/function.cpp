#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <constant.h>

int PitchDice()
{
       // บันทึกการทอยลูกเต๋าในแต่ละตา
return 0;
}

int Location()
{
       // บันทึกตำแหน่งปัจจุบัน
return 0;
}

int Ranking()
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
	/*
	กำหนดว่า ที่ field [Width][High]มีค่า gameevent = ?
	 1 = เดินถอยหลังไป ... (random เอา)
	 2 = ตกหลุม  หล่น ไปด้านล่าง field [5][5]  >> field [5][4] 
	 3 = ปีนบันไดขึ้นข้างบน field [5][5]  >> field [5][6]
	 4 = หยุดเดิน 1 ตา
	 5 = เดินอีกตา 
	 อื่นๆ เดินปกติ
	 */
	
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