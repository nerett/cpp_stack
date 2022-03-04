DEPENDENCIES =

CC = g++
CFLAGS = -c #-fsanitize=address #-Wall -Wextra -g
LDFLAGS = #-fsanitize=address #-Wall -Wextra -g
BUILDDIR = Build/
EXECDIR = Debug/

EXECNAME = cpp_stack


#------------------------------------BUILDING-----------------------------------------------
all: mkdir main
	$(CC) $(LDFLAGS) $(BUILDDIR)main.o $(BUILDDIR)libcpp_stack.o -o $(EXECDIR)$(EXECNAME)
	
mkdir:
	mkdir -p Build Debug
	
main: libcpp_stack
	$(CC) $(CFLAGS) main.cpp -o $(BUILDDIR)main.o


#-------------------------------------libcpp_stack------------------------------------------------
libcpp_stack:
	$(CC) $(CFLAGS) cpp_stack.cpp -o $(BUILDDIR)libcpp_stack.o


#-----------------------------INSTALLING DEPENDENCIES----------------------------------------
install-dependencies:
	cd .. && git clone $(DEPENDENCIES)


#------------------------------------RUNNING-------------------------------------------------
run:
	./$(EXECDIR)$(EXECNAME) $(CPUCODEPATH)

rund:
	valgrind ./$(EXECDIR)$(EXECNAME)


#-----------------------------------CLEANING-------------------------------------------------
clean:
	rm -rf $(BUILDDIR) $(EXECDIR)
