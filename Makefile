SRCDIR = src
TESTDIR = test
INCDIR = include
OBJDIR = obj
CONIODIR = vendor/conio-master
CPPVERSION = 17

INCS = 
OBJS = main.o ioController.o stdioc.o
EXE = main

CXXFLAGS = -Wall -Wextra -Wconversion -g -MMD -MP -std=c++$(CPPVERSION)
INCLUDES = -I$(CONIODIR) -I$(INCDIR) -Itest
LIBS = 

_INCS = $(patsubst %,$(INCDIR)/%,$(INCS))
_OBJS = $(patsubst %,$(OBJDIR)/%,$(OBJS))
_OBJS_CONIO = $(CONIODIR)/conio.o

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(_INCS)
	@echo "Compiling $@ from $<..."
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)
	@echo

$(OBJDIR)/%.o: $(TESTDIR)/%.cpp $(_INCS)
	@echo "Compiling $@ from $<..."
	$(CXX) -c -o $@ $< $(CXXFLAGS) $(INCLUDES)
	@echo

$(EXE): $(_OBJS_CONIO) $(_OBJS)
	@echo "Compiling... "
	@echo "Linking $@ from $^..."
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)
	@echo

.PHONY: clean

all: $(EXE)

create:
	@echo "Creating dir 'obj'"
	@mkdir obj
	@echo "Done!"

clean:
	@echo "Cleaning..."
	@rm -f $(OBJDIR)/*
	@rm -f $(EXE)
	@echo "Done."

show_obj:
	@echo "Finding..."
	@ls obj
	@echo "Done!"

reset: clean $(EXE)
