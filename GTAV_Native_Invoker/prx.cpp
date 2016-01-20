#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <string.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/process.h>
#include <ppu_intrinsics.h>
#include <stdarg.h>
#include <stdio.h>
#include <cstdlib>
#include "Natives.h"

SYS_MODULE_INFO("GTAV_Native_Invoker", 0, 1, 1);
SYS_MODULE_START(PRX_ENTRY);

void HookNative(int native, int dest) {
	int FuncBytes[1];
	FuncBytes[0] = *(int*)dest;
	memcpy((void*)native, FuncBytes, 4);
}
int is_player_online() {
	if (*(char*)(0x22322A0) == 0)
		return 0;
	else return 1337;
}

int Hook()
{
	//Call Natives Here
	//EX: Player player = PLAYER::PLAYER_ID();
	//EX: Ped ped = PLAYER::PLAYER_PED_ID();
	return is_player_online();
}

extern "C" int PRX_ENTRY()
{
	HookNative(0x01C1BB60, (int)Hook);
	return SYS_PRX_RESIDENT;
}
