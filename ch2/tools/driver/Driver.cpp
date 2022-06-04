#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/raw_ostream.h"
#include "tinylang/Basic/Version.h"
#include <iostream>

int main(int argc_, const char** argv_) {
  llvm::InitLLVM x(argc_, argv_);
  std::cout  << "Hello, i am Tinylang "
  << tinylang::getTinylangVersion()
  << "\n";
  return 0;

}


