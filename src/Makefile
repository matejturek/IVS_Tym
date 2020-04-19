.PHONY: all pack clean test doc run profile app-compile profile-compile test-compile profile-run

PROJ-NAME = Calculator
APP = app
TEST = test
PROF = profiling

all: app-compile test-compile profile-compile

profile: profile-compile

test: test-compile
	cd $(PROJ-NAME)/$(TEST) && ./$(TEST)

doc:
	echo 'TO DO doc'

app-compile:
	cd $(PROJ-NAME)/$(APP) && qmake -qt=qt5 $(APP).pro && make

test-compile: $(PROJ-NAME)/$(TEST)/tst_math_lib_test.cpp
	cd $(PROJ-NAME)/$(TEST) && qmake -qt=qt5 $(TEST).pro && make

profile-compile: $(PROJ-NAME)/$(PROF)/main.cpp
	cd $(PROJ-NAME)/$(PROF) && g++ -Wall -Wextra -g -pg ./main.cpp -o $(PROF)

run:
	cd $(PROJ-NAME)/$(APP) && ./$(APP)

pack: clean
	cd ../.. && zip -r xturek05 doc install repo

clean:
	git clean -xdf && rm -f ../../xturek05
