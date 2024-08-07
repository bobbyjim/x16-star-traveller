#include <stdio.h>

#include "player.h"

#define		PLAYER_ACTIVE_FILENAME		"active.p"

extern Player player;

char activeFilename[16];

//
//   Maybe the Player Data should be loaded into a RAM bank.
//   Since we have cbm_load and cbm_save, it becomes both
//   easy and memory-efficient to do this.
//

int player_loadActive()
{
	FILE* fp = fopen(PLAYER_ACTIVE_FILENAME, "r");
	fscanf(fp, "%s", &activeFilename);
	fclose(fp);

	fp = fopen(activeFilename, "rb");
	fread(&player, sizeof(Player), 1, fp);
	fclose(fp);

	if (player.turns_left < 1) return 1;
	return 0;
}

void player_save()
{
	FILE* fp = fopen(activeFilename, "wb");
	fwrite(&player, sizeof(Player), 1, fp);
	fclose(fp);
}
