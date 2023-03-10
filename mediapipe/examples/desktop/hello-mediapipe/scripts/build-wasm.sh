#!/usr/bin/env bash
set -euo pipefail

# Build the WASM variant
bazel build \
     -c opt \
     --config=wasm \
     --define MEDIAPIPE_DISABLE_GPU=1 \
     //mediapipe/examples/desktop/hello-mediapipe/javascript:hello-mediapipe-wasm

