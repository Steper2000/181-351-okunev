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

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

//#define BUFLEN 256
// ���������� OpenSSL (openssl.org) ������������ ������ ����������� (��. �������� ���. �� �����������)

using namespace std;

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
	
	unsigned char plaintext[256];
	int plaintext_len;// = fread(plaintext, 1, BUFLEN, in); // ����� ������
	unsigned char *key = (unsigned char *)"0123456789"; // ������ (����)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // ���������������� ������, �����������
	unsigned char cryptedtext[256]; // ������������� ���������
	unsigned char decryptedtext[256]; // �������������� ���������

	// 1. �������� ��������� �� �������������� ���������
	// ��������� - ��� ������ � C++, ������ � ������, �������� ����������
	EVP_CIPHER_CTX *ctx; // structure

	// 2. ��� ��������� �������� ������ ��������� �������� (�����, ����, ������ ������������� � �.�.)
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 3. ��������� EVP_CIPHER_CTX ����������� �����������
	EVP_EncryptInit_ex(ctx, // ������ �� ������/���������, ���� ��������� ���������
		EVP_aes_256_cbc(), // ������ �� ��������� ���� AES 256 (������� � ����������)
		NULL,
		key, // ����/������/������
		iv); // ����������� (��������� ��������� ������)

	unsigned char plaintext2[1000];
	int len;
	FILE *t1, *t2, *t3;
	t1 = fopen("t3.txt", "r");
	t2 = fopen("t2.txt", "w");
	
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
			if ((i + 1) % 80 == 0) cout << endl;
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

	// �����������

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // �������� ��������� � ����������� ������

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // ������������� ������� AES, ������ � ��������

	// 3.
	int x = 0;
	t3 = fopen("t2.txt", "r");
	
//char a[10000];
//int a1 = 0;
//a1 = fread(a, 1, 10000, t3);
	
	for (;;)
	{
		//x += 1;
		//cout << "\n"<< x<<" ->";

		cryptedtext_len = fread(cryptedtext, 1, 256, t3);
		//cout << dec << cryptedtext_len;
		if (cryptedtext_len <= 0) break;
		if (!EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len)) return 0; // ������� �������� : ����� ������� ������

		if (cryptedtext_len == 256)
		{
			
			for (int i = 0; i < len; i++)
			{
				cout << hex << decryptedtext[i];
				if ((i + 1) % 80 == 0) cout << endl;
			}
		}

	}
	//EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // ����������, ����������

	// 4.
int decrypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);
	//cout << decryptedtext << endl;
	//cout << "------------ " << endl;
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
	//decryptedtext[decrypted_len] = '\0';
	//cout << decryptedtext << endl;

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