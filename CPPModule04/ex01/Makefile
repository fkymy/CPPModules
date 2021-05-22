# updated Sun May 23 02:07:43 JST 2021

SRC := AWeapon.cpp Alien.cpp Character.cpp Enemy.cpp PlasmaRifle.cpp PowerFist.cpp RadScorpion.cpp SuperMutant.cpp Sword.cpp main.cpp

OBJ := AWeapon.o Alien.o Character.o Enemy.o PlasmaRifle.o PowerFist.o RadScorpion.o SuperMutant.o Sword.o main.o

HDR := AWeapon.hpp Alien.hpp Character.hpp Enemy.hpp PlasmaRifle.hpp PowerFist.hpp RadScorpion.hpp SuperMutant.hpp Sword.hpp

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
