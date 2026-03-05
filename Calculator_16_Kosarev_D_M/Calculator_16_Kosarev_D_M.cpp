#include <iostream>//библиотека входа ввывода
#include<string>// для работы со строками
#include<sstream>// для преобразование строк в числа 
#include<iomanip> // для форматирование вывода 

int a = 0;
int b = 0;
int result = 0;
//функция для ввода 16-ричного числа, принимает строку подсказку , возвращает число в десятичном виде 
int inputHex(std::string promt) {
	std::string input;
	int number;
	std::cout << promt;
	getline(std::cin, input);
	std::stringstream ss;//поток для преобразования строки в число 
	ss << std::hex << input;//записываем строку в поток, "hex" обозначает что число в 116-ричной системе
	ss >> number;//преобразуем поток в число
	return number;
}
// функция сложения на ассемблере - принимает 2 числа и возвращает их сумму 
int addAsm(int x, int y) {
	int result_asm = 0;
	__asm {
		movl eax,x//загружаем первое число 
		movl ebx , y// загркжаем второк число 
		add eax,ebx // складываем в "eax"
		mov result_asm , eax// сохраняем результат в "eax" в переменную
		// Описываем какие регистры мы используем 
		
	}
	return result_asm;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	std::cout << "===================" << std::endl;
	std::cout << "Введите чисда в HEX (например: 1F,A3,100" << std::endl;
	a = inputHex("Введите первое число в HEX: ");
	b = inputHex("Введите второе число в HEX: ");
	result = addAsm(a, b);

	std::cout << "Результат: " << result;
	return 0;
}

