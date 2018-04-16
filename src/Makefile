LIB_DIR=../lib
CC=gcc

teste: main.c $(LIB_DIR)/libcthread.a
	$(CC) -m32 -g -o teste main.c -L$(LIB_DIR) -lcthread -Wall
	
	
exemplo: exemplo.c $(LIB_DIR)/libcthread.a
	 $(CC) -o exemplo exemplo.c -L$(LIB_DIR) -lcthread -Wall
