
<!-- README.md is generated from README.Rmd. Please edit that file -->

# zones

<!-- badges: start -->

[![R-CMD-check](https://github.com/DavisVaughan/zones/workflows/R-CMD-check/badge.svg)](https://github.com/DavisVaughan/zones/actions)
<!-- badges: end -->

The goal of zones is to provide access to the C++ library,
[date](https://github.com/HowardHinnant/date). This is a developer
focused package, useful for those that are building their own date and
date-time R package.

Calendrical calculations are available through the `date/date.h` header.
Time zone specific calculations are exposed through a combination of the
`date/tz.h` header and a limited callable API that is safe to call from
other R packages. All of this is accessible through a single include,
`zones.h`.

To use the callable API, zones must be in both the Imports and LinkingTo
fields of the client’s package. Additionally, the client package should
call `zones::zone_database_initialize()` from its `.onLoad()`, which
will ensure that zones is loaded before any attempt to access its
callable API is attempted.

Function declared, but not implemented, in `tz.h` are *not* safe to call
from other R packages. The critical ones have been exposed in the
`zones::` C++ namespace accessible through `zones.h`. Attempting to call
any other function from `tz.h` will likely crash your R session.

## Installation

You can install the released version of zones from
[CRAN](https://CRAN.R-project.org) with:

``` r
install.packages("zones")
```

And the development version from [GitHub](https://github.com/) with:

``` r
# install.packages("devtools")
devtools::install_github("DavisVaughan/zones")
```
