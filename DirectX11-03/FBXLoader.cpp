#include "FBXLoader.h"

namespace FBXLoader
{

	FbxManager* fbxManager;

	HRESULT LoadFBX(LPCSTR fileName, vector<Vertex>* outVertices, vector<DWORD>* outIndices)
	{
		//fbxManager�� ������ �ȵ����� �����ϱ�
		if (fbxManager == NULL)
		{
			//SDK �Ŵ��� ����
			fbxManager = FbxManager::Create();
			//�Ŵ��� �ʱ�ȭ
			FbxIOSettings* ioSetting = FbxIOSettings::Create(fbxManager, IOSROOT);
			fbxManager->SetIOSettings(ioSetting);

		}
		//FbxGeometryConverter ����
		FbxGeometryConverter GeometryConverter(fbxManager);
		FbxImporter* Importer = FbxImporter::Create(fbxManager, " ");
		FbxScene* fbxScene = FbxScene::Create(fbxManager, " "); // �� �̸� ������ ����° ���� �޾������

		//������ �ʱ�ȭ
		if (Importer->Initialize(fileName, -1, fbxManager->GetIOSettings()) == false)
		{
			return E_FAIL;
		}

		//3D ��(���) ����Ʈ
		if (Importer->Import(fbxScene) == false)
		{
			return E_FAIL;
		}

		//FBX Node �б�
		FbxNode* fbxRootNode = fbxScene->GetRootNode();
		if (fbxRootNode == NULL)
		{
			return E_FAIL;
		}
		//�� ������ �⺻ ������ ������Ƽ��� ����
		GeometryConverter.Triangulate(fbxScene, true);


		// ��Ʈ ���� ���� ��� ���� ������
		int childCount = fbxRootNode->GetChildCount();

		for (int i = 0; i < childCount; ++i)
		{
			//�ڽ� ���� ��� �ε��� ������
			FbxNode* childNode = fbxRootNode->GetChild(i);

			//���� Ÿ������ Ȯ�� ( �Ӽ� Ȯ�� )
			FbxNodeAttribute::EType attributeType;
			attributeType = childNode->GetNodeAttribute()->GetAttributeType();

			//�޽� Ÿ������ Ȯ��
			if (attributeType != FbxNodeAttribute::EType::eMesh)
			{
				continue;
			}
			//�޽� ���� �о� ����
			FbxMesh* fbxMesh = childNode->GetMesh();

			//���ؽ� �迭 ������( ���� ) 
			FbxVector4* vertices = fbxMesh->GetControlPoints();

			//������ �� Ȯ��
			int PolyGonCount = fbxMesh->GetPolygonCount();

			//�ε��� ������ ����
			int VertexIndexCounter = 0;

			//������ ��ȸ
			for (int i = 0; i < PolyGonCount; ++i)
			{
				//�������� �����ϴ� ���� ���� Ȯ��
				int VertexCount = fbxMesh->GetPolygonSize(i); //3�� ������

				//������ ���� ���� ��ȸ( 3�� ���ƾ� ����)
				for (int j = 0; j < VertexCount; ++j)
				{
					//���� ���� Ȯ��
					int VerTexIndex = fbxMesh->GetPolygonVertex(j, i);

					//���� ���� �о� ����
					Vertex vertex;
					vertex.xmPosition.x = static_cast<float>(vertices[VerTexIndex].mData[0]);
					vertex.xmPosition.y = static_cast<float>(vertices[VerTexIndex].mData[1]);
					vertex.xmPosition.z = static_cast<float>(vertices[VerTexIndex].mData[2]);

					//�ؽ��� ��ǥ�� ������
					vertex.xmUV = ReadTextureUV(fbxMesh, VerTexIndex, VertexIndexCounter);

					//��� ��
					vertex.xmNormal = ReadNormal(fbxMesh, VerTexIndex, VertexIndexCounter);
					//���� �߰�
					outVertices->push_back(vertex);

					//�ε��� �߰�
					outIndices->push_back(VertexIndexCounter);
					++VertexIndexCounter;
				}
			}

		}

		return S_OK;
	}
	XMFLOAT2 ReadTextureUV(FbxMesh * fbxMesh, int ControlPointIndex, int VerTexCounter)
	{
		//�ؽ��� ��ǥ�� �ִ��� Ȯ��
		if (fbxMesh->GetElementUVCount() < 1)
		{
			//�ؽ��� ��ǥ�� ������ �� 0���� ����
			MessageBox(NULL, TEXT("�ؽ��� ��ǥ�� �����ϴ�."), TEXT("����"), MB_OK);
			return XMFLOAT2();
		}
		//��ȯ�� ����
		XMFLOAT2 TexCoord(0.0f, 0.0f);

		//�ؽ��� ��ǥ��ü �迭 �о����
		FbxGeometryElementUV* VerTexUV = fbxMesh->GetElementUV(0);

		//���� UV���� �о�� �ε��� ������
		int index = VerTexUV->GetIndexArray().GetAt(VerTexCounter);

		//�ؽ��� ��ǥ�� �о����
		TexCoord.x = static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[0]);
		//���̷�Ʈ ��ǥ�� ǥ�����ֱ� ���ؼ�
		//Fbx�� ���ʾƷ��� �������̶� �׷���
		//�ٷ��� �������� ���� ���̱� ������ �׷���
		TexCoord.y = 1.0f - static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[1]);

		//��ȯ
		return TexCoord;
		//���� ����� Ȯ���Ѵ�.
	//	const bool isUsingIndex = VerTexUV->GetReferenceMode() != FbxGeometryElement::eDirect;
	//    const int IndexCount = isUsingIndex ? VerTexUV->GetIndexArray().GetCount() : 0;

	//	//���� ��� Ȯ��
	//	switch (VerTexUV->GetMappingMode())
	//	{
	//		//���� ������ ������(Control Point) ������ ���
	//	    case FbxGeometryElement::eByControlPoint:
	//		{
	//			//���� UV���� �о�� �ε��� ������
	//			int index = isUsingIndex ? VerTexUV->GetIndexArray().GetAt(ControlPointIndex) : ControlPointIndex;

	//			//�ؽ��� ��ǥ�� �о����
	//			TexCoord.x = static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[0]);
	//			//���̷�Ʈ ��ǥ�� ǥ�����ֱ� ���ؼ�
	//			//Fbx�� ���ʾƷ��� �������̶� �׷���
	//			//�ٷ��� �������� ���� ���̱� ������ �׷���
	//			TexCoord.y = 1.0f - static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[1]);
	//			
	//			//��ȯ
	//			return TexCoord;
	//		}
	//		//�ٸ� ��ȯ��
	//		case FbxGeometryElement::eByPolygonVertex:
	//		{
	//			//���� UV���� �о�� �ε��� ������
	//			int index = isUsingIndex ? VerTexUV->GetIndexArray().GetAt(VerTexCounter) : VerTexCounter;

	//			//�ؽ��� ��ǥ�� �о����
	//			TexCoord.x = static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[0]);
	//			//���̷�Ʈ ��ǥ�� ǥ�����ֱ� ���ؼ�
	//			//Fbx�� ���ʾƷ��� �������̶� �׷���
	//			//�ٷ��� �������� ���� ���̱� ������ �׷���
	//			TexCoord.y = 1.0f - static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[1]);

	//			//��ȯ
	//			return TexCoord;
	//		}
	//		default:
	//		{
	//			MessageBox(NULL, TEXT("�ؽ��� ��ǥ���� ��ȿ���� �ʽ��ϴ�."), TEXT("����"), MB_OK);
	//			return XMFLOAT2();
	//		}
	//	}

	//	return XMFLOAT2();
	//}
	}
	XMFLOAT3 ReadNormal(FbxMesh * fbxMesh, int ControlPointIndex, int VerTexCounter)
	{
		//�ؽ��� ��ǥ�� �ִ��� Ȯ��
		if (fbxMesh->GetElementNormalCount() < 1)
		{
			//�ؽ��� ��ǥ�� ������ �� 0���� ����
			MessageBox(NULL, TEXT("����� �����ϴ�."), TEXT("����"), MB_OK);
			return XMFLOAT3();
		}
		//��ȯ�� ����
		XMFLOAT3 Normal(0.0f, 0.0f, 0.0f);

		//�ؽ��� ��ǥ��ü �迭 �о����
		FbxGeometryElementNormal* VerTexNormal = fbxMesh->GetElementNormal(0);

		//���� UV���� �о�� �ε��� ������
		int index = VerTexNormal->GetIndexArray().GetAt(VerTexCounter);

		//�ؽ��� ��ǥ�� �о����
		Normal.x = static_cast<float>(VerTexNormal->GetDirectArray().GetAt(index).mData[0]);
		//���̷�Ʈ ��ǥ�� ǥ�����ֱ� ���ؼ�
		//Fbx�� ���ʾƷ��� �������̶� �׷���
		//�ٷ��� �������� ���� ���̱� ������ �׷���
		Normal.y = 1.0f - static_cast<float>(VerTexNormal->GetDirectArray().GetAt(index).mData[1]);
		Normal.z = static_cast<float>(VerTexNormal->GetDirectArray().GetAt(index).mData[2]);

		//��ȯ
		return Normal;
	}
};