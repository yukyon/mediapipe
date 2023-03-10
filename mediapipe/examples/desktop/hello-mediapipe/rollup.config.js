import { terser } from "rollup-plugin-terser";

const variants = ["wasm"];
const formats = ["umd", "es"];

const outputs = variants.reduce(
  (acc, variant) => [
    ...acc,
    {
      input: `javascript/src/index_${variant}.js`,
      output: formats.reduce(
        (acc, format) => [
          ...acc,
          {
            file: `javascript/dist/${variant}/${format}/index.js`,
            sourcemap: true,
            format,
            name: "HelloMediapipe",
            plugins: [terser()],
          },
        ],
        []
      ),
    },
  ],
  []
);

export default outputs;

