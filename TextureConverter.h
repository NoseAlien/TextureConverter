#pragma once
#include <string>
#include <DirectXTex.h>

class TextureConverter
{
private:
	//�摜�̏��
	DirectX::TexMetadata metadata_;
	//�摜�C���[�W�̃R���e�i
	DirectX::ScratchImage scratchImage_;
	//�f�B���N�g���p�X
	std::wstring directoryPath_;
	//�t�@�C����
	std::wstring fileName_;
	//�t�@�C���g���q
	std::wstring fileExt_;

public:
	void ConvertTextureWICToDDS(const std::string& filePath,
		int numOptions = 0, char* options[] = nullptr);
	void LoadWICTextureFromFile(const std::string& filePath);

private:
	void SeparateFilePath(const std::wstring& filePath);
	void SaveDDSTextureToFile();

public:
	static void OutputUsage();

private:
	static std::wstring ConvertMultibyteStringToWideString(const std::string& mString);
};