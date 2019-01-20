#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <openssl/conf.h> // функции, структуры и константы настройки OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // сами криптогрфические функции https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // коды внутренних ошибок OpenSSL и их расшифровка
#include <openssl/aes.h>
#include <fstream>
#include <string>
#include <cstring>


#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

//#define BUFLEN 256
// библиотеки OpenSSL (openssl.org) подключаются неявно динамически (см. конспект лаб. по библиотекам)

//в разделе С++/общие пишем ...\openssl-master\openssl-master\include
//в разделе Компоновщик/общие/Дополнительные каталоги библиотек пишем ...\openssl-master\openssl-master
//в разделе Компоновщик/ввод пишем libcrypto.lib
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	// работа с криптофункциями OpenSSL:
	// 1) создание объекта с настройками
	// 2) собственно, шифрование
	// 3) финализация
	// 4) и вывод зашифрованных данных

	// как правило, в литературе, структуры используются для хранения только данных
	// ни слова о методах и конструкторах/деструкторах
	struct name_of_my_struct // сродни классу
	{
		name_of_my_struct()
		{

		}

		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};
	
	unsigned char plaintext[256];
	int plaintext_len;// = fread(plaintext, 1, BUFLEN, in); // длина текста
	unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
	unsigned char cryptedtext[256]; // зашифрованный результат
	unsigned char decryptedtext[256]; // расшифрованный результат

	// 1. Создаётся указатель на несуществующую структуру
	// структура - тип данных в C++, близка к КЛАССУ, различия минимальны
	EVP_CIPHER_CTX *ctx; // structure

	// 2. Для указателя создаётся пустая структура настроек (метод, ключ, вектор инициализации и т.д.)
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 3. Структура EVP_CIPHER_CTX заполняется настройками
	EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
		EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
		NULL,
		key, // ключ/пароль/секрет
		iv); // рандомайзер (случайный начальный вектор)

	unsigned char plaintext2[1000];
	int len;
	FILE *t1, *t2 ;
	t1 = fopen("t3.txt", "rb");
	t2 = fopen("t2.txt", "wb");
	
	for (;;)
	{
		// 4. САМ ПРОЦЕСС ШИФРОВАНИЯ - ФУКНЦИЯ EVP_EncryptUpdate
		plaintext_len = fread(plaintext, 1, 256, t1);
		
		if (plaintext_len <= 0) break;
		if (!EVP_EncryptUpdate(ctx, // объект с настройками
			cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
			&len, // выходной параметр: длина полученного шифра
			plaintext, // входной параметр: что шифровать
			plaintext_len)) return 0; // входной параметр : длина входных данных
		
		if (plaintext_len == 256) 
		{
			fwrite(cryptedtext, 1, len, t2);
		for (int i = 0; i < len; i++)
		{
			cout << hex << cryptedtext[i];
			//if ((i + 1) % 80 == 0) cout << endl;
		}
		}
		
	}
	int cryptedtext_len = len;
	
	
	// 5. Финализация процесса шифрования
	// необходима, если последний блок заполнен данными не полностью
	EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
	cryptedtext_len += len;
	fwrite(cryptedtext, 1, cryptedtext_len, t2);

	for (int i = 0; i < cryptedtext_len; i++)
	{
		cout << hex << cryptedtext[i];
		if ((i + 1) % 80 == 0) cout << endl;
	}
	cout << endl;
	cout << "------------ " << endl;


	// 6. Удаление структуры
	EVP_CIPHER_CTX_free(ctx);
	fclose(t1);
	fclose(t2);

	// РАСШИФРОВКА

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором

	// 3.
	FILE *t3;
	t3 = fopen("t2.txt", "rb");

	for (;;)
	{
		cryptedtext_len = fread(cryptedtext, 1, 256, t3);
		if (cryptedtext_len <= 0) break;
		if (!EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len)) return 0; // входной параметр : длина входных данных

		if (cryptedtext_len == 256)
		{
			
			for (int i = 0; i < len; i++)
			{
				cout << hex << decryptedtext[i];
				//if ((i + 1) % 80 == 0) cout << endl;
			}
		}

	}
	//EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ

	// 4.
int decrypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);
	// 5.
	decrypted_len += len;
	for (int i = 0; i < decrypted_len; i++)
	{
		cout << hex << decryptedtext[i];
		//if ((i + 1) % 80 == 0) cout << endl;
	}
	cout << endl;
	cout << "------------ " << endl;

	EVP_CIPHER_CTX_free(ctx);
	fclose(t3);

	// --- шифрование файла
	// производится точно так же, но порциями, в цикле
	// в цикле
	/*
		1) открытие файлов и настройка параметров OpenSSL
		2) считывание первого блока
		3) while(считанный_фрагмент > 0)
		{
			4) шифрование считанного
			5) запись зашифрованного массива в файл
			6) считывание следующего фрагмента
		}
		7) применение финализирующей фукнции
		8) запись финализирующего блока в файл
		9) закрытие файлов
	*/
	getchar();
	return 0;
}