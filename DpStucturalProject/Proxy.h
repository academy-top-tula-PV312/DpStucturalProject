#pragma once
#include <iostream>
#include <thread>

class IMath
{
public:
	virtual double add(double, double) = 0;
	virtual double sub(double, double) = 0;
	virtual double mul(double, double) = 0;
	virtual double div(double, double) = 0;

	virtual ~IMath() = default;
};

class MathServer : public IMath // Real object
{
public:
	MathServer()
	{
		using namespace std::chrono_literals;

		std::cout << "Connect at math server...\n";
		std::this_thread::sleep_for(3000ms);
	}

	double add(double a, double b) override
	{
		return a + b;
	}
	double sub(double a, double b) override
	{
		return a - b;
	}
	double mul(double a, double b) override
	{
		return a * b;
	}
	double div(double a, double b) override
	{
		return a / b;
	}
};

class MathProxy : public IMath
{
public:
	double add(double a, double b) override
	{
		MathServer server;
		return server.add(a, b);
	}
	double sub(double a, double b) override
	{
		MathServer server;
		return server.sub(a, b);
	}
	double mul(double a, double b) override
	{
		return a * b;
	}
	double div(double a, double b) override
	{
		return a / b;
	}
};

