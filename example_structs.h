#ifndef __STRUCTS_H
#define __STRUCTS_H

typedef enum { CRAZY, INSANE, WHACKO } MentalState;

typedef struct
{
	int hours;
	char *dreams;
} Restfulness;

typedef struct
{
	MentalState state;
	Restfulness *sleep;
	int iq;
} Brain;

#endif
