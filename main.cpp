
/**
 * @file main.cpp
 * @brief Obtain BibTeX information from iNSPIRE web site
 * @author So Chigusa
 * @date 2019/08/14
 */

#include "inspire.h"

int main(int argc, char * argv[]) {
  if(argc != 3) {
    std::cout << "Usage: ./Inspire2BibTeX [Author name] [Output file]" << std::endl;
    std::cout << "For the format of [Author name], please see README.md." << std::endl;
    return -1;
  }

  Inspire my_inspire(argv[1], argv[2]);
  my_inspire.get();
  return 0;
}
