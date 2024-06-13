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

#include "common.h"
#include "gamestate.h"
#include "command_menu.h"
#include "player.h"
#include "map.h"
#include "menu.h"

void main() {
   unsigned char choice; 

   set_PET_font();
   
   gamestate_load();

   while(1) {
        clrscr();
        gotox(67);
        printf("%u k free\n", _heapmemavail());

        menu_draw( 43, 9, "starship command center" );
        //cputsxy(  2, 1, "starship command center" );
        cputsxy(  4, 5, "r - register   l - login   q - quit" );
        cputsxy(  4, 8, "your choice:");
        choice = cgetc();

        switch (choice) {
            case 'R':
            case 'r':
                player_register();
                break;
            case 'L':
            case 'l':
                if (player_login()) {
                    // Proceed to game menu for the logged-in player
                    command_menu();
                }
                break;
            case 'Q':
            case 'q':
                return;
            //default:
                //printf("Invalid choice. Try again.\n");
        }
    }              
}
