#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student
{
	private:
		string name;
		int id, rank;
		double average;
		char grade;
	public:
		Student();
		void setName(string name);
		void setID(int id);
		void setAverage(double average);
		void setGrade(char grade);
		void setRank(int rank);
		string getName();
		int getID();
		double getAverage();
		char getGrade();
		int getRank();
		void print();
};

#endif
