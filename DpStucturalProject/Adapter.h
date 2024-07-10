#pragma once
#include <iostream>
#include <string>


class IReturnData
{
public:
	virtual std::string ReturnData(std::string name, int age) = 0;
};


class ReturnXml : public IReturnData
{
public:
	std::string ReturnData(std::string name, int age) override
	{
		return "<name>" + name
			+ "</name><age>"
			+ std::to_string(age)
			+ "</age>";
	}
};


class Client
{
	IReturnData* returnData;
public:
	Client(IReturnData* returnData) : returnData{ returnData } {}

	void ClientMethod(std::string name, int age)
	{
		std::string data = returnData->ReturnData(name, age);
		
		int index = data.find('>');
		int count = data.find('<', index + 1) - index - 1;
		std::string nameData = data.substr(index + 1, count);

		std::cout << nameData << "\n";
	}
};


class ReturnJson
{
public:
	std::string ReturnJsonData(std::string name, int age, bool format)
	{
		return "{name:" + name + ", age:" + std::to_string(age) + "}";
	}
};

class ReturnJsonToXmlAdapter : public IReturnData
{
	ReturnJson* returnJson;
public:
	ReturnJsonToXmlAdapter(ReturnJson* returnJson)
		: returnJson{ returnJson } {}

	std::string ReturnData(std::string name, int age) override
	{
		std::string dataJson = returnJson->ReturnJsonData(name, age, false);

		int index = dataJson.find(":") + 1;
		int count = dataJson.find(",") - index;
		std::string nameJson = dataJson.substr(index, count);

		index = dataJson.find(":", index + count) + 1;
		count = dataJson.find("}") - index;
		std::string ageJson = dataJson.substr(index, count);

		return "<name>" + nameJson
			+ "</name><age>" + ageJson
			+ "</age>";
	}
};


