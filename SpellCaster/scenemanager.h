#pragma once

#include <iostream>
#include <vector>

class Scene
{
public:
	virtual void load()
	{
		std::cout << "BaseScene" << std::endl;
		return;
	}
};

class Menu : public Scene
{
public:
	void load() override
	{
		std::cout << "MENU" << std::endl;
		return;
	}
};

class Scenemanager
{
private:
	struct SM_Empty_Scene_List_EXCEPTION : public std::exception
	{
		const char* what() const throw ()
		{
			return "Given Scene List Is Empty.\nPlease Insert One Scene Before Loading Scene Manager.";
		}
	};

	struct SM_Invalid_Current_Scene_EXCEPTION : public std::exception
	{
		const char* what() const throw ()
		{
			return "Current Scene is invalid. Unknown Scene Information Present.";
		}
	};

public:
	std::vector<Scene*> scenelist = std::vector<Scene*>();
	Scene currentscene;

	Scenemanager() { return; }
	Scenemanager(std::vector<Scene*>pScenelist)
	{
		// Error Check
		if (pScenelist.size() < 1) throw SM_Empty_Scene_List_EXCEPTION();


		this->scenelist    = pScenelist;
		this->currentscene = *this->scenelist.at(0);
		return;
	}

	void LOADSCENE()
	{
		try { this->currentscene.load(); }
		catch (SM_Invalid_Current_Scene_EXCEPTION SMICSE)
		{ this->currentscene = *this->scenelist.at(0); }
	}
};