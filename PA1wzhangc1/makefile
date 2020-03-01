#
# Specifiy the target
all:	zhangcen_p1

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
zhangcen_p1: zhangcen_p1.o
	g++  zhangcen_p1.o	-o zhangcen_p1

# Specify how the object files should be created from source files
zhangcen_p1.o:	zhangcen_p1.cpp
		g++ -c zhangcen_p1.cpp

# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o zhangcen_p1
