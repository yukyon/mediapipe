const Library = require(`../dist/wasm/umd`);

(async () => {
  // Wait for the library to initialize
  const HelloMediapipe = await Library();

  HelloMediapipe.Greet.sayHello();
})();
