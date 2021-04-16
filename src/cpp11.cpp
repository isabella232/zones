// Generated by cpp11: do not edit by hand
// clang-format off


#include "cpp11/declarations.hpp"

// names.cpp
cpp11::writable::strings zone_database_names_cpp();
extern "C" SEXP _zones_zone_database_names_cpp() {
  BEGIN_CPP11
    return cpp11::as_sexp(zone_database_names_cpp());
  END_CPP11
}
// path.cpp
void zones_set_install_cpp(const cpp11::strings& path);
extern "C" SEXP _zones_zones_set_install_cpp(SEXP path) {
  BEGIN_CPP11
    zones_set_install_cpp(cpp11::as_cpp<cpp11::decay_t<const cpp11::strings&>>(path));
    return R_NilValue;
  END_CPP11
}
// version.cpp
cpp11::writable::strings zone_database_version_cpp();
extern "C" SEXP _zones_zone_database_version_cpp() {
  BEGIN_CPP11
    return cpp11::as_sexp(zone_database_version_cpp());
  END_CPP11
}

extern "C" {
/* .Call calls */
extern SEXP _zones_zone_database_names_cpp();
extern SEXP _zones_zone_database_version_cpp();
extern SEXP _zones_zones_set_install_cpp(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_zones_zone_database_names_cpp",   (DL_FUNC) &_zones_zone_database_names_cpp,   0},
    {"_zones_zone_database_version_cpp", (DL_FUNC) &_zones_zone_database_version_cpp, 0},
    {"_zones_zones_set_install_cpp",     (DL_FUNC) &_zones_zones_set_install_cpp,     1},
    {NULL, NULL, 0}
};
}

void api_init(DllInfo* dll);

extern "C" void R_init_zones(DllInfo* dll){
  R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  api_init(dll);
  R_forceSymbols(dll, TRUE);
}
