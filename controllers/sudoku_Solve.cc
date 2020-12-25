#include "sudoku_Solve.h"
#include "cppSudokuSolver.h"
using namespace std;
using namespace sudoku;
void Solve::sudoku_solve(const HttpRequestPtr &req,  // 必須
                   std::function<void (const HttpResponsePtr &)> &&callback,  // 必須
                   int m00, int m01, int m02, int m03, int m04, int m05, int m06, int m07, int m08,
                int m10, int m11, int m12, int m13, int m14, int m15, int m16, int m17, int m18,
                int m20, int m21, int m22, int m23, int m24, int m25, int m26, int m27, int m28,
                int m30, int m31, int m32, int m33, int m34, int m35, int m36, int m37, int m38,
                int m40, int m41, int m42, int m43, int m44, int m45, int m46, int m47, int m48,
                int m50, int m51, int m52, int m53, int m54, int m55, int m56, int m57, int m58,
                int m60, int m61, int m62, int m63, int m64, int m65, int m66, int m67, int m68,
                int m70, int m71, int m72, int m73, int m74, int m75, int m76, int m77, int m78,
                int m80, int m81, int m82, int m83, int m84, int m85, int m86, int m87, int m88
                   ) const
{
    // LOG_DEBUGでコンソール上に、「いつ」「どの関数で」「どのファイルで」呼び出されたかが表示される
    LOG_DEBUG<< "solve start";
    // ~~本来であればここでトークンを参照したり、データベースからユーザIDをもとにデータを取得する処理が入る~~
    Json::Value ret;    // JSONインスタンス
    // JSONにデータを格納
    ret["result"]="ok";
    vector<vector<int>> field = {
        {m00, m01, m02, m03, m04, m05, m06, m07, m08},
        {m10, m11, m12, m13, m14, m15, m16, m17, m18},
        {m20, m21, m22, m23, m24, m25, m26, m27, m28},
        {m30, m31, m32, m33, m34, m35, m36, m37, m38},
        {m40, m41, m42, m43, m44, m45, m46, m47, m48},
        {m50, m51, m52, m53, m54, m55, m56, m57, m58},
        {m60, m61, m62, m63, m64, m65, m66, m67, m68},
        {m70, m71, m72, m73, m74, m75, m76, m77, m78},
        {m80, m81, m82, m83, m84, m85, m86, m87, m88},
    };
    SudokuSolver solver(field);
    cout << "以下の盤面の解を探索します." << endl;
    solver.print();
    solver.solve(0, 0);
    cout << "解の探索が終了しました." << endl;
    solver.print();
    vector<vector<int>> returnField = solver.get_field();
    ret["m00"]=returnField[0][0];
    ret["m01"]=returnField[0][1];
    ret["m02"]=returnField[0][2];
    ret["m03"]=returnField[0][3];
    ret["m04"]=returnField[0][4];
    ret["m05"]=returnField[0][5];
    ret["m06"]=returnField[0][6];
    ret["m07"]=returnField[0][7];
    ret["m08"]=returnField[0][8];
    ret["m10"]=returnField[1][0];
    ret["m11"]=returnField[1][1];
    ret["m12"]=returnField[1][2];
    ret["m13"]=returnField[1][3];
    ret["m14"]=returnField[1][4];
    ret["m15"]=returnField[1][5];
    ret["m16"]=returnField[1][6];
    ret["m17"]=returnField[1][7];
    ret["m18"]=returnField[1][8];
    ret["m20"]=returnField[2][0];
    ret["m21"]=returnField[2][1];
    ret["m22"]=returnField[2][2];
    ret["m23"]=returnField[2][3];
    ret["m24"]=returnField[2][4];
    ret["m25"]=returnField[2][5];
    ret["m26"]=returnField[2][6];
    ret["m27"]=returnField[2][7];
    ret["m28"]=returnField[2][8];
    ret["m30"]=returnField[3][0];
    ret["m31"]=returnField[3][1];
    ret["m32"]=returnField[3][2];
    ret["m33"]=returnField[3][3];
    ret["m34"]=returnField[3][4];
    ret["m35"]=returnField[3][5];
    ret["m36"]=returnField[3][6];
    ret["m37"]=returnField[3][7];
    ret["m38"]=returnField[3][8];
    ret["m40"]=returnField[4][0];
    ret["m41"]=returnField[4][1];
    ret["m42"]=returnField[4][2];
    ret["m43"]=returnField[4][3];
    ret["m44"]=returnField[4][4];
    ret["m45"]=returnField[4][5];
    ret["m46"]=returnField[4][6];
    ret["m47"]=returnField[4][7];
    ret["m48"]=returnField[4][8];
    ret["m50"]=returnField[5][0];
    ret["m51"]=returnField[5][1];
    ret["m52"]=returnField[5][2];
    ret["m53"]=returnField[5][3];
    ret["m54"]=returnField[5][4];
    ret["m55"]=returnField[5][5];
    ret["m56"]=returnField[5][6];
    ret["m57"]=returnField[5][7];
    ret["m58"]=returnField[5][8];
    ret["m60"]=returnField[6][0];
    ret["m61"]=returnField[6][1];
    ret["m62"]=returnField[6][2];
    ret["m63"]=returnField[6][3];
    ret["m64"]=returnField[6][4];
    ret["m65"]=returnField[6][5];
    ret["m66"]=returnField[6][6];
    ret["m67"]=returnField[6][7];
    ret["m68"]=returnField[6][8];
    ret["m70"]=returnField[7][0];
    ret["m71"]=returnField[7][1];
    ret["m72"]=returnField[7][2];
    ret["m73"]=returnField[7][3];
    ret["m74"]=returnField[7][4];
    ret["m75"]=returnField[7][5];
    ret["m76"]=returnField[7][6];
    ret["m77"]=returnField[7][7];
    ret["m78"]=returnField[7][8];
    ret["m80"]=returnField[8][0];
    ret["m81"]=returnField[8][1];
    ret["m82"]=returnField[8][2];
    ret["m83"]=returnField[8][3];
    ret["m84"]=returnField[8][4];
    ret["m85"]=returnField[8][5];
    ret["m86"]=returnField[8][6];
    ret["m87"]=returnField[8][7];
    ret["m88"]=returnField[8][8];
    auto resp=HttpResponse::newHttpJsonResponse(ret);
    callback(resp);
}