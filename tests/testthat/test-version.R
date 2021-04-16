test_that("can get known database version", {
  expect_identical(zone_database_version(), "2021a")
})
