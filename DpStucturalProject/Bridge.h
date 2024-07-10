#pragma once
#include <iostream>

class ILogger
{
public:
	virtual void Log(std::string message) = 0;
};

class ThreadContext
{
protected:
	ILogger* logger;
public:
	ThreadContext(ILogger* logger) : logger{ logger } {}

	virtual void ThreadLog(std::string message) = 0;
};

class ConsoleLogger : public ILogger
{
public:
	void Log(std::string message) override
	{
		std::cout << "Message log: " << message << " to console\n";
	}
};

class FileLogger : public ILogger
{
	std::string fileName;
public:
	FileLogger(std::string fileName) : fileName{ fileName } {}
	void Log(std::string message) override
	{
		std::cout << "Message log: " << message << " to file " << fileName << "\n";
	}
};

class SocketLogger : public ILogger
{
	std::string domain;
	int port;
public:
	SocketLogger(std::string domain, int port) 
		: domain{ domain }, port{ port } {}

	void Log(std::string message) override
	{
		std::cout << "Message log: " << message 
				<< " to server " << domain << ":" << port << "\n";
	}
};



class SingleThread : public ThreadContext
{
public:
	SingleThread(ILogger* logger)
		: ThreadContext(logger) {};

	void ThreadLog(std::string message) override
	{
		std::cout << "data read before...\n";
		logger->Log(message);
		std::cout << "woring after...\n";
	}
};

class MultyThread : public ThreadContext
{
	std::string mutex = "main mutex";
public:
	MultyThread(ILogger* logger)
		: ThreadContext(logger) {};

	void ThreadLog(std::string message) override
	{
		std::cout << "thread lock with mutex " << mutex << "\n";

		std::cout << "data read before...\n";
		logger->Log(message);
		std::cout << "woring after...\n";

		std::cout << "thread unlock\n";
	}
};