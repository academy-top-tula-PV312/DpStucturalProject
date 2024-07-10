#include <iostream>
#include "Examples.h"

#include "Composite.h"

int main()
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
