#include <date/tz.h>
#include <cpp11/R.hpp>
#include <R_ext/Rdynload.h> // For DllInfo on R 3.3

// -----------------------------------------------------------------------------

const date::time_zone*
api_locate_zone(const std::string& name) {
  return date::locate_zone(name);
}

date::local_info
api_get_local_info(const date::local_seconds& tp,
                   const date::time_zone* p_time_zone) {
  return p_time_zone->get_info(tp);
}

date::sys_info
api_get_sys_info(const date::sys_seconds& tp,
                 const date::time_zone* p_time_zone) {
  return p_time_zone->get_info(tp);
}

// -----------------------------------------------------------------------------

[[cpp11::init]]
void api_init(DllInfo* dll){
  R_RegisterCCallable("zones", "api_locate_zone",    (DL_FUNC)api_locate_zone);
  R_RegisterCCallable("zones", "api_get_local_info", (DL_FUNC)api_get_local_info);
  R_RegisterCCallable("zones", "api_get_sys_info",   (DL_FUNC)api_get_sys_info);
}
