# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/juliapazdziorek/CLionProjects/2324L_19_s29852_FK/cmake-build-release/_deps/sfml-src"
  "/Users/juliapazdziorek/CLionProjects/2324L_19_s29852_FK/cmake-build-release/_deps/sfml-build"
  "/Users/juliapazdziorek/CLionProjects/2324L_19_s29852_FK/cmake-build-release/_deps/sfml-subbuild/sfml-populate-prefix"
  "/Users/juliapazdziorek/CLionProjects/2324L_19_s29852_FK/cmake-build-release/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "/Users/juliapazdziorek/CLionProjects/2324L_19_s29852_FK/cmake-build-release/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "/Users/juliapazdziorek/CLionProjects/2324L_19_s29852_FK/cmake-build-release/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "/Users/juliapazdziorek/CLionProjects/2324L_19_s29852_FK/cmake-build-release/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/juliapazdziorek/CLionProjects/2324L_19_s29852_FK/cmake-build-release/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/juliapazdziorek/CLionProjects/2324L_19_s29852_FK/cmake-build-release/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
