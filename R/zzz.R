# nocov start

.onLoad <- function(libname, pkgname) {
  path <- tzdb::tzdb_path(type = "text")
  zones_set_install_cpp(path)
}

# nocov end
