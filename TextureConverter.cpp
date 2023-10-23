#include "TextureConverter.h"
#include <DirectXTex.h>

void TextureConverter::ConvertTextureWICToDDS(const std::string& filePath)
{
	LoadWICTextureFromFile(filePath);
}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	std::wstring wFilePath = ConvertMultibyteStringToWideString(filePath);
}

std::wstring TextureConverter::ConvertMultibyteStringToWideString(const std::string& mString)
{
	//ワイド文字列に変換した際の文字数を計算
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//ワイド文字列
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//ワイド文字列に変換
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}
