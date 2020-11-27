g++ -c lib.cpp -o lib.o
g++ --std=c++11 Create_link.cpp lib.o -o my_ln
g++ --std=c++11 Length_out.cpp  lib.o -o lenout
g++ --std=c++11 Attr.cpp        lib.o -o attr
g++ --std=c++11 Read_from_n.cpp lib.o -o readn
