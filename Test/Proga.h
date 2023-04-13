#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <list>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <map>
#include "Menu.h"

using namespace std;

class Test
{
public:
	//Test* test = nullptr;
	//string marks;

	vector<string> category, key, tests, questions; // у класса теста будут параметры  категория ключь название теста 
	map<string, int> answers; // Вопросы 
	int points = 0; // Баллы за прохождение 

	void loadTest();
	void saveTest();


	void addTest();
	void addTestToRazdel();
	void delTest();

	void takeTheTest();
	void continueTest();

	void statistics();



	//
};

void Test::loadTest()
{
	//ifstream in("Question.txt");
	ifstream in("Hz.txt");
	//out.open();
	//out.open("Hz.txt");
	//list<string> category, key, tests, questions; // у класса теста будут параметры  категория ключь название теста
	//map<string, int> answers; // Вопросы
	//int points = 0;
	string tempCategory; // Переменные для того чтобы у нас была возможность спросить что записывать
	string tempKey;
	string tempTest;
	string tempQuestions;
	string tempAnswers;
	string tempAnswersOnQuestions;
	string howWrite;
	string pints;
	int answerPoint = 0;
	auto itC = category;
	auto itK = key;
	auto itT = tests;
	auto itA = answers;

	//itA.find("2 4 5 1");
	//cout << itA << endl;

	if (in.is_open()) {

		while (!in.eof())
		{
			getline(in, howWrite);
			//getline(in, pints);
			if (howWrite == "-") {
				//getline(in, pints);
				getline(in, tempCategory);
				category.push_back(tempCategory);
				getline(in, tempKey);
				key.push_back(tempKey);
				getline(in, tempTest);
				tests.push_back(tempTest);

				while (tempQuestions != "+")
				{
					getline(in, tempQuestions);
					questions.push_back(tempQuestions);
					
					getline(in, tempAnswers);
					

					getline(in, tempAnswersOnQuestions);
					answerPoint = atoi(tempAnswersOnQuestions.c_str());

					answers[tempAnswers] = answerPoint;
					
					break;
				}
			}
			else if (howWrite == "+") {
				while (true)
				{
					getline(in, tempQuestions);
					questions.push_back(tempQuestions);
					getline(in, tempAnswers);

					getline(in, tempAnswersOnQuestions);
					answerPoint = atoi(tempAnswersOnQuestions.c_str());
					answers[tempAnswers] = answerPoint;

					break;

				}
			}
			else if (howWrite == "+-") {
				while (true)
				{
					getline(in, tempTest);
					tests.push_back(tempTest);
					getline(in, tempQuestions);

					questions.push_back(tempQuestions);
					
					getline(in, tempAnswers);

					getline(in, tempAnswersOnQuestions);
					answerPoint = atoi(tempAnswersOnQuestions.c_str());

					answers[tempAnswers] = answerPoint;

					break;

				}
			}
		}
	}
	else {
		cout << "Файл поврежден чтение прерванно" << endl;
	}

	/*for (auto it : category)
	{
		cout << it << endl;
	}
	for (auto it : key)
	{
		cout << it << endl;
	}
	for (auto it : tests)
	{
		cout << it << endl;
	}*/
	in.close();

}

void Test::saveTest()
{
	ofstream out("Hz.txt", ofstream::app);

	for (auto it : category)
	{
		out << it << endl;
	}
	for (auto it : key)
	{
		out << it << endl;
	}
	for (auto it : tests)
	{
		out << it << endl;
	}

	out.close();

	

}

void Test::addTest() {
	
	ofstream out("Hz.txt", ofstream::app);

	string tempCategory; // Переменные для того чтобы у нас была возможность спросить что записывать
	string tempKey;
	string tempTest;
	int answer = 0;
	//list<string> an;
	cout << "" << endl;


	out << "-" << endl;
	cout << right << setw(34) << "Enter category" << endl;
	cin >> tempCategory;
	category.push_back(tempCategory);
	out << category.back() << "\n";

	cout << "Enter Key" << endl;
	cin >> tempKey;
	key.push_back(tempKey);
	out << key.back() << "\n";

	cout << "Enter Test" << endl;
	cin >> tempTest;
	tests.push_back(tempTest);
	out << tests.back() << "\n";
	
	cout << "Enter Questions\n" << setw(34) <<"View questions\n" 
		 << "\t\tQuestions :: 4 + 4\n" << "\t\tAnswers :: 2 4 5 1\n" << "\t\tCorrect answer index number :: 2" << endl;

	cin.ignore();
	string q, a;
	getline(cin, q);
	//cin >> q;
	//an.push_back(q);
	//cin >> a;
	getline(cin, a);
	//an.push_back(a);
	
	out << q << endl;

	cin >> answer;
	answers[a] = answer;

	for (auto it : answers)
	{
		cout << it.first << ": " << it.second << endl;
		out << it.first << endl << it.second;
	}

	/*an.push_back("fdaf");

	auto it = an.begin();

	cout << *it << endl;*/

	//getline(questions);

	//auto it = 3;

    for (auto it : key)
	{
		cout << it << endl;
	}

	out.close();
	

	
}

void Test::addTestToRazdel()
{
	ofstream out("Hz.txt", ofstream::app);
	string tempKey = "keyochic";
	string tempTest;
	this->takeTheTest();
	cout << "\n===================\n" << endl;

	int i = 0;
	for (auto it = key.begin(); it != key.end(); it++, i++)
	{
		cout << i << " - " << *it << " ";
	}
	//cin >> i;
	//i = 0;
	//auto it = key.fi
	
	//auto it = find(key.begin(), key.end(), tempKey);
	//cout << *it << endl;
	
}

void Test::delTest()
{
	cout << "-----------=-=" << endl;
	this->addTest();
	//this->addTest();
}

void Test::takeTheTest()
{
	ifstream in("Question.txt");
	//ifstream in("Hz.txt");
	//out.open();
	//out.open("Hz.txt");
	//list<string> category, key, tests, questions; // у класса теста будут параметры  категория ключь название теста
	//map<string, int> answers; // Вопросы
	//int points = 0;
	string tempCategory; // Переменные для того чтобы у нас была возможность спросить что записывать
	string tempKey;
	string tempTest;
	string tempQuestions;
	string tempAnswers;
	string tempAnswersOnQuestions;
	string howWrite;
	string pints;
	int answerPoint = 0;
	auto itC = category;
	auto itK = key;
	auto itT = tests;
	auto itA = answers;
    
	//itA.find("2 4 5 1");
	//cout << itA << endl;

	if (in.is_open()) {

		while (!in.eof())
		{
			getline(in, howWrite);
			//getline(in, pints);
			if (howWrite == "-") {
				//getline(in, pints);
				getline(in, tempCategory);
				category.push_back(tempCategory);
				getline(in, tempKey);
				key.push_back(tempKey);
				getline(in, tempTest);
				tests.push_back(tempTest);
				for (auto it : category)
				{
					cout << "category :: " << it << endl;
				}
				for (auto it : key)
				{
					cout << "key :: " << it << endl;
				}
				for (auto it : tests)
				{
					cout << "tests ::" << it << endl;
				}
				while (tempQuestions != "+")
				{
					getline(in, tempQuestions);
					questions.push_back(tempQuestions);
					for (auto it : questions)
					{
						cout << "Voprosu " << it << endl;
					}
					getline(in, tempAnswers);
					/*string s;
					int i = atoi(s.c_str());*/

					getline(in, tempAnswersOnQuestions);
					answerPoint = atoi(tempAnswersOnQuestions.c_str());
					
					answers[tempAnswers] = answerPoint;

					for (auto itA : answers)
					{
						cout << " otvetu ::" << endl;
						cout << itA.first << "\n" << itA.second << endl;
					}
					//i++;
					break;
					//itA.begin(tempAnswers);
					//itA.emplace(tempAnswers);
				//}
				}
			}
			else if (howWrite == "+") {
				while (true)
				{
					getline(in, tempQuestions);
					questions.push_back(tempQuestions);
					for (auto it : questions)
					{
						cout << "Voprosu " << it << endl;
					}
					getline(in, tempAnswers);

					getline(in, tempAnswersOnQuestions);
					answerPoint = atoi(tempAnswersOnQuestions.c_str());
					answers[tempAnswers] = answerPoint;

					break;
					
				}
			}
			else if (howWrite == "+-") {
				while (true)
				{
					getline(in, tempTest);
					tests.push_back(tempTest);
					getline(in, tempQuestions);
					
					questions.push_back(tempQuestions);
					for (auto it : questions)
					{
						cout << "Voprosu " << it << endl;
					}
					getline(in, tempAnswers);
			
					getline(in, tempAnswersOnQuestions);
					answerPoint = atoi(tempAnswersOnQuestions.c_str());
					
					answers[tempAnswers] = answerPoint;

					break;
					
				}
			}
			//else {
			//	getline(in, tempQuestions);
			//	/*if (tempQuestions == "-") {
			//		getline(in, pints);
			//		cout << pints << endl;
			//		i++;
			//		break;
			//	}*/
			//	/*else {*/
			//	questions.push_back(tempQuestions);
			//	for (auto it : questions)
			//	{
			//		cout << "Voprosu" << it << endl;
			//	}
			//	getline(in, tempAnswers);
			//	/*string s;
			//	int i = atoi(s.c_str());*/

			//	getline(in, tempAnswersOnQuestions);
			//	answerPoint = atoi(tempAnswersOnQuestions.c_str());
			//	//cout << answerPoint << endl;
			//	//break;
			//	answers[tempAnswers] = answerPoint;

			//	for (auto itA : answers)
			//	{
			//		cout << " otvetu ::" << endl;
			//		cout << itA.first << "\n" << itA.second << endl;
			//	}
			//	//i++;
			//	break;
			//}
			//	getline(in, tempCategory);
			//	category.push_back(tempCategory);
			//	getline(in, tempKey);
			//	key.push_back(tempKey);
			//	getline(in, tempTest);
			//	tests.push_back(tempTest);
			//	for (auto it : category)
			//	{
			//		cout << "category :: " << it << endl;
			//	}
			//	for (auto it : key)
			//	{
			//		cout << "key :: " << it << endl;
			//	}
			//	for (auto it : tests)
			//	{
			//		cout << "tests ::" << it << endl;
			//	}
			//	int i = 0;
			//	while (i < 5)
			//	{
			//		getline(in, tempQuestions);
			//		if (tempQuestions == "-") {
			//			getline(in, pints);
			//			cout << pints << endl;
			//			i++;
			//			break;
			//		}
			//		else {
			//			questions.push_back(tempQuestions);
			//			for (auto it : questions)
			//			{
			//				cout << "Voprosu" << it << endl;
			//			}
			//			getline(in, tempAnswers);
			//			/*string s;
			//			int i = atoi(s.c_str());*/

			//			getline(in, tempAnswersOnQuestions);
			//			answerPoint = atoi(tempAnswersOnQuestions.c_str());
			//			//cout << answerPoint << endl;
			//			//break;
			//			answers[tempAnswers] = answerPoint;

			//			for (auto itA : answers)
			//			{
			//				cout << " otvetu ::" << endl;
			//				cout << itA.first << "\n" << itA.second << endl;
			//			}
			//			i++;
			//			//break;
			//			//itA.begin(tempAnswers);
			//			//itA.emplace(tempAnswers);
			//		}
			//	}
			//}



			/*string str;
			while (!fs.eof())
			{
				string line;
				getline(fs, line);
				str += line + "\n";
			}*/
		}
	}
	else {
		cout << "Файл поврежден чтение прерванно" << endl;
	}

	//if (fs.fail()) //îòêðûëñÿ ëè ôàéë
	//{
	//	cout << "Error opening file!\a";
	//	return 404;
	//}

	
	//cout << tempCategory << endl;

	/*for (auto it : category)
	{
		cout << it << endl;
	}
	for (auto it : key)
	{
		cout << it << endl;
	}
	for (auto it : tests)
	{
		cout << it << endl;
	}*/
	in.close();

}

void Test::continueTest()
{
	//fstream

	//int choice = 
	vector<string> icategory;
	auto itu = category;

	

	for (auto it : category)
	{
		cout << "Categories available : " << it << endl;
		icategory.push_back(it);
	}
	int choice = Menu::select_vertical(
		{ icategory },
		HorizontalAlignment::Center);

	for (size_t i = 0; i < category.size(); i++)
	{
		cout << category[i] << endl;
	}

	/*for (auto it : key)
	{
		cout << it << endl;
	}
	for (auto it : tests)
	{
		cout << it << endl;
	}
	for (auto it : questions)
	{
		cout << it << endl;
	}*/
	for (auto it : answers)
	{
		//string int
		cout << it.first << endl;
		int i = 0;
		//cin >> i;
		if (i == it.second) { cout << "WIN" << endl; }
	}
}

void Test::statistics()
{
	if (tests.size() != 0)
	{
		for (auto it : tests)
		{
			cout << it << " dads " << points << endl;
		}
	}
}





//void add(string name_test, string name_file_answer);
//void go_test(string name_test, string my_answer);
//void result(string name_user, string name_faile_answer, string my_answer);
//string get_name_answer(string name_test);
//void files(string name_file);
//void file_category_tests(string categort);
//bool exam_base(string base, string str);
//bool exam_category(string category, string str);

//void menegment_user();// управління користувачами
//void add_user();//додати користувача
//void delete_user();// відалити користувача
//void user_modification();// изменить параметрі пользователя

//void statistic();//статистика
//void statistic_categories();//по ктегории
//void statistic_test();// по тесту
//void statistic_user();//по пользователю
//void statistic_output_fille();//загрузить статистику в файл

//void menegment_tests();// управление тестами
//void add();
//void del();
//void add_test();// добавить тест
//void delete_test();
//void add_category();//  категорию
//void delete_category();
//void add_questions();//добавить вопросс
//void delete_questions();
//void inport_txt();// импортировать из файла
//void export_txt();// експортировать в файл