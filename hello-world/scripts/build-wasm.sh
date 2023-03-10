#!/usr/bin/env bash
set -euo pipefail

# Build the WASM variant
bazel build -c opt --config=wasm //hello-world/javascript:hello-world-wasm

