#' Initialize zones for usage in other packages
#'
#' @description
#' `zones_initialize()` is intended to be called from a client package's
#' `.onLoad()` as `zones::zones_initialize()` to ensure that the zones package
#' has been loaded.
#'
#' The function itself doesn't do anything. It is instead called for the
#' side-effect of loading the zones package. This does two things:
#'
#' - The zones `.onLoad()` hook is run, which sets the path to the time zone
#' database that exists in tzdb.
#'
#' - The callables in zones are registered, which allows them to be called from
#' other packages.
#'
#' @details
#' There are alternative ways to ensure that zones is loaded. A client package
#' can alternatively import a function from zones into its package with the
#' `@importFrom` tag, or can call `requireNamespace("zones", quiet = TRUE)` from
#' its `.onLoad()`.
#'
#' @return `NULL`, invisibly.
#'
#' @export
#' @examples
#' zones_initialize()
zones_initialize <- function() {
  invisible()
}
