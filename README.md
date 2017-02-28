# WD Engine

Small multi platform ready engine to test various stuff

1. C++14/17
   * [x] default, delete on constructors and functions
   * [x] member initialization at declaration
   * [x] lambdas
   * [x] auto keyword
   * [x] RAII with std::unique_ptr, std::vector, etc..
   * [x] move operations, std::move, emplace_back, etc..
2. Vulkan API
   * [x] instance creation
   * [ ] physical device selection
   * [ ] queue selection
   * [ ] logical device creation
3. ~~Zero~~ Low overhead multiplatform design patterns
   * I dropped the zero overhead approach to a more self contained, implementation hiding approach so the lib can be linked against without needing all the additional SDKs. 
   * Experimented with the 3 classes approach (base, impl, top)
      * Include mess
      * Hard to design an "interface" for the platform specific implementations
      * 3 classes to maintain instead of 2
   * Experimented with the fixed size char array and placement new pimpl approach
      * Issues with memory alignment, which causes an indirection as well if alignment is done at run-time
      * If alignment is done at compile time, need to expose the needed alignment in the headers and thus kinda need to show the implementation
      * Would have been a mess to maintain the fixed size buffers for the multiple platforms
         * need worst case and waste memory or need constant per platform, per class
   * Settled with aggregation for the platform specific code and classic pimpl pattern
      * The interface is dictated by the container / generic class based on the calls it's making, no virtual fonction calls
      * Implementation / data use dynamic allocation at object construction
         * Will try and keep this limited to "heavy" classes which shouldn't be allocated that often
      * Implementation entirely hidden in the .cpp files
      



