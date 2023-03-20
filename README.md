# hello_dg
> 记录drogon框架中使用协程进行redis访问的Demo。

#### 前提：
- 源码编译安装`cppjson`
- 安装`drogon`时，指定`-std=20`,开启协程`coroutine`支持。

#### 注意：
留意对比`CMakeLists.txt`的参数。