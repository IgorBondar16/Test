#include<iostream>

#include"Proga.h"

using namespace std;

int main()
{
	cout << "0/Creaty 1/Del 2/TakeTest 3/Continue 4/Statistics" << endl;
	Test t; 
	//t.addTest();
	//t.addTestToRazdel();
	//t.takeTheTest();
	t.loadTest();
	t.saveTest();
	cout << "\n===================" << endl;

	//t.statistics();


	return 0;
}


//#include <iostream>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <Windows.h>
//
//using namespace std;
//
//int main()
//{
//    string filename = "test.txt";
//    string filenameEngl = "testEngl.txt";
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    fstream fs("test.txt"); //??? ?????? 
//    ofstream out; // ??? ??????
//
//    fs.open();
//
//    if (fs.fail()) //открылся ли файл
//    {
//        cout << "Error opening file!\a";
//        return 404;
//    }
//
//    string str;
//    while (!fs.eof())
//    {
//        string line;
//        getline(fs, line);
//        str += line + "\n";
//    }
//    cout << str << endl;
//
//    fs.open(filename);
//
//    char abcRu[26]{ 'А', 'Б', 'Ц', 'Д', 'И', 'Ф', 'Ж', 'Х', 'Й', 'Ш', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Ю', 'Р', 'С', 'Т', 'У', 'В', 'Ч', 'P', 'Ай', 'З' };
//    char abcENGL[26]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
//    char abcRuSm[26]{ 'а', 'б', 'ц', 'д', 'и', 'ф', 'ж', 'х', 'й', 'ш', 'к', 'л', 'м', 'н', 'о', 'п', 'ю', 'Р', 'с', 'т', 'у', 'в', 'ч', 'P', 'Ай', 'з' };
//    char abcEngl[26]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
//
//    //a b c d e f g h i j k l m n o p q r s t u v w x y z
//    //A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
//    //А Б Ц Д И Ф Ж Х Й ДЖ К Л М Н О П Ю Р С Т У В Ч З Ай З
//
//    for (int i = 0; i < str.length(); i++)
//        for (int j = 0; j < 26; j++)
//            if (str[i] == abcRu[j]) {
//                str[i] = abcENGL[j];
//                break;
//            }
//            else if (str[i] == abcRuSm[j]) {
//                str[i] = abcEngl[j];
//                break;
//            }
//
//    cout << str << endl;
//    fs.close();
//
//    out.open(filenameEngl, ofstream::app);
//
//    out << str;
//
//    out.close();
//
//    system("pause");
//    return 0;
//}
