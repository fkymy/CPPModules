# updated Sun May 23 02:23:39 JST 2021

SRC := AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp

OBJ := AMateria.o Character.o Cure.o Ice.o MateriaSource.o main.o

HDR := AMateria.hpp Character.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp Ice.hpp MateriaSource.hpp

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

test:
	clang++ -Wall -Werror -Wextra -std=c++98 -D TEST *.cpp

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
