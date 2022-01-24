#include <vector>
#include <fstream>
#include "commands.h"

vector<string> readFile(string filename);
void initRobots(Robot* robots, vector<string> startinfo);
int getNumberFromString(string* robotInfo);
string& rtrim(string& str, const string& chars = "\t\n ");

int main()
{
	vector<string> startinfo = readFile("start.txt");
	Robot* robots = new Robot[startinfo.size()];
	initRobots(robots, startinfo);
	vector<string> commandsInfo = readFile("commands.txt");
	Command command(robots, startinfo.size());
	for (int i = 0; i < (int)commandsInfo.size(); i++)
		command.commandParsing(commandsInfo.at(i));
	delete[] robots;
}

vector<string> readFile(string filename)
{
	ifstream in(filename);
	string str;
	vector<string> info;
	while (getline(in, str))
		info.push_back(rtrim(str));
	in.close();
	return info;
}

void initRobots(Robot* robots, vector<string> startinfo)
{
	for (int i = 0; i < (int)startinfo.size(); i++)
	{
		string robotInfo = startinfo.at(i);
		robots[i].setID(getNumberFromString(&robotInfo));
		robots[i].setTeam(getNumberFromString(&robotInfo));
		robots[i].setPosition(getNumberFromString(&robotInfo), getNumberFromString(&robotInfo));
	}
}

int getNumberFromString(string* robotInfo)
{
	int number = stoi(robotInfo->substr(0, robotInfo->find(' ')));
	robotInfo->erase(0, robotInfo->find(' ') + 1);
	return number;
}

string& rtrim(string& str, const string& chars)
{
	str.erase(str.find_last_not_of(chars) + 1);
	return str;
}