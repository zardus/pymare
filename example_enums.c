#include <Python.h>

#include "pymare.h"
#include "example_enums.h"
#include "example_structs.h"

PYMARE_ENUM_CONVERSION(MentalState)

void init_enums()
{
	PYMARE_ENUM_INIT(MentalState)
	PYMARE_ENUM_ADD(MentalState, CRAZY)
	PYMARE_ENUM_ADD(MentalState, INSANE)
	PYMARE_ENUM_ADD(MentalState, WHACKO)
}
