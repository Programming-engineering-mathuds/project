#include <Windows.h>
#include <string>
#include <stdio.h>

using namespace std;

class CheckList
{
	string bName;
	int curY;
	bool pressed;
	bool active;
public:
	CheckList(string name, short place);
	void coordinator(COORD& cur, string upDown);
	void checkSwitch(COORD cur);
	bool isActive();
	int getPlace();
	bool getSwitchState();
	string getName();
	void setActive(COORD cur);
	void setActiveTrue(COORD& cur);
	void setActiveFalse(COORD cur);
	void printMyList(COORD cur);

	~CheckList();
};

