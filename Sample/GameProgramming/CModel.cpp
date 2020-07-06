#include"CModel.h"
//文字列関数のインクルード
#include<string.h>
//CVectorのインクルード
#include"CVector.h"


//標準入出力のインクルード
#include<stdio.h>
//デフォルトコンストラクタ
CModel::CModel()
:mpVertex(0), mpNormal(0), mpTextureCoord(0)
{
}
//デストラクタ
CModel::~CModel(){
	if (mpVertex){
		//頂点座標配列削除
		delete[]mpVertex;
	}
	if (mpNormal){
		//法線配列削除
		delete[]mpNormal;
	}
	if (mpTextureCoord){
		//テクスチャマッピング配列削除
		delete[]mpTextureCoord;
	}
}
//モデルファイルの入力
//Load(モデルファイル名、マテリアルファイル名)
void CModel::Load(char*obj, char*mtl){
	FILE*fp;

	std::vector<CVector> vertex;
	std::vector<CVector> normal;
	std::vector<CVector>uv;

	//入力エリアの作成を移動
	char buf[256];
	//ファイルのオープン
	//fopen(ファイル名、モード)
	//オープンできないときはNULLを返す
	fp = fopen(mtl, "r");
	//ファイルオープンエラーの判定
	//fpがNULLの時はエラー
	if (fp == NULL){
		//コンソールにエラー出力して戻る
		printf("%s file open error\n", mtl);
		return;
	}
	//マテリアルインデックス
	int idx = 0;
	//ファイルからデータを入力
	while (fgets(buf, sizeof(buf), fp) != NULL){
		//データを分割する
		char str[4][64] = { "", "", "", "" };
		//文字列からデータを4つ変数へ代入する
		sscanf(buf, "%s %s %s %s", str[0], str[1], str[2], str[3]);
		//先頭がnewmtlの時、マテリアルを追加する
		if (strcmp(str[0], "newmtl") == 0){
			CMaterial material;
			//スマートポインタの作成
			std::shared_ptr<CTexture> t(new CTexture());
			//スマートポインタの代入
			material.mpTexture = t;
			//マテリアル名をコピー
			strncpy(material.mName, str[1], sizeof(material.mName) - 1);
			//マテリアルの可変長配列に追加
			mMaterial.push_back(material);
			//配列の長さを取得
			idx = mMaterial.size() - 1;
		}
		//先頭がKdの時、Diffuseを設定する
		else if (strcmp(str[0], "Kd") == 0){
			mMaterial[idx].mDiffuse[0] = atof(str[1]);
			mMaterial[idx].mDiffuse[1] = atof(str[2]);
			mMaterial[idx].mDiffuse[2] = atof(str[3]);
		}
		//先頭がdの時、a値を設定する
		else if (strcmp(str[0], "d") == 0){
			mMaterial[idx].mDiffuse[3] = atof(str[1]);
		}
		//先頭がmap_Kdの時、テクスチャを入力する
		else if (strcmp(str[0], "map_Kd") == 0){
			mMaterial[idx].mpTexture->Load(str[1]);
		}
	}
	//ファイルのクローズ
	fclose(fp);
	//ファイルのオープン
	//fopen(ファイル名、モード)
	//オープンできないときはNULLを返す
	fp = fopen(obj, "r");
	//ファイルオープンエラーの判定
	//fpがNULLの時はエラー
	if (fp == NULL){
		//コンソールにエラー出力して戻る
		printf("%s file open error\n", obj);
		return;
	}
	//ファイルからデータを入力
	//入力エリアを作成する
	//ファイルから1行入力
	//fgets(入力エリア,エリアサイズ,ファイルポインタ)
	//ファイルの最後になるとNULLを返す
	while (fgets(buf, sizeof(buf), fp) != NULL){
		//ファイルポインタ変数の作成
		//データを分割する
		char str[4][64] = { "", "", "", "" };
		//文字列からデータを4つ変数へ代入する
		//sscanf(文字列,変換指定子,変数)
		sscanf(buf, "%s %s %s %s", str[0], str[1], str[2], str[3]);
		//文字列の比較//stecmp(文字列1,文字列2)
		//同じ時0,異なる時0以外を返す
		//先頭がvの時、頂点をvertexを追加
		if (strcmp(str[0], "v") == 0){
			//可変長配列vertexに追加
			//atof(文字列)文字列からfloat型の値を返す
			vertex.push_back(CVector(atof(str[1]), atof(str[2]), atof(str[3])));
		}
		if (strcmp(str[0], "vn") == 0){
			normal.push_back(CVector(atof(str[1]), atof(str[2]), atof(str[3])));
		}
		//先頭がusemtlの時、マテリアルインデックスを取得する
		else if (strcmp(str[0], "usemtl") == 0){
			//可変長配列を後から比較
			for (idx = mMaterial.size() - 1; idx > 0; idx--){
				//同じ名前のマテリアルがあればループ終了
				if (strcmp(mMaterial[idx].mName, str[1]) == 0){
					break;//ループを出る
				}
			}
		}
		//先頭がvtの時、uvに追加する
		else if (strcmp(str[0], "vt") == 0){
			//可変長配列uvに追加
			//atof(文字列)　文字列からfloat型の値を返す
			uv.push_back(CVector(atof(str[1]), atof(str[2]), 0.0));
		}
		//先頭がfの時、三角形を作成して追加する
		else if (strcmp(str[0], "f") == 0){
			//頂点と法線の番号作成
			int v[3], n[3];
			//テクスチャマッピングの有無を判定
			if (strstr(str[1], "//")){
				//頂点と法線の番号取得
				sscanf(str[1], "%d//%d", &v[0], &n[0]);
				sscanf(str[2], "%d//%d", &v[1], &n[1]);
				sscanf(str[3], "%d//%d", &v[2], &n[2]);
				//三角形作成
				CTriangle t;
				t.SetNormal(normal[n[0] - 1], normal[n[1] - 1], normal[n[2] - 1]);
				t.SetVertex(vertex[v[0] - 1], vertex[v[1] - 1], vertex[v[2] - 1]);
				//マテリアル番号の設定
				t.mMaterialIdx = idx;
				//可変長配列mTriangleに三角形を追加
				mTriangle.push_back(t);
			}
			else{
				//テクスチャマッピング有り
				int u[3];//テクスチャマッピングの番号
				//頂点と法線の番号取得とマッピングの番号取得
				sscanf(str[1], "%d/%d/%d", &v[0], &u[0], &n[0]);
				sscanf(str[2], "%d/%d/%d", &v[1], &u[1], &n[1]);
				sscanf(str[3], "%d/%d/%d", &v[2], &u[2], &n[2]);
				//三角形作成
				CTriangle t;
				t.SetVertex(vertex[v[0] - 1], vertex[v[1] - 1], vertex[v[2] - 1]);
				t.SetNormal(normal[n[0] - 1], normal[n[1] - 1], normal[n[2] - 1]);
				//テクスチャマッピングの設定
				t.mUv[0] = uv[u[0] - 1];
				t.mUv[1] = uv[u[1] - 1];
				t.mUv[2] = uv[u[2] - 1];
				//マテリアル番号の設定
				t.mMaterialIdx = idx;
				//可変長配列mTrianglesに三角形を追加
				mTriangle.push_back(t);
			}
		}
		//入力した値をコンソールに出力する
		//printf("%s", buf);
	}
	//ファイルのクローズ
	fclose(fp);
	
	//頂点配列の作成
	//全ての座標の値をマテリアルの順番に保存する
	mpVertex = new float[mTriangle.size() * 9];
	//全ての法線の値をマテリアルの順番に保存する
	mpNormal = new float[mTriangle.size() * 9];
	//全てのテクスチャマッピングの値をマテリアルの順番に保存する
	mpTextureCoord = new float[mTriangle.size() * 6];
	int v = 0, t = 0;
	//マテリアル毎に頂点配列に設定する
	for (int i = 0; i < mMaterial.size(); i++){
		//全ての三角形を比較
		for (int j = 0; j < mTriangle.size(); j++){
			//マテリアル番号が一致する時
			if (i == mTriangle[j].mMaterialIdx){
				//頂点配列に設定する
				//頂点座標
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
				//テクスチャマッピング
				mpTextureCoord[t++] = mTriangle[j].mUv[0].mX;
				mpTextureCoord[t++] = mTriangle[j].mUv[0].mY;
				mpTextureCoord[t++] = mTriangle[j].mUv[1].mX;
				mpTextureCoord[t++] = mTriangle[j].mUv[1].mY;
				mpTextureCoord[t++] = mTriangle[j].mUv[2].mX;
				mpTextureCoord[t++] = mTriangle[j].mUv[2].mY;

			}
		}
		//頂点数を設定
		mMaterial[i].mVertexNum = v / 3;
	}
}

void CModel::Render(){
	//可変長配列の大きさだけ繰り返し
	for (int i = 0; i < mTriangle.size(); i++){
		//マテリアルの適用
		mMaterial[mTriangle[i].mMaterialIdx].Enabled();
		//可変長配列に添え字でアクセスする
		mTriangle[i].Render();
		mMaterial[mTriangle[i].mMaterialIdx].Disabled();
	}
}

//Render(合成行列)
void CModel::Render(const CMatrix &m){
//行列の退避
	glPushMatrix();
	//合成行列を掛ける
	glMultMatrixf(&m.mM[0][0]);
	//頂点座標の配列を有効にする
	glEnableClientState(GL_VERTEX_ARRAY);
	//法線の配列を有効にする
	glEnableClientState(GL_NORMAL_ARRAY);
	//テクスチャマッピングの配列を無効にする
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	//頂点座標の配列を指定する
	glVertexPointer(3, GL_FLOAT, 0, mpVertex);
	//法線の配列を指定する
	glNormalPointer(GL_FLOAT, 0, mpNormal);
	//テクスチャコードの配列を指定する
	glTexCoordPointer(2, GL_FLOAT, 0, mpTextureCoord);
	int first = 0;//描画位置
	//マテリアル毎に描画する
	for (int i = 0; i < mMaterial.size(); i++){
		//マテリアルを適用する
		mMaterial[i].Enabled();
		//描画位置からのデータで三角形を描画します
		glDrawArrays(GL_TRIANGLES, first, mMaterial[i].mVertexNum - first);
		//マテリアルを無効にする
		mMaterial[i].Disabled();
		//描画位置を移動
		first = mMaterial[i].mVertexNum;
	}
	//行列を戻す
	glPopMatrix();

	//頂点座標の配列を無効にする
	glDisableClientState(GL_VERTEX_ARRAY);
	//法線の配列を無効にする
	glDisableClientState(GL_NORMAL_ARRAY);
	//テクスチャマッピングの配列を無効にする
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

	return;
}