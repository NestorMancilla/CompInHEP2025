CXX         = $(shell root-config --cxx)
CXXFLAGS    = $(shell root-config --cflags) -O2 -Wall
LDLIBS      = $(shell root-config --libs)

all: Normal_distribution PlotTree

Normal_distribution: Normal_distribution.cc
	$(CXX) $(CXXFLAGS) -o Normal_distribution Normal_distribution.cc $(LDLIBS)

PlotTree: PlotTree.cc
	$(CXX) $(CXXFLAGS) -o PlotTree PlotTree.cc $(LDLIBS)

clean:
	rm -f Normal_distribution PlotTree data.root histogram.pdf
