local tek = require "@nasso/epine-tek/v0.1.0-alpha8"

tek:project "malloc" {"libmy_malloc.so"}

tek:shared "libmy_malloc" {
    srcs = {find "./src/*.c"}
}

tek:binary "unit_tests" {
    srcs = {find "./tests/*.c"},
    libs = {tek:ref "libmy_malloc"}
}

return tek:make()