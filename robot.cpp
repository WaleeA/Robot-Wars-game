#include "robot.h"

Robot::Robot()
{
	this->id = 0;
	pos.x = 0;
	pos.y = 0;
	face = NORTH;
	this->team = 0;
	steps = 0;
}

void Robot::setPosition(int y, int x)
{
	pos.x = x;
	pos.y = y;
}

void Robot::setID(int id)
{
	this->id = id;
}

void Robot::setTeam(int id)
{
	this->team = id;
}

void Robot::setFace(Face face)
{
	this->face = face;
}
Position Robot::getPosition()
{
	return pos;
}

int Robot::getID()
{
	return id;
}

int Robot::getTeam()
{
	return team;
}

Face Robot::getFace()
{
	return face;
}

int Robot::getSteps()
{
	return steps;
}

void Robot::turnLeft()
{
	switch (face)
	{
	case NORTH:
		face = WEST;
		break;
	case SOUTH:
		face = EAST;
		break;
	case EAST:
		face = NORTH;
		break;
	case WEST:
		face = SOUTH;
		break;
	default:
		break;
	}
}

void Robot::turnRight()
{
	switch (face)
	{
	case NORTH:
		face = EAST;
		break;
	case SOUTH:
		face = WEST;
		break;
	case EAST:
		face = SOUTH;
		break;
	case WEST:
		face = NORTH;
		break;
	default:
		break;
	}
}

void Robot::move()
{
	switch (face)
	{
	case NORTH:
		pos.y += 1;
		break;
	case SOUTH:
		pos.y -= 1;
		break;
	case EAST:
		pos.x += 1;
		break;
	case WEST:
		pos.x -= 1;
		break;
	default:
		break;
	}
	steps++;
}