#pragma once
#include <string>
#include <map>
#include <vector>

void userReg(std::string& curName, std::string& curSername, std::string& curEmail, int hash); // Ввод данных пользователя во время регистрации

void userEnt(std::string& curName, int hash); // Ввод данных пользователя во время входа в чат

class Chat
{
	std::map <std::string, int> persArray; // Массив с данными пользователя
public:
	void entrChat(bool& persPresence, std::string& curName, int hash); // Вход в чат
	void regChat(bool& nameInChatAlready, bool& persPresence, std::string& curName, std::string& curSername, std::string& curEmail, int hash); // Регистрация в чате
	void sendMess(std::string curName); // Отправить сообщение
};