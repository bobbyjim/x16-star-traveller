#ifndef _ASTROGATION_H_
#define _ASTROGATION_H_

#include "map.h"

int distance( int col1, int row1,
              int col2, int row2,
              int maximumValue1,
			  int maximumValue2 );

int astrogation_menu();
int astrogation_fetch( MAP1* world, int col, int row );
void astrogation_print_current();
int astrogation_attempt_jump_to(int hex);
//void astrogation_show_range();

#endif