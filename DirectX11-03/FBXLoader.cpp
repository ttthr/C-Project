#include "FBXLoader.h"

namespace FBXLoader
{

	FbxManager* fbxManager;

	HRESULT LoadFBX(LPCSTR fileName, vector<Vertex>* outVertices, vector<DWORD>* outIndices)
	{
		//fbxManager가 생성이 안됐으면 생성하기
		if (fbxManager == NULL)
		{
			//SDK 매니저 생성
			fbxManager = FbxManager::Create();
			//매니저 초기화
			FbxIOSettings* ioSetting = FbxIOSettings::Create(fbxManager, IOSROOT);
			fbxManager->SetIOSettings(ioSetting);

		}
		//FbxGeometryConverter 생성
		FbxGeometryConverter GeometryConverter(fbxManager);
		FbxImporter* Importer = FbxImporter::Create(fbxManager, " ");
		FbxScene* fbxScene = FbxScene::Create(fbxManager, " "); // 씬 이름 있으면 세번째 인자 받아줘야함

		//임포터 초기화
		if (Importer->Initialize(fileName, -1, fbxManager->GetIOSettings()) == false)
		{
			return E_FAIL;
		}

		//3D 씬(장면) 임포트
		if (Importer->Import(fbxScene) == false)
		{
			return E_FAIL;
		}

		//FBX Node 읽기
		FbxNode* fbxRootNode = fbxScene->GetRootNode();
		if (fbxRootNode == NULL)
		{
			return E_FAIL;
		}
		//모델 폴리곤 기본 구조를 프리미티브로 설정
		GeometryConverter.Triangulate(fbxScene, true);


		// 루트 노의 하위 노드 개수 얻어오기
		int childCount = fbxRootNode->GetChildCount();

		for (int i = 0; i < childCount; ++i)
		{
			//자식 계층 노드 인덱스 얻어오기
			FbxNode* childNode = fbxRootNode->GetChild(i);

			//무슨 타입인지 확인 ( 속성 확인 )
			FbxNodeAttribute::EType attributeType;
			attributeType = childNode->GetNodeAttribute()->GetAttributeType();

			//메시 타입인지 확인
			if (attributeType != FbxNodeAttribute::EType::eMesh)
			{
				continue;
			}
			//메시 정보 읽어 오기
			FbxMesh* fbxMesh = childNode->GetMesh();

			//버텍스 배열 얻어오기( 정점 ) 
			FbxVector4* vertices = fbxMesh->GetControlPoints();

			//폴리곤 수 확인
			int PolyGonCount = fbxMesh->GetPolygonCount();

			//인덱스 설정용 변수
			int VertexIndexCounter = 0;

			//폴리곤 순회
			for (int i = 0; i < PolyGonCount; ++i)
			{
				//폴리곤을 구성하는 정점 개수 확인
				int VertexCount = fbxMesh->GetPolygonSize(i); //3개 여야함

				//폴리곤 안의 정점 순회( 3번 돌아야 정상)
				for (int j = 0; j < VertexCount; ++j)
				{
					//정점 순번 확인
					int VerTexIndex = fbxMesh->GetPolygonVertex(j, i);

					//정점 정보 읽어 오기
					Vertex vertex;
					vertex.xmPosition.x = static_cast<float>(vertices[VerTexIndex].mData[0]);
					vertex.xmPosition.y = static_cast<float>(vertices[VerTexIndex].mData[1]);
					vertex.xmPosition.z = static_cast<float>(vertices[VerTexIndex].mData[2]);

					//텍스쳐 좌표값 얻어오기
					vertex.xmUV = ReadTextureUV(fbxMesh, VerTexIndex, VertexIndexCounter);

					//노멀 값
					vertex.xmNormal = ReadNormal(fbxMesh, VerTexIndex, VertexIndexCounter);
					//정점 추가
					outVertices->push_back(vertex);

					//인덱스 추가
					outIndices->push_back(VertexIndexCounter);
					++VertexIndexCounter;
				}
			}

		}

		return S_OK;
	}
	XMFLOAT2 ReadTextureUV(FbxMesh * fbxMesh, int ControlPointIndex, int VerTexCounter)
	{
		//텍스쳐 좌표가 있는지 확인
		if (fbxMesh->GetElementUVCount() < 1)
		{
			//텍스쳐 좌표가 없으면 다 0으로 셋팅
			MessageBox(NULL, TEXT("텍스쳐 좌표가 없습니다."), TEXT("오류"), MB_OK);
			return XMFLOAT2();
		}
		//변환용 변수
		XMFLOAT2 TexCoord(0.0f, 0.0f);

		//텍스쳐 좌표전체 배열 읽어오기
		FbxGeometryElementUV* VerTexUV = fbxMesh->GetElementUV(0);

		//현재 UV값을 읽어올 인덱스 얻어오기
		int index = VerTexUV->GetIndexArray().GetAt(VerTexCounter);

		//텍스쳐 좌표값 읽어오기
		TexCoord.x = static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[0]);
		//다이렉트 좌표로 표현해주기 위해서
		//Fbx가 왼쪽아래가 기준점이라서 그런것
		//다렉의 기준점은 왼쪽 위이기 때문에 그런것
		TexCoord.y = 1.0f - static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[1]);

		//반환
		return TexCoord;
		//참조 방법을 확인한다.
	//	const bool isUsingIndex = VerTexUV->GetReferenceMode() != FbxGeometryElement::eDirect;
	//    const int IndexCount = isUsingIndex ? VerTexUV->GetIndexArray().GetCount() : 0;

	//	//매핑 모드 확인
	//	switch (VerTexUV->GetMappingMode())
	//	{
	//		//현재 정점이 제어점(Control Point) 유형인 경우
	//	    case FbxGeometryElement::eByControlPoint:
	//		{
	//			//현재 UV값을 읽어올 인덱스 얻어오기
	//			int index = isUsingIndex ? VerTexUV->GetIndexArray().GetAt(ControlPointIndex) : ControlPointIndex;

	//			//텍스쳐 좌표값 읽어오기
	//			TexCoord.x = static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[0]);
	//			//다이렉트 좌표로 표현해주기 위해서
	//			//Fbx가 왼쪽아래가 기준점이라서 그런것
	//			//다렉의 기준점은 왼쪽 위이기 때문에 그런것
	//			TexCoord.y = 1.0f - static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[1]);
	//			
	//			//반환
	//			return TexCoord;
	//		}
	//		//다른 반환형
	//		case FbxGeometryElement::eByPolygonVertex:
	//		{
	//			//현재 UV값을 읽어올 인덱스 얻어오기
	//			int index = isUsingIndex ? VerTexUV->GetIndexArray().GetAt(VerTexCounter) : VerTexCounter;

	//			//텍스쳐 좌표값 읽어오기
	//			TexCoord.x = static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[0]);
	//			//다이렉트 좌표로 표현해주기 위해서
	//			//Fbx가 왼쪽아래가 기준점이라서 그런것
	//			//다렉의 기준점은 왼쪽 위이기 때문에 그런것
	//			TexCoord.y = 1.0f - static_cast<float>(VerTexUV->GetDirectArray().GetAt(index).mData[1]);

	//			//반환
	//			return TexCoord;
	//		}
	//		default:
	//		{
	//			MessageBox(NULL, TEXT("텍스쳐 좌표값이 유효하지 않습니다."), TEXT("오류"), MB_OK);
	//			return XMFLOAT2();
	//		}
	//	}

	//	return XMFLOAT2();
	//}
	}
	XMFLOAT3 ReadNormal(FbxMesh * fbxMesh, int ControlPointIndex, int VerTexCounter)
	{
		//텍스쳐 좌표가 있는지 확인
		if (fbxMesh->GetElementNormalCount() < 1)
		{
			//텍스쳐 좌표가 없으면 다 0으로 셋팅
			MessageBox(NULL, TEXT("노멀이 없습니다."), TEXT("오류"), MB_OK);
			return XMFLOAT3();
		}
		//변환용 변수
		XMFLOAT3 Normal(0.0f, 0.0f, 0.0f);

		//텍스쳐 좌표전체 배열 읽어오기
		FbxGeometryElementNormal* VerTexNormal = fbxMesh->GetElementNormal(0);

		//현재 UV값을 읽어올 인덱스 얻어오기
		int index = VerTexNormal->GetIndexArray().GetAt(VerTexCounter);

		//텍스쳐 좌표값 읽어오기
		Normal.x = static_cast<float>(VerTexNormal->GetDirectArray().GetAt(index).mData[0]);
		//다이렉트 좌표로 표현해주기 위해서
		//Fbx가 왼쪽아래가 기준점이라서 그런것
		//다렉의 기준점은 왼쪽 위이기 때문에 그런것
		Normal.y = 1.0f - static_cast<float>(VerTexNormal->GetDirectArray().GetAt(index).mData[1]);
		Normal.z = static_cast<float>(VerTexNormal->GetDirectArray().GetAt(index).mData[2]);

		//반환
		return Normal;
	}
};