# File: Makefile

CXX = cl
CXXFLAGS = /EHsc /c /nologo
LD = link
LDFLAGS = /nologo /Fe:$@
RM = del
MAIN_EXECUTABLE = main.exe

all: $(MAIN_EXECUTABLE)
.PHONY: all

$(MAIN_EXECUTABLE): main.obj sort.obj
	$(LD) $(LDFLAGS) $^

%.obj: %.cpp
	$(CXX) $(CXXFLAGS) $<

clean:
	$(RM) *.obj
.PHONY: clean

distclean: clean
	$(RM) $(MAIN_EXECUTABLE)
.PHONY: distclean