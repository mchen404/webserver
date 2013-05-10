compiler = g++

src_folder = ./src
header_folder = ./headers
obj_folder = ./obj

src = $(wildcard $(src_folder)/*.cpp) $(wildcard ./*.cpp)
headers = $(wildcard $(header_folder)/*.h) $(wildcard ./*.h)

all:
	$(compiler) -I $(header_folder) -I . $(src)
	
organize:
	-mv *.cpp $(src_folder)
	-mv *.h $(header_folder)
	
clean:
	rm *exe*