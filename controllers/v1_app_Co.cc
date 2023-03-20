#include "v1_app_Co.h"
#include "redis_cache.h"
#include <coroutine>
#include <drogon/drogon.h>

using namespace v1::app;

void Co::get(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback) {
  auto resp = HttpResponse::newHttpResponse();
  resp->setBody("nice");
  callback(resp);
}
drogon::AsyncTask Co::async(const HttpRequestPtr req, std::function<void(const HttpResponsePtr &)> callback) {

  auto redis_ptr = drogon::app().getFastRedisClient();
  try {
    auto a = co_await get_redis_value<std::string>("aa", redis_ptr);
    auto b = co_await get_redis_value<std::string>("bb", redis_ptr);

    auto resp = drogon::HttpResponse::newHttpResponse();
    resp->setBody("i'm async" + a + ":" + b);
    callback(resp);
  }
  catch (const std::exception &err) {
    LOG_ERROR << err.what();
    callback(drogon::HttpResponse::newNotFoundResponse());
  }
}
