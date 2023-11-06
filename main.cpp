#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <wrl.h>
#include "TextureConverter.h"

//コマンドライン引数
enum Argument
{
	kApplicationPath,
	kFilePath,
	NumArgument
};

int main(int argc, char* argv[])
{
	assert(argc >= NumArgument);

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (argc < NumArgument)
	{
		//使い方を表示する
		TextureConverter::OutputUsage();
		return 0;
	}

	//オプションの数
	int numOptions = argc - NumArgument;
	//オプション配列（ダブルポインタ）
	char** options = argv + NumArgument;

	//テクスチャコンバータ
	TextureConverter converter;
	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath], numOptions, options);

	//COMライブラリの終了
	CoUninitialize();

	//system("pause");
	return 0;
}