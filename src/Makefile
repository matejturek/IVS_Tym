.PHONY: all pack clean test doc run profile compile-program compile-profile

PROJ-NAME = Calculator

all: compile-program compile-profile

compile-program:
	cd $(PROJ-NAME) && qmake -qt=qt5 $(PROJ-name).pro && make

run:
	cd $(PROJ-NAME) && ./$(PROJ-NAME)

pack: clean
	echo "to do pack"

clean:
		echo "to do clean"
