
#include <iostream>
#include <string>

#include "scenemanager.h";

struct GAMEMANAGER
{
	bool ISRUNNING = true;
} GAMEMANAGER;

std::vector<Scene*> scenelist;
Scenemanager SCENEMANAGER;


int main()
{
	Menu menu = Menu();
	scenelist = std::vector<Scene*>();
	scenelist.push_back(&menu);
	SCENEMANAGER = Scenemanager(scenelist);



	while (GAMEMANAGER.ISRUNNING)
	{
		SCENEMANAGER.LOADSCENE();
		GAMEMANAGER.ISRUNNING = false;
	}
	return 0;
}