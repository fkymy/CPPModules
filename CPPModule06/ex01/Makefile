# updated Mon May 24 02:01:36 JST 2021

SRC := Data.cpp main.cpp

OBJ := Data.o main.o

HDR := Data.hpp

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- run 'make source' to add files

PROGRAM := a.out

CXX := clang++
WARNINGS := -Wall -Wextra -Werror
CXXFLAGS := $(WARNINGS) -std=c++98

.PHONY: all clean source
all: $(PROGRAM)

$(PROGRAM): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

$(OBJ): %.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

fclean: clean
	-rm -f $(PROGRAM)

clean:
	-rm -f Makefile.bak $(OBJ)

source:
	@mv Makefile Makefile.bak
	@echo "# updated `date`" > Makefile
	@echo '' >> Makefile
	@echo SRC := `ls *.cpp` >> Makefile
	@echo '' >> Makefile
	@echo OBJ := `ls *.cpp | sed s/cpp$$/o/` >> Makefile
	@echo '' >> Makefile
	@echo HDR := `ls *.hpp` >> Makefile
	@echo '' >> Makefile
	@sed -n -e '/^# DO NOT ADD OR MODIFY/,$$p' < Makefile.bak >> Makefile
