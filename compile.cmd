cmd /c windres resources/resource.rc -O coff -o resources/resource.res
cmd /c g++ -g -std=c++11 -o generate generator.cc resources/resource.res