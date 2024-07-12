#pragma once
#include "Adapter.h"
#include "Bridge.h"
#include "Composite.h"
#include "Decorator.h"
#include "Facade.h"
#include "Flyweight.h"

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

    static void Composite()
    {
		IGift* teddy = new SingleGift("Teddy", 100);
		IGift* piggy = new SingleGift("Piggy", 80);
		IGift* ball = new SingleGift("Ball", 230);
		IGift* puppet = new SingleGift("Puppet", 170);
		IGift* darts = new SingleGift("Darts", 320);

		BoxGift* box1 = new BoxGift("Box1");
		box1->AddGift(teddy);
		box1->AddGift(ball);
		BoxGift* box2 = new BoxGift("Box2");
		box2->AddGift(piggy);
		box2->AddGift(darts);
		box2->AddGift(teddy);

		BoxGift* boxMain = new BoxGift("Box Main");
		boxMain->AddGift(box1);
		boxMain->AddGift(puppet);
		boxMain->AddGift(box2);

		/*std::cout << boxMain->Price() << "\n";
		std::cout << box1->Price() << "\n";
		std::cout << puppet->Price() << "\n";*/

		boxMain->Name();
		std::cout << "\n==========\n";
		box1->Name();
		std::cout << "\n==========\n";
		puppet->Name();
		std::cout << "\n==========\n";
    }

	static void Decorator()
	{
		IMessage* messageWathup = new BaseMessage();
		messageWathup->From() = "@Bobby";
		messageWathup->To() = "@Tommy";
		messageWathup->Text() = "Hello Bobby. It's Tommy!";

		messageWathup->Send();
		std::cout << "\n";

		IMessage* messageWathupFile = new FileMessage(messageWathup, "file.txt");
		messageWathupFile->Send();
		std::cout << "\n";

		IMessage* messageWathupContact = new ContactMessage(messageWathup, "Sammy +7 999 123-45-67");
		messageWathupContact->Send();
		std::cout << "\n";

		messageWathupContact = new MessangerMessage(messageWathupContact, "8-)");
		messageWathupContact->Send();
		std::cout << "\n";
	}

	static void Facade()
	{
		VisualStudioFacade* vs = new VisualStudioFacade(
			new TextEditor(),
			new Compiller(),
			new Debugger(),
			new RunTime());

		vs->Start();
	}

	static void Flyweight()
	{
		int x = 10;
		int y = 5;

		HouseFactory* factory = new HouseFactory();
		for (int i = 0; i < 10; i++)
		{
			House* house = factory->GetHouse("panel");
			if (house)
				house->Build(x, y);
			x += 2;
			y += 1;
		}

		for (int i = 0; i < 10; i++)
		{
			House* house = factory->GetHouse("brick");
			if (house)
				house->Build(x, y);
			x += 3;
			y += 2;
		}
	}
};

