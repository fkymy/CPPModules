# updated Tue May 11 20:01:00 JST 2021

SRC := Zombie.cpp ZombieEvent.cpp main.cpp

OBJ := Zombie.o ZombieEvent.o main.o

HDR := Zombie.hpp ZombieEvent.hpp

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- run 'make source' to add files
#
PROGRAM := zombie

CXX := clang++
WARNINGS := -Wall -Wextra -Werror
CXXFLAGS := $(WARNINGS) -g -pedantic -std=c++98

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
