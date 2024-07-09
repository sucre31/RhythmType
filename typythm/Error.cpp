#include <string>
#include <DxLib.h>
#include "Error.h"
#include "Define.h"

using namespace std;

void Error::finish(const char* errorMessage, LPCTSTR lpszFuncName, int lineN)
{
	char funcName[1024];
	sprintf_s(funcName, "%s", lpszFuncName);
	printfDx("ÉGÉâÅ[Ç≈Ç∑ÅB \n%s\n%s(%d)"
			,errorMessage
			,funcName
			,lineN);
	while (!ProcessMessage()) {
		ClearDrawScreen();
		ScreenFlip();
	}
	DxLib_End();
	exit(99);
}