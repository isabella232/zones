#ifndef ZONES_ZONES_H
#define ZONES_ZONES_H

#include <date/date.h>
#include <date/tz.h>

#include <R_ext/Rdynload.h>

#include <string>

// -----------------------------------------------------------------------------

namespace zones {

static
inline
const date::time_zone*
locate_zone(const std::string& name) {
  typedef const date::time_zone* fn_t(const std::string&);
  static fn_t *fn = (fn_t*) R_GetCCallable("zones", "api_locate_zone");
  return fn(name);
}

static
inline
date::local_info
get_local_info(const date::local_seconds& tp,
               const date::time_zone* p_time_zone) {
  typedef date::local_info fn_t(const date::local_seconds&, const date::time_zone*);
  static fn_t *fn = (fn_t*) R_GetCCallable("zones", "api_get_local_info");
  return fn(tp, p_time_zone);
}

static
inline
date::sys_info
get_sys_info(const date::sys_seconds& tp,
             const date::time_zone* p_time_zone) {
  typedef date::sys_info fn_t(const date::sys_seconds&, const date::time_zone*);
  static fn_t *fn = (fn_t*) R_GetCCallable("zones", "api_get_sys_info");
  return fn(tp, p_time_zone);
}

} // namespace zones

// -----------------------------------------------------------------------------

#endif
