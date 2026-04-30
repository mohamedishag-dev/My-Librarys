#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{
private:
	string _Value;
public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value) {
		_Value = Value;
	}

	string GetValue() {
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short CountWords(string S1)
	{
		string delim = " "; // delimiter
		short Counter = 0;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				Counter++;
			}
			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			Counter++; // it counts the last word of the string.
		}
		return Counter;
	}

	short CountWords()
	{
		return CountWords(_Value);
	};

	static char FirstLetter(string S1)
	{
		bool isFirstLetter = true;


		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				return S1[i];
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}

	}

	static char LastLetter(string S1)
	{
		bool isLastLetter = true;


		for (int i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ' && isLastLetter)
			{
				return S1[i];
			}
			isLastLetter = (S1[i] == ' ' ? true : false);
		}

	}

	static string UpperEachWords(string S1)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void UpperEachWords()
	{
		_Value = UpperEachWords(_Value);
	}

	static string LowerEachWords(string S1)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}
	void LowerEachWords()
	{
		_Value = LowerEachWords(_Value);
	}

	static string UpperAllString(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}

		return S1;
	}
	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S1)
	{

		for (int i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}

		return S1;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertLetterCase(char Char1)
	{
		return isupper(Char1) ? tolower(Char1) : toupper(Char1);
	}

	static string InvertAllStringLetterCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void InvertAllStringLetterCase()
	{
		_Value = InvertAllStringLetterCase(_Value);
	}

	static short CountCapitalLetters(string S1)
	{
		short Capital = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isupper(S1[i]))
			{
				Capital++;
			}
		}
		return Capital;
	}
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSamallLetters(string S1)
	{
		short Samall = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && islower(S1[i]))
			{
				Samall++;
			}
		}
		return Samall;
	}
	short CountSamallLetters()
	{
		return CountSamallLetters(_Value);
	}

	static short CountLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
				{
					Counter++;
				}
			}
		}
		return Counter;
	}
	short CountLetter(char Letter, bool MatchCase = true)
	{
		return CountLetter(_Value, Letter);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);
		return  ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}

	static short CountVowels(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintEachWords(string S1)
	{
		string Delim = " ";

		cout << "\nYour string words are:\n\n";
		short Pos = 0;
		string sWord;

		while ((Pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, Pos);

			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, Pos + Delim.length());
		}

		if (S1 != "")
		{
			cout << S1 << endl;
		}

	}
	void PrintEachWords()
	{
		PrintEachWords(_Value);
	}

	static vector <string> Split(string S1, string delim)
	{
		vector <string> vString;
		short pos = 0;
		string sWord; // define a string variable

		do
		{
			pos = S1.find(delim);
			sWord = S1.substr(0, pos); // store the word
			if (sWord != delim)
			{
				vString.push_back(sWord);
			}
			//erase() until positon and move to next word.
			S1.erase(0, pos + delim.length());

		} while (pos != std::string::npos);

		return vString;
	}
	vector <string> Split(string delim)
	{
		return Split(_Value, delim);
	}

	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
				return S1.substr(i, S1.length() - i);
		}

		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (short i = S1.length(); i >= 0; i++)
		{
			if (S1[i] != ' ')
				return S1.substr(0, i + 1);
		}

		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string Join(vector <string>& vString, string delim)
	{
		string S1 = ""; // define a string variable

		for (string& s : vString)
		{
			S1 += s + delim;
		}
		return S1.substr(0, S1.length() - delim.length());
	}
	static string Join(string arrString[], short length, string delim)
	{
		string S1 = ""; // define a string variable
		for (short i = 0; i < length; i++)
		{
			S1 += arrString[i] + delim;
		}

		return S1.substr(0, S1.length() - delim.length());

	}

	static string ReverseWords(string S1)
	{
		string S2 = "";
		vector <string> vString;
		vString = Split(S1, " ");

		vector <string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";

		}
		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}
	string ReverseWords()
	{
		return  ReverseWords(_Value);
	}

	static string ReplaceWords(string S1, string StringToRepace, string ReplaceTo)
	{
		short pos = S1.find(StringToRepace);
		while (pos != std::string::npos)
		{
			S1.replace(pos, StringToRepace.length(), ReplaceTo);
			pos = S1.find(StringToRepace);//find next
		}
		return S1;
	}
	void ReplaceWords(string StringToRepace, string ReplaceTo)
	{
		_Value = ReplaceWords(_Value, StringToRepace, ReplaceTo);
	}

	static string ReplaceWordsUsingJoin(string S1, string StringToRepace, string ReplaceTo, bool MatchCase = true)
	{
		vector <string>	vString = Split(S1, " ");

		for (string& S : vString)
		{
			if (MatchCase)
			{
				if (S == StringToRepace)
				{
					S = ReplaceTo;
				}
			}

			else
			{
				if (UpperAllString(S) == UpperAllString(StringToRepace))
				{
					S = ReplaceTo;

				}
			}

		}

		return Join(vString, " ");
	}
	void ReplaceWordsUsingJoin(string StringToRepace, string ReplaceTo, bool MatchCase = true)
	{
		_Value = ReplaceWordsUsingJoin(_Value, StringToRepace, ReplaceTo, MatchCase);

	}

	static string RemovePunctuations(string S1)
	{
		string sWords = "";
		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				sWords += S1[i];
			}
		}
		return sWords;
	}
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}

};