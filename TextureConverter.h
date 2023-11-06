#pragma once
#include <string>
#include <DirectXTex.h>

class TextureConverter
{
private:
	//画像の情報
	DirectX::TexMetadata metadata_;
	//画像イメージのコンテナ
	DirectX::ScratchImage scratchImage_;
	//ディレクトリパス
	std::wstring directoryPath_;
	//ファイル名
	std::wstring fileName_;
	//ファイル拡張子
	std::wstring fileExt_;

public:
	void ConvertTextureWICToDDS(const std::string& filePath,
		int numOptions = 0, char* options[] = nullptr);
	void LoadWICTextureFromFile(const std::string& filePath);

private:
	void SeparateFilePath(const std::wstring& filePath);
	void SaveDDSTextureToFile(int numOptions, char* options[]);

public:
	static void OutputUsage();

private:
	static std::wstring ConvertMultibyteStringToWideString(const std::string& mString);
};