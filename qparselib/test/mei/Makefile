# Object files to either reference or create                          
OBJECTS = createmei.o      
# The executable file that will be created at the end                 
EXEC = createmei                                                   
# The flags to use for compilation                                    
FLAGS = -Wall -lmei                                                        
# The code compiler to use for compilation                            
CC = g++                                                              

# Perform action on all object files (May or may not exist)           
all: $(OBJECTS)                                                       
		$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)