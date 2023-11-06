#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <wrl.h>
#include "TextureConverter.h"

//�R�}���h���C������
enum Argument
{
	kApplicationPath,
	kFilePath,
	NumArgument
};

int main(int argc, char* argv[])
{
	assert(argc >= NumArgument);

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	if (argc < NumArgument)
	{
		//�g������\������
		TextureConverter::OutputUsage();
		return 0;
	}

	//�I�v�V�����̐�
	int numOptions = argc - NumArgument;
	//�I�v�V�����z��i�_�u���|�C���^�j
	char** options = argv + NumArgument;

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;
	//�e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath], numOptions, options);

	//COM���C�u�����̏I��
	CoUninitialize();

	//system("pause");
	return 0;
}