/*
 * Title: Student Report
 * Description: Student Report Options
 * Author: Emily Contreras
 * Date: 4/28/23
 */
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include "Student.h"

using namespace std;

//Print dash lines of n dashes
void printDash(int n)
{
	for(int i = 0; i < n; i++)
		cout << "-";
	cout << endl;
}

//Comparator function for Average decreasing order sorting
bool tempAvg(Student s1, Student s2)
{
	if (s1.getAverage() == s2.getAverage())
	{
		return (s1.getID() < s2.getID());
	}
	return (s1.getAverage() > s2.getAverage());
}

//Comparator function for name order sorting
bool tempName(Student s1, Student s2)
{
	if (s1.getName() == s2.getName())
	{
		return (s1.getID() < s2.getID());
	}
	return (s1.getName() < s2.getName());
}

//Printing Numerical average order
void printAvg(vector<Student> course)
{
	sort(course.begin(), course.end(), tempAvg);
	vector<Student>::iterator it;
	printDash(50);
	cout << "  Course Report: Numerical Average Order" << endl;
	printDash(50);
	for (it = course.begin(); it != course.end(); it++)
	{
		printf("  %-8s %4d - %6.2f (%c) (rank: %d)\n", it->getName().c_str(), it->getID(), it->getAverage(), it->getGrade(), it->getRank());
	}
	printDash(50);
}

//Printing Name order
void printName(vector<Student>course)
{
	sort(course.begin(),course.end(),tempName);//Sort the vector
	vector<Student>::iterator it;
	printDash(50);
	cout<<"  Course Report: First Name Order"<<endl;
	printDash(50);
	for(it=course.begin();it!=course.end();it++){
		printf("  %-8s%4d - %6.2f (%c) (rank: %d)\n",it->getName().c_str(),it->getID(),it->getAverage(),it->getGrade(),it->getRank());
	}
	printDash(50);
}

//Print Statistics
void printStat(vector<Student>course)
{
	int num = course.size();
	vector<Student>::iterator it;
	printDash(50);
	cout<<"  Statistics"<<endl;
	printDash(50);
	cout<<"  Number of students: "<<num<<endl;
	double avg = 0;
	int arr[6] = {0,0,0,0,0,0};
	for(it=course.begin();it!=course.end();it++){
		avg += it->getAverage();
		arr['F'-it->getGrade()] += 1;
	}
	avg /= num;
	cout<<"  Class Average: "<<avg<<endl;

	cout<<"  Grade Distribution (histogram)"<<endl<<endl;
	cout<<"  A ";
	for(int i=0;i<arr[5];i++)cout<<"* ";
	cout<<endl;
	cout<<"  B ";
	for(int i=0;i<arr[4];i++)cout<<"* ";
	cout<<endl;
	cout<<"  C ";
	for(int i=0;i<arr[3];i++)cout<<"* ";
	cout<<endl;
	cout<<"  D ";
	for(int i=0;i<arr[2];i++)cout<<"* ";
	cout<<endl;
	cout<<"  F ";
	for(int i=0;i<arr[0];i++)cout<<"* ";
	cout<<endl;
	printDash(50);
}
//Finding record of a student by their name
void recordFind(vector<Student>course)
{
	printDash(50);
	cout<<"  Record Finder: Enter the name of a student: ";
	string name;
	cin>>name;
	vector<Student>::iterator it;
	bool flag = true;
	for(it=course.begin();it!=course.end();it++){
		if(it->getName()==name){
			it->print();
			flag = false;
		}
	}
	if(flag){
		cout<<"  Fail. "<<name<<" isn't enrolled in this class."<<endl<<endl;
	}
}
int main()
{
	cout<<"\n\nEnter an input file: ";
	string fileName;
	cin>>fileName;
	fstream file1;
	file1.open(fileName.c_str(),ios::in);
	if(file1.fail()){
		cout<<"Error: Could not open file"<<endl;
		exit(EXIT_FAILURE);
	}
	vector<Student>course;
	string str;
	while(getline(file1,str)){
		char tname[10];
		string name;
		int id;
		double quiz[5];
		double score[3];
		sscanf(str.c_str(),"%s %d %lf %lf %lf %lf %lf %lf %lf %lf",tname,&id,&quiz[0],&quiz[1],&quiz[2],&quiz[3],&quiz[4],&score[0],&score[1],&score[2]);
		name = tname;
		sort(quiz,quiz+5);
		double quizAvg = (quiz[1]+quiz[2]+quiz[3]+quiz[4])/4.0;
		double average = quizAvg*2+score[0]*.2+score[1]*.2+score[2]*.4;
		Student temp;
		char grade;
		if(average>=90){
			grade = 'A';
		}
		else if(average>=80){
			grade = 'B';
		}
		else if(average>=70){
			grade = 'C';
		}
		else if(average>=60){
			grade = 'D';
		}
		else
			grade = 'F';
		temp.setName(name);
		temp.setID(id);
		temp.setAverage(average);
		temp.setGrade(grade);
		course.push_back(temp);
	}
	sort(course.begin(),course.end(),tempAvg);
	course[0].setRank(1);
	for(int i=1;i<course.size();i++){
		if(course[i].getAverage()==course[i-1].getAverage()){
			course[i].setRank(course[i-1].getRank());
		}
		else{
			course[i].setRank(i+1);
		}
	}
	while(1){
    cout << "\n\n";
		printDash(50);
		cout<<"  Course Report Options"<<endl;
		printDash(50);
		cout<<"  1. Print in numerical average order\n";
		cout<<"  2. Print in first name order\n";
		cout<<"  3. Print course satistics\n";
		cout<<"  4. Record Finder\n";
		cout<<"  Choose any other option to quit.\n";
		printDash(50);
		char ch;
		cout<<"  Selection: ";
		cin>>ch;
		printDash(50);
		switch(ch){
			case '1':
				printAvg(course);
				break;
			case '2':
				printName(course);
				break;
			case '3':
				printStat(course);
				break;
			case '4':
				recordFind(course);
				break;
			default:
				cout<<"  Done.\n";
				exit(0);
		}
	}
	return 0;
}
/* Enter an input file: proj1_test_case.txt


--------------------------------------------------
  Course Report Options
--------------------------------------------------
  1. Print in numerical average order
  2. Print in first name order
  3. Print course satistics
  4. Record Finder
  Choose any other option to quit.
--------------------------------------------------
  Selection: 1
--------------------------------------------------
--------------------------------------------------
  Course Report: Numerical Average Order
--------------------------------------------------
  Ana      2000 - 100.00 (A) (rank: 1)
  Sarah    1000 -  88.05 (B) (rank: 2)
  Ana      1500 -  80.00 (B) (rank: 3)
  Lee      3000 -  80.00 (B) (rank: 3)
  Diego    2500 -  50.00 (F) (rank: 5)
--------------------------------------------------


--------------------------------------------------
  Course Report Options
--------------------------------------------------
  1. Print in numerical average order
  2. Print in first name order
  3. Print course satistics
  4. Record Finder
  Choose any other option to quit.
--------------------------------------------------
  Selection: 2
--------------------------------------------------
--------------------------------------------------
  Course Report: First Name Order
--------------------------------------------------
  Ana     1500 -  80.00 (B) (rank: 3)
  Ana     2000 - 100.00 (A) (rank: 1)
  Diego   2500 -  50.00 (F) (rank: 5)
  Lee     3000 -  80.00 (B) (rank: 3)
  Sarah   1000 -  88.05 (B) (rank: 2)
--------------------------------------------------


--------------------------------------------------
  Course Report Options
--------------------------------------------------
  1. Print in numerical average order
  2. Print in first name order
  3. Print course satistics
  4. Record Finder
  Choose any other option to quit.
--------------------------------------------------
  Selection: 3
--------------------------------------------------
--------------------------------------------------
  Statistics
--------------------------------------------------
  Number of students: 5
  Class Average: 79.61
  Grade Distribution (histogram)

  A * 
  B * * * 
  C 
  D 
  F * 
--------------------------------------------------


--------------------------------------------------
  Course Report Options
--------------------------------------------------
  1. Print in numerical average order
  2. Print in first name order
  3. Print course satistics
  4. Record Finder
  Choose any other option to quit.
--------------------------------------------------
  Selection: 4
--------------------------------------------------
--------------------------------------------------
  Record Finder: Enter the name of a student: Ana
  Name: Ana
  ID: 2000
  Average: 100 (A)

  Name: Ana
  ID: 1500
  Average: 80 (B)



--------------------------------------------------
  Course Report Options
--------------------------------------------------
  1. Print in numerical average order
  2. Print in first name order
  3. Print course satistics
  4. Record Finder
  Choose any other option to quit.
--------------------------------------------------
  Selection: 5
--------------------------------------------------
  Done.*/