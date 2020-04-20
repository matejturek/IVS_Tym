.PHONY: all pack clean test doc run profile app-compile profile-compile test-compile profile-run math_lib-compile uninstall install

PROJ-NAME = Calculator
APP = app
TEST = test
PROF = profiling
MATH = math_lib

all: math_lib-compile app-compile test-compile profile-compile

profile: profile-compile

test: test-compile
	cd $(PROJ-NAME)/$(TEST) && ./$(TEST)

doc:
	doxygen Doxyfile

app-compile: math_lib-compile
	cd $(PROJ-NAME)/$(APP) && qmake -qt=qt5 $(APP).pro && make

test-compile: math_lib-compile $(PROJ-NAME)/$(TEST)/tst_math_lib_test.cpp
	cd $(PROJ-NAME)/$(TEST) && qmake -qt=qt5 $(TEST).pro && make

profile-compile: math_lib-compile $(PROJ-NAME)/$(PROF)/main.cpp
	cd $(PROJ-NAME)/$(PROF) && qmake -qt=qt5 $(PROF).pro && make

math_lib-compile: $(PROJ-NAME)/$(MATH)/$(MATH).cpp $(PROJ-NAME)/$(MATH)/$(MATH).h
	cd $(PROJ-NAME)/$(MATH) && qmake -qt=qt5 $(MATH).pro && make

run:
	cd $(PROJ-NAME)/$(APP) && ./$(APP)

install: app-compile
	install Manual/calculator-ivs.desktop /usr/shared/applications/
	install -m 0775 Calculator/app/app /usr/bin/calculator-ivs
	install Manual/calculator.xpm /usr/share/pixmaps

uninstall:
	rm -f /usr/share/pixmaps/calculator.xpm
	rm -f /usr/bin/calculator-ivs
	rm -f /usr/share/applications/calculator-ivs.desktop

pack: clean
	cd ../../.. && zip -r xturek05_xkolbj00_xsladk07_xkluci01 xturek05_xkolbj00_xsladk07_xkluci01

clean:
	git clean -xdf && rm -f ../../xturek05
