#include "CSceneGame.h"
//OpenGL
#include"glut.h"
#include"CVector.h"
#include"CMatrix.h"
#include"CTriangle.h"
#include<math.h>
#include"CModel.h"
#include"CBullet.h"
#include"CTaskManager.h"
#include"CEnemy.h"
#include"CCollisionManager.h"
#include"CBillBoard.h"
#include"CCamera.h"
#include"CText.h"
#include"CKey.h"
#include "CItem.h"
#include"CGate.h"
#include"CObj.h"
CModel Model;
CModel BackGround;
CModel ModelEnemy;
CModel ModelEnemy2;
CModel ModelAirBase;//��R��n���f��
std::shared_ptr<CTexture>TextureExp(new CTexture());
//�L�����N�^�̐ݒ�
void CSceneGame::Init() {

	mItem.Load("sphere.obj", "sphere.mtl");
	mGate.Load("cube.obj", "cube.mtl");
	mCube.Load("cube.obj", "cube.mtl");
	mCube.mMaterial[0].mDiffuse[3] = 0.0f;
	mWood.Load("ki.obj", "ki.mtl");
	mStop.Load("sphere.obj", "sphere.mtl");
	mFallenTree.Load("touboku.obj", "touboku.mtl");
	////////////////////////////////////���H
	new CObj(&mCube, CVector(89.0f, -2.6f, 50.0f), CVector(0.0f, 90.0f, 0.0f), CVector(15.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(87.0f, -2.6f, 35.0f), CVector(0.0f, 105.0f, 0.0f), CVector(15.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(110.0f, -2.6f, 63.0f), CVector(0.0f, 8.0f, 0.0f), CVector(15.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(32.0f, -2.6f, 8.0f), CVector(0.0f, 20.0f, 0.0f), CVector(15.0f, 1.8f, 2.45f));
	new CObj(&mCube, CVector(80.5f, -2.6f, 14.6f), CVector(0.0f, -20.0f, 0.0f), CVector(15.5f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(40.0f, -2.6f, -24.9f), CVector(0.0f, 40.0f, 0.0f), CVector(17.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(110.0f, -2.6f, -15.0f), CVector(0.0f, -45.0f, 0.0f), CVector(16.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(116.0f, -2.6f, 4.6f), CVector(0.0f, -20.0f, 0.0f), CVector(17.5f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(130.0f, -2.6f, -3.0f), CVector(0.0f, 90.0f, 0.0f), CVector(16.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(122.0f, -2.6f, 73.0f), CVector(0.0f, 100.0f, 0.0f), CVector(15.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(125.0f, -2.6f, 28.0f), CVector(0.0f, 85.0f, 0.0f), CVector(15.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(135.0f, -2.6f, -25.0f), CVector(0.0f, 0.0f, 0.0f), CVector(15.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(127.0f, -2.6f, 67.0f), CVector(0.0f, 30.0f, 0.0f), CVector(15.0f, 1.8f, 2.9f));
	new CObj(&mCube, CVector(85.5f, -2.6f, -9.5f), CVector(0.0f, 130.0f, 0.0f), CVector(14.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(56.0f, -2.6f, 1.84f), CVector(0.0f, 93.0f, 0.0f), CVector(14.0f, 1.8f, 3.2f));


//	new CObj(&mCube, CVector(110.0f, -2.6f, 5.0f), CVector(0.0f, -75.0f, 0.0f), CVector(16.0f, 1.8f, 2.4f));
	////////////////////////////////�����

	new CObj(&mCube, CVector(111.0f, -2.6f, 29.5f), CVector(0.0f, 193.0f, 0.0f), CVector(15.5f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(110.0f, -2.6f, 51.5f), CVector(0.0f, -35.0f, 0.0f), CVector(16.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(120.0f, -2.6f, 39.7f), CVector(0.0f, 115.0f, 0.0f), CVector(16.0f, 1.8f, 2.4f));
	new CObj(&mCube, CVector(99.0f, -2.6f, 40.9f), CVector(0.0f, 80.0f, 0.0f), CVector(15.0f, 1.8f, 2.5f));//���̎���

	//�␶���A���f���A�ʒu�A��]�A�g��
	//new CItem(&mItem, CVector(20.0f, 0.5f, 20.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));
	//new CItem(&mItem, CVector(-20.0f, 0.5f, -40.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));
	//new CItem(&mItem, CVector(40.0f, 0.5f, 40.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));
	new CItem(&mItem, CVector(20.0f, 0.5f, 40.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));
	new CItem(&mItem, CVector(-20.0f, 0.5f, 40.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));
	new CItem(&mItem, CVector(110.0f, 0.5f, 40.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));//�L�[�A�C�e��3��
	
	new CDisturdanceItem(&mStop, CVector(-110.0f, 0.5f, 40.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));

//////////////�X�G���A
	new CObj(&mCube, CVector(0.0f, -1.0f, 60.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(0.0f, -1.0f, 60.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(30.0f, -1.0f, 30.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(30.0f, -1.0f, 30.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(50.0f, -1.0f, 60.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(50.0f, -1.0f, 60.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(70.0f, -1.0f, 30.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(70.0f, -1.0f, 30.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(50.0f, -1.0f, 60.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(50.0f, -1.0f, 60.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(70.0f, -1.0f, 30.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(70.0f, -1.0f, 30.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(70.0f, -1.0f, 50.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(70.0f, -1.0f, 50.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(70.0f, -1.0f, 70.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(70.0f, -1.0f, 70.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(90.0f, -1.0f, 80.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(90.0f, -1.0f, 80.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(85.0f, -1.0f, 110.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(85.0f, -1.0f, 110.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(70.0f, -1.0f, 130.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(70.0f, -1.0f, 130.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(70.0f, -1.0f, 150.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(70.0f, -1.0f, 150.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(70.0f, -1.0f, 170.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(70.0f, -1.0f, 170.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

	new CObj(&mCube, CVector(70.0f, -1.0f, 190.0f), CVector(), CVector(1.3f, 2.0f, 1.3f));
	new CWood(&mWood, CVector(70.0f, -1.0f, 190.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));//2�y�A

//////////////////
	new CFallenTree(&mFallenTree, CVector(110.0f, 0.1f, 30.0f), CVector(0.0f, 103.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));

	new CFallenTree(&mFallenTree, CVector(109.5f, 0.1f, 51.2f), CVector(0.0f, 55.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));

	new CFallenTree(&mFallenTree, CVector(119.9f, 0.1f, 39.6f), CVector(0.0f, 25.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));

	new CFallenTree(&mFallenTree, CVector(99.0f, 0.1f, 41.0f), CVector(0.0f, -10.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));//���̎���

//////////////////���H�G���A
	new CFallenTree(&mFallenTree, CVector(89.0f, 0.1f, 50.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(87.0f, 0.1f, 35.0f), CVector(0.0f, 15.0f, 0.0f), CVector(1.6f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(110.0f, 0.1f, 63.0f), CVector(0.0f, 98.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(32.0f, 0.1f, 8.0f), CVector(0.0f, 110.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(80.5f, 0.1f, 14.7f), CVector(0.0f, -110.0f, 0.0f), CVector(1.60f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(40.0f, 0.1f, -25.0f), CVector(0.0f, -50.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(110.0f, 0.1f, -15.0f), CVector(0.0f, -135.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(116.0f, 0.1f, 4.55f), CVector(0.0f, 70.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(130.0f, 0.1f, -3.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(122.0f, 0.1f, 73.0f), CVector(0.0f, 10.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(125.0f, 0.1f, 28.0f), CVector(0.0f, -5.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(135.0f, 0.1f, -25.0f), CVector(0.0f, 90.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(127.0f, 0.1f, 67.0f), CVector(0.0f, 120.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));
	new CFallenTree(&mFallenTree, CVector(85.0f, 0.1f, -10.0f), CVector(0.0f, 40.0f, 0.0f), CVector(1.7f, 1.7f, 2.15f));
	new CFallenTree(&mFallenTree, CVector(56.0f, 0.1f, 1.73f), CVector(0.0f, 3.0f, 0.0f), CVector(1.7f, 1.7f, 2.15f));

	//new CFallenTree(&mFallenTree, CVector(110.0f, 0.1f, 5.0f), CVector(0.0f, -165.0f, 0.0f), CVector(1.7f, 1.7f, 2.35f));

	//////////////////
	//new CObj(&mCube, CVector(70.0f, -1.0f, 30.0f), CVector(), CVector(4.3f, 1.0f, 1.3f));
	//new CObj(&mCube, CVector(70.0f, -1.0f, 30.0f), CVector(), CVector(4.3f, 1.0f, 1.3f));


	//CEnemy::mPointSize = 3;//�|�C���g���̐ݒ�
	//CEnemy::mPoint = new CPoint[CEnemy::mPointSize];
	//CEnemy::mPoint[0].Set(CVector(50.0f,30.0f,60.0f), 10.0f);
	//CEnemy::mPoint[1].Set(CVector(35.0f, 5.0f, 0.0f), 10.0f);
	//CEnemy::mPoint[2].Set(CVector(-35.0f, 45.0f, 50.0f), 10.0f);

	BackGround.Load("sky.obj", "sky.mtl");
	CMatrix matrix;
	matrix.RotateY(30);
	matrix.Print();
	matrix.RotateX(30);
	matrix.Print();
	matrix.RotateZ(30);
	matrix.Print();
	//���f���t�@�C���̓���
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
	Model.Load("Sphere.obj", "Sphere.mtl");
	ModelEnemy.Load("nekoX.obj", "nekoX.mtl");
	//�����e�N�X�`���̓ǂݍ���
	TextureExp->Load("exp.tga");
	//�L�����N�^�̐ݒ�
	//Character.mpModel = &Model;
	Player.mpModel = &Model;
	//�X�P�[����1�{��ݒ�
	//Character.mScale = CVector(1.0f, 1.0f, 1.0f);
	Player.mScale = CVector(0.1f, 0.1f, 0.1f);
	Player.mPosition = CVector(-10.0f, 1.0f, -55.0f);
	//�G�@�̐���
	//new CEnemy(&ModelEnemy, CVector(-10.0f, 2.0f, 55.0f), CVector(0.0f,-180.0f,0.0f), CVector(3.0f, 3.0f, 3.0f));
	//new CEnemy(&ModelEnemy, CVector(-10.0f, 9.0f, 55.0f), CVector(0.0f, 0.0f, -30.0f), CVector(0.2f, 0.2f, 0.2f));
	//�r���{�[�h�̐���
	//new CBillBoard(CVector(13.0f, 6.0f, 10.0f), 2.0f, 2.0f);
	//�|�C���g�̐ݒ�
	//CEnemy::mPoint = new CPoint[3];
}

void CSceneGame::Update() {
	//���_�̐ݒ�
	//gluLookAt(���_X,���_Y,���_Z,���SX,���SY,���SZ,���X,���Y,���Z)
	//gluLookAt(11.0f, 12.0f, 83.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		//�X�V����
	if (CGate::CG > 0){
		TaskManager.Update();
	}
	//�R���W�����}�l�[�W���̏Փˏ���
	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = Player.mPosition;/* CVector(0.0, 10.0, -30.0)*Player.mMatrix;*/
		//�����_�����߂�
	c = CVector(0.0,-0.05,1.0)*Player.mMatrix; Player.mPosition;
	//����������߂�
		u = CVector(0.0, 1.0, 0.0)*Player.mMartixRotate;

		if (CKey::Push('U')){
			//�����_�����߂�
			c = CVector(0.0, -0.05, -1.0)*Player.mMatrix; //Player.mPosition;
		}

		if (CKey::Push('M')){

			e = CVector(0.0, 180.0, -4.0);
			c = CVector(0.0, -0.05, 1.0);
			u = CVector(0.0, 0.5, 0.0);
			
			//(> - <;)						

		}
	//�J�����̐ݒ�
	//gluLookAt(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);
	//�J�����N���X�̐ݒ�
		Camera.Set(e, c, u);
		Camera.Render();
	BackGround.Render();
	//Y���ŉ�]������
	//Character.mRotation.mY++;
	//�`�揈��
	CollisionManager.Collision();

	//�^�X�N���X�g�̍폜
	TaskManager.Delete();
	//�^�X�N�}�l�[�W���̕`��
	TaskManager.Render();

	CollisionManager.Render();
	//static�ϐ��̍쐬
	static int frame = 0;//�t���[�����̃J�E���g
	frame++;//�t���[�����̃J�E���g
	if (CItem::GateCount > 2){
		new CGate(&mGate, CVector(-20.0f, 0.0f, 100.0f), CVector(), CVector(4.5f, 5.5f, 0.5f));
		CItem::GateCount = 0;
	}

	//if (frame < 1000 && frame % 150 == 0){
	//	//�G�@�̐���
	//	new CEnemy(&ModelEnemy, CVector(-10.0f, 7.0f, 200.0f),
	//		CVector(0.0f, 180.0f, -30.0f), CVector(0.2f, 0.2f, 0.2f));
	//	EnemyHP = 10;//(/�ց_)
	//}
	//2D�`��J�n
	Start2D(0, 800, 0, 600);
	if (frame < 150){
		//2D�`��
		CText::DrawString("MISSION START", 170, 400, 20, 20);
	}
	if (CGate::CG<=0){
		CText::DrawString("GAME CLAER!",180,400,20,20);
	}
	//2D�`��I��
	End2D();
	return;
}
CSceneGame::~CSceneGame(){
	delete[]CEnemy::mPoint;
}


void CSceneGame::Start2D(float left, float right, float bottom, float top){
	//���f���r���[�s��̑ޑI
	glPushMatrix();
	//���f���r���[�s��̏�����
	glLoadIdentity();

	//���f���r���[�s�񂩂�
	//�v���W�F�N�V�����s��֐؂�ւ�
	glMatrixMode(GL_PROJECTION);
	//�v���W�F�N�V�����s��̑ޑI
	glPushMatrix();
	//�v���W�F�N�V�����s��̏�����
	glLoadIdentity();
	//2D�`��̐ݒ�
	gluOrtho2D(left, right, bottom, top);
	//Depth�e�X�g�I�t
	glDisable(GL_DEPTH_TEST);
}

//2D�`��I��
void CSceneGame::End2D(){
	//�v���W�F�N�V�����s���߂�
	glPopMatrix();
	//���f���r���[���[�h�֐؂�ւ�
	glMatrixMode(GL_MODELVIEW);
	//���f���r���[�s���߂�
	glPopMatrix();
	//Depth�e�X�g�I��
	glEnable(GL_DEPTH_TEST);
}