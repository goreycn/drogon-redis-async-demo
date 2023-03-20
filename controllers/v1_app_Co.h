#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace v1 {
namespace app {
class Co : public drogon::HttpController<Co> {
 public:
  METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(Co::get, "/{2}/{1}", Get); // path is /v1/app/Co/{arg2}/{arg1}
    // METHOD_ADD(Co::your_method_name, "/{1}/{2}/list", Get); // path is /v1/app/Co/{arg1}/{arg2}/list
    // ADD_METHOD_TO(Co::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
    METHOD_ADD(Co::get, "/", Get);
    METHOD_ADD(Co::async, "/async", Get);
  METHOD_LIST_END
  // your declaration of processing function maybe like this:
  // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
  // void your_method_name(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, double p1, int p2) const;
  void get(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback);
  drogon::AsyncTask async(const HttpRequestPtr req, std::function<void(const HttpResponsePtr &)> callback);
};
}
}
