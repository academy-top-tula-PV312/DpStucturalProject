#pragma once
#include <iostream>
#include <vector>

class IGift
{
protected:
	std::string name;
	int price;
public:
	IGift(std::string name = "gift")
		: name{ name }, price{} {}
	void Price(int price)
	{
		this->price = price;
	}

	virtual int Price() = 0;
	virtual void Name() = 0;
};

class SingleGift : public IGift
{
public:
	SingleGift(std::string name) : IGift(name) {}
	SingleGift(std::string name, int price) 
		: IGift(name)
	{
		this->price = price;
	}

	int Price() override
	{
		return this->price;
	}

	void Name() override
	{
		std::cout << name << "\n";
	}
};

class BoxGift : public IGift
{
	std::vector<IGift*> gifts;
public:
	BoxGift(std::string name) : IGift(name) {}
	
	void AddGift(IGift* gift)
	{
		gifts.push_back(gift);
	}

	int Price() override
	{
		int priceFull{};
		for (auto gift : gifts)
			priceFull += gift->Price();
		return priceFull;
	}

	void Name() override
	{
		std::cout << name << "\n";
		std::cout << "----------\n";
		for (auto gift : gifts)
			gift->Name();
		std::cout << "----------\n";
	}
};
