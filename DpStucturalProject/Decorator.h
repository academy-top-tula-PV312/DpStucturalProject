#pragma once
#include <iostream>

class IMessage
{
protected:
	std::string from;
	std::string to;
	std::string text;
public:
	std::string& From() { return from; }
	std::string& To() { return to; }
	std::string& Text() { return text; }

	virtual void Send() = 0;
};

class BaseMessage : public IMessage
{
public:
	void Send()
	{
		std::cout << "Messanger send from: " << from
			<< "\nto: " << to
			<< "\ntext: " << text << "\n";
	}
};


class IMessageDecorator : public IMessage
{
protected:
	IMessage* message;
public:
	IMessageDecorator(IMessage* message) : message{message} {}
};


class MessangerMessage : public IMessageDecorator
{
	std::string sticker;
public:
	MessangerMessage(IMessage* message, std::string sticker = ":-)")
		: IMessageDecorator(message),
		sticker{ sticker } {}

	std::string& Sticker() { return sticker; }

	void Send() override
	{
		message->Send();
		std::cout << "\nsticker: " << sticker << "\n";
	}
};



class EmailMessage : public IMessageDecorator
{
	std::string subject;
public:
	EmailMessage(IMessage* message, std::string subject = "")
		: IMessageDecorator(message),
		subject{ subject } {}

	std::string& Subject() { return subject; }

	void Send() override
	{
		message->Send();
		std::cout << "\nsubject: " << subject << "\n";
	}
};

class FileMessage : public IMessageDecorator
{
	std::string fileName;
public:
	FileMessage(IMessage* message, std::string fileName = "")
		: IMessageDecorator(message),
		fileName{ fileName } {}

	std::string& FileName() { return fileName; }

	void Send() override
	{
		message->Send();
		std::cout << "\naccept file: " << fileName << "\n";
	}
};

class ContactMessage : public IMessageDecorator
{
	std::string contact;
public:
	ContactMessage(IMessage* message, std::string contact = "")
		: IMessageDecorator(message),
		contact{ contact } {}

	std::string& Contact() { return contact; }

	void Send() override
	{
		message->Send();
		std::cout << "\nwith contact: " << contact << "\n";
	}
};
