load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//mediapipe/examples:__subpackages__"])

cc_library(
    name = "greet",
    srcs = ["greet.cpp"],
    hdrs = ["greet.hpp"],
    visibility = ["//visibility:public"],
    deps = [
        "//mediapipe/calculators/core:pass_through_calculator",
        "//mediapipe/framework:calculator_graph",
        "//mediapipe/framework/port:logging",
        "//mediapipe/framework/port:parse_text_proto",
        "//mediapipe/framework/port:status",
    ],
)
