#ifndef LIB_GREET_H_
#define LIB_GREET_H_

#include "mediapipe/framework/port/status.h"

namespace mediapipe {

    class Greet {
        public:

        static void SayHello();
        static absl::Status PrintHelloWorld();
    };

} // namespace mediapipe

#endif
