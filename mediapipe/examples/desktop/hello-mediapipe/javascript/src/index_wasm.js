import helloMediapipeWasmLibrary from "../bin/hello-mediapipe-wasm";

import { createLoader } from "./loader";

import { GreetImpl } from "./implementation/greet";

/**
 * Main export for the library
 */
export default async () => {
  const { library } = await createLoader(helloMediapipeWasmLibrary);

  return {
    Greet: GreetImpl(library),
  };
};
