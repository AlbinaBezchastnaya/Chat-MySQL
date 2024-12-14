#include <iostream>
#include "HeaderC.h"
#include <map>
#include <vector>

using namespace std;

int main()
{
	string curName; // ������� ��� ������������
	string curSername; // ������� ������� ������������
	string curEmail; // ������� ����� ����������� ����� ������������
	int hash; // ������� ��� ������������
	int messNumber = 0; // ����� �������� ��������� (�� ���� � � ������� ���������)
	bool persPresence = false; // ���� ���� ������������ � ����� ������ � �������
	bool nameInChatAlready = false; // ���� ������������ � ����� ������ ��� ���� � ����

	string contProcNumber = "0";     

	Chat presChat;


	while (true)
	{
		while (persPresence == false)  // ������������ �� ����� � �� �����������������
		{
			while (contProcNumber != "1" && contProcNumber != "2" && contProcNumber != "3")  // ������ �� ������������� �����
			{
				cout << "Choose the action, please: 1 - to enter; 2 - to log in; 3 - exit." << endl;
				getline(cin, contProcNumber);
			}
			persPresence = false;
			if (contProcNumber == "1")
			{
				presChat.entrChat(persPresence, curName, hash);      // ����� � ���
				contProcNumber = "0";
			}

			if (contProcNumber == "2")
			{
				presChat.regChat(nameInChatAlready, persPresence, curName, curSername, curEmail, hash);    // ������������������ � ����
				contProcNumber = "0";
			}

			if (contProcNumber == "3") break;  
		}
		if (contProcNumber == "3") break;      // ����� �� ���������
		while (true)                       //  ���� ������������ �� ��� ���, ���� ������������ �� ������ �� ������� ��� ���������
		{
			while (contProcNumber != "1" && contProcNumber != "2" && contProcNumber != "3")  
			{
				cout << "Choose the action, please: 1 - start the dialoge (you have to send the message first); 2 - quit the profile." << endl;
				getline(cin, contProcNumber);
			}
			if (contProcNumber == "2")     // ���� ������ �����
			{
				cout << endl;
				persPresence = false;
				contProcNumber = "0";
				break;
			}
			if (contProcNumber == "1")      // ���� ������� �������� ���������
			{
				presChat.sendMess(curName);
				contProcNumber = "0";
			}
			if (contProcNumber == "2")      
			{
				contProcNumber = "3";
				break;
			}
		}
		if (contProcNumber == "3") break;      // ����� �� ���������
	}
	return 0;
}
