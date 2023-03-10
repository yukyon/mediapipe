#!/usr/bin/env bash

BAZEL_OUTPUT_DIR="${HOME}/wasm/mediapipe/bazel-bin/mediapipe/examples/desktop/hello-mediapipe"

# Copy over to the `bin` directory
test -f ${BAZEL_OUTPUT_DIR}/javascript/hello-mediapipe-wasm/hello-mediapipe-wasm.js && cp -rf ${BAZEL_OUTPUT_DIR}/javascript/hello-mediapipe-wasm/hello-mediapipe-wasm.js javascript/bin/
test -f ${BAZEL_OUTPUT_DIR}/javascript/hello-mediapipe-js/hello-mediapipe-js.js && cp -rf ${BAZEL_OUTPUT_DIR}/javascript/hello-mediapipe-js/hello-mediapipe-js.js javascript/bin/

exit 0
