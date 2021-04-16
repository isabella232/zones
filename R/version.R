#' Time zone database version
#'
#' @description
#' `zone_database_version()` returns the version of the time zone database
#' currently in use.
#'
#' @return
#' A single string of the database version.
#'
#' @export
#' @examples
#' zone_database_version()
zone_database_version <- function() {
  zone_database_version_cpp()
}
