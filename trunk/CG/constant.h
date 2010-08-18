 
const int Width = 5;  //กระดานกว้างเท่าไร
const int High = 5;  //กระดานสูงเท่าไร
int field [Width][High];
//เลขของตัวละคร
int Shichi = 1; // ดิน
int Aqua = 2; //น้ำ
int Windy = 3;//ลม
int Akki = 4; //ไฟ

typedef struct  
{
	int Dice; // ทอยได้เท่าไหร่
	int Location; // ตำแหน่งปัจจุบัน
	int Rank;//อันดับผู้เล่นในปัจจุบัน
	int Turn; //มีลำดับการเล่นอยู่ลำดับที่ 1-4
	bool PlayerIsStop;//ถูกส่งให้หยุดหรือไม่ถ้าไม่ก็ได้เล่น
	char name[20]; // ชื่อ
}Record;

typedef struct  
{
	int player; // player อะไร
	Record record; // มีค่าอะไรบ้าง
}Player; // Player อะไร

int event;
