// StrToUint64InCpp.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <locale>
#include <atlstr.h>

using namespace std;

// knuth hash
UINT64 CalculateHash(CString read){
	UINT64 hashedValue = 3074457345618258791ull;
	for (int i = 0; i<read.GetLength(); i++)
	{
		hashedValue += read[i];
		hashedValue *= 3074457345618258799ull;
	}
	return hashedValue;
}

int _tmain(int argc, _TCHAR* argv[])
{
	// test code 
	locale::global(locale(""));
	CString str = R"(C:\Users\user\Desktop\제목 없음.png)";

	str.MakeLower();

	printf("%ws\n", str.GetBuffer());
	printf("%llu\n", CalculateHash(str));


	return 0;
}