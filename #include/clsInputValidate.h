#pragma once

#include <iostream>   
#include <string>     
#include "clsDate.h"     
using namespace std;

class clsInputValidate
{

public:


	static bool IsNumberBetween(short Number, short From, short To)
	{
		if (Number >= From || Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (Number >= From || Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From || Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From || Number <= To)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{

		if (clsDate::CompareDate(DateFrom, DateTo) == clsDate::eDateCompare::After)
		{
			clsDate::SwapDate(DateFrom, DateTo);
		}

		return !(clsDate::CompareDate(Date, DateFrom) == clsDate::eDateCompare::Before
			||
			clsDate::CompareDate(Date, DateTo) == clsDate::eDateCompare::After);

	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		int Number;

		while (!(cin >> Number))
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDdlNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		double Number;

		while (!(cin >> Number))
		{
			// user didn't input a number
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();

		}

		return Number;
	}

	static double ReadDdlNumberBetween(double From, double To, string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		double Number = ReadDdlNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDdlNumber();

		}

		return Number;
	}

}; 