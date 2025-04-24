SRCDIR := $(shell pwd)
LIBNAME := libMyAnalysis.so
EXECUTABLE := runAnalysis

GARBAGE := $(wildcard *~ *.o)

FILES_SRC := $(wildcard *.cc)
FILES_OBJ := $(patsubst %.cc,%.o,$(FILES_SRC))

ROOTINC := $(shell root-config --cflags)
ROOTLIBS := $(shell root-config --glibs)

INC := -I$(SRCDIR) $(ROOTINC)
CXXFLAGS := -O2 -Wall -fPIC -D_REENTRANT $(INC) -DSTANDALONE

all: $(LIBNAME) $(EXECUTABLE)

$(LIBNAME): $(FILES_OBJ) analysisdict.o
	$(CXX) -shared $^ -o $@ $(ROOTLIBS)

$(EXECUTABLE): $(LIBNAME)
	$(CXX) $(CXXFLAGS) -o $@ runAnalysis.cc $(ROOTLIBS) -L. -lMyAnalysis

analysisdict.cc: MyAnalysis.h LinkDef.h
	rootcling -f $@ -I$(SRCDIR) -DSTANDALONE $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

plot:
	python3 plot_distributions.py

clean:
	rm -f $(GARBAGE) $(LIBNAME) $(EXECUTABLE) analysisdict.*

cleanAll: clean
	rm -f *.so *.pcm output.root
