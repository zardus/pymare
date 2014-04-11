#include <Python.h>
#include "example_pystructs.h"
#include "example_enums.h"

#ifndef PyMODINIT_FUNC  /* declarations for DLL import/export */
#define PyMODINIT_FUNC void
#endif

PyObject *PyMareError;
PyObject *module;

static PyMethodDef module_methods[] = { {NULL} };

PyMODINIT_FUNC initexample(void)
{
	PyMareError = PyErr_NewException("example.PyMareError", NULL, NULL);
	module = Py_InitModule3("example", module_methods, "An example for pymare.");

	PYMARE_INITTYPE(Brain)
	PyModule_AddObject(module, "PyMareError", PyMareError);
	init_enums();

	PyModule_AddObject(module, "MentalState_tostr", dict_MentalState_tostr);
	PyModule_AddObject(module, "MentalState_fromstr", dict_MentalState_fromstr);
}
