#include "Student.h"
#include<iostream>
using namespace std;

Student::Student()
{
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setID(int id)
{
	this->id = id;
}

void Student::setAverage(double average)
{
	this->average = average;
}

void Student::setGrade(char grade)
{
	this->grade = grade;
}

void Student::setRank(int rank)
{
	this->rank = rank;
}

string Student::getName()
{
	return name;
}

int Student::getID()
{
	return id;
}

double Student::getAverage()
{
	return average;
}

char Student::getGrade()
{
	return grade;
}

int Student::getRank()
{
	return rank;
}

void Student::print()
{
	cout << "  Name: " << name << "\n  ID: " << id << "\n  Average: " << average << " " << "(" << grade << ")" << endl << endl;
}
