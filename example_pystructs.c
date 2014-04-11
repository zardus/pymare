#include <Python.h>
#include <structmember.h>
#include "pymare.h"
#include "example_structs.h"
#include "example_pystructs.h"
#include "example_enums.h"

PYMARE_NEW(Brain);
PYMARE_WRAP(Brain);

static int pyBrain_init(pyBrain *self, PyObject *args, PyObject *kwargs)
{
	PYMARE_WRAP_CONSTRUCTOR(Brain);
	self->wrapped = malloc(sizeof(Brain));
	self->wrapped->sleep = malloc(sizeof(Restfulness));
	return 0;
}

static void pyBrain_dealloc(pyBrain *self)
{
	free(self->wrapped->sleep);
	free(self->wrapped);
}

static PyObject *pyBrain_complain(pyBrain *self)
{
	printf("Waaah. (iq: %d)\n", self->wrapped->iq);
	Py_RETURN_NONE;
}

static PyMemberDef pyBrain_members[] = { {NULL} };

PYMARE_ACCESSOR_BUILDVAL(Brain, Brain, self->wrapped->iq, iq, "i")
PYMARE_ACCESSOR_ENUM(Brain, Brain, self->wrapped->state, state, MentalState)
static PyGetSetDef pyBrain_getseters[] =
{
	PYMARE_ACCESSOR_DEF(Brain, iq),
	PYMARE_ACCESSOR_DEF(Brain, state),
	{NULL}  /* Sentinel */
};

static PyMethodDef pyBrain_methods[] =
{
	{"complain", (PyCFunction)pyBrain_complain, METH_NOARGS, "Prints something"},
	{NULL}  /* Sentinel */
};

PYMARE_TYPEOBJECT("example", Brain)
