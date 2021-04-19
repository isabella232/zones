
<!-- README.md is generated from README.Rmd. Please edit that file -->

# zones

<!-- badges: start -->

[![R-CMD-check](https://github.com/r-lib/zones/workflows/R-CMD-check/badge.svg)](https://github.com/r-lib/zones/actions)
<!-- badges: end -->

The goal of zones is to provide access to the C++ library,
[date](https://github.com/HowardHinnant/date). This is a developer
focused package, useful for those that are building their own date and
date-time R package, like [clock](https://clock.r-lib.org/).

To use the C++ API supplied by zones:

-   Add zones to both Imports and LinkingTo.

-   Call `zones::zones_initialize()` from your `.onLoad()`.

-   Access the date API through `#include <zones/*.h>` where `*` is
    replaced with the date header you want to use.

Note that while `zones/tz.h` declares many functions and types, most of
their implementations are not present in the header file. This means
that the functions in `zones/tz.h` are *not* safe to call from your R
package. Instead, the most critical helpers have been exposed in a safe
way in `zones/zones.h`. Use these instead.

## Installation

You can install the released version of zones from
[CRAN](https://CRAN.R-project.org) with:

``` r
install.packages("zones")
```

And the development version from [GitHub](https://github.com/) with:

``` r
# install.packages("devtools")
devtools::install_github("r-lib/zones")
```
