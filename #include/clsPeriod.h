#pragma once

#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <ctime>
#include "clsDate.h"

class clsPeriod
{

public:


	clsDate StartDate;
	clsDate EndDate;


	clsPeriod()
	{

		time_t t = time(0); // get time now
		tm* now = localtime(&t);

		StartDate.Year = now->tm_year + 1900;
		StartDate.Month = now->tm_mon + 1;
		StartDate.Day = now->tm_mday;

		EndDate.Year = now->tm_year + 1900;
		EndDate.Month = now->tm_mon + 2;
		EndDate.Day = now->tm_mday;

	}

	clsPeriod(clsDate DateStart, clsDate DateEnd)
	{
		StartDate = DateStart;
		EndDate = DateEnd;
	}

	clsPeriod(string DateStart, string DateEnd)
	{
		StartDate = clsDate::StringToDate(DateStart);
		EndDate = clsDate::StringToDate(DateEnd);
	}

	clsPeriod(short DayStart, short MonthStart, short YearStart, short DayEnd, short MonthEnd, short YearEnd)
	{
		StartDate = clsDate::clsDate(DayStart, MonthStart, YearStart);
		EndDate = clsDate::clsDate(DayEnd, MonthEnd, YearEnd);
	}

	clsPeriod(short DateStartOrderInYear, short YearStart, short DateEndOrderInYear, short YearEnd)

	{
		StartDate = clsDate::clsDate(DateStartOrderInYear, YearStart);
		EndDate = clsDate::clsDate(DateEndOrderInYear, YearEnd);
	}

	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();


		cout << "Period End: ";
		EndDate.Print();

	}

	void PrintDate1()
	{
		cout << StartDate.Day << "/" << StartDate.Month << "/" << StartDate.Year << endl;
	}

	void PrintDate2()
	{
		cout << EndDate.Day << "/" << EndDate.Month << "/" << EndDate.Year << endl;
	}

	static bool IsOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		if (
			Period1.StartDate.CompareDate(Period2.EndDate, Period1.StartDate) == Period1.StartDate.eDateCompare::Before
			||
			Period1.EndDate.CompareDate(Period2.StartDate, Period1.EndDate) == Period1.EndDate.eDateCompare::After
			)
			return false;
		else
			return true;
	}
	bool IsOverlapPeriods(clsPeriod Period2)
	{
		return IsOverlapPeriods(*this, Period2);
	}

	static int PeriodLengthInDays(clsPeriod Period, bool IncludingEndDay = false)
	{
		return clsDate::GetDiffrenceInDays(Period.StartDate, Period.EndDate, IncludingEndDay);
	}
	int PeriodLengthInDays(bool IncludingEndDay = false)
	{
		return PeriodLengthInDays(*this, IncludingEndDay);
	}


	static bool IsDateInPeriod(clsDate Date, clsPeriod Period1)
	{

		return (Date.CompareDate(Date, Period1.StartDate) == Date.eDateCompare::Before
			||
			Date.CompareDate(Date, Period1.EndDate) == Date.eDateCompare::After);

	}
	bool IsDateInPeriod(clsDate Date)
	{
		return IsDateInPeriod(Date, *this);
	}

	static short CountOverlapDays(clsPeriod Period1, clsPeriod Period2)
	{
		short Period1Length = PeriodLengthInDays(Period1);
		short Period2Length = PeriodLengthInDays(Period2);
		short CountOoerlap = 0;

		if (!IsOverlapPeriods(Period1, Period2))
		{
			return 0;
		}

		if (Period1Length < Period2Length)
		{
			while (clsDate::IsDate1BeforDate2(Period1.StartDate, Period1.EndDate))
			{

				if ((IsDateInPeriod(Period1.StartDate, Period2)))
					CountOoerlap++;

				Period1.StartDate = clsDate::IncreaseDateByOneDay(Period1.StartDate);
			}
		}

		else
		{
			while (clsDate::IsDate1BeforDate2(Period2.StartDate, Period2.EndDate))
			{
				if ((IsDateInPeriod(Period2.StartDate, Period1)))
					CountOoerlap++;

				Period2.StartDate = clsDate::IncreaseDateByOneDay(Period2.StartDate);
			}
		}


		return CountOoerlap;

	}
	short CountOverlapDays(clsPeriod Period2)
	{
		return CountOverlapDays(*this, Period2);
	}

	static short MyCountOverlapDay(clsPeriod Period1, clsPeriod Period2, short IncludingEndDay = 0)
	{

		if (IsDateInPeriod(Period2.StartDate, Period1))
		{
			return clsDate::GetDiffrenceInDays(Period2.StartDate, Period1.EndDate, IncludingEndDay);

		}

		return 0;

	}
	short MyCountOverlapDay(clsPeriod Period2, short IncludingEndDay = 0)
	{
		return MyCountOverlapDay(*this, Period2, IncludingEndDay);
	}

};