#' Time zone database names
#'
#' @description
#' `zone_database_names()` returns the time zone names found in the database.
#'
#' @return
#' A character vector of zone names.
#'
#' @export
#' @examples
#' zone_database_names()
zone_database_names <- function() {
  zone_database_names_cpp()
}
