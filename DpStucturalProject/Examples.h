#pragma once
#include "Adapter.h"
#include "Bridge.h"

class Examples
{
public:
	static void Adapter()
	{
        ReturnXml* returnXml = new ReturnXml();
        ReturnJson* returnJson = new ReturnJson();
        ReturnJsonToXmlAdapter* adapter = new ReturnJsonToXmlAdapter(returnJson);

        std::cout << returnXml->ReturnData("Bobby", 25) << "\n";
        std::cout << returnJson->ReturnJsonData("Bobby", 25, true) << "\n";
        std::cout << adapter->ReturnData("Bobby", 25) << "\n";

        Client client(adapter);

        client.ClientMethod("Bobby", 25);
	}

    static void Bridge()
    {
        ILogger* logger = new FileLogger("data.log");
        ThreadContext* context = new MultyThread(logger);
        context->ThreadLog("Error into context");

        std::cout << "\n";

        context = new MultyThread(new SocketLogger("dataserver", 3000));
        context->ThreadLog("No Error into context");
    }
};

