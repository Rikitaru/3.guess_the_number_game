//Напишите программу, реализующую игру «Угадай число» для четырехзначных чисел.
//Правила следующие : играют двое; один задумывает число, 
//второй – угадывает.На каждом шаге угадывающий делает предположение, 
//а задумавший число – говорит, сколько цифр числа угаданы и сколько из угаданных цифр занимают правильные позиции в числе.
//Например, если загадано число 1725 и выдвинуто предположение, что задумано число 1523, то угаданы две цифры(5 и 2) и одна из них(2) 
//занимает верную позицию.
//Загаданные числа хранятся в отдельном файле.Программа должна позволять 
//формировать новый входной текстовый файл на основании введенных пользователем данных.
//Во второй отдельный файл необходимо писать всю хронику всех игр.
//Пример вывода на экран и в выходной файл :
//ПК загадал четырехзначное число.
//Ваш вариант -> 1238 Угадано : 0. На своих местах : 0.
//Ваш вариант -> 5498 Угадано : 2. На своих местах : 1.
//****Вы Угадали!****
//Нажмите 1 для повторной игры, и 2 для выхода из программы.
#include <stdio.h>
#include <iostream>
#include <clocale>
#include <fstream>
#include <cstdlib>
using namespace std;
void main(void) {
	setlocale(LC_ALL, "Russian");
	ofstream history("Game.txt", std::ios::app);
	ofstream chislo("chislo.txt", std::ios::app);
	int flag1 = 1;
	int flag2 = 0;
	int game_number = 0; //загадываемого число
	int choice;//выбор пользователя для входных данных
	int game;
	int newgame_number;
	do {
		system("cls");
		cout << "Загадываемое число уже находится в файле Input.txt. Хотите ли ввести новое число и его использовать в следующей игре?" << endl;
		cout << "1 - Ввести новое число и перезаписать входной файл Input.txt. 2 - Использовать число, которое находится в файле." << endl;
		do {
			try
			{
				cin >> choice;
				if (!(choice == 1 || choice == 2)) {
					throw - 1;
				}
			}
			catch (int a)
			{
				// Любые исключения типа int, сгенерированные в блоке try, приведенном выше, - обрабатываются здесь
				choice = -1;
				cout << "Неправильный ввод переменной. Ошибка номер  " << a << ", повторие ввод." << endl;
			}
		} while (!(choice == 1 || choice == 2));

		if (choice == 1) {
			cout << "Введите новое четырехзначное пложительное число." << endl;
			do {
				try
				{
					cin >> game_number;
					if ((game_number > 999) && (game_number < 10000)) {
						flag1= 1;
					}
					else {
						flag1= 0;
						throw - 2;
					}
				}
				catch (int a)
				{
					cout << "Это не четырехзначное положительное число. Ошибка номер  " << a << ", повторие ввод." << endl;
				}
			} while (!flag1);
			ofstream input("Input.txt");
			input << game_number;
			input.close();
		}
		else {
			ifstream input("Input.txt");
			try
			{
				if (!(input.is_open()) || (input.peek() == EOF)) {
					throw 0;
				}   //Если файл не существует или если первый символ конец файла

			}
			catch (int a)
			{
				cout << "Вы выбрали считывание из файла, но этого файла не существует или он пустой. Поэтому будет создан этот файл снова с изначальным загадываемым числом 1111. Ошибка номер  " << a << endl;
				input.close();
				ofstream input("Input.txt");
				input << "1111" << endl;
				input.close();
				system("pause");
			}
			input >> game_number;
			input.close();
			cout << "Четырехзначное пложительное число было считано из файла ." << endl;
		}
		system("cls");
		cout << "ИГРА НАЧАЛАСЬ!!" << endl;
		flag1= 0;
		history << "Загаданное число: " << game_number << endl;
		chislo << game_number << endl;
		while (flag1!= 4) {
			flag1= 0;
			flag2 = 0;
			cout << "ПК загадал четырехзначное число." << endl;
			cout << "Ваш вариант -> ";
			do {
				try
				{
					cin >> newgame_number;
					if (newgame_number < 1000 || newgame_number > 9999) {
						throw - 3;
					}
				}
				catch (int a)
				{
					newgame_number = 999;
					cout << "Неправильный ввод переменной. Ошибка номер  " << a << ", повторие ввод." << endl;
				}
			}
			while (!(newgame_number > 999 && newgame_number < 10000));
			
			int start_value1 = game_number / 1000;
			int start_value2 = (game_number % 1000) / 100;
			int start_value3 = ((game_number % 1000) % 100) / 10;
			int start_value4 = ((game_number % 1000) % 100) % 10;

			int new_value1 = newgame_number / 1000;
			int new_value2 = (newgame_number % 1000) / 100;
			int new_value3 = ((newgame_number % 1000) % 100) / 10;
			int new_value4 = ((newgame_number % 1000) % 100) % 10;

			if (start_value1 == new_value1) {
				flag1++;
			}
			else if (((start_value1 == new_value1) &&((new_value1 != start_value2) || (new_value1 != start_value3)|| (new_value1 != start_value4)))
				|| ((start_value1 == new_value2) && ((new_value2 != start_value2) || (new_value2 != start_value3) || (new_value2 != start_value4)))
				|| ((start_value1 == new_value3) && ((new_value3 != start_value2) || (new_value3 != start_value3) || (new_value3 != start_value4)))
				|| ((start_value1 == new_value4) && ((new_value4 != start_value2) || (new_value4 != start_value3) || (new_value4 != start_value4)))) {
				flag2++;
			}
			if (start_value2 == new_value2) {
				flag1++;
			}
			else if (((start_value2 == new_value1) &&  ((new_value1 != start_value1) || (new_value1 != start_value3) || (new_value1 != start_value4)))
				 || ((start_value2 == new_value2) && ((new_value2 != start_value1) || (new_value2 != start_value3) || (new_value2 != start_value3)))
				 || ((start_value2 == new_value3) && ((new_value3 != start_value1) || (new_value3 != start_value3) || (new_value3 != start_value3)))
				 || ((start_value2 == new_value4) && ((new_value4 != start_value1) || (new_value4 != start_value3) || (new_value4 != start_value3)))) {
				flag2++;
			}
			if (start_value3 == new_value3) {
				flag1++;
			}
			else if (((start_value3 == new_value1) && ((new_value1 != start_value1) || (new_value1 != start_value2) || (new_value1 != start_value4)))
				 || ((start_value3 == new_value2) && ((new_value2 != start_value1) || (new_value2 != start_value2) || (new_value2 != start_value4)))
				 || ((start_value3 == new_value3) && ((new_value3 != start_value1) || (new_value3 != start_value2) || (new_value3 != start_value4)))
				 || ((start_value3 == new_value4) && ((new_value4 != start_value1) || (new_value4 != start_value2) || (new_value4 != start_value4)))) {
				flag2++;
			}
			if (start_value4 == new_value4) {
				flag1++;
			}
			else if (((start_value4 == new_value1) && ((new_value1 != start_value1) || (start_value4 != start_value2) || (start_value4 != start_value3)))
				 || ((start_value4 == new_value2) && ((new_value2 != start_value1) || (start_value4 != start_value2) || (start_value4 != start_value3)))
			 	 || ((start_value4 == new_value3) && ((new_value3 != start_value1) || (start_value4 != start_value2) || (start_value4 != start_value3)))
			  	 || ((start_value4 == new_value4) && ((new_value4 != start_value1) || (start_value4 != start_value2) || (start_value4 != start_value3)))) {
				flag2++;
			}
			cout << "Угадано : " << flag2 << ". На своих местах : " << flag1<< endl; \
				history << "Ваш вариант -> " << game_number << " Угадано : " << flag2 << ". На своих местах : " << flag1<< endl;
		}
		cout << "****Вы Угадали!****" << endl;
		history << "****Вы Угадали!****" << endl;
		cout << "Введите 1 для повторной игры, и 2 для выхода из программы." << endl;
		do {
			try
			{
				cin >> game;
				if (game < 1 || game >  2) {
					throw - 4;
				}
			}
			catch (int a) {
				game = 0;
				cout << "Неправильный ввод переменной. Ошибка номер  " << a << ", повторие ввод." << endl;
			}
		}
		while (game == 0);
	} 
	while (game == 1);

	history.close();
	chislo.close();
	cout << "Программа завершилась." << endl;
}