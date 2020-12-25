#pragma once
#include <drogon/HttpController.h>
#include <vector>
using namespace drogon;
using namespace std;
namespace sudoku
{
class Solve:public drogon::HttpController<Solve>
{
  public:
    METHOD_LIST_BEGIN
    //use METHOD_ADD to add your custom processing function here;
    //METHOD_ADD(Solve::get,"/{2}/{1}",Get);//path is /sudoku/Solve/{arg2}/{arg1}
    //METHOD_ADD(Solve::your_method_name,"/{1}/{2}/list",Get);//path is /sudoku/Solve/{arg1}/{arg2}/list
    //ADD_METHOD_TO(Solve::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list
    METHOD_ADD(Solve::sudoku_solve,"/{1}/{2}/{3}/{4}/{5}/{6}/{7}/{8}/{9}/{10}/{11}/{12}/{13}/{14}/{15}/{16}/{17}/{18}/{19}/{20}/{21}/{22}/{23}/{24}/{25}/{26}/{27}/{28}/{29}/{30}/{31}/{32}/{33}/{34}/{35}/{36}/{37}/{38}/{39}/{40}/{41}/{42}/{43}/{44}/{45}/{46}/{47}/{48}/{49}/{50}/{51}/{52}/{53}/{54}/{55}/{56}/{57}/{58}/{59}/{60}/{61}/{62}/{63}/{64}/{65}/{66}/{67}/{68}/{69}/{70}/{71}/{72}/{73}/{74}/{75}/{76}/{77}/{78}/{79}/{80}/{81}",Get);
    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,int p1,std::string p2);
    // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;

    void sudoku_solve(const HttpRequestPtr &req,
                std::function<void (const HttpResponsePtr &)> &&callback,
                int m00, int m01, int m02, int m03, int m04, int m05, int m06, int m07, int m08,
                int m10, int m11, int m12, int m13, int m14, int m15, int m16, int m17, int m18,
                int m20, int m21, int m22, int m23, int m24, int m25, int m26, int m27, int m28,
                int m30, int m31, int m32, int m33, int m34, int m35, int m36, int m37, int m38,
                int m40, int m41, int m42, int m43, int m44, int m45, int m46, int m47, int m48,
                int m50, int m51, int m52, int m53, int m54, int m55, int m56, int m57, int m58,
                int m60, int m61, int m62, int m63, int m64, int m65, int m66, int m67, int m68,
                int m70, int m71, int m72, int m73, int m74, int m75, int m76, int m77, int m78,
                int m80, int m81, int m82, int m83, int m84, int m85, int m86, int m87, int m88) const;
};
}
