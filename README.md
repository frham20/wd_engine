# WD Engine

Small multi platform ready engine to test various stuff

1. C++14/17
2. Vulkan API
3. ~~Zero~~ Low overhead multiplatform design patterns
   * I dropped the zero overhead approach to a more self contained, implementation hiding approach so the lib can be linked against without needing all the additional SDKs. 
   * Experimented with the 3 classes approach (base, impl, top)
   * Experimented with the fixed size char array and placement new pimpl approach
      * Issues with memory alignment, which causes an indirection as well if alignment is done at run-time
      * If alignment is done at compile time, need to expose the needed alignment in the headers and thus kinda need to show the implementation
      * Would have been a mess to maintain the fixed size buffers for the multiple platforms
         * need worst case and waste memory or need constant per platform, per class



