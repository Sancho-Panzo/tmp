#ifndef BOTXO_H
#define BOTXO_H

extern int pos;
extern char field[9];
extern char buffer_cell_value[2];
void rand_move(char p1, char p2);
void defend_attack(char p1, char p2, char p3);
void bot_easy(char p1, char p2);
void bot_medium(char p1, char p2);
void bot_hard(char p1, char p2);

#endif
