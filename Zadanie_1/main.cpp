#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
using namespace std;

void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
	try {
		wstring cipherText;
		wstring decryptedText;
		modAlphaCipher cipher(key);
		cipherText = cipher.encrypt(Text);
		if (destructCipherText)
			cipherText.front() = towlower(cipherText.front());
		decryptedText = cipher.decrypt(cipherText);
		wcout<<"key="<<key<<endl;
		wcout<<Text<<endl;
		wcout<<cipherText<<endl;
		wcout<<decryptedText<<endl;
	} catch (const cipher_error & e) {
		wcerr<<"Error: "<<e.what()<<endl;
	}
}
int main(int argc, char **argv)
{
	locale loc("ru_RU.UTF-8");
	locale::global(loc);
	check(L"ТУТТЕКСТНАРУССКОМЯЗЫКЕ",L"Первый");
	check(L"ТУТТЕКСТНАРУССКОМЯЗЫКЕ",L"");
	check(L"ТУТТЕКСТНАРУССКОМЯЗЫКЕ",L"АБВГ123");
	check(L"ТУТ ТЕКСТ НА РУССКОМ ЯЗЫКЕ",L"Второй");
	check(L"ТУТТЕКСТНАРУССКОМЯЗЫКЕ",L"Третий",true);
	check(L"123",L"АБВГ");
	return 0;
}