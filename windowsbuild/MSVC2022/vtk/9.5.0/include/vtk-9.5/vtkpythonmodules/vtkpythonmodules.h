#ifndef vtkpythonmodules_h
#define vtkpythonmodules_h
#define PY_APPEND_INIT(module) PyImport_AppendInittab("." #module, PyInit_ ## module)
#define PY_IMPORT(module) { \
    PyObject* var_ ## module = PyInit_ ## module(); \
    PyDict_SetItemString(PyImport_GetModuleDict(), "." #module,var_ ## module); \
    Py_DECREF(var_ ## module); }

#define PY_APPEND_INIT_OR_IMPORT(module, do_import) \
  if (do_import) { PY_IMPORT(module); } else { PY_APPEND_INIT(module); }

static void vtkpythonmodules_load() {
}
#undef PY_APPEND_INIT
#undef PY_IMPORT
#undef PY_APPEND_INIT_OR_IMPORT
#endif
