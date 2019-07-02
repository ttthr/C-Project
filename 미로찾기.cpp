#include<iostream>
#include<queue>
#include<stack>
using namespace std;

#define way 0
#define max 5
#define level 10

class position
{
public:
	position() : x(0), y(0) { }
	position(int _x ,int _y) : x(_x), y(_y){}
	~position() {}
public:
	int x;
	int y;
public:
	int getx() { return x; }
	int gety() { return y; }
	position operator+(const position& rhs)
	{
		position result;
		result.x = this->x + rhs.x;
		result.y = this->y + rhs.y;

		return result;
	}
	position operator+(const int& rhs)
	{
		position result;
		result.x = this->x + rhs;

		return result;
	}
};


enum class direction
{
	right = 0,
	down = 1,
	left = 2,
	up = 3
};

//±âº» ¸Ê
//{0, 1, 1, 1, 0},
//{ 0, 0, 0, 0, 0 },
//{ 1, 0, 1, 1, 1 },
//{ 1, 0, 1, 1, 1 },
//{ 1, 0, 0, 0, 0 }

//È®ÀÎ¿ë ¸Ê 7 x 7 
//{0, 1, 1, 1, 0, 1, 0},
//{ 0, 0, 0, 0, 0, 0, 0 },
//{ 1, 0, 1, 1, 1, 1, 0 },
//{ 1, 0, 1, 1, 1, 1, 0 },
//{ 1, 0, 1, 1, 0, 1, 0 },
//{ 1, 0, 0, 0, 1, 0, 0 },
//{ 1, 0, 1, 0, 0, 0, 0 }

int	maze[max][max] =
{
	{ 0, 1, 1, 1, 0 },
	{ 0, 0, 0, 0, 0 },
	{ 1, 0, 1, 1, 1 },
	{ 1, 0, 1, 1, 1 },
	{ 1, 0, 0, 0, 0 }
};
int trace_maze[max][max]{ 1,};
int result_maze[max][max]{ 1, };
position Dir[4];
int maxlevel = 0;
int mylevel = 0;
int ResultLevel = 0;
int TempResultLevel = 0;

bool Resulttrace(position& _traceposition, int _level)
{
	if (_traceposition.x < 0 || _traceposition.y < 0 || _traceposition.x > max - 1 || _traceposition.y > max - 1)
	{
		return false;
	}

	if (result_maze[_traceposition.y][_traceposition.x] == _level)
	{
		if (TempResultLevel == _level)
		{
			return false;
		}
		return true;

	}

	return false;
}
bool trace(position& _traceposition, int _level)
{

	if (_traceposition.x < 0 || _traceposition.y < 0 || _traceposition.x > max - 1 || _traceposition.y > max - 1)
	{
		

		return false;
	}

	if (maze[_traceposition.y][_traceposition.x] == _level)
	{
		result_maze[_traceposition.y][_traceposition.x] = maze[_traceposition.y][_traceposition.x];
		return true;

	}

	return false;
}

void initailzedirection()
{
	Dir[static_cast<int>(direction::right)].x = 1;
	Dir[(int)direction::right].y = 0;

	Dir[(int)direction::down].x = 0;
	Dir[(int)direction::down].y = 1;

	Dir[(int)direction::left].x = -1;
	Dir[(int)direction::left].y = 0;

	Dir[(int)direction::up].x = 0;
	Dir[(int)direction::up].y = -1;
}	
void printnomalmap()
{
	cout << "¸Ê ·»´õ" << endl;
	//¸Ê ·»´õ
	for (int y = 0; y < max; ++y)
	{
		for (int x = 0; x < max; ++x)
		{
			cout << maze[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void searchqueue()
{
	queue<position> my_queue;
	position currentpos, temppos;
	my_queue.push(currentpos);
	maze[currentpos.y][currentpos.x] = level;

	while (!my_queue.empty())
	{
		currentpos = my_queue.front();
		my_queue.pop();

		mylevel = maze[currentpos.y][currentpos.x];

		for (int dir = (int)direction::right; dir <= (int)direction::up; ++dir)
		{

			temppos = currentpos + Dir[dir];

			if (temppos.x < 0 || temppos.y < 0 || temppos.x > max - 1 || temppos.y > max - 1)
			{
				break;
			}
			if (maze[temppos.y][temppos.x] == way)
			{
				maze[temppos.y][temppos.x] = mylevel + 1;
				my_queue.push(temppos);
			
				
			}

			if (temppos.x == max - 1 && temppos.y == max - 1)
			{
				TempResultLevel = maze[temppos.y][temppos.x];
				break;
			}

		}
	}
}
void traceway()
{
	position tracepos(max - 1, max -1);
	position tracenext;
	vector<int> my_vector;
	while (true)
	{
	

		maxlevel = maze[tracepos.y][tracepos.x];
	
		if (tracepos.x == 0 && tracepos.y == 0)
		{
			cout << "(0,0)";
			break;
		}
		

		for (int dir = (int)direction::right; dir <= (int)direction::up; ++dir)
		{

			tracenext = tracepos + Dir[dir];
			
			if (trace_maze[tracepos.y][tracepos.x] == way)
			{
	
				if(trace(tracenext, maxlevel - 1))
				{
					tracepos = tracenext;
					
				}
			
			}
		
		}
	
	}

	cout << endl;
}

void ResultWay()
{
	position tracepos(0, 0);
	position tracenext;

	while (true)
	{
		ResultLevel = result_maze[tracepos.y][tracepos.x];
		
		for (int dir = (int)direction::right; dir <= (int)direction::up; ++dir)
		{
			if (result_maze[tracepos.y][tracepos.x] != way)
			{
				tracenext = tracepos + Dir[dir];
				if (Resulttrace(tracenext, ResultLevel + 1))
				{
					tracepos = tracenext;
					cout << "(" << tracepos.x << "," << tracepos.y << ")" << endl;
				

				} 
			}
		}
		if (tracepos.x == max - 2 && tracepos.y == max - 1)
		{
			cout << "(" << tracepos.x + 1 << "," << tracepos.y << ")" << endl;
			cout << "Å»Ãâ ¼º°ø ³¡~" << endl;
			break;
		}
	}

}

void printresultmap()
{
	cout << endl;

	cout << "ÃÖ´Ü °æ·Î ¸Ê ·»´õ" << endl;

	for (int y = 0; y < max; ++y)
	{
		for (int x = 0; x < max; ++x)
		{
			cout << maze[y][x] <<" ";
		}

		cout << endl;
	}
}
int main()
{
	
	initailzedirection(); //¹æÇâ Å½»ö ÃÊ±âÈ­
	printnomalmap();      //ÀÏ¹Ý ¸Ê ·»´õ
	searchqueue();        //Å¥·Î ÃÖ´Ü°Å¸® Å½»ö
	traceway();           //ÃÖ´Ü °Å¸® °æ·Î ±¸ÇÏ±â
	ResultWay();          //ÃÖ´Ü °Å¸® ÁÂÇ¥·Î »Ì±â
	printresultmap();     //ÃÖÁ¾ ¸Ê ·»´õ
	
	return 0;             //ÇÁ·Î±×·¥ Á¾·á
}
