// move.c
int nextMove(int);
// board.c
int printBoard(int, int);
// art.c
void printComputerWon();
void printPlayerWon();
// timer.c
void set_A9_IRQ_stack(void);
void config_GIC(void);
void config_HPS_timer(int);
void config_interval_timer(int);
void enable_A9_interrupts(void);
// music.c
void playTheme(int);
void playTone1();
void playTone2();
void playTone3();
void playToneLadder();
void playToneSnake();