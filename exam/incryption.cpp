#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <openssl/conf.h> // �������, ��������� � ��������� ��������� OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // ���� ���������������� ������� https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // ���� ���������� ������ OpenSSL � �� �����������
#include <openssl/aes.h>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

//#define BUFLEN 256
// ���������� OpenSSL (openssl.org) ������������ ������ ����������� (��. �������� ���. �� �����������)

//� ������� �++/�����/�������������� �������� ���������� ������  ����� ...\openssl-master\openssl-master\include
//� ������� �����������/�����/�������������� �������� ��������� ����� ...\openssl-master\openssl-master
//� ������� �����������/���� ����� libcrypto.lib
// � ���� ������� ������� � ������ openssl � ��������� ������� perl Configure VC-WIN64A no-asm
//����� � x64 native tools ������� � ������ openssl � ������ nmake
//������� cd /d ��� ����� ����� � ��������
//������� cd .. ��������� �� ���� ������� �����
// ������ � �������� ������������ � ��������� ������� ���
//libcrypto.dll ��������� � ����� x64 debug 
using namespace std;

class  DBRecord
{
protected: string name, sname, passport;
};

class DBclass : public DBRecord
{
private: string alldate;
public:
	int load(const char * filename, const unsigned char * k)
	{
		unsigned char cryptedtext[256]; 
		unsigned char decryptedtext[256];
		unsigned char *key = (unsigned char *)k;
		unsigned char *iv = (unsigned char *)"0123456789012345";
		EVP_CIPHER_CTX *ctx;
		ctx = EVP_CIPHER_CTX_new();
		EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

		FILE *t3;
		t3 = fopen("41_encrypted.txt", "rb");
		int len;
		int cryptedtext_len;
		for (;;)
		{
			cryptedtext_len = fread(cryptedtext, 1, 256, t3);
			if (cryptedtext_len <= 0) break;
			if (!EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len)) return 0; // ������� �������� : ����� ������� ������

			string as;
			if (cryptedtext_len == 256)
			{

				for (int i = 0; i < len; i++)
				{
					cout << hex << decryptedtext[i];
					//as[i] = decryptedtext[i];
					//if ((i + 1) % 80 == 0) cout << endl;
				}
				//as = decryptedtext;
				//alldate += as;
			}

		}
		//EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // ����������, ����������

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
	
	};
};
void bruteforse(const char * filename, char* pass_to_find)
{
	EVP_CIPHER_CTX *ctx;
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������
	unsigned char *iv = (unsigned char *)"0123456789012345";
	int len;
	int cryptedtext_len;
	char k[33];
	unsigned char decryptedtex[256];
	unsigned char cryptedtex[256];
	FILE *t3;
	t3 = fopen(filename, "rb");
	if (t3 == NULL) std::cout << "errrrrrooooor" << std::endl;

	cryptedtext_len = fread(cryptedtex, 1, 256, t3);
	if (cryptedtext_len > 0) std::cout << "all good" << std::endl;
	// 2.
	for (int i = 0; i < 10000; i++)
	{
		sprintf(k, "%032d", i);
		//std::cout << k[0];
		//key = (unsigned char *)k;
		EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)k, iv); // ������������� ������� AES, ������ � ��������
		EVP_DecryptUpdate(ctx, decryptedtex, &len, cryptedtex, cryptedtext_len);
		//std::cout << cryptedtex[0]<<" ";
		//std::cout << decryptedtex[0]<<std::endl;
		//EVP_DecryptFinal_ex(ctx, (unsigned char *)3, &len);
		if (decryptedtex[0] == '{' && decryptedtex[1] == '\r' && decryptedtex[2] == '\n')
		{
			for (int j=0; j<33; j++)
			pass_to_find[j] = k[j];
			
			cout << pass_to_find<<endl;
			break;
		}

	}
	fclose(t3);
};
int main()
{
	setlocale(LC_ALL, "Russian");
	// ������ � ��������������� OpenSSL:
	// 1) �������� ������� � �����������
	// 2) ����������, ����������
	// 3) �����������
	// 4) � ����� ������������� ������

	// ��� �������, � ����������, ��������� ������������ ��� �������� ������ ������
	// �� ����� � ������� � �������������/������������
	struct name_of_my_struct // ������ ������
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

	//unsigned char plaintext[256];
	//int plaintext_len;// = fread(plaintext, 1, BUFLEN, in); // ����� ������
	unsigned char *key; //= (unsigned char *)"0123456789"; // ������ (����)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // ���������������� ������, �����������
	unsigned char cryptedtext[256]; // ������������� ���������
	unsigned char decryptedtext[256]; // �������������� ���������

	// 1. �������� ��������� �� �������������� ���������
	// ��������� - ��� ������ � C++, ������ � ������, �������� ����������
	EVP_CIPHER_CTX *ctx; // structure
	/*
	// 2. ��� ��������� �������� ������ ��������� �������� (�����, ����, ������ ������������� � �.�.)
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������
	/*
	// 3. ��������� EVP_CIPHER_CTX ����������� �����������
	EVP_EncryptInit_ex(ctx, // ������ �� ������/���������, ���� ��������� ���������
		EVP_aes_256_cbc(), // ������ �� ��������� ���� AES 256 (������� � ����������)
		NULL,
		key, // ����/������/������
		iv); // ����������� (��������� ��������� ������)

	/*
	int len;
	FILE *t1, *t2;
	t1 = fopen("t3.txt", "rb");
	t2 = fopen("t2.txt", "wb");

	for (;;)
	{
		// 4. ��� ������� ���������� - ������� EVP_EncryptUpdate
		plaintext_len = fread(plaintext, 1, 256, t1);

		if (plaintext_len <= 0) break;
		if (!EVP_EncryptUpdate(ctx, // ������ � �����������
			cryptedtext, // ������� ��������: ������, ���� �������� ������������� ������
			&len, // �������� ��������: ����� ����������� �����
			plaintext, // ������� ��������: ��� ���������
			plaintext_len)) return 0; // ������� �������� : ����� ������� ������

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


	// 5. ����������� �������� ����������
	// ����������, ���� ��������� ���� �������� ������� �� ���������
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


	// 6. �������� ���������
	EVP_CIPHER_CTX_free(ctx);
	fclose(t1);
	fclose(t2);
	*/
	// �����������
	/*
	// 1.
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������
int len;
int cryptedtext_len;
char k[33];
unsigned char decryptedtex[256];
unsigned char cryptedtex[256];
FILE *t3;
t3 = fopen("41_encrypted.txt", "rb");
if (t3 == NULL) std::cout << "errrrrrooooor"<<std::endl;

cryptedtext_len = fread(cryptedtex, 1, 256, t3);
if (cryptedtext_len > 0) std::cout << "all good" << std::endl;
// 2.
for (int i = 0; i < 10000; i++)
{
	sprintf(k,"%032d", i);
	//std::cout << k[0];
	key = (unsigned char *)k;
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // ������������� ������� AES, ������ � ��������
	EVP_DecryptUpdate(ctx, decryptedtex, &len, cryptedtex, cryptedtext_len);
	//std::cout << cryptedtex[0]<<" ";
	//std::cout << decryptedtex[0]<<std::endl;
	//EVP_DecryptFinal_ex(ctx, (unsigned char *)3, &len);
	if (decryptedtex[0] == '{' && decryptedtex[1] == '\r' && decryptedtex[2] == '\n')
	{
		std::cout << "key="<< key<<std::endl;
		break;
	}
		
}
*/
	// 3.
	char ke[33];
	bruteforse("41_encrypted.txt", ke);
	cout << ke<<endl;
	key = (unsigned char*)ke;
	
	DBclass baza;
	baza.load("41_encrypted.txt", key);
	/*
	ctx = EVP_CIPHER_CTX_new();
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
	
	FILE *t3;
	t3 = fopen("41_encrypted.txt", "rb");
	int len;
	int cryptedtext_len;
	for (;;)
	{
		cryptedtext_len = fread(cryptedtext, 1, 256, t3);
		if (cryptedtext_len <= 0) break;
		if (!EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len)) return 0; // ������� �������� : ����� ������� ������

		if (cryptedtext_len == 256)
		{

			for (int i = 0; i < len; i++)
			{
				cout << hex << decryptedtext[i];
				//if ((i + 1) % 80 == 0) cout << endl;
			}
		}

	}
	//EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // ����������, ����������

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
	*/
	// --- ���������� �����
	// ������������ ����� ��� ��, �� ��������, � �����
	// � �����
	/*
		1) �������� ������ � ��������� ���������� OpenSSL
		2) ���������� ������� �����
		3) while(���������_�������� > 0)
		{
			4) ���������� ����������
			5) ������ �������������� ������� � ����
			6) ���������� ���������� ���������
		}
		7) ���������� �������������� �������
		8) ������ ��������������� ����� � ����
		9) �������� ������
	*/
	getchar();
	return 0;
}