#include"CModel.h"
//������֐��̃C���N���[�h
#include<string.h>
//CVector�̃C���N���[�h
#include"CVector.h"


//�W�����o�͂̃C���N���[�h
#include<stdio.h>
//�f�t�H���g�R���X�g���N�^
CModel::CModel()
:mpVertex(0), mpNormal(0), mpTextureCoord(0)
{
}
//�f�X�g���N�^
CModel::~CModel(){
	if (mpVertex){
		//���_���W�z��폜
		delete[]mpVertex;
	}
	if (mpNormal){
		//�@���z��폜
		delete[]mpNormal;
	}
	if (mpTextureCoord){
		//�e�N�X�`���}�b�s���O�z��폜
		delete[]mpTextureCoord;
	}
}
//���f���t�@�C���̓���
//Load(���f���t�@�C�����A�}�e���A���t�@�C����)
void CModel::Load(char*obj, char*mtl){
	FILE*fp;

	std::vector<CVector> vertex;
	std::vector<CVector> normal;
	std::vector<CVector>uv;

	//���̓G���A�̍쐬���ړ�
	char buf[256];
	//�t�@�C���̃I�[�v��
	//fopen(�t�@�C�����A���[�h)
	//�I�[�v���ł��Ȃ��Ƃ���NULL��Ԃ�
	fp = fopen(mtl, "r");
	//�t�@�C���I�[�v���G���[�̔���
	//fp��NULL�̎��̓G���[
	if (fp == NULL){
		//�R���\�[���ɃG���[�o�͂��Ė߂�
		printf("%s file open error\n", mtl);
		return;
	}
	//�}�e���A���C���f�b�N�X
	int idx = 0;
	//�t�@�C������f�[�^�����
	while (fgets(buf, sizeof(buf), fp) != NULL){
		//�f�[�^�𕪊�����
		char str[4][64] = { "", "", "", "" };
		//�����񂩂�f�[�^��4�ϐ��֑������
		sscanf(buf, "%s %s %s %s", str[0], str[1], str[2], str[3]);
		//�擪��newmtl�̎��A�}�e���A����ǉ�����
		if (strcmp(str[0], "newmtl") == 0){
			CMaterial material;
			//�X�}�[�g�|�C���^�̍쐬
			std::shared_ptr<CTexture> t(new CTexture());
			//�X�}�[�g�|�C���^�̑��
			material.mpTexture = t;
			//�}�e���A�������R�s�[
			strncpy(material.mName, str[1], sizeof(material.mName) - 1);
			//�}�e���A���̉ϒ��z��ɒǉ�
			mMaterial.push_back(material);
			//�z��̒������擾
			idx = mMaterial.size() - 1;
		}
		//�擪��Kd�̎��ADiffuse��ݒ肷��
		else if (strcmp(str[0], "Kd") == 0){
			mMaterial[idx].mDiffuse[0] = atof(str[1]);
			mMaterial[idx].mDiffuse[1] = atof(str[2]);
			mMaterial[idx].mDiffuse[2] = atof(str[3]);
		}
		//�擪��d�̎��Aa�l��ݒ肷��
		else if (strcmp(str[0], "d") == 0){
			mMaterial[idx].mDiffuse[3] = atof(str[1]);
		}
		//�擪��map_Kd�̎��A�e�N�X�`������͂���
		else if (strcmp(str[0], "map_Kd") == 0){
			mMaterial[idx].mpTexture->Load(str[1]);
		}
	}
	//�t�@�C���̃N���[�Y
	fclose(fp);
	//�t�@�C���̃I�[�v��
	//fopen(�t�@�C�����A���[�h)
	//�I�[�v���ł��Ȃ��Ƃ���NULL��Ԃ�
	fp = fopen(obj, "r");
	//�t�@�C���I�[�v���G���[�̔���
	//fp��NULL�̎��̓G���[
	if (fp == NULL){
		//�R���\�[���ɃG���[�o�͂��Ė߂�
		printf("%s file open error\n", obj);
		return;
	}
	//�t�@�C������f�[�^�����
	//���̓G���A���쐬����
	//�t�@�C������1�s����
	//fgets(���̓G���A,�G���A�T�C�Y,�t�@�C���|�C���^)
	//�t�@�C���̍Ō�ɂȂ��NULL��Ԃ�
	while (fgets(buf, sizeof(buf), fp) != NULL){
		//�t�@�C���|�C���^�ϐ��̍쐬
		//�f�[�^�𕪊�����
		char str[4][64] = { "", "", "", "" };
		//�����񂩂�f�[�^��4�ϐ��֑������
		//sscanf(������,�ϊ��w��q,�ϐ�)
		sscanf(buf, "%s %s %s %s", str[0], str[1], str[2], str[3]);
		//������̔�r//stecmp(������1,������2)
		//������0,�قȂ鎞0�ȊO��Ԃ�
		//�擪��v�̎��A���_��vertex��ǉ�
		if (strcmp(str[0], "v") == 0){
			//�ϒ��z��vertex�ɒǉ�
			//atof(������)�����񂩂�float�^�̒l��Ԃ�
			vertex.push_back(CVector(atof(str[1]), atof(str[2]), atof(str[3])));
		}
		if (strcmp(str[0], "vn") == 0){
			normal.push_back(CVector(atof(str[1]), atof(str[2]), atof(str[3])));
		}
		//�擪��usemtl�̎��A�}�e���A���C���f�b�N�X���擾����
		else if (strcmp(str[0], "usemtl") == 0){
			//�ϒ��z����ォ���r
			for (idx = mMaterial.size() - 1; idx > 0; idx--){
				//�������O�̃}�e���A��������΃��[�v�I��
				if (strcmp(mMaterial[idx].mName, str[1]) == 0){
					break;//���[�v���o��
				}
			}
		}
		//�擪��vt�̎��Auv�ɒǉ�����
		else if (strcmp(str[0], "vt") == 0){
			//�ϒ��z��uv�ɒǉ�
			//atof(������)�@�����񂩂�float�^�̒l��Ԃ�
			uv.push_back(CVector(atof(str[1]), atof(str[2]), 0.0));
		}
		//�擪��f�̎��A�O�p�`���쐬���Ēǉ�����
		else if (strcmp(str[0], "f") == 0){
			//���_�Ɩ@���̔ԍ��쐬
			int v[3], n[3];
			//�e�N�X�`���}�b�s���O�̗L���𔻒�
			if (strstr(str[1], "//")){
				//���_�Ɩ@���̔ԍ��擾
				sscanf(str[1], "%d//%d", &v[0], &n[0]);
				sscanf(str[2], "%d//%d", &v[1], &n[1]);
				sscanf(str[3], "%d//%d", &v[2], &n[2]);
				//�O�p�`�쐬
				CTriangle t;
				t.SetNormal(normal[n[0] - 1], normal[n[1] - 1], normal[n[2] - 1]);
				t.SetVertex(vertex[v[0] - 1], vertex[v[1] - 1], vertex[v[2] - 1]);
				//�}�e���A���ԍ��̐ݒ�
				t.mMaterialIdx = idx;
				//�ϒ��z��mTriangle�ɎO�p�`��ǉ�
				mTriangle.push_back(t);
			}
			else{
				//�e�N�X�`���}�b�s���O�L��
				int u[3];//�e�N�X�`���}�b�s���O�̔ԍ�
				//���_�Ɩ@���̔ԍ��擾�ƃ}�b�s���O�̔ԍ��擾
				sscanf(str[1], "%d/%d/%d", &v[0], &u[0], &n[0]);
				sscanf(str[2], "%d/%d/%d", &v[1], &u[1], &n[1]);
				sscanf(str[3], "%d/%d/%d", &v[2], &u[2], &n[2]);
				//�O�p�`�쐬
				CTriangle t;
				t.SetVertex(vertex[v[0] - 1], vertex[v[1] - 1], vertex[v[2] - 1]);
				t.SetNormal(normal[n[0] - 1], normal[n[1] - 1], normal[n[2] - 1]);
				//�e�N�X�`���}�b�s���O�̐ݒ�
				t.mUv[0] = uv[u[0] - 1];
				t.mUv[1] = uv[u[1] - 1];
				t.mUv[2] = uv[u[2] - 1];
				//�}�e���A���ԍ��̐ݒ�
				t.mMaterialIdx = idx;
				//�ϒ��z��mTriangles�ɎO�p�`��ǉ�
				mTriangle.push_back(t);
			}
		}
		//���͂����l���R���\�[���ɏo�͂���
		//printf("%s", buf);
	}
	//�t�@�C���̃N���[�Y
	fclose(fp);
	
	//���_�z��̍쐬
	//�S�Ă̍��W�̒l���}�e���A���̏��Ԃɕۑ�����
	mpVertex = new float[mTriangle.size() * 9];
	//�S�Ă̖@���̒l���}�e���A���̏��Ԃɕۑ�����
	mpNormal = new float[mTriangle.size() * 9];
	//�S�Ẵe�N�X�`���}�b�s���O�̒l���}�e���A���̏��Ԃɕۑ�����
	mpTextureCoord = new float[mTriangle.size() * 6];
	int v = 0, t = 0;
	//�}�e���A�����ɒ��_�z��ɐݒ肷��
	for (int i = 0; i < mMaterial.size(); i++){
		//�S�Ă̎O�p�`���r
		for (int j = 0; j < mTriangle.size(); j++){
			//�}�e���A���ԍ�����v���鎞
			if (i == mTriangle[j].mMaterialIdx){
				//���_�z��ɐݒ肷��
				//���_���W
				mpVertex[v++] = mTriangle[j].mV[0].mX;
				mpVertex[v++] = mTriangle[j].mV[0].mY;
				mpVertex[v++] = mTriangle[j].mV[0].mZ;
				mpVertex[v++] = mTriangle[j].mV[1].mX;
				mpVertex[v++] = mTriangle[j].mV[1].mY;
				mpVertex[v++] = mTriangle[j].mV[1].mZ;
				mpVertex[v++] = mTriangle[j].mV[2].mX;
				mpVertex[v++] = mTriangle[j].mV[2].mY;
				mpVertex[v++] = mTriangle[j].mV[2].mZ;
				v -= 9;
				mpNormal[v++] = mTriangle[j].mN[0].mX;
				mpNormal[v++] = mTriangle[j].mN[0].mY;
				mpNormal[v++] = mTriangle[j].mN[0].mZ;
				mpNormal[v++] = mTriangle[j].mN[1].mX;
				mpNormal[v++] = mTriangle[j].mN[1].mY;
				mpNormal[v++] = mTriangle[j].mN[1].mZ;
				mpNormal[v++] = mTriangle[j].mN[2].mX;
				mpNormal[v++] = mTriangle[j].mN[2].mY;
				mpNormal[v++] = mTriangle[j].mN[2].mZ;
				//�e�N�X�`���}�b�s���O
				mpTextureCoord[t++] = mTriangle[j].mUv[0].mX;
				mpTextureCoord[t++] = mTriangle[j].mUv[0].mY;
				mpTextureCoord[t++] = mTriangle[j].mUv[1].mX;
				mpTextureCoord[t++] = mTriangle[j].mUv[1].mY;
				mpTextureCoord[t++] = mTriangle[j].mUv[2].mX;
				mpTextureCoord[t++] = mTriangle[j].mUv[2].mY;

			}
		}
		//���_����ݒ�
		mMaterial[i].mVertexNum = v / 3;
	}
}

void CModel::Render(){
	//�ϒ��z��̑傫�������J��Ԃ�
	for (int i = 0; i < mTriangle.size(); i++){
		//�}�e���A���̓K�p
		mMaterial[mTriangle[i].mMaterialIdx].Enabled();
		//�ϒ��z��ɓY�����ŃA�N�Z�X����
		mTriangle[i].Render();
		mMaterial[mTriangle[i].mMaterialIdx].Disabled();
	}
}

//Render(�����s��)
void CModel::Render(const CMatrix &m){
//�s��̑ޔ�
	glPushMatrix();
	//�����s����|����
	glMultMatrixf(&m.mM[0][0]);
	//���_���W�̔z���L���ɂ���
	glEnableClientState(GL_VERTEX_ARRAY);
	//�@���̔z���L���ɂ���
	glEnableClientState(GL_NORMAL_ARRAY);
	//�e�N�X�`���}�b�s���O�̔z��𖳌��ɂ���
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//���_���W�̔z����w�肷��
	glVertexPointer(3, GL_FLOAT, 0, mpVertex);
	//�@���̔z����w�肷��
	glNormalPointer(GL_FLOAT, 0, mpNormal);
	//�e�N�X�`���R�[�h�̔z����w�肷��
	glTexCoordPointer(2, GL_FLOAT, 0, mpTextureCoord);
	int first = 0;//�`��ʒu
	//�}�e���A�����ɕ`�悷��
	for (int i = 0; i < mMaterial.size(); i++){
		//�}�e���A����K�p����
		mMaterial[i].Enabled();
		//�`��ʒu����̃f�[�^�ŎO�p�`��`�悵�܂�
		glDrawArrays(GL_TRIANGLES, first, mMaterial[i].mVertexNum - first);
		//�}�e���A���𖳌��ɂ���
		mMaterial[i].Disabled();
		//�`��ʒu���ړ�
		first = mMaterial[i].mVertexNum;
	}
	//�s���߂�
	glPopMatrix();

	//���_���W�̔z��𖳌��ɂ���
	glDisableClientState(GL_VERTEX_ARRAY);
	//�@���̔z��𖳌��ɂ���
	glDisableClientState(GL_NORMAL_ARRAY);
	//�e�N�X�`���}�b�s���O�̔z��𖳌��ɂ���
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	return;
}