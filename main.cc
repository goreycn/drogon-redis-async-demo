#include <drogon/drogon.h>
int main() {
    //Set HTTP listener address and port
//    drogon::app().addListener("0.0.0.0",8000);
    //Load config file
    drogon::app().loadConfigFile("../dev.json");
    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
