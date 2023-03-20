#pragma once
#include <drogon/utils/coroutine.h>
#include <drogon/nosql/RedisClient.h>

template <typename T>
drogon::Task<T> getFromCache(
    const std::string &key,
    const drogon::nosql::RedisClientPtr &client) noexcept(false)
{
  auto value = co_await client->execCommandCoro("get %s", key.data());
  co_return fromString<T>(value.asString());
}


template <typename T>
drogon::Task<T> get_redis_value(
    const std::string &key,
    const drogon::nosql::RedisClientPtr &client) noexcept(false)
{
  auto value = co_await client->execCommandCoro("get %s", key.data());
  co_return value.asString();
}


template <typename T>
drogon::Task<> updateCache(
    const std::string &key,
    T &&value,
    const drogon::nosql::RedisClientPtr &client) noexcept(false)
{
  std::string vstr = toString(std::forward<T>(value));
  co_await client->execCommandCoro("set %s %s", key.data(), vstr.data());
}