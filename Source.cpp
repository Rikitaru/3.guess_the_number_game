//�������� ���������, ����������� ���� ������� ����� ��� �������������� �����.
//������� ��������� : ������ ����; ���� ���������� �����, 
//������ � ���������.�� ������ ���� ����������� ������ �������������, 
//� ���������� ����� � �������, ������� ���� ����� ������� � ������� �� ��������� ���� �������� ���������� ������� � �����.
//��������, ���� �������� ����� 1725 � ��������� �������������, ��� �������� ����� 1523, �� ������� ��� �����(5 � 2) � ���� �� ���(2) 
//�������� ������ �������.
//���������� ����� �������� � ��������� �����.��������� ������ ��������� 
//����������� ����� ������� ��������� ���� �� ��������� ��������� ������������� ������.
//�� ������ ��������� ���� ���������� ������ ��� ������� ���� ���.
//������ ������ �� ����� � � �������� ���� :
//�� ������� �������������� �����.
//��� ������� -> 1238 ������� : 0. �� ����� ������ : 0.
//��� ������� -> 5498 ������� : 2. �� ����� ������ : 1.
//****�� �������!****
//������� 1 ��� ��������� ����, � 2 ��� ������ �� ���������.
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
	int game_number = 0; //������������� �����
	int choice;//����� ������������ ��� ������� ������
	int game;
	int newgame_number;
	do {
		system("cls");
		cout << "������������ ����� ��� ��������� � ����� Input.txt. ������ �� ������ ����� ����� � ��� ������������ � ��������� ����?" << endl;
		cout << "1 - ������ ����� ����� � ������������ ������� ���� Input.txt. 2 - ������������ �����, ������� ��������� � �����." << endl;
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
				// ����� ���������� ���� int, ��������������� � ����� try, ����������� ����, - �������������� �����
				choice = -1;
				cout << "������������ ���� ����������. ������ �����  " << a << ", �������� ����." << endl;
			}
		} while (!(choice == 1 || choice == 2));

		if (choice == 1) {
			cout << "������� ����� �������������� ������������ �����." << endl;
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
					cout << "��� �� �������������� ������������� �����. ������ �����  " << a << ", �������� ����." << endl;
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
				}   //���� ���� �� ���������� ��� ���� ������ ������ ����� �����

			}
			catch (int a)
			{
				cout << "�� ������� ���������� �� �����, �� ����� ����� �� ���������� ��� �� ������. ������� ����� ������ ���� ���� ����� � ����������� ������������ ������ 1111. ������ �����  " << a << endl;
				input.close();
				ofstream input("Input.txt");
				input << "1111" << endl;
				input.close();
				system("pause");
			}
			input >> game_number;
			input.close();
			cout << "�������������� ������������ ����� ���� ������� �� ����� ." << endl;
		}
		system("cls");
		cout << "���� ��������!!" << endl;
		flag1= 0;
		history << "���������� �����: " << game_number << endl;
		chislo << game_number << endl;
		while (flag1!= 4) {
			flag1= 0;
			flag2 = 0;
			cout << "�� ������� �������������� �����." << endl;
			cout << "��� ������� -> ";
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
					cout << "������������ ���� ����������. ������ �����  " << a << ", �������� ����." << endl;
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
			cout << "������� : " << flag2 << ". �� ����� ������ : " << flag1<< endl; \
				history << "��� ������� -> " << game_number << " ������� : " << flag2 << ". �� ����� ������ : " << flag1<< endl;
		}
		cout << "****�� �������!****" << endl;
		history << "****�� �������!****" << endl;
		cout << "������� 1 ��� ��������� ����, � 2 ��� ������ �� ���������." << endl;
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
				cout << "������������ ���� ����������. ������ �����  " << a << ", �������� ����." << endl;
			}
		}
		while (game == 0);
	} 
	while (game == 1);

	history.close();
	chislo.close();
	cout << "��������� �����������." << endl;
}