#include "commands.h"

Command::Command(Robot* robots, int count)
{
	this->robots = robots;
	robotCount = count;
}

void Command::commandParsing(string command)
{
	int spaceIndex = command.find(' ');
	string operation;
	int number = -1;
	if (spaceIndex != -1)
	{
		operation = command.substr(0, spaceIndex);
		command.erase(0, spaceIndex + 1);
		number = stoi(command);
	}
	else
		operation = command;

	if (operation == "show")
		show();
	else if (operation == "travelled")
		travelled();
	else if (operation == "within" && number != -1)
		within(number);
	else if (operation == "turnleft" && number != -1)
		turnLeft(number);
	else if (operation == "turnright" && number != -1)
		turnRight(number);
	else if (operation == "move" && number != -1)
		move(number);
}

void Command::show()
{
	sortByID();
	for (int i = 0; i < robotCount; i++)
		cout << robots[i].getID() << " " << robots[i].getTeam() << " "
		<< robots[i].getPosition().x << " " << robots[i].getPosition().y << endl;
}
void Command::travelled()
{
	sortByID();
	sortBySteps();
	for (int i = 0; i < robotCount; i++)
		cout << robots[i].getID() << " " << robots[i].getSteps() << endl;
}
void Command::within(int range)
{
	int count = 0;
	for (int i = 0; i < robotCount; i++)
		if (abs(robots[i].getPosition().x) + abs(robots[i].getPosition().y) <= range)
			count += 1;
	cout << count << endl;
}
void Command::turnLeft(int robotNumber)
{
	int index = getIndex(robotNumber);
	if (index >= 0 && index < robotCount)
		robots[index].turnLeft();
}
void Command::turnRight(int robotNumber)
{
	int index = getIndex(robotNumber);
	if (index >= 0 && index < robotCount)
		robots[index].turnRight();
}
void Command::move(int robotNumber)
{
	int index = getIndex(robotNumber);
	if (index >= 0 && index < robotCount) {
		Position temp = robots[index].getPosition();
		switch (robots[index].getFace())
		{
		case NORTH:
			temp.y += 1;
			break;
		case SOUTH:
			temp.y -= 1;
			break;
		case EAST:
			temp.x += 1;
			break;
		case WEST:
			temp.x -= 1;
			break;
		default:
			break;
		}

		for (int i = 0; i < robotCount; i++)
		{
			if (i != index && robots[i].getTeam() == robots[index].getTeam()) {
				Position teamRobotPos = robots[i].getPosition();
				if (teamRobotPos.x == temp.x && teamRobotPos.y == temp.y)
					return;
			}
			else if (i != index && robots[i].getTeam() != robots[index].getTeam()) {
				Position teamRobotPos = robots[i].getPosition();
				if (teamRobotPos.x == temp.x && teamRobotPos.y == temp.y) {
					removeRobot(i);
					break;
				}
			}
		}
		index = getIndex(robotNumber);
		if (index >= 0 && index < robotCount)
			robots[index].move();
	}
}

void Command::removeRobot(int index)
{
	if (index >= 0 && index < robotCount)
	{
		Robot* tempRobots = new Robot[robotCount - 1];
		int temp = 0;
		for (int i = 0; i < robotCount; i++)
			if (i != index) {
				tempRobots[temp] = robots[i];
				temp++;
			}
		robotCount--;
		delete[] robots;
		robots = tempRobots;
	}
}

int Command::getIndex(int robotNumber)
{
	int index = -1;
	for (int i = 0; i < robotCount; i++)
		if (robots[i].getID() == robotNumber) {
			index = i;
			break;
		}
	return index;
}

void Command::sortByID()
{
	for (int i = 0; i < robotCount; i++)
	{
		int index = findMinID(i);
		if (index != -1 && robots[i].getID() > robots[index].getID()) {
			Robot tempRobot = robots[i];
			robots[i] = robots[index];
			robots[index] = tempRobot;
		}
	}
}

int Command::findMinID(int from)
{
	int index = -1;
	int iMin = robots[from].getID();
	for (int i = from + 1; i < robotCount; i++)
	{
		if (robots[i].getID() < iMin) {
			iMin = robots[i].getID();
			index = i;
		}
	}
	return index;
}

void Command::sortBySteps()
{
	for (int i = 0; i < robotCount; i++)
	{
		int index = findMaxSteps(i);
		if (index != -1 && robots[i].getSteps() < robots[index].getSteps()) {
			Robot tempRobot = robots[i];
			robots[i] = robots[index];
			robots[index] = tempRobot;
		}
	}
}

int Command::findMaxSteps(int from)
{
	int index = -1;
	int iMax = robots[from].getSteps();
	for (int i = from + 1; i < robotCount; i++)
	{
		if (robots[i].getSteps() > iMax) {
			iMax = robots[i].getSteps();
			index = i;
		}
	}
	return index;
}