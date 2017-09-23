PROGRAM = img

# gcc ou g++ ?
CXX = $(shell wx-config --cxx)
# wx-config --libs
WX_LIBS = $(shell wx-config --libs)
# wx-config --cxxflags
WX_CXXFLAGS = $(shell wx-config --cxxflags)

# emplacement des dossiers "src", "obj" et "bin"
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)


$(BINDIR)/$(PROGRAM): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CXX) $(OBJECTS) -o $@ $(WX_LIBS)
	
$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $< -o $@ -c $(WX_CXXFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)
	rm -rf $(BINDIR)
