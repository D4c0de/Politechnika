

#include <iostream>
#include "App.h"
#define CONSOLE_MODE true
#define WINDOW_MODE false
#define LOGINE_AS_ADMIN true
#define REQUIRE_AUTHORYZATION false

int main()
{

	App* app = new App(CONSOLE_MODE, REQUIRE_AUTHORYZATION);
}
