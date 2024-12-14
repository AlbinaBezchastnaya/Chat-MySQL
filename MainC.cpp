#include <iostream>
#include "HeaderC.h"
#include <map>
#include <vector>

using namespace std;

int main()
{
	string curName; // Текущее имя пользователя
	string curSername; // Текущая фамилия пользователя
	string curEmail; // Текущий адрес электронной почты пользователя
	int hash; // Текущий хэш пользователя
	int messNumber = 0; // Номер текущего сообщения (от ноля и в порядке появления)
	bool persPresence = false; // Если есть пользователь с таким именем и паролем
	bool nameInChatAlready = false; // Если пользователь с таким именем уже есть в чате

	string contProcNumber = "0";     

	Chat presChat;


	while (true)
	{
		while (persPresence == false)  // Пользователь не зашел и не зарегистрировался
		{
			while (contProcNumber != "1" && contProcNumber != "2" && contProcNumber != "3")  // Защита от неправильного ввода
			{
				cout << "Choose the action, please: 1 - to enter; 2 - to log in; 3 - exit." << endl;
				getline(cin, contProcNumber);
			}
			persPresence = false;
			if (contProcNumber == "1")
			{
				presChat.entrChat(persPresence, curName, hash);      // Зайти в чат
				contProcNumber = "0";
			}

			if (contProcNumber == "2")
			{
				presChat.regChat(nameInChatAlready, persPresence, curName, curSername, curEmail, hash);    // Зарегистрироваться в чате
				contProcNumber = "0";
			}

			if (contProcNumber == "3") break;  
		}
		if (contProcNumber == "3") break;      // Выход из программы
		while (true)                       //  Цикл продолжается до тех пор, пока пользователь не выйдет из профиля или программы
		{
			while (contProcNumber != "1" && contProcNumber != "2" && contProcNumber != "3")  
			{
				cout << "Choose the action, please: 1 - start the dialoge (you have to send the message first); 2 - quit the profile." << endl;
				getline(cin, contProcNumber);
			}
			if (contProcNumber == "2")     // Если выбран выход
			{
				cout << endl;
				persPresence = false;
				contProcNumber = "0";
				break;
			}
			if (contProcNumber == "1")      // Если выбрана отправка сообщения
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
		if (contProcNumber == "3") break;      // Выход из программы
	}
	return 0;
}
