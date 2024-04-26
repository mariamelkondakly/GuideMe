# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\GuideMe_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GuideMe_autogen.dir\\ParseCache.txt"
  "GuideMe_autogen"
  )
endif()
