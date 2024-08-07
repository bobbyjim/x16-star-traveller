/*
MIT License

Copyright (c) 2024 Robert Eaglestone

Permission is hereby granted, free of charge, to any person obtaining a copy 
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

#include "common.h"
#include "splash.h"
#include "gamestate.h"
#include "command_menu.h"
#include "player.h"
#include "map.h"
#include "menu.h"
#include "ship.h"

Player player;

void logout() {
    printf("player %s, your turns are up.\n\n", player.name);
    puts("please allow another player to log in, if possible, before re-logging in.\n\n");
    exit(0);
}

void main() {
   set_PET_font();

   gamestate_load();
   if (player_loadActive())
      logout();

   splash(player.name);
   sleep(1);

   textcolor(COLOR_YELLOW);
   cputsxy(30,20, "press a key to begin");
   cgetc();
   clrscr();
   _randomize();

   while(1) {
        command_menu();
    }    
}
