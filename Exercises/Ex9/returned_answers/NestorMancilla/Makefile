# Compiler and flags
CXX = clang++
CXXFLAGS = -O2 -std=c++17 -stdlib=libc++ -pedantic -W -Wall -Wshadow -fPIC -pthread -m64

# Pythia8 paths
PYTHIA8_INC = -I../../include
PYTHIA8_LIB = -L../../lib -Wl,-rpath,../../lib -lpythia8

# ROOT paths
ROOT_FLAGS = $(shell root-config --cflags --glibs)

# Target
TARGET = minbias_muons
SRC = minbias_muons.cc

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(PYTHIA8_INC) $(ROOT_FLAGS) $< -o $@ $(PYTHIA8_LIB)

clean:
	rm -f $(TARGET)
