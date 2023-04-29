#include <iostream>
#include <locale.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

bool overwrite(std::string str, std::string filename);

int main() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	//Задача 1.
	/*
		Напишите программу, в которой реализована запись
	в файл и считывание из него. Пользователь бесконечно
	вводит строки, которые записываются в файл, пока не
	будет набрана строка end. После этого, программа
	выводит содержимое файла в консоль и удаляет его.
	*/
	
	std::string filename = "file1.txt";
	std::string str;
	std::cout << "Задача 1.\n";
	std::ofstream fout;
	fout.open(filename);
	if (fout.is_open()) {
		
		do {
			std::cout << "Введите строку, для выхода введите строку \"end\":\n";
			std::getline(std::cin, str);
			fout << str << '\n';
			system("cls");
		} while (str != "end");
	}else
		std::cout << "Ошибка открытия файла \"" << filename << "\" для записи.\n";

	fout.close();
	std::ifstream fin;
	fin.open(filename);
	if (fin.is_open()) {
		std::string text_from_file;
		while (std::getline(fin, str)) {
			text_from_file += str + '\n';
		}
		std::cout << text_from_file;
		fin.close();
		system("pause");
		if (remove(filename.c_str()) == 0)
			std::cout << "Файл \"" << filename << "\" удалён.\n";
		else
			std::cout << "Ошибка удаления файла.\n";
	}
	else
		std::cout << "Ошибка открытия файла \"" << filename << "\"  для чтения.\n";
	


	// Задача 2.
	/*
		Создайте функцию overwrite, которая принимает
	путь к файлу и строку, которая полностью заменяет
	содержимое файла. Если файла не существует, то
	функция возвращает false. Если замена прошла
	успешно, функция возвращает true.
	*/
	std::cout << "\n\n\nЗадача 2.\n";
	std::string words = "Кроме этой строки в файле больше ничего нет.\n";
	if (overwrite(words, "file.txt")) {
		std::cout << "Файл file.txt перезаписан.\n";
	}
	else {
		std::cout << "Файл file.txt отсутствует.\n";
	}

	return 0;
}


bool overwrite(std::string str, std::string filename) {
	std::ifstream in;
	in.open(filename);
	if (!in.is_open()) {
		return false;
	}
	else {
		in.close();
		std::ofstream out;
		out.open(filename);
		if (out.is_open()) {
			out << str;
			out.close();
			return true;
		}
		
	}
}