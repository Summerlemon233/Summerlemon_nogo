#pragma once

//
// Created by 16523 on 2022/11/14.
//

#ifndef NOGO_SIMPLE_NOGO_FUNC_H
#define NOGO_SIMPLE_NOGO_FUNC_H

#endif //NOGO_SIMPLE_NOGO_FUNC_H

#define WINVER 0x0600
#define _WIN32_WINNT 0x0600

//存档和读档
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

#define EXIT 27 //esc的ascii码是27
#define PAUSE 9 //键充当暂停（至菜单）键，对应ascii码为9
#define HELP 18//Alt键充当帮助键，对应ascii码为18*/

//全局变量的声明
//system设置变量
extern int difficulty;//难度,0和1
extern int theme;//主题
extern int bgmnum;//bgm

extern int humanColor;
extern int AIColor;
extern int steps;
extern int userNum;
extern int whoWins;
extern string PreviousTime;
extern int NowCondition;
extern bool needSelect;

//全局变量数组声明

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

//主菜单按钮
extern const int btn_x[BtnNum][2];
extern const int btn_y[BtnNum][2];
//帮助页面按钮
extern const int helpbtn_x[HelpBtnNum][2];
extern const int helpbtn_y[HelpBtnNum][2];
//退出页面按钮
extern const int exitbtn_x[ExitBtnNum][2];
extern const int exitbtn_y[ExitBtnNum][2];
//游戏进程中棋盘
extern int chessarea_x[11][11][2];
extern int chessarea_y[11][11][2];
//游戏进程中菜单
extern const int ingamebtn_x[InGameBtnNum][2];
extern const int ingamebtn_y[InGameBtnNum][2];
//系统界面按钮
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


//函数的声明

//存档和读档
void saveData();

void loadData();

//键盘读入实现暂停和返回菜单
void getKeyboardInstruction(void);

//产生随机数
int randSelectQuestion(int from, int to);

//输出系统日期
string systemTime(void);

//合法性初始化
void initialize(bool isLoadedData);

//打印棋盘
void printBoard(void);

//棋子（组）的气计数
int Qi_onceCount(int x, int y);
int Qi_count(int x, int y);

//判断输赢
int judge();//0-暂时平局；1-AI胜利；-1-人胜利；

//下一步bot能走的合法地带探索
void exceptNoQi(void);

//判断某个特定位置是否可走
bool isLegal(int x, int y,int color);

//棋局开始时的选择
void humanselect(void);

// 人走棋时的操作
void humanturn(void);
void humanturn_GUI(void);

//bot走棋时的操作
void AIturn(int mode);

//贪心算法的估值函数
int evaluateFunc(int color);

//生成用户编号
int getUserNum(void);

//判断用户是否之前记录在档
bool isUserInRecord(string name);

//向用户姓名文档里写入用户姓名
void writeUsername(void);

//为用户打开帮助文档
void openHelpFile(void);

//调用出主菜单
void mainMenu(void);

//开始新游戏时的初始化操作
void newGame(void);

//easyx输入方式
void mycout(const wchar_t* s, int begin_x, int begin_y, int fontsize);

//开始菜单相关
void openingBkGnd();

void openingBtn();

void opening();

//控制背景音乐
void bkGndMusic(bool isOpening);

void pauseMusic();

//帮助界面
void help();

//退出页面
void exit_m();

//游戏页面
void ingame();

//设置界面
void system_m();

//控制音量
bool SetVolum(int volume);

int GetVolume();

void outputVol();

//输出歌名
void outputBgmName(int x,int y,int size);

//清除存档记录
void clearSave();

//决出胜负后
void winOrLose();

//黑子第一步限制条件
void blackFirst();

//投降
void surrender();

