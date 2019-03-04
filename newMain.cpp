#include"Header.h"
int main()
{
	student st[3]={student(3,2.0),student(3,3.0),student(4,2.33)};
	st[0].addQuizScore(1);
	st[0].addQuizScore(4);
	st[0].addQuizScore(10);
	st[1].addQuizScore(10);
	st[1].addQuizScore(4);
	st[1].addQuizScore(9);
	st[2].addQuizScore(9);
	st[2].addQuizScore(8);
	st[2].addQuizScore(7);
	st[0].print();
	st[1].print();
	st[2].print();
	int size=4;
	student*st2=new student[size];
	st2[0]=student(3,2.0);
    st2[0].addQuizScore(1);
	st2[0].addQuizScore(4);
	st2[0].addQuizScore(10);
    st2[1]=student(3,3.0);
	st2[1].addQuizScore(10);
	st2[1].addQuizScore(4);
	st2[1].addQuizScore(9);
	st2[2]=student(4,2.33);
	st2[2].addQuizScore(9);
	st2[2].addQuizScore(8);
	st2[2].addQuizScore(7);
	st2[3]=student(4,1.00);
	st2[3].addQuizScore(2);
	st2[3].addQuizScore(3);
	st2[0].print();
	st2[1].print();
	st2[2].print();
	st2[3].print();
	int sizechecker=0;
	student* arrayofgpa=setgpagreaterthantwo(st,3,sizechecker);
	for (int i=0;i<sizechecker ;i++)
	{
	  arrayofgpa[i].print();
	}
	system("pause");
}