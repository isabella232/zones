#include <date/tz.h>
#include <cpp11/R.hpp>
#include <cpp11/protect.hpp>
#include <R_ext/Rdynload.h> // For DllInfo on R 3.3

// -----------------------------------------------------------------------------

/*
 * To avoid throwing C++ exceptions across package boundaries, we require
 * that all API functions have a `std::string& error` argument. The client
 * is responsible for checking if this is `.empty()` after calling any API
 * function. They can then handle the error in any way that they require.
 */

#define BEGIN_ZONES_CPP \
  try {
#define END_ZONES_CPP                     \
  }                                       \
  catch (std::exception & e) {            \
    error = e.what();                     \
  }                                       \
  catch (...) {                           \
    error = "C++ error (unknown cause)."; \
  }

// -----------------------------------------------------------------------------

const date::time_zone*
api_locate_zone(const std::string& name, std::string& error) {
  BEGIN_ZONES_CPP

  return date::locate_zone(name);

  END_ZONES_CPP
  return nullptr;
}

date::local_info
api_get_local_info(const date::local_seconds& tp,
                   const date::time_zone* p_time_zone,
                   std::string& error) {
  BEGIN_ZONES_CPP

  return p_time_zone->get_info(tp);

  END_ZONES_CPP
  return date::local_info{};
}

date::sys_info
api_get_sys_info(const date::sys_seconds& tp,
                 const date::time_zone* p_time_zone,
                 std::string& error) {
  BEGIN_ZONES_CPP

  return p_time_zone->get_info(tp);

  END_ZONES_CPP
  return date::sys_info{};
}

// -----------------------------------------------------------------------------

[[cpp11::init]]
void api_init(DllInfo* dll){
  R_RegisterCCallable("zones", "api_locate_zone",    (DL_FUNC)api_locate_zone);
  R_RegisterCCallable("zones", "api_get_local_info", (DL_FUNC)api_get_local_info);
  R_RegisterCCallable("zones", "api_get_sys_info",   (DL_FUNC)api_get_sys_info);
}
