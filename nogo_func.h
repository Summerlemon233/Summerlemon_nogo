#pragma once

//
// Created by 16523 on 2022/11/14.
//

#ifndef NOGO_SIMPLE_NOGO_FUNC_H
#define NOGO_SIMPLE_NOGO_FUNC_H

#endif //NOGO_SIMPLE_NOGO_FUNC_H

#define WINVER 0x0600
#define _WIN32_WINNT 0x0600

//�浵�Ͷ���
#include <bits/stdc++.h>
#include <cmath>
#include <conio.h>
#include <graphics.h>
#include <easyx.h>
#include <mmsystem.h>
#include <atlconv.h>
#include <mmdeviceapi.h> 
#include <endpointvolume.h>
#include <audioclient.h>
#include <devicetopology.h>
#pragma comment(lib,"winmm.lib")


using namespace std;

#define BtnNum 10
#define HelpBtnNum 4
#define ExitBtnNum 2
#define MaxChessNum 81
#define InGameBtnNum 10
#define SystemBtnNum 22

#define ChessDelim 53
#define singleChess 41 

#define MAX_INSTRUCTION 81

#define EXIT 27 //esc��ascii����27
#define PAUSE 9 //���䵱��ͣ�����˵���������Ӧascii��Ϊ9
#define HELP 18//Alt���䵱����������Ӧascii��Ϊ18*/

//ȫ�ֱ���������
//system���ñ���
extern int difficulty;//�Ѷ�,0��1
extern int theme;//����
extern int bgmnum;//bgm

extern int humanColor;
extern int AIColor;
extern int steps;
extern int userNum;
extern int whoWins;
extern string PreviousTime;
extern int NowCondition;
extern bool needSelect;

//ȫ�ֱ�����������

extern int position[11][11];
extern int value[9][9];
extern char sign[10];

extern bool isPositionLegal[11][11];
extern string username;

extern int direction_x[4];
extern int direction_y[4];

extern int recentInstruction_x[MAX_INSTRUCTION];
extern int recentInstruction_y[MAX_INSTRUCTION];

extern bool marked[10][10];

//���˵���ť
extern const int btn_x[BtnNum][2];
extern const int btn_y[BtnNum][2];
//����ҳ�水ť
extern const int helpbtn_x[HelpBtnNum][2];
extern const int helpbtn_y[HelpBtnNum][2];
//�˳�ҳ�水ť
extern const int exitbtn_x[ExitBtnNum][2];
extern const int exitbtn_y[ExitBtnNum][2];
//��Ϸ����������
extern int chessarea_x[11][11][2];
extern int chessarea_y[11][11][2];
//��Ϸ�����в˵�
extern const int ingamebtn_x[InGameBtnNum][2];
extern const int ingamebtn_y[InGameBtnNum][2];
//ϵͳ���水ť
extern const int systembtn_x[SystemBtnNum][2];
extern const int systembtn_y[SystemBtnNum][2];

extern const int singleBtn_x[1][2];
extern const int singleBtn_y[1][2];

extern const int chessboard_x;
extern const int chessboard_y;

extern bool isStoppedFlag_select[ExitBtnNum];
extern bool isStoppedFlag_exit[ExitBtnNum];
extern bool isStoppedFlag_single[1];
extern bool isStoppedflag[BtnNum];
extern bool isStoppedflag_help[HelpBtnNum];
extern bool isStoppedflag_chess[11][11];
extern bool isStoppedflag_ingame[InGameBtnNum];
extern bool isStoppedflag_system[SystemBtnNum];

extern bool visitedExceptQi[11][11];

extern bool isPlayingflag;
extern bool clickedExit;

extern bool notFirstPlay[9];

extern string bgmName[9];


//����������

//�浵�Ͷ���
void saveData();

void loadData();

//���̶���ʵ����ͣ�ͷ��ز˵�
void getKeyboardInstruction(void);

//���������
int randSelectQuestion(int from, int to);

//���ϵͳ����
string systemTime(void);

//�Ϸ��Գ�ʼ��
void initialize(bool isLoadedData);

//��ӡ����
void printBoard(void);

//���ӣ��飩��������
int Qi_onceCount(int x, int y);
int Qi_count(int x, int y);

//�ж���Ӯ
int judge();//0-��ʱƽ�֣�1-AIʤ����-1-��ʤ����

//��һ��bot���ߵĺϷ��ش�̽��
void exceptNoQi(void);

//�ж�ĳ���ض�λ���Ƿ����
bool isLegal(int x, int y,int color);

//��ֿ�ʼʱ��ѡ��
void humanselect(void);

// ������ʱ�Ĳ���
void humanturn(void);
void humanturn_GUI(void);

//bot����ʱ�Ĳ���
void AIturn(int mode);

//̰���㷨�Ĺ�ֵ����
int evaluateFunc(int color);

//�����û����
int getUserNum(void);

//�ж��û��Ƿ�֮ǰ��¼�ڵ�
bool isUserInRecord(string name);

//���û������ĵ���д���û�����
void writeUsername(void);

//Ϊ�û��򿪰����ĵ�
void openHelpFile(void);

//���ó����˵�
void mainMenu(void);

//��ʼ����Ϸʱ�ĳ�ʼ������
void newGame(void);

//easyx���뷽ʽ
void mycout(const wchar_t* s, int begin_x, int begin_y, int fontsize);

//��ʼ�˵����
void openingBkGnd();

void openingBtn();

void opening();

//���Ʊ�������
void bkGndMusic(bool isOpening);

void pauseMusic();

//��������
void help();

//�˳�ҳ��
void exit_m();

//��Ϸҳ��
void ingame();

//���ý���
void system_m();

//��������
bool SetVolum(int volume);

int GetVolume();

void outputVol();

//�������
void outputBgmName(int x,int y,int size);

//����浵��¼
void clearSave();

//����ʤ����
void winOrLose();

//���ӵ�һ����������
void blackFirst();

//Ͷ��
void surrender();

