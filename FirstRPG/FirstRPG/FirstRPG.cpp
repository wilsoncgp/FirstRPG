#include "stdafx.h"
#include "Main.h"

int main(int argc, char *argv[])
{
	CMain* cMain = new CMain(600, 500);

	cMain->GameLoop();

	delete cMain;

	return 0;
}

 