#pragma once
#include <string>
class TextureConverter
{
public:
	void ConvertTextureWICToDDS(const std::string& filePath);
	void LoadWICTextureFromFile(const std::string& filePath);

private:
	static std::wstring ConvertMultibyteStringToWideString(const std::string& mString);
};