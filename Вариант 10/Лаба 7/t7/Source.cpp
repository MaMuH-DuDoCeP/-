#include<iostream>
#include<string>
#include <fstream>
#include <windows.h>
#include <list>

using namespace std;

string lowers = "qwertyuiopasdfghjklzxcvbnméöóêåíãøùçõúôûâàïğîëäæıÿ÷ñìèòüáş¸";
string highers = "QWERTYUIOPASDFGHJKLZXCVBNMÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏĞÎËÄÆİß×ÑÌÈÒÜÁŞ¨";
string stopSigns = "!.;";

int main()
{
	setlocale(LC_ALL, "ru");

	string str;



	ifstream fi;
	fi.open("file.dat", ios::in);
	getline(fi, str, '\0');
	fi.close();


	cout << "Òåêñò:\n'" << str << "'\n\n";

	struct Sentence
	{
		string sentence = "";
		list<string> words;
	};

	list<Sentence> sentences;

	str = " " + str + " ";
	int pos = str.find("  ");
	while (pos >= 0)
	{
		str = str.substr(0, pos) + str.substr(pos + 1);
		pos = str.find("  ");
	}
	str = str.substr(1, str.length() - 2);

	string word = "";
	Sentence s;
	for (int i = 0; i < str.length(); i++)
	{
		bool isHigher = highers.find(str[i]) != -1;
		bool isLower = lowers.find(str[i]) != -1;
		bool isStopSign = stopSigns.find(str[i]) != -1;
		
		if ((str[i] != ' ' && str[i] != '\n') || s.sentence.length() > 0)
			s.sentence += str[i];

		if (isHigher || isLower)
		{
			word += str[i];
		}
		else
		{
			if (word != "")
			{
				s.words.push_back(word);
				word = "";
			}

			if (isStopSign)
			{
				
				if (s.sentence.size() == 1 && sentences.size())
				{
					sentences.back().sentence = sentences.back().sentence + str[i];
					s.sentence = "";
					continue;
				}
				sentences.push_back(s);
				s.sentence = "";
				s.words.clear();
			}
		}
	}

	int count = sentences.size();
	cout<<"Êîë=âî ïğåäëîæåíèé: " << count << "";


	while (sentences.size())
	{
		Sentence s = sentences.front();
		sentences.pop_front();
		getchar();
		cout << "Ïğåäëîæåíèå ¹" << count - sentences.size() << ": '" << s.sentence << "'\n";
		int wCount = s.words.size();
		cout << "Êîë-âî ñëîâ: " << wCount << "";

		while (s.words.size())
		{
			string word = s.words.front();
			s.words.pop_front();
			getchar();
			cout << "  Ñëîâî ¹" << wCount - s.words.size() << ": '" << word << "'";
		}

	}

	getchar();
	getchar();

	return 0;
}
