/**
 * @implements Greet
 */
export const GreetImpl = (library) => {
  /**
   * @interface Greet
   */
  return {
    /**
     * Greet hello
     *
     * @function
     * @name Greet.sayHello
     */
    sayHello() {
      library.Greet.SayHello();
    },
  };
};
