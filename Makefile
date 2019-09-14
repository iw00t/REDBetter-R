INCLUDEDIR = headers  # location for header files
CXXFLAGS   = -std=c++14 -I $(INCLUDEDIR) -Wall -Wfatal-errors  # override default makefile CXXFLAGS

# add search paths for the header source files 
# %.h           : any file with the extension .h
# $(INCLUDEDIR) : location for header files stored in variable
vpath %.h $(INCLUDEDIR)

# "all" does not correspond to a file, it is a "phoney target"
# .PHONY declares this so that Make does not attempt to build any file named "all"
.PHONY: all
# "all" is the first target such that "make" and "make all" will have the same effect
all: REDBetter-R

REDBetter-R: src/main.cpp src/APIModel.o src/APIView.o src/APIController.o
	$(CXX) ${CXXFLAGS} $^ -o REDBetter-R

# builds the object files (without linking into an executable)
# each .cpp file should map to zero or one .h file as no .cpp file has more than 
# one .h file we can use $<, which takes the first prerequisite
%.o: src/%.cpp headers/%.h
	$(CXX) -c $(CXXFLAGS) $< -o $@
# -c : compile only, no linking

clean:
	rm -f REDBetter-R */*.o
