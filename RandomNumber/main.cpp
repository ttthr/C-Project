#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long uint64;

int main()
{
	//cout << sizeof(uint64);
	vector<uint64> Storage;
	vector<uint64> NPOTStorage;
	int N = 0;
	uint64 X = 0;
	cin >> N;

	//ют╥б
	for (int i = 0; i < N; ++i)
	{
		cin >> X;
		Storage.push_back(X);
	}


	for (int count = 0; count < N; ++count)
	{
		//NPOT
		uint64 Temp = 1;
		for (int i = 0; i < 64; ++i)
		{
			Temp = (uint64)(1ULL << i);

			if (Temp >= Storage[count])
			{
				NPOTStorage.push_back(Temp);
				break;
			}
		}
	}

	uint64 Result = NPOTStorage[0];
	for (unsigned int i = 1; i < NPOTStorage.size(); ++i)
	{
		//cout << NPOTStorage[i] << " ^ ";
		Result ^= NPOTStorage[i];
	}
	cout << Result << endl;

	return 0;
}
