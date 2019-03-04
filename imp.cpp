#include"Header.h"
int student::counter=0;
student::student()//defualt constructor
{
	cout<<"Instructor invoke:"<<endl;
	++counter;
	ID=counter;
	quizCapacity=3; // capacity of quizScore Array
	quizTaken=0;
	quizScore=new float[quizCapacity];
    quizScore=nullptr;
	 // number of quizzes taken, cannot be greater than capacity
	GPA=-1;
}
student::student(int x,float y)//overloaded constructor
{
	++counter;
	ID=counter;
	quizCapacity=x;
	GPA=y;
	quizTaken=0;
	quizScore=new float[quizCapacity];
	quizScore=nullptr;
	cout<<"Overloaded constructor invoke:"<<endl;
}
student::student(const student & a)//copy constructor
{
	ID=a.ID;
	quizCapacity=a.quizCapacity;
	quizTaken=a.quizTaken;
	GPA=a.GPA;
	quizScore=new float[a.quizCapacity];
	for(int i=0;i<a.quizCapacity;i++)
	{
		quizScore[i]=a.quizScore[i];

	}
}
student::~student()//Destructor
{
	   delete[]quizScore;
	   cout<<"Destructor invoke: "<<endl;
}
void student::addQuizScore(int s)//To add score of quizzes
{
	if(quizTaken>=quizCapacity)
		cout<<"No space to add new quiz score:"<<endl;
	else
	{
		
		if(quizScore==nullptr)
			quizScore=new float[quizCapacity];
		quizScore[quizTaken]=s;
		quizTaken++;
	}
	 
}
void student::setGPA(float a)// To set gpa
{
	GPA=a;
}
float student::getGPA()const//To return GPA
{
	return GPA;
}
void student::print()const//Print function
{
	cout<<"Student Id::"<<ID<<endl;
	cout<<"Student GPA:"<<GPA<<endl;
	cout<<"Quizes taken:"<<quizTaken<<endl;
	for(int i=0;i<quizTaken;i++)
	cout<<"Quiz "<<i<<" Score: "<<quizScore[i]<<endl;
	cout<<endl;

}
bool student::compare(student a)//compares GPA of two students
{
	if(a.GPA>GPA)
	{
		return true;
	}
	else return false;
}
void student::updateScore(int nmb,int quizscore)//update Score of quizzes
{
	if(nmb<=quizTaken)
		quizScore[nmb]=quizscore;
	else
		cout<<"Quiz "<<nmb<<" is not taken:"<<endl;
}
void printarray(student*array,int size)//print static array
{
	for(int i=0;i<size;i++)
	{
		array[i].print();
	}
}
void printarray(student**array,int size)//print dynamic array
{
	for(int i=0;i<size;i++)
	{
		(*array[i]).print();
	}
}
student*setgpagreaterthantwo(student*array,int size,int &sizechecker)//To set gpa>2 for static array
{
	sizechecker=0;
	for(int i=0;i<size;i++)
	{
		if((array[i]).getGPA>2)
			sizechecker++;
	}
	student*arr=new student[sizechecker];
	for(int i=0;i<size;i++)
	{
			if((array[i]).getGPA>2)
				arr[i]=(array[i]).getGPA;
	}
		return arr;
}
student**dynamicsetgpagreaterthantwo(student**array,int size,int&sizechecker)//To set gpa>2 for static array
{
	sizechecker=0;
	for(int i=0;i<size;i++)
	{
		if((*array[i]).getGPA>2)
			sizechecker++;
	}
	student**arr=new student*[sizechecker];
	for(int i=0;i<size;i++)
	{
			if((*array[i]).getGPA>2)
				(*arr[i])=(*array[i]).getGPA;
	}
		return arr;
}
void arraysortingindescendingorder(student*array,int size)//Array sorting
{
	student maxgpa=array[0];
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(array[i].getGPA()<array[j].getGPA())
			{
				maxgpa=array[i];
				array[i]=array[j];
				array[j]=maxgpa;
			}
		}
	}
		
}