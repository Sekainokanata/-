#include <stdio.h>
#include "DxLib.h"
#include <iostream>
#include <stdlib.h>

void preInitialize(int *width,int *height)
{
	//�f�B�X�v���C�𑜓x�̎擾
	RECT rc;
	GetWindowRect(GetDesktopWindow(), &rc);
	*width = rc.right - rc.left;
	*height = rc.bottom - rc.top;
	//�𑜓x�C�E�B���h�E���[�h�w�聨p�v���W�F�N�g��DPI�ݒ�̕ύX���K�v
	SetGraphMode(*width, *height, 32); // �𑜓x�̐ݒ�
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɕύX
	SetWindowStyleMode(2); // �E�B���h�E�̃X�^�C����g�����Ɏw��
	SetUseBackBufferTransColorFlag(TRUE); // �E�B���h�E�𓧖��ɂ��܂�
}

void afterInitialize() {
	HWND hWnd = GetMainWindowHandle();//�����E�B���h�E
	SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	SetAlwaysRunFlag(TRUE);//�E�B���h�E���A�N�e�B�u��ԂłȂ��Ă����s����
	SetDrawScreen(DX_SCREEN_BACK);//�`��Ώۂ𗠉�ʂɂ���
}

void mainsystem(int width, int height)
{
	/*Live 2D viwer��p����΍s����\����*/
	
	
	
	
	
	/*
	int Arisa_Meido = LoadGraph("�A�[�������C�h��.png");//�f�[�^�n���h��
	int Maria_Tenshi = LoadGraph("�}�[�V���V�g.png");
	int Arisa_Seifuku = LoadGraph("�A�[��������.png");
	int SELECT_GRAPH = Arisa_Meido;
	while (ProcessMessage() == 0)
	{
		ClearDrawScreen();
		DrawGraph(width - 250, height - 450, SELECT_GRAPH,TRUE);//width - 250, height - 450
		ScreenFlip();
		if (CheckHitKey(KEY_INPUT_1)) 
			SELECT_GRAPH = Arisa_Meido;
		if (CheckHitKey(KEY_INPUT_2)) 
			SELECT_GRAPH = Maria_Tenshi;
		if (CheckHitKey(KEY_INPUT_3))
			SELECT_GRAPH = Arisa_Seifuku;

		if (CheckHitKey(KEY_INPUT_Q)) {
			DeleteGraph(Arisa_Meido);// �}�X�R�b�g�̉摜�f�[�^�����������������܂�
			break;
		}
	}
	*/
}


// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int width = NULL;
	int height = NULL;
	preInitialize(&width,&height);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
		return -1;			// �G���[���N�����璼���ɏI��
	afterInitialize();
	mainsystem(width, height);
	DxLib_End();				// �c�w���C�u�����g�p�̏I������
	return 0;				// �\�t�g�̏I�� 
}