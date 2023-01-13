//
// Created by 16523 on 2022/11/18.
//

#include "nogo_func.h"
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
//ȫ�ֱ�������

//һЩ�����Ķ���

//�浵


void saveData()
{
	IMAGE box_qsave;
	loadimage(&box_qsave, L"./material/box/box_qsave.jpg", 440, 233);
	putimage(420, 240, &box_qsave);
	while (1)
	{
		ExMessage msg_qsave;
		msg_qsave = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i < ExitBtnNum; i++)
		{
			isStoppedFlag_exit[i] = (msg_qsave.x >= exitbtn_x[i][0] && msg_qsave.x <= exitbtn_x[i][1]
				&& msg_qsave.y >= exitbtn_y[i][0] && msg_qsave.y <= exitbtn_y[i][1]);
		}
		switch (msg_qsave.message)
		{
		case WM_MOUSEMOVE:
			{
				if (isStoppedFlag_exit[0])
				{
					IMAGE box_qsave_yesclk;
					loadimage(&box_qsave_yesclk, L"./material/box/box_qsave_yesclk.jpg", 440, 233);
					putimage(420, 240, &box_qsave_yesclk);
					break;
				}
				else if (isStoppedFlag_exit[1])
				{
					IMAGE box_qsave_noclk;
					loadimage(&box_qsave_noclk, L"./material/box/box_qsave_noclk.jpg", 440, 233);
					putimage(420, 240, &box_qsave_noclk);
					break;
				}
				else
				{
					IMAGE box_qsave;
					loadimage(&box_qsave, L"./material/box/box_qsave.jpg", 440, 233);
					putimage(420, 240, &box_qsave);
					break;
				}
			}
		case WM_LBUTTONDOWN:
			{
				if (isStoppedFlag_exit[0])
				{
					goto qsave;
				}
				else if (isStoppedFlag_exit[1])
				{
					cleardevice();
					opening();
					break;
				}
			}
		}
	}
qsave:
	//���������
	ifstream ifs;
	ofstream ofs;
	//�򿪴浵�ļ�
	ofs.open("./material/text/savedata.txt", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cerr << "�浵�ļ���ʧ�ܣ�\n";
		return;
	}
	//д��浵�ļ�
	ofs << systemTime() << ',';
	ofs << humanColor << ',';
	ofs << steps << ',';
	ofs << whoWins << ',';
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			ofs << position[i][j] << ' ';
		}
		ofs << ',';
	}
	ofs << "END" << ',';
	ofs << endl;
	//�رմ浵�ļ�
	ofs.close();
	cout << "qsavesuccess" << endl;
	cleardevice();
	ingame();
}


//����
void loadData()
{
	IMAGE box_qload;
	loadimage(&box_qload, L"./material/box/box_qload.jpg", 440, 233);
	putimage(420, 240, &box_qload);
	while (1)
	{
		ExMessage msg_qload;
		msg_qload = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i < ExitBtnNum; i++)
		{
			isStoppedFlag_exit[i] = (msg_qload.x >= exitbtn_x[i][0] && msg_qload.x <= exitbtn_x[i][1]
				&& msg_qload.y >= exitbtn_y[i][0] && msg_qload.y <= exitbtn_y[i][1]);
		}
		switch (msg_qload.message)
		{
		case WM_MOUSEMOVE:
			{
				if (isStoppedFlag_exit[0])
				{
					IMAGE box_qload_yesclk;
					loadimage(&box_qload_yesclk, L"./material/box/box_qload_yesclk.jpg", 440, 233);
					putimage(420, 240, &box_qload_yesclk);
					break;
				}
				else if (isStoppedFlag_exit[1])
				{
					IMAGE box_qload_noclk;
					loadimage(&box_qload_noclk, L"./material/box/box_qload_noclk.jpg", 440, 233);
					putimage(420, 240, &box_qload_noclk);
					break;
				}
				else
				{
					IMAGE box_qload;
					loadimage(&box_qload, L"./material/box/box_qload.jpg", 440, 233);
					putimage(420, 240, &box_qload);
					break;
				}
			}
		case WM_LBUTTONDOWN:
			{
				if (isStoppedFlag_exit[0])
				{
					goto qload;
				}
				else if (isStoppedFlag_exit[1])
				{
					cleardevice();
					opening();
					break;
				}
			}
		}
	}
qload:
	ifstream ifs;
	ofstream ofs;
	//�򿪴浵�ļ�
	ifs.open("./material/text/savedata.txt", ios::in);
	//����浵�ļ��������ַ�����
	string buf;
	bool flag = false;
	while (getline(ifs, buf))
	{
		if (buf[0] == 'P')
			continue;
		else
		{
			/*buf.erase(0, start);
			int end = buf.find_first_of("END");
			int backLen = buf.length() - (end + 1);
			buf.erase(end, backLen);*/

			//��ʼ��ȡ

			/*//�����û����
			int next_comma = buf.find_first_of(",");
			buf.erase(0, next_comma + 1);*/

			/*//�����û�����
			next_comma = buf.find_first_of(",");
			buf.erase(0, next_comma + 1);*/

			//�����û���һ�����ʱ��
			int next_comma = buf.find_first_of(",");
			PreviousTime = buf.substr(0, next_comma);
			next_comma = buf.find_first_of(",");
			buf.erase(0, next_comma + 1);

			//�����û���ִ��ɫ
			humanColor = stoi(buf.substr(0, 1));
			buf.erase(0, 2);
			AIColor = (1 - humanColor);
			//�����û�Ŀǰ����
			next_comma = buf.find_first_of(",");
			steps = stoi(buf.substr(0, next_comma));
			buf.erase(0, next_comma + 1);

			//�������Ŀǰ��ʤ��״̬
			next_comma = buf.find_first_of(",");
			whoWins = stoi(buf.substr(0, next_comma));
			buf.erase(0, next_comma + 1);

			//�������̾������
			for (int i = 1; i <= 9; i++)
			{
				for (int j = 1; j <= 9; j++)
				{
					int next_space = buf.find_first_of(' ');
					position[i][j] = stoi(buf.substr(0, next_space + 1));
					buf.erase(0, next_space + 1);
				}
				buf.erase(0, 1);
			}
		}
	}
	cout << "qloadsuccess" << endl;
	cleardevice();
	ingame();
	return;
}


//���̶�ȡʵ����ͣ�ͷ��ز˵�ҳ��
void getKeyboardInstruction(void)
{
	/*if (kbhit()) {
		if (getch() == EXIT) {
			cout << "��ѡ�����˳�������Ϊ���浵��\n";
			saveData(userNum);
			_sleep(10000);
			system("cls");
			exit(0);
		}
		else if (getch() == PAUSE) {
			cout << "��Ϸ�Ѿ���ͣ������Ϊ���浵��\n";
			saveData(userNum);
			_sleep(100000);
		}
		else if (getch() == HELP) {
			cout << "����Ϊ���򿪰����ĵ���" << endl;
			openHelpFile();
		}
	}*/
}

//���������
int randSelectQuestion(int from, int to)
{
	//��from��to��֮��ѡ��һ������
	srand((unsigned)time(NULL));
	int span = 0;
	if (to > from)
	{
		span = to - from;
		return from + rand() % span;
	}
	else
	{
		span = from - to;
		return to + rand() % span;
	}
}

//���ϵͳ����
string systemTime(void)
{
	time_t timep;
	time(&timep);
	char tmp[64];
	struct tm nowTime;
	localtime_s(&nowTime, &timep);
	strftime(tmp, sizeof(tmp), "%Y-%m-%d-%H:%M:%S", &nowTime);
	return std::string(tmp);


	/*time_t now = time(0);
	tm* ltm = localtime(&now);
	string timeString = to_string(1900 + ltm->tm_year) + "-"
		+ to_string(1 + ltm->tm_mon) + "-"
		+ to_string(ltm->tm_mday) + " "
		+ to_string(ltm->tm_hour) + ":"
		+ to_string(ltm->tm_min) + ":"
		+ to_string(ltm->tm_sec);
	PreviousTime = timeString;
	return timeString;*/
}

//�Ϸ��Գ�ʼ��
void initialize(bool isLoadedData)
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (i == 0 || i == 10 || j == 0 || j == 10)
			{
				isPositionLegal[i][j] = false;
			}
		}
	}
	//�Ϸ��Գ�ʼ��
	if (!isLoadedData)
	{
		steps = 1;
		memset(position, -1, sizeof(position));
		for (int i = 0; i <= 10; i++)
			for (int j = 0; j <= 10; j++)
			{
				if (i == 0 || i == 10)
					position[i][j] = -2;
				else if (j == 0 || j == 10)
					position[i][j] = -2;
			}
	}
	//�߽��ʼ��
	for (int i = 0; i <= 10; i++)
		for (int j = 0; j <= 10; j++)
		{
			if (i == 0 || i == 10)
			{
				chessarea_x[i][j][0] = 0;
				chessarea_x[i][j][1] = 0;
				chessarea_y[i][j][0] = 0;
				chessarea_y[i][j][1] = 0;
			}
			else if (j == 0 || j == 10)
			{
				chessarea_x[i][j][0] = 0;
				chessarea_x[i][j][1] = 0;
				chessarea_y[i][j][0] = 0;
				chessarea_y[i][j][1] = 0;
			}
			else
			{
				chessarea_x[i][j][0] = chessboard_x + (i - 1) * ChessDelim;
				chessarea_x[i][j][1] = chessboard_x + singleChess + (i - 1) * ChessDelim;
				chessarea_y[i][j][0] = chessboard_y + (j - 1) * ChessDelim;
				chessarea_y[i][j][1] = chessboard_y + singleChess + (j - 1) * ChessDelim;
			}
		}
	return;
}

//��ӡ���̡��
void printBoard(void)
{
	cleardevice();
	switch (theme)
	{
	case 0:
		{
			if (isPlayingflag)
			{
				IMAGE scene_bgmplay;
				loadimage(&scene_bgmplay, L"./material/scene/scene_bgmplay.jpg", 1280, 720);
				putimage(0, 0, &scene_bgmplay);
				break;
			}
			else
			{
				IMAGE scene_bgmstop;
				loadimage(&scene_bgmstop, L"./material/scene/scene_bgmstop.jpg", 1280, 720);
				putimage(0, 0, &scene_bgmstop);
				break;
			}
		}
	case 1:
		{
			if (isPlayingflag)
			{
				IMAGE scene_bgmplay_2;
				loadimage(&scene_bgmplay_2, L"./material/scene/scene_bgmplay_2.jpg", 1280, 720);
				putimage(0, 0, &scene_bgmplay_2);
				break;
			}
			else
			{
				IMAGE scene_bgmstop_2;
				loadimage(&scene_bgmstop_2, L"./material/scene/scene_bgmstop_2.jpg", 1280, 720);
				putimage(0, 0, &scene_bgmstop_2);
				break;
			}
		}
	}
	//��ӡ����
	IMAGE go_black;
	loadimage(&go_black, L"./material/go/go_black.jpg", 42, 42);
	IMAGE go_white;
	loadimage(&go_white, L"./material/go/go_white.jpg", 42, 42);
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			switch (position[i][j])
			{
			case -1:
				break;
			case 1: //black
				putimage(chessboard_x + ChessDelim * (i - 1), chessboard_y + ChessDelim * (j - 1), &go_black);
				break;
			case 0:
				putimage(chessboard_x + ChessDelim * (i - 1), chessboard_y + ChessDelim * (j - 1), &go_white);
				break;
			}
		}
	}
	/*Sleep(2000);*/

	//������Ϣ-����
	string vol_str = "";
	char text[20];
	vol_str += to_string(steps);
	strcpy_s(text, vol_str.c_str());
	USES_CONVERSION;
	wchar_t* wchar_temp = A2W(text);
	const wchar_t* wchar_text = wchar_temp;
	setbkmode(TRANSPARENT);
	settextcolor(BROWN);
	settextstyle(23, 0, L"����С���μ���");
	outtextxy(253, 16, wchar_text);

	//�Ѷ�
	switch (difficulty)
	{
	case 0:
		{
			setbkmode(TRANSPARENT);
			settextcolor(BROWN);
			settextstyle(24, 0, L"����С���μ���");
			outtextxy(378, 16, L"��");
			break;
		}
	case 1:
		{
			setbkmode(TRANSPARENT);
			settextcolor(BROWN);
			settextstyle(24, 0, L"����С���μ���");
			outtextxy(378, 16, L"�е�");
			break;
		}
	}
	//����
	string temp = "";
	temp += bgmName[bgmnum];
	char _text[50];
	strcpy_s(_text, temp.c_str());
	wchar_temp = A2W(_text);
	setbkmode(TRANSPARENT);
	settextstyle(21, 0, L"����С���μ���");
	outtextxy(960, 16, wchar_temp);
	return;
}

//���ӣ��飩��������

int Qi_onceCount(int x, int y)
{
	int singleQi = 0;
	for (int i = 0; i < 4; i++)
	{
		if (position[x + direction_x[i]][y + direction_y[i]] == -1)
		{
			singleQi++;
		}
	}
	return singleQi;
}

int Qi_count(int x, int y)
{
	marked[x][y] = true; //��ǣ���ʾ���λ���Ѿ��ѹ���������
	int Qi = 0;
	bool haveboarder = false; //�����̵ı߽紦
	int boarder = 0;
	for (int i = 0; i < 4; i++)
	{
		int x_dx = x + direction_x[i], y_dy = y + direction_y[i];
		if (position[x_dx][y_dy] != -2) //����
		{
			if (position[x_dx][y_dy] == -1) //�Ա����λ��û������
				Qi = 1;
			else if (position[x_dx][y_dy] == position[x][y] && !marked[x_dx][y_dy]) //�Ա����λ����û����������ͬɫ��
				if (Qi_count(x_dx, y_dy))
				{
					Qi = 1;
				}
		}
		else if (position[x_dx][y_dy] == -2)
		{
			haveboarder = true;
			break;
		}
	}
	if (haveboarder)
	{
		int empty = 0;
		for (int i = 0; i < 4; i++)
		{
			int x_dx = x + direction_x[i], y_dy = y + direction_y[i];
			if (position[x_dx][y_dy] == -1)
				empty++;
		}
		if (!empty) return 0;
		return 1;
	}
	return Qi;
	/*marked[x][y] = true;
	int CurrColor = position[x][y];
	int singleQi = 0;
	int NotCurrCount = 4 - singleQi;
	for (int i = 0; i < 4; i++)
	{
		if (position[x + direction_x[i]][y + direction_y[i]] == -1)
		{
			singleQi++;
		}
	}
	if (NotCurrCount == 3 || NotCurrCount == 4)
		return Qi_onceCount(x, y);
	else if (NotCurrCount == 2)
	{
		bool EndVal = true;//EndVal����������������յ�
		for (int i = 0; i < 4; i++)
		{
			if (position[x + direction_x[i]][y + direction_y[i]] == CurrColor &&
				!marked[x + direction_x[i]][y + direction_y[i]])
			{
				EndVal = false;
				break;
			}
		}
		if (EndVal)
		{
			return Qi_onceCount(x, y);
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				if (position[x + direction_x[i]][y + direction_y[i]] == CurrColor)
				{
					return singleQi + Qi_count(x + direction_x[i], y + direction_y[i]);
				}
			}
		}
	}*/
}

//�ж���Ӯ
int judge() //0-��ʱƽ�֣�1-ʤ����-1-ʧ�ܣ�
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j < 9; j++)
		{
			if (position[i][j] == humanColor)
				if (Qi_count(i, j) == 0)
				{
					//�ж��Ƿ���ɱ��
					//�ж��Ƿ��ڱ߽�
					bool isSurroundAllSame = true;
					int tempboarder[2][2] = {{-1, -1}, {-1, -1}};
					int boardercnt = 0;
					for (int k = 0; k < 4; k++)
					{
						if (position[i + direction_x[k]][j + direction_y[k]] == -2)
						{
							tempboarder[boardercnt][0] = i + direction_x[k];
							tempboarder[boardercnt][1] = j + direction_y[k];
							boardercnt++;
						}
					}
					if (!boardercnt)
					{
						for (int k = 0; k < 4; k++)
						{
							if (position[i][j] != position[i + direction_x[k]][j + direction_y[k]])
							{
								isSurroundAllSame = false;
								break;
							}
						}
					}
					else if (boardercnt)
					{
						for (int k = 0; k < 4; k++)
						{
							if ((tempboarder[0][0] == i + direction_x[k]
									&& tempboarder[0][1] == j + direction_y[k])
								|| (tempboarder[1][0] == i + direction_x[k]
									&& tempboarder[1][1] == j + direction_y[k]))
							{
								continue;
							}
							if (position[i][j] != position[i + direction_x[k]][j + direction_y[k]])
							{
								isSurroundAllSame = false;
								break;
							}
						}
					}


					if (isSurroundAllSame)
					{
						return 1; //����ɱ��AIӮ
					}
					else if (!isSurroundAllSame)
					{
						return -1;
					} //AI����
				}
			if (position[i][j] == AIColor)
			{
				if (Qi_count(i, j) == 0)
				{
					bool isSurroundAllSame = true;
					for (int k = 0; k < 4; k++)
					{
						if (position[i][j] != position[i + direction_x[k]][j + direction_y[k]])
						{
							isSurroundAllSame = false;
							break;
						}
					}
					if (isSurroundAllSame)
					{
						return -1; //AI��ɱ����Ӯ
					}
					else if (!isSurroundAllSame)
					{
						return 1; //����
					}
				}
			}
		}
	return 0;
};
/*bool isLegal(int x, int y, int color)
{
	if (position[x][y] == -1) {
		position[x][y] = color;
		memset(visitedExceptQi, 0x00, sizeof(visitedExceptQi)); //����

		if (Qi_count(x, y) == 0) //��������ⲽ�����û����,˵������ɱ����������
		{
			position[x][y] = -1;
			return false;
		}

		for (int i = 0; i < 4; i++) //�ж������ⲽ��Χλ�õ������Ƿ�����
		{
			int x_dx = x + dx[i], y_dy = y + dy[i];
			if (inBoard_judge(x_dx, y_dy)) //��������
			{
				if (board[x_dx][y_dy] && !visited_by_air_judge[x_dx][y_dy]) //���������ӵ�λ�ã���Ƿ��ʹ�������ѭ����
					if (!air_judge(x_dx, y_dy))                             //�������(x_dx,y_dy)û���ˣ�������
					{
						board[x][y] = 0; //����
						return false;
					}
			}
		}
		board[x][y] = 0; //����
		return true;
	}
	else return false;//λ���ϱ����������ӻ����Ǳ߽�
}*/

//��һ��bot���ߵĺϷ��ش�̽��
void exceptNoQi()
{
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			if (position[i][j] == 1 || position[i][j] == 0)
			{
				isPositionLegal[i][j] = false;
				continue;
			}
			else if (position[i][j] == -1)
			{
				bool haveHumanChess = false;
				bool allEmptyChess = true;
				for (int k = 0; k < 4; k++)
				{
					if (position[i + direction_x[k]][j + direction_y[k]] == humanColor)
					{
						haveHumanChess = true;
						break;
					}
					else if (position[i + direction_x[k]][j + direction_y[k]] == -2)
					{
						allEmptyChess = false;
						break;
					}
				}
				if (!haveHumanChess && allEmptyChess) //�����Χȫ�ǿ�λ��λ���ǺϷ���
				{
					isPositionLegal[i][j] = true;
					continue;
				}
				else //�����Χ�жԷ����ӻ򼺷����ӣ������ж���������(�����öԷ�������
				{
					int tempColor = position[i][j];
					position[i][j] = AIColor;
					if (Qi_count(i, j) == 0)
					{
						isPositionLegal[i][j] = false;
					}
					else isPositionLegal[i][j] = true;
					position[i][j] = tempColor;
				}
			}
		}
}

//�ж�ĳ���ض�λ���Ƿ����
bool isLegal(int x, int y, int color)
{
	if (position[x][y] == 1 || position[x][y] == 0) //�������㱾����������
		return false;
	position[x][y] = color;
	memset(marked, 0, sizeof(marked)); //����

	if (!Qi_count(x, y)) //��������ⲽ�����û����,˵������ɱ����������
	{
		position[x][y] = -1;
		return false;
	}

	for (int i = 0; i < 4; i++) //�ж������ⲽ��Χλ�õ������Ƿ�����
	{
		int x_dx = x + direction_x[i], y_dy = y + direction_y[i];
		if (position[x_dx][y_dy] != -2) //��������
		{
			if (position[x_dx][y_dy] && !marked[x_dx][y_dy]) //���������ӵ�λ�ã���Ƿ��ʹ�������ѭ����
				if (!Qi_count(x_dx, y_dy)) //�������(x_dx,y_dy)û���ˣ�������
				{
					position[x][y] = -1; //����
					return false;
				}
		}
	}
	position[x][y] = -1; //����
	return true;
}

void humanselect() //��ֿ�ʼʱ��ѡ��
{
begin:
	cout << "��ѡ�������Լ�ѡ��"
		"��ִ�����밴1����ִ�����밴0��\n"
		"��ע�⣬ִ���ӵ�һ���޷�����������Ԫ����\n";
	cin >> humanColor;
	if (humanColor == 1)
	{
		AIColor = 0;
	}
	else AIColor = 1;
	switch (humanColor)
	{
	case 0:
		cout << "��ѡ����ǰ�ɫ��\n";
		break;
	case 1:
		cout << "��ѡ����Ǻ�ɫ��\n";
		break;
	default:
		cerr << "�������벻�Ϸ������������롣\n";
		goto begin;
	}
}

void humanturn() // ������ʱ�Ĳ���
{
begin1:
	exceptNoQi();
	cout << "�ⲽ�ǵ�" << steps << "����";
	cout << "���������ˡ�\n����������Ҫ��������꣨x,y)��\n";
	cout << "����1 <= x <= 9��1 <= y <= 9��\n";
	char comma;
	cin >> recentInstruction_x[steps] >> comma >> recentInstruction_y[steps];
	if (recentInstruction_x[steps] >= 1 && recentInstruction_x[steps] <= 9
		&& recentInstruction_y[steps] >= 1 && recentInstruction_y[steps] <= 9
		&& isPositionLegal[recentInstruction_x[steps]][recentInstruction_y[steps]])
	{
		position[recentInstruction_x[steps]][recentInstruction_y[steps]] = humanColor;
		steps++;
		return;
	}
	else
	{
		recentInstruction_x[steps] = 0;
		recentInstruction_y[steps] = 0;
		cerr << "�������벻�Ϸ������������롣";
		goto begin1;
	}
}

void humanturn_GUI()
{
	while (1)
	{
		ExMessage msg_play;
		msg_play = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i <= 10; i++)
		{
			for (int j = 0; j <= 10; j++)
			{
				isStoppedflag_chess[i][j] =
				(msg_play.x >= chessarea_x[i][j][0] &&
					msg_play.x <= chessarea_x[i][j][1] &&
					msg_play.y >= chessarea_y[i][j][0] &&
					msg_play.y <= chessarea_y[i][j][1]);
			}
		}
		for (int i = 0; i < InGameBtnNum; i++)
		{
			isStoppedflag_ingame[i] =
			(msg_play.x >= ingamebtn_x[i][0] &&
				msg_play.x <= ingamebtn_x[i][1] &&
				msg_play.y >= ingamebtn_y[i][0] &&
				msg_play.y <= ingamebtn_y[i][1]);
		}

		if (msg_play.message == WM_KEYDOWN)
		{
			if (msg_play.vkcode == VK_ESCAPE)
			{
				exit_m();
			}
		}
		if (msg_play.message == WM_LBUTTONDOWN)
		{
			if (isStoppedflag_ingame[0])
			{
				saveData();
			}
			else if (isStoppedflag_ingame[1])
			{
				loadData();
			}
			else if (isStoppedflag_ingame[2])
			{
				saveData(); //qsave
			}
			else if (isStoppedflag_ingame[3])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[4])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[5])
			{
				switch (isPlayingflag)
				{
				case true:
					{
						pauseMusic();
						isPlayingflag = false;
						cleardevice();
						IMAGE scene_bgmstop;
						loadimage(&scene_bgmstop, L"./material/scene/scene_bgmstop.jpg", 1280, 720);
						putimage(0, 0, &scene_bgmstop);
						printBoard();
						cout << "stop" << endl;
						break;
					}
				case false:
					{
						isPlayingflag = true;
						bkGndMusic(false);
						cleardevice();
						IMAGE scene_bgmplay;
						loadimage(&scene_bgmplay, L"./material/scene/scene_bgmplay.jpg", 1280, 720);
						putimage(0, 0, &scene_bgmplay);
						printBoard();
						break;
					}
				}
			}
			else if (isStoppedflag_ingame[6])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[7])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[8])
			{
				exit_m();
			}
			else if (isStoppedflag_ingame[9])
			{
				surrender();
			}
			else
			{
				for (int i = 1; i <= 9; i++)
					for (int j = 1; j <= 9; j++)
					{
						if (isStoppedflag_chess[i][j])
						{
							if (position[i][j] == -1)
							{
								position[i][j] = humanColor;
								cout << i << " " << j << endl;
								printBoard();
								return;
							}
						}
					}
			}
		}
	}
}

//bot����ʱ�Ĳ���
void AIturn(int mode) //bot����ʱ�Ĳ���
{
	if (mode == 0) //����·�
	{
		exceptNoQi();
	randFormation:
		int rand_x = randSelectQuestion(1, 9);
		Sleep(50);
		int rand_y = randSelectQuestion(1, 9);
		if (isPositionLegal[rand_x][rand_y])
		{
			cout << "�ⲽ�ǵ�" << steps << "����";
			recentInstruction_x[steps] = rand_x;
			recentInstruction_y[steps] = rand_y;
			steps++;
			position[rand_x][rand_y] = AIColor;
			cout << "�����bot���塣\nbot���ξ�����(" << rand_x << "," << rand_y << ")��\n";
			printBoard();
			return;
		}
		else goto randFormation;
	}
	else if (mode == 1) //̰���㷨
	{
		int start = clock();
		int timeout = (int)(0.9 * (double)CLOCKS_PER_SEC);
		int max_value = INT_MIN;
		int best_i[81] = {0}, best_j[81] = {0}, best_num = 0;
		memset(value, 0, sizeof(value));
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (isLegal(i, j, AIColor))
				{
					position[i][j] = AIColor;
					value[i][j] = evaluateFunc(AIColor);
					if (value[i][j] > max_value)
						max_value = value[i][j];
					position[i][j] = -1;
				}
				else
					value[i][j] = INT32_MIN;
				if (clock() - start > timeout)
					break;
			}
		}
		for (int i = 1; i <= 9; i++)
			for (int j = 1; j <= 9; j++)
				if (value[i][j] == max_value)
				{
					best_i[best_num] = i;
					best_j[best_num] = j;
					best_num++;
				}

		int random = rand() % best_num; //���������value�������ѡ
		position[best_i[random]][best_j[random]] = AIColor;
		printBoard();
		cout << "�ⲽ�ǵ�" << steps << "����";
		cout << "�����bot���塣\nbot���ξ�����(" << best_i[random] << "," << best_j[random] << ")��\n";
		return;
	}
}

//̰���㷨�Ĺ�ֵ����
int evaluateFunc(int color)
{
	int right = 0;
	int oppositeColor = abs(color - 1);
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (isLegal(i, j, color))
				right++;
			if (isLegal(i, j, oppositeColor))
				right--;
		}
	}
	return right;
}

//�����û����(
int getUserNum(void)
{
	ifstream ifs;
	ofstream ofs;
	ifs.open("./username.csv", ios::in);
	if (!ifs.is_open())
	{
		cerr << "�û������ļ���ʧ�ܣ�\n";
		exit(1);
	}
	string buf;
	int max_pervNum = 0;
	while (getline(ifs, buf))
	{
		if (buf == "username,number,")
		{
			continue; //���ж�ȡ
		}
		else
		{
			int last_comma = buf.find_last_of(",");
			string temp = buf.substr(last_comma - 1, 2);
			if (stoi(temp) > max_pervNum)
			{
				max_pervNum = stoi(temp);
			}
		}
	}
	return max_pervNum + 1;
}

//�ж��û��Ƿ�֮ǰ��¼�ڵ�
bool isUserInRecord(string name)
{
	ifstream ifs;
	ofstream ofs;
	ifs.open("./username.csv", ios::in);
	if (!ifs.is_open())
	{
		cerr << "�û������ļ���ʧ�ܣ�\n";
		return false;
	}
	//�����û�����
	string buf;
	while (getline(ifs, buf))
	{
		if (buf == "username,number,")
		{
			/*buf.erase(0, 16);//ɾ����username,number,��*/
			continue;
		}
		else
		{
			bool flag = false;
			if (!buf.size()) return false;
			else
			{
				int next_comma = buf.find_first_of(',');
				string name_temp = buf.substr(0, next_comma);
				if (name_temp == name)
				{
					flag = true;
					buf.erase(0, next_comma);
					next_comma = buf.find_first_of(',');
					int next_comma2 = buf.find_last_of(',');
					userNum = stoi(buf.substr(1, next_comma2 - next_comma - 1));
					return true;
				}
				else
				{
					continue;
				}
			}
			/*int userNumPosition = buf.find_last_of(",");
			userNumPosition += 1;
			string userNum_str = "";
			for (int i = userNumPosition; i < userNumPosition + 4; i++) {
				if (buf[i] <= '9' && buf[i] >= '0') {
					userNum_str += buf[i];
				} else break;
			}
			userNum = stoi(userNum_str);*/
			return false;
		}
	}
}

//���û������ĵ���д���û�����
void writeUsername(void)
{
	//���������
	ifstream ifs;
	ofstream ofs;
	//���û������ļ�
	ofs.open("./username.csv", ios::out | ios::app);
	if (!ofs.is_open())
	{
		cerr << "�û������ļ���ʧ�ܣ�\n";
		return;
	}
	//д��浵�ļ�
	ofs << username << "," << userNum << "," << endl;
	ofs.close();
}

//Ϊ�û��򿪰����ĵ�
void openHelpFile(void)
{
	ifstream ifs;
	ofstream ofs;

	//�򿪰����ļ�
	ifs.open("./material/text/help.txt", ios::in);
	if (!ifs.is_open())
	{
		cerr << "�ļ���ʧ�ܣ�\n";
		return;
	}
	//��ӡ�ļ��е�����
	char text[2048];
	while (ifs.getline(text, sizeof(text)))
	{
		cout << text << endl;
	}
	ifs.close();
}

void mainMenu(void)
{
	printf("��           Χ          ��\n");
	cout << "��������������������������������������������������������������������\n"
		<< "��                       ��\n";
	PreviousTime = systemTime();
	cout << "������" << PreviousTime << endl;
	cout << "��ӭ������Χ��Ver2.0��\n"
		<< "��������������:\n";
	cin >> username;
	cout << username << "�����á�";
	if (!isUserInRecord(username))
	{
		cout << "��⵽���ǵ�һ�ο�ʼ��Ϸ����Ϊ���Զ������浵��\n";
		userNum = getUserNum();
		writeUsername();
		saveData();
		newGame();
	}
	else
	{
	selectReplay:
		cout << "��֮ǰ�й���Ϸ�浵��\n";
		cout << "�������¿�ʼһ����Ϸ���������֮ǰδ��ɵ���Ϸ�浵��\n"
			<< "�����֮ǰ�Ĵ浵�밴1���뿪ʼ����Ϸ�밴2��";
		int readOrNew;
		cin >> readOrNew;
		switch (readOrNew)
		{
		case 1:
			loadData();
			break;
		case 2:
			newGame();
			break;
		default:
			system("cls");
			cerr << "�������벻�Ϸ������������롣";
			goto selectReplay;
		}

		/*cout << "���¼����ϵ��ض���ѡ��ģʽ��"
				"����Esc��-�˳���\n";
		cout << "����Alt��-�浵��\n";
		cout << "����Tab��-�鿴��Ϸ����\n";
		getKeyboardInstruction();*/
	}
}

void newGame(void)
{
selectRandom:
	cout << "����ִ���ӻ��ǰ��ӣ������ɳ������������\n"
		"ִ���ӽ��������塣\n"
		"��������ѡ���밴Y����������Լ�ѡ���밴N��\n";
	char isRandom;
	cin >> isRandom;
	switch (isRandom)
	{
	case 'N':
		humanselect();
		break;
	case 'Y':
		int randomNum = randSelectQuestion(0, 10000);
		if (randomNum % 2)
		{
			humanColor = 1;
			cout << "���ģ��Ľ��������ִ���ӡ������������塣\n";
		}
		else if (!randomNum % 2)
		{
			humanColor = 0;
			cout << "���ģ��Ľ��������ִ���ӡ������������塣\n";
		}
		break;
	}
}

void newGame_GUI(void)
{
}

//easyx���뷽ʽ
void mycout(const wchar_t* s, int begin_x, int begin_y, int fontsize)
{
	int x = begin_x, y = begin_y;
	for (unsigned int i = 0; i < wcslen(s); i++)
	{
		if (s[i] == L'\n')
			x = begin_x, y += 3 * textheight(L'A');
		else
		{
			int w = textwidth(s[i]);
			if (x + w > 1200)
			{
				x = begin_x, y += 2 * textheight(s[i]);
			}
			settextstyle(fontsize, 0, L"�����ƺ�_508R");
			outtextxy(x, y, s[i]);
			Sleep(0);
			x += w;
			if (x > 1220)
				x = begin_x, y += 3 * textheight(s[i]);
		}
	}
}

//��ʼ�˵����
void openingBkGnd()
{
	IMAGE opening;
	loadimage(&opening, L"./material/scene/opening.jpg", 1280, 720, true);
	putimage(0, 0, &opening);
}

void openingBtn()
{
	IMAGE btn_startgame;
	loadimage(&btn_startgame, L"./material/btn/btn_startgame.jpg", 240, 30);
	putimage(0, 345, &btn_startgame);
	IMAGE btn_loadgame;
	loadimage(&btn_loadgame, L"./material/btn/btn_loadgame.jpg", 240, 30);
	putimage(0, 415, &btn_loadgame);
	IMAGE btn_help;
	loadimage(&btn_help, L"./material/btn/btn_help.jpg", 240, 30);
	putimage(0, 485, &btn_help);
	IMAGE btn_settings;
	loadimage(&btn_settings, L"./material/btn/btn_settings.jpg", 240, 30);
	putimage(0, 555, &btn_settings);
	IMAGE btn_exit;
	loadimage(&btn_exit, L"./material/btn/btn_exit.jpg", 240, 30);
	putimage(0, 625, &btn_exit);
}

void opening()
{
	openingBkGnd();
	openingBtn();
	bkGndMusic(true);

	while (true)
	{
		//BGM

		if (isPlayingflag)
		{
			bkGndMusic(true);
		}
		else
		{
			IMAGE btn_bgmpause;
			loadimage(&btn_bgmpause, L"./material/btn/btn_bgmpause.jpg", 200, 40);
			putimage(1075, 8, &btn_bgmpause);
		}

		//

		ExMessage msg;
		msg = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i <= 9; i++)
		{
			isStoppedflag[i] = (msg.x >= btn_x[i][0] && msg.x <= btn_x[i][1] && msg.y >= btn_y[i][0] && msg.y <= btn_y[
				i][1]);
		}
		if (msg.message == WM_KEYDOWN)
		{
			if (msg.vkcode == VK_ESCAPE)
				exit_m();
		}
		if (msg.message == WM_LBUTTONDOWN)
		{
			if (isStoppedflag[0])
			{
				ingame();
			}
			if (isStoppedflag[1])
			{
				loadData();
				ingame();
			}
			if (isStoppedflag[2])
			{
				cleardevice();
				help();
			}
			if (isStoppedflag[3])
			{
				cleardevice();
				system_m();
			}
			if (isStoppedflag[4])
			{
				exit_m();
			}
			if (isStoppedflag[6])
			{
				switch (isPlayingflag)
				{
				case true:
					{
						isPlayingflag = false;
						bkGndMusic(true);
						IMAGE btn_bgmpause;
						loadimage(&btn_bgmpause, L"./material/btn/btn_bgmpause.jpg", 200, 40);
						putimage(1075, 8, &btn_bgmpause);
						cout << "stop" << endl;
						break;
					}
				case false:
					{
						isPlayingflag = true;
						bkGndMusic(false);
						IMAGE btn_bgmctrl;
						loadimage(&btn_bgmctrl, L"./material/btn/btn_bgmctrl.jpg", 200, 40);
						putimage(1075, 8, &btn_bgmctrl);
						break;
					}
				}
			}
		}
		if (msg.message == WM_MOUSEMOVE)
		{
			if (isStoppedflag[0])
			{
				IMAGE clk_startgame;
				loadimage(&clk_startgame, L"./material/btn/clk_startgame.jpg", 240, 30);
				putimage(0, btn_y[0][0], &clk_startgame);
			}
			else if (isStoppedflag[1])
			{
				IMAGE clk_loadgame;
				loadimage(&clk_loadgame, L"./material/btn/clk_loadgame.jpg", 240, 30);
				putimage(0, btn_y[1][0], &clk_loadgame);
			}
			else if (isStoppedflag[2])
			{
				IMAGE clk_help;
				loadimage(&clk_help, L"./material/btn/clk_help.jpg", 240, 30);
				putimage(0, btn_y[2][0], &clk_help);
			}
			else if (isStoppedflag[3])
			{
				IMAGE clk_settings;
				loadimage(&clk_settings, L"./material/btn/clk_settings.jpg", 240, 30);
				putimage(0, btn_y[3][0], &clk_settings);
			}
			else if (isStoppedflag[4])
			{
				IMAGE clk_exit;
				loadimage(&clk_exit, L"./material/btn/clk_exit.jpg", 240, 30);
				putimage(0, btn_y[4][0], &clk_exit);
			}
			else openingBtn();
		}
	}
}

//���Ʊ�������
void bkGndMusic(bool isOpening)
{
	if (isOpening)
	{
		IMAGE btn_bgmctrl;
		loadimage(&btn_bgmctrl, L"./material/btn/btn_bgmctrl.jpg", 200, 40);
		putimage(1075, 8, &btn_bgmctrl);
	}
	if (isPlayingflag)
	{
		switch (bgmnum)
		{
		case 1:
			{
				if (!notFirstPlay[1])
				{
					mciSendString(L"open ./material/music/Sympathy(Instrumental).mp3 alias BGM1", 0, 0, 0);
					mciSendString(L"play BGM1 repeat", 0, 0, 0);
					notFirstPlay[1] = true;
					break;
				}
				else
				{
					mciSendString(L"resume BGM1", 0, 0, 0);
					break;
				}
			}
		case 2:
			{
				if (!notFirstPlay[2])
				{
					mciSendString(L"open ./material/music/Sympathy(Quiet).mp3 alias BGM2", 0, 0, 0);
					mciSendString(L"play BGM2 repeat", 0, 0, 0);
					notFirstPlay[2] = true;
					break;
				}
				else
				{
					mciSendString(L"resume BGM2", 0, 0, 0);
					break;
				}
			}
		case 3:
			{
				if (!notFirstPlay[3])
				{
					mciSendString(L"open ./material/music/ꖤ��ޤ�Ц�(Instrumental).mp3 alias BGM3", 0, 0, 0);
					mciSendString(L"play BGM3 repeat", 0, 0, 0);
					notFirstPlay[3] = true;
					break;
				}
				else
				{
					mciSendString(L"resume BGM3", 0, 0, 0);
					break;
				}
			}
		case 4:
			{
				if (!notFirstPlay[4])
				{
					mciSendString(L"open ./material/music/SecretLabo(Instrumental).mp3 alias BGM4", 0, 0, 0);
					mciSendString(L"play BGM4 repeat", 0, 0, 0);
					notFirstPlay[4] = true;
					break;
				}
				else
				{
					mciSendString(L"resume BGM4", 0, 0, 0);
					break;
				}
			}
		case 5:
			{
				if (!notFirstPlay[5])
				{
					mciSendString(L"open ./material/music/PERFECTGIRL(Quiet).mp3 alias BGM5", 0, 0, 0);
					mciSendString(L"play BGM5 repeat", 0, 0, 0);
					notFirstPlay[5] = true;
					break;
				}
				else
				{
					mciSendString(L"resume BGM5", 0, 0, 0);
					break;
				}
			}
		case 6:
			{
				if (!notFirstPlay[6])
				{
					mciSendString(L"open ./material/music/�Ȥ����󤻡������L��(Instrumental).mp3 alias BGM6", 0, 0, 0);
					mciSendString(L"play BGM6 repeat", 0, 0, 0);
					notFirstPlay[6] = true;
					break;
				}
				else
				{
					mciSendString(L"resume BGM6", 0, 0, 0);
					break;
				}
			}
		case 7:
			{
				if (!notFirstPlay[7])
				{
					mciSendString(L"open ./material/music/�����䤫���ճ�.mp3 alias BGM7", 0, 0, 0);
					mciSendString(L"play BGM7 repeat", 0, 0, 0);
					notFirstPlay[7] = true;
					break;
				}
				else
				{
					mciSendString(L"resume BGM7", 0, 0, 0);
					break;
				}
			}
		case 8:
			{
				if (!notFirstPlay[8])
				{
					mciSendString(L"open ./material/music/Bluesky(Quiet).mp3 alias BGM8", 0, 0, 0);
					mciSendString(L"play BGM8 repeat", 0, 0, 0);
					notFirstPlay[8] = true;
					break;
				}
				else
				{
					mciSendString(L"resume BGM8", 0, 0, 0);
					break;
				}
			}
		}
	}
	else
	{
		switch (bgmnum)
		{
		case 1:
			{
				mciSendString(L"pause BGM1", 0, 0, 0);
				isPlayingflag = false;
				break;
			}
		case 2:
			{
				mciSendString(L"pause BGM2", 0, 0, 0);
				isPlayingflag = false;
				break;
			}
		case 3:
			{
				mciSendString(L"pause BGM3", 0, 0, 0);
				isPlayingflag = false;
				break;
			}
		case 4:
			{
				mciSendString(L"pause BGM4", 0, 0, 0);
				isPlayingflag = false;
				break;
			}
		case 5:
			{
				mciSendString(L"pause BGM5", 0, 0, 0);
				isPlayingflag = false;
				break;
			}
		case 6:
			{
				mciSendString(L"pause BGM6", 0, 0, 0);
				isPlayingflag = false;
				break;
			}
		case 7:
			{
				mciSendString(L"pause BGM7", 0, 0, 0);
				isPlayingflag = false;
				break;
			}
		case 8:
			{
				mciSendString(L"pause BGM8", 0, 0, 0);
				isPlayingflag = false;
				break;
			}
		}
	}
}

void pauseMusic()
{
	switch (bgmnum)
	{
	case 1:
		{
			mciSendString(L"pause BGM1", 0, 0, 0);
			isPlayingflag = false;
			break;
		}
	case 2:
		{
			mciSendString(L"pause BGM2", 0, 0, 0);
			isPlayingflag = false;
			break;
		}
	case 3:
		{
			mciSendString(L"pause BGM3", 0, 0, 0);
			isPlayingflag = false;
			break;
		}
	case 4:
		{
			mciSendString(L"pause BGM4", 0, 0, 0);
			isPlayingflag = false;
			break;
		}
	case 5:
		{
			mciSendString(L"pause BGM5", 0, 0, 0);
			isPlayingflag = false;
			break;
		}
	case 6:
		{
			mciSendString(L"pause BGM6", 0, 0, 0);
			isPlayingflag = false;
			break;
		}
	case 7:
		{
			mciSendString(L"pause BGM7", 0, 0, 0);
			isPlayingflag = false;
			break;
		}
	case 8:
		{
			mciSendString(L"pause BGM8", 0, 0, 0);
			isPlayingflag = false;
			break;
		}
	}
}

//����ҳ��
void help()
{
	settextcolor(WHITE);
	int mode = 1;
modechange:
	if (mode == 1)
	{
		IMAGE scene_help;
		loadimage(&scene_help, L"./material/scene/scene_help.jpg", 1280, 720);
		putimage(0, 0, &scene_help);
		//�����������
		setbkmode(TRANSPARENT);
		setfillcolor(WHITE);
		settextstyle(30, 0, _T("����С���μ���"));
		outtextxy(105, 16, L"������ع�");
		settextstyle(20, 0, _T("����С���μ���"));
		outtextxy(316, 43, L"����˵��");
		outtextxy(408, 43, L"��Ϸ����");
		outtextxy(500, 43, L"������Ϸ");
		settextstyle(20, 0, _T("�����ƺ�_508R"));
		/*wchar_t rule_text[] = "��Χ��Ĺ���";*/
		/*outtextxy(108, 136, _T(rule_text));*/
		mycout(L"��Χ��Ĺ���", 108, 136, 22);


		//���ļ���ȡ
		fstream ifs;
		ofstream ofs;

		//�򿪰����ļ� help.txt
		ifs.open("./material/text/help.txt", ios::in);
		if (!ifs.is_open())
		{
			cerr << "�ļ���ʧ�ܣ�\n";
			return;
		}
		//��ӡ�ļ��е�����
		string buf = "";
		int linecnt = 0;
		while (getline(ifs, buf))
		{
			char text[2048];
			buf += '\n';
			strcpy_s(text, buf.c_str());
			USES_CONVERSION;
			wchar_t* wchar_temp = A2W(text);
			const wchar_t* wchar_text = wchar_temp;
			mycout(wchar_text, 100, 185 + 15 * linecnt, 22);
			linecnt++;
		}
		ifs.close();
		while (1)
		{
			ExMessage msg_help;
			msg_help = getmessage(EX_MOUSE | EX_KEY);
			for (int i = 0; i <= HelpBtnNum - 1; i++)
			{
				isStoppedflag_help[i] =
				(msg_help.x >= helpbtn_x[i][0] && msg_help.x <= helpbtn_x[i][1] && msg_help.y >= helpbtn_y[i][0] &&
					msg_help.y <= helpbtn_y[i][1]);
			}
			if (msg_help.message == WM_KEYDOWN)
			{
				if (msg_help.vkcode == VK_ESCAPE)
				{
					exit_m();
				}
			}
			if (msg_help.message == WM_LBUTTONDOWN)
			{
				if (isStoppedflag_help[0])
				{
					cleardevice();
					opening();
				}
				if (isStoppedflag_help[1])
				{
					mode = 1;
					cleardevice();
					goto modechange;
				}
				if (isStoppedflag_help[2])
				{
					mode = 2;
					cleardevice();
					goto modechange;
				}
				if (isStoppedflag_help[3])
				{
					mode = 3;
					cleardevice();
					goto modechange;
				}
			}
		}
	}

	else if (mode == 2)
	{
		cleardevice();
		IMAGE scene_help2;
		loadimage(&scene_help2, L"./material/scene/scene_help2.jpg", 1280, 720);
		putimage(0, 0, &scene_help2);
		//�����������
		setbkmode(TRANSPARENT);
		setfillcolor(WHITE);
		settextstyle(30, 0, _T("����С���μ���"));
		outtextxy(105, 16, L"������ع�");
		settextstyle(20, 0, _T("����С���μ���"));
		outtextxy(408, 43, L"��Ϸ����");
		outtextxy(500, 43, L"������Ϸ");
		outtextxy(316, 43, L"����˵��");
		mycout(L"����˵��", 108, 136, 22);
		//��about.txt
		fstream ifs;
		ofstream ofs;
		ifs.open("./material/text/about.txt", ios::in);
		if (!ifs.is_open())
		{
			cerr << "�ļ���ʧ�ܣ�\n";
			return;
		}
		//��ӡ�ļ��е�����
		string buf = "";
		int linecnt = 0;
		while (getline(ifs, buf))
		{
			char text[2048];
			buf += '\n';
			strcpy_s(text, buf.c_str());
			USES_CONVERSION;
			wchar_t* wchar_temp = A2W(text);
			const wchar_t* wchar_text = wchar_temp;
			mycout(wchar_text, 100, 185 + 15 * linecnt, 22);
			linecnt++;
		}
		ifs.close();
		while (1)
		{
			ExMessage msg_help;
			msg_help = getmessage(EX_MOUSE | EX_KEY);
			for (int i = 0; i <= HelpBtnNum - 1; i++)
			{
				isStoppedflag_help[i] =
				(msg_help.x >= helpbtn_x[i][0] && msg_help.x <= helpbtn_x[i][1] && msg_help.y >= helpbtn_y[i][0] &&
					msg_help.y <= helpbtn_y[i][1]);
			}
			if (msg_help.message == WM_KEYDOWN)
			{
				if (msg_help.vkcode == VK_ESCAPE)
				{
					cout << 3 << endl;
					exit_m();
				}
			}
			if (msg_help.message == WM_LBUTTONDOWN)
			{
				if (isStoppedflag_help[0])
				{
					cleardevice();
					opening();
				}
				if (isStoppedflag_help[1])
				{
					mode = 1;
					cleardevice();
					goto modechange;
				}
				if (isStoppedflag_help[2])
				{
					mode = 2;
					cleardevice();
					goto modechange;
				}
				if (isStoppedflag_help[3])
				{
					mode = 3;
					cleardevice();
					goto modechange;
				}
			}
		}
	}
	else if (mode == 3)
	{
		cleardevice();
		IMAGE scene_help1;
		loadimage(&scene_help1, L"./material/scene/scene_help1.jpg", 1280, 720);
		putimage(0, 0, &scene_help1);
		//�����������
		setbkmode(TRANSPARENT);
		setfillcolor(WHITE);
		settextstyle(30, 0, _T("����С���μ���"));
		outtextxy(105, 16, L"������ع�");
		settextstyle(20, 0, _T("����С���μ���"));
		outtextxy(408, 43, L"��Ϸ����");
		outtextxy(500, 43, L"������Ϸ");
		outtextxy(316, 43, L"����˵��");
		mycout(L"��Ϸ��ϸ��Ϣ", 108, 136, 22);
		//��about.txt
		fstream ifs;
		ofstream ofs;
		ifs.open("./material/text/manual.txt", ios::in);
		if (!ifs.is_open())
		{
			cerr << "�ļ���ʧ�ܣ�\n";
			return;
		}
		//��ӡ�ļ��е�����
		string buf = "";
		int linecnt = 0;
		while (getline(ifs, buf))
		{
			char text[2048];
			buf += '\n';
			strcpy_s(text, buf.c_str());
			USES_CONVERSION;
			wchar_t* wchar_temp = A2W(text);
			const wchar_t* wchar_text = wchar_temp;
			mycout(wchar_text, 100, 185 + 15 * linecnt, 22);
			linecnt++;
		}
		ifs.close();
		while (1)
		{
			ExMessage msg_help;
			msg_help = getmessage(EX_MOUSE | EX_KEY);
			for (int i = 0; i <= HelpBtnNum - 1; i++)
			{
				isStoppedflag_help[i] =
				(msg_help.x >= helpbtn_x[i][0] && msg_help.x <= helpbtn_x[i][1] && msg_help.y >= helpbtn_y[i][0] &&
					msg_help.y <= helpbtn_y[i][1]);
			}
			if (msg_help.message == WM_KEYDOWN)
			{
				if (msg_help.vkcode == VK_ESCAPE)
				{
					cout << 3 << endl;
					exit_m();
				}
			}
			if (msg_help.message == WM_LBUTTONDOWN)
			{
				if (isStoppedflag_help[0])
				{
					cleardevice();
					opening();
				}
				if (isStoppedflag_help[1])
				{
					mode = 1;
					cleardevice();
					goto modechange;
				}
				if (isStoppedflag_help[2])
				{
					mode = 2;
					cleardevice();
					goto modechange;
				}
				if (isStoppedflag_help[3])
				{
					mode = 3;
					cleardevice();
					goto modechange;
				}
			}
		}
	}
}

//�˳�ҳ��
void exit_m()
{
	IMAGE box_exit;
	loadimage(&box_exit, L"./material/box/box_exit.jpg", 440, 233);
	putimage(420, 240, &box_exit);
	clickedExit = true;
	while (1)
	{
		ExMessage msg_exit;
		msg_exit = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i < ExitBtnNum; i++)
		{
			isStoppedFlag_exit[i] = (msg_exit.x >= exitbtn_x[i][0] && msg_exit.x <= exitbtn_x[i][1]
				&& msg_exit.y >= exitbtn_y[i][0] && msg_exit.y <= exitbtn_y[i][1]);
		}
		switch (msg_exit.message)
		{
		case WM_MOUSEMOVE:
			{
				if (isStoppedFlag_exit[0] && clickedExit)
				{
					IMAGE box_yesclk;
					loadimage(&box_yesclk, L"./material/box/box_exit_yesclk.jpg", 440, 233);
					putimage(420, 240, &box_yesclk);
					break;
				}
				else if (isStoppedFlag_exit[1] && clickedExit)
				{
					IMAGE box_noclk;
					loadimage(&box_noclk, L"./material/box/box_exit_noclk.jpg", 440, 233);
					putimage(420, 240, &box_noclk);
					break;
				}
				else
				{
					IMAGE box_exit;
					loadimage(&box_exit, L"./material/box/box_exit.jpg", 440, 233);
					putimage(420, 240, &box_exit);
					break;
				}
			}
		case WM_LBUTTONDOWN:
			{
				if (isStoppedFlag_exit[0] && clickedExit)
				{
					exit(0);
					break;
				}
				else if (isStoppedFlag_exit[1] && clickedExit)
				{
					clickedExit = false;
					cout << 8 << endl;
					opening();
					break;
				}
			}
		}
	}
}

//��Ϸҳ��
void ingame()
{
	if (steps == 1)
	{
		if (needSelect) {
			//����ѡ����
			IMAGE box_select;
			loadimage(&box_select, L"./material/box/box_select.jpg", 440, 233);
			putimage(420, 240, &box_select);
			while (1)
			{
				ExMessage msg_select;
				msg_select = getmessage(EX_MOUSE | EX_KEY);
				for (int i = 0; i < ExitBtnNum; i++)
				{
					isStoppedFlag_select[i] = (msg_select.x >= exitbtn_x[i][0] && msg_select.x <= exitbtn_x[i][1]
						&& msg_select.y >= exitbtn_y[i][0] && msg_select.y <= exitbtn_y[i][1]);
				}
				switch (msg_select.message)
				{
				case WM_MOUSEMOVE:
				{
					if (isStoppedFlag_select[0])
					{
						IMAGE box_selectblack;
						loadimage(&box_selectblack, L"./material/box/box_selectblack.jpg", 440, 233);
						putimage(420, 240, &box_selectblack);
						break;
					}
					else if (isStoppedFlag_select[1])
					{
						IMAGE box_selectwhite;
						loadimage(&box_selectwhite, L"./material/box/box_selectwhite.jpg", 440, 233);
						putimage(420, 240, &box_selectwhite);
						break;
					}
					else
					{
						IMAGE box_select;
						loadimage(&box_select, L"./material/box/box_select.jpg", 440, 233);
						putimage(420, 240, &box_select);
						break;
					}
				}
				case WM_LBUTTONDOWN:
				{
					if (isStoppedFlag_select[0])
					{
						humanColor = 1;
						AIColor = 0;
						goto inScene;
					}
					else if (isStoppedFlag_select[1])
					{
						humanColor = 0;
						AIColor = 1;
						goto inScene;
					}
				}
				case WM_KEYDOWN:
				{
					if (msg_select.vkcode == VK_ESCAPE)
					{
						exit_m();
					}
				}
				}
			}
		}
	}

inScene:
	//���������龰
	cleardevice();
	cout << theme << endl;
	switch (theme)
	{
	case 0:
		{
			if (isPlayingflag)
			{
				IMAGE scene_bgmplay;
				loadimage(&scene_bgmplay, L"./material/scene/scene_bgmplay.jpg", 1280, 720);
				putimage(0, 0, &scene_bgmplay);
				break;
			}
			else
			{
				IMAGE scene_bgmstop;
				loadimage(&scene_bgmstop, L"./material/scene/scene_bgmstop.jpg", 1280, 720);
				putimage(0, 0, &scene_bgmstop);
				break;
			}
		}
	case 1:
		{
			if (isPlayingflag)
			{
				IMAGE scene_bgmplay_2;
				loadimage(&scene_bgmplay_2, L"./material/scene/scene_bgmplay_2.jpg", 1280, 720);
				putimage(0, 0, &scene_bgmplay_2);
				break;
			}
			else
			{
				IMAGE scene_bgmstop_2;
				loadimage(&scene_bgmstop_2, L"./material/scene/scene_bgmstop_2.jpg", 1280, 720);
				putimage(0, 0, &scene_bgmstop_2);
				break;
			}
		}
	}
	//�������̳�ʼ��
	if (steps == 1)
	{
		initialize(false);
	}
	else initialize(true);
	printBoard();
	if(judge() == -1)
	{
		whoWins = 1;
		winOrLose();
	}
	if (judge() == 1)
	{
		whoWins = -1;
		winOrLose();
	}
	//��ʼ���,step == 1
	cout << 2 << endl;
	for (int i = steps; i <= 81; ++i)
	{
		if (i % 2 == humanColor)
		{
			cout << 3 << endl;
			humanturn_GUI();
			if(steps == 1)
			{
				blackFirst();
			}
			steps++;
			if (judge() == -1)
			{
				cout << "��Ӯ�ˣ�";
				whoWins = 1;
				winOrLose();
				break;
			}
			if (judge() == 1)
			{
				whoWins = -1;
				winOrLose();
				break;
			}
		}
		else
		{
			AIturn(difficulty);
			steps++;
			if (judge() == 1)
			{
				whoWins = -1;
				cout << "�����ˣ�";
				winOrLose();
				break;
			}
			if (judge() == -1)
			{
				cout << "��Ӯ�ˣ�";
				whoWins = 1;
				winOrLose();
				break;
			}
		}
	}
}

void system_m()
{
	cleardevice();
	IMAGE scene_system;
	loadimage(&scene_system, L"./material/scene/scene_system.jpg", 1280, 720);
	putimage(0, 0, &scene_system);

	outputVol();
	outputBgmName(720, 550, 22);

	while (1)
	{
		settextcolor(WHITE);
		ExMessage msg_system;
		msg_system = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i <= SystemBtnNum - 1; i++)
		{
			isStoppedflag_system[i] =
			(msg_system.x >= systembtn_x[i][0] && msg_system.x <= systembtn_x[i][1] && msg_system.y >= systembtn_y[i][0]
				&&
				msg_system.y <= systembtn_y[i][1]);
		}
		if (msg_system.message == WM_KEYDOWN)
		{
			if (msg_system.vkcode == VK_ESCAPE)
			{
				exit_m();
			}
		}
		if (msg_system.message == WM_LBUTTONDOWN)
		{
			if (isStoppedflag_system[0] && difficulty == 1)
			{
				difficulty = 0;
				IMAGE box_simple;
				loadimage(&box_simple, L"./material/box/box_simple.jpg", 440, 233);
				putimage(420, 240, &box_simple);
				while (1)
				{
					ExMessage msg_simple;
					msg_simple = getmessage(EX_MOUSE | EX_KEY);
					for (int i = 0; i < 1; i++)
					{
						isStoppedFlag_single[i] = (msg_simple.x >= singleBtn_x[i][0]
							&& msg_simple.x <= singleBtn_x[i][1]
							&& msg_simple.y >= singleBtn_y[i][0] 
							&& msg_simple.y <= singleBtn_y[i][1]);
					}
					switch (msg_simple.message)
					{
					case WM_MOUSEMOVE:
						{
							if (isStoppedFlag_single[0])
							{
								IMAGE box_simple_yesclk;
								loadimage(&box_simple_yesclk, L"./material/box/box_simple_yesclk.jpg", 440, 233);
								putimage(420, 240, &box_simple_yesclk);
								break;
							}
							else
							{
								IMAGE box_simple;
								loadimage(&box_simple, L"./material/box/box_simple.jpg", 440, 233);
								putimage(420, 240, &box_simple);
								break;
							}
						}
					case WM_LBUTTONDOWN:
						{
							if (isStoppedFlag_single[0])
							{
								cleardevice();
								system_m();
								break;
							}
						}
					}
				}
			}

			if (isStoppedflag_system[1] && difficulty == 0)
			{
				difficulty = 1;
				IMAGE box_mid;
				loadimage(&box_mid, L"./material/box/box_mid.jpg", 440, 233);
				putimage(420, 240, &box_mid);
				while (1)
				{
					ExMessage msg_mid;
					msg_mid = getmessage(EX_MOUSE | EX_KEY);
					for (int i = 0; i < 1; i++)
					{
						isStoppedFlag_single[i] = 
							(msg_mid.x >= singleBtn_x[i][0] 
								&& msg_mid.x <= singleBtn_x[i][1]
							&& msg_mid.y >= singleBtn_y[i][0] 
								&& msg_mid.y <= singleBtn_y[i][1]);
					}
					switch (msg_mid.message)
					{
					case WM_MOUSEMOVE:
						{
							if (isStoppedFlag_single[0])
							{
								IMAGE box_mid_yesclk;
								loadimage(&box_mid_yesclk, L"./material/box/box_mid_yesclk.jpg", 440, 233);
								putimage(420, 240, &box_mid_yesclk);
								break;
							}
							else
							{
								IMAGE box_mid;
								loadimage(&box_mid, L"./material/box/box_mid.jpg", 440, 233);
								putimage(420, 240, &box_mid);
								break;
							}
						}
					case WM_LBUTTONDOWN:
						{
							if (isStoppedFlag_single[0])
							{
								cleardevice();
								system_m();
								break;
							}
						}
					}
				}
			}
			if (isStoppedflag_system[2] && theme == 1)
			{
				theme = 0;
				IMAGE box_theme0;
				loadimage(&box_theme0, L"./material/box/box_theme0.jpg", 440, 233);
				putimage(420, 240, &box_theme0);
				while (1)
				{
					ExMessage msg_theme0;
					msg_theme0 = getmessage(EX_MOUSE | EX_KEY);
					for (int i = 0; i < 1; i++)
					{
						isStoppedFlag_single[i] = (msg_theme0.x >= singleBtn_x[i][0] 
							&& msg_theme0.x <= singleBtn_x[i][1]
							&& msg_theme0.y >= singleBtn_y[i][0] 
							&& msg_theme0.y <= singleBtn_y[i][1]);
					}
					switch (msg_theme0.message)
					{
					case WM_MOUSEMOVE:
						{
							if (isStoppedFlag_single[0])
							{
								IMAGE box_theme0_yesclk;
								loadimage(&box_theme0_yesclk, L"./material/box/box_theme0_yesclk.jpg", 440, 233);
								putimage(420, 240, &box_theme0_yesclk);
								break;
							}
							else
							{
								IMAGE box_theme0;
								loadimage(&box_theme0, L"./material/box/box_theme0.jpg", 440, 233);
								putimage(420, 240, &box_theme0);
								break;
							}
						}
					case WM_LBUTTONDOWN:
						{
							if (isStoppedFlag_single[0])
							{
								cleardevice();
								system_m();
								break;
							}
						}
					}
				}
			}
			if (isStoppedflag_system[3] && theme == 0)
			{
				theme = 1;
				IMAGE box_theme1;
				loadimage(&box_theme1, L"./material/box/box_theme1.jpg", 440, 233);
				putimage(420, 240, &box_theme1);
				while (1)
				{
					ExMessage msg_theme1;
					msg_theme1 = getmessage(EX_MOUSE | EX_KEY);
					for (int i = 0; i < 1; i++)
					{
						isStoppedFlag_single[i] = (msg_theme1.x >= singleBtn_x[i][0] 
							&& msg_theme1.x <= singleBtn_x[i][1]
							&& msg_theme1.y >= singleBtn_y[i][0] 
							&& msg_theme1.y <= singleBtn_y[i][1]);
					}
					switch (msg_theme1.message)
					{
					case WM_MOUSEMOVE:
						{
							if (isStoppedFlag_single[0])
							{
								IMAGE box_theme1_yesclk;
								loadimage(&box_theme1_yesclk, L"./material/box/box_theme1_yesclk.jpg", 440, 233);
								putimage(420, 240, &box_theme1_yesclk);
								break;
							}
							else
							{
								IMAGE box_theme1;
								loadimage(&box_theme1, L"./material/box/box_theme1.jpg", 440, 233);
								putimage(420, 240, &box_theme1);
								break;
							}
						}
					case WM_LBUTTONDOWN:
						{
							if (isStoppedFlag_single[0])
							{
								cleardevice();
								system_m();
								break;
							}
						}
					}
				}
			}
			if (isStoppedflag_system[4])
			{
				clearSave();
			}
			else if (isStoppedflag_system[5])
			{
				SetVolum(0);
				outputVol();
			}
			else if (isStoppedflag_system[6])
			{
				SetVolum(25);
				outputVol();
			}
			else if (isStoppedflag_system[7])
			{
				SetVolum(50);
				outputVol();
			}
			else if (isStoppedflag_system[8])
			{
				SetVolum(75);
				outputVol();
			}
			else if (isStoppedflag_system[9])
			{
				SetVolum(100);
				outputVol();
			}
			else if (isStoppedflag_system[10])
			{
				difficulty = 1;
				theme = 0;
				SetVolum(50);
				bgmnum = 1;
				bkGndMusic(false);
				outputBgmName(720, 550, 22);
				outputVol();
			}
			else if (isStoppedflag_system[11])
			{
				cleardevice();
				opening();
			}
			else if (isStoppedflag_system[12])
			{
				pauseMusic();
				bgmnum = 1;
				isPlayingflag = true;
				bkGndMusic(false);
				outputBgmName(720, 550, 22);
			}
			else if (isStoppedflag_system[13])
			{
				pauseMusic();
				bgmnum = 2;
				isPlayingflag = true;
				bkGndMusic(false);
				outputBgmName(720, 550, 22);
			}
			else if (isStoppedflag_system[14])
			{
				pauseMusic();
				bgmnum = 3;
				isPlayingflag = true;
				bkGndMusic(false);
				outputBgmName(720, 550, 22);
			}
			else if (isStoppedflag_system[15])
			{
				pauseMusic();
				bgmnum = 4;
				isPlayingflag = true;
				bkGndMusic(false);
				outputBgmName(720, 550, 22);
			}
			else if (isStoppedflag_system[16])
			{
				pauseMusic();
				bgmnum = 5;
				isPlayingflag = true;
				bkGndMusic(false);
				outputBgmName(720, 550, 22);
			}
			else if (isStoppedflag_system[17])
			{
				pauseMusic();
				bgmnum = 6;
				isPlayingflag = true;
				bkGndMusic(false);
				outputBgmName(720, 550, 22);
			}
			else if (isStoppedflag_system[18])
			{
				pauseMusic();
				bgmnum = 7;
				isPlayingflag = true;
				bkGndMusic(false);
				outputBgmName(720, 550, 22);
			}
			else if (isStoppedflag_system[19])
			{
				pauseMusic();
				bgmnum = 8;
				isPlayingflag = true;
				bkGndMusic(false);
				outputBgmName(720, 550, 22);
			}
			//
			else if (isStoppedflag_system[20])
			{
				pauseMusic();
			}
			else if (isStoppedflag_system[21])
			{
				isPlayingflag = true;
				bkGndMusic(false);
			}
		}
	}
}


//��������
bool SetVolum(int volume)
{
	bool ret = false;
	HRESULT hr;
	IMMDeviceEnumerator* pDeviceEnumerator = 0;
	IMMDevice* pDevice = 0;
	IAudioEndpointVolume* pAudioEndpointVolume = 0;
	IAudioClient* pAudioClient = 0;

	try
	{
		hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),
		                      (void**)&pDeviceEnumerator);
		if (FAILED(hr)) throw "CoCreateInstance";
		hr = pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &pDevice);
		if (FAILED(hr)) throw "GetDefaultAudioEndpoint";
		hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pAudioEndpointVolume);
		if (FAILED(hr)) throw "pDevice->Active";
		hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
		if (FAILED(hr)) throw "pDevice->Active";

		float fVolume;
		fVolume = volume / 100.0f;
		hr = pAudioEndpointVolume->SetMasterVolumeLevelScalar(fVolume, &GUID_NULL);
		if (FAILED(hr)) throw "SetMasterVolumeLevelScalar";

		pAudioClient->Release();
		pAudioEndpointVolume->Release();
		pDevice->Release();
		pDeviceEnumerator->Release();

		ret = true;
	}
	catch (...)
	{
		if (pAudioClient) pAudioClient->Release();
		if (pAudioEndpointVolume) pAudioEndpointVolume->Release();
		if (pDevice) pDevice->Release();
		if (pDeviceEnumerator) pDeviceEnumerator->Release();
		throw;
	}

	return ret;
}

int GetVolume()
{
	int volumeValue = 0;
	HRESULT hr;
	IMMDeviceEnumerator* pDeviceEnumerator = 0;
	IMMDevice* pDevice = 0;
	IAudioEndpointVolume* pAudioEndpointVolume = 0;
	IAudioClient* pAudioClient = 0;

	try
	{
		hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),
		                      (void**)&pDeviceEnumerator);
		if (FAILED(hr)) throw "CoCreateInstance";
		hr = pDeviceEnumerator->GetDefaultAudioEndpoint(eRender, eMultimedia, &pDevice);
		if (FAILED(hr)) throw "GetDefaultAudioEndpoint";
		hr = pDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_ALL, NULL, (void**)&pAudioEndpointVolume);
		if (FAILED(hr)) throw "pDevice->Active";
		hr = pDevice->Activate(__uuidof(IAudioClient), CLSCTX_ALL, NULL, (void**)&pAudioClient);
		if (FAILED(hr)) throw "pDevice->Active";

		float fVolume;
		hr = pAudioEndpointVolume->GetMasterVolumeLevelScalar(&fVolume);
		if (FAILED(hr)) throw "SetMasterVolumeLevelScalar";

		pAudioClient->Release();
		pAudioEndpointVolume->Release();
		pDevice->Release();
		pDeviceEnumerator->Release();

		volumeValue = fVolume * 100;
	}
	catch (...)
	{
		if (pAudioClient) pAudioClient->Release();
		if (pAudioEndpointVolume) pAudioEndpointVolume->Release();
		if (pDevice) pDevice->Release();
		if (pDeviceEnumerator) pDeviceEnumerator->Release();
		throw;
	}

	return volumeValue;
}

void outputVol()
{
	cleardevice();
	IMAGE scene_system;
	loadimage(&scene_system, L"./material/scene/scene_system.jpg", 1280, 720);
	putimage(0, 0, &scene_system);

	string vol_str = "��ǰ������";
	int volume = GetVolume();
	char text[20];
	vol_str += to_string(volume);
	vol_str += "%";
	strcpy_s(text, vol_str.c_str());
	USES_CONVERSION;
	wchar_t* wchar_temp = A2W(text);
	const wchar_t* wchar_text = wchar_temp;
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	mycout(wchar_text, 72, 675, 20);
}

//�������
void outputBgmName(int x, int y, int size)
{
	cleardevice();
	IMAGE scene_system;
	loadimage(&scene_system, L"./material/scene/scene_system.jpg", 1280, 720);
	putimage(0, 0, &scene_system);

	string temp = "������ţ�";
	temp += bgmName[bgmnum];
	char text[50];
	strcpy_s(text, temp.c_str());
	USES_CONVERSION;
	wchar_t* wchar_temp = A2W(text);
	const wchar_t* wchar_text = wchar_temp;
	setbkmode(TRANSPARENT);
	mycout(wchar_text, x, y, size);
}

//����浵��¼
void clearSave()
{
	IMAGE box_clear;
	loadimage(&box_clear, L"./material/box/box_clear.jpg", 440, 233);
	putimage(420, 240, &box_clear);
	while (1)
	{
		ExMessage msg_clear;
		msg_clear = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i < ExitBtnNum; i++)
		{
			isStoppedFlag_exit[i] = (msg_clear.x >= exitbtn_x[i][0] && msg_clear.x <= exitbtn_x[i][1]
				&& msg_clear.y >= exitbtn_y[i][0] && msg_clear.y <= exitbtn_y[i][1]);
		}
		switch (msg_clear.message)
		{
		case WM_MOUSEMOVE:
			{
				if (isStoppedFlag_exit[0] && clickedExit)
				{
					IMAGE box_clear_yesclk;
					loadimage(&box_clear_yesclk, L"./material/box/box_clear_yesclk.jpg", 440, 233);
					putimage(420, 240, &box_clear_yesclk);
					break;
				}
				else if (isStoppedFlag_exit[1] && clickedExit)
				{
					IMAGE box_clear_noclk;
					loadimage(&box_clear_noclk, L"./material/box/box_clear_noclk.jpg", 440, 233);
					putimage(420, 240, &box_clear_noclk);
					break;
				}
				else
				{
					IMAGE box_clear;
					loadimage(&box_clear, L"./material/box/box_clear.jpg", 440, 233);
					putimage(420, 240, &box_clear);
					break;
				}
			}
		case WM_LBUTTONDOWN:
			{
				if (isStoppedFlag_exit[0])
				{
					goto cleardata;
					break;
				}
				else if (isStoppedFlag_exit[1])
				{
					cleardevice();
					system_m();
					break;
				}
			}
		}
	}
cleardata:
	ifstream ifs;
	ofstream ofs;
	//�򿪴浵�ļ�
	ofs.open("./material/text/savedata.txt", ios::out | ios::trunc);
	if (!ofs.is_open())
	{
		cerr << "�浵�ļ���ʧ�ܣ�\n";
		return;
	}
	//����д��浵�ļ�
	ofs << "PreviousTime,humanColor,steps,whoWins,"
		"chessBoard_1,chessBoard_2,chessBoard_3,"
		"chessBoard_4,chessBoard_5,chessBoard_6,chessBoard_7,"
		"chessBoard_8,chessBoard_9,END" << endl;
	ofs.close();
}

void winOrLose()
{
	switch (whoWins)
	{
	case 1:
		{
			needSelect = false;
			IMAGE box_win;
			loadimage(&box_win, L"./material/box/box_win.jpg", 440, 233);
			putimage(420, 240, &box_win);
			while (1)
			{
				ExMessage msg_win;
				msg_win = getmessage(EX_MOUSE | EX_KEY);
				for (int i = 0; i < ExitBtnNum; i++)
				{
					isStoppedFlag_exit[i] = (msg_win.x >= exitbtn_x[i][0] && msg_win.x <= exitbtn_x[i][1]
						&& msg_win.y >= exitbtn_y[i][0] && msg_win.y <= exitbtn_y[i][1]);
				}
				switch (msg_win.message)
				{
				case WM_MOUSEMOVE:
					{
						if (isStoppedFlag_exit[1])
						{
							IMAGE box_win_reclk;
							loadimage(&box_win_reclk, L"./material/box/box_win_reclk.jpg", 440, 233);
							putimage(420, 240, &box_win_reclk);
							break;
						}
						else if (isStoppedFlag_exit[0])
						{
							IMAGE box_win_exitclk;
							loadimage(&box_win_exitclk, L"./material/box/box_win_exitclk.jpg", 440, 233);
							putimage(420, 240, &box_win_exitclk);
							break;
						}
						else
						{
							IMAGE box_win;
							loadimage(&box_win, L"./material/box/box_win.jpg", 440, 233);
							putimage(420, 240, &box_win);
							break;
						}
					}
				case WM_LBUTTONDOWN:
					{
						if (isStoppedFlag_exit[0])
						{
							cleardevice();
							initialize(false);
							opening();
							break;
						}
						else if (isStoppedFlag_exit[1])
						{
							goto reboard;
						}
					}
				}
			}
		}
	case -1:
		{
			needSelect = false;
			while (1)
			{
				ExMessage msg_lose;
				msg_lose = getmessage(EX_MOUSE | EX_KEY);
				for (int i = 0; i < ExitBtnNum; i++)
				{
					isStoppedFlag_exit[i] = (msg_lose.x >= exitbtn_x[i][0] && msg_lose.x <= exitbtn_x[i][1]
						&& msg_lose.y >= exitbtn_y[i][0] && msg_lose.y <= exitbtn_y[i][1]);
				}
				switch (msg_lose.message)
				{
				case WM_MOUSEMOVE:
					{
						if (isStoppedFlag_exit[1])
						{
							IMAGE box_lose_reclk;
							loadimage(&box_lose_reclk, L"./material/box/box_lose_reclk.jpg", 440, 233);
							putimage(420, 240, &box_lose_reclk);
							break;
						}
						else if (isStoppedFlag_exit[0])
						{
							IMAGE box_lose_exitclk;
							loadimage(&box_lose_exitclk, L"./material/box/box_lose_exitclk.jpg", 440, 233);
							putimage(420, 240, &box_lose_exitclk);
							break;
						}
						else
						{
							IMAGE box_lose;
							loadimage(&box_lose, L"./material/box/box_lose.jpg", 440, 233);
							putimage(420, 240, &box_lose);
							break;
						}
					}
				case WM_LBUTTONDOWN:
					{
						if (isStoppedFlag_exit[0])
						{
							cleardevice();
							initialize(false);
							opening();
							break;
						}
						else if (isStoppedFlag_exit[1])
						{
							goto reboard;
						}
					}
				}
			}
		}
	}
reboard:
	cleardevice();
	printBoard();
	while (1)
	{
		ExMessage msg_play;
		msg_play = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i < InGameBtnNum; i++)
		{
			isStoppedflag_ingame[i] =
			(msg_play.x >= ingamebtn_x[i][0] &&
				msg_play.x <= ingamebtn_x[i][1] &&
				msg_play.y >= ingamebtn_y[i][0] &&
				msg_play.y <= ingamebtn_y[i][1]);
		}

		if (msg_play.message == WM_KEYDOWN)
		{
			if (msg_play.vkcode == VK_ESCAPE)
			{
				exit_m();
			}
		}
		if (msg_play.message == WM_LBUTTONDOWN)
		{
			if (isStoppedflag_ingame[0])
			{
				/*saveData_GUI();*/
			}
			else if (isStoppedflag_ingame[1])
			{
				loadData();
			}
			else if (isStoppedflag_ingame[2])
			{
				saveData(); //qsave
			}
			else if (isStoppedflag_ingame[3])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[4])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[5])
			{
				switch (isPlayingflag)
				{
				case true:
					{
						pauseMusic();
						isPlayingflag = false;
						cleardevice();
						IMAGE scene_bgmstop;
						loadimage(&scene_bgmstop, L"./material/scene/scene_bgmstop.jpg", 1280, 720);
						putimage(0, 0, &scene_bgmstop);
						printBoard();
						cout << "stop" << endl;
						break;
					}
				case false:
					{
						isPlayingflag = true;
						bkGndMusic(false);
						cleardevice();
						IMAGE scene_bgmplay;
						loadimage(&scene_bgmplay, L"./material/scene/scene_bgmplay.jpg", 1280, 720);
						putimage(0, 0, &scene_bgmplay);
						printBoard();
						break;
					}
				}
			}
			else if (isStoppedflag_ingame[6])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[7])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[8])
			{
				exit_m();
			}
			else if (isStoppedflag_ingame[9])
			{
				//surrender();
			}
		}
	}
}

//���ӵ�һ����������
void blackFirst()
{
	if(steps == 1)
	{
		if(position[5][5] == 1)
		{
			initialize(false);
			needSelect = false;

			IMAGE box_prohibit;
			loadimage(&box_prohibit, L"./material/box/box_prohibit.jpg", 440, 233);
			putimage(420, 240, &box_prohibit);
			while (1)
			{
				ExMessage msg_prohibit;
				msg_prohibit = getmessage(EX_MOUSE | EX_KEY);
				for (int i = 0; i < 1; i++)
				{
					isStoppedFlag_single[i] = (msg_prohibit.x >= singleBtn_x[i][0]
						&& msg_prohibit.x <= singleBtn_x[i][1]
						&& msg_prohibit.y >= singleBtn_y[i][0]
						&& msg_prohibit.y <= singleBtn_y[i][1]);
				}
				switch (msg_prohibit.message)
				{
				case WM_MOUSEMOVE:
				{
					if (isStoppedFlag_single[0])
					{
						IMAGE box_prohibit_yesclk;
						loadimage(&box_prohibit_yesclk, L"./material/box/box_prohibit_yesclk.jpg", 440, 233);
						putimage(420, 240, &box_prohibit_yesclk);
						break;
					}
					else
					{
						IMAGE box_prohibit;
						loadimage(&box_prohibit, L"./material/box/box_prohibit.jpg", 440, 233);
						putimage(420, 240, &box_prohibit);
						break;
					}
				}
				case WM_LBUTTONDOWN:
				{
					if (isStoppedFlag_single[0])
					{
						cleardevice();
						ingame();
						break;
					}
				}
				}
			}
		}
	}
}
//Ͷ��
void surrender()
{
	whoWins = -1;
	IMAGE box_surrender;
	loadimage(&box_surrender, L"./material/box/box_surrender.jpg", 440, 233);
	putimage(420, 240, &box_surrender);
	while (1)
	{
		ExMessage msg_surrender;
		msg_surrender = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i < ExitBtnNum; i++)
		{
			isStoppedFlag_exit[i] = (msg_surrender.x >= exitbtn_x[i][0] && msg_surrender.x <= exitbtn_x[i][1]
				&& msg_surrender.y >= exitbtn_y[i][0] && msg_surrender.y <= exitbtn_y[i][1]);
		}
		switch (msg_surrender.message)
		{
		case WM_MOUSEMOVE:
		{
			if (isStoppedFlag_exit[1])
			{
				IMAGE box_surrender_reclk;
				loadimage(&box_surrender_reclk, L"./material/box/box_surrender_reclk.jpg", 440, 233);
				putimage(420, 240, &box_surrender_reclk);
				break;
			}
			else if (isStoppedFlag_exit[0])
			{
				IMAGE box_surrender_exitclk;
				loadimage(&box_surrender_exitclk, L"./material/box/box_surrender_exitclk.jpg", 440, 233);
				putimage(420, 240, &box_surrender_exitclk);
				break;
			}
			else
			{
				IMAGE box_surrender;
				loadimage(&box_surrender, L"./material/box/box_surrender.jpg", 440, 233);
				putimage(420, 240, &box_surrender);
				break;
			}
		}
		case WM_LBUTTONDOWN:
		{
			if (isStoppedFlag_exit[0])
			{
				cleardevice();
				initialize(false);
				opening();
				break;
			}
			else if (isStoppedFlag_exit[1])
			{
				goto reboard;
			}
		}
		}
	}
reboard:
	cleardevice();
	printBoard();
	while (1)
	{
		ExMessage msg_play;
		msg_play = getmessage(EX_MOUSE | EX_KEY);
		for (int i = 0; i < InGameBtnNum; i++)
		{
			isStoppedflag_ingame[i] =
				(msg_play.x >= ingamebtn_x[i][0] &&
					msg_play.x <= ingamebtn_x[i][1] &&
					msg_play.y >= ingamebtn_y[i][0] &&
					msg_play.y <= ingamebtn_y[i][1]);
		}

		if (msg_play.message == WM_KEYDOWN)
		{
			if (msg_play.vkcode == VK_ESCAPE)
			{
				exit_m();
			}
		}
		if (msg_play.message == WM_LBUTTONDOWN)
		{
			if (isStoppedflag_ingame[0])
			{
				/*saveData_GUI();*/
			}
			else if (isStoppedflag_ingame[1])
			{
				loadData();
			}
			else if (isStoppedflag_ingame[2])
			{
				saveData(); //qsave
			}
			else if (isStoppedflag_ingame[3])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[4])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[5])
			{
				switch (isPlayingflag)
				{
				case true:
				{
					pauseMusic();
					isPlayingflag = false;
					cleardevice();
					IMAGE scene_bgmstop;
					loadimage(&scene_bgmstop, L"./material/scene/scene_bgmstop.jpg", 1280, 720);
					putimage(0, 0, &scene_bgmstop);
					printBoard();
					cout << "stop" << endl;
					break;
				}
				case false:
				{
					isPlayingflag = true;
					bkGndMusic(false);
					cleardevice();
					IMAGE scene_bgmplay;
					loadimage(&scene_bgmplay, L"./material/scene/scene_bgmplay.jpg", 1280, 720);
					putimage(0, 0, &scene_bgmplay);
					printBoard();
					break;
				}
				}
			}
			else if (isStoppedflag_ingame[6])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[7])
			{
				system_m();
			}
			else if (isStoppedflag_ingame[8])
			{
				exit_m();
			}
			else if (isStoppedflag_ingame[9])
			{
				surrender();
			}
		}
	}
}