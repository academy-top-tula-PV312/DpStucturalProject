#pragma once
#include <iostream>
#include <map>

class House
{
protected:
	int stages;
	std::string image;

public:
	virtual void Build(double x, double y) = 0;
};

class PanelHouse : public House
{
public:
	PanelHouse()
	{
		stages = 9;
		image = "texture_panel.jpg";
	}

	void Build(double x, double y) override
	{
		std::cout << "Panel house build:\n"
			<< "Stages: " << stages << "\n"
			<< "Texture: " << image << "\n"
			<< "x = " << x << ", y = " << y << "\n\n";
	}
};

class BrickHouse : public House
{
public:
	BrickHouse()
	{
		stages = 5;
		image = "texture_briks.jpg";
	}

	void Build(double x, double y) override
	{
		std::cout << "Brick house build:\n"
			<< "Stages: " << stages << "\n"
			<< "Texture: " << image << "\n"
			<< "x = " << x << ", y = " << y << "\n\n";
	}
};

class HouseFactory
{
	std::map<std::string, House*> housesFW;
public:
	House* GetHouse(std::string keyProject)
	{
		if (housesFW.find(keyProject) == housesFW.end())
		{
			if (keyProject == "panel")
				housesFW.insert(std::make_pair("panel", new PanelHouse()));
			if (keyProject == "brick")
				housesFW.insert(std::make_pair("brick", new BrickHouse()));
		}
		return housesFW[keyProject];
	}
};
