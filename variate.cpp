//
// Created by 16523 on 2022/11/18.
//
#include "nogo_func.h"
//system设置变量
extern int difficulty = 1;//难度
extern int theme = 0;//主题
extern int bgmnum = 1;//bgm序号


extern int humanColor = 0;
extern int AIColor = 1 - humanColor;
extern int steps = 1;
extern int userNum = 0;
extern int whoWins = 0;//1-人赢；0-暂时难分胜负；-1-bot赢
extern string PreviousTime = "";
extern int NowCondition = 0;//0-程序正常运行；1-暂停；2-退出并存档
extern bool isPlayingflag = true;
extern bool clickedExit = false;
extern bool needSelect = true;

//全局变量数组定义
extern char sign[10] = { '#','1','2','3','4','5','6','7','8','9' };
extern int position[11][11] = { -1 };//初始条件
extern bool isPositionLegal[11][11] = { true };
extern string username = "";
extern int value[9][9] = { 0 };

extern int direction_x[4] = { 1, -1, 0, 0 };
extern int direction_y[4] = { 0, 0, 1, -1 };

extern int recentInstruction_x[MAX_INSTRUCTION] = { 0 };
extern int recentInstruction_y[MAX_INSTRUCTION] = { 0 };

extern bool marked[10][10] = { false };

extern const int btn_x[BtnNum][2] =
{
	{0, 240}, {0, 240}, {0, 240}, {0, 240}, {0, 240}, {1123, 1151}, {1164, 1187}, {1197, 1231}
};
extern const int btn_y[BtnNum][2] =
{ {345, 375}, {415, 445}, {485, 515}, {555, 585}, {625, 655}, {16, 40}, {16, 40}, {16, 40} };
extern const int helpbtn_x[HelpBtnNum][2] = { {1035,1240},{395,485},{490,580},{390,480} };
extern const int helpbtn_y[HelpBtnNum][2] = { {663,705},{25,85},{25,85},{25,85} };

extern const int exitbtn_x[ExitBtnNum][2] = { {498, 620}, {658, 780} };
extern const int exitbtn_y[ExitBtnNum][2] = { {375, 400}, {375, 400} };

extern const int ingamebtn_x[InGameBtnNum][2] =
{ {634,662},{677,714},{726,773},{789,839},{868,891},{945,964},{1016,1040},{1099,1120},{1195,1218},{555,712} };
extern const int ingamebtn_y[InGameBtnNum][2] = 
{{695,713},{695,713}, {695,713}, {695,713}, {695,713}, {695,713}, {695,713}, {695,713}, {695,713},{13,39}};
//系统页面，1-12设置按钮，13-20播放列表，21-22媒体控制
extern const int systembtn_x[SystemBtnNum][2] = 
{{120,271},{345,496},{120,271},{345,496},{120,271},{119,205},{227,314},{342,429},{454,540},{556,642},{600,800},{1037,1237},
{699,1082},{699,1082},{699,1082},{699,1082},{699,1082},{699,1082},{699,1082},{699,1082},
{861,884},{913,936}};
extern const int systembtn_y[SystemBtnNum][2] = 
{{182,214},{182,214},{294,327},{294,327},{403,436},{540,573},{540,573},{540,573},{540,573},{540,573},{661,703},{661,703},
{182,218},{218,254},{254,290},{290,326},{326,362},{362,398},{398,434},{434,470},
{588,610},{588,610}};

extern const int singleBtn_x[1][2] = { 578,700 };
extern const int singleBtn_y[1][2] = { 390,415 };

extern int chessarea_x[11][11][2] = {0};
extern int chessarea_y[11][11][2] = {0};

extern const int chessboard_x = 392;
extern const int chessboard_y = 126;


extern bool isStoppedFlag_exit[ExitBtnNum] = { false };
extern bool isStoppedFlag_single[1] = {false};
extern bool isStoppedFlag_select[ExitBtnNum] = { false };
extern bool isStoppedflag[BtnNum] = { false };
extern bool isStoppedflag_help[HelpBtnNum] = { false };
extern bool isStoppedflag_system[SystemBtnNum] = { false };
extern bool isStoppedflag_chess[11][11] = {false};
extern bool isStoppedflag_ingame[InGameBtnNum] = {false};


extern bool visitedExceptQi[11][11] = { false };

extern bool notFirstPlay[9] = { false };

extern string bgmName[9] =
{ "","Sympathy(Instrumental)","Sympathy(Quiet)",
"陽だまり笑顔で(Instrumental)",
"Secret Labo(Instrumental)",
"PERFECT GIRL(Quiet)",
"とおりゃんせ～甘美風来(Instrumental)",
"おだやかな日常",
"Blue Sky(Quiet)" };