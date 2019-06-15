CC          := g++ -O0 -g -Wall -std=c++17 -Wextra -pedantic -Wno-comment
INC         := 
LIBS        := -pthread
SRC         := $(wildcard *.cpp)
DEP         := $(wildcard *.cpp) $(wildcard *.h) $(wildcard *.sh)

.PHONY: clean-% clean-all

%.out : $(DEP) $(wildcard ../$(@:%.out=%)/*)
	@/bin/rm -f $@
	$(CC) $(SRC) $(wildcard ../$(@:%.out=%)/*.cpp) \
		$(INC) -I../$(@:%.out=%) $(LIBS) -o $@

clean-% : 
	/bin/rm -rf $(@:clean-%=%).out

clean-all : 
	@/bin/rm -rf *.o 
	@/bin/rm -rf *.d 
	/bin/rm -rf *.out
