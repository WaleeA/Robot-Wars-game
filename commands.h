#include <iostream>
#include <string>
#include <cmath>
#include "robot.h"
using namespace std;

class Command
{
private:
	Robot* robots;
	int robotCount;
public:
	Command(Robot*, int);
	void commandParsing(string);
	int getIndex(int);
	void removeRobot(int);
	void show();
	void travelled();
	void within(int);
	void turnLeft(int);
	void turnRight(int);
	void move(int);
	void sortByID();
	int findMinID(int);
	void sortBySteps();
	int findMaxSteps(int);
};