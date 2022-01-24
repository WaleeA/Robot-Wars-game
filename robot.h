class Position
{
public: //initalising x and y co-ords in a position class
	int x;
	int y;
};

enum  Face
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Robot //created a robot class to store
{			// and initialise a few variables and their responses of commands
private:
	Position pos;
	Face face;
	int steps;
	int id;
	int team;


public: 
	Robot();
	void setID(int);
	void setPosition(int, int);
	void setTeam(int);
	void setFace(Face);

	Position getPosition();
	int getID();
	int getTeam();

	Face getFace();
	int getSteps();
	void turnRight();
	void turnLeft();
	void move();
};