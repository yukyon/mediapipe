#include <emscripten/bind.h>

#include "cpp/greet.hpp"

using namespace emscripten;
using namespace mediapipe;

EMSCRIPTEN_BINDINGS(Hello_Mediapipe) {
    emscripten::class_<Greet>("Greet")
        .constructor<>()
        .class_function("SayHello", &Greet::SayHello);
}
